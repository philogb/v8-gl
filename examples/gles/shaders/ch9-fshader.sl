/*precision mediump float;*/
varying vec3 v_normal;
uniform samplerCube s_texture;
void main()
{
  gl_FragColor = textureCube(s_texture, v_normal);
}
