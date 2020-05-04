#ifdef GL_ES
precision mediump float;
#endif

uniform vec2 u_resolution;
uniform float u_time;

// drawing rectangle
// from 03_shader_rectangle.frag
float rectShape(vec2 position, vec2 scale)
{
    scale = vec2(0.5) - scale * 0.5;
    vec2 rect = vec2(step(scale.x, position.x), step(scale.y, position.y));

    // scaling at the center of the screen
    rect *= vec2(step(scale.x, 1. - position.x), step(scale.y, 1. - position.y));
    return rect.x * rect.y;
}

mat2 rotate(float angle)
{
    // second sin with minus for preventing from goinf ouside of the screen when the angle is 45 deg
    return mat2(cos(angle), -sin(angle), sin(angle), cos(angle));
}

void main()
{
    vec2 coord = gl_FragCoord.xy / u_resolution;
    vec3 color = vec3(0.);

    coord -= vec2(0.5);
    // by changing the rotate param you could change the start point, 
    // btw beacuse of u_time there will be animation
    coord = rotate(0. + u_time) * coord;
    coord += vec2(0.5);

    color += vec3(rectShape(coord, vec2(0.3, 0.3)));

    gl_FragColor = vec4(color, 1.);
}