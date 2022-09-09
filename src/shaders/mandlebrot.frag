#version 410
precision mediump float;
out vec4 frag_color;

float map(float value, float min1, float max1, float min2, float max2) {
  return min2 + (value - min1) * (max2 - min2) / (max1 - min1);
}

void main() {
  float normalized_coords_x = mix(-0.25,0.25,gl_FragCoord.x);
  float normalized_coords_y = mix(-0.25,0.25,gl_FragCoord.y);
  vec2 coords = vec2(normalized_coords_x,normalized_coords_y) / vec2(1280,720);
  vec2 c;
  c.x = mix(-2.0, 1.0, coords.x);
  c.y = mix(-1.5,1.5,coords.y);
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
  frag_color = vec4(
  map(iterations%4 * 64.0,0.0,255.0,0.0,1.0), 
  map(iterations%8 * 32.0,0.0,255.0,0.0,1.0), 
  map(iterations%16 * 16.0,0.0,255.0,0.0,1.0), 
  1.0f);
}

 