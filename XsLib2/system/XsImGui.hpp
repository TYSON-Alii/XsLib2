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
	void DragInt2(const char* label, vex2ui& v, float v_speed, size_t _min, size_t _max) {
		int _v[2]{ v.x, v.y };
		ImGui::DragInt2(label, _v, v_speed, _min, _max);
		v.x = _v[0];
		v.y = _v[1];
	};
	void DragInt3(const char* label, vex3ui& v, float v_speed, size_t _min, size_t _max) {
		int _v[3]{ v.x, v.y, v.z };
		ImGui::DragInt3(label, _v, v_speed, _min, _max);
		v.x = _v[0];
		v.y = _v[1];
		v.z = _v[2];
	};
	void DragInt4(const char* label, vex4ui& v, float v_speed, size_t _min, size_t _max) {
		int _v[4]{ v.x, v.y, v.z, v.w };
		ImGui::DragInt4(label, _v, v_speed, _min, _max);
		v.x = _v[0];
		v.y = _v[1];
		v.z = _v[2];
		v.w = _v[3];
	};
	void SliderInt2(const char* label, vex2i& v, int _min, int _max) {
		int _v[4]{ v.x, v.y };
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

	void StyleXsDark() {
		ImVec4* colors = ImGui::GetStyle().Colors;
		colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 0.98f);
		colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 0.91f);
		colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.06f, 0.06f, 0.56f);
		colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
		colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
		colors[ImGuiCol_Border] = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
		colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
		colors[ImGuiCol_FrameBg] = ImVec4(0.12f, 0.10f, 0.21f, 1.00f);
		colors[ImGuiCol_FrameBgHovered] = ImVec4(0.37f, 0.17f, 0.69f, 1.00f);
		colors[ImGuiCol_FrameBgActive] = ImVec4(0.45f, 0.31f, 0.85f, 1.00f);
		colors[ImGuiCol_TitleBg] = ImVec4(0.16f, 0.16f, 0.19f, 0.94f);
		colors[ImGuiCol_TitleBgActive] = ImVec4(0.16f, 0.16f, 0.19f, 0.96f);
		colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.16f, 0.16f, 0.19f, 0.98f);
		colors[ImGuiCol_MenuBarBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
		colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.53f);
		colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
		colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
		colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
		colors[ImGuiCol_CheckMark] = ImVec4(0.82f, 0.42f, 0.48f, 1.00f);
		colors[ImGuiCol_SliderGrab] = ImVec4(0.45f, 0.31f, 0.85f, 1.00f);
		colors[ImGuiCol_SliderGrabActive] = ImVec4(0.37f, 0.17f, 0.69f, 1.00f);
		colors[ImGuiCol_Button] = ImVec4(0.29f, 0.07f, 0.11f, 1.00f);
		colors[ImGuiCol_ButtonHovered] = ImVec4(0.42f, 0.11f, 0.18f, 1.00f);
		colors[ImGuiCol_ButtonActive] = ImVec4(0.42f, 0.11f, 0.18f, 1.00f);
		colors[ImGuiCol_Header] = ImVec4(0.12f, 0.10f, 0.21f, 1.00f);
		colors[ImGuiCol_HeaderHovered] = ImVec4(0.37f, 0.17f, 0.69f, 1.00f);
		colors[ImGuiCol_HeaderActive] = ImVec4(0.45f, 0.31f, 0.85f, 1.00f);
		colors[ImGuiCol_Separator] = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
		colors[ImGuiCol_SeparatorHovered] = ImVec4(0.91f, 0.52f, 0.64f, 0.78f);
		colors[ImGuiCol_SeparatorActive] = ImVec4(0.67f, 0.64f, 0.81f, 1.00f);
		colors[ImGuiCol_ResizeGrip] = ImVec4(0.00f, 0.02f, 0.04f, 0.20f);
		colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.41f, 0.41f, 0.41f, 0.67f);
		colors[ImGuiCol_ResizeGripActive] = ImVec4(0.35f, 0.35f, 0.35f, 0.95f);
		colors[ImGuiCol_Tab] = ImVec4(0.28f, 0.17f, 0.44f, 0.86f);
		colors[ImGuiCol_TabHovered] = ImVec4(0.28f, 0.16f, 0.71f, 0.80f);
		colors[ImGuiCol_TabActive] = ImVec4(0.10f, 0.06f, 0.24f, 1.00f);
		colors[ImGuiCol_TabUnfocused] = ImVec4(0.07f, 0.10f, 0.15f, 0.97f);
		colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.30f, 0.26f, 0.39f, 1.00f);
		colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
		colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
		colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
		colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
		colors[ImGuiCol_TableHeaderBg] = ImVec4(0.19f, 0.19f, 0.20f, 1.00f);
		colors[ImGuiCol_TableBorderStrong] = ImVec4(0.31f, 0.31f, 0.35f, 1.00f);
		colors[ImGuiCol_TableBorderLight] = ImVec4(0.23f, 0.23f, 0.25f, 1.00f);
		colors[ImGuiCol_TableRowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
		colors[ImGuiCol_TableRowBgAlt] = ImVec4(1.00f, 1.00f, 1.00f, 0.06f);
		colors[ImGuiCol_TextSelectedBg] = ImVec4(0.64f, 0.78f, 0.94f, 0.35f);
		colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
		colors[ImGuiCol_NavHighlight] = ImVec4(0.69f, 0.79f, 0.90f, 1.00f);
		colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
		colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
		colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);
	};
};

void XsInfo(XsTexture& v, const char* name = nullptr, const char* _filedialogname = nullptr) {
	if (name != nullptr) ImGui::Begin(name);
	vex2f _t = vex2f(ImGui::GetWindowSize().x, ImGui::GetWindowSize().y);
	_t.normalize();
	ImGui::Image((void*)v.data, ImVec2(ImGui::GetWindowSize().x - 25, ImGui::GetWindowSize().x * _t.y - 25), ImVec2(0, 0), ImVec2(1, 1));
	ImGui::Text(("File Name: "s + v.fileName).c_str());
	ImGui::Text(("Size: x = "stx + v.scale().x + ", y = " + v.scale().y).c_str());
	if (ImGui::Button("Open File Diolog"))
		ImGuiFileDialog::Instance()->OpenDialog((_filedialogname == nullptr) ? "Load File" : (("Load File "s + _filedialogname).c_str()), "Choose File", ".png,.jpg", ".");
	if (name != nullptr) ImGui::End();
	if (ImGuiFileDialog::Instance()->Display((_filedialogname == nullptr) ? "Load File" : (("Load File "s + _filedialogname).c_str()))) {
		if (ImGuiFileDialog::Instance()->IsOk()) {
			v.fileName = ImGuiFileDialog::Instance()->GetFilePathName();
			v.load();
		};
		ImGuiFileDialog::Instance()->Close();
		if (Xs.KeyPressed(Xs.Key.Escape))
			ImGuiFileDialog::Instance()->Close();
	};
};
void XsInfo(XsCamera& v, const char* name = nullptr, bool editor_settings = false) {
	if (name != nullptr) ImGui::Begin(name);
	ImGui::DragFloat3("Position", v.pos, 0.01f, -FLT_MAX, FLT_MAX);
	if (editor_settings) {
		ImGui::DragFloat2("Rotation", Xs.Editor.Cam.Rot, 0.1f, -FLT_MAX, FLT_MAX);
		ImGui::DragFloat2("Rotation Velocity", Xs.Editor.Cam.RotVel, 0.001f, -FLT_MAX, FLT_MAX);
		ImGui::DragFloat3("Speed", Xs.Editor.Cam.Speed, 0.001f, -FLT_MAX, FLT_MAX);
		ImGui::DragFloat3("Speed V", Xs.Editor.Cam.Speed_v, 0.000001f, -FLT_MAX, FLT_MAX);
	}
	else
		ImGui::DragFloat3("Rotation", v.rot, 0.1f, -FLT_MAX, FLT_MAX);
	ImGui::DragFloat("Fov", &v.fov, 0.01f, -FLT_MAX, FLT_MAX);
	ImGui::DragFloat("Near", &v.near, 0.01f, -FLT_MAX, FLT_MAX);
	ImGui::DragFloat("Far", &v.far, 0.01f, -FLT_MAX, FLT_MAX);
	ImGui::DragInt2("View Port", v.viewport, 1, 1, INT_MAX);
	if (name != nullptr) ImGui::End();
};
static XsEnum __XS_last_load_vert_mode__ = Xs.Enum.Vertex;
static std::string __XS_last_load_vert_filename__ = "";
void XsInfo(XsShape& v, const char* name = nullptr) {
	if (name != nullptr) ImGui::Begin(name);
	ImGui::DragFloat3("Position", v.pos, 0.01f, -FLT_MAX, FLT_MAX);
	ImGui::DragFloat3("Rotation", v.rot, 0.5f, -FLT_MAX, FLT_MAX);
	ImGui::DragFloat3("Scale", v.scale, 0.01f, -FLT_MAX, FLT_MAX);
	ImGui::DragFloat3("Origin", v.origin, 0.01f, -FLT_MAX, FLT_MAX);
	ImGui::ColorPicker4("Color", v.color);
	
	int _XSIMVERTC_ = (v.mode == Xs.Enum.Vertex) ? 0 : (v.mode == Xs.Enum.VertexAndTexture) ? 1 : (v.mode == Xs.Enum.VertexAndNormal) ? 2 : (v.mode == Xs.Enum.All) ? 3 : 0;
	ImGui::Combo("Xs Mode", &_XSIMVERTC_, Xs.Values.XsModeNames, 4);
	v.mode = (_XSIMVERTC_ == 0) ? Xs.Enum.Vertex : (_XSIMVERTC_ == 1) ? Xs.Enum.VertexAndTexture : (_XSIMVERTC_ == 2) ? Xs.Enum.VertexAndNormal : (_XSIMVERTC_ == 3) ? Xs.Enum.All : Xs.Enum.Vertex;
	_XSIMVERTC_ = (v.glmode == GL_POINTS) ? 0 : (v.glmode == GL_LINES) ? 1 : (v.glmode == GL_TRIANGLES) ? 2 : (v.glmode == GL_QUADS) ? 3 : (v.glmode == GL_POLYGON) ? 4 : 0;
	ImGui::Combo("GL Mode", &_XSIMVERTC_, Xs.Values.GlModeNames, 5);
	v.glmode = (_XSIMVERTC_ == 0) ? GL_POINTS : (_XSIMVERTC_ == 1) ? GL_LINES : (_XSIMVERTC_ == 2) ? GL_TRIANGLES : (_XSIMVERTC_ == 3) ? GL_QUADS : GL_POLYGON;
	
	if (ImGui::TreeNode("Vertices")) {
		int _XSIMVERTC_ = (__XS_last_load_vert_mode__ == Xs.Enum.Vertex) ? 0 : (__XS_last_load_vert_mode__ == Xs.Enum.VertexAndTexture) ? 1 : (__XS_last_load_vert_mode__ == Xs.Enum.VertexAndNormal) ? 2 : (__XS_last_load_vert_mode__ == Xs.Enum.All) ? 3 : 0;
		ImGui::Combo("Load Mode", &_XSIMVERTC_, Xs.Values.XsModeNames, 4);
		__XS_last_load_vert_mode__ = (_XSIMVERTC_ == 0) ? Xs.Enum.Vertex : (_XSIMVERTC_ == 1) ? Xs.Enum.VertexAndTexture : (_XSIMVERTC_ == 2) ? Xs.Enum.VertexAndNormal : (_XSIMVERTC_ == 3) ? Xs.Enum.All : Xs.Enum.Vertex;
		ImGui::InputText("File Name", &__XS_last_load_vert_filename__);
		if (ImGui::Button("Open File Dialog! "))
			ImGuiFileDialog::Instance()->OpenDialog("Load File for Vert "s + name, "Choose File", ".obj", ".");
		if (ImGui::Button("Load!"))
			if (v.vert == nullptr)
				v.vert = new XsVerts(Xs.LoadOBJ(__XS_last_load_vert_filename__.c_str(), __XS_last_load_vert_mode__));
			else
				*v.vert = Xs.LoadOBJ(__XS_last_load_vert_filename__.c_str(), __XS_last_load_vert_mode__);
		if (ImGuiFileDialog::Instance()->Display("Load File for Vert "s + name)) {
			if (ImGuiFileDialog::Instance()->IsOk())
				__XS_last_load_vert_filename__ = ImGuiFileDialog::Instance()->GetFilePathName();
			ImGuiFileDialog::Instance()->Close();
			if (Xs.KeyPressed(Xs.Key.Escape))
				ImGuiFileDialog::Instance()->Close();
		};
		ImGui::TreePop();
	};

	if (ImGui::TreeNode("Texture")) {
		if (v.tex != nullptr)
			XsInfo(*v.tex, nullptr, name);
		else
			if (ImGui::Button("Create A Texture", { ImGui::GetWindowSize().x - 15, 0 }))
				v.tex = new XsTexture();
		ImGui::TreePop();
	};
	if (name != nullptr) ImGui::End();
};

class XsInfoList {
private:
	struct data_t {
		enum data_enums { Texture, Shape, Camera };
		data_t() = default;
		data_t(const char* _name, void* _data, data_enums _data_enum) {
			name = _name;
			data = _data;
			data_enum = _data_enum;
		};
		data_enums data_enum = data_enums::Shape;
		const char* name = nullptr;
		void* data = nullptr;
		bool open = false;
	};
	std::vector<data_t> datas;
public:
	XsInfoList(const char* _ListName) { ListName = _ListName; };
	std::string ListName;
	void Add(const char* name, XsTexture& tex) { datas.push_back(data_t(name, &tex, data_t::Texture)); };
	void Add(const char* name, XsShape& shape) { datas.push_back(data_t(name, &shape, data_t::Shape)); };
	void Add(const char* name, XsCamera& camera) { datas.push_back(data_t(name, &camera, data_t::Camera)); };

	void Draw() {
		ImGui::Begin(ListName.c_str());
		for (auto& i : datas)
			ImGui::Checkbox(i.name, &i.open);
		ImGui::End();
		for (const auto& i : datas)
			if (i.open == true)
				if (i.data_enum == data_t::Texture)
					XsInfo(*static_cast<XsTexture*>(i.data), i.name);
				else if (i.data_enum == data_t::Shape)
					XsInfo(*static_cast<XsShape*>(i.data), i.name);
				else if (i.data_enum == data_t::Camera)
					XsInfo(*static_cast<XsCamera*>(i.data), i.name);
	};
};