struct XsShape {
	XsShape() = default;
	XsShape(XsVerts& v) { vert = &v; };
	vex3f pos = 0.f, rot = 0.f, scale = 1.f;
	vex4f color = vex4f(vex3f(0.f), 1.f);
	XsVerts* vert = nullptr;
	decltype(Xs.Enum)::Enum_t mode = Xs.Enum.Vertex;
	GLenum glmode = GL_TRIANGLES;
	XsTexture* tex = nullptr;
	inline vex3f& move(float x, float y, float z)	{ return pos += vex3f(x, y, z); };
	inline vex3f& move(vex4f xyz)					{ return pos += xyz; };
	inline vex3f& move(vex3f xyz)					{ return pos += xyz; };
	inline vex3f& move(vex2f xy)					{ return pos += xy; };
	void draw(const bool _reset_matrix = true) {
		if (_reset_matrix)
			glLoadIdentity();
		if (tex != nullptr)
			tex->bind();
		glTranslatef(pos);
		glRotatef(rot);
		glScalef(scale);
		if (vert != nullptr)
			Xs.Draw(*vert, mode, glmode);
	};
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
