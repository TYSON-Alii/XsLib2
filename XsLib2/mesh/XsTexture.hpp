bool decltype(Xs)::LoadTexture(const char* filename, unsigned int& _tex_data, GLenum _filter = GL_NEAREST) {
    glGenTextures(1, &_tex_data);
    glBindTexture(GL_TEXTURE_2D, _tex_data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, _filter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, _filter);
    int _widthh, _heightt, _nrChannels;
    unsigned char* _data = stbi_load(filename, &_widthh, &_heightt, &_nrChannels, 0);
    if (_data) {
        glTexImage2D(GL_TEXTURE_2D, 0, (_nrChannels == 4) ? GL_RGBA : GL_RGB, _widthh, _heightt, 0, (_nrChannels == 4) ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, _data);
        glGenerateMipmap(GL_TEXTURE_2D);
        return true;
    }
    else {
       std::cout << "Failed to Load \""s + filename + '"' + "Image.\n";
       Xs.Log << ("Failed to Load \""s + filename + '"' + "Image.\n").c_str();
       glBindTexture(GL_TEXTURE_2D, 0);
       stbi_image_free(_data);
       return false;
    };
    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(_data);
};
class XsTexture {
private:
    vex2i _scale;
    bool _isl = false;
public:
    XsTexture() = default;
    XsTexture(const char* _f) {
        load(_f);
        _isl = true;
    };
    XsTexture(const char* _f, GLenum _filter) {
        filter = _filter;
        load(_f);
        _isl = true;
    };
    XsTexData data;
    GLenum filter = GL_NEAREST;
    vex2i scale() { return _scale; };
    std::string fileName;
    bool isLoad() { return _isl; };
    void load(const char* _file_name);
    void load();
    void bind();
};
void XsTexture::load(const char* _file_name) {
    fileName = _file_name;
    glGenTextures(1, &data);
    glBindTexture(GL_TEXTURE_2D, data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter);
    int _widthh, _heightt, _nrChannels;
    auto __data = stbi_load(_file_name, &_widthh, &_heightt, &_nrChannels, 0);
    if (__data) {
        _scale = vex2i(_widthh, _heightt);
        glTexImage2D(GL_TEXTURE_2D, 0, (_nrChannels == 4) ? GL_RGBA : GL_RGB, _widthh, _heightt, 0, (_nrChannels == 4) ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, __data);
        //glGenerateMipmap(GL_TEXTURE_2D);
        _isl = true;
    }
    else {
        std::cout << "Failed to Load \""s + fileName + '"' + "Image.\n";
        Xs.Log << ("Failed to Load \""s + fileName + '"' + "Image.\n").c_str();
    };
    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(__data);
};
void XsTexture::load() {
    const char* _file_name = fileName.c_str();
    glGenTextures(1, &data);
    glBindTexture(GL_TEXTURE_2D, data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter);
    int _widthh, _heightt, _nrChannels;
    unsigned char* __data = stbi_load(_file_name, &_widthh, &_heightt, &_nrChannels, 0);
    if (__data) {
        _scale = vex2i(_widthh, _heightt);
        glTexImage2D(GL_TEXTURE_2D, 0, (_nrChannels == 4) ? GL_RGBA : GL_RGB, _widthh, _heightt, 0, (_nrChannels == 4) ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, __data);
        glGenerateMipmap(GL_TEXTURE_2D);
        _isl = true;
    }
    else {
        std::cout << "Failed to Load \""s + fileName + '"' + "Image.\n";
        Xs.Log << ("Failed to Load \""s + fileName + '"' + "Image.\n").c_str();
    };
    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(__data);
};
void XsTexture::bind() {
    glBindTexture(GL_TEXTURE_2D, data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter);
}