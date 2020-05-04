#ifdef GL_ES
precision mediump float;
#endif

const float PI = 3.14159265;

uniform vec2 u_resolution;

float polygonShape(vec2 position, float radius, float sides)
{
    position = position * 2. - 1.;
    float angle = atan(position.x, position.y);
    float slice = PI * 2. / sides;

    return step(radius, cos(floor(0.5 + angle / slice) * slice - angle) * length(position));
}

void main()
{
    vec2 position = gl_FragCoord.xy / u_resolution;

    float polygon = polygonShape(position, 0.3, 7.);

    vec3 color = vec3(polygon);
    gl_FragColor = vec4(color, 1.);    
}