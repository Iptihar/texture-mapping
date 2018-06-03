#ifndef TRANSFORM_INCLUDED_H
#define TRANSFORM_INCLUDED_H

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include "camera.h"

struct Transform
{
public:

	inline glm::mat4 GetModel() const
	{
		glm::mat4 Model = glm::mat4(1.0f);
		Model = glm::translate(glm::rotate(glm::mat4(1.0f), glm::radians(-90.0f), glm::vec3(1.f, 0.f, 0.f)), glm::vec3(0.0f, -10.f, 0.0f));
		return Model;
	}

	inline glm::mat4 GetMVP(const Camera& camera) const
	{
		glm::mat4 VP = camera.GetViewProjection();
		glm::mat4 M = GetModel();

		return VP * M;
	}

	inline glm::mat4 GetNormal(const Camera& camera) const
	{
		glm::mat4 normalMatrix = transpose(inverse(camera.GetView() * GetModel()));
		return normalMatrix;
	}

};

#endif
