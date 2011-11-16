

#include "glutbind.h"

int* pargc_;
char** argv_;
map<const char*, void*> font_;
Persistent<Context> GlutFactory::glut_persistent_context;
    
    

Handle<Value> GetGLUT_APIENTRY_DEFINED(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_APIENTRY_DEFINED);
}




Handle<Value> GetGLUT_WINGDIAPI_DEFINED(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_WINGDIAPI_DEFINED);
}




Handle<Value> GetGLUT_API_VERSION(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_API_VERSION);
}




Handle<Value> GetGLUT_XLIB_IMPLEMENTATION(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_XLIB_IMPLEMENTATION);
}




Handle<Value> GetGLUT_MACOSX_IMPLEMENTATION(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_MACOSX_IMPLEMENTATION);
}




Handle<Value> GetGLUT_RGB(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_RGB);
}




Handle<Value> GetGLUT_RGBA(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_RGBA);
}




Handle<Value> GetGLUT_INDEX(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_INDEX);
}




Handle<Value> GetGLUT_SINGLE(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_SINGLE);
}




Handle<Value> GetGLUT_DOUBLE(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_DOUBLE);
}




Handle<Value> GetGLUT_ACCUM(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_ACCUM);
}




Handle<Value> GetGLUT_ALPHA(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_ALPHA);
}




Handle<Value> GetGLUT_DEPTH(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_DEPTH);
}




Handle<Value> GetGLUT_STENCIL(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_STENCIL);
}




Handle<Value> GetGLUT_MULTISAMPLE(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_MULTISAMPLE);
}




Handle<Value> GetGLUT_STEREO(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_STEREO);
}




Handle<Value> GetGLUT_LUMINANCE(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_LUMINANCE);
}




Handle<Value> GetGLUT_NO_RECOVERY(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_NO_RECOVERY);
}




Handle<Value> GetGLUT_LEFT_BUTTON(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_LEFT_BUTTON);
}




Handle<Value> GetGLUT_MIDDLE_BUTTON(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_MIDDLE_BUTTON);
}




Handle<Value> GetGLUT_RIGHT_BUTTON(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_RIGHT_BUTTON);
}




Handle<Value> GetGLUT_DOWN(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_DOWN);
}




Handle<Value> GetGLUT_UP(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_UP);
}




Handle<Value> GetGLUT_KEY_F1(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_KEY_F1);
}




Handle<Value> GetGLUT_KEY_F2(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_KEY_F2);
}




Handle<Value> GetGLUT_KEY_F3(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_KEY_F3);
}




Handle<Value> GetGLUT_KEY_F4(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_KEY_F4);
}




Handle<Value> GetGLUT_KEY_F5(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_KEY_F5);
}




Handle<Value> GetGLUT_KEY_F6(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_KEY_F6);
}




Handle<Value> GetGLUT_KEY_F7(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_KEY_F7);
}




Handle<Value> GetGLUT_KEY_F8(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_KEY_F8);
}




Handle<Value> GetGLUT_KEY_F9(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_KEY_F9);
}




Handle<Value> GetGLUT_KEY_F10(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_KEY_F10);
}




Handle<Value> GetGLUT_KEY_F11(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_KEY_F11);
}




Handle<Value> GetGLUT_KEY_F12(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_KEY_F12);
}




Handle<Value> GetGLUT_KEY_LEFT(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_KEY_LEFT);
}




Handle<Value> GetGLUT_KEY_UP(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_KEY_UP);
}




Handle<Value> GetGLUT_KEY_RIGHT(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_KEY_RIGHT);
}




Handle<Value> GetGLUT_KEY_DOWN(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_KEY_DOWN);
}




Handle<Value> GetGLUT_KEY_PAGE_UP(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_KEY_PAGE_UP);
}




Handle<Value> GetGLUT_KEY_PAGE_DOWN(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_KEY_PAGE_DOWN);
}




Handle<Value> GetGLUT_KEY_HOME(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_KEY_HOME);
}




Handle<Value> GetGLUT_KEY_END(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_KEY_END);
}




Handle<Value> GetGLUT_KEY_INSERT(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_KEY_INSERT);
}




Handle<Value> GetGLUT_LEFT(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_LEFT);
}




Handle<Value> GetGLUT_ENTERED(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_ENTERED);
}




Handle<Value> GetGLUT_MENU_NOT_IN_USE(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_MENU_NOT_IN_USE);
}




Handle<Value> GetGLUT_MENU_IN_USE(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_MENU_IN_USE);
}




Handle<Value> GetGLUT_NOT_VISIBLE(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_NOT_VISIBLE);
}




Handle<Value> GetGLUT_VISIBLE(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_VISIBLE);
}




Handle<Value> GetGLUT_HIDDEN(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_HIDDEN);
}




Handle<Value> GetGLUT_FULLY_RETAINED(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_FULLY_RETAINED);
}




Handle<Value> GetGLUT_PARTIALLY_RETAINED(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_PARTIALLY_RETAINED);
}




Handle<Value> GetGLUT_FULLY_COVERED(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_FULLY_COVERED);
}




Handle<Value> GetGLUT_RED(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_RED);
}




Handle<Value> GetGLUT_GREEN(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_GREEN);
}




Handle<Value> GetGLUT_BLUE(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_BLUE);
}




Handle<Value> GetGLUT_NORMAL(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_NORMAL);
}




Handle<Value> GetGLUT_OVERLAY(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_OVERLAY);
}




Handle<Value> GetGLUT_STROKE_ROMAN(Local<String> property,
                      const AccessorInfo &info) {
    return String::New("STROKE_ROMAN");

}




Handle<Value> GetGLUT_STROKE_MONO_ROMAN(Local<String> property,
                      const AccessorInfo &info) {
    return String::New("STROKE_MONO_ROMAN");

}




Handle<Value> GetGLUT_BITMAP_9_BY_15(Local<String> property,
                      const AccessorInfo &info) {
    return String::New("BITMAP_9_BY_15");

}




Handle<Value> GetGLUT_BITMAP_8_BY_13(Local<String> property,
                      const AccessorInfo &info) {
    return String::New("BITMAP_8_BY_13");

}




Handle<Value> GetGLUT_BITMAP_TIMES_ROMAN_10(Local<String> property,
                      const AccessorInfo &info) {
    return String::New("BITMAP_TIMES_ROMAN_10");

}




Handle<Value> GetGLUT_BITMAP_TIMES_ROMAN_24(Local<String> property,
                      const AccessorInfo &info) {
    return String::New("BITMAP_TIMES_ROMAN_24");

}




Handle<Value> GetGLUT_BITMAP_HELVETICA_10(Local<String> property,
                      const AccessorInfo &info) {
    return String::New("BITMAP_HELVETICA_10");

}




Handle<Value> GetGLUT_BITMAP_HELVETICA_12(Local<String> property,
                      const AccessorInfo &info) {
    return String::New("BITMAP_HELVETICA_12");

}




Handle<Value> GetGLUT_BITMAP_HELVETICA_18(Local<String> property,
                      const AccessorInfo &info) {
    return String::New("BITMAP_HELVETICA_18");

}




Handle<Value> GetGLUT_WINDOW_X(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_WINDOW_X);
}




Handle<Value> GetGLUT_WINDOW_Y(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_WINDOW_Y);
}




Handle<Value> GetGLUT_WINDOW_WIDTH(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_WINDOW_WIDTH);
}




Handle<Value> GetGLUT_WINDOW_HEIGHT(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_WINDOW_HEIGHT);
}




Handle<Value> GetGLUT_WINDOW_BUFFER_SIZE(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_WINDOW_BUFFER_SIZE);
}




Handle<Value> GetGLUT_WINDOW_STENCIL_SIZE(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_WINDOW_STENCIL_SIZE);
}




Handle<Value> GetGLUT_WINDOW_DEPTH_SIZE(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_WINDOW_DEPTH_SIZE);
}




Handle<Value> GetGLUT_WINDOW_RED_SIZE(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_WINDOW_RED_SIZE);
}




Handle<Value> GetGLUT_WINDOW_GREEN_SIZE(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_WINDOW_GREEN_SIZE);
}




Handle<Value> GetGLUT_WINDOW_BLUE_SIZE(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_WINDOW_BLUE_SIZE);
}




Handle<Value> GetGLUT_WINDOW_ALPHA_SIZE(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_WINDOW_ALPHA_SIZE);
}




Handle<Value> GetGLUT_WINDOW_ACCUM_RED_SIZE(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_WINDOW_ACCUM_RED_SIZE);
}




Handle<Value> GetGLUT_WINDOW_ACCUM_GREEN_SIZE(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_WINDOW_ACCUM_GREEN_SIZE);
}




Handle<Value> GetGLUT_WINDOW_ACCUM_BLUE_SIZE(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_WINDOW_ACCUM_BLUE_SIZE);
}




Handle<Value> GetGLUT_WINDOW_ACCUM_ALPHA_SIZE(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_WINDOW_ACCUM_ALPHA_SIZE);
}




Handle<Value> GetGLUT_WINDOW_DOUBLEBUFFER(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_WINDOW_DOUBLEBUFFER);
}




Handle<Value> GetGLUT_WINDOW_RGBA(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_WINDOW_RGBA);
}




Handle<Value> GetGLUT_WINDOW_PARENT(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_WINDOW_PARENT);
}




Handle<Value> GetGLUT_WINDOW_NUM_CHILDREN(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_WINDOW_NUM_CHILDREN);
}




Handle<Value> GetGLUT_WINDOW_COLORMAP_SIZE(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_WINDOW_COLORMAP_SIZE);
}




Handle<Value> GetGLUT_WINDOW_NUM_SAMPLES(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_WINDOW_NUM_SAMPLES);
}




Handle<Value> GetGLUT_WINDOW_STEREO(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_WINDOW_STEREO);
}




Handle<Value> GetGLUT_WINDOW_CURSOR(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_WINDOW_CURSOR);
}




Handle<Value> GetGLUT_SCREEN_WIDTH(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_SCREEN_WIDTH);
}




Handle<Value> GetGLUT_SCREEN_HEIGHT(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_SCREEN_HEIGHT);
}




Handle<Value> GetGLUT_SCREEN_WIDTH_MM(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_SCREEN_WIDTH_MM);
}




Handle<Value> GetGLUT_SCREEN_HEIGHT_MM(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_SCREEN_HEIGHT_MM);
}




Handle<Value> GetGLUT_MENU_NUM_ITEMS(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_MENU_NUM_ITEMS);
}




Handle<Value> GetGLUT_DISPLAY_MODE_POSSIBLE(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_DISPLAY_MODE_POSSIBLE);
}




Handle<Value> GetGLUT_INIT_WINDOW_X(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_INIT_WINDOW_X);
}




Handle<Value> GetGLUT_INIT_WINDOW_Y(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_INIT_WINDOW_Y);
}




Handle<Value> GetGLUT_INIT_WINDOW_WIDTH(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_INIT_WINDOW_WIDTH);
}




Handle<Value> GetGLUT_INIT_WINDOW_HEIGHT(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_INIT_WINDOW_HEIGHT);
}




Handle<Value> GetGLUT_INIT_DISPLAY_MODE(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_INIT_DISPLAY_MODE);
}




Handle<Value> GetGLUT_ELAPSED_TIME(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_ELAPSED_TIME);
}




Handle<Value> GetGLUT_WINDOW_FORMAT_ID(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_WINDOW_FORMAT_ID);
}




Handle<Value> GetGLUT_HAS_KEYBOARD(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_HAS_KEYBOARD);
}




Handle<Value> GetGLUT_HAS_MOUSE(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_HAS_MOUSE);
}




Handle<Value> GetGLUT_HAS_SPACEBALL(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_HAS_SPACEBALL);
}




Handle<Value> GetGLUT_HAS_DIAL_AND_BUTTON_BOX(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_HAS_DIAL_AND_BUTTON_BOX);
}




Handle<Value> GetGLUT_HAS_TABLET(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_HAS_TABLET);
}




Handle<Value> GetGLUT_NUM_MOUSE_BUTTONS(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_NUM_MOUSE_BUTTONS);
}




Handle<Value> GetGLUT_NUM_SPACEBALL_BUTTONS(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_NUM_SPACEBALL_BUTTONS);
}




Handle<Value> GetGLUT_NUM_BUTTON_BOX_BUTTONS(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_NUM_BUTTON_BOX_BUTTONS);
}




Handle<Value> GetGLUT_NUM_DIALS(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_NUM_DIALS);
}




Handle<Value> GetGLUT_NUM_TABLET_BUTTONS(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_NUM_TABLET_BUTTONS);
}




Handle<Value> GetGLUT_DEVICE_IGNORE_KEY_REPEAT(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_DEVICE_IGNORE_KEY_REPEAT);
}




Handle<Value> GetGLUT_DEVICE_KEY_REPEAT(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_DEVICE_KEY_REPEAT);
}




Handle<Value> GetGLUT_HAS_JOYSTICK(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_HAS_JOYSTICK);
}




Handle<Value> GetGLUT_OWNS_JOYSTICK(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_OWNS_JOYSTICK);
}




Handle<Value> GetGLUT_JOYSTICK_BUTTONS(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_JOYSTICK_BUTTONS);
}




Handle<Value> GetGLUT_JOYSTICK_AXES(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_JOYSTICK_AXES);
}




Handle<Value> GetGLUT_JOYSTICK_POLL_RATE(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_JOYSTICK_POLL_RATE);
}




Handle<Value> GetGLUT_OVERLAY_POSSIBLE(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_OVERLAY_POSSIBLE);
}




Handle<Value> GetGLUT_LAYER_IN_USE(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_LAYER_IN_USE);
}




Handle<Value> GetGLUT_HAS_OVERLAY(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_HAS_OVERLAY);
}




Handle<Value> GetGLUT_TRANSPARENT_INDEX(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_TRANSPARENT_INDEX);
}




Handle<Value> GetGLUT_NORMAL_DAMAGED(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_NORMAL_DAMAGED);
}




Handle<Value> GetGLUT_OVERLAY_DAMAGED(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_OVERLAY_DAMAGED);
}




Handle<Value> GetGLUT_VIDEO_RESIZE_POSSIBLE(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_VIDEO_RESIZE_POSSIBLE);
}




Handle<Value> GetGLUT_VIDEO_RESIZE_IN_USE(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_VIDEO_RESIZE_IN_USE);
}




Handle<Value> GetGLUT_VIDEO_RESIZE_X_DELTA(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_VIDEO_RESIZE_X_DELTA);
}




Handle<Value> GetGLUT_VIDEO_RESIZE_Y_DELTA(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_VIDEO_RESIZE_Y_DELTA);
}




Handle<Value> GetGLUT_VIDEO_RESIZE_WIDTH_DELTA(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_VIDEO_RESIZE_WIDTH_DELTA);
}




Handle<Value> GetGLUT_VIDEO_RESIZE_HEIGHT_DELTA(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_VIDEO_RESIZE_HEIGHT_DELTA);
}




Handle<Value> GetGLUT_VIDEO_RESIZE_X(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_VIDEO_RESIZE_X);
}




Handle<Value> GetGLUT_VIDEO_RESIZE_Y(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_VIDEO_RESIZE_Y);
}




Handle<Value> GetGLUT_VIDEO_RESIZE_WIDTH(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_VIDEO_RESIZE_WIDTH);
}




Handle<Value> GetGLUT_VIDEO_RESIZE_HEIGHT(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_VIDEO_RESIZE_HEIGHT);
}




Handle<Value> GetGLUT_ACTIVE_SHIFT(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_ACTIVE_SHIFT);
}




Handle<Value> GetGLUT_ACTIVE_CTRL(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_ACTIVE_CTRL);
}




Handle<Value> GetGLUT_ACTIVE_ALT(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_ACTIVE_ALT);
}




Handle<Value> GetGLUT_CURSOR_RIGHT_ARROW(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_CURSOR_RIGHT_ARROW);
}




Handle<Value> GetGLUT_CURSOR_LEFT_ARROW(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_CURSOR_LEFT_ARROW);
}




Handle<Value> GetGLUT_CURSOR_INFO(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_CURSOR_INFO);
}




Handle<Value> GetGLUT_CURSOR_DESTROY(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_CURSOR_DESTROY);
}




Handle<Value> GetGLUT_CURSOR_HELP(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_CURSOR_HELP);
}




Handle<Value> GetGLUT_CURSOR_CYCLE(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_CURSOR_CYCLE);
}




Handle<Value> GetGLUT_CURSOR_SPRAY(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_CURSOR_SPRAY);
}




Handle<Value> GetGLUT_CURSOR_WAIT(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_CURSOR_WAIT);
}




Handle<Value> GetGLUT_CURSOR_TEXT(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_CURSOR_TEXT);
}




Handle<Value> GetGLUT_CURSOR_CROSSHAIR(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_CURSOR_CROSSHAIR);
}




Handle<Value> GetGLUT_CURSOR_UP_DOWN(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_CURSOR_UP_DOWN);
}




Handle<Value> GetGLUT_CURSOR_LEFT_RIGHT(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_CURSOR_LEFT_RIGHT);
}




Handle<Value> GetGLUT_CURSOR_TOP_SIDE(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_CURSOR_TOP_SIDE);
}




Handle<Value> GetGLUT_CURSOR_BOTTOM_SIDE(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_CURSOR_BOTTOM_SIDE);
}




Handle<Value> GetGLUT_CURSOR_LEFT_SIDE(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_CURSOR_LEFT_SIDE);
}




Handle<Value> GetGLUT_CURSOR_RIGHT_SIDE(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_CURSOR_RIGHT_SIDE);
}




Handle<Value> GetGLUT_CURSOR_TOP_LEFT_CORNER(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_CURSOR_TOP_LEFT_CORNER);
}




Handle<Value> GetGLUT_CURSOR_TOP_RIGHT_CORNER(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_CURSOR_TOP_RIGHT_CORNER);
}




Handle<Value> GetGLUT_CURSOR_BOTTOM_RIGHT_CORNER(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_CURSOR_BOTTOM_RIGHT_CORNER);
}




Handle<Value> GetGLUT_CURSOR_BOTTOM_LEFT_CORNER(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_CURSOR_BOTTOM_LEFT_CORNER);
}




Handle<Value> GetGLUT_CURSOR_INHERIT(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_CURSOR_INHERIT);
}




Handle<Value> GetGLUT_CURSOR_NONE(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_CURSOR_NONE);
}




Handle<Value> GetGLUT_CURSOR_FULL_CROSSHAIR(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_CURSOR_FULL_CROSSHAIR);
}



Handle<Value> GLUTInitCallback(const Arguments& args) {
  glutInit(( int* ) pargc_, ( char** ) argv_);
  return v8::Undefined();
}



Handle<Value> GLUTInitDisplayModeCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

  //make call
  glutInitDisplayMode((unsigned int)arg0);
  return v8::Undefined();
}




Handle<Value> GLUTInitDisplayStringCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //get arguments
  String::Utf8Value value0(args[0]);
  char* arg0 = *value0;

  //make call
  glutInitDisplayString((const char*)arg0);
  return v8::Undefined();
}




Handle<Value> GLUTInitWindowPositionCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();

  //make call
  glutInitWindowPosition((int)arg0, (int)arg1);
  return v8::Undefined();
}




Handle<Value> GLUTInitWindowSizeCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();

  //make call
  glutInitWindowSize((int)arg0, (int)arg1);
  return v8::Undefined();
}




Handle<Value> GLUTMainLoopCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 0) return v8::Undefined();
  //get arguments

  //make call
  glutMainLoop();
  return v8::Undefined();
}




Handle<Value> GLUTCreateWindowCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //get arguments
  String::Utf8Value value0(args[0]);
  char* arg0 = *value0;

  //make call
  glutCreateWindow((const char*)arg0);
  return v8::Undefined();
}




Handle<Value> GLUTCreateSubWindowCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 5) return v8::Undefined();
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();
  int arg2 = args[2]->IntegerValue();
  int arg3 = args[3]->IntegerValue();
  int arg4 = args[4]->IntegerValue();

  //make call
  glutCreateSubWindow((int)arg0, (int)arg1, (int)arg2, (int)arg3, (int)arg4);
  return v8::Undefined();
}




Handle<Value> GLUTDestroyWindowCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //get arguments
  int arg0 = args[0]->IntegerValue();

  //make call
  glutDestroyWindow((int)arg0);
  return v8::Undefined();
}




Handle<Value> GLUTPostRedisplayCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 0) return v8::Undefined();
  //get arguments

  //make call
  glutPostRedisplay();
  return v8::Undefined();
}




Handle<Value> GLUTPostWindowRedisplayCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //get arguments
  int arg0 = args[0]->IntegerValue();

  //make call
  glutPostWindowRedisplay((int)arg0);
  return v8::Undefined();
}




Handle<Value> GLUTSwapBuffersCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 0) return v8::Undefined();
  //get arguments

  //make call
  glutSwapBuffers();
  return v8::Undefined();
}




Handle<Value> GLUTGetWindowCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 0) return v8::Undefined();
  //get arguments

  //make call
  glutGetWindow();
  return v8::Undefined();
}




Handle<Value> GLUTSetWindowCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //get arguments
  int arg0 = args[0]->IntegerValue();

  //make call
  glutSetWindow((int)arg0);
  return v8::Undefined();
}




Handle<Value> GLUTSetWindowTitleCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //get arguments
  String::Utf8Value value0(args[0]);
  char* arg0 = *value0;

  //make call
  glutSetWindowTitle((const char*)arg0);
  return v8::Undefined();
}




Handle<Value> GLUTSetIconTitleCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //get arguments
  String::Utf8Value value0(args[0]);
  char* arg0 = *value0;

  //make call
  glutSetIconTitle((const char*)arg0);
  return v8::Undefined();
}




Handle<Value> GLUTPositionWindowCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();

  //make call
  glutPositionWindow((int)arg0, (int)arg1);
  return v8::Undefined();
}




Handle<Value> GLUTReshapeWindowCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();

  //make call
  glutReshapeWindow((int)arg0, (int)arg1);
  return v8::Undefined();
}




Handle<Value> GLUTPopWindowCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 0) return v8::Undefined();
  //get arguments

  //make call
  glutPopWindow();
  return v8::Undefined();
}




Handle<Value> GLUTPushWindowCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 0) return v8::Undefined();
  //get arguments

  //make call
  glutPushWindow();
  return v8::Undefined();
}




Handle<Value> GLUTIconifyWindowCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 0) return v8::Undefined();
  //get arguments

  //make call
  glutIconifyWindow();
  return v8::Undefined();
}




Handle<Value> GLUTShowWindowCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 0) return v8::Undefined();
  //get arguments

  //make call
  glutShowWindow();
  return v8::Undefined();
}




Handle<Value> GLUTHideWindowCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 0) return v8::Undefined();
  //get arguments

  //make call
  glutHideWindow();
  return v8::Undefined();
}




Handle<Value> GLUTFullScreenCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 0) return v8::Undefined();
  //get arguments

  //make call
  glutFullScreen();
  return v8::Undefined();
}




Handle<Value> GLUTSetCursorCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //get arguments
  int arg0 = args[0]->IntegerValue();

  //make call
  glutSetCursor((int)arg0);
  return v8::Undefined();
}




Handle<Value> GLUTWarpPointerCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();

  //make call
  glutWarpPointer((int)arg0, (int)arg1);
  return v8::Undefined();
}




Persistent<Function> persistentWMCloseFunc;

void funcWMCloseFunc ( ) {
  //define handle scope
  HandleScope scope;

  Handle<Value> valueArr[0];

  
  TryCatch try_catch;
  Handle<Value> result = persistentWMCloseFunc->Call(GlutFactory::glut_persistent_context->Global(), 0, valueArr);
  if (result.IsEmpty()) {
    String::Utf8Value error(try_catch.Exception());
    fprintf(stderr, "Exception in WMCloseFunc: %s\n", *error);
  }
}

Handle<Value> GLUTWMCloseFuncCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1 || !args[0]->IsFunction()) return v8::Undefined();
#if (GLUT_MACOSX_IMPLEMENTATION >= 2)
  //get arguments
  //delete previous assigned function
  persistentWMCloseFunc.Dispose();
  Handle<Function> value0 = Handle<Function>::Cast(args[0]);
  persistentWMCloseFunc = Persistent<Function>::New(value0);

  //make call
  glutWMCloseFunc((void (*)(void)) funcWMCloseFunc);
#endif
  return v8::Undefined();
}




Handle<Value> GLUTCheckLoopCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 0) return v8::Undefined();
  //get arguments

#if (GLUT_MACOSX_IMPLEMENTATION >= 2)
  //make call
  glutCheckLoop();
#endif
  return v8::Undefined();
}




Handle<Value> GLUTEstablishOverlayCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 0) return v8::Undefined();
  //get arguments

  //make call
  glutEstablishOverlay();
  return v8::Undefined();
}




Handle<Value> GLUTRemoveOverlayCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 0) return v8::Undefined();
  //get arguments

  //make call
  glutRemoveOverlay();
  return v8::Undefined();
}




Handle<Value> GLUTUseLayerCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //get arguments
  int arg0 = args[0]->IntegerValue();

  //make call
  glutUseLayer((GLenum)arg0);
  return v8::Undefined();
}




Handle<Value> GLUTPostOverlayRedisplayCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 0) return v8::Undefined();
  //get arguments

  //make call
  glutPostOverlayRedisplay();
  return v8::Undefined();
}




Handle<Value> GLUTPostWindowOverlayRedisplayCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //get arguments
  int arg0 = args[0]->IntegerValue();

  //make call
  glutPostWindowOverlayRedisplay((int)arg0);
  return v8::Undefined();
}




Handle<Value> GLUTShowOverlayCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 0) return v8::Undefined();
  //get arguments

  //make call
  glutShowOverlay();
  return v8::Undefined();
}




Handle<Value> GLUTHideOverlayCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 0) return v8::Undefined();
  //get arguments

  //make call
  glutHideOverlay();
  return v8::Undefined();
}




Handle<Value> GLUTCreateMenuCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //get arguments
  Handle<Function> value0 = Handle<Function>::Cast(args[0]);
  void* arg0 = *value0;

  //make call
  glutCreateMenu((void (*)(int))arg0);
  return v8::Undefined();
}




Handle<Value> GLUTDestroyMenuCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //get arguments
  int arg0 = args[0]->IntegerValue();

  //make call
  glutDestroyMenu((int)arg0);
  return v8::Undefined();
}




Handle<Value> GLUTGetMenuCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 0) return v8::Undefined();
  //get arguments

  //make call
  glutGetMenu();
  return v8::Undefined();
}




Handle<Value> GLUTSetMenuCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //get arguments
  int arg0 = args[0]->IntegerValue();

  //make call
  glutSetMenu((int)arg0);
  return v8::Undefined();
}




Handle<Value> GLUTAddMenuEntryCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //get arguments
  String::Utf8Value value0(args[0]);
  char* arg0 = *value0;
  int arg1 = args[1]->IntegerValue();

  //make call
  glutAddMenuEntry((const char*)arg0, (int)arg1);
  return v8::Undefined();
}




Handle<Value> GLUTAddSubMenuCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //get arguments
  String::Utf8Value value0(args[0]);
  char* arg0 = *value0;
  int arg1 = args[1]->IntegerValue();

  //make call
  glutAddSubMenu((const char*)arg0, (int)arg1);
  return v8::Undefined();
}




Handle<Value> GLUTChangeToMenuEntryCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //get arguments
  int arg0 = args[0]->IntegerValue();
  String::Utf8Value value1(args[1]);
  char* arg1 = *value1;
  int arg2 = args[2]->IntegerValue();

  //make call
  glutChangeToMenuEntry((int)arg0, (const char*)arg1, (int)arg2);
  return v8::Undefined();
}




Handle<Value> GLUTChangeToSubMenuCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //get arguments
  int arg0 = args[0]->IntegerValue();
  String::Utf8Value value1(args[1]);
  char* arg1 = *value1;
  int arg2 = args[2]->IntegerValue();

  //make call
  glutChangeToSubMenu((int)arg0, (const char*)arg1, (int)arg2);
  return v8::Undefined();
}




Handle<Value> GLUTRemoveMenuItemCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //get arguments
  int arg0 = args[0]->IntegerValue();

  //make call
  glutRemoveMenuItem((int)arg0);
  return v8::Undefined();
}




Handle<Value> GLUTAttachMenuCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //get arguments
  int arg0 = args[0]->IntegerValue();

  //make call
  glutAttachMenu((int)arg0);
  return v8::Undefined();
}




Handle<Value> GLUTDetachMenuCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //get arguments
  int arg0 = args[0]->IntegerValue();

  //make call
  glutDetachMenu((int)arg0);
  return v8::Undefined();
}




Persistent<Function> persistentDisplayFunc;

void funcDisplayFunc ( ) {
  //define handle scope
  HandleScope scope;

  Handle<Value> valueArr[0];

  
  TryCatch try_catch;
  Handle<Value> result = persistentDisplayFunc->Call(GlutFactory::glut_persistent_context->Global(), 0, valueArr);
  if (result.IsEmpty()) {
    String::Utf8Value error(try_catch.Exception());
    fprintf(stderr, "Exception in DisplayFunc: %s\n", *error);
  }
}

Handle<Value> GLUTDisplayFuncCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1 || !args[0]->IsFunction()) return v8::Undefined();
  //get arguments
  //delete previous assigned function
  persistentDisplayFunc.Dispose();
  Handle<Function> value0 = Handle<Function>::Cast(args[0]);
  persistentDisplayFunc = Persistent<Function>::New(value0);

  //make call
  glutDisplayFunc((void (*)(void)) funcDisplayFunc);
  return v8::Undefined();
}




Persistent<Function> persistentReshapeFunc;

void funcReshapeFunc ( int arg0,int arg1) {
  //define handle scope
  HandleScope scope;

  Handle<Value> valueArr[2];
  valueArr[0] = Integer::New(arg0);
  valueArr[1] = Integer::New(arg1);
  
  TryCatch try_catch;
  Handle<Value> result = persistentReshapeFunc->Call(GlutFactory::glut_persistent_context->Global(), 2, valueArr);
  if (result.IsEmpty()) {
    String::Utf8Value error(try_catch.Exception());
    fprintf(stderr, "Exception in ReshapeFunc: %s\n", *error);
  }
}

Handle<Value> GLUTReshapeFuncCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1 || !args[0]->IsFunction()) return v8::Undefined();
  //get arguments
  //delete previous assigned function
  persistentReshapeFunc.Dispose();
  Handle<Function> value0 = Handle<Function>::Cast(args[0]);
  persistentReshapeFunc = Persistent<Function>::New(value0);

  //make call
  glutReshapeFunc((void (*)(int width, int height)) funcReshapeFunc);
  return v8::Undefined();
}




Persistent<Function> persistentKeyboardFunc;

void funcKeyboardFunc ( unsigned char arg0,int arg1,int arg2) {
  //define handle scope
  HandleScope scope;

  Handle<Value> valueArr[3];
  valueArr[0] = Integer::New(arg0);
  valueArr[1] = Integer::New(arg1);
  valueArr[2] = Integer::New(arg2);
  
  TryCatch try_catch;
  Handle<Value> result = persistentKeyboardFunc->Call(GlutFactory::glut_persistent_context->Global(), 3, valueArr);
  if (result.IsEmpty()) {
    String::Utf8Value error(try_catch.Exception());
    fprintf(stderr, "Exception in KeyboardFunc: %s\n", *error);
  }
}

Handle<Value> GLUTKeyboardFuncCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1 || !args[0]->IsFunction()) return v8::Undefined();
  //get arguments
  //delete previous assigned function
  persistentKeyboardFunc.Dispose();
  Handle<Function> value0 = Handle<Function>::Cast(args[0]);
  persistentKeyboardFunc = Persistent<Function>::New(value0);

  //make call
  glutKeyboardFunc((void (*)(unsigned char key, int x, int y)) funcKeyboardFunc);
  return v8::Undefined();
}




Persistent<Function> persistentMouseFunc;

void funcMouseFunc ( int arg0,int arg1,int arg2,int arg3) {
  //define handle scope
  HandleScope scope;

  Handle<Value> valueArr[4];
  valueArr[0] = Integer::New(arg0);
  valueArr[1] = Integer::New(arg1);
  valueArr[2] = Integer::New(arg2);
  valueArr[3] = Integer::New(arg3);
  
  TryCatch try_catch;
  Handle<Value> result = persistentMouseFunc->Call(GlutFactory::glut_persistent_context->Global(), 4, valueArr);
  if (result.IsEmpty()) {
    String::Utf8Value error(try_catch.Exception());
    fprintf(stderr, "Exception in MouseFunc: %s\n", *error);
  }
}

Handle<Value> GLUTMouseFuncCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1 || !args[0]->IsFunction()) return v8::Undefined();
  //get arguments
  //delete previous assigned function
  persistentMouseFunc.Dispose();
  Handle<Function> value0 = Handle<Function>::Cast(args[0]);
  persistentMouseFunc = Persistent<Function>::New(value0);

  //make call
  glutMouseFunc((void (*)(int button, int state, int x, int y)) funcMouseFunc);
  return v8::Undefined();
}




Persistent<Function> persistentMotionFunc;

void funcMotionFunc ( int arg0,int arg1) {
  //define handle scope
  HandleScope scope;

  Handle<Value> valueArr[2];
  valueArr[0] = Integer::New(arg0);
  valueArr[1] = Integer::New(arg1);
  
  TryCatch try_catch;
  Handle<Value> result = persistentMotionFunc->Call(GlutFactory::glut_persistent_context->Global(), 2, valueArr);
  if (result.IsEmpty()) {
    String::Utf8Value error(try_catch.Exception());
    fprintf(stderr, "Exception in MotionFunc: %s\n", *error);
  }
}

Handle<Value> GLUTMotionFuncCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1 || !args[0]->IsFunction()) return v8::Undefined();
  //get arguments
  //delete previous assigned function
  persistentMotionFunc.Dispose();
  Handle<Function> value0 = Handle<Function>::Cast(args[0]);
  persistentMotionFunc = Persistent<Function>::New(value0);

  //make call
  glutMotionFunc((void (*)(int x, int y)) funcMotionFunc);
  return v8::Undefined();
}




Persistent<Function> persistentPassiveMotionFunc;

void funcPassiveMotionFunc ( int arg0,int arg1) {
  //define handle scope
  HandleScope scope;

  Handle<Value> valueArr[2];
  valueArr[0] = Integer::New(arg0);
  valueArr[1] = Integer::New(arg1);
  
  TryCatch try_catch;
  Handle<Value> result = persistentPassiveMotionFunc->Call(GlutFactory::glut_persistent_context->Global(), 2, valueArr);
  if (result.IsEmpty()) {
    String::Utf8Value error(try_catch.Exception());
    fprintf(stderr, "Exception in PassiveMotionFunc: %s\n", *error);
  }
}

Handle<Value> GLUTPassiveMotionFuncCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1 || !args[0]->IsFunction()) return v8::Undefined();
  //get arguments
  //delete previous assigned function
  persistentPassiveMotionFunc.Dispose();
  Handle<Function> value0 = Handle<Function>::Cast(args[0]);
  persistentPassiveMotionFunc = Persistent<Function>::New(value0);

  //make call
  glutPassiveMotionFunc((void (*)(int x, int y)) funcPassiveMotionFunc);
  return v8::Undefined();
}




Persistent<Function> persistentEntryFunc;

void funcEntryFunc ( int arg0) {
  //define handle scope
  HandleScope scope;

  Handle<Value> valueArr[1];
  valueArr[0] = Integer::New(arg0);
  
  TryCatch try_catch;
  Handle<Value> result = persistentEntryFunc->Call(GlutFactory::glut_persistent_context->Global(), 1, valueArr);
  if (result.IsEmpty()) {
    String::Utf8Value error(try_catch.Exception());
    fprintf(stderr, "Exception in EntryFunc: %s\n", *error);
  }
}

Handle<Value> GLUTEntryFuncCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1 || !args[0]->IsFunction()) return v8::Undefined();
  //get arguments
  //delete previous assigned function
  persistentEntryFunc.Dispose();
  Handle<Function> value0 = Handle<Function>::Cast(args[0]);
  persistentEntryFunc = Persistent<Function>::New(value0);

  //make call
  glutEntryFunc((void (*)(int state)) funcEntryFunc);
  return v8::Undefined();
}




Persistent<Function> persistentVisibilityFunc;

void funcVisibilityFunc ( int arg0) {
  //define handle scope
  HandleScope scope;

  Handle<Value> valueArr[1];
  valueArr[0] = Integer::New(arg0);
  
  TryCatch try_catch;
  Handle<Value> result = persistentVisibilityFunc->Call(GlutFactory::glut_persistent_context->Global(), 1, valueArr);
  if (result.IsEmpty()) {
    String::Utf8Value error(try_catch.Exception());
    fprintf(stderr, "Exception in VisibilityFunc: %s\n", *error);
  }
}

Handle<Value> GLUTVisibilityFuncCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1 || !args[0]->IsFunction()) return v8::Undefined();
  //get arguments
  //delete previous assigned function
  persistentVisibilityFunc.Dispose();
  Handle<Function> value0 = Handle<Function>::Cast(args[0]);
  persistentVisibilityFunc = Persistent<Function>::New(value0);

  //make call
  glutVisibilityFunc((void (*)(int state)) funcVisibilityFunc);
  return v8::Undefined();
}




Persistent<Function> persistentIdleFunc;

void funcIdleFunc ( ) {
  //define handle scope
  HandleScope scope;

  Handle<Value> valueArr[0];

  
  TryCatch try_catch;
  Handle<Value> result = persistentIdleFunc->Call(GlutFactory::glut_persistent_context->Global(), 0, valueArr);
  if (result.IsEmpty()) {
    String::Utf8Value error(try_catch.Exception());
    fprintf(stderr, "Exception in IdleFunc: %s\n", *error);
  }
}

Handle<Value> GLUTIdleFuncCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1 || !args[0]->IsFunction()) return v8::Undefined();
  //get arguments
  //delete previous assigned function
  persistentIdleFunc.Dispose();
  Handle<Function> value0 = Handle<Function>::Cast(args[0]);
  persistentIdleFunc = Persistent<Function>::New(value0);

  //make call
  glutIdleFunc((void (*)(void)) funcIdleFunc);
  return v8::Undefined();
}



typedef struct {
    int value;
    Persistent<Function> timerFunc;
} timerData;

timerData * persistentTimers[50] = { NULL };

void callbackTimerFunc(int value) {
    timerData * elem = persistentTimers[value];
    if(elem != NULL) {
      //define handle scope
      HandleScope scope;
      Handle<Value> args[1];
      args[0] = Integer::New(elem->value);
      Persistent<Function> timer = elem->timerFunc;
      timer->Call(GlutFactory::glut_persistent_context->Global(), 1, args);

      timer.Dispose();
      delete elem;
      persistentTimers[value] = NULL;
    }
}

Handle<Value> GLUTTimerFuncCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //get arguments
  unsigned int millisec = args[0]->Uint32Value();
  int timerId = args[2]->IntegerValue();

  //find an empty timer spot and place the function there.
  int i = 0;
  bool found = false;
  for(; i < 50; i++) {
      if(persistentTimers[i] == NULL) {
          //get the function
          Handle<Function> value = Handle<Function>::Cast(args[1]);
          Persistent<Function> persistentValue = Persistent<Function>::New(value);
          //assign callback and value values.
          timerData * structElem = new timerData;
          structElem->value = timerId;
          structElem->timerFunc = persistentValue;
          persistentTimers[i] = structElem;
          found = true;
          break;
      }
  }

  //TODO add dynamic resize for persistent Timers
  if(!found) return v8::Undefined();

  //make call
  //Don't pass the actual *value*, but an id to our persistent Function
  glutTimerFunc(( unsigned int ) millisec, (  void (* )( int )) callbackTimerFunc, ( int ) i);
  return v8::Undefined();
}



Persistent<Function> persistentMenuStateFunc;

void funcMenuStateFunc ( int arg0) {
  //define handle scope
  HandleScope scope;

  Handle<Value> valueArr[1];
  valueArr[0] = Integer::New(arg0);
  
  TryCatch try_catch;
  Handle<Value> result = persistentMenuStateFunc->Call(GlutFactory::glut_persistent_context->Global(), 1, valueArr);
  if (result.IsEmpty()) {
    String::Utf8Value error(try_catch.Exception());
    fprintf(stderr, "Exception in MenuStateFunc: %s\n", *error);
  }
}

Handle<Value> GLUTMenuStateFuncCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1 || !args[0]->IsFunction()) return v8::Undefined();
  //get arguments
  //delete previous assigned function
  persistentMenuStateFunc.Dispose();
  Handle<Function> value0 = Handle<Function>::Cast(args[0]);
  persistentMenuStateFunc = Persistent<Function>::New(value0);

  //make call
  glutMenuStateFunc((void (*)(int state)) funcMenuStateFunc);
  return v8::Undefined();
}




Persistent<Function> persistentSpecialFunc;

void funcSpecialFunc ( int arg0,int arg1,int arg2) {
  //define handle scope
  HandleScope scope;

  Handle<Value> valueArr[3];
  valueArr[0] = Integer::New(arg0);
  valueArr[1] = Integer::New(arg1);
  valueArr[2] = Integer::New(arg2);
  
  TryCatch try_catch;
  Handle<Value> result = persistentSpecialFunc->Call(GlutFactory::glut_persistent_context->Global(), 3, valueArr);
  if (result.IsEmpty()) {
    String::Utf8Value error(try_catch.Exception());
    fprintf(stderr, "Exception in SpecialFunc: %s\n", *error);
  }
}

Handle<Value> GLUTSpecialFuncCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1 || !args[0]->IsFunction()) return v8::Undefined();
  //get arguments
  //delete previous assigned function
  persistentSpecialFunc.Dispose();
  Handle<Function> value0 = Handle<Function>::Cast(args[0]);
  persistentSpecialFunc = Persistent<Function>::New(value0);

  //make call
  glutSpecialFunc((void (*)(int key, int x, int y)) funcSpecialFunc);
  return v8::Undefined();
}




Persistent<Function> persistentSpaceballMotionFunc;

void funcSpaceballMotionFunc ( int arg0,int arg1,int arg2) {
  //define handle scope
  HandleScope scope;

  Handle<Value> valueArr[3];
  valueArr[0] = Integer::New(arg0);
  valueArr[1] = Integer::New(arg1);
  valueArr[2] = Integer::New(arg2);
  
  TryCatch try_catch;
  Handle<Value> result = persistentSpaceballMotionFunc->Call(GlutFactory::glut_persistent_context->Global(), 3, valueArr);
  if (result.IsEmpty()) {
    String::Utf8Value error(try_catch.Exception());
    fprintf(stderr, "Exception in SpaceballMotionFunc: %s\n", *error);
  }
}

Handle<Value> GLUTSpaceballMotionFuncCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1 || !args[0]->IsFunction()) return v8::Undefined();
  //get arguments
  //delete previous assigned function
  persistentSpaceballMotionFunc.Dispose();
  Handle<Function> value0 = Handle<Function>::Cast(args[0]);
  persistentSpaceballMotionFunc = Persistent<Function>::New(value0);

  //make call
  glutSpaceballMotionFunc((void (*)(int x, int y, int z)) funcSpaceballMotionFunc);
  return v8::Undefined();
}




Persistent<Function> persistentSpaceballRotateFunc;

void funcSpaceballRotateFunc ( int arg0,int arg1,int arg2) {
  //define handle scope
  HandleScope scope;

  Handle<Value> valueArr[3];
  valueArr[0] = Integer::New(arg0);
  valueArr[1] = Integer::New(arg1);
  valueArr[2] = Integer::New(arg2);
  
  TryCatch try_catch;
  Handle<Value> result = persistentSpaceballRotateFunc->Call(GlutFactory::glut_persistent_context->Global(), 3, valueArr);
  if (result.IsEmpty()) {
    String::Utf8Value error(try_catch.Exception());
    fprintf(stderr, "Exception in SpaceballRotateFunc: %s\n", *error);
  }
}

Handle<Value> GLUTSpaceballRotateFuncCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1 || !args[0]->IsFunction()) return v8::Undefined();
  //get arguments
  //delete previous assigned function
  persistentSpaceballRotateFunc.Dispose();
  Handle<Function> value0 = Handle<Function>::Cast(args[0]);
  persistentSpaceballRotateFunc = Persistent<Function>::New(value0);

  //make call
  glutSpaceballRotateFunc((void (*)(int x, int y, int z)) funcSpaceballRotateFunc);
  return v8::Undefined();
}




Persistent<Function> persistentSpaceballButtonFunc;

void funcSpaceballButtonFunc ( int arg0,int arg1) {
  //define handle scope
  HandleScope scope;

  Handle<Value> valueArr[2];
  valueArr[0] = Integer::New(arg0);
  valueArr[1] = Integer::New(arg1);
  
  TryCatch try_catch;
  Handle<Value> result = persistentSpaceballButtonFunc->Call(GlutFactory::glut_persistent_context->Global(), 2, valueArr);
  if (result.IsEmpty()) {
    String::Utf8Value error(try_catch.Exception());
    fprintf(stderr, "Exception in SpaceballButtonFunc: %s\n", *error);
  }
}

Handle<Value> GLUTSpaceballButtonFuncCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1 || !args[0]->IsFunction()) return v8::Undefined();
  //get arguments
  //delete previous assigned function
  persistentSpaceballButtonFunc.Dispose();
  Handle<Function> value0 = Handle<Function>::Cast(args[0]);
  persistentSpaceballButtonFunc = Persistent<Function>::New(value0);

  //make call
  glutSpaceballButtonFunc((void (*)(int button, int state)) funcSpaceballButtonFunc);
  return v8::Undefined();
}




Persistent<Function> persistentButtonBoxFunc;

void funcButtonBoxFunc ( int arg0,int arg1) {
  //define handle scope
  HandleScope scope;

  Handle<Value> valueArr[2];
  valueArr[0] = Integer::New(arg0);
  valueArr[1] = Integer::New(arg1);
  
  TryCatch try_catch;
  Handle<Value> result = persistentButtonBoxFunc->Call(GlutFactory::glut_persistent_context->Global(), 2, valueArr);
  if (result.IsEmpty()) {
    String::Utf8Value error(try_catch.Exception());
    fprintf(stderr, "Exception in ButtonBoxFunc: %s\n", *error);
  }
}

Handle<Value> GLUTButtonBoxFuncCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1 || !args[0]->IsFunction()) return v8::Undefined();
  //get arguments
  //delete previous assigned function
  persistentButtonBoxFunc.Dispose();
  Handle<Function> value0 = Handle<Function>::Cast(args[0]);
  persistentButtonBoxFunc = Persistent<Function>::New(value0);

  //make call
  glutButtonBoxFunc((void (*)(int button, int state)) funcButtonBoxFunc);
  return v8::Undefined();
}




Persistent<Function> persistentDialsFunc;

void funcDialsFunc ( int arg0,int arg1) {
  //define handle scope
  HandleScope scope;

  Handle<Value> valueArr[2];
  valueArr[0] = Integer::New(arg0);
  valueArr[1] = Integer::New(arg1);
  
  TryCatch try_catch;
  Handle<Value> result = persistentDialsFunc->Call(GlutFactory::glut_persistent_context->Global(), 2, valueArr);
  if (result.IsEmpty()) {
    String::Utf8Value error(try_catch.Exception());
    fprintf(stderr, "Exception in DialsFunc: %s\n", *error);
  }
}

Handle<Value> GLUTDialsFuncCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1 || !args[0]->IsFunction()) return v8::Undefined();
  //get arguments
  //delete previous assigned function
  persistentDialsFunc.Dispose();
  Handle<Function> value0 = Handle<Function>::Cast(args[0]);
  persistentDialsFunc = Persistent<Function>::New(value0);

  //make call
  glutDialsFunc((void (*)(int dial, int value)) funcDialsFunc);
  return v8::Undefined();
}




Persistent<Function> persistentTabletMotionFunc;

void funcTabletMotionFunc ( int arg0,int arg1) {
  //define handle scope
  HandleScope scope;

  Handle<Value> valueArr[2];
  valueArr[0] = Integer::New(arg0);
  valueArr[1] = Integer::New(arg1);
  
  TryCatch try_catch;
  Handle<Value> result = persistentTabletMotionFunc->Call(GlutFactory::glut_persistent_context->Global(), 2, valueArr);
  if (result.IsEmpty()) {
    String::Utf8Value error(try_catch.Exception());
    fprintf(stderr, "Exception in TabletMotionFunc: %s\n", *error);
  }
}

Handle<Value> GLUTTabletMotionFuncCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1 || !args[0]->IsFunction()) return v8::Undefined();
  //get arguments
  //delete previous assigned function
  persistentTabletMotionFunc.Dispose();
  Handle<Function> value0 = Handle<Function>::Cast(args[0]);
  persistentTabletMotionFunc = Persistent<Function>::New(value0);

  //make call
  glutTabletMotionFunc((void (*)(int x, int y)) funcTabletMotionFunc);
  return v8::Undefined();
}




Persistent<Function> persistentTabletButtonFunc;

void funcTabletButtonFunc ( int arg0,int arg1,int arg2,int arg3) {
  //define handle scope
  HandleScope scope;

  Handle<Value> valueArr[4];
  valueArr[0] = Integer::New(arg0);
  valueArr[1] = Integer::New(arg1);
  valueArr[2] = Integer::New(arg2);
  valueArr[3] = Integer::New(arg3);
  
  TryCatch try_catch;
  Handle<Value> result = persistentTabletButtonFunc->Call(GlutFactory::glut_persistent_context->Global(), 4, valueArr);
  if (result.IsEmpty()) {
    String::Utf8Value error(try_catch.Exception());
    fprintf(stderr, "Exception in TabletButtonFunc: %s\n", *error);
  }
}

Handle<Value> GLUTTabletButtonFuncCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1 || !args[0]->IsFunction()) return v8::Undefined();
  //get arguments
  //delete previous assigned function
  persistentTabletButtonFunc.Dispose();
  Handle<Function> value0 = Handle<Function>::Cast(args[0]);
  persistentTabletButtonFunc = Persistent<Function>::New(value0);

  //make call
  glutTabletButtonFunc((void (*)(int button, int state, int x, int y)) funcTabletButtonFunc);
  return v8::Undefined();
}




Persistent<Function> persistentMenuStatusFunc;

void funcMenuStatusFunc ( int arg0,int arg1,int arg2) {
  //define handle scope
  HandleScope scope;

  Handle<Value> valueArr[3];
  valueArr[0] = Integer::New(arg0);
  valueArr[1] = Integer::New(arg1);
  valueArr[2] = Integer::New(arg2);
  
  TryCatch try_catch;
  Handle<Value> result = persistentMenuStatusFunc->Call(GlutFactory::glut_persistent_context->Global(), 3, valueArr);
  if (result.IsEmpty()) {
    String::Utf8Value error(try_catch.Exception());
    fprintf(stderr, "Exception in MenuStatusFunc: %s\n", *error);
  }
}

Handle<Value> GLUTMenuStatusFuncCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1 || !args[0]->IsFunction()) return v8::Undefined();
  //get arguments
  //delete previous assigned function
  persistentMenuStatusFunc.Dispose();
  Handle<Function> value0 = Handle<Function>::Cast(args[0]);
  persistentMenuStatusFunc = Persistent<Function>::New(value0);

  //make call
  glutMenuStatusFunc((void (*)(int status, int x, int y)) funcMenuStatusFunc);
  return v8::Undefined();
}




Persistent<Function> persistentOverlayDisplayFunc;

void funcOverlayDisplayFunc ( ) {
  //define handle scope
  HandleScope scope;

  Handle<Value> valueArr[0];

  
  TryCatch try_catch;
  Handle<Value> result = persistentOverlayDisplayFunc->Call(GlutFactory::glut_persistent_context->Global(), 0, valueArr);
  if (result.IsEmpty()) {
    String::Utf8Value error(try_catch.Exception());
    fprintf(stderr, "Exception in OverlayDisplayFunc: %s\n", *error);
  }
}

Handle<Value> GLUTOverlayDisplayFuncCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1 || !args[0]->IsFunction()) return v8::Undefined();
  //get arguments
  //delete previous assigned function
  persistentOverlayDisplayFunc.Dispose();
  Handle<Function> value0 = Handle<Function>::Cast(args[0]);
  persistentOverlayDisplayFunc = Persistent<Function>::New(value0);

  //make call
  glutOverlayDisplayFunc((void (*)(void)) funcOverlayDisplayFunc);
  return v8::Undefined();
}




Persistent<Function> persistentWindowStatusFunc;

void funcWindowStatusFunc ( int arg0) {
  //define handle scope
  HandleScope scope;

  Handle<Value> valueArr[1];
  valueArr[0] = Integer::New(arg0);
  
  TryCatch try_catch;
  Handle<Value> result = persistentWindowStatusFunc->Call(GlutFactory::glut_persistent_context->Global(), 1, valueArr);
  if (result.IsEmpty()) {
    String::Utf8Value error(try_catch.Exception());
    fprintf(stderr, "Exception in WindowStatusFunc: %s\n", *error);
  }
}

Handle<Value> GLUTWindowStatusFuncCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1 || !args[0]->IsFunction()) return v8::Undefined();
  //get arguments
  //delete previous assigned function
  persistentWindowStatusFunc.Dispose();
  Handle<Function> value0 = Handle<Function>::Cast(args[0]);
  persistentWindowStatusFunc = Persistent<Function>::New(value0);

  //make call
  glutWindowStatusFunc((void (*)(int state)) funcWindowStatusFunc);
  return v8::Undefined();
}




Persistent<Function> persistentKeyboardUpFunc;

void funcKeyboardUpFunc ( unsigned char arg0,int arg1,int arg2) {
  //define handle scope
  HandleScope scope;

  Handle<Value> valueArr[3];
  valueArr[0] = Integer::New(arg0);
  valueArr[1] = Integer::New(arg1);
  valueArr[2] = Integer::New(arg2);
  
  TryCatch try_catch;
  Handle<Value> result = persistentKeyboardUpFunc->Call(GlutFactory::glut_persistent_context->Global(), 3, valueArr);
  if (result.IsEmpty()) {
    String::Utf8Value error(try_catch.Exception());
    fprintf(stderr, "Exception in KeyboardUpFunc: %s\n", *error);
  }
}

Handle<Value> GLUTKeyboardUpFuncCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1 || !args[0]->IsFunction()) return v8::Undefined();
  //get arguments
  //delete previous assigned function
  persistentKeyboardUpFunc.Dispose();
  Handle<Function> value0 = Handle<Function>::Cast(args[0]);
  persistentKeyboardUpFunc = Persistent<Function>::New(value0);

  //make call
  glutKeyboardUpFunc((void (*)(unsigned char key, int x, int y)) funcKeyboardUpFunc);
  return v8::Undefined();
}




Persistent<Function> persistentSpecialUpFunc;

void funcSpecialUpFunc ( int arg0,int arg1,int arg2) {
  //define handle scope
  HandleScope scope;

  Handle<Value> valueArr[3];
  valueArr[0] = Integer::New(arg0);
  valueArr[1] = Integer::New(arg1);
  valueArr[2] = Integer::New(arg2);
  
  TryCatch try_catch;
  Handle<Value> result = persistentSpecialUpFunc->Call(GlutFactory::glut_persistent_context->Global(), 3, valueArr);
  if (result.IsEmpty()) {
    String::Utf8Value error(try_catch.Exception());
    fprintf(stderr, "Exception in SpecialUpFunc: %s\n", *error);
  }
}

Handle<Value> GLUTSpecialUpFuncCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1 || !args[0]->IsFunction()) return v8::Undefined();
  //get arguments
  //delete previous assigned function
  persistentSpecialUpFunc.Dispose();
  Handle<Function> value0 = Handle<Function>::Cast(args[0]);
  persistentSpecialUpFunc = Persistent<Function>::New(value0);

  //make call
  glutSpecialUpFunc((void (*)(int key, int x, int y)) funcSpecialUpFunc);
  return v8::Undefined();
}




Handle<Value> GLUTJoystickFuncCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //get arguments
  Handle<Function> value0 = Handle<Function>::Cast(args[0]);
  void* arg0 = *value0;
  int arg1 = args[1]->IntegerValue();

  //make call
  glutJoystickFunc((void (*)(unsigned int buttonMask, int x, int y, int z))arg0, (int)arg1);
  return v8::Undefined();
}




Handle<Value> GLUTSetColorCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 4) return v8::Undefined();
  //get arguments
  int arg0 = args[0]->Int32Value();
  double arg1 = args[1]->NumberValue();
  double arg2 = args[2]->NumberValue();
  double arg3 = args[3]->NumberValue();

  //make call
  glutSetColor(arg0, (GLfloat)arg1, (GLfloat)arg2, (GLfloat)arg3);
  return v8::Undefined();
}




Handle<Value> GLUTGetColorCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();

  //make call
  glutGetColor((int)arg0, (int)arg1);
  return v8::Undefined();
}




Handle<Value> GLUTCopyColormapCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //get arguments
  int arg0 = args[0]->IntegerValue();

  //make call
  glutCopyColormap((int)arg0);
  return v8::Undefined();
}




Handle<Value> GLUTGetCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //get arguments
  int arg0 = args[0]->IntegerValue();

  //make call
  glutGet((GLenum)arg0);
  return v8::Undefined();
}




Handle<Value> GLUTDeviceGetCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //get arguments
  int arg0 = args[0]->IntegerValue();

  //make call
  glutDeviceGet((GLenum)arg0);
  return v8::Undefined();
}




Handle<Value> GLUTExtensionSupportedCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //get arguments
  String::Utf8Value value0(args[0]);
  char* arg0 = *value0;

  //make call
  glutExtensionSupported((const char*)arg0);
  return v8::Undefined();
}




Handle<Value> GLUTGetModifiersCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 0) return v8::Undefined();
  //get arguments

  //make call
  glutGetModifiers();
  return v8::Undefined();
}




Handle<Value> GLUTLayerGetCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //get arguments
  int arg0 = args[0]->IntegerValue();

  //make call
  glutLayerGet((GLenum)arg0);
  return v8::Undefined();
}




Handle<Value> GLUTBitmapCharacterCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //get arguments
  String::Utf8Value value0(args[0]);
  char* key0 = *value0;
  void* arg0 = font_[key0];
  int arg1 = args[1]->IntegerValue();

  //make call
  glutBitmapCharacter((void*)arg0, (int)arg1);
  return v8::Undefined();
}




Handle<Value> GLUTBitmapWidthCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //get arguments
  String::Utf8Value value0(args[0]);
  char* key0 = *value0;
  void* arg0 = font_[key0];
  int arg1 = args[1]->IntegerValue();

  //make call
  glutBitmapWidth((void*)arg0, (int)arg1);
  return v8::Undefined();
}




Handle<Value> GLUTStrokeCharacterCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //get arguments
  String::Utf8Value value0(args[0]);
  char* key0 = *value0;
  void* arg0 = font_[key0];
  int arg1 = args[1]->IntegerValue();

  //make call
  glutStrokeCharacter((void*)arg0, (int)arg1);
  return v8::Undefined();
}




Handle<Value> GLUTStrokeWidthCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //get arguments
  String::Utf8Value value0(args[0]);
  char* key0 = *value0;
  void* arg0 = font_[key0];
  int arg1 = args[1]->IntegerValue();

  //make call
  glutStrokeWidth((void*)arg0, (int)arg1);
  return v8::Undefined();
}




Handle<Value> GLUTBitmapLengthCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //get arguments
  String::Utf8Value value0(args[0]);
  char* key0 = *value0;
  void* arg0 = font_[key0];
  String::Utf8Value value1(args[1]);
  char* arg1 = *value1;

  //make call
  glutBitmapLength((void*)arg0, (const unsigned char*)arg1);
  return v8::Undefined();
}




Handle<Value> GLUTStrokeLengthCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //get arguments
  String::Utf8Value value0(args[0]);
  char* key0 = *value0;
  void* arg0 = font_[key0];
  String::Utf8Value value1(args[1]);
  char* arg1 = *value1;

  //make call
  glutStrokeLength((void*)arg0, (const unsigned char*)arg1);
  return v8::Undefined();
}




Handle<Value> GLUTWireSphereCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //get arguments
  double arg0 = args[0]->NumberValue();
  int arg1 = args[1]->IntegerValue();
  int arg2 = args[2]->IntegerValue();

  //make call
  glutWireSphere((GLdouble)arg0, (GLint)arg1, (GLint)arg2);
  return v8::Undefined();
}




Handle<Value> GLUTSolidSphereCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //get arguments
  double arg0 = args[0]->NumberValue();
  int arg1 = args[1]->IntegerValue();
  int arg2 = args[2]->IntegerValue();

  //make call
  glutSolidSphere((GLdouble)arg0, (GLint)arg1, (GLint)arg2);
  return v8::Undefined();
}




Handle<Value> GLUTWireConeCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 4) return v8::Undefined();
  //get arguments
  double arg0 = args[0]->NumberValue();
  double arg1 = args[1]->NumberValue();
  int arg2 = args[2]->IntegerValue();
  int arg3 = args[3]->IntegerValue();

  //make call
  glutWireCone((GLdouble)arg0, (GLdouble)arg1, (GLint)arg2, (GLint)arg3);
  return v8::Undefined();
}




Handle<Value> GLUTSolidConeCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 4) return v8::Undefined();
  //get arguments
  double arg0 = args[0]->NumberValue();
  double arg1 = args[1]->NumberValue();
  int arg2 = args[2]->IntegerValue();
  int arg3 = args[3]->IntegerValue();

  //make call
  glutSolidCone((GLdouble)arg0, (GLdouble)arg1, (GLint)arg2, (GLint)arg3);
  return v8::Undefined();
}




Handle<Value> GLUTWireCubeCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //get arguments
  double arg0 = args[0]->NumberValue();

  //make call
  glutWireCube((GLdouble)arg0);
  return v8::Undefined();
}




Handle<Value> GLUTSolidCubeCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //get arguments
  double arg0 = args[0]->NumberValue();

  //make call
  glutSolidCube((GLdouble)arg0);
  return v8::Undefined();
}




Handle<Value> GLUTWireTorusCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 4) return v8::Undefined();
  //get arguments
  double arg0 = args[0]->NumberValue();
  double arg1 = args[1]->NumberValue();
  int arg2 = args[2]->IntegerValue();
  int arg3 = args[3]->IntegerValue();

  //make call
  glutWireTorus((GLdouble)arg0, (GLdouble)arg1, (GLint)arg2, (GLint)arg3);
  return v8::Undefined();
}




Handle<Value> GLUTSolidTorusCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 4) return v8::Undefined();
  //get arguments
  double arg0 = args[0]->NumberValue();
  double arg1 = args[1]->NumberValue();
  int arg2 = args[2]->IntegerValue();
  int arg3 = args[3]->IntegerValue();

  //make call
  glutSolidTorus((GLdouble)arg0, (GLdouble)arg1, (GLint)arg2, (GLint)arg3);
  return v8::Undefined();
}




Handle<Value> GLUTWireDodecahedronCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 0) return v8::Undefined();
  //get arguments

  //make call
  glutWireDodecahedron();
  return v8::Undefined();
}




Handle<Value> GLUTSolidDodecahedronCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 0) return v8::Undefined();
  //get arguments

  //make call
  glutSolidDodecahedron();
  return v8::Undefined();
}




Handle<Value> GLUTWireTeapotCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //get arguments
  double arg0 = args[0]->NumberValue();

  //make call
  glutWireTeapot((GLdouble)arg0);
  return v8::Undefined();
}




Handle<Value> GLUTSolidTeapotCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //get arguments
  double arg0 = args[0]->NumberValue();

  //make call
  glutSolidTeapot((GLdouble)arg0);
  return v8::Undefined();
}




Handle<Value> GLUTWireOctahedronCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 0) return v8::Undefined();
  //get arguments

  //make call
  glutWireOctahedron();
  return v8::Undefined();
}




Handle<Value> GLUTSolidOctahedronCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 0) return v8::Undefined();
  //get arguments

  //make call
  glutSolidOctahedron();
  return v8::Undefined();
}




Handle<Value> GLUTWireTetrahedronCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 0) return v8::Undefined();
  //get arguments

  //make call
  glutWireTetrahedron();
  return v8::Undefined();
}




Handle<Value> GLUTSolidTetrahedronCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 0) return v8::Undefined();
  //get arguments

  //make call
  glutSolidTetrahedron();
  return v8::Undefined();
}




Handle<Value> GLUTWireIcosahedronCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 0) return v8::Undefined();
  //get arguments

  //make call
  glutWireIcosahedron();
  return v8::Undefined();
}




Handle<Value> GLUTSolidIcosahedronCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 0) return v8::Undefined();
  //get arguments

  //make call
  glutSolidIcosahedron();
  return v8::Undefined();
}




Handle<Value> GLUTVideoResizeGetCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //get arguments
  int arg0 = args[0]->IntegerValue();

  //make call
  glutVideoResizeGet((GLenum)arg0);
  return v8::Undefined();
}




Handle<Value> GLUTSetupVideoResizingCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 0) return v8::Undefined();
  //get arguments

  //make call
  glutSetupVideoResizing();
  return v8::Undefined();
}




Handle<Value> GLUTStopVideoResizingCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 0) return v8::Undefined();
  //get arguments

  //make call
  glutStopVideoResizing();
  return v8::Undefined();
}




Handle<Value> GLUTVideoResizeCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 4) return v8::Undefined();
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();
  int arg2 = args[2]->IntegerValue();
  int arg3 = args[3]->IntegerValue();

  //make call
  glutVideoResize((int)arg0, (int)arg1, (int)arg2, (int)arg3);
  return v8::Undefined();
}




Handle<Value> GLUTVideoPanCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 4) return v8::Undefined();
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();
  int arg2 = args[2]->IntegerValue();
  int arg3 = args[3]->IntegerValue();

  //make call
  glutVideoPan((int)arg0, (int)arg1, (int)arg2, (int)arg3);
  return v8::Undefined();
}




Handle<Value> GLUTReportErrorsCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 0) return v8::Undefined();
  //get arguments

  //make call
  glutReportErrors();
  return v8::Undefined();
}




Handle<Value> GetGLUT_KEY_REPEAT_OFF(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_KEY_REPEAT_OFF);
}




Handle<Value> GetGLUT_KEY_REPEAT_ON(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_KEY_REPEAT_ON);
}




Handle<Value> GetGLUT_KEY_REPEAT_DEFAULT(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_KEY_REPEAT_DEFAULT);
}




Handle<Value> GetGLUT_JOYSTICK_BUTTON_A(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_JOYSTICK_BUTTON_A);
}




Handle<Value> GetGLUT_JOYSTICK_BUTTON_B(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_JOYSTICK_BUTTON_B);
}




Handle<Value> GetGLUT_JOYSTICK_BUTTON_C(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_JOYSTICK_BUTTON_C);
}




Handle<Value> GetGLUT_JOYSTICK_BUTTON_D(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_JOYSTICK_BUTTON_D);
}




Handle<Value> GLUTIgnoreKeyRepeatCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //get arguments
  int arg0 = args[0]->IntegerValue();

  //make call
  glutIgnoreKeyRepeat((int)arg0);
  return v8::Undefined();
}




Handle<Value> GLUTSetKeyRepeatCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //get arguments
  int arg0 = args[0]->IntegerValue();

  //make call
  glutSetKeyRepeat((int)arg0);
  return v8::Undefined();
}




Handle<Value> GLUTForceJoystickFuncCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 0) return v8::Undefined();
  //get arguments

  //make call
  glutForceJoystickFunc();
  return v8::Undefined();
}




Handle<Value> GetGLUT_GAME_MODE_ACTIVE(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_GAME_MODE_ACTIVE);
}




Handle<Value> GetGLUT_GAME_MODE_POSSIBLE(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_GAME_MODE_POSSIBLE);
}




Handle<Value> GetGLUT_GAME_MODE_WIDTH(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_GAME_MODE_WIDTH);
}




Handle<Value> GetGLUT_GAME_MODE_HEIGHT(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_GAME_MODE_HEIGHT);
}




Handle<Value> GetGLUT_GAME_MODE_PIXEL_DEPTH(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_GAME_MODE_PIXEL_DEPTH);
}




Handle<Value> GetGLUT_GAME_MODE_REFRESH_RATE(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_GAME_MODE_REFRESH_RATE);
}




Handle<Value> GetGLUT_GAME_MODE_DISPLAY_CHANGED(Local<String> property,
                      const AccessorInfo &info) {
    return Uint32::New(GLUT_GAME_MODE_DISPLAY_CHANGED);
}




Handle<Value> GLUTGameModeStringCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //get arguments
  String::Utf8Value value0(args[0]);
  char* arg0 = *value0;

  //make call
  glutGameModeString((const char*)arg0);
  return v8::Undefined();
}




Handle<Value> GLUTEnterGameModeCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 0) return v8::Undefined();
  //get arguments

  //make call
  glutEnterGameMode();
  return v8::Undefined();
}




Handle<Value> GLUTLeaveGameModeCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 0) return v8::Undefined();
  //get arguments

  //make call
  glutLeaveGameMode();
  return v8::Undefined();
}




Handle<Value> GLUTGameModeGetCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //get arguments
  int arg0 = args[0]->IntegerValue();

  //make call
  glutGameModeGet((GLenum)arg0);
  return v8::Undefined();
}



Handle<ObjectTemplate> GlutFactory::createGlut(int* pargc, char** argv) {
      pargc_ = pargc;
      argv_  = argv;
      
      HandleScope handle_scope;

      Handle<ObjectTemplate> Glut = ObjectTemplate::New();
      Glut->SetInternalFieldCount(1);

     font_["STROKE_ROMAN"] = GLUT_STROKE_ROMAN;

     font_["STROKE_MONO_ROMAN"] = GLUT_STROKE_MONO_ROMAN;

     font_["BITMAP_9_BY_15"] = GLUT_BITMAP_9_BY_15;

     font_["BITMAP_8_BY_13"] = GLUT_BITMAP_8_BY_13;

     font_["BITMAP_TIMES_ROMAN_10"] = GLUT_BITMAP_TIMES_ROMAN_10;

     font_["BITMAP_TIMES_ROMAN_24"] = GLUT_BITMAP_TIMES_ROMAN_24;

     font_["BITMAP_HELVETICA_10"] = GLUT_BITMAP_HELVETICA_10;

     font_["BITMAP_HELVETICA_12"] = GLUT_BITMAP_HELVETICA_12;

     font_["BITMAP_HELVETICA_18"] = GLUT_BITMAP_HELVETICA_18;
     Glut->SetAccessor(String::NewSymbol("APIENTRY_DEFINED"), GetGLUT_APIENTRY_DEFINED);

     Glut->SetAccessor(String::NewSymbol("WINGDIAPI_DEFINED"), GetGLUT_WINGDIAPI_DEFINED);

     Glut->SetAccessor(String::NewSymbol("API_VERSION"), GetGLUT_API_VERSION);

     Glut->SetAccessor(String::NewSymbol("XLIB_IMPLEMENTATION"), GetGLUT_XLIB_IMPLEMENTATION);

     Glut->SetAccessor(String::NewSymbol("MACOSX_IMPLEMENTATION"), GetGLUT_MACOSX_IMPLEMENTATION);

     Glut->SetAccessor(String::NewSymbol("RGB"), GetGLUT_RGB);

     Glut->SetAccessor(String::NewSymbol("RGBA"), GetGLUT_RGBA);

     Glut->SetAccessor(String::NewSymbol("INDEX"), GetGLUT_INDEX);

     Glut->SetAccessor(String::NewSymbol("SINGLE"), GetGLUT_SINGLE);

     Glut->SetAccessor(String::NewSymbol("DOUBLE"), GetGLUT_DOUBLE);

     Glut->SetAccessor(String::NewSymbol("ACCUM"), GetGLUT_ACCUM);

     Glut->SetAccessor(String::NewSymbol("ALPHA"), GetGLUT_ALPHA);

     Glut->SetAccessor(String::NewSymbol("DEPTH"), GetGLUT_DEPTH);

     Glut->SetAccessor(String::NewSymbol("STENCIL"), GetGLUT_STENCIL);

     Glut->SetAccessor(String::NewSymbol("MULTISAMPLE"), GetGLUT_MULTISAMPLE);

     Glut->SetAccessor(String::NewSymbol("STEREO"), GetGLUT_STEREO);

     Glut->SetAccessor(String::NewSymbol("LUMINANCE"), GetGLUT_LUMINANCE);

     Glut->SetAccessor(String::NewSymbol("NO_RECOVERY"), GetGLUT_NO_RECOVERY);

     Glut->SetAccessor(String::NewSymbol("LEFT_BUTTON"), GetGLUT_LEFT_BUTTON);

     Glut->SetAccessor(String::NewSymbol("MIDDLE_BUTTON"), GetGLUT_MIDDLE_BUTTON);

     Glut->SetAccessor(String::NewSymbol("RIGHT_BUTTON"), GetGLUT_RIGHT_BUTTON);

     Glut->SetAccessor(String::NewSymbol("DOWN"), GetGLUT_DOWN);

     Glut->SetAccessor(String::NewSymbol("UP"), GetGLUT_UP);

     Glut->SetAccessor(String::NewSymbol("KEY_F1"), GetGLUT_KEY_F1);

     Glut->SetAccessor(String::NewSymbol("KEY_F2"), GetGLUT_KEY_F2);

     Glut->SetAccessor(String::NewSymbol("KEY_F3"), GetGLUT_KEY_F3);

     Glut->SetAccessor(String::NewSymbol("KEY_F4"), GetGLUT_KEY_F4);

     Glut->SetAccessor(String::NewSymbol("KEY_F5"), GetGLUT_KEY_F5);

     Glut->SetAccessor(String::NewSymbol("KEY_F6"), GetGLUT_KEY_F6);

     Glut->SetAccessor(String::NewSymbol("KEY_F7"), GetGLUT_KEY_F7);

     Glut->SetAccessor(String::NewSymbol("KEY_F8"), GetGLUT_KEY_F8);

     Glut->SetAccessor(String::NewSymbol("KEY_F9"), GetGLUT_KEY_F9);

     Glut->SetAccessor(String::NewSymbol("KEY_F10"), GetGLUT_KEY_F10);

     Glut->SetAccessor(String::NewSymbol("KEY_F11"), GetGLUT_KEY_F11);

     Glut->SetAccessor(String::NewSymbol("KEY_F12"), GetGLUT_KEY_F12);

     Glut->SetAccessor(String::NewSymbol("KEY_LEFT"), GetGLUT_KEY_LEFT);

     Glut->SetAccessor(String::NewSymbol("KEY_UP"), GetGLUT_KEY_UP);

     Glut->SetAccessor(String::NewSymbol("KEY_RIGHT"), GetGLUT_KEY_RIGHT);

     Glut->SetAccessor(String::NewSymbol("KEY_DOWN"), GetGLUT_KEY_DOWN);

     Glut->SetAccessor(String::NewSymbol("KEY_PAGE_UP"), GetGLUT_KEY_PAGE_UP);

     Glut->SetAccessor(String::NewSymbol("KEY_PAGE_DOWN"), GetGLUT_KEY_PAGE_DOWN);

     Glut->SetAccessor(String::NewSymbol("KEY_HOME"), GetGLUT_KEY_HOME);

     Glut->SetAccessor(String::NewSymbol("KEY_END"), GetGLUT_KEY_END);

     Glut->SetAccessor(String::NewSymbol("KEY_INSERT"), GetGLUT_KEY_INSERT);

     Glut->SetAccessor(String::NewSymbol("LEFT"), GetGLUT_LEFT);

     Glut->SetAccessor(String::NewSymbol("ENTERED"), GetGLUT_ENTERED);

     Glut->SetAccessor(String::NewSymbol("MENU_NOT_IN_USE"), GetGLUT_MENU_NOT_IN_USE);

     Glut->SetAccessor(String::NewSymbol("MENU_IN_USE"), GetGLUT_MENU_IN_USE);

     Glut->SetAccessor(String::NewSymbol("NOT_VISIBLE"), GetGLUT_NOT_VISIBLE);

     Glut->SetAccessor(String::NewSymbol("VISIBLE"), GetGLUT_VISIBLE);

     Glut->SetAccessor(String::NewSymbol("HIDDEN"), GetGLUT_HIDDEN);

     Glut->SetAccessor(String::NewSymbol("FULLY_RETAINED"), GetGLUT_FULLY_RETAINED);

     Glut->SetAccessor(String::NewSymbol("PARTIALLY_RETAINED"), GetGLUT_PARTIALLY_RETAINED);

     Glut->SetAccessor(String::NewSymbol("FULLY_COVERED"), GetGLUT_FULLY_COVERED);

     Glut->SetAccessor(String::NewSymbol("RED"), GetGLUT_RED);

     Glut->SetAccessor(String::NewSymbol("GREEN"), GetGLUT_GREEN);

     Glut->SetAccessor(String::NewSymbol("BLUE"), GetGLUT_BLUE);

     Glut->SetAccessor(String::NewSymbol("NORMAL"), GetGLUT_NORMAL);

     Glut->SetAccessor(String::NewSymbol("OVERLAY"), GetGLUT_OVERLAY);

     Glut->SetAccessor(String::NewSymbol("STROKE_ROMAN"), GetGLUT_STROKE_ROMAN);

     Glut->SetAccessor(String::NewSymbol("STROKE_MONO_ROMAN"), GetGLUT_STROKE_MONO_ROMAN);

     Glut->SetAccessor(String::NewSymbol("BITMAP_9_BY_15"), GetGLUT_BITMAP_9_BY_15);

     Glut->SetAccessor(String::NewSymbol("BITMAP_8_BY_13"), GetGLUT_BITMAP_8_BY_13);

     Glut->SetAccessor(String::NewSymbol("BITMAP_TIMES_ROMAN_10"), GetGLUT_BITMAP_TIMES_ROMAN_10);

     Glut->SetAccessor(String::NewSymbol("BITMAP_TIMES_ROMAN_24"), GetGLUT_BITMAP_TIMES_ROMAN_24);

     Glut->SetAccessor(String::NewSymbol("BITMAP_HELVETICA_10"), GetGLUT_BITMAP_HELVETICA_10);

     Glut->SetAccessor(String::NewSymbol("BITMAP_HELVETICA_12"), GetGLUT_BITMAP_HELVETICA_12);

     Glut->SetAccessor(String::NewSymbol("BITMAP_HELVETICA_18"), GetGLUT_BITMAP_HELVETICA_18);

     Glut->SetAccessor(String::NewSymbol("WINDOW_X"), GetGLUT_WINDOW_X);

     Glut->SetAccessor(String::NewSymbol("WINDOW_Y"), GetGLUT_WINDOW_Y);

     Glut->SetAccessor(String::NewSymbol("WINDOW_WIDTH"), GetGLUT_WINDOW_WIDTH);

     Glut->SetAccessor(String::NewSymbol("WINDOW_HEIGHT"), GetGLUT_WINDOW_HEIGHT);

     Glut->SetAccessor(String::NewSymbol("WINDOW_BUFFER_SIZE"), GetGLUT_WINDOW_BUFFER_SIZE);

     Glut->SetAccessor(String::NewSymbol("WINDOW_STENCIL_SIZE"), GetGLUT_WINDOW_STENCIL_SIZE);

     Glut->SetAccessor(String::NewSymbol("WINDOW_DEPTH_SIZE"), GetGLUT_WINDOW_DEPTH_SIZE);

     Glut->SetAccessor(String::NewSymbol("WINDOW_RED_SIZE"), GetGLUT_WINDOW_RED_SIZE);

     Glut->SetAccessor(String::NewSymbol("WINDOW_GREEN_SIZE"), GetGLUT_WINDOW_GREEN_SIZE);

     Glut->SetAccessor(String::NewSymbol("WINDOW_BLUE_SIZE"), GetGLUT_WINDOW_BLUE_SIZE);

     Glut->SetAccessor(String::NewSymbol("WINDOW_ALPHA_SIZE"), GetGLUT_WINDOW_ALPHA_SIZE);

     Glut->SetAccessor(String::NewSymbol("WINDOW_ACCUM_RED_SIZE"), GetGLUT_WINDOW_ACCUM_RED_SIZE);

     Glut->SetAccessor(String::NewSymbol("WINDOW_ACCUM_GREEN_SIZE"), GetGLUT_WINDOW_ACCUM_GREEN_SIZE);

     Glut->SetAccessor(String::NewSymbol("WINDOW_ACCUM_BLUE_SIZE"), GetGLUT_WINDOW_ACCUM_BLUE_SIZE);

     Glut->SetAccessor(String::NewSymbol("WINDOW_ACCUM_ALPHA_SIZE"), GetGLUT_WINDOW_ACCUM_ALPHA_SIZE);

     Glut->SetAccessor(String::NewSymbol("WINDOW_DOUBLEBUFFER"), GetGLUT_WINDOW_DOUBLEBUFFER);

     Glut->SetAccessor(String::NewSymbol("WINDOW_RGBA"), GetGLUT_WINDOW_RGBA);

     Glut->SetAccessor(String::NewSymbol("WINDOW_PARENT"), GetGLUT_WINDOW_PARENT);

     Glut->SetAccessor(String::NewSymbol("WINDOW_NUM_CHILDREN"), GetGLUT_WINDOW_NUM_CHILDREN);

     Glut->SetAccessor(String::NewSymbol("WINDOW_COLORMAP_SIZE"), GetGLUT_WINDOW_COLORMAP_SIZE);

     Glut->SetAccessor(String::NewSymbol("WINDOW_NUM_SAMPLES"), GetGLUT_WINDOW_NUM_SAMPLES);

     Glut->SetAccessor(String::NewSymbol("WINDOW_STEREO"), GetGLUT_WINDOW_STEREO);

     Glut->SetAccessor(String::NewSymbol("WINDOW_CURSOR"), GetGLUT_WINDOW_CURSOR);

     Glut->SetAccessor(String::NewSymbol("SCREEN_WIDTH"), GetGLUT_SCREEN_WIDTH);

     Glut->SetAccessor(String::NewSymbol("SCREEN_HEIGHT"), GetGLUT_SCREEN_HEIGHT);

     Glut->SetAccessor(String::NewSymbol("SCREEN_WIDTH_MM"), GetGLUT_SCREEN_WIDTH_MM);

     Glut->SetAccessor(String::NewSymbol("SCREEN_HEIGHT_MM"), GetGLUT_SCREEN_HEIGHT_MM);

     Glut->SetAccessor(String::NewSymbol("MENU_NUM_ITEMS"), GetGLUT_MENU_NUM_ITEMS);

     Glut->SetAccessor(String::NewSymbol("DISPLAY_MODE_POSSIBLE"), GetGLUT_DISPLAY_MODE_POSSIBLE);

     Glut->SetAccessor(String::NewSymbol("INIT_WINDOW_X"), GetGLUT_INIT_WINDOW_X);

     Glut->SetAccessor(String::NewSymbol("INIT_WINDOW_Y"), GetGLUT_INIT_WINDOW_Y);

     Glut->SetAccessor(String::NewSymbol("INIT_WINDOW_WIDTH"), GetGLUT_INIT_WINDOW_WIDTH);

     Glut->SetAccessor(String::NewSymbol("INIT_WINDOW_HEIGHT"), GetGLUT_INIT_WINDOW_HEIGHT);

     Glut->SetAccessor(String::NewSymbol("INIT_DISPLAY_MODE"), GetGLUT_INIT_DISPLAY_MODE);

     Glut->SetAccessor(String::NewSymbol("ELAPSED_TIME"), GetGLUT_ELAPSED_TIME);

     Glut->SetAccessor(String::NewSymbol("WINDOW_FORMAT_ID"), GetGLUT_WINDOW_FORMAT_ID);

     Glut->SetAccessor(String::NewSymbol("HAS_KEYBOARD"), GetGLUT_HAS_KEYBOARD);

     Glut->SetAccessor(String::NewSymbol("HAS_MOUSE"), GetGLUT_HAS_MOUSE);

     Glut->SetAccessor(String::NewSymbol("HAS_SPACEBALL"), GetGLUT_HAS_SPACEBALL);

     Glut->SetAccessor(String::NewSymbol("HAS_DIAL_AND_BUTTON_BOX"), GetGLUT_HAS_DIAL_AND_BUTTON_BOX);

     Glut->SetAccessor(String::NewSymbol("HAS_TABLET"), GetGLUT_HAS_TABLET);

     Glut->SetAccessor(String::NewSymbol("NUM_MOUSE_BUTTONS"), GetGLUT_NUM_MOUSE_BUTTONS);

     Glut->SetAccessor(String::NewSymbol("NUM_SPACEBALL_BUTTONS"), GetGLUT_NUM_SPACEBALL_BUTTONS);

     Glut->SetAccessor(String::NewSymbol("NUM_BUTTON_BOX_BUTTONS"), GetGLUT_NUM_BUTTON_BOX_BUTTONS);

     Glut->SetAccessor(String::NewSymbol("NUM_DIALS"), GetGLUT_NUM_DIALS);

     Glut->SetAccessor(String::NewSymbol("NUM_TABLET_BUTTONS"), GetGLUT_NUM_TABLET_BUTTONS);

     Glut->SetAccessor(String::NewSymbol("DEVICE_IGNORE_KEY_REPEAT"), GetGLUT_DEVICE_IGNORE_KEY_REPEAT);

     Glut->SetAccessor(String::NewSymbol("DEVICE_KEY_REPEAT"), GetGLUT_DEVICE_KEY_REPEAT);

     Glut->SetAccessor(String::NewSymbol("HAS_JOYSTICK"), GetGLUT_HAS_JOYSTICK);

     Glut->SetAccessor(String::NewSymbol("OWNS_JOYSTICK"), GetGLUT_OWNS_JOYSTICK);

     Glut->SetAccessor(String::NewSymbol("JOYSTICK_BUTTONS"), GetGLUT_JOYSTICK_BUTTONS);

     Glut->SetAccessor(String::NewSymbol("JOYSTICK_AXES"), GetGLUT_JOYSTICK_AXES);

     Glut->SetAccessor(String::NewSymbol("JOYSTICK_POLL_RATE"), GetGLUT_JOYSTICK_POLL_RATE);

     Glut->SetAccessor(String::NewSymbol("OVERLAY_POSSIBLE"), GetGLUT_OVERLAY_POSSIBLE);

     Glut->SetAccessor(String::NewSymbol("LAYER_IN_USE"), GetGLUT_LAYER_IN_USE);

     Glut->SetAccessor(String::NewSymbol("HAS_OVERLAY"), GetGLUT_HAS_OVERLAY);

     Glut->SetAccessor(String::NewSymbol("TRANSPARENT_INDEX"), GetGLUT_TRANSPARENT_INDEX);

     Glut->SetAccessor(String::NewSymbol("NORMAL_DAMAGED"), GetGLUT_NORMAL_DAMAGED);

     Glut->SetAccessor(String::NewSymbol("OVERLAY_DAMAGED"), GetGLUT_OVERLAY_DAMAGED);

     Glut->SetAccessor(String::NewSymbol("VIDEO_RESIZE_POSSIBLE"), GetGLUT_VIDEO_RESIZE_POSSIBLE);

     Glut->SetAccessor(String::NewSymbol("VIDEO_RESIZE_IN_USE"), GetGLUT_VIDEO_RESIZE_IN_USE);

     Glut->SetAccessor(String::NewSymbol("VIDEO_RESIZE_X_DELTA"), GetGLUT_VIDEO_RESIZE_X_DELTA);

     Glut->SetAccessor(String::NewSymbol("VIDEO_RESIZE_Y_DELTA"), GetGLUT_VIDEO_RESIZE_Y_DELTA);

     Glut->SetAccessor(String::NewSymbol("VIDEO_RESIZE_WIDTH_DELTA"), GetGLUT_VIDEO_RESIZE_WIDTH_DELTA);

     Glut->SetAccessor(String::NewSymbol("VIDEO_RESIZE_HEIGHT_DELTA"), GetGLUT_VIDEO_RESIZE_HEIGHT_DELTA);

     Glut->SetAccessor(String::NewSymbol("VIDEO_RESIZE_X"), GetGLUT_VIDEO_RESIZE_X);

     Glut->SetAccessor(String::NewSymbol("VIDEO_RESIZE_Y"), GetGLUT_VIDEO_RESIZE_Y);

     Glut->SetAccessor(String::NewSymbol("VIDEO_RESIZE_WIDTH"), GetGLUT_VIDEO_RESIZE_WIDTH);

     Glut->SetAccessor(String::NewSymbol("VIDEO_RESIZE_HEIGHT"), GetGLUT_VIDEO_RESIZE_HEIGHT);

     Glut->SetAccessor(String::NewSymbol("ACTIVE_SHIFT"), GetGLUT_ACTIVE_SHIFT);

     Glut->SetAccessor(String::NewSymbol("ACTIVE_CTRL"), GetGLUT_ACTIVE_CTRL);

     Glut->SetAccessor(String::NewSymbol("ACTIVE_ALT"), GetGLUT_ACTIVE_ALT);

     Glut->SetAccessor(String::NewSymbol("CURSOR_RIGHT_ARROW"), GetGLUT_CURSOR_RIGHT_ARROW);

     Glut->SetAccessor(String::NewSymbol("CURSOR_LEFT_ARROW"), GetGLUT_CURSOR_LEFT_ARROW);

     Glut->SetAccessor(String::NewSymbol("CURSOR_INFO"), GetGLUT_CURSOR_INFO);

     Glut->SetAccessor(String::NewSymbol("CURSOR_DESTROY"), GetGLUT_CURSOR_DESTROY);

     Glut->SetAccessor(String::NewSymbol("CURSOR_HELP"), GetGLUT_CURSOR_HELP);

     Glut->SetAccessor(String::NewSymbol("CURSOR_CYCLE"), GetGLUT_CURSOR_CYCLE);

     Glut->SetAccessor(String::NewSymbol("CURSOR_SPRAY"), GetGLUT_CURSOR_SPRAY);

     Glut->SetAccessor(String::NewSymbol("CURSOR_WAIT"), GetGLUT_CURSOR_WAIT);

     Glut->SetAccessor(String::NewSymbol("CURSOR_TEXT"), GetGLUT_CURSOR_TEXT);

     Glut->SetAccessor(String::NewSymbol("CURSOR_CROSSHAIR"), GetGLUT_CURSOR_CROSSHAIR);

     Glut->SetAccessor(String::NewSymbol("CURSOR_UP_DOWN"), GetGLUT_CURSOR_UP_DOWN);

     Glut->SetAccessor(String::NewSymbol("CURSOR_LEFT_RIGHT"), GetGLUT_CURSOR_LEFT_RIGHT);

     Glut->SetAccessor(String::NewSymbol("CURSOR_TOP_SIDE"), GetGLUT_CURSOR_TOP_SIDE);

     Glut->SetAccessor(String::NewSymbol("CURSOR_BOTTOM_SIDE"), GetGLUT_CURSOR_BOTTOM_SIDE);

     Glut->SetAccessor(String::NewSymbol("CURSOR_LEFT_SIDE"), GetGLUT_CURSOR_LEFT_SIDE);

     Glut->SetAccessor(String::NewSymbol("CURSOR_RIGHT_SIDE"), GetGLUT_CURSOR_RIGHT_SIDE);

     Glut->SetAccessor(String::NewSymbol("CURSOR_TOP_LEFT_CORNER"), GetGLUT_CURSOR_TOP_LEFT_CORNER);

     Glut->SetAccessor(String::NewSymbol("CURSOR_TOP_RIGHT_CORNER"), GetGLUT_CURSOR_TOP_RIGHT_CORNER);

     Glut->SetAccessor(String::NewSymbol("CURSOR_BOTTOM_RIGHT_CORNER"), GetGLUT_CURSOR_BOTTOM_RIGHT_CORNER);

     Glut->SetAccessor(String::NewSymbol("CURSOR_BOTTOM_LEFT_CORNER"), GetGLUT_CURSOR_BOTTOM_LEFT_CORNER);

     Glut->SetAccessor(String::NewSymbol("CURSOR_INHERIT"), GetGLUT_CURSOR_INHERIT);

     Glut->SetAccessor(String::NewSymbol("CURSOR_NONE"), GetGLUT_CURSOR_NONE);

     Glut->SetAccessor(String::NewSymbol("CURSOR_FULL_CROSSHAIR"), GetGLUT_CURSOR_FULL_CROSSHAIR);

     Glut->SetAccessor(String::NewSymbol("KEY_REPEAT_OFF"), GetGLUT_KEY_REPEAT_OFF);

     Glut->SetAccessor(String::NewSymbol("KEY_REPEAT_ON"), GetGLUT_KEY_REPEAT_ON);

     Glut->SetAccessor(String::NewSymbol("KEY_REPEAT_DEFAULT"), GetGLUT_KEY_REPEAT_DEFAULT);

     Glut->SetAccessor(String::NewSymbol("JOYSTICK_BUTTON_A"), GetGLUT_JOYSTICK_BUTTON_A);

     Glut->SetAccessor(String::NewSymbol("JOYSTICK_BUTTON_B"), GetGLUT_JOYSTICK_BUTTON_B);

     Glut->SetAccessor(String::NewSymbol("JOYSTICK_BUTTON_C"), GetGLUT_JOYSTICK_BUTTON_C);

     Glut->SetAccessor(String::NewSymbol("JOYSTICK_BUTTON_D"), GetGLUT_JOYSTICK_BUTTON_D);

     Glut->SetAccessor(String::NewSymbol("GAME_MODE_ACTIVE"), GetGLUT_GAME_MODE_ACTIVE);

     Glut->SetAccessor(String::NewSymbol("GAME_MODE_POSSIBLE"), GetGLUT_GAME_MODE_POSSIBLE);

     Glut->SetAccessor(String::NewSymbol("GAME_MODE_WIDTH"), GetGLUT_GAME_MODE_WIDTH);

     Glut->SetAccessor(String::NewSymbol("GAME_MODE_HEIGHT"), GetGLUT_GAME_MODE_HEIGHT);

     Glut->SetAccessor(String::NewSymbol("GAME_MODE_PIXEL_DEPTH"), GetGLUT_GAME_MODE_PIXEL_DEPTH);

     Glut->SetAccessor(String::NewSymbol("GAME_MODE_REFRESH_RATE"), GetGLUT_GAME_MODE_REFRESH_RATE);

     Glut->SetAccessor(String::NewSymbol("GAME_MODE_DISPLAY_CHANGED"), GetGLUT_GAME_MODE_DISPLAY_CHANGED);
     Glut->Set(String::NewSymbol("init"), FunctionTemplate::New(GLUTInitCallback));

     Glut->Set(String::NewSymbol("initDisplayMode"), FunctionTemplate::New(GLUTInitDisplayModeCallback));

     Glut->Set(String::NewSymbol("initDisplayString"), FunctionTemplate::New(GLUTInitDisplayStringCallback));

     Glut->Set(String::NewSymbol("initWindowPosition"), FunctionTemplate::New(GLUTInitWindowPositionCallback));

     Glut->Set(String::NewSymbol("initWindowSize"), FunctionTemplate::New(GLUTInitWindowSizeCallback));

     Glut->Set(String::NewSymbol("mainLoop"), FunctionTemplate::New(GLUTMainLoopCallback));

     Glut->Set(String::NewSymbol("createWindow"), FunctionTemplate::New(GLUTCreateWindowCallback));

     Glut->Set(String::NewSymbol("createSubWindow"), FunctionTemplate::New(GLUTCreateSubWindowCallback));

     Glut->Set(String::NewSymbol("destroyWindow"), FunctionTemplate::New(GLUTDestroyWindowCallback));

     Glut->Set(String::NewSymbol("postRedisplay"), FunctionTemplate::New(GLUTPostRedisplayCallback));

     Glut->Set(String::NewSymbol("postWindowRedisplay"), FunctionTemplate::New(GLUTPostWindowRedisplayCallback));

     Glut->Set(String::NewSymbol("swapBuffers"), FunctionTemplate::New(GLUTSwapBuffersCallback));

     Glut->Set(String::NewSymbol("getWindow"), FunctionTemplate::New(GLUTGetWindowCallback));

     Glut->Set(String::NewSymbol("setWindow"), FunctionTemplate::New(GLUTSetWindowCallback));

     Glut->Set(String::NewSymbol("setWindowTitle"), FunctionTemplate::New(GLUTSetWindowTitleCallback));

     Glut->Set(String::NewSymbol("setIconTitle"), FunctionTemplate::New(GLUTSetIconTitleCallback));

     Glut->Set(String::NewSymbol("positionWindow"), FunctionTemplate::New(GLUTPositionWindowCallback));

     Glut->Set(String::NewSymbol("reshapeWindow"), FunctionTemplate::New(GLUTReshapeWindowCallback));

     Glut->Set(String::NewSymbol("popWindow"), FunctionTemplate::New(GLUTPopWindowCallback));

     Glut->Set(String::NewSymbol("pushWindow"), FunctionTemplate::New(GLUTPushWindowCallback));

     Glut->Set(String::NewSymbol("iconifyWindow"), FunctionTemplate::New(GLUTIconifyWindowCallback));

     Glut->Set(String::NewSymbol("showWindow"), FunctionTemplate::New(GLUTShowWindowCallback));

     Glut->Set(String::NewSymbol("hideWindow"), FunctionTemplate::New(GLUTHideWindowCallback));

     Glut->Set(String::NewSymbol("fullScreen"), FunctionTemplate::New(GLUTFullScreenCallback));

     Glut->Set(String::NewSymbol("setCursor"), FunctionTemplate::New(GLUTSetCursorCallback));

     Glut->Set(String::NewSymbol("warpPointer"), FunctionTemplate::New(GLUTWarpPointerCallback));

     Glut->Set(String::NewSymbol("wMCloseFunc"), FunctionTemplate::New(GLUTWMCloseFuncCallback));

     Glut->Set(String::NewSymbol("checkLoop"), FunctionTemplate::New(GLUTCheckLoopCallback));

     Glut->Set(String::NewSymbol("establishOverlay"), FunctionTemplate::New(GLUTEstablishOverlayCallback));

     Glut->Set(String::NewSymbol("removeOverlay"), FunctionTemplate::New(GLUTRemoveOverlayCallback));

     Glut->Set(String::NewSymbol("useLayer"), FunctionTemplate::New(GLUTUseLayerCallback));

     Glut->Set(String::NewSymbol("postOverlayRedisplay"), FunctionTemplate::New(GLUTPostOverlayRedisplayCallback));

     Glut->Set(String::NewSymbol("postWindowOverlayRedisplay"), FunctionTemplate::New(GLUTPostWindowOverlayRedisplayCallback));

     Glut->Set(String::NewSymbol("showOverlay"), FunctionTemplate::New(GLUTShowOverlayCallback));

     Glut->Set(String::NewSymbol("hideOverlay"), FunctionTemplate::New(GLUTHideOverlayCallback));

     Glut->Set(String::NewSymbol("createMenu"), FunctionTemplate::New(GLUTCreateMenuCallback));

     Glut->Set(String::NewSymbol("destroyMenu"), FunctionTemplate::New(GLUTDestroyMenuCallback));

     Glut->Set(String::NewSymbol("getMenu"), FunctionTemplate::New(GLUTGetMenuCallback));

     Glut->Set(String::NewSymbol("setMenu"), FunctionTemplate::New(GLUTSetMenuCallback));

     Glut->Set(String::NewSymbol("addMenuEntry"), FunctionTemplate::New(GLUTAddMenuEntryCallback));

     Glut->Set(String::NewSymbol("addSubMenu"), FunctionTemplate::New(GLUTAddSubMenuCallback));

     Glut->Set(String::NewSymbol("changeToMenuEntry"), FunctionTemplate::New(GLUTChangeToMenuEntryCallback));

     Glut->Set(String::NewSymbol("changeToSubMenu"), FunctionTemplate::New(GLUTChangeToSubMenuCallback));

     Glut->Set(String::NewSymbol("removeMenuItem"), FunctionTemplate::New(GLUTRemoveMenuItemCallback));

     Glut->Set(String::NewSymbol("attachMenu"), FunctionTemplate::New(GLUTAttachMenuCallback));

     Glut->Set(String::NewSymbol("detachMenu"), FunctionTemplate::New(GLUTDetachMenuCallback));

     Glut->Set(String::NewSymbol("displayFunc"), FunctionTemplate::New(GLUTDisplayFuncCallback));

     Glut->Set(String::NewSymbol("reshapeFunc"), FunctionTemplate::New(GLUTReshapeFuncCallback));

     Glut->Set(String::NewSymbol("keyboardFunc"), FunctionTemplate::New(GLUTKeyboardFuncCallback));

     Glut->Set(String::NewSymbol("mouseFunc"), FunctionTemplate::New(GLUTMouseFuncCallback));

     Glut->Set(String::NewSymbol("motionFunc"), FunctionTemplate::New(GLUTMotionFuncCallback));

     Glut->Set(String::NewSymbol("passiveMotionFunc"), FunctionTemplate::New(GLUTPassiveMotionFuncCallback));

     Glut->Set(String::NewSymbol("entryFunc"), FunctionTemplate::New(GLUTEntryFuncCallback));

     Glut->Set(String::NewSymbol("visibilityFunc"), FunctionTemplate::New(GLUTVisibilityFuncCallback));

     Glut->Set(String::NewSymbol("idleFunc"), FunctionTemplate::New(GLUTIdleFuncCallback));

     Glut->Set(String::NewSymbol("timerFunc"), FunctionTemplate::New(GLUTTimerFuncCallback));

     Glut->Set(String::NewSymbol("menuStateFunc"), FunctionTemplate::New(GLUTMenuStateFuncCallback));

     Glut->Set(String::NewSymbol("specialFunc"), FunctionTemplate::New(GLUTSpecialFuncCallback));

     Glut->Set(String::NewSymbol("spaceballMotionFunc"), FunctionTemplate::New(GLUTSpaceballMotionFuncCallback));

     Glut->Set(String::NewSymbol("spaceballRotateFunc"), FunctionTemplate::New(GLUTSpaceballRotateFuncCallback));

     Glut->Set(String::NewSymbol("spaceballButtonFunc"), FunctionTemplate::New(GLUTSpaceballButtonFuncCallback));

     Glut->Set(String::NewSymbol("buttonBoxFunc"), FunctionTemplate::New(GLUTButtonBoxFuncCallback));

     Glut->Set(String::NewSymbol("dialsFunc"), FunctionTemplate::New(GLUTDialsFuncCallback));

     Glut->Set(String::NewSymbol("tabletMotionFunc"), FunctionTemplate::New(GLUTTabletMotionFuncCallback));

     Glut->Set(String::NewSymbol("tabletButtonFunc"), FunctionTemplate::New(GLUTTabletButtonFuncCallback));

     Glut->Set(String::NewSymbol("menuStatusFunc"), FunctionTemplate::New(GLUTMenuStatusFuncCallback));

     Glut->Set(String::NewSymbol("overlayDisplayFunc"), FunctionTemplate::New(GLUTOverlayDisplayFuncCallback));

     Glut->Set(String::NewSymbol("windowStatusFunc"), FunctionTemplate::New(GLUTWindowStatusFuncCallback));

     Glut->Set(String::NewSymbol("keyboardUpFunc"), FunctionTemplate::New(GLUTKeyboardUpFuncCallback));

     Glut->Set(String::NewSymbol("specialUpFunc"), FunctionTemplate::New(GLUTSpecialUpFuncCallback));

     Glut->Set(String::NewSymbol("joystickFunc"), FunctionTemplate::New(GLUTJoystickFuncCallback));

     Glut->Set(String::NewSymbol("setColor"), FunctionTemplate::New(GLUTSetColorCallback));

     Glut->Set(String::NewSymbol("getColor"), FunctionTemplate::New(GLUTGetColorCallback));

     Glut->Set(String::NewSymbol("copyColormap"), FunctionTemplate::New(GLUTCopyColormapCallback));

     Glut->Set(String::NewSymbol("get"), FunctionTemplate::New(GLUTGetCallback));

     Glut->Set(String::NewSymbol("deviceGet"), FunctionTemplate::New(GLUTDeviceGetCallback));

     Glut->Set(String::NewSymbol("extensionSupported"), FunctionTemplate::New(GLUTExtensionSupportedCallback));

     Glut->Set(String::NewSymbol("getModifiers"), FunctionTemplate::New(GLUTGetModifiersCallback));

     Glut->Set(String::NewSymbol("layerGet"), FunctionTemplate::New(GLUTLayerGetCallback));

     Glut->Set(String::NewSymbol("bitmapCharacter"), FunctionTemplate::New(GLUTBitmapCharacterCallback));

     Glut->Set(String::NewSymbol("bitmapWidth"), FunctionTemplate::New(GLUTBitmapWidthCallback));

     Glut->Set(String::NewSymbol("strokeCharacter"), FunctionTemplate::New(GLUTStrokeCharacterCallback));

     Glut->Set(String::NewSymbol("strokeWidth"), FunctionTemplate::New(GLUTStrokeWidthCallback));

     Glut->Set(String::NewSymbol("bitmapLength"), FunctionTemplate::New(GLUTBitmapLengthCallback));

     Glut->Set(String::NewSymbol("strokeLength"), FunctionTemplate::New(GLUTStrokeLengthCallback));

     Glut->Set(String::NewSymbol("wireSphere"), FunctionTemplate::New(GLUTWireSphereCallback));

     Glut->Set(String::NewSymbol("solidSphere"), FunctionTemplate::New(GLUTSolidSphereCallback));

     Glut->Set(String::NewSymbol("wireCone"), FunctionTemplate::New(GLUTWireConeCallback));

     Glut->Set(String::NewSymbol("solidCone"), FunctionTemplate::New(GLUTSolidConeCallback));

     Glut->Set(String::NewSymbol("wireCube"), FunctionTemplate::New(GLUTWireCubeCallback));

     Glut->Set(String::NewSymbol("solidCube"), FunctionTemplate::New(GLUTSolidCubeCallback));

     Glut->Set(String::NewSymbol("wireTorus"), FunctionTemplate::New(GLUTWireTorusCallback));

     Glut->Set(String::NewSymbol("solidTorus"), FunctionTemplate::New(GLUTSolidTorusCallback));

     Glut->Set(String::NewSymbol("wireDodecahedron"), FunctionTemplate::New(GLUTWireDodecahedronCallback));

     Glut->Set(String::NewSymbol("solidDodecahedron"), FunctionTemplate::New(GLUTSolidDodecahedronCallback));

     Glut->Set(String::NewSymbol("wireTeapot"), FunctionTemplate::New(GLUTWireTeapotCallback));

     Glut->Set(String::NewSymbol("solidTeapot"), FunctionTemplate::New(GLUTSolidTeapotCallback));

     Glut->Set(String::NewSymbol("wireOctahedron"), FunctionTemplate::New(GLUTWireOctahedronCallback));

     Glut->Set(String::NewSymbol("solidOctahedron"), FunctionTemplate::New(GLUTSolidOctahedronCallback));

     Glut->Set(String::NewSymbol("wireTetrahedron"), FunctionTemplate::New(GLUTWireTetrahedronCallback));

     Glut->Set(String::NewSymbol("solidTetrahedron"), FunctionTemplate::New(GLUTSolidTetrahedronCallback));

     Glut->Set(String::NewSymbol("wireIcosahedron"), FunctionTemplate::New(GLUTWireIcosahedronCallback));

     Glut->Set(String::NewSymbol("solidIcosahedron"), FunctionTemplate::New(GLUTSolidIcosahedronCallback));

     Glut->Set(String::NewSymbol("videoResizeGet"), FunctionTemplate::New(GLUTVideoResizeGetCallback));

     Glut->Set(String::NewSymbol("setupVideoResizing"), FunctionTemplate::New(GLUTSetupVideoResizingCallback));

     Glut->Set(String::NewSymbol("stopVideoResizing"), FunctionTemplate::New(GLUTStopVideoResizingCallback));

     Glut->Set(String::NewSymbol("videoResize"), FunctionTemplate::New(GLUTVideoResizeCallback));

     Glut->Set(String::NewSymbol("videoPan"), FunctionTemplate::New(GLUTVideoPanCallback));

     Glut->Set(String::NewSymbol("reportErrors"), FunctionTemplate::New(GLUTReportErrorsCallback));

     Glut->Set(String::NewSymbol("ignoreKeyRepeat"), FunctionTemplate::New(GLUTIgnoreKeyRepeatCallback));

     Glut->Set(String::NewSymbol("setKeyRepeat"), FunctionTemplate::New(GLUTSetKeyRepeatCallback));

     Glut->Set(String::NewSymbol("forceJoystickFunc"), FunctionTemplate::New(GLUTForceJoystickFuncCallback));

     Glut->Set(String::NewSymbol("gameModeString"), FunctionTemplate::New(GLUTGameModeStringCallback));

     Glut->Set(String::NewSymbol("enterGameMode"), FunctionTemplate::New(GLUTEnterGameModeCallback));

     Glut->Set(String::NewSymbol("leaveGameMode"), FunctionTemplate::New(GLUTLeaveGameModeCallback));

     Glut->Set(String::NewSymbol("gameModeGet"), FunctionTemplate::New(GLUTGameModeGetCallback));


      // Again, return the result through the current handle scope.
      return handle_scope.Close(Glut);
}    
