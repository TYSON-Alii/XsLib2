struct XsShape {
	vex3f pos = 0.f, rot = 0.f, scale = 1.f;
	vex4f color = vex4f(vex3f(0.f), 1.f);
	unsigned int vert = 0;
	XsTexture tex = 0;
	vex3f& move(float x, float y, float z)	{ return pos += vex3f(x, y, z); };
	vex3f& move(vex3f xyz)                  { return pos += xyz; };
	vex3f& move(vex2f xy)					{ return pos += xy; };
	void draw() {
		glTranslatef(pos);
		glRotatef(rot);
		glScalef(scale);
	};
};
