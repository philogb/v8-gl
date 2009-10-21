/*
 * Copyright (c) 2009, Nicolas Garcia Belmonte
 * 
 * Some Utility functions.
 */

(function() {
//convenience function to create a shader from a filepath
  function getShader(filepath, type)
  {
      var shaderScriptType = type;
      var shaderPath = filepath;
   
      if (!shaderPath || shaderPath.length == 0)
          return 0;
   
      var shader = Gles.createShader(type);
      
      if (shader == 0) return 0;
   
      //added method
      Gles.shaderSourceFile(shader, filepath);
      Gles.compileShader(shader);
   
      if (Gles.getShaderiv(shader, Gles.COMPILE_STATUS) != 1) {
        var error = Gles.getShaderInfoLog(shader);
        log("Error while compiling " + id + ":");
        log(shader);
   
        Gles.deleteShader(shader);
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
      var program = Gles.createProgram();
      if (program == 0)
        return 0;
   
      // attach all the shaders
      for (var i = 0; i < shaders.length; i++) {
        Gles.attachShader(program, shaders[i]);
      }
   
      // link, and check for errors
      Gles.linkProgram(program);
   
      var linked = Gles.getProgramiv(program, Gles.LINK_STATUS);
      if (!linked) {
        var error = Gles.getProgramInfoLog(program);
        log("Error while linking: " + error);
        return 0;
      }
   
      return program;
  }
  
  this.getProgram = function(vertexShader, fragmentShader) {
    return getProgram(vertexShader, Gles.VERTEX_SHADER, 
                      fragmentShader, Gles.FRAGMENT_SHADER);
  };

})();
