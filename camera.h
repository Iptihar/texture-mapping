#ifndef CAMERA_INCLUDED_H
#define CAMERA_INCLUDED_H

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

struct Camera
{
public:
	Camera(const glm::vec3& eye, const glm::vec3& center, const glm::vec3& up)
	{
		this->eye = eye;
		this->center = center;
		this->up = up;
		this->projection = glm::ortho(-24.0f, 24.0f, -18.0f, 18.0f, 1.0f, 500.0f);
	}

	inline glm::mat4 GetViewProjection() const
	{
		return projection * glm::lookAt(eye, center, up);
	}

	inline glm::mat4 GetView() const
	{
		return glm::lookAt(eye, center, up);
	}

protected:
private:
	glm::mat4 projection;
	glm::vec3 eye;
	glm::vec3 center;
	glm::vec3 up;
};

#endif
