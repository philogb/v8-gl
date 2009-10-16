uniform vec4 in_color;
vec2 v=(gl_FragCoord.xy-vec2(400,300))/vec2(400,300);
float w=dot(in_color.xyz,vec3(1.0,256.0,65536.0))*.25;
const float s=0.4;

float obj(vec3 pos){
  float final=1.0;
  final *= distance(pos,vec3(cos(w)+sin(w*0.2),0.3,2.0+cos(w*0.5)*0.5));
  final *= distance(pos,vec3(-cos(w*0.7),0.3,2.0+sin(w*0.5)));
  final *= distance(pos,vec3(-sin(w*0.2)*0.5,sin(w),2.0));
  final *= cos(pos.y)*cos(pos.x)-0.1-cos(pos.z*7.+w*7.)*cos(pos.x*3.)*cos(pos.y*4.)*0.1;
  return final;
}

void main(){
  vec3 o=vec3(v.x,v.y*1.25,0.0);
  vec3 d=vec3(v.x+cos(w)*.3,v.y,1.0)/64.0;
  vec4 color=vec4(0.0);
  float t=0.0;

  for(int i=0;i<75;i++) {
    if(obj(o+d*t)<s){
      t-=5.0;
      for(int j=0;j<5;j++){
        if(obj(o+d*t)<s){
          break;
        }
        t+=1.0;
      }
      vec3 e=vec3(0.01,.0,.0);
      vec3 n=vec3(0.0);
      n.x=obj(o+d*t)-obj(vec3(o+d*t+e.xyy));
      n.y=obj(o+d*t)-obj(vec3(o+d*t+e.yxy));
      n.z=obj(o+d*t)-obj(vec3(o+d*t+e.yyx));
      n=normalize(n);
      color+=max(dot(vec3(0.0,0.0,-0.5),n),0.0)+max(dot(vec3(0.0,-0.5,0.5),n),0.0)*0.5;break;
    }
    t+=5.0;
  }
  gl_FragColor=color+vec4(0.1,0.2,0.5,1.0)*(t*0.025);
}
