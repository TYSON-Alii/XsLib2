namespace ImGui {
	void DragFloat2(const char* label, vex2f& v, float v_speed, float _min, float _max) {
		auto _v = v.arr();
		ImGui::DragFloat2(label, _v, v_speed, _min, _max);
		v.x = _v[0];
		v.y = _v[1];
	};
	void DragFloat3(const char* label, vex3f& v, float v_speed, float _min, float _max) {
		auto _v = v.arr();
		ImGui::DragFloat3(label, _v, v_speed, _min, _max);
		v.x = _v[0];
		v.y = _v[1];
		v.z = _v[2];
	};
	void DragFloat4(const char* label, vex4f& v, float v_speed, float _min, float _max) {
		auto _v = v.arr();
		ImGui::DragFloat4(label, _v, v_speed, _min, _max);
		v.x = _v[0];
		v.y = _v[1];
		v.z = _v[2];
		v.w = _v[3];
	};
	void SliderFloat2(const char* label, vex2f& v, float _min, float _max) {
		auto _v = v.arr();
		ImGui::SliderFloat2(label, _v, _min, _max);
		v.x = _v[0];
		v.y = _v[1];
	};
	void SliderFloat3(const char* label, vex3f& v, float _min, float _max) {
		auto _v = v.arr();
		ImGui::SliderFloat3(label, _v, _min, _max);
		v.x = _v[0];
		v.y = _v[1];
		v.z = _v[2];
	};
	void SliderFloat4(const char* label, vex4f& v, float _min, float _max) {
		auto _v = v.arr();
		ImGui::SliderFloat4(label, _v, _min, _max);
		v.x = _v[0];
		v.y = _v[1];
		v.z = _v[2];
		v.w = _v[3];
	};
	void DragInt2(const char* label, vex2i& v, float v_speed, int _min, int _max) {
		auto _v = v.arr();
		ImGui::DragInt2(label, _v, v_speed, _min, _max);
		v.x = _v[0];
		v.y = _v[1];
	};
	void DragInt3(const char* label, vex3i& v, float v_speed, int _min, int _max) {
		auto _v = v.arr();
		ImGui::DragInt3(label, _v, v_speed, _min, _max);
		v.x = _v[0];
		v.y = _v[1];
		v.z = _v[2];
	};
	void DragInt4(const char* label, vex4i& v, float v_speed, int _min, int _max) {
		auto _v = v.arr();
		ImGui::DragInt4(label, _v, v_speed, _min, _max);
		v.x = _v[0];
		v.y = _v[1];
		v.z = _v[2];
		v.w = _v[3];
	};
	void SliderInt2(const char* label, vex2i& v, int _min, int _max) {
		auto _v = v.arr();
		ImGui::SliderInt2(label, _v, _min, _max);
		v.x = _v[0];
		v.y = _v[1];
	};
	void SliderInt3(const char* label, vex3i& v, int _min, int _max) {
		auto _v = v.arr();
		ImGui::SliderInt3(label, _v, _min, _max);
		v.x = _v[0];
		v.y = _v[1];
		v.z = _v[2];
	};
	void SliderInt4(const char* label, vex4i& v, int _min, int _max) {
		auto _v = v.arr();
		ImGui::SliderInt4(label, _v, _min, _max);
		v.x = _v[0];
		v.y = _v[1];
		v.z = _v[2];
		v.w = _v[3];
	};
	void ColorPicker4(const char* label, vex4f& v) {
		auto _v = v.arr();
		ImGui::ColorPicker4(label, _v);
		v.x = _v[0];
		v.y = _v[1];
		v.z = _v[2];
		v.w = _v[3];
	};
	void ColorPicker3(const char* label, vex3f& v) {
		auto _v = v.arr();
		ImGui::ColorPicker3(label, _v);
		v.x = _v[0];
		v.y = _v[1];
		v.z = _v[2];
	};

	void DragFloat2(const char* label, sf::Vector2f& v, float v_speed, float _min, float _max) {
		float _v[2];
		_v[0] = v.x;
		_v[1] = v.y;
		ImGui::DragFloat2(label, _v, v_speed, _min, _max);
		v.x = _v[0];
		v.y = _v[1];
	};
	void SliderFloat2(const char* label, sf::Vector2f& v, float _min, float _max) {
		float _v[2];
		_v[0] = v.x;
		_v[1] = v.y;
		ImGui::SliderFloat2(label, _v, _min, _max);
		v.x = _v[0];
		v.y = _v[1];
	};
	void DragInt2(const char* label, sf::Vector2i& v, float v_speed, int _min, int _max) {
		int _v[2];
		_v[0] = v.x;
		_v[1] = v.y;
		ImGui::DragInt2(label, _v, v_speed, _min, _max);
		v.x = _v[0];
		v.y = _v[1];
	};
	void SliderInt2(const char* label, sf::Vector2i& v, int _min, int _max) {
		int _v[2];
		_v[0] = v.x;
		_v[1] = v.y;
		ImGui::SliderInt2(label, _v, _min, _max);
		v.x = _v[0];
		v.y = _v[1];
	};
	void InputInt3(const char* label, vex3i& v) {
		auto _v = v.arr();
		ImGui::InputInt3(label, _v);
		v.x = _v[0];
		v.y = _v[1];
		v.z = _v[2];
	};
	void InputFloat3(const char* label, vex3f& v) {
		auto _v = v.arr();
		ImGui::InputFloat3(label, _v);
		v.x = _v[0];
		v.y = _v[1];
		v.z = _v[2];
	};
};

void XsInfo(XsTexture& v, const char* name = nullptr) {
	if (name != nullptr) ImGui::Begin(name);
	vex2f _t = vex2f(ImGui::GetWindowSize().x, ImGui::GetWindowSize().y);
	_t.normalize();
	ImGui::Image((void*)v.data, ImVec2(ImGui::GetWindowSize().x - 25, ImGui::GetWindowSize().x * _t.y - 25), ImVec2(0, 0), ImVec2(1, 1));
	ImGui::Text(("File Name: "s + v.fileName).c_str());
	ImGui::Text(("Size: x = "stx + v.scale().x + ", y = " + v.scale().y).c_str());
	if (name != nullptr) ImGui::End();
};
void XsInfo(XsShape& v, const char* name = nullptr) {
	if (name != nullptr) ImGui::Begin(name);
	ImGui::DragFloat3("Position", v.pos, 0.01f, -FLT_MAX, FLT_MAX);
	ImGui::DragFloat3("Rotation", v.rot, 0.5f, -FLT_MAX, FLT_MAX);
	ImGui::DragFloat3("Scale", v.scale, 0.01f, -FLT_MAX, FLT_MAX);
	ImGui::DragFloat3("Origin", v.origin, 0.01f, -FLT_MAX, FLT_MAX);
	int _XSIMVERTC_ = (v.mode == Xs.Enum.Vertex) ? 0 : (v.mode == Xs.Enum.VertexAndTexture) ? 1 : (v.mode == Xs.Enum.VertexAndNormal) ? 2 : (v.mode == Xs.Enum.All) ? 3 : 0;
	ImGui::Combo("Xs Mode", &_XSIMVERTC_, Xs.Values.XsModeNames, 4);
	v.mode = (_XSIMVERTC_ == 0) ? Xs.Enum.Vertex : (_XSIMVERTC_ == 1) ? Xs.Enum.VertexAndTexture : (_XSIMVERTC_ == 2) ? Xs.Enum.VertexAndNormal : (_XSIMVERTC_ == 3) ? Xs.Enum.All : Xs.Enum.Vertex;
	_XSIMVERTC_ = (v.glmode == GL_POINTS) ? 0 : (v.glmode == GL_LINES) ? 1 : (v.glmode == GL_TRIANGLES) ? 2 : (v.glmode == GL_QUADS) ? 3 : (v.glmode == GL_POLYGON) ? 4 : 0;
	ImGui::Combo("GL Mode", &_XSIMVERTC_, Xs.Values.GlModeNames, 5);
	v.glmode = (_XSIMVERTC_ == 0) ? GL_POINTS : (_XSIMVERTC_ == 1) ? GL_LINES : (_XSIMVERTC_ == 2) ? GL_TRIANGLES : (_XSIMVERTC_ == 3) ? GL_QUADS : GL_POLYGON;
	ImGui::ColorPicker4("Color", v.color);
	if (v.tex != nullptr) XsInfo(*v.tex);
	if (name != nullptr) ImGui::End();
};