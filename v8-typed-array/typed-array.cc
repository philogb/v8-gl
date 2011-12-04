#include <v8.h>

#include <stdlib.h>
#include <string.h>

using namespace v8;

#define DEFINE_ARRAY_BUFFER_VIEW(name, type, element_size) \
    Handle<Value> name(const Arguments& args) {\
        return CreateArrayBufferView(args, type, element_size);\
    }

#define INIT_ARRAY_BUFFER_VIEW(name, type, element_size) {\
    Local<FunctionTemplate> t = FunctionTemplate::New(name); \
    t->InstanceTemplate()->SetInternalFieldCount(1); \
    Local<Function> f = t->GetFunction();\
    f->Set(String::New("BYTES_PER_ELEMENT"), Int32::New(element_size), ReadOnly);\
    target->Set(String::New(#name), f);}

void ExternalArrayWeakCallback(Persistent<Value> object, void* data) {
    free(data);
    object.Dispose();
}

Persistent<FunctionTemplate> array_buffer_constructor_template;

Handle<Value> ArrayBuffer(const Arguments& args) {
    if (args.Length() != 1 || !args[0]->IsNumber()) {
        return ThrowException(String::New("Invalid ArrayBuffer arguments."));
    }

    unsigned long length = args[0]->Uint32Value();
    void* data = malloc(length);
    memset(data, 0, length);

    Persistent<Object> persistentHandle = Persistent<Object>::New(args.This());
    persistentHandle.MakeWeak(data, ExternalArrayWeakCallback);

    args.This()->SetPointerInInternalField(0, data);
    args.This()->SetPointerInInternalField(1, (void*)length);
    args.This()->Set(String::New("byteLength"), Int32::New(length), ReadOnly);

    return args.This();
}

Handle<Value> ArrayBufferViewSet(const Arguments& args) {
    Local<Object> arrayBuffer = args.This()->Get(String::New("buffer"))->ToObject();

    if (args.Length() >= 1 && args[0]->IsArray()) {
        Local<Array> source = Local<Array>::Cast(args[0]);
        unsigned int offset = 0;

        if (args.Length() >= 2 && args[1]->IsUint32()) {
            offset = args[1]->Uint32Value();
        }

        unsigned int dataLength = args.This()->GetIndexedPropertiesExternalArrayDataLength();
        if (offset + source->Length() > dataLength) {
            return ThrowException(String::New("INDEX_SIZE_ERR: array too large"));
        }

        for (unsigned int index = 0; index < source->Length(); index++) {
            args.This()->Set(offset + index, source->Get(index));
        }
    } else {
        return ThrowException(String::New("Invalid ArrayBufferView::set arguments."));
    }

    return Undefined();
}

Handle<Value> ArrayBufferViewSubarray(const Arguments& args) {
    return ThrowException(String::New("ArrayBufferView::subarray not yet implemented."));
}

Handle<Value> CreateArrayBufferView(const Arguments& args, ExternalArrayType type, int element_size) {
    Local<Object> arrayBuffer = Local<Object>();
    Local<Object> initData = Local<Object>();
    unsigned long elements = 0;
    unsigned long byteOffset = 0;
    unsigned long arrayBufferLength = 0;

    if (!args.IsConstructCall())
	return ThrowException(String::New("Typed Array constructor cannot be called as a function."));

    if (args.Length() == 1 && args[0]->IsUint32()) {
        // TypedArray(unsigned long length)
        elements = args[0]->Uint32Value();
    } else if (args.Length() >= 1 && args[0]->IsObject() &&
	       !((Handle<Object>::Cast(args[0]))->FindInstanceInPrototypeChain
		 (array_buffer_constructor_template).IsEmpty())) {
        // TypedArray(ArrayBuffer buffer, optional unsigned long byteOffset, optional unsigned long length)
        arrayBuffer = args[0]->ToObject();
	arrayBufferLength = (unsigned long)
	    arrayBuffer->GetPointerFromInternalField(1);

        if (args.Length() > 1) {
            byteOffset = args[1]->Uint32Value();
        }
        if (args.Length() > 2) {
            elements = args[2]->Uint32Value();
        } else {
	    if ((arrayBufferLength - byteOffset) % element_size != 0) {
		return ThrowException(String::New("Length of the ArrayBuffer minus the byteOffset must be a multiple of the element size."));
	    }
	    elements = (arrayBufferLength - byteOffset) / element_size;
	}

    } else if (args.Length() == 1 && args[0]->IsArray()) {
        // TypedArray(type[] array)
	initData = Local<Object>::Cast(args[0]);
	elements = Handle<Array>::Cast(initData)->Length();
    } else if (args.Length() == 1 && args[0]->IsObject() &&
	       Handle<Object>::Cast(args[0])->HasIndexedPropertiesInExternalArrayData()) {
        // TypedArray(TypedArray array)
	initData = Local<Object>::Cast(args[0]);
	elements = initData->GetIndexedPropertiesExternalArrayDataLength();
    } else {
        return ThrowException(String::New("Invalid ArrayBufferView arguments."));
    }

    if (arrayBuffer.IsEmpty()) {
        Local<Value> arg = Int32::New(elements * element_size);
        arrayBuffer = array_buffer_constructor_template->GetFunction()->NewInstance(1, &arg);
	arrayBufferLength = (unsigned long)
	    arrayBuffer->GetPointerFromInternalField(1);
    }

    void* arrayBufferData = arrayBuffer->GetPointerFromInternalField(0);

    if (byteOffset + elements * element_size > arrayBufferLength) {
        return ThrowException(String::New("Given byteOffset and length references an area beyond the end of the ArrayBuffer."));
    }

    args.This()->SetIndexedPropertiesToExternalArrayData(((int8_t*)arrayBufferData) + byteOffset, type, elements);

    // Initialize
    if (!initData.IsEmpty()) {
	if (initData->HasIndexedPropertiesInExternalArrayData() &&
	    initData->GetIndexedPropertiesExternalArrayDataType() == type) {
	    // fast path
	    void *source = initData->GetIndexedPropertiesExternalArrayData();
	    memcpy(((int8_t*)arrayBufferData) + byteOffset, source,
		   elements * element_size);
	} else {
	    // slow path
	    for (unsigned int index = 0; index < elements; index++) {
		args.This()->Set(index, initData->Get(index));
	    }
	}
    }

    // ArrayBufferView properties
    args.This()->Set(String::New("buffer"), arrayBuffer, ReadOnly);
    args.This()->Set(String::New("byteLength"), Int32::New(elements * element_size), ReadOnly);
    args.This()->Set(String::New("byteOffset"), Int32::New(byteOffset), ReadOnly);

    // TypedArray properties
    args.This()->Set(String::New("BYTES_PER_ELEMENT"), Int32::New(element_size), ReadOnly);
    args.This()->Set(String::New("length"), Int32::New(elements), ReadOnly);

    // TypedArray methods (TODO: move to prototype)
    args.This()->Set(String::New("set"), FunctionTemplate::New(ArrayBufferViewSet)->GetFunction());
    args.This()->Set(String::New("subarray"), FunctionTemplate::New(ArrayBufferViewSubarray)->GetFunction());

    return args.This();
}

DEFINE_ARRAY_BUFFER_VIEW(Int8Array, kExternalByteArray, sizeof(int8_t));
DEFINE_ARRAY_BUFFER_VIEW(Uint8Array, kExternalUnsignedByteArray, sizeof(uint8_t));
DEFINE_ARRAY_BUFFER_VIEW(Int16Array, kExternalShortArray, sizeof(int16_t));
DEFINE_ARRAY_BUFFER_VIEW(Uint16Array, kExternalUnsignedShortArray, sizeof(uint16_t));
DEFINE_ARRAY_BUFFER_VIEW(Int32Array, kExternalIntArray, sizeof(int32_t));
DEFINE_ARRAY_BUFFER_VIEW(Uint32Array, kExternalUnsignedIntArray, sizeof(uint32_t));
DEFINE_ARRAY_BUFFER_VIEW(Float32Array, kExternalFloatArray, sizeof(float));
// DEFINE_ARRAY_BUFFER_VIEW(Float64Array, kExternalDoubleArray, sizeof(double));
// DEFINE_ARRAY_BUFFER_VIEW(PixelArray, kExternalPixelArray, sizeof(uint8_t));

extern "C" void
init (Handle<Object> target) {
    HandleScope scope;

    {
        array_buffer_constructor_template = Persistent<FunctionTemplate>::New(FunctionTemplate::New(ArrayBuffer));
        array_buffer_constructor_template->InstanceTemplate()->SetInternalFieldCount(2);
        Local<Function> f = array_buffer_constructor_template->GetFunction();
        target->Set(String::New("ArrayBuffer"), f);
    }

    INIT_ARRAY_BUFFER_VIEW(Int8Array, kExternalByteArray, sizeof(int8_t));
    INIT_ARRAY_BUFFER_VIEW(Uint8Array, kExternalUnsignedByteArray, sizeof(uint8_t));
    INIT_ARRAY_BUFFER_VIEW(Int16Array, kExternalShortArray, sizeof(int16_t));
    INIT_ARRAY_BUFFER_VIEW(Uint16Array, kExternalUnsignedShortArray, sizeof(uint16_t));
    INIT_ARRAY_BUFFER_VIEW(Int32Array, kExternalIntArray, sizeof(int32_t));
    INIT_ARRAY_BUFFER_VIEW(Uint32Array, kExternalUnsignedIntArray, sizeof(uint32_t));
    INIT_ARRAY_BUFFER_VIEW(Float32Array, kExternalFloatArray, sizeof(float));
    // INIT_ARRAY_BUFFER_VIEW(Float64Array, kExternalDoubleArray, sizeof(double));
    // INIT_ARRAY_BUFFER_VIEW(PixelArray, kExternalPixelArray, sizeof(uint8_t));
}
