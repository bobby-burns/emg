#version 410
precision mediump float;
out vec4 frag_color;

uniform vec2 viewport;
uniform vec4 mandle_coords;
uniform float zoomFactor;

#define PI 3.1415926538

float map(float value, float min1, float max1, float min2, float max2) {
  return min2 + (value - min1) * (max2 - min2) / (max1 - min1);
}

vec3 hsv2rgb(vec3 c)
{
    vec4 K = vec4(1.0, 2.0 / 3.0, 1.0 / 3.0, 3.0);
    vec3 p = abs(fract(c.xxx + K.xyz) * 6.0 - K.www);
    return c.z * mix(K.xxx, clamp(p - K.xxx, 0.0, 1.0), c.y);
}

vec4 genColor(float x, float k){
  float eq = log(x)/k;
  float more = (1 + cos(2*PI*eq)/2);
  return vec4(more,more,more,1.0);

}

void main() {
  float normalized_coords_x = mix(-0.5,0.5,gl_FragCoord.x);
  float normalized_coords_y = mix(-0.5,0.5,gl_FragCoord.y);
  vec2 coords = vec2(normalized_coords_x,normalized_coords_y) / viewport.xy;
  vec2 c;
  c.x = mix(mandle_coords.x  , mandle_coords.y  , coords.x);
  c.y = mix(mandle_coords.z  , mandle_coords.w  , coords.y);
  vec2 z = c;

  int limit = 1000;
  int iterations = 0;
  for(int i = 0; i < limit; i++){
      float t = 2.0 * z.x * z.y + c.y;
      z.x = z.x * z.x - z.y * z.y + c.x;
      z.y = t;

      if(z.x * z.x + z.y *z.y > 4.0){
          break;
      }

      iterations += 1;
  }
  /*
  map(iterations%4 * 64.0,0.0,255.0,0.0,1.0), 
  map(iterations%8 * 32.0,0.0,255.0,0.0,1.0), 
  map(iterations%16 * 16.0,0.0,255.0,0.0,1.0))
  */

  frag_color = genColor(iterations,log(1.5));

} 