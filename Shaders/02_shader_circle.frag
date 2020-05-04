#ifdef GL_ES
precision mediump float;
#endif

uniform vec2 u_resolution;

// drawing circle with radius and at position
float circleShape(vec2 position, float radius)
{
    return step(radius, length(position - vec2(0.5)));
}

void main()
{
    vec2 position = gl_FragCoord.xy / u_resolution;

    float circle = circleShape(position, 0.3);
    vec3 color = vec3(circle);

    gl_FragColor = vec4(color, 1.0);
}
