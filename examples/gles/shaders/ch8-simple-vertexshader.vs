uniform mat4 u_mvpMatrix;
attribute vec4 a_position;
void main() {
  gl_Position = u_mvpMatrix * a_position;
  //gl_PointSize = 1
}