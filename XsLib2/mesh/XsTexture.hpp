class XsTexture {
private:
    vex2i _scale = 0;
    bool _isl = false;
    static const GLenum filter = GL_NEAREST;
public:
    XsTexture() = default;
    XsTexture(const std::string& _f) {
        load(_f);
        _isl = true;
    };
    XsTexData data = 0;
    vex2i scale() const { return _scale; };
    std::string fileName;
    bool isLoad() const { return _isl; };
    void loadFromMemory(void* _data, int x, int y, int format, int type) {
        glGenTextures(1, &data);
        glBindTexture(GL_TEXTURE_2D, data);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter);
        if (_data) {
            _scale = vex2i(x, y);
            glTexImage2D(GL_TEXTURE_2D, 0, format, x, y, 0, format, type, _data);
            _isl = true;
        }
        glBindTexture(GL_TEXTURE_2D, 0);
    };
    void load(const std::string& _file_name) {
        fileName = _file_name;
        fileName = fileName.substr(fileName.find_last_of("/\\") + 1);
        glGenTextures(1, &data);
        glBindTexture(GL_TEXTURE_2D, data);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter);
        int _widthh, _heightt, _nrChannels;
        auto __data = stbi_load(_file_name.c_str(), &_widthh, &_heightt, &_nrChannels, 0);
        if (__data) {
            _scale = vex2i(_widthh, _heightt);
            glTexImage2D(GL_TEXTURE_2D, 0, (_nrChannels == 4) ? GL_RGBA : GL_RGB, _widthh, _heightt, 0, (_nrChannels == 4) ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, __data);
            _isl = true;
        }
        else {
            std::cout << "Failed to Load \""s + fileName + '"' + " Image.\n";
            Xs.Log << ("Failed to Load \""s + fileName + '"' + " Image.\n").c_str();
        };
        glBindTexture(GL_TEXTURE_2D, 0);
        stbi_image_free(__data);
    };
    void load() {
        glGenTextures(1, &data);
        glBindTexture(GL_TEXTURE_2D, data);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter);
        int _widthh, _heightt, _nrChannels;
        unsigned char* __data = stbi_load(fileName.c_str(), &_widthh, &_heightt, &_nrChannels, 0);
        if (__data) {
            _scale = vex2i(_widthh, _heightt);
            glTexImage2D(GL_TEXTURE_2D, 0, (_nrChannels == 4) ? GL_RGBA : GL_RGB, _widthh, _heightt, 0, (_nrChannels == 4) ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, __data);
            _isl = true;
        }
        else {
            std::cout << "Failed to Load \""s + fileName + '"' + " Image.\n";
            Xs.Log << ("Failed to Load \""s + fileName + '"' + " Image.\n").c_str();
        };
        glBindTexture(GL_TEXTURE_2D, 0);
        stbi_image_free(__data);
    };
    void bind() const {
        glBindTexture(GL_TEXTURE_2D, data);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter);
    }
};