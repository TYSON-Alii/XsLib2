struct XsShape {
	XsShape() = default;
	XsShape(XsVerts& v) { vert = &v; };
#ifdef _XsEngine_
	const char* name = nullptr;
	float lineWidth = 1.f, pointSize = 1.f;
#endif
	vex3f pos = 0.f, rot = 0.f, scale = 1.f, origin = 0.f;
	vex4f color = 1.f;
	XsVerts* vert = nullptr;
	decltype(Xs.Enum)::Enum_t mode = Xs.Enum.Vertex;
	GLenum glmode = GL_TRIANGLES;
	XsTexture* tex = nullptr;
	XsShader* shader = nullptr;
	inline vex3f& move(float x, float y, float z)			{ return pos += vex3f(x, y, z); };
	template <typename T> inline vex3f& move(vex4<T> xyz)	{ return pos += xyz;			};
	template <typename T> inline vex3f& move(vex3<T> xyz)	{ return pos += xyz;			};
	template <typename T> inline vex3f& move(vex2<T> xy)	{ return pos += xy;				};
	void draw(const bool _reset_matrix = true) {
		if (_reset_matrix)
			glLoadIdentity();
#ifdef _XsEngine_
		if (glmode == GL_POINT) glPointSize(pointSize);
		else if (glmode == GL_LINES) glLineWidth(lineWidth);
#endif
		glTranslatef(pos);
		Xs.Math.Limit(rot, vex3f(0.f), vex3f(360.f));
		glRotatef(rot);
		glScalef(scale);
		glTranslatef(origin);
		glColor4f(color);
		if (vert != nullptr) {
			if (tex != nullptr)
				tex->bind();
			else
				glBindTexture(GL_TEXTURE_2D, 0);
			if (shader != nullptr) shader->use();
			Xs.Draw(*vert, mode, glmode);
			if (shader != nullptr) glUseProgram(0);
		};
#ifdef _XsEngine_
		if (glmode == GL_POINT) glPointSize(1.f);
		else if (glmode == GL_LINES) glLineWidth(1.f);
#endif
	};
	operator strinx() const {
		strinx t;
		t < "[Pos]:   " < pos.str  (", ", "\n");
		t < "[Rot]:   " < rot.str  (", ", "\n");
		t < "[Scale]: " < scale.str(", ", "\n");
		t < "[Color]: " < color.str(", ", "\n");
		return t;
	};
	friend std::ostream& operator<<(std::ostream& os, const XsShape& v) { return os << strinx(v); };
};
void decltype(Xs)::Draw(XsVerts vert, XsEnum mode = Xs.Enum.Vertex, GLenum glmode = GL_TRIANGLES) {
	switch (mode) {
	case XsEnum::Vertex:
		glEnableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_NORMAL_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		glVertexPointer(3, GL_FLOAT, 3 * sizeof(GLfloat), &vert[0]);
		glDrawArrays(glmode, 0, vert.size() / 3);
		glDisableClientState(GL_VERTEX_ARRAY);
		break;
	case XsEnum::VertexAndTexture:
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glDisableClientState(GL_NORMAL_ARRAY);
		glVertexPointer(3, GL_FLOAT, 5 * sizeof(GLfloat), &vert[0]);
		glTexCoordPointer(2, GL_FLOAT, 5 * sizeof(GLfloat), &vert[0] + 3);
		glDrawArrays(glmode, 0, vert.size() / 5);
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		break;
	case XsEnum::VertexAndNormal:
		glEnableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		glEnableClientState(GL_NORMAL_ARRAY);
		glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), &vert[0]);
		glNormalPointer(GL_FLOAT, 6 * sizeof(GLfloat), &vert[0] + 3);
		glDrawArrays(glmode, 0, vert.size() / 6);
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_NORMAL_ARRAY);
		break;
	case XsEnum::All:
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glEnableClientState(GL_NORMAL_ARRAY);
		glVertexPointer(3, GL_FLOAT, 8 * sizeof(GLfloat), &vert[0]);
		glTexCoordPointer(2, GL_FLOAT, 8 * sizeof(GLfloat), &vert[0] + 3);
		glNormalPointer(GL_FLOAT, 8 * sizeof(GLfloat), &vert[0] + 5);
		glDrawArrays(glmode, 0, vert.size() / 8);
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_NORMAL_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		break;
	default:
		glEnableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_NORMAL_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		glVertexPointer(3, GL_FLOAT, 3 * sizeof(GLfloat), &vert[0]);
		glDrawArrays(glmode, 0, vert.size() / 3);
		glDisableClientState(GL_VERTEX_ARRAY);
		break;
	};
};