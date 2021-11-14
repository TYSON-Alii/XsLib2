class XsEngine;
class XsEngine {
protected:
    void open_with_notepad(const char* const file_name) { system(std::string(std::string("notepad \"") + file_name + "\"").c_str()); };
    struct {
        enum Selected_Enums { None, Shape};
        Selected_Enums type = None;
        int num = 0;
    } Selected;
    const std::string floor_shader_vs = R"(
#version 400
layout(location = 0) in vec3 aPos;

void main() {
    gl_Position = ftransform();
};)";
    const std::string floor_shader_fs = R"(
#version 400
out vec4 FragColor;

float near = 0.20;
float far = 100.0;
float p = 100.0;
uniform vec3 color;
uniform float cam_y;

float linearizeDepth(float depth) {
    float z = depth * 2.0 - 1.0;
    return (2.0 * near * p) / (p + near - z * (p - near));
};

void main() {
    p = far - (far - abs(cam_y));
    float alpha = linearizeDepth(gl_FragCoord.z) / p;
    FragColor = vec4(color, 1 - alpha);
};)";
    XsShader* floor_shader = nullptr;
    vex2f cam_rot = vex2f(0, 300);
    vex2f cam_vel = 0;
    vex2f last_mouse_pos = 0, plast_mouse_pos = 0;
    bool mouse_press = false;
    vex2f m_sayac = 0;

    vex3f speed = 0;
    vex2f mouse_pos = 0;
    float speed_x = 100.f;

    //const char* solid_types[10]{ "cube", "prism", "sphere", "cylinder", "cone", "ico sphere", "torus", "teapot", "star", "monke" };
    const char* file_formats[2]{ "obj", "xs.model" };

    float fps = 1.f;
    XsChrono fps_tm;
    struct Push_t {
        Push_t() = default;
        Push_t(void (*push_f)(void), const char* name) {
            data = push_f;
            this->name = name;
        };
        void (*data)(void);
        std::string name;
    };
    std::vector<Push_t> pushs;
    vex3f m_fdis = 110.f;
    vex3f m_ldis = 2.f;
    void drawfloor(XsShader& v) {
        glDepthFunc(GL_ALWAYS);
        glDepthMask(GL_FALSE);
        glEnable(GL_LINE_SMOOTH);
        glEnable(GL_POINT_SMOOTH);
        glLoadIdentity();
        v.use();
        v("projection", Camera.projectionMatrix());
        v("view", Camera.viewMatrix());
        v("color", vex3f(0.05f, 0.05f, 0.075f));
        v("cam_y", Camera.pos.y);
        if (3 > fabs(Camera.pos.y))
            glLineWidth(4.1 - fabs(Camera.pos.y));
        else
            glLineWidth(1);
        glTranslatef(ceil(Camera.pos.x / 2) * 2, 0, ceil(Camera.pos.z / 2) * 2);
        glBegin(GL_LINES);
        rep(m_ldis.x * m_fdis.z, 2.f)
            if ((ceil(Camera.pos.z / 2) * 2) + m_fdis.z - i != 0)
                Xs.Line(m_fdis.x, 0, m_fdis.z - i, -m_fdis.x, 0, m_fdis.z - i);
        glEnd();

        glBegin(GL_LINES);
        rep(m_ldis.z * m_fdis.x, 2.f)
            if ((ceil(Camera.pos.x / 2) * 2) + m_fdis.x - i != 0)
                Xs.Line(m_fdis.x - i, 0, m_fdis.z, m_fdis.x - i, 0, -m_fdis.z);
        glEnd();

        glLoadIdentity();
        if (4 > fabs(Camera.pos.y))
            glLineWidth(5.1 - fabs(Camera.pos.y));
        else
            glLineWidth(2);
        v("color", vex3f(34.f, 207.f, 230.f) / 255.f);
        glBegin(GL_LINES);
        Xs.Line(0, 0, m_fdis.z + Camera.pos.z, 0, 0, -m_fdis.z + Camera.pos.z);
        glEnd();
        v("color", vex3f(238.f, 23.f, 23.f) / 255.f);
        glBegin(GL_LINES);
        Xs.Line(m_fdis.x + Camera.pos.x, 0, 0, -m_fdis.x + Camera.pos.x, 0, 0);
        glEnd();
        v("color", Xs.Color.DarkGreen);
        glBegin(GL_LINES);
        Xs.Line(0, m_fdis.y + Camera.pos.y, 0, 0, -m_fdis.y + Camera.pos.y, 0);
        glEnd();

        v.disuse();
        glDepthFunc(GL_LESS);
        glDepthMask(GL_TRUE);
    };
    bool game_mode = true;
    void camera_sett() {
        Camera.viewport = vex2f(Window.getSize().x, Window.getSize().y);
        if (game_mode) {
            if (Xs.KeyPressed(Xs.Mouse.Button.Right)) {
                if (Xs.Event.type == sf::Event::MouseWheelMoved) {
                    speed_x += (float)Xs.Event.mouseWheel.delta * 10;
                    if (speed_x < 20)
                        speed_x = 20;
                }
                if (Xs.KeyPressed(Xs.Key.W) && !Xs.KeyPressed(Xs.Key.Space))
                    speed += Camera.rot * (1.f / speed_x);
                else if (Xs.KeyPressed(Xs.Key.S) && !Xs.KeyPressed(Xs.Key.Space))
                    speed -= Camera.rot * (1.f / speed_x);
                if (mouse_press == false) {
                    last_mouse_pos = mouse_pos;
                    mouse_press = true;
                }
                vex2f f_pos = mouse_pos - last_mouse_pos;
                vex2f sm_pos = cam_rot + f_pos;
                cam_vel = (sm_pos - cam_rot) / 17.5;
                last_mouse_pos += cam_vel;
            }
            if (!Xs.KeyPressed(Xs.Key.S) && !Xs.KeyPressed(Xs.Key.W))
                speed *= 0.95;
            if (Xs.KeyPressed(Xs.Key.Space))
                speed *= 0.75f;
            Camera.pos += speed;
            cam_vel *= 0.88;
            cam_rot += cam_vel;
        }
        XsFPSCamera(Camera, cam_rot - vex2f(0, 300), 0.3);
    };
public:
    XsCamera Camera;
    const char* WindowName = nullptr;
    sf::RenderWindow Window;
    std::vector<Push_t>& __Pushs__() { return pushs; };
    void operator<<(Push_t v) { pushs.push_back(v); };
    void __deletePush__(const char* name) {
        size_t index = std::string::npos;
        rep(pushs.size(),1) {
            if (pushs[i].name == name) {
                index = i;
                break;
            };
        };
        if (index != std::string::npos) pushs.erase(pushs.begin() + index);
    };
    XsEngine() {
        Camera.fov = 45.0f;
        Camera.far = 100;
        Camera.viewport = vex2ui(Xs.Sett.WindowSize.x, Xs.Sett.WindowSize.y);
        Camera.near = 0.2;
        Camera.pos = vex3f(-20, 20, 0);

        floor_shader = new XsShader(floor_shader_vs, floor_shader_fs);
    };
    void __drawenv__() {
        camera_sett();
        drawfloor(*floor_shader);
    };
    void operator<<(XsShape& v);
};