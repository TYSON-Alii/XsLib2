namespace ImGui {
	void StyleXsDark() {
		ImVec4* colors = ImGui::GetStyle().Colors;
		colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
		colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
		colors[ImGuiCol_WindowBg] = ImVec4(0.10f, 0.10f, 0.10f, 0.28f);
		colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
		colors[ImGuiCol_PopupBg] = ImVec4(0.19f, 0.19f, 0.19f, 0.92f);
		colors[ImGuiCol_Border] = ImVec4(0.19f, 0.19f, 0.19f, 0.29f);
		colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.24f);
		colors[ImGuiCol_FrameBg] = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
		colors[ImGuiCol_FrameBgHovered] = ImVec4(0.19f, 0.19f, 0.19f, 0.54f);
		colors[ImGuiCol_FrameBgActive] = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
		colors[ImGuiCol_TitleBg] = ImVec4(0.06f, 0.06f, 0.06f, 1.00f);
		colors[ImGuiCol_TitleBgActive] = ImVec4(0.06f, 0.06f, 0.06f, 1.00f);
		colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.06f, 0.06f, 0.06f, 1.00f);
		colors[ImGuiCol_MenuBarBg] = ImVec4(0.06f, 0.06f, 0.06f, 1.00f);
		colors[ImGuiCol_ScrollbarBg] = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
		colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.34f, 0.34f, 0.34f, 0.54f);
		colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.40f, 0.40f, 0.40f, 0.54f);
		colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.56f, 0.56f, 0.56f, 0.54f);
		colors[ImGuiCol_CheckMark] = ImVec4(0.89f, 0.46f, 0.54f, 1.00f);
		colors[ImGuiCol_SliderGrab] = ImVec4(0.34f, 0.34f, 0.34f, 0.54f);
		colors[ImGuiCol_SliderGrabActive] = ImVec4(0.56f, 0.56f, 0.56f, 0.54f);
		colors[ImGuiCol_Button] = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
		colors[ImGuiCol_ButtonHovered] = ImVec4(0.19f, 0.19f, 0.19f, 0.54f);
		colors[ImGuiCol_ButtonActive] = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
		colors[ImGuiCol_Header] = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
		colors[ImGuiCol_HeaderHovered] = ImVec4(0.00f, 0.00f, 0.00f, 0.36f);
		colors[ImGuiCol_HeaderActive] = ImVec4(0.20f, 0.22f, 0.23f, 0.33f);
		colors[ImGuiCol_Separator] = ImVec4(0.28f, 0.28f, 0.28f, 0.29f);
		colors[ImGuiCol_SeparatorHovered] = ImVec4(0.44f, 0.44f, 0.44f, 0.29f);
		colors[ImGuiCol_SeparatorActive] = ImVec4(0.40f, 0.44f, 0.47f, 1.00f);
		colors[ImGuiCol_ResizeGrip] = ImVec4(0.f, 0.f, 0.f, 0.f);
		colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.f, 0.f, 0.f, 0.f);
		colors[ImGuiCol_ResizeGripActive] = ImVec4(0.f, 0.f, 0.f, 0.f);
		colors[ImGuiCol_Tab] = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
		colors[ImGuiCol_TabHovered] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
		colors[ImGuiCol_TabActive] = ImVec4(0.20f, 0.20f, 0.20f, 0.36f);
		colors[ImGuiCol_TabUnfocused] = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
		colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
		colors[ImGuiCol_PlotLines] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
		colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
		colors[ImGuiCol_PlotHistogram] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
		colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
		colors[ImGuiCol_TableHeaderBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
		colors[ImGuiCol_TableBorderStrong] = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
		colors[ImGuiCol_TableBorderLight] = ImVec4(0.28f, 0.28f, 0.28f, 0.29f);
		colors[ImGuiCol_TableRowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
		colors[ImGuiCol_TableRowBgAlt] = ImVec4(1.00f, 1.00f, 1.00f, 0.06f);
		colors[ImGuiCol_TextSelectedBg] = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
		colors[ImGuiCol_DragDropTarget] = ImVec4(0.33f, 0.67f, 0.86f, 1.00f);
		colors[ImGuiCol_NavHighlight] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
		colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 0.00f, 0.00f, 0.70f);
		colors[ImGuiCol_NavWindowingDimBg] = ImVec4(1.00f, 0.00f, 0.00f, 0.20f);
		colors[ImGuiCol_ModalWindowDimBg] = ImVec4(1.00f, 0.00f, 0.00f, 0.35f);

		ImGuiStyle& style = ImGui::GetStyle();
		style.WindowPadding = ImVec2(8.00f, 8.00f);
		style.FramePadding = ImVec2(5.00f, 2.00f);
		style.CellPadding = ImVec2(6.00f, 6.00f);
		style.ItemSpacing = ImVec2(6.00f, 6.00f);
		style.ItemInnerSpacing = ImVec2(6.00f, 6.00f);
		style.TouchExtraPadding = ImVec2(0.00f, 0.00f);
		style.IndentSpacing = 25;
		style.ScrollbarSize = 11;
		style.GrabMinSize = 10;
		style.WindowBorderSize = 1;
		style.ChildBorderSize = 1;
		style.PopupBorderSize = 1;
		style.FrameBorderSize = 1;
		style.TabBorderSize = 1;
		style.WindowRounding = 0;
		style.ChildRounding = 0;
		style.FrameRounding = 3;
		style.PopupRounding = 3;
		style.ScrollbarRounding = 0;
		style.GrabRounding = 3;
		style.LogSliderDeadzone = 4;
		style.TabRounding = 3;
	};
	bool RedButton(const std::string& label) {
		auto them = &ImGui::GetStyle();
		const auto c1 = them->Colors[ImGuiCol_Button];
		const auto c2 = them->Colors[ImGuiCol_ButtonActive];
		const auto c3 = them->Colors[ImGuiCol_ButtonHovered];
		them->Colors[ImGuiCol_Button] = ImVec4(Xs.Color.Red.x, Xs.Color.Red.y, Xs.Color.Red.z, 0.726);
		them->Colors[ImGuiCol_ButtonActive] = ImVec4(Xs.Color.Red.x, Xs.Color.Red.y, Xs.Color.Red.z, 0.886);
		them->Colors[ImGuiCol_ButtonHovered] = ImVec4(Xs.Color.Red.x, Xs.Color.Red.y, Xs.Color.Red.z, 0.986);
		const bool& b = ImGui::Button(label.c_str());
		them->Colors[ImGuiCol_Button] = c1;
		them->Colors[ImGuiCol_ButtonActive] = c2;
		them->Colors[ImGuiCol_ButtonHovered] = c3;
		return b;
	};
};
void XsInfo(XsTexture& v, const char* name = nullptr) {
	if (name != nullptr) ImGui::Begin(name);
	const vex2f _t = vex2f(ImGui::GetWindowSize().x, ImGui::GetWindowSize().y).normalize();
	ImGui::Image((void*)v.data, ImVec2(ImGui::GetWindowSize().x - 25, ImGui::GetWindowSize().x * _t.y - 25), ImVec2(0, 0), ImVec2(1, 1));
	ImGui::Text(("File Name: "s + v.fileName).c_str());
	ImGui::Text(("Size: X = "s + std::to_string(v.scale().x) + ", Y = " + std::to_string(v.scale().y)).c_str());
	if (ImGui::Button("Load From File")) {
		const auto& s = pfd::open_file::open_file("Select File", std::filesystem::current_path().string(), { "Image Files", "*.png *.jpg *.jpeg *.gif" }, pfd::opt::none).result();
		if (!s.empty()) {
			v.load(s[0]);
		};
	};
	if (name != nullptr) ImGui::End();
};
void XsInfo(XsLight& v, const char* name = nullptr) {
	if (name != nullptr) ImGui::Begin(name);
	ImGui::DragFloat3("Position", *v.pos, 0.01f, -FLT_MAX, FLT_MAX);
	ImGui::DragFloat("Power", &v.power, 0.01f, -FLT_MAX, FLT_MAX);
	ImGui::ColorPicker3("Color", *v.color);
	if (name != nullptr) ImGui::End();
}
void XsInfo(XsShape& v, const char* name = nullptr) {
	if (name != nullptr) ImGui::Begin(name);
	ImGui::DragFloat3("Position", *v.pos, 0.01f, -FLT_MAX, FLT_MAX);
	ImGui::DragFloat3("Rotation", *v.rot, 0.1f, -FLT_MAX, FLT_MAX);
	ImGui::DragFloat3("Scale", *v.scale, 0.01f, -FLT_MAX, FLT_MAX);
	ImGui::DragFloat3("Origin", *v.origin, 0.01f, -FLT_MAX, FLT_MAX);
	ImGui::ColorPicker4("Color", *v.color);
	if (ImGui::TreeNode("Material")) {
		ImGui::DragFloat3("Ambient", *v.material.ambient, 0.01f, -FLT_MAX, FLT_MAX);
		ImGui::DragFloat3("Diffuse", *v.material.diffuse, 0.01f, -FLT_MAX, FLT_MAX);
		ImGui::DragFloat3("Specular", *v.material.specular, 0.01f, -FLT_MAX, FLT_MAX);
		ImGui::DragFloat("Shininess", &v.material.shininess, 0.01f, -FLT_MAX, FLT_MAX);
		ImGui::TreePop();
	};
	if (ImGui::TreeNode("Texture")) {
		if (v.tex != nullptr) XsInfo(*v.tex);
		ImGui::TreePop();
	};
	if (ImGui::TreeNode("Mesh")) {
		if (v.mesh == nullptr) {
			if (ImGui::Button("Load From OBJ")) {
				auto s = pfd::open_file::open_file("Select File", std::filesystem::current_path().string(), { "Obj", "*.obj" }, pfd::opt::none).result();
				if (!s.empty()) v.mesh = new XsMesh(Xs.LoadOBJ(s[0]));
			};
			if (ImGui::IsWindowHovered() and ImGui::GetIO().MouseClicked[1])
				ImGui::OpenPopup("rclick");
			if (ImGui::BeginPopup("rclick")) {
				ImGui::Text("Solid Meshs:");
				ImGui::Separator();
				if (ImGui::MenuItem("Plane"))
					v.mesh = new XsMesh(Xs.Mesh.Plane);
				if (ImGui::MenuItem("Cube"))
					v.mesh = new XsMesh(Xs.Mesh.Cube);
				ImGui::EndPopup();
			};
		}
		else {
			int temp_s = (v.mesh->poly == Xs.Enum.Point) ? 0 : (v.mesh->poly == Xs.Enum.Line) ? 1 : (v.mesh->poly == Xs.Enum.Triangle) ? 2 : (v.mesh->poly == Xs.Enum.Quad) ? 3 : (v.mesh->poly == Xs.Enum.Polygon) ? 4 : 0;
			ImGui::Combo("Poly", &temp_s, Xs.Values.PolyNames, 5);
			v.mesh->poly = (temp_s == 0) ? Xs.Enum.Point : (temp_s == 1) ? Xs.Enum.Line : (temp_s == 2) ? Xs.Enum.Triangle : (temp_s == 3) ? Xs.Enum.Quad : Xs.Enum.Polygon;
			if (ImGui::Button("Load From OBJ")) {
				auto s = pfd::open_file::open_file("Select File", std::filesystem::current_path().string(), { "Obj", "*.obj" }, pfd::opt::none).result();
				if (!s.empty()) *v.mesh = Xs.LoadOBJ(s[0]);
			};
			if (ImGui::RedButton("Remove") and ImGui::GetIO().MouseDoubleClicked[0]) {
				*v.mesh = XsMesh();
				v.mesh = nullptr;
			};
			if (ImGui::IsWindowHovered() and ImGui::GetIO().MouseClicked[1])
				ImGui::OpenPopup("rclick");
			if (ImGui::BeginPopup("rclick")) {
				ImGui::Text("Solid Meshs:");
				ImGui::Separator();
				if (ImGui::MenuItem("Plane"))
					*v.mesh = XsMesh(Xs.Mesh.Plane);
				if (ImGui::MenuItem("Cube"))
					*v.mesh = XsMesh(Xs.Mesh.Cube);
				ImGui::EndPopup();
			};
		};
		ImGui::TreePop();
	};
	if (name != nullptr) ImGui::End();
};
template <XsRigidType T>
void XsInfo(XsRigid<T>& v, const char* name = nullptr) {
	if (name != nullptr) ImGui::Begin(name);
	//vex3f t;
	//t = v.pos();
	//ImGui::DragFloat3("Position", *t, 0.01f, -FLT_MAX, FLT_MAX);
	//v.pos(t);
	//t = v.velLin();
	//ImGui::DragFloat3("Linear Vel", *t, 0.01f, -FLT_MAX, FLT_MAX);
	//v.velLin(t);
	//t = v.velAng();
	//ImGui::DragFloat3("Angular Vel", *t, 0.01f, -FLT_MAX, FLT_MAX);
	//v.velAng(t);
	ImGui::DragFloat3("Scale", *v.scale, 0.01f, -FLT_MAX, FLT_MAX);
	ImGui::DragFloat3("Origin", *v.origin, 0.01f, -FLT_MAX, FLT_MAX);
	ImGui::ColorPicker4("Color", *v.color);
	//ImGui::Text("Lock Lin Axis: ");
	//{
	//	auto b = v.lockLinAxis();
	//	ImGui::SameLine(50, -50);
	//	ImGui::PushStyleColor(ImGuiCol_Text, ImVec4( Xs.Color.Red.x,Xs.Color.Red.y,Xs.Color.Red.z,0.89 ));
	//	ImGui::Checkbox("X", &b.x);
	//	ImGui::PopStyleColor();
	//	ImGui::SameLine(100, -50);
	//	ImGui::PushStyleColor(ImGuiCol_Text, ImVec4( Xs.Color.DarkGreen.x,Xs.Color.DarkGreen.y,Xs.Color.DarkGreen.z,0.89 ));
	//	ImGui::Checkbox("Y", &b.y);
	//	ImGui::PopStyleColor();
	//	ImGui::SameLine(150, -50);
	//	ImGui::PushStyleColor(ImGuiCol_Text, ImVec4( Xs.Color.Blue.x,Xs.Color.Blue.y,Xs.Color.Blue.z,0.89 ));
	//	ImGui::Checkbox("Z", &b.z);
	//	ImGui::PopStyleColor();
	//	v.lockLinAxis(b);
	//};
	//ImGui::Text("Lock Ang Axis: ");
	//{
	//	auto b = v.lockAngAxis();
	//	ImGui::SameLine(50, -50);
	//	ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(Xs.Color.Red.x, Xs.Color.Red.y, Xs.Color.Red.z, 0.89));
	//	ImGui::Checkbox("X", &b.x);
	//	ImGui::PopStyleColor();
	//	ImGui::SameLine(100, -50);
	//	ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(Xs.Color.DarkGreen.x, Xs.Color.DarkGreen.y, Xs.Color.DarkGreen.z, 0.89));
	//	ImGui::Checkbox("Y", &b.y);
	//	ImGui::PopStyleColor();
	//	ImGui::SameLine(150, -50);
	//	ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(Xs.Color.Blue.x, Xs.Color.Blue.y, Xs.Color.Blue.z, 0.89));
	//	ImGui::Checkbox("Z", &b.z);
	//	ImGui::PopStyleColor();
	//	v.lockAngAxis(b);
	//};
	if (ImGui::TreeNode("Material")) {
		ImGui::DragFloat3("Ambient", *v.material.ambient, 0.01f, -FLT_MAX, FLT_MAX);
		ImGui::DragFloat3("Diffuse", *v.material.diffuse, 0.01f, -FLT_MAX, FLT_MAX);
		ImGui::DragFloat3("Specular", *v.material.specular, 0.01f, -FLT_MAX, FLT_MAX);
		ImGui::DragFloat("Shininess", &v.material.shininess, 0.01f, -FLT_MAX, FLT_MAX);
		ImGui::TreePop();
	};
	if (ImGui::TreeNode("Texture")) {
		if (v.tex != nullptr) XsInfo(*v.tex);
		ImGui::TreePop();
	};
	if (ImGui::TreeNode("Mesh")) {
		if (v.mesh == nullptr) {
			if (ImGui::Button("Load From OBJ")) {
				auto s = pfd::open_file::open_file("Select File", std::filesystem::current_path().string(), { "Obj", "*.obj" }, pfd::opt::none).result();
				if (!s.empty()) v.mesh = new XsMesh(Xs.LoadOBJ(s[0]));
			};
			if (ImGui::IsWindowHovered() and ImGui::GetIO().MouseClicked[1])
				ImGui::OpenPopup("rclick");
			if (ImGui::BeginPopup("rclick")) {
				ImGui::Text("Solid Meshs:");
				ImGui::Separator();
				if (ImGui::MenuItem("Plane"))
					v.mesh = new XsMesh(Xs.Mesh.Plane);
				if (ImGui::MenuItem("Cube"))
					v.mesh = new XsMesh(Xs.Mesh.Cube);
				ImGui::EndPopup();
			};
		}
		else {
			int temp_s = (v.mesh->poly == Xs.Enum.Point) ? 0 : (v.mesh->poly == Xs.Enum.Line) ? 1 : (v.mesh->poly == Xs.Enum.Triangle) ? 2 : (v.mesh->poly == Xs.Enum.Quad) ? 3 : (v.mesh->poly == Xs.Enum.Polygon) ? 4 : 0;
			ImGui::Combo("Poly", &temp_s, Xs.Values.PolyNames, 5);
			v.mesh->poly = (temp_s == 0) ? Xs.Enum.Point : (temp_s == 1) ? Xs.Enum.Line : (temp_s == 2) ? Xs.Enum.Triangle : (temp_s == 3) ? Xs.Enum.Quad : Xs.Enum.Polygon;
			if (ImGui::Button("Load From OBJ")) {
				auto s = pfd::open_file::open_file("Select File", std::filesystem::current_path().string(), { "Obj", "*.obj" }, pfd::opt::none).result();
				if (!s.empty()) *v.mesh = Xs.LoadOBJ(s[0]);
			};
			if (ImGui::RedButton("Remove") and ImGui::GetIO().MouseDoubleClicked[0]) {
				*v.mesh = XsMesh();
				v.mesh = nullptr;
			};
			if (ImGui::IsWindowHovered() and ImGui::GetIO().MouseClicked[1])
				ImGui::OpenPopup("rclick");
			if (ImGui::BeginPopup("rclick")) {
				ImGui::Text("Solid Meshs:");
				ImGui::Separator();
				if (ImGui::MenuItem("Plane"))
					*v.mesh = XsMesh(Xs.Mesh.Plane);
				if (ImGui::MenuItem("Cube"))
					*v.mesh = XsMesh(Xs.Mesh.Cube);
				ImGui::EndPopup();
			};
		};
		ImGui::TreePop();
	};
	if (name != nullptr) ImGui::End();
};