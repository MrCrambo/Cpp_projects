#ifdef GL_ES
precision mediump float;
#endif

uniform vec2 u_resolution;
uniform float u_time;

void main(){
    vec2 coord = gl_FragCoord.xy / u_resolution;
    vec3 color = vec3(0.);

    float angle = atan(-coord.y + 0.25, coord.x - 0.5) * 0.1;
    float len = length(coord - vec2(0.5, 0.25));

    color.r += sin(len * 40. + angle * 80. + u_time);
    color.g += cos(len * 30. + angle * 40. - u_time);
    color.b += cos(len * 50. + angle * 50. + 10.);

    gl_FragColor = vec4(color, 1.);
}