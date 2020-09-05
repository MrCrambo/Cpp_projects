#ifdef GL_ES
precision mediump float;
#endif

uniform vec2 u_resolution;

void main()
{
    vec2 position = gl_FragCoord.xy / u_resolution;

    float circle = step(0.3, length(position - vec2(0.5)));

    gl_FragColor = mix(vec4(vec3(1.0, 1.0, 0.0), 1.0), vec4(vec3(1.0, 1.0, 0.0), 0.0), circle);
}
