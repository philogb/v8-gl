attribute vec4 pos; 

void main() { 
  gl_Position = vec4(pos.x * float(370), pos.y * float(240), 0.0, 1.0);
}