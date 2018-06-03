#version 120

varying vec2 texCoord0;
varying vec3 normal0;

uniform sampler2D sampler;
uniform mat4 MVP;
uniform mat4 Normal;
uniform mat4 MV;

struct Dirlight {
	vec3 direction;
	vec3 color;
};

void main()
{
    Dirlight lights[3];

	lights[0].direction = vec3(0.0f, -1.f, 0.0f);
	lights[1].direction = vec3(-1.0f, 0.0f, 0.0f);
	lights[2].direction = vec3(0.0f, 0.0f, -1.0f);

	lights[0].color = vec3(1.0f, 1.0f, 1.0f);
	lights[1].color = vec3(1.0f, 1.0f, 1.0f);
	lights[2].color = vec3(1.0f, 1.0f, 1.0f);

    vec3 diffuseSum = vec3(0);

    for (int i = 0; i < 3; i++) {
        vec3 lightDir = normalize(vec3(MV * -vec4(lights[i].direction, 0)));
		float diff = max(dot(normal0, lightDir), 0.0f);
		vec3 diffuse = diff * lights[i].color;
        diffuseSum += diffuse;
    }
    vec4 result = vec4(diffuseSum, 1);
    gl_FragColor = texture2D(sampler, texCoord0) * result;
}
