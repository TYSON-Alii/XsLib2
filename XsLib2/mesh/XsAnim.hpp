class XsAnim : public XsEntity {
private:
    void gif_load(const std::string& filename) {
        EasyGifReader gifReader = EasyGifReader::openFile(filename.c_str());
        const auto& frameCount = gifReader.frameCount();
        const auto& x = gifReader.width();
        const auto& y = gifReader.height();
        duration = gifReader.begin()->duration().seconds();
        for (EasyGifReader::Frame frame : gifReader) {
            XsTexture t;
            t.loadFromMemory((void*)frame.pixels(), x, y, GL_RGBA, GL_UNSIGNED_BYTE);
            Frame(t);
        };
    };
    XsChrono clk;
    std::vector<XsTexture> tex_data;
    XsTexture c_frame;
    size_t current_index = 0;
public:
    XsAnim() = default;
    XsAnim(const XsAnim&) = default;
    inline void loadFromGIF(const std::string& filename) { gif_load(filename); };
    inline void Frame(XsTexture tex) { tex_data.push_back(tex); };
    inline XsTexture& Frame(const size_t& at) { return tex_data[at]; };
    inline XsTexture Frame(const size_t& at) const { return tex_data[at]; };
    inline void Remove(const size_t& at) { tex_data.erase(tex_data.begin()+at); };
    inline void Clear() {
        clk.restart();
        current_index = 0;
        c_frame = XsTexture();
        tex_data.clear();
    };
    inline void Reset() {
        if( !tex_data.empty() )
            c_frame = tex_data.front();
        else
            c_frame = XsTexture();
        current_index = 0;
        clk.restart();
    };
    bool move_reverse = false;
    float duration = 1.f;
    inline XsTexture& Current() { return c_frame; };
    inline XsTexture Current() const { return c_frame; };
    void Step() {
        if( XsLimiter(clk, duration) ) {
            if( move_reverse ) {
                if( current_index==0 ) current_index = tex_data.size();
                current_index--;
                c_frame = tex_data[current_index];
                clk.restart();
            }
            else {
                current_index++;
                if( current_index==tex_data.size() ) current_index = 0;
                c_frame = tex_data[current_index];
                clk.restart();
            };
        };
    };
};
//class XsAnimMesh {
//private:
//    void fbx_load(const std::string& filename) {
//        FILE* fp = fopen(filename.c_str(), "rb");
//        fseek(fp, 0, SEEK_END);
//        long file_size = ftell(fp);
//        fseek(fp, 0, SEEK_SET);
//        auto* content = new ofbx::u8[file_size];
//        fread(content, 1, file_size, fp);
//        auto scene = ofbx::load((ofbx::u8*)content, file_size, (ofbx::u64)ofbx::LoadFlags::TRIANGULATE);
//        for (int i = 0; i < (scene->getMeshCount()); ++i) {
//            const ofbx::Mesh& mesh = *(scene->getMesh(i));
//            const ofbx::Geometry& geom = *mesh.getGeometry();
//            int vertex_count = geom.getVertexCount();
//            const ofbx::Vec3* vertices = geom.getVertices();
//            const ofbx::Vec3* normals = geom.getNormals();
//            const ofbx::Vec2* uvs = geom.getUVs();
//            XsMesh t;
//            for (size_t i = 0; i < vertex_count; ++i) {
//                t.add(
//                    { vertices[i].x,vertices[i].y,vertices[i].z },
//                    { uvs[i].x, uvs[i].y },
//                    { normals[i].x,normals[i].y, normals[i].z }
//                );
//            };
//            Frame(t);
//        };
//    };
//    XsChrono clk;
//    std::vector<XsMesh> mesh_data;
//    XsMesh c_frame;
//    size_t current_index = 0;
//public:
//    XsAnimMesh() = default;
//    XsAnimMesh(const XsAnimMesh&) = default;
//    XsAnimMesh(XsAnimMesh&&) = default;
//    inline void loadFromFBX(const std::string& filename) { fbx_load(filename); };
//    inline void Frame(XsMesh mesh) { mesh_data.push_back(mesh); };
//    inline XsMesh& Frame(const size_t & at) { return mesh_data[at]; };
//    inline XsMesh Frame(const size_t & at) const { return mesh_data[at]; };
//    inline void Remove(const size_t& at) { mesh_data.erase(mesh_data.begin() + at); };
//    inline void Clear() {
//        clk.restart();
//        current_index = 0;
//        c_frame = XsMesh();
//        mesh_data.clear();
//    };
//    inline void Reset() {
//        if (!mesh_data.empty())
//            c_frame = mesh_data.front();
//        else
//            c_frame = XsMesh();
//        current_index = 0;
//        clk.restart();
//    };
//    float speed = 1.f;
//    inline XsMesh& Current() { return c_frame; };
//    inline XsMesh Current() const { return c_frame; };
//    void Step() {
//        if (XsLimiter(clk, speed)) {
//            current_index++;
//            if (current_index == mesh_data.size())
//                current_index = 0;
//            c_frame = mesh_data[current_index];
//            clk.restart();
//        };
//    };
//};