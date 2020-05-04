#ifdef GL_ES
precision mediump float;
#endif

uniform vec2 u_resolution;

// drawing rectangle
float rectShape(vec2 position, vec2 scale)
{
    scale = vec2(0.5) - scale * 0.5;
    vec2 rect = vec2(step(scale.x, position.x), step(scale.y, position.y));

    // scaling at the center of the screen
    rect *= vec2(step(scale.x, 1. - position.x), step(scale.y, 1. - position.y));
    return rect.x * rect.y;
}

void main()
{
    vec2 position = gl_FragCoord.xy / u_resolution;
    
    float rect = rectShape(position, vec2(0.3, 0.3));
    vec3 color = vec3(rect);
    
    gl_FragColor = vec4(color, 1.);
}