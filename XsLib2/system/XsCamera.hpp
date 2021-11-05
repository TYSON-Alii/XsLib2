class XsCamera {
private:
	glm::mat4 _viewMatrix;
public:
	XsCamera() = default;
	vex3f pos = 0;
	vex3f rot = 0;
	float fov = 45.0f;
	float near_ = 0.001f, far_ = 1000.0f;
	vex2f viewport;
	inline glm::mat4 projectionMatrix() { return glm::perspective(fov, (float)viewport.x / (float)viewport.y, near_, far_); };
	inline glm::mat4& viewMatrix() { return _viewMatrix; };
};
void XsDefaultCamera(XsCamera& cam) {
	glScissor(0, 0, cam.viewport.x, cam.viewport.y);
	glViewport(0, 0, (GLsizei)cam.viewport.x, (GLsizei)cam.viewport.y);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glm::mat4 pmx = glm::perspective(cam.fov, (float)cam.viewport.x / (float)cam.viewport.y, cam.near_, cam.far_);
	glm::mat4 tmx = glm::translate(glm::mat4(1.f), glm::vec3(-cam.pos.x, -cam.pos.y + 1, -cam.pos.z));
	glm::vec3 position = glm::normalize(glm::vec3(0, 1, 0));
	glm::vec3 t_rot;
	t_rot.x = cam.rot.x;
	t_rot.y = cam.rot.y;
	t_rot.z = cam.rot.z;
	glm::vec3 rott = glm::normalize(t_rot);
	glm::vec3 right = glm::normalize(glm::cross(rott, position));
	glm::vec3 up = glm::normalize(glm::cross(right, rott));
	cam.viewMatrix() = glm::lookAt(position, position + rott, up);
	glm::mat4 _ftransform = pmx * cam.viewMatrix() * tmx;
	glLoadMatrixf(&_ftransform[0][0]);
	glMatrixMode(GL_MODELVIEW);
};
void XsFPSCamera(XsCamera& cam, vex2f _mouse_pos, float _sensivity) {
	float _yaw = _mouse_pos.x * _sensivity;
	float _pitch = (_mouse_pos.y * _sensivity > 89.9f) ? 89.9f : (_mouse_pos.y * _sensivity < -89.9f) ? -89.9f : (_mouse_pos.y * _sensivity);
	glViewport(0, 0, (GLsizei)cam.viewport.x, (GLsizei)cam.viewport.y);
	glScissor(0, 0, cam.viewport.x, cam.viewport.y);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glm::mat4 pmx = glm::perspective(cam.fov, (float)cam.viewport.x / (float)cam.viewport.y, cam.near_, cam.far_);
	glm::mat4 tmx = glm::translate(glm::mat4(1.f), glm::vec3(-cam.pos.x, -cam.pos.y + 1, -cam.pos.z));
	glm::vec3 position = glm::normalize(glm::vec3(0, 1, 0));
	glm::vec3 t_rot = glm::vec3(0, 0, 0);
	t_rot.x = cos(glm::radians(_yaw)) * cos(glm::radians(_pitch));
	t_rot.y = -sin(glm::radians(_pitch));
	t_rot.z = sin(glm::radians(_yaw)) * cos(glm::radians(_pitch));
	glm::vec3 rott = glm::normalize(t_rot);
	glm::vec3 right = glm::normalize(glm::cross(rott, position));
	glm::vec3 up = glm::normalize(glm::cross(right, rott));
	cam.viewMatrix() = glm::lookAt(position, position + rott, up);
	glm::mat4 xs_fullTransform_ = pmx * cam.viewMatrix() * tmx;
	cam.rot.x = t_rot.x;
	cam.rot.y = t_rot.y;
	cam.rot.z = t_rot.z;
	glLoadMatrixf(&xs_fullTransform_[0][0]);
	glMatrixMode(GL_MODELVIEW);
};
