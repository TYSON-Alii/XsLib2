struct XsShape {
	XsShape() = default;
	XsShape(const std::string& loadfrom) {
		std::ifstream i(loadfrom);
		if (i.is_open()) {
			json loadfile;
			i >> loadfile;
			pos    = vex3f(float(loadfile["pos"][0]), float(loadfile["pos"][1]), float(loadfile["pos"][2]));
			rot    = vex3f(float(loadfile["rot"][0]), float(loadfile["rot"][1]), float(loadfile["rot"][2]));
			scale  = vex3f(float(loadfile["scale"][0]), float(loadfile["scale"][1]), float(loadfile["scale"][2]));
			origin = vex3f(float(loadfile["origin"][0]), float(loadfile["origin"][1]), float(loadfile["origin"][2]));
			color  = vex4f(float(loadfile["color"][0]), float(loadfile["color"][1]), float(loadfile["color"][2]), float(loadfile["color"][3]));
		}
		else {
			std::cerr << "Shape Cannot Load.";
			Xs.Log << "Shape Cannot Load.";
		};
	};
	vex3f pos = 0.f, rot = 0.f, scale = 1.f, origin = 0.f;
	vex4f color = 1.f;
	XsMesh* mesh = nullptr;
	XsTexture* tex = nullptr;
	virtual void loop() { };
	void draw(const bool& _reset_matrix = true) {
		loop();
		if (_reset_matrix) glLoadIdentity();
		glTranslatef(pos);
		limit(rot, 0.f, 360.f, true);
		glRotatef(rot);
		glScalef(scale);
		glTranslatef(origin);
		glColor4f(color);
		if (mesh != nullptr) {
			if (tex != nullptr)
				tex->bind();
			else
				glBindTexture(GL_TEXTURE_2D, 0);
			glEnableClientState(GL_VERTEX_ARRAY);
			glVertexPointer(3, GL_FLOAT, sizeof(vex3f), &mesh->pos[0]);
			glEnableClientState(GL_TEXTURE_COORD_ARRAY);
			glTexCoordPointer(2, GL_FLOAT, sizeof(vex2f), &mesh->tex[0]);
			glEnableClientState(GL_NORMAL_ARRAY);
			glNormalPointer(GL_FLOAT, sizeof(vex3f), &mesh->normal[0]);
			glDrawArrays(mesh->poly, 0, mesh->pos.size());
			glDisableClientState(GL_VERTEX_ARRAY);
			glDisableClientState(GL_NORMAL_ARRAY);
			glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		};
	};
	void save(const char* filename) const {
		json savefile{
			{"pos",   {pos.x, pos.y, pos.z}					},
			{"rot",	  {rot.x, rot.y, rot.z}					},
			{"scale", {scale.x, scale.y, scale.z}			},
			{"origin",{origin.x, origin.y, origin.z}		},
			{"color", {color.x, color.y, color.z, color.w}	}
		};
		std::ofstream o(filename);
		o << savefile;
		o.close();
	};
	operator std::string() const {
		std::string t;
		(t += "[Pos   ]: ") += pos.str  (", ", "\n");
		(t += "[Rot   ]: ") += rot.str  (", ", "\n");
		(t += "[Scale ]: ") += scale.str(", ", "\n");
		(t += "[Color ]: ") += color.str(", ", "\n");
		return t;
	};
	friend std::ostream& operator<<(std::ostream& os, const XsShape& v) { return os << (std::string)v; };
};