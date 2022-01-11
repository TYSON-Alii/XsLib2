using namespace std;

class XsEngine {
private:
public:
    XsEngine() = default;
    sf::RenderWindow Window;
    XsCamera Cam;
    template <typename T>
    class Mem_t {
    private:
        vector<T*> _data;
        T null_data;
    public:
        inline auto& Data() { return _data; };
        T& New(T* msh = new T()) {
            _data.emplace_back(msh);
            return *_data.back();
        };
        void Del(XsShape& shp) {
            const auto& a = find_if(_data.begin(), _data.end(), [&](auto& i) -> bool { return (&*i == &shp); });
            if (a != _data.end())
                _data.erase(a);
        };
    };
    Mem_t<XsMesh> Meshs;
    Mem_t<XsShape> Shapes;
    Mem_t<XsTexture> Textures;
    Mem_t<XsAnim> Anims;
    inline void operator()() { for (auto& i : Anims.Data()) i->step(); for (auto& i : Shapes.Data()) i->draw(); };
#define __extra_funcs__(type,name)                                                                                      \
    type& New(type* v) {                                                                                                \
    name.Data().emplace_back(v);                                                                                        \
    return *name.Data().back();                                                                                         \
    };                                                                                                                  \
    void Del(type& v) {                                                                                                 \
        const auto& a = find_if(name.Data().begin(), name.Data().end(), [&](auto& i) -> bool { return (&*i == &v); });  \
        if (a != name.Data().end()) name.Data().erase(a);                                                               \
    };
    __extra_funcs__(XsShape, Shapes);
    __extra_funcs__(XsMesh, Meshs);
    __extra_funcs__(XsTexture, Textures);
    __extra_funcs__(XsAnim, Anims);
#undef __extra_funcs__
};