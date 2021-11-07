namespace ImGui {
	void DragFloat2(const char* label, vex2f& v, float v_speed, float _min, float _max) {
		float _v[2];
		_v[0] = v.x;
		_v[1] = v.y;
		ImGui::DragFloat2(label, _v, v_speed, _min, _max);
		v.x = _v[0];
		v.y = _v[1];
	};
	void DragFloat3(const char* label, vex3f& v, float v_speed, float _min, float _max) {
		float _v[3];
		_v[0] = v.x;
		_v[1] = v.y;
		_v[2] = v.z;
		ImGui::DragFloat3(label, _v, v_speed, _min, _max);
		v.x = _v[0];
		v.y = _v[1];
		v.z = _v[2];
	};
	void DragFloat4(const char* label, vex4f& v, float v_speed, float _min, float _max) {
		float _v[4];
		_v[0] = v.x;
		_v[1] = v.y;
		_v[2] = v.z;
		_v[3] = v.w;
		ImGui::DragFloat4(label, _v, v_speed, _min, _max);
		v.x = _v[0];
		v.y = _v[1];
		v.z = _v[2];
		v.w = _v[3];
	};
	void SliderFloat2(const char* label, vex2f& v, float _min, float _max) {
		float _v[2];
		_v[0] = v.x;
		_v[1] = v.y;
		ImGui::SliderFloat2(label, _v, _min, _max);
		v.x = _v[0];
		v.y = _v[1];
	};
	void SliderFloat3(const char* label, vex3f& v, float _min, float _max) {
		float _v[3];
		_v[0] = v.x;
		_v[1] = v.y;
		_v[2] = v.z;
		ImGui::SliderFloat3(label, _v, _min, _max);
		v.x = _v[0];
		v.y = _v[1];
		v.z = _v[2];
	};
	void SliderFloat4(const char* label, vex4f& v, float _min, float _max) {
		float _v[4];
		_v[0] = v.x;
		_v[1] = v.y;
		_v[2] = v.z;
		_v[3] = v.w;
		ImGui::SliderFloat4(label, _v, _min, _max);
		v.x = _v[0];
		v.y = _v[1];
		v.z = _v[2];
		v.w = _v[3];
	};
	void DragInt2(const char* label, vex2f& v, int v_speed, int _min, int _max) {
		int _v[2];
		_v[0] = v.x;
		_v[1] = v.y;
		ImGui::DragInt2(label, _v, v_speed, _min, _max);
		v.x = _v[0];
		v.y = _v[1];
	};
	void DragInt3(const char* label, vex3f& v, int v_speed, int _min, int _max) {
		int _v[3];
		_v[0] = v.x;
		_v[1] = v.y;
		_v[2] = v.z;
		ImGui::DragInt3(label, _v, v_speed, _min, _max);
		v.x = _v[0];
		v.y = _v[1];
		v.z = _v[2];
	};
	void DragInt4(const char* label, vex4f& v, int v_speed, int _min, int _max) {
		int _v[4];
		_v[0] = v.x;
		_v[1] = v.y;
		_v[2] = v.z;
		_v[3] = v.w;
		ImGui::DragInt4(label, _v, v_speed, _min, _max);
		v.x = _v[0];
		v.y = _v[1];
		v.z = _v[2];
		v.w = _v[3];
	};
	void SliderInt2(const char* label, vex2f& v, int _min, int _max) {
		int _v[2];
		_v[0] = v.x;
		_v[1] = v.y;
		ImGui::SliderInt2(label, _v, _min, _max);
		v.x = _v[0];
		v.y = _v[1];
	};
	void SliderInt3(const char* label, vex3f& v, int _min, int _max) {
		int _v[3];
		_v[0] = v.x;
		_v[1] = v.y;
		_v[2] = v.z;
		ImGui::SliderInt3(label, _v, _min, _max);
		v.x = _v[0];
		v.y = _v[1];
		v.z = _v[2];
	};
	void SliderInt4(const char* label, vex4f& v, int _min, int _max) {
		int _v[4];
		_v[0] = v.x;
		_v[1] = v.y;
		_v[2] = v.z;
		_v[3] = v.w;
		ImGui::SliderInt4(label, _v, _min, _max);
		v.x = _v[0];
		v.y = _v[1];
		v.z = _v[2];
		v.w = _v[3];
	};
	void ColorPicker4(const char* label, vex4f& v) {
		float _v[4];
		_v[0] = v.x;
		_v[1] = v.y;
		_v[2] = v.z;
		_v[3] = v.w;
		ImGui::ColorPicker4(label, _v);
		v.x = _v[0];
		v.y = _v[1];
		v.z = _v[2];
		v.w = _v[3];
	};
	void ColorPicker3(const char* label, vex3f& v) {
		float _v[3];
		_v[0] = v.x;
		_v[1] = v.y;
		_v[2] = v.z;
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
	void DragInt2(const char* label, sf::Vector2i& v, int v_speed, int _min, int _max) {
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
		int _v[3];
		_v[0] = v.x;
		_v[1] = v.y;
		_v[2] = v.z;
		ImGui::InputInt3(label, _v);
		v.x = _v[0];
		v.y = _v[1];
		v.z = _v[2];
	};
	void InputFloat3(const char* label, vex3f& v) {
		float _v[3];
		_v[0] = v.x;
		_v[1] = v.y;
		_v[2] = v.z;
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
	ImGui::Text(("file name: "s + v.fileName).c_str());
	ImGui::Text(("size: x = "stx + v.scale().x + ", y = " + v.scale().y).c_str());
	if (name != nullptr) ImGui::End();
};
void XsInfo(XsShape& v, const char* name = nullptr) {
	if (name != nullptr) ImGui::Begin(name);
	ImGui::DragFloat3("position", v.pos, 0.01f, -FLT_MAX, FLT_MAX);
	ImGui::DragFloat3("rotation", v.rot, 0.1f, -FLT_MAX, FLT_MAX);
	ImGui::DragFloat3("scale", v.scale, 0.01f, -FLT_MAX, FLT_MAX);
	ImGui::ColorPicker4("color", v.color);
	if (v.tex != nullptr) XsInfo(*v.tex);
	if (name != nullptr) ImGui::End();
};