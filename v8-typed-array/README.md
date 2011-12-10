v8-typed-array
==============

Typed Array implementation for V8 and Node.js. Works well enough to run jslinux but otherwise has not been tested. Many missing APIs.

* ArrayBuffer
* Int8Array
* Uint8Array
* Int16Array
* Uint16Array
* Int32Array
* Uint32Array
* Float32Array

Based Editor's Draft 28 April 2011: http://www.khronos.org/registry/typedarray/specs/latest/

Build
-----

    node-waf configure build

Or install using NPM (npm install typed-array)

Credits
-------

Inspired by:

* https://github.com/pufuwozu/node-webgl
* http://v8.googlecode.com/svn/trunk/samples/shell.cc

TODO
----

* Implement the rest of the API
* Bridge to Node's Buffers?

License
-------

Copyright (C) 2011 by Thomas Robinson (http://tlrobinson.net/)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
