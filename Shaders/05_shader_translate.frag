#ifdef GL_ES
precision mediump float;
#endif

uniform vec2 u_resolution;
uniform float u_time;

float circleShape(vec2 position, float radius)
{
    return step(radius, length(position - vec2(0.5)));
}

void main()
{
    vec2 coord = gl_FragCoord.xy / u_resolution;
    vec3 color = vec3(0.);

    // u_time gives the animation of translating 
    vec2 translate = vec2(sin(u_time / 10.), 
                          cos(u_time));
    coord += translate * 0.5; // speed of the movements

    color += vec3(circleShape(coord, 0.3));

    gl_FragColor = vec4(color, 1.);
}