#ifdef GL_ES
precision mediump float;
#endif

uniform vec2 u_resolution;
uniform float u_time;

const int AMOUNT = 11;

void main()
{
    vec2 coord = 20. * (gl_FragCoord.xy - u_resolution / 2.) / min(u_resolution.x, u_resolution.y);
    float len;

    for(int i = 1; i < AMOUNT; i++)
    {
        len = length(vec2(coord.x, coord.y));

        coord.x -= cos(coord.y + sin(len)) + cos(u_time / 4.);
        coord.y -= sin(coord.x + cos(len)) + sin(u_time / 8.);
    }

    gl_FragColor = vec4(cos(len) / 12., cos(len) / 5., cos(len), 1.);
}
