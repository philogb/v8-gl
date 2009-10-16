
/*
 * Copyright (c) 2009, Mozilla Corp
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the <organization> nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY <copyright holder> ''AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL <copyright holder> BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

// convenience function to create a shader from a filepath
function getShader(filepath, type)
{
    var shaderScriptType = type;
    var shaderPath = filepath;

    if (!shaderPath || shaderPath.length == 0)
        return 0;

    var shader = Gles.CreateShader(type);
    
    if (shader == 0) return 0;

    //added method
    Gles.ShaderSourceFile(shader, filepath);
    Gles.CompileShader(shader);

    if (Gles.GetShaderiv(shader, Gles.COMPILE_STATUS) != 1) {
      var error = Gles.GetShaderInfoLog(shader);
      log("Error while compiling " + id + ":");
      log(shader);

      Gles.DeleteShader(shader);
        return 0;
    }

    return shader;
}

// Convenience function to create a program from all the passed-in
// shader filepaths and types.
function getProgram() {
    var shaders = [];

    // first load and compile all the passed-in shaders.
    for (var i = 0; i < arguments.length; i+=2) {
      var shader = getShader(arguments[i], arguments[i+1]);
      if (shader == 0)
        return 0;
      shaders.push(shader);
    }

    // then do the program object creation
    var program = Gles.CreateProgram();
    if (program == 0)
  return 0;

    // attach all the shaders
    for (var i = 0; i < shaders.length; i++) {
      Gles.AttachShader(program, shaders[i]);
    }

    // link, and check for errors
    Gles.LinkProgram(program);

    var linked = Gles.GetProgramiv(program, Gles.LINK_STATUS);
    if (!linked) {
      var error = Gles.GetProgramInfoLog(program);
      log("Error while linking: " + error);
      return 0;
    }

    return program;
}

//end library code.