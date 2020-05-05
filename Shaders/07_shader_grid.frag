#ifdef GL_ES
precision mediump float;
#endif

uniform vec2 u_resolution;
uniform float u_time;

void main()
{
    vec2 coord = gl_FragCoord.xy / u_resolution;
    vec3 color = vec3(0.);

    color += sin(coord.x * cos(u_time / 60.) * 60.) + sin(coord.y * cos(u_time / 60.) * 10.);

    color *= sin(u_time / 10.);

    gl_FragColor = vec4(color, 1.);
}
