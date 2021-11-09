#define _XS_VEX2_
#include <string>
template <typename T> struct vex2;
template <typename T> struct vex3;
template <typename T> struct vex4;

template <typename T>
struct vex2 {
    T x, y;
    operator std::string() { return (std::to_string(x) + ' ' + std::to_string(y)); };
    operator char* () { return _strdup((std::to_string(x) + ' ' + std::to_string(y)).c_str()); };
#ifdef _XS_STRINX_
    operator strinx() { return strinx(x) + ' ' + strinx(y); };
#endif
    T* arr() {
        T tarr[2]{ x, y };
        return tarr;
    };
    const char* str(const char* sep = " ", const char* end = "") { return ((std::to_string(x) + sep + std::to_string(y) + end).c_str()); };
    vex2() = default;
    vex2(const vex2<T>&) = default;
    template <typename _T> vex2(_T v) { x = y = T(v); };
    template <typename _T> vex2(vex2<_T> v) { x = T(v.x); y = T(v.y); };
    template <typename _T> vex2(vex3<_T> v) { x = T(v.x); y = T(v.y); };
    template <typename _T> vex2(vex4<_T> v) { x = T(v.x); y = T(v.y); };
    template <typename _T1, typename _T2> vex2(_T1 v1, _T2 v2) { x = T(v1); y = T(v2); };

    template <typename _T>  vex2<T>& operator=(_T v) { x = y = T(v);             return *this; };
    template <typename _T>  vex2<T>& operator=(vex2<_T> v) { x = T(v.x); y = T(v.y);   return *this; };

    template <> vex2(std::string v);
    template <> vex2(std::string v1, std::string v2);
    template <> vex2<T>& operator=(std::string v);

    bool isEmpty() { return (x && y) ? false : true; };
    operator bool() { return isEmpty(); };

    vex2<T>& operator~() { x = T(); y = T(); return *this; };
    bool operator!() { return !isEmpty(); };
    vex2<T>& swap() { *this = vex2<T>(y, x); return *this; };
    template <typename _T>
    vex2<T>& operator,(vex2<_T>& v) {
        const vex2<T> c = *this;
        *this = v;
        v = c;
        return *this;
    };

    vex2<T> operator()() { return *this; };
    vex2<T> copy() { return *this; };

    T& operator[](int v) { return fmod(v, 2) == 0 ? x : y; };

    template <typename _T>  vex2<T> operator%(_T v) { return vex2<T>(std::rand() % int(v), std::rand() % int(v)); };
    template <typename _T>  vex2<T> operator%(vex2<_T> v) { return vex2<T>(std::rand() % int(v.x), std::rand() % int(v.y)); };

    template <typename _T>  vex2<T>& operator%=(_T v) { x = std::rand() % int(v);     y = std::rand() % int(v);   return *this; };
    template <typename _T>  vex2<T>& operator%=(vex2<_T> v) { x = std::rand() % int(v.x);   y = std::rand() % int(v.y); return *this; };

    template <typename _T>  vex2<T> operator|(_T v) { return std::rand() % 2 == 0 ? vex2<T>(v) : *this; };
    template <typename _T>  vex2<T> operator|(vex2<_T> v) { return std::rand() % 2 == 0 ? vex2<T>(v) : *this; };
    template <typename _T>  vex2<T>& operator|=(vex2<_T> v) { *this = std::rand() % 2 == 0 ? vex2<T>(v) : *this; };

    template <typename _T>  vex2<T> operator|(vex3<_T> v) { return std::rand() % 2 == 0 ? vex2<T>(v) : *this; };
    template <typename _T>  vex2<T>& operator|=(vex3<_T> v) { *this = std::rand() % 2 == 0 ? vex2<T>(v) : *this; };

    template <typename _T>  vex2<T> operator|(vex4<_T> v) { return std::rand() % 2 == 0 ? vex2<T>(v) : *this; };
    template <typename _T>  vex2<T>& operator|=(vex4<_T> v) { *this = std::rand() % 2 == 0 ? vex2<T>(v) : *this; };

    vex2<T>& operator++() { x++; y++; return *this; };
    vex2<T>& operator--() { x--; y--; return *this; };

    template <typename _T>  vex2<T>& operator+=(_T v) { x += T(v);    y += T(v);      return *this; };
    template <typename _T>  vex2<T>& operator+=(vex2<_T> v) { x += T(v.x);  y += T(v.y);    return *this; };

    template <typename _T>  vex2<T>& operator-=(_T v) { x -= T(v);    y -= T(v);      return *this; };
    template <typename _T>  vex2<T>& operator-=(vex2<_T> v) { x -= T(v.x);  y -= T(v.y);    return *this; };

    template <typename _T>  vex2<T>& operator*=(_T v) { x *= T(v);    y *= T(v);      return *this; };
    template <typename _T>  vex2<T>& operator*=(vex2<_T> v) { x *= T(v.x);  y *= T(v.y);    return *this; };

    template <typename _T>  vex2<T>& operator/=(_T v) { x /= T(v);    y /= T(v);      return *this; };
    template <typename _T>  vex2<T>& operator/=(vex2<_T> v) { x /= T(v.x);  y /= T(v.y);    return *this; };

    template <typename _T>  vex2<T> operator+(_T v) { return vex2<T>(this->x + T(v), this->y + T(v)); };
    template <typename _T>  vex2<T> operator+(vex2<_T> v) { return vex2<T>(this->x + T(v.x), this->y + T(v.y)); };

    template <typename _T>  vex2<T> operator-(_T v) { return vex2<T>(this->x - T(v), this->y - T(v)); };
    template <typename _T>  vex2<T> operator-(vex2<_T> v) { return vex2<T>(this->x - T(v.x), this->y - T(v.y)); };

    template <typename _T>  vex2<T> operator*(_T v) { return vex2<T>(this->x * T(v), this->y * T(v)); };
    template <typename _T>  vex2<T> operator*(vex2<_T> v) { return vex2<T>(this->x * T(v.x), this->y * T(v.y)); };

    template <typename _T>  vex2<T> operator/(_T v) { return vex2<T>(this->x / T(v), this->y / T(v)); };
    template <typename _T>  vex2<T> operator/(vex2<_T> v) { return vex2<T>(this->x / T(v.x), this->y / T(v.y)); };

    template <typename _T>  vex2<T> operator^(_T v) { return vex2<T>(std::pow(this->x, T(v)), std::pow(this->y / T(v))); };
    template <typename _T>  vex2<T> operator^(vex2<_T> v) { return vex2<T>(std::pow(this->x / T(v.x)), std::pow(this->y / T(v.y))); };

    template <typename _T>  bool operator==(_T v) { return this->x == T(v) && this->y == T(v); };
    template <typename _T>  bool operator==(vex2<_T> v) { return this->x == T(v.x) && this->y == T(v.y); };

    template <typename _T>  bool operator!=(_T v) { return this->x != T(v) && this->y != T(v); };
    template <typename _T>  bool operator!=(vex2<_T> v) { return this->x != T(v.x) && this->y != T(v.y); };

    template <typename _T>  bool operator>(_T v) { return this->x > T(v) && this->y > T(v); };
    template <typename _T>  bool operator>(vex2<_T> v) { return this->x > T(v.x) && this->y > T(v.y); };

    template <typename _T>  bool operator<(_T v) { return this->x < T(v) && this->y < T(v); };
    template <typename _T>  bool operator<(vex2<_T> v) { return this->x < T(v.x) && this->y < T(v.y); };

    template <typename _T>  bool operator>=(_T v) { return this->x >= T(v) && this->y >= T(v); };
    template <typename _T>  bool operator>=(vex2<_T> v) { return this->x >= T(v.x) && this->y >= T(v.y); };

    template <typename _T>  bool operator<=(_T v) { return this->x <= T(v) && this->y <= T(v); };
    template <typename _T>  bool operator<=(vex2<_T> v) { return this->x <= T(v.x) && this->y <= T(v.y); };

    //template <typename _T> vex2<T>& operator<<(_T& v) { *this = *reinterpret_cast<T*>(v); return *this; };

    vex2<T>& normalize() { *this /= x > y ? x : y; return *this; };
    vex2<T> ceil() { return vex2<T>(std::ceil(x), std::ceil(y)); };
    vex2<T> floor() { return vex2<T>(std::floor(x), std::floor(y)); };
    vex2<T> abs() { return vex2<T>(std::abs(x), std::abs(y)); };
    vex2<T> sqrt() { return vex2<T>(std::sqrt(x), std::sqrt(y)); };
    vex2<T> cbrt() { return vex2<T>(std::cbrt(x), std::cbrt(y)); };
    vex2<T> pow(int v) { return vex2<T>(std::pow(x, v), std::pow(y, v)); };
    vex2<T> round() { return vex2<T>(std::round(x), std::round(y)); };
    vex2<T> trunc() { return vex2<T>(std::trunc(x), std::trunc(y)); };
    vex2<T> exp() { return vex2<T>(std::exp(x), std::exp(y)); };
    vex2<T> percent(T v) { return vex2<T>(x / T(100) * T(v), y / T(100) * T(v)); };
    vex2<T> percent(T v1, T v2) { return vex2<T>(x / T(100) * T(v1), y / T(100) * T(v2)); };

    template <typename _T> vex2<T>& operator=(vex3<_T> v) { x = T(v.x);  y = T(v.y);    return *this; };
    template <typename _T> vex2<T>& operator+=(vex3<_T> v) { x += T(v.x);  y += T(v.y);    return *this; };
    template <typename _T> vex2<T>& operator-=(vex3<_T> v) { x -= T(v.x);  y -= T(v.y);    return *this; };
    template <typename _T> vex2<T>& operator*=(vex3<_T> v) { x *= T(v.x);  y *= T(v.y);    return *this; };
    template <typename _T> vex2<T>& operator/=(vex3<_T> v) { x /= T(v.x);  y /= T(v.y);    return *this; };
    template <typename _T> vex2<T> operator+(vex3<_T> v) { return vex2<T>(x + T(v.x), y + T(v.y)); };
    template <typename _T> vex2<T> operator-(vex3<_T> v) { return vex2<T>(x - T(v.x), y - T(v.y)); };
    template <typename _T> vex2<T> operator*(vex3<_T> v) { return vex2<T>(x * T(v.x), y * T(v.y)); };
    template <typename _T> vex2<T> operator/(vex3<_T> v) { return vex2<T>(x / T(v.x), y / T(v.y)); };
    template <typename _T>  bool operator==(vex3<_T> v) { return this->x == T(v.x) && this->y == T(v.y); };
    template <typename _T>  bool operator!=(vex3<_T> v) { return this->x != T(v.x) && this->y != T(v.y); };
    template <typename _T>  bool operator>(vex3<_T> v) { return this->x > T(v.x) && this->y > T(v.y); };
    template <typename _T>  bool operator<(vex3<_T> v) { return this->x < T(v.x) && this->y < T(v.y); };
    template <typename _T>  bool operator>=(vex3<_T> v) { return this->x >= T(v.x) && this->y >= T(v.y); };
    template <typename _T>  bool operator<=(vex3<_T> v) { return this->x <= T(v.x) && this->y <= T(v.y); };

    template <typename _T> vex2<T>& operator=(vex4<_T> v) { x = T(v.x);  y = T(v.y);    return *this; };
    template <typename _T> vex2<T>& operator+=(vex4<_T> v) { x += T(v.x);  y += T(v.y);    return *this; };
    template <typename _T> vex2<T>& operator-=(vex4<_T> v) { x -= T(v.x);  y -= T(v.y);    return *this; };
    template <typename _T> vex2<T>& operator*=(vex4<_T> v) { x *= T(v.x);  y *= T(v.y);    return *this; };
    template <typename _T> vex2<T>& operator/=(vex4<_T> v) { x /= T(v.x);  y /= T(v.y);    return *this; };
    template <typename _T> vex2<T>& operator+(vex4<_T> v) { return vex2<T>(x + T(v.x), y + T(v.y)); };
    template <typename _T> vex2<T>& operator-(vex4<_T> v) { return vex2<T>(x - T(v.x), y - T(v.y)); };
    template <typename _T> vex2<T>& operator*(vex4<_T> v) { return vex2<T>(x * T(v.x), y * T(v.y)); };
    template <typename _T> vex2<T>& operator/(vex4<_T> v) { return vex2<T>(x / T(v.x), y / T(v.y)); };
    template <typename _T>  bool operator==(vex4<_T> v) { return this->x == T(v.x) && this->y == T(v.y); };
    template <typename _T>  bool operator!=(vex4<_T> v) { return this->x != T(v.x) && this->y != T(v.y); };
    template <typename _T>  bool operator>(vex4<_T> v) { return this->x > T(v.x) && this->y > T(v.y); };
    template <typename _T>  bool operator<(vex4<_T> v) { return this->x < T(v.x) && this->y < T(v.y); };
    template <typename _T>  bool operator>=(vex4<_T> v) { return this->x >= T(v.x) && this->y >= T(v.y); };
    template <typename _T>  bool operator<=(vex4<_T> v) { return this->x <= T(v.x) && this->y <= T(v.y); };

    friend std::ostream& operator<<(std::ostream& os, const vex2<T>& v) { os << v.x << ' ' << v.y; return os; };
};

template <typename T>
struct vex3 {
    T x, y, z;
    operator std::string() { return (std::to_string(x) + ' ' + std::to_string(y) + ' ' + std::to_string(z)); };
    operator char* () { return _strdup((std::to_string(x) + ' ' + std::to_string(y) + ' ' + std::to_string(z)).c_str()); };
#ifdef _XS_STRINX_
    operator strinx() { return strinx(x) + ' ' + strinx(y) + ' ' + strinx(z); };
#endif
    T* arr() {
        T tarr[3]{ x, y, z };
        return tarr;
    };
    const char* str(const char* sep = " ", const char* end = "") { return ((std::to_string(x) + sep + std::to_string(y) + sep + std::to_string(z) + end).c_str()); };
    vex3() = default;
    vex3(const vex3<T>&) = default;
    template <typename _T> vex3(_T v) { x = y = z = T(v); };
    template <typename _T> vex3(vex2<_T> v) { x = T(v.x); y = T(v.y); };
    template <typename _T> vex3(vex3<_T> v) { x = T(v.x); y = T(v.y); z = T(v.z); };
    template <typename _T> vex3(vex4<_T> v) { x = T(v.x); y = T(v.y); z = T(v.z); };
    template <typename _T1, typename _T2> vex3(_T1 v1, _T2 v2) { x = T(v1); y = T(v2); };
    template <typename _T1, typename _T2, typename _T3> vex3(_T1 v1, _T2 v2, _T3 v3) { x = T(v1); y = T(v2); z = T(v3); };

    template <typename _T1, typename _T2> vex3(vex2<_T1> v1_2, _T2 v3) { x = T(v1_2.x); y = T(v1_2.y); z = T(v3); };
    template <typename _T1, typename _T2> vex3(_T1 v1, vex2<_T2> v2_3) { x = T(v1); y = T(v2_3.x); z = T(v2_3.y); };

    template <typename _T>  vex3<T>& operator=(_T v) { x = y = z = T(v); return *this; };
    template <typename _T>  vex3<T>& operator=(vex3<_T> v) { x = T(v.x); y = T(v.y); z = T(v.z); return *this; };

    template <> vex3(std::string v);
    template <> vex3(std::string v1, std::string v2);
    template <> vex3(std::string v1, std::string v2, std::string v3);
    template <> vex3<T>& operator=(std::string v);

    bool isEmpty() { return (x && y && z) ? false : true; };
    operator bool() { return isEmpty(); };

    vex3<T>& operator~() { x = T(); y = T(); z = T(); return *this; };
    bool operator!() { return !isEmpty(); };
    vex3<T>& swap() { *this = vex3<T>(z, y, x); return *this; };

    template <typename _T>
    vex3<T>& operator,(vex3<_T>& v) {
        const vex3<T> c = *this;
        *this = v;
        v = c;
        return *this;
    };

    vex3<T> operator()() { return *this; };
    vex3<T> copy() { return *this; };

    T& operator[](int v) { return fmod(v, 3) == 0 ? x : fmod(v, 3) == 1 ? y : z; };

    template <typename _T>  vex3<T> operator%(_T v) { return vex3<T>(std::rand() % int(v), std::rand() % int(v), std::rand() % int(v)); };
    template <typename _T>  vex3<T> operator%(vex3<_T> v) { return vex3<T>(std::rand() % int(v.x), std::rand() % int(v.y), std::rand() % int(v.z)); };

    template <typename _T>  vex3<T>& operator%=(_T v) { x = std::rand() % int(v);     y = std::rand() % int(v);   z = std::rand() % int(v);   return *this; };
    template <typename _T>  vex3<T>& operator%=(vex3<_T> v) { x = std::rand() % int(v.x);   y = std::rand() % int(v.y); z = std::rand() % int(v.z); return *this; };

    template <typename _T>  vex3<T> operator|(_T v) { return std::rand() % 2 == 0 ? vex3<T>(v) : *this; };
    template <typename _T>  vex3<T> operator|(vex3<_T> v) { return std::rand() % 2 == 0 ? vex3<T>(v) : *this; };
    template <typename _T>  vex3<T>& operator|=(vex3<_T> v) { *this = std::rand() % 2 == 0 ? vex3<T>(v) : *this; };

    template <typename _T>  vex3<T> operator|(vex2<_T> v) { return std::rand() % 2 == 0 ? vex3<T>(v) : *this; };
    template <typename _T>  vex3<T>& operator|=(vex2<_T> v) { *this = std::rand() % 2 == 0 ? vex3<T>(v) : *this; };

    template <typename _T>  vex3<T> operator|(vex4<_T> v) { return std::rand() % 2 == 0 ? vex3<T>(v) : *this; };
    template <typename _T>  vex3<T>& operator|=(vex4<_T> v) { *this = std::rand() % 2 == 0 ? vex3<T>(v) : *this; };

    vex3<T>& operator++() { x++; y++; z++; return *this; };
    vex3<T>& operator--() { x--; y--; z--; return *this; };

    template <typename _T>  vex3<T>& operator+=(_T v) { x += T(v);    y += T(v);      z += T(v);      return *this; };
    template <typename _T>  vex3<T>& operator+=(vex3<_T> v) { x += T(v.x);  y += T(v.y);    z += T(v.z);    return *this; };

    template <typename _T>  vex3<T>& operator-=(_T v) { x -= T(v);    y -= T(v);      z -= T(v);      return *this; };
    template <typename _T>  vex3<T>& operator-=(vex3<_T> v) { x -= T(v.x);  y -= T(v.y);    z -= T(v.z);    return *this; };

    template <typename _T>  vex3<T>& operator*=(_T v) { x *= T(v);    y *= T(v);      z *= T(v);      return *this; };
    template <typename _T>  vex3<T>& operator*=(vex3<_T> v) { x *= T(v.x);  y *= T(v.y);    z *= T(v.z);    return *this; };

    template <typename _T>  vex3<T>& operator/=(_T v) { x /= T(v);    y /= T(v);      z /= T(v);      return *this; };
    template <typename _T>  vex3<T>& operator/=(vex3<_T> v) { x /= T(v.x);  y /= T(v.y);    z /= T(v.z);    return *this; };

    template <typename _T>  vex3<T> operator+(_T v) { return vex3<T>(this->x + T(v), this->y + T(v), this->z + T(v)); };
    template <typename _T>  vex3<T> operator+(vex3<_T> v) { return vex3<T>(this->x + T(v.x), this->y + T(v.y), this->z + T(v.z)); };

    template <typename _T>  vex3<T> operator-(_T v) { return vex3<T>(this->x - T(v), this->y - T(v), this->z - T(v)); };
    template <typename _T>  vex3<T> operator-(vex3<_T> v) { return vex3<T>(this->x - T(v.x), this->y - T(v.y), this->z - T(v.z)); };

    template <typename _T>  vex3<T> operator*(_T v) { return vex3<T>(this->x * T(v), this->y * T(v), this->z * T(v)); };
    template <typename _T>  vex3<T> operator*(vex3<_T> v) { return vex3<T>(this->x * T(v.x), this->y * T(v.y), this->z * T(v.z)); };

    template <typename _T>  vex3<T> operator/(_T v) { return vex3<T>(this->x / T(v), this->y / T(v), this->z / T(v)); };
    template <typename _T>  vex3<T> operator/(vex3<_T> v) { return vex3<T>(this->x / T(v.x), this->y / T(v.y), this->z / T(v.z)); };

    template <typename _T>  bool operator==(_T v) { return this->x == T(v) && this->y == T(v) && this->z == T(v); };
    template <typename _T>  bool operator==(vex3<_T> v) { return this->x == T(v.x) && this->y == T(v.y) && this->z == T(v.z); };

    template <typename _T>  bool operator!=(_T v) { return this->x != T(v) && this->y != T(v) && this->z != T(v); };
    template <typename _T>  bool operator!=(vex3<_T> v) { return this->x != T(v.x) && this->y != T(v.y) && this->z != T(v.z); };

    template <typename _T>  bool operator>(_T v) { return this->x > T(v) && this->y > T(v) && this->z > T(v); };
    template <typename _T>  bool operator>(vex3<_T> v) { return this->x > T(v.x) && this->y > T(v.y) && this->z > T(v.z); };

    template <typename _T>  bool operator<(_T v) { return this->x < T(v) && this->y < T(v) && this->z < T(v); };
    template <typename _T>  bool operator<(vex3<_T> v) { return this->x < T(v.x) && this->y < T(v.y) && this->z < T(v.z); };

    template <typename _T>  bool operator>=(_T v) { return this->x >= T(v) && this->y >= T(v) && this->z >= T(v); };
    template <typename _T>  bool operator>=(vex3<_T> v) { return this->x >= T(v.x) && this->y >= T(v.y) && this->z >= T(v.z); };

    template <typename _T>  bool operator<=(_T v) { return this->x <= T(v) && this->y <= T(v) && this->z <= T(v); };
    template <typename _T>  bool operator<=(vex3<_T> v) { return this->x <= T(v.x) && this->y <= T(v.y) && this->z <= T(v.z); };

    vex3<T>& normalize() { *this /= x > y ? x : y > z ? y : z; return *this; };
    vex3<T> ceil() { return vex3<T>(std::ceil(x), std::ceil(y), std::ceil(z)); };
    vex3<T> floor() { return vex3<T>(std::floor(x), std::floor(y), std::floor(z)); };
    vex3<T> abs() { return vex3<T>(std::abs(x), std::abs(y), std::abs(z)); };
    vex3<T> sqrt() { return vex3<T>(std::sqrt(x), std::sqrt(y), std::sqrt(z)); };
    vex3<T> cbrt() { return vex3<T>(std::cbrt(x), std::cbrt(y), std::cbrt(z)); };
    vex3<T> pow(int v) { return vex3<T>(std::pow(x, v), std::pow(y, v), std::pow(z, v)); };
    vex3<T> round() { return vex3<T>(std::round(x), std::round(y), std::round(z)); };
    vex3<T> trunc() { return vex3<T>(std::trunc(x), std::trunc(y), std::trunc(z)); };
    vex3<T> exp() { return vex3<T>(std::exp(x), std::exp(y), std::exp(z)); };
    vex3<T> percent(T v) { return vex2<T>(x / T(100) * T(v), y / T(100) * T(v), z / T(100) * T(v)); };
    vex3<T> percent(T v1, T v2, T v3) { return vex2<T>(x / T(100) * T(v1), y / T(100) * T(v2), z / T(100) * T(v3)); };

    template <typename _T> vex3<T>& operator=(vex2<_T> v) { x = T(v.x);  y = T(v.y);    return *this; };
    template <typename _T> vex3<T>& operator+=(vex2<_T> v) { x += T(v.x);  y += T(v.y);    return *this; };
    template <typename _T> vex3<T>& operator-=(vex2<_T> v) { x -= T(v.x);  y -= T(v.y);    return *this; };
    template <typename _T> vex3<T>& operator*=(vex2<_T> v) { x *= T(v.x);  y *= T(v.y);    return *this; };
    template <typename _T> vex3<T>& operator/=(vex2<_T> v) { x /= T(v.x);  y /= T(v.y);    return *this; };
    template <typename _T> vex3<T> operator+(vex2<_T> v) { return vex3<T>(x + T(v.x), y + T(v.y)); };
    template <typename _T> vex3<T> operator-(vex2<_T> v) { return vex3<T>(x - T(v.x), y - T(v.y)); };
    template <typename _T> vex3<T> operator*(vex2<_T> v) { return vex3<T>(x * T(v.x), y * T(v.y)); };
    template <typename _T> vex3<T> operator/(vex2<_T> v) { return vex3<T>(x / T(v.x), y / T(v.y)); };
    template <typename _T>  bool operator==(vex2<_T> v) { return this->x == T(v.x) && this->y == T(v.y); };
    template <typename _T>  bool operator!=(vex2<_T> v) { return this->x != T(v.x) && this->y != T(v.y); };
    template <typename _T>  bool operator>(vex2<_T> v) { return this->x > T(v.x) && this->y > T(v.y); };
    template <typename _T>  bool operator<(vex2<_T> v) { return this->x < T(v.x) && this->y < T(v.y); };
    template <typename _T>  bool operator>=(vex2<_T> v) { return this->x >= T(v.x) && this->y >= T(v.y); };
    template <typename _T>  bool operator<=(vex2<_T> v) { return this->x <= T(v.x) && this->y <= T(v.y); };

    template <typename _T> vex3<T>& operator=(vex4<_T> v) { x = T(v.x);  y = T(v.y);  z = T(v.z);  return *this; };
    template <typename _T> vex3<T>& operator+=(vex4<_T> v) { x += T(v.x);  y += T(v.y);  z += T(v.z);  return *this; };
    template <typename _T> vex3<T>& operator-=(vex4<_T> v) { x -= T(v.x);  y -= T(v.y);  z -= T(v.z);  return *this; };
    template <typename _T> vex3<T>& operator*=(vex4<_T> v) { x *= T(v.x);  y *= T(v.y);  z *= T(v.z);  return *this; };
    template <typename _T> vex3<T>& operator/=(vex4<_T> v) { x /= T(v.x);  y /= T(v.y);  z /= T(v.z);  return *this; };
    template <typename _T> vex3<T>& operator+(vex4<_T> v) { return vex3<T>(x + T(v.x), y + T(v.y), z + T(v.z)); };
    template <typename _T> vex3<T>& operator-(vex4<_T> v) { return vex3<T>(x - T(v.x), y - T(v.y), z - T(v.z)); };
    template <typename _T> vex3<T>& operator*(vex4<_T> v) { return vex3<T>(x * T(v.x), y * T(v.y), z * T(v.z)); };
    template <typename _T> vex3<T>& operator/(vex4<_T> v) { return vex3<T>(x / T(v.x), y / T(v.y), z / T(v.z)); };
    template <typename _T>  bool operator==(vex4<_T> v) { return this->x == T(v.x) && this->y == T(v.y) && this->z == T(v.z); };
    template <typename _T>  bool operator!=(vex4<_T> v) { return this->x != T(v.x) && this->y != T(v.y) && this->z != T(v.z); };
    template <typename _T>  bool operator>(vex4<_T> v) { return this->x > T(v.x) && this->y > T(v.y) && this->z > T(v.z); };
    template <typename _T>  bool operator<(vex4<_T> v) { return this->x < T(v.x) && this->y < T(v.y) && this->z < T(v.z); };
    template <typename _T>  bool operator>=(vex4<_T> v) { return this->x >= T(v.x) && this->y >= T(v.y) && this->z >= T(v.z); };
    template <typename _T>  bool operator<=(vex4<_T> v) { return this->x <= T(v.x) && this->y <= T(v.y) && this->z <= T(v.z); };

    friend std::ostream& operator<<(std::ostream& os, const vex3<T>& v) { os << v.x << ' ' << v.y << ' ' << v.z; return os; };
};

template <typename T>
struct vex4 {
    T x, y, z, w;
    operator std::string() { return (std::to_string(x) + ' ' + std::to_string(y) + ' ' + std::to_string(z) + ' ' + std::to_string(w)); };
    operator char* () { return _strdup((std::to_string(x) + ' ' + std::to_string(y) + ' ' + std::to_string(z) + ' ' + std::to_string(w)).c_str()); };
#ifdef _XS_STRINX_
    operator strinx() { return strinx(x) + ' ' + strinx(y) + ' ' + strinx(z) + ' ' + strinx(w); };
#endif
    T* arr() {
        T tarr[4]{ x, y, z, w };
        return tarr;
    };
    const char* str(const char* sep = " ", const char* end = "") { return ((std::to_string(x) + sep + std::to_string(y) + sep + std::to_string(z) + sep + std::to_string(w) + end).c_str()); };
    vex4() = default;
    vex4(const vex4<T>&) = default;
    template <typename _T> vex4(_T v) { x = y = z = w = T(v); };
    template <typename _T> vex4(vex2<_T> v) { x = T(v.x); y = T(v.y); };
    template <typename _T> vex4(vex3<_T> v) { x = T(v.x); y = T(v.y); z = T(v.z); };
    template <typename _T> vex4(vex4<_T> v) { x = T(v.x); y = T(v.y); z = T(v.z); w = T(v.w); };
    template <typename _T1, typename _T2> vex4(_T1 v1, _T2 v2) { x = T(v1); y = T(v2); };
    template <typename _T1, typename _T2, typename _T3> vex4(_T1 v1, _T2 v2, _T3 v3) { x = T(v1); y = T(v2); z = T(v3); };
    template <typename _T1, typename _T2, typename _T3, typename _T4> vex4(_T1 v1, _T2 v2, _T3 v3, _T4 v4) { x = T(v1); y = T(v2); z = T(v3); w = T(v4); };

    template <typename _T1, typename _T2> vex4(_T1 v1, vex3<_T2> v2_3_4) { x = T(v1); y = T(v2_3_4.x); z = T(v2_3_4.y); w = T(v2_3_4.z); };
    template <typename _T1, typename _T2> vex4(vex3<_T1> v1_2_3, _T2 v4) { x = T(v1_2_3.x); y = T(v1_2_3.y); z = T(v1_2_3.z); w = T(v4); };

    template <typename _T1, typename _T2> vex4(vex2<_T1> v1_2, _T2 v3) { x = T(v1_2.x); y = T(v1_2.y); z = T(v3); };
    template <typename _T1, typename _T2> vex4(_T1 v1, vex2<_T2> v2_3) { x = T(v1); y = T(v2_3.x); z = T(v2_3.y); };
    template <typename _T1, typename _T2> vex4(vex2<_T1> v1_2, vex2<_T2> v3_4) { x = T(v1_2.x); y = T(v1_2.y); z = T(v3_4.x); w = T(v3_4.y); };
    template <typename _T1, typename _T2, typename _T3> vex4(vex2<_T1> v1_2, _T2 v3, _T3 v4) { x = T(v1_2.x); y = T(v1_2.y); z = T(v3); w = T(v4); };
    template <typename _T1, typename _T2, typename _T3> vex4(_T1 v1, vex2<_T2> v2_3, _T3 v4) { x = T(v1); y = T(v2_3.x); z = T(v2_3.y); w = T(v4); };
    template <typename _T1, typename _T2, typename _T3> vex4(_T1 v1, _T2 v2, vex2<_T3> v3_4) { x = T(v1); y = T(v2); z = T(v3_4.x); w = T(v3_4.y); };

    template <typename _T>  vex4<T>& operator=(_T v) { x = y = z = T(v); return *this; };
    template <typename _T>  vex4<T>& operator=(vex4<_T> v) { x = T(v.x); y = T(v.y); z = T(v.z); w = T(v.w); return *this; };

    template <> vex4(std::string v);
    template <> vex4(std::string v1, std::string v2);
    template <> vex4(std::string v1, std::string v2, std::string v3);
    template <> vex4(std::string v1, std::string v2, std::string v3, std::string v4);
    template <> vex4<T>& operator=(std::string v);

    bool isEmpty() { return (x && y && z && w) ? false : true; };
    operator bool() { return isEmpty(); };

    vex4<T>& operator~() { x = T(); y = T(); z = T(); w = T(); return *this; };
    bool operator!() { return !isEmpty(); };
    vex4<T>& swap() { *this = vex4<T>(w, z, y, x); return *this; };

    template <typename _T>
    vex4<T>& operator,(vex4<_T>& v) {
        const vex4<T> c = *this;
        *this = v;
        v = c;
        return *this;
    };

    vex4<T> operator()() { return *this; };
    vex4<T> copy() { return *this; };

    T& operator[](int v) { return fmod(v, 4) == 0 ? x : fmod(v, 4) == 1 ? y : fmod(v, 4) == 2 ? z : w; };

    template <typename _T>  vex4<T> operator%(_T v) { return vex4<T>(std::rand() % int(v), std::rand() % int(v), std::rand() % int(v), std::rand() % int(v)); };
    template <typename _T>  vex4<T> operator%(vex4<_T> v) { return vex4<T>(std::rand() % int(v.x), std::rand() % int(v.y), std::rand() % int(v.z), std::rand() % int(v.w)); };

    template <typename _T>  vex4<T>& operator%=(_T v) { x = std::rand() % int(v);     y = std::rand() % int(v);   z = std::rand() % int(v);   w = std::rand() % int(v);  return *this; };
    template <typename _T>  vex4<T>& operator%=(vex4<_T> v) { x = std::rand() % int(v.x);   y = std::rand() % int(v.y); z = std::rand() % int(v.z); w = std::rand() % int(v.w); return *this; };

    template <typename _T>  vex4<T> operator|(_T v) { return std::rand() % 2 == 0 ? vex4<T>(v) : *this; };
    template <typename _T>  vex4<T> operator|(vex4<_T> v) { return std::rand() % 2 == 0 ? vex4<T>(v) : *this; };
    template <typename _T>  vex4<T>& operator|=(vex4<_T> v) { *this = std::rand() % 2 == 0 ? vex4<T>(v) : *this; };

    template <typename _T>  vex4<T> operator|(vex3<_T> v) { return std::rand() % 2 == 0 ? vex4<T>(v) : *this; };
    template <typename _T>  vex4<T>& operator|=(vex3<_T> v) { *this = std::rand() % 2 == 0 ? vex4<T>(v) : *this; };

    template <typename _T>  vex4<T> operator|(vex2<_T> v) { return std::rand() % 2 == 0 ? vex4<T>(v) : *this; };
    template <typename _T>  vex4<T>& operator|=(vex2<_T> v) { *this = std::rand() % 2 == 0 ? vex4<T>(v) : *this; };

    vex4<T>& operator++() { x++; y++; z++; w++; return *this; };
    vex4<T>& operator--() { x--; y--; z--; w--; return *this; };

    template <typename _T>  vex4<T>& operator+=(_T v) { x += T(v);    y += T(v);      z += T(v);    w += T(v);    return *this; };
    template <typename _T>  vex4<T>& operator+=(vex4<_T> v) { x += T(v.x);  y += T(v.y);    z += T(v.z);  w += T(v.w);  return *this; };

    template <typename _T>  vex4<T>& operator-=(_T v) { x -= T(v);    y -= T(v);      z -= T(v);   w -= T(v);     return *this; };
    template <typename _T>  vex4<T>& operator-=(vex4<_T> v) { x -= T(v.x);  y -= T(v.y);    z -= T(v.z); w -= T(v.w);   return *this; };

    template <typename _T>  vex4<T>& operator*=(_T v) { x *= T(v);    y *= T(v);      z *= T(v);   w *= T(v);     return *this; };
    template <typename _T>  vex4<T>& operator*=(vex4<_T> v) { x *= T(v.x);  y *= T(v.y);    z *= T(v.z); w *= T(v.w);   return *this; };

    template <typename _T>  vex4<T>& operator/=(_T v) { x /= T(v);    y /= T(v);      z /= T(v);   w /= T(v);     return *this; };
    template <typename _T>  vex4<T>& operator/=(vex4<_T> v) { x /= T(v.x);  y /= T(v.y);    z /= T(v.z); w /= T(v.w);   return *this; };

    template <typename _T>  vex4<T> operator+(_T v) { return vex4<T>(this->x + T(v), this->y + T(v), this->z + T(v), this->w + T(v)); };
    template <typename _T>  vex4<T> operator+(vex4<_T> v) { return vex4<T>(this->x + T(v.x), this->y + T(v.y), this->z + T(v.z), this->w + T(v.w)); };

    template <typename _T>  vex4<T> operator-(_T v) { return vex4<T>(this->x - T(v), this->y - T(v), this->z - T(v), this->w - T(v)); };
    template <typename _T>  vex4<T> operator-(vex4<_T> v) { return vex4<T>(this->x - T(v.x), this->y - T(v.y), this->z - T(v.z), this->w - T(v.w)); };

    template <typename _T>  vex4<T> operator*(_T v) { return vex4<T>(this->x * T(v), this->y * T(v), this->z * T(v), this->w * T(v)); };
    template <typename _T>  vex4<T> operator*(vex4<_T> v) { return vex4<T>(this->x * T(v.x), this->y * T(v.y), this->z * T(v.z), this->w * T(v.w)); };

    template <typename _T>  vex4<T> operator/(_T v) { return vex4<T>(this->x / T(v), this->y / T(v), this->z / T(v), this->w / T(v)); };
    template <typename _T>  vex4<T> operator/(vex4<_T> v) { return vex4<T>(this->x / T(v.x), this->y / T(v.y), this->z / T(v.z), this->w / T(v.w)); };

    template <typename _T>  bool operator==(_T v) { return this->x == T(v) && this->y == T(v) && this->z == T(v) && this->w == T(v); };
    template <typename _T>  bool operator==(vex4<_T> v) { return this->x == T(v.x) && this->y == T(v.y) && this->z == T(v.z) && this->w == T(v.w); };

    template <typename _T>  bool operator!=(_T v) { return this->x != T(v) && this->y != T(v) && this->z != T(v) && this->w != T(v); };
    template <typename _T>  bool operator!=(vex4<_T> v) { return this->x != T(v.x) && this->y != T(v.y) && this->z != T(v.z) && this->w != T(v.w); };

    template <typename _T>  bool operator>(_T v) { return this->x > T(v) && this->y > T(v) && this->z > T(v) && this->w > T(v); };
    template <typename _T>  bool operator>(vex4<_T> v) { return this->x > T(v.x) && this->y > T(v.y) && this->z > T(v.z) && this->w > T(v.w); };

    template <typename _T>  bool operator<(_T v) { return this->x < T(v) && this->y < T(v) && this->z < T(v) && this->w < T(v); };
    template <typename _T>  bool operator<(vex4<_T> v) { return this->x < T(v.x) && this->y < T(v.y) && this->z < T(v.z) && this->w < T(v.w); };

    template <typename _T>  bool operator>=(_T v) { return this->x >= T(v) && this->y >= T(v) && this->z >= T(v) && this->w >= T(v); };
    template <typename _T>  bool operator>=(vex4<_T> v) { return this->x >= T(v.x) && this->y >= T(v.y) && this->z >= T(v.z) && this->w >= T(v.w); };

    template <typename _T>  bool operator<=(_T v) { return this->x <= T(v) && this->y <= T(v) && this->z <= T(v) && this->w <= T(v); };
    template <typename _T>  bool operator<=(vex4<_T> v) { return this->x <= T(v.x) && this->y <= T(v.y) && this->z <= T(v.z) && this->w <= T(v.w); };

    vex4<T>& normalize() { *this /= x > y ? x : y; return *this; };
    vex4<T> ceil() { return vex4<T>(std::ceil(x), std::ceil(y), std::ceil(z), std::ceil(w)); };
    vex4<T> floor() { return vex4<T>(std::floor(x), std::floor(y), std::floor(z), std::floor(w)); };
    vex4<T> abs() { return vex4<T>(std::abs(x), std::abs(y), std::abs(z), std::abs(w)); };
    vex4<T> sqrt() { return vex4<T>(std::sqrt(x), std::sqrt(y), std::sqrt(z), std::sqrt(w)); };
    vex4<T> cbrt() { return vex4<T>(std::cbrt(x), std::cbrt(y), std::cbrt(z), std::cbrt(w)); };
    vex4<T> pow(int v) { return vex4<T>(std::pow(x, v), std::pow(y, v), std::pow(z, v), std::pow(w, v)); };
    vex4<T> round() { return vex4<T>(std::round(x), std::round(y), std::round(z), std::round(w)); };
    vex4<T> trunc() { return vex4<T>(std::trunc(x), std::trunc(y), std::trunc(z), std::trunc(w)); };
    vex4<T> exp() { return vex4<T>(std::exp(x), std::exp(y), std::exp(z), std::exp(w)); };
    vex4<T> percent(T v) { return vex2<T>(x / T(100) * T(v), y / T(100) * T(v), z / T(100) * T(v), w / T(100) * T(v)); };
    vex4<T> percent(T v1, T v2, T v3, T v4) { return vex2<T>(x / T(100) * T(v1), y / T(100) * T(v2), z / T(100) * T(v3), w / T(100) * T(v4)); };

    template <typename _T> vex4<T>& operator=(vex2<_T> v) { x = T(v.x);  y = T(v.y);    return *this; };
    template <typename _T> vex4<T>& operator+=(vex2<_T> v) { x += T(v.x);  y += T(v.y);    return *this; };
    template <typename _T> vex4<T>& operator-=(vex2<_T> v) { x -= T(v.x);  y -= T(v.y);    return *this; };
    template <typename _T> vex4<T>& operator*=(vex2<_T> v) { x *= T(v.x);  y *= T(v.y);    return *this; };
    template <typename _T> vex4<T>& operator/=(vex2<_T> v) { x /= T(v.x);  y /= T(v.y);    return *this; };
    template <typename _T> vex4<T> operator+(vex2<_T> v) { return vex4<T>(x + T(v.x), y + T(v.y)); };
    template <typename _T> vex4<T> operator-(vex2<_T> v) { return vex4<T>(x - T(v.x), y - T(v.y)); };
    template <typename _T> vex4<T> operator*(vex2<_T> v) { return vex4<T>(x * T(v.x), y * T(v.y)); };
    template <typename _T> vex4<T> operator/(vex2<_T> v) { return vex4<T>(x / T(v.x), y / T(v.y)); };
    template <typename _T>  bool operator==(vex2<_T> v) { return this->x == T(v.x) && this->y == T(v.y); };
    template <typename _T>  bool operator!=(vex2<_T> v) { return this->x != T(v.x) && this->y != T(v.y); };
    template <typename _T>  bool operator>(vex2<_T> v) { return this->x > T(v.x) && this->y > T(v.y); };
    template <typename _T>  bool operator<(vex2<_T> v) { return this->x < T(v.x) && this->y < T(v.y); };
    template <typename _T>  bool operator>=(vex2<_T> v) { return this->x >= T(v.x) && this->y >= T(v.y); };
    template <typename _T>  bool operator<=(vex2<_T> v) { return this->x <= T(v.x) && this->y <= T(v.y); };

    template <typename _T> vex4<T>& operator=(vex3<_T> v) { x = T(v.x);  y = T(v.y);  z = T(v.z);  return *this; };
    template <typename _T> vex4<T>& operator+=(vex3<_T> v) { x += T(v.x);  y += T(v.y);  z += T(v.z);  return *this; };
    template <typename _T> vex4<T>& operator-=(vex3<_T> v) { x -= T(v.x);  y -= T(v.y);  z -= T(v.z);  return *this; };
    template <typename _T> vex4<T>& operator*=(vex3<_T> v) { x *= T(v.x);  y *= T(v.y);  z *= T(v.z);  return *this; };
    template <typename _T> vex4<T>& operator/=(vex3<_T> v) { x /= T(v.x);  y /= T(v.y);  z /= T(v.z);  return *this; };
    template <typename _T> vex4<T>& operator+(vex3<_T> v) { return vex4<T>(x + T(v.x), y + T(v.y), z + T(v.z)); };
    template <typename _T> vex4<T>& operator-(vex3<_T> v) { return vex4<T>(x - T(v.x), y - T(v.y), z - T(v.z)); };
    template <typename _T> vex4<T>& operator*(vex3<_T> v) { return vex4<T>(x * T(v.x), y * T(v.y), z * T(v.z)); };
    template <typename _T> vex4<T>& operator/(vex3<_T> v) { return vex4<T>(x / T(v.x), y / T(v.y), z / T(v.z)); };
    template <typename _T>  bool operator==(vex3<_T> v) { return this->x == T(v.x) && this->y == T(v.y) && this->z == T(v.z); };
    template <typename _T>  bool operator!=(vex3<_T> v) { return this->x != T(v.x) && this->y != T(v.y) && this->z != T(v.z); };
    template <typename _T>  bool operator>(vex3<_T> v) { return this->x > T(v.x) && this->y > T(v.y) && this->z > T(v.z); };
    template <typename _T>  bool operator<(vex3<_T> v) { return this->x < T(v.x) && this->y < T(v.y) && this->z < T(v.z); };
    template <typename _T>  bool operator>=(vex3<_T> v) { return this->x >= T(v.x) && this->y >= T(v.y) && this->z >= T(v.z); };
    template <typename _T>  bool operator<=(vex3<_T> v) { return this->x <= T(v.x) && this->y <= T(v.y) && this->z <= T(v.z); };

    friend std::ostream& operator<<(std::ostream& os, const vex4<T>& v) { os << v.x << ' ' << v.y << ' ' << v.z << ' ' << v.w; return os; };
};

template<> vex2<int>& vex2<int>::normalize() = delete;
template<> vex2<int> vex2<int>::ceil() = delete;
template<> vex2<int> vex2<int>::floor() = delete;
template<> vex2<int> vex2<int>::round() = delete;
template<> vex2<int> vex2<int>::trunc() = delete;
template<> vex2<size_t>& vex2<size_t>::normalize() = delete;
template<> vex2<size_t> vex2<size_t>::ceil() = delete;
template<> vex2<size_t> vex2<size_t>::floor() = delete;
template<> vex2<size_t> vex2<size_t>::round() = delete;
template<> vex2<size_t> vex2<size_t>::trunc() = delete;
template<> vex2<long int>& vex2<long int>::normalize() = delete;
template<> vex2<long int> vex2<long int>::ceil() = delete;
template<> vex2<long int> vex2<long int>::floor() = delete;
template<> vex2<long int> vex2<long int>::round() = delete;
template<> vex2<long int> vex2<long int>::trunc() = delete;
template<> vex2<long long int>& vex2<long long int>::normalize() = delete;
template<> vex2<long long int> vex2<long long int>::ceil() = delete;
template<> vex2<long long int> vex2<long long int>::floor() = delete;
template<> vex2<long long int> vex2<long long int>::round() = delete;
template<> vex2<long long int> vex2<long long int>::trunc() = delete;

template<> vex3<int>& vex3<int>::normalize() = delete;
template<> vex3<int> vex3<int>::ceil() = delete;
template<> vex3<int> vex3<int>::floor() = delete;
template<> vex3<int> vex3<int>::round() = delete;
template<> vex3<int> vex3<int>::trunc() = delete;
template<> vex3<size_t>& vex3<size_t>::normalize() = delete;
template<> vex3<size_t> vex3<size_t>::ceil() = delete;
template<> vex3<size_t> vex3<size_t>::floor() = delete;
template<> vex3<size_t> vex3<size_t>::round() = delete;
template<> vex3<size_t> vex3<size_t>::trunc() = delete;
template<> vex3<long int>& vex3<long int>::normalize() = delete;
template<> vex3<long int> vex3<long int>::ceil() = delete;
template<> vex3<long int> vex3<long int>::floor() = delete;
template<> vex3<long int> vex3<long int>::round() = delete;
template<> vex3<long int> vex3<long int>::trunc() = delete;
template<> vex3<long long int>& vex3<long long int>::normalize() = delete;
template<> vex3<long long int> vex3<long long int>::ceil() = delete;
template<> vex3<long long int> vex3<long long int>::floor() = delete;
template<> vex3<long long int> vex3<long long int>::round() = delete;
template<> vex3<long long int> vex3<long long int>::trunc() = delete;

template<> vex4<int>& vex4<int>::normalize() = delete;
template<> vex4<int> vex4<int>::ceil() = delete;
template<> vex4<int> vex4<int>::floor() = delete;
template<> vex4<int> vex4<int>::round() = delete;
template<> vex4<int> vex4<int>::trunc() = delete;
template<> vex4<size_t>& vex4<size_t>::normalize() = delete;
template<> vex4<size_t> vex4<size_t>::ceil() = delete;
template<> vex4<size_t> vex4<size_t>::floor() = delete;
template<> vex4<size_t> vex4<size_t>::round() = delete;
template<> vex4<size_t> vex4<size_t>::trunc() = delete;
template<> vex4<long int>& vex4<long int>::normalize() = delete;
template<> vex4<long int> vex4<long int>::ceil() = delete;
template<> vex4<long int> vex4<long int>::floor() = delete;
template<> vex4<long int> vex4<long int>::round() = delete;
template<> vex4<long int> vex4<long int>::trunc() = delete;
template<> vex4<long long int>& vex4<long long int>::normalize() = delete;
template<> vex4<long long int> vex4<long long int>::ceil() = delete;
template<> vex4<long long int> vex4<long long int>::floor() = delete;
template<> vex4<long long int> vex4<long long int>::round() = delete;
template<> vex4<long long int> vex4<long long int>::trunc() = delete;

template<> template <typename _T> vex2<std::string> vex2<std::string>::operator%(_T v) = delete;
template<> template <typename _T> vex2<std::string>& vex2<std::string>::operator%=(_T v) = delete;
template<> template <typename _T> vex2<std::string> vex2<std::string>::operator%(vex2<_T> v) = delete;
template<> template <typename _T> vex2<std::string>& vex2<std::string>::operator%=(vex2<_T> v) = delete;
template<> template <typename _T> bool vex2<std::string>::operator<(_T v) = delete;
template<> template <typename _T> bool vex2<std::string>::operator<(vex2<_T> v) = delete;
template<> template <typename _T> bool vex2<std::string>::operator>(_T v) = delete;
template<> template <typename _T> bool vex2<std::string>::operator>(vex2<_T> v) = delete;
template<> template <typename _T> bool vex2<std::string>::operator<=(_T v) = delete;
template<> template <typename _T> bool vex2<std::string>::operator<=(vex2<_T> v) = delete;
template<> template <typename _T> bool vex2<std::string>::operator>=(_T v) = delete;
template<> template <typename _T> bool vex2<std::string>::operator>=(vex2<_T> v) = delete;
template<> template <typename _T> vex2<std::string> vex2<std::string>::operator-(_T v) = delete;
template<> template <typename _T> vex2<std::string> vex2<std::string>::operator-(vex2<_T> v) = delete;
template<> template <typename _T> vex2<std::string>& vex2<std::string>::operator-=(_T v) = delete;
template<> template <typename _T> vex2<std::string>& vex2<std::string>::operator-=(vex2<_T> v) = delete;
template<> template <typename _T> vex2<std::string> vex2<std::string>::operator*(_T v) = delete;
template<> template <typename _T> vex2<std::string> vex2<std::string>::operator*(vex2<_T> v) = delete;
template<> template <typename _T> vex2<std::string>& vex2<std::string>::operator*=(_T v) = delete;
template<> template <typename _T> vex2<std::string>& vex2<std::string>::operator*=(vex2<_T> v) = delete;
template<> template <typename _T> vex2<std::string> vex2<std::string>::operator/(_T v) = delete;
template<> template <typename _T> vex2<std::string> vex2<std::string>::operator/(vex2<_T> v) = delete;
template<> template <typename _T> vex2<std::string>& vex2<std::string>::operator/=(_T v) = delete;
template<> template <typename _T> vex2<std::string>& vex2<std::string>::operator/=(vex2<_T> v) = delete;
template<> vex2<std::string>& vex2<std::string>::operator++() = delete;
template<> vex2<std::string>& vex2<std::string>::operator--() = delete;
template<> vex2<std::string>& vex2<std::string>::normalize() = delete;
template<> vex2<std::string> vex2<std::string>::ceil() = delete;
template<> vex2<std::string> vex2<std::string>::floor() = delete;
template<> vex2<std::string> vex2<std::string>::abs() = delete;
template<> vex2<std::string> vex2<std::string>::sqrt() = delete;
template<> vex2<std::string> vex2<std::string>::cbrt() = delete;
template<> vex2<std::string> vex2<std::string>::pow(int v) = delete;
template<> vex2<std::string> vex2<std::string>::round() = delete;
template<> vex2<std::string> vex2<std::string>::trunc() = delete;
template<> vex2<std::string> vex2<std::string>::exp() = delete;
template<> vex2<std::string> vex2<std::string>::percent(std::string v) = delete;
template<> vex2<std::string> vex2<std::string>::percent(std::string v1, std::string v2) = delete;

template<> template <typename _T> vex3<std::string> vex3<std::string>::operator%(_T v) = delete;
template<> template <typename _T> vex3<std::string>& vex3<std::string>::operator%=(_T v) = delete;
template<> template <typename _T> vex3<std::string> vex3<std::string>::operator%(vex3<_T> v) = delete;
template<> template <typename _T> vex3<std::string>& vex3<std::string>::operator%=(vex3<_T> v) = delete;
template<> template <typename _T> bool vex3<std::string>::operator<(_T v) = delete;
template<> template <typename _T> bool vex3<std::string>::operator<(vex3<_T> v) = delete;
template<> template <typename _T> bool vex3<std::string>::operator>(_T v) = delete;
template<> template <typename _T> bool vex3<std::string>::operator>(vex3<_T> v) = delete;
template<> template <typename _T> bool vex3<std::string>::operator<=(_T v) = delete;
template<> template <typename _T> bool vex3<std::string>::operator<=(vex3<_T> v) = delete;
template<> template <typename _T> bool vex3<std::string>::operator>=(_T v) = delete;
template<> template <typename _T> bool vex3<std::string>::operator>=(vex3<_T> v) = delete;
template<> template <typename _T> vex3<std::string> vex3<std::string>::operator-(_T v) = delete;
template<> template <typename _T> vex3<std::string> vex3<std::string>::operator-(vex3<_T> v) = delete;
template<> template <typename _T> vex3<std::string>& vex3<std::string>::operator-=(_T v) = delete;
template<> template <typename _T> vex3<std::string>& vex3<std::string>::operator-=(vex3<_T> v) = delete;
template<> template <typename _T> vex3<std::string> vex3<std::string>::operator*(_T v) = delete;
template<> template <typename _T> vex3<std::string> vex3<std::string>::operator*(vex3<_T> v) = delete;
template<> template <typename _T> vex3<std::string>& vex3<std::string>::operator*=(_T v) = delete;
template<> template <typename _T> vex3<std::string>& vex3<std::string>::operator*=(vex3<_T> v) = delete;
template<> template <typename _T> vex3<std::string> vex3<std::string>::operator/(_T v) = delete;
template<> template <typename _T> vex3<std::string> vex3<std::string>::operator/(vex3<_T> v) = delete;
template<> template <typename _T> vex3<std::string>& vex3<std::string>::operator/=(_T v) = delete;
template<> template <typename _T> vex3<std::string>& vex3<std::string>::operator/=(vex3<_T> v) = delete;
template<> vex3<std::string>& vex3<std::string>::operator++() = delete;
template<> vex3<std::string>& vex3<std::string>::operator--() = delete;
template<> vex3<std::string>& vex3<std::string>::normalize() = delete;
template<> vex3<std::string> vex3<std::string>::ceil() = delete;
template<> vex3<std::string> vex3<std::string>::floor() = delete;
template<> vex3<std::string> vex3<std::string>::abs() = delete;
template<> vex3<std::string> vex3<std::string>::sqrt() = delete;
template<> vex3<std::string> vex3<std::string>::cbrt() = delete;
template<> vex3<std::string> vex3<std::string>::pow(int v) = delete;
template<> vex3<std::string> vex3<std::string>::round() = delete;
template<> vex3<std::string> vex3<std::string>::trunc() = delete;
template<> vex3<std::string> vex3<std::string>::exp() = delete;
template<> vex3<std::string> vex3<std::string>::percent(std::string v) = delete;
template<> vex3<std::string> vex3<std::string>::percent(std::string v1, std::string v2, std::string v3) = delete;

template<> template <typename _T> vex4<std::string> vex4<std::string>::operator%(_T v) = delete;
template<> template <typename _T> vex4<std::string>& vex4<std::string>::operator%=(_T v) = delete;
template<> template <typename _T> vex4<std::string> vex4<std::string>::operator%(vex4<_T> v) = delete;
template<> template <typename _T> vex4<std::string>& vex4<std::string>::operator%=(vex4<_T> v) = delete;
template<> template <typename _T> bool vex4<std::string>::operator<(_T v) = delete;
template<> template <typename _T> bool vex4<std::string>::operator<(vex4<_T> v) = delete;
template<> template <typename _T> bool vex4<std::string>::operator>(_T v) = delete;
template<> template <typename _T> bool vex4<std::string>::operator>(vex4<_T> v) = delete;
template<> template <typename _T> bool vex4<std::string>::operator<=(_T v) = delete;
template<> template <typename _T> bool vex4<std::string>::operator<=(vex4<_T> v) = delete;
template<> template <typename _T> bool vex4<std::string>::operator>=(_T v) = delete;
template<> template <typename _T> bool vex4<std::string>::operator>=(vex4<_T> v) = delete;
template<> template <typename _T> vex4<std::string> vex4<std::string>::operator-(_T v) = delete;
template<> template <typename _T> vex4<std::string> vex4<std::string>::operator-(vex4<_T> v) = delete;
template<> template <typename _T> vex4<std::string>& vex4<std::string>::operator-=(_T v) = delete;
template<> template <typename _T> vex4<std::string>& vex4<std::string>::operator-=(vex4<_T> v) = delete;
template<> template <typename _T> vex4<std::string> vex4<std::string>::operator*(_T v) = delete;
template<> template <typename _T> vex4<std::string> vex4<std::string>::operator*(vex4<_T> v) = delete;
template<> template <typename _T> vex4<std::string>& vex4<std::string>::operator*=(_T v) = delete;
template<> template <typename _T> vex4<std::string>& vex4<std::string>::operator*=(vex4<_T> v) = delete;
template<> template <typename _T> vex4<std::string> vex4<std::string>::operator/(_T v) = delete;
template<> template <typename _T> vex4<std::string> vex4<std::string>::operator/(vex4<_T> v) = delete;
template<> template <typename _T> vex4<std::string>& vex4<std::string>::operator/=(_T v) = delete;
template<> template <typename _T> vex4<std::string>& vex4<std::string>::operator/=(vex4<_T> v) = delete;
template<> vex4<std::string>& vex4<std::string>::operator++() = delete;
template<> vex4<std::string>& vex4<std::string>::operator--() = delete;
template<> vex4<std::string>& vex4<std::string>::normalize() = delete;
template<> vex4<std::string> vex4<std::string>::ceil() = delete;
template<> vex4<std::string> vex4<std::string>::floor() = delete;
template<> vex4<std::string> vex4<std::string>::abs() = delete;
template<> vex4<std::string> vex4<std::string>::sqrt() = delete;
template<> vex4<std::string> vex4<std::string>::cbrt() = delete;
template<> vex4<std::string> vex4<std::string>::pow(int v) = delete;
template<> vex4<std::string> vex4<std::string>::round() = delete;
template<> vex4<std::string> vex4<std::string>::trunc() = delete;
template<> vex4<std::string> vex4<std::string>::exp() = delete;
template<> vex4<std::string> vex4<std::string>::percent(std::string v) = delete;
template<> vex4<std::string> vex4<std::string>::percent(std::string v1, std::string v2, std::string v3, std::string v4) = delete;


template<> template <typename _T> vex2<bool> vex2<bool>::operator%(_T v) = delete;
template<> template <typename _T> vex2<bool>& vex2<bool>::operator%=(_T v) = delete;
template<> template <typename _T> vex2<bool> vex2<bool>::operator%(vex2<_T> v) = delete;
template<> template <typename _T> vex2<bool>& vex2<bool>::operator%=(vex2<_T> v) = delete;
template<> template <typename _T> bool vex2<bool>::operator<(_T v) = delete;
template<> template <typename _T> bool vex2<bool>::operator<(vex2<_T> v) = delete;
template<> template <typename _T> bool vex2<bool>::operator>(_T v) = delete;
template<> template <typename _T> bool vex2<bool>::operator>(vex2<_T> v) = delete;
template<> template <typename _T> bool vex2<bool>::operator<=(_T v) = delete;
template<> template <typename _T> bool vex2<bool>::operator<=(vex2<_T> v) = delete;
template<> template <typename _T> bool vex2<bool>::operator>=(_T v) = delete;
template<> template <typename _T> bool vex2<bool>::operator>=(vex2<_T> v) = delete;
template<> template <typename _T> vex2<bool> vex2<bool>::operator-(_T v) = delete;
template<> template <typename _T> vex2<bool> vex2<bool>::operator-(vex2<_T> v) = delete;
template<> template <typename _T> vex2<bool>& vex2<bool>::operator-=(_T v) = delete;
template<> template <typename _T> vex2<bool>& vex2<bool>::operator-=(vex2<_T> v) = delete;
template<> template <typename _T> vex2<bool> vex2<bool>::operator*(_T v) = delete;
template<> template <typename _T> vex2<bool> vex2<bool>::operator*(vex2<_T> v) = delete;
template<> template <typename _T> vex2<bool>& vex2<bool>::operator*=(_T v) = delete;
template<> template <typename _T> vex2<bool>& vex2<bool>::operator*=(vex2<_T> v) = delete;
template<> template <typename _T> vex2<bool> vex2<bool>::operator/(_T v) = delete;
template<> template <typename _T> vex2<bool> vex2<bool>::operator/(vex2<_T> v) = delete;
template<> template <typename _T> vex2<bool>& vex2<bool>::operator/=(_T v) = delete;
template<> template <typename _T> vex2<bool>& vex2<bool>::operator/=(vex2<_T> v) = delete;
template<> vex2<bool>& vex2<bool>::operator++() = delete;
template<> vex2<bool>& vex2<bool>::operator--() = delete;
template<> vex2<bool>& vex2<bool>::normalize() = delete;
template<> vex2<bool> vex2<bool>::ceil() = delete;
template<> vex2<bool> vex2<bool>::floor() = delete;
template<> vex2<bool> vex2<bool>::abs() = delete;
template<> vex2<bool> vex2<bool>::sqrt() = delete;
template<> vex2<bool> vex2<bool>::cbrt() = delete;
template<> vex2<bool> vex2<bool>::pow(int v) = delete;
template<> vex2<bool> vex2<bool>::round() = delete;
template<> vex2<bool> vex2<bool>::trunc() = delete;
template<> vex2<bool> vex2<bool>::exp() = delete;
template<> vex2<bool> vex2<bool>::percent(bool v) = delete;
template<> vex2<bool> vex2<bool>::percent(bool v1, bool v2) = delete;

template<> template <typename _T> vex3<bool> vex3<bool>::operator%(_T v) = delete;
template<> template <typename _T> vex3<bool>& vex3<bool>::operator%=(_T v) = delete;
template<> template <typename _T> vex3<bool> vex3<bool>::operator%(vex3<_T> v) = delete;
template<> template <typename _T> vex3<bool>& vex3<bool>::operator%=(vex3<_T> v) = delete;
template<> template <typename _T> bool vex3<bool>::operator<(_T v) = delete;
template<> template <typename _T> bool vex3<bool>::operator<(vex3<_T> v) = delete;
template<> template <typename _T> bool vex3<bool>::operator>(_T v) = delete;
template<> template <typename _T> bool vex3<bool>::operator>(vex3<_T> v) = delete;
template<> template <typename _T> bool vex3<bool>::operator<=(_T v) = delete;
template<> template <typename _T> bool vex3<bool>::operator<=(vex3<_T> v) = delete;
template<> template <typename _T> bool vex3<bool>::operator>=(_T v) = delete;
template<> template <typename _T> bool vex3<bool>::operator>=(vex3<_T> v) = delete;
template<> template <typename _T> vex3<bool> vex3<bool>::operator-(_T v) = delete;
template<> template <typename _T> vex3<bool> vex3<bool>::operator-(vex3<_T> v) = delete;
template<> template <typename _T> vex3<bool>& vex3<bool>::operator-=(_T v) = delete;
template<> template <typename _T> vex3<bool>& vex3<bool>::operator-=(vex3<_T> v) = delete;
template<> template <typename _T> vex3<bool> vex3<bool>::operator*(_T v) = delete;
template<> template <typename _T> vex3<bool> vex3<bool>::operator*(vex3<_T> v) = delete;
template<> template <typename _T> vex3<bool>& vex3<bool>::operator*=(_T v) = delete;
template<> template <typename _T> vex3<bool>& vex3<bool>::operator*=(vex3<_T> v) = delete;
template<> template <typename _T> vex3<bool> vex3<bool>::operator/(_T v) = delete;
template<> template <typename _T> vex3<bool> vex3<bool>::operator/(vex3<_T> v) = delete;
template<> template <typename _T> vex3<bool>& vex3<bool>::operator/=(_T v) = delete;
template<> template <typename _T> vex3<bool>& vex3<bool>::operator/=(vex3<_T> v) = delete;
template<> vex3<bool>& vex3<bool>::operator++() = delete;
template<> vex3<bool>& vex3<bool>::operator--() = delete;
template<> vex3<bool>& vex3<bool>::normalize() = delete;
template<> vex3<bool> vex3<bool>::ceil() = delete;
template<> vex3<bool> vex3<bool>::floor() = delete;
template<> vex3<bool> vex3<bool>::abs() = delete;
template<> vex3<bool> vex3<bool>::sqrt() = delete;
template<> vex3<bool> vex3<bool>::cbrt() = delete;
template<> vex3<bool> vex3<bool>::pow(int v) = delete;
template<> vex3<bool> vex3<bool>::round() = delete;
template<> vex3<bool> vex3<bool>::trunc() = delete;
template<> vex3<bool> vex3<bool>::exp() = delete;
template<> vex3<bool> vex3<bool>::percent(bool v) = delete;
template<> vex3<bool> vex3<bool>::percent(bool v1, bool v2, bool v3) = delete;

template<> template <typename _T> vex4<bool> vex4<bool>::operator%(_T v) = delete;
template<> template <typename _T> vex4<bool>& vex4<bool>::operator%=(_T v) = delete;
template<> template <typename _T> vex4<bool> vex4<bool>::operator%(vex4<_T> v) = delete;
template<> template <typename _T> vex4<bool>& vex4<bool>::operator%=(vex4<_T> v) = delete;
template<> template <typename _T> bool vex4<bool>::operator<(_T v) = delete;
template<> template <typename _T> bool vex4<bool>::operator<(vex4<_T> v) = delete;
template<> template <typename _T> bool vex4<bool>::operator>(_T v) = delete;
template<> template <typename _T> bool vex4<bool>::operator>(vex4<_T> v) = delete;
template<> template <typename _T> bool vex4<bool>::operator<=(_T v) = delete;
template<> template <typename _T> bool vex4<bool>::operator<=(vex4<_T> v) = delete;
template<> template <typename _T> bool vex4<bool>::operator>=(_T v) = delete;
template<> template <typename _T> bool vex4<bool>::operator>=(vex4<_T> v) = delete;
template<> template <typename _T> vex4<bool> vex4<bool>::operator-(_T v) = delete;
template<> template <typename _T> vex4<bool> vex4<bool>::operator-(vex4<_T> v) = delete;
template<> template <typename _T> vex4<bool>& vex4<bool>::operator-=(_T v) = delete;
template<> template <typename _T> vex4<bool>& vex4<bool>::operator-=(vex4<_T> v) = delete;
template<> template <typename _T> vex4<bool> vex4<bool>::operator*(_T v) = delete;
template<> template <typename _T> vex4<bool> vex4<bool>::operator*(vex4<_T> v) = delete;
template<> template <typename _T> vex4<bool>& vex4<bool>::operator*=(_T v) = delete;
template<> template <typename _T> vex4<bool>& vex4<bool>::operator*=(vex4<_T> v) = delete;
template<> template <typename _T> vex4<bool> vex4<bool>::operator/(_T v) = delete;
template<> template <typename _T> vex4<bool> vex4<bool>::operator/(vex4<_T> v) = delete;
template<> template <typename _T> vex4<bool>& vex4<bool>::operator/=(_T v) = delete;
template<> template <typename _T> vex4<bool>& vex4<bool>::operator/=(vex4<_T> v) = delete;
template<> vex4<bool>& vex4<bool>::operator++() = delete;
template<> vex4<bool>& vex4<bool>::operator--() = delete;
template<> vex4<bool>& vex4<bool>::normalize() = delete;
template<> vex4<bool> vex4<bool>::ceil() = delete;
template<> vex4<bool> vex4<bool>::floor() = delete;
template<> vex4<bool> vex4<bool>::abs() = delete;
template<> vex4<bool> vex4<bool>::sqrt() = delete;
template<> vex4<bool> vex4<bool>::cbrt() = delete;
template<> vex4<bool> vex4<bool>::pow(int v) = delete;
template<> vex4<bool> vex4<bool>::round() = delete;
template<> vex4<bool> vex4<bool>::trunc() = delete;
template<> vex4<bool> vex4<bool>::exp() = delete;
template<> vex4<bool> vex4<bool>::percent(bool v) = delete;
template<> vex4<bool> vex4<bool>::percent(bool v1, bool v2, bool v3, bool v4) = delete;

#ifdef _XS_STRINX_
template<> template <typename _T> vex2<strinx> vex2<strinx>::operator%(_T v) = delete;
template<> template <typename _T> vex2<strinx>& vex2<strinx>::operator%=(_T v) = delete;
template<> template <typename _T> vex2<strinx> vex2<strinx>::operator%(vex2<_T> v) = delete;
template<> template <typename _T> vex2<strinx>& vex2<strinx>::operator%=(vex2<_T> v) = delete;
template<> template <typename _T> bool vex2<strinx>::operator<(_T v) = delete;
template<> template <typename _T> bool vex2<strinx>::operator<(vex2<_T> v) = delete;
template<> template <typename _T> bool vex2<strinx>::operator>(_T v) = delete;
template<> template <typename _T> bool vex2<strinx>::operator>(vex2<_T> v) = delete;
template<> template <typename _T> bool vex2<strinx>::operator<=(_T v) = delete;
template<> template <typename _T> bool vex2<strinx>::operator<=(vex2<_T> v) = delete;
template<> template <typename _T> bool vex2<strinx>::operator>=(_T v) = delete;
template<> template <typename _T> bool vex2<strinx>::operator>=(vex2<_T> v) = delete;
template<> vex2<strinx>& vex2<strinx>::normalize() = delete;
template<> vex2<strinx> vex2<strinx>::ceil() = delete;
template<> vex2<strinx> vex2<strinx>::floor() = delete;
template<> vex2<strinx> vex2<strinx>::abs() = delete;
template<> vex2<strinx> vex2<strinx>::sqrt() = delete;
template<> vex2<strinx> vex2<strinx>::cbrt() = delete;
template<> vex2<strinx> vex2<strinx>::pow(int v) = delete;
template<> vex2<strinx> vex2<strinx>::round() = delete;
template<> vex2<strinx> vex2<strinx>::trunc() = delete;
template<> vex2<strinx> vex2<strinx>::exp() = delete;
template<> vex2<strinx> vex2<strinx>::percent(strinx v) = delete;
template<> vex2<strinx> vex2<strinx>::percent(strinx v1, strinx v2) = delete;
typedef vex2<strinx> vex2x;

template<> template <typename _T> vex3<strinx> vex3<strinx>::operator%(_T v) = delete;
template<> template <typename _T> vex3<strinx>& vex3<strinx>::operator%=(_T v) = delete;
template<> template <typename _T> vex3<strinx> vex3<strinx>::operator%(vex3<_T> v) = delete;
template<> template <typename _T> vex3<strinx>& vex3<strinx>::operator%=(vex3<_T> v) = delete;
template<> template <typename _T> bool vex3<strinx>::operator<(_T v) = delete;
template<> template <typename _T> bool vex3<strinx>::operator<(vex3<_T> v) = delete;
template<> template <typename _T> bool vex3<strinx>::operator>(_T v) = delete;
template<> template <typename _T> bool vex3<strinx>::operator>(vex3<_T> v) = delete;
template<> template <typename _T> bool vex3<strinx>::operator<=(_T v) = delete;
template<> template <typename _T> bool vex3<strinx>::operator<=(vex3<_T> v) = delete;
template<> template <typename _T> bool vex3<strinx>::operator>=(_T v) = delete;
template<> template <typename _T> bool vex3<strinx>::operator>=(vex3<_T> v) = delete;
template<> vex3<strinx>& vex3<strinx>::normalize() = delete;
template<> vex3<strinx> vex3<strinx>::ceil() = delete;
template<> vex3<strinx> vex3<strinx>::floor() = delete;
template<> vex3<strinx> vex3<strinx>::abs() = delete;
template<> vex3<strinx> vex3<strinx>::sqrt() = delete;
template<> vex3<strinx> vex3<strinx>::cbrt() = delete;
template<> vex3<strinx> vex3<strinx>::pow(int v) = delete;
template<> vex3<strinx> vex3<strinx>::round() = delete;
template<> vex3<strinx> vex3<strinx>::trunc() = delete;
template<> vex3<strinx> vex3<strinx>::exp() = delete;
template<> vex3<strinx> vex3<strinx>::percent(strinx v) = delete;
template<> vex3<strinx> vex3<strinx>::percent(strinx v1, strinx v2, strinx v3) = delete;
typedef vex3<strinx> vex3x;

template<> template <typename _T> vex4<strinx> vex4<strinx>::operator%(_T v) = delete;
template<> template <typename _T> vex4<strinx>& vex4<strinx>::operator%=(_T v) = delete;
template<> template <typename _T> vex4<strinx> vex4<strinx>::operator%(vex4<_T> v) = delete;
template<> template <typename _T> vex4<strinx>& vex4<strinx>::operator%=(vex4<_T> v) = delete;
template<> template <typename _T> bool vex4<strinx>::operator<(_T v) = delete;
template<> template <typename _T> bool vex4<strinx>::operator<(vex4<_T> v) = delete;
template<> template <typename _T> bool vex4<strinx>::operator>(_T v) = delete;
template<> template <typename _T> bool vex4<strinx>::operator>(vex4<_T> v) = delete;
template<> template <typename _T> bool vex4<strinx>::operator<=(_T v) = delete;
template<> template <typename _T> bool vex4<strinx>::operator<=(vex4<_T> v) = delete;
template<> template <typename _T> bool vex4<strinx>::operator>=(_T v) = delete;
template<> template <typename _T> bool vex4<strinx>::operator>=(vex4<_T> v) = delete;
template<> vex4<strinx>& vex4<strinx>::normalize() = delete;
template<> vex4<strinx> vex4<strinx>::ceil() = delete;
template<> vex4<strinx> vex4<strinx>::floor() = delete;
template<> vex4<strinx> vex4<strinx>::abs() = delete;
template<> vex4<strinx> vex4<strinx>::sqrt() = delete;
template<> vex4<strinx> vex4<strinx>::cbrt() = delete;
template<> vex4<strinx> vex4<strinx>::pow(int v) = delete;
template<> vex4<strinx> vex4<strinx>::round() = delete;
template<> vex4<strinx> vex4<strinx>::trunc() = delete;
template<> vex4<strinx> vex4<strinx>::exp() = delete;
template<> vex4<strinx> vex4<strinx>::percent(strinx v) = delete;
template<> vex4<strinx> vex4<strinx>::percent(strinx v1, strinx v2, strinx v3, strinx v4) = delete;
typedef vex4<strinx> vex4x;
#endif

template<> template<> vex2<float>::vex2(std::string v) { x = y = std::stof(v.c_str()); };
template<> template<> vex2<int>::vex2(std::string v) { x = y = std::stoi(v.c_str()); };
template<> template<> vex2<size_t>::vex2(std::string v) { x = y = std::stoi(v.c_str()); };
template<> template<> vex2<long int>::vex2(std::string v) { x = y = std::stoi(v.c_str()); };
template<> template<> vex2<long long int>::vex2(std::string v) { x = y = std::stoi(v.c_str()); };
template<> template<> vex2<double>::vex2(std::string v) { x = y = std::stof(v.c_str()); };
template<> template<> vex2<long double>::vex2(std::string v) { x = y = std::stof(v.c_str()); };

template<> template<> vex2<float>::vex2(std::string v1, std::string v2) { x = std::stof(v1.c_str()); y = std::stof(v2.c_str()); };
template<> template<> vex2<int>::vex2(std::string v1, std::string v2) { x = std::stoi(v1.c_str()); y = std::stoi(v2.c_str()); };
template<> template<> vex2<size_t>::vex2(std::string v1, std::string v2) { x = std::stoi(v1.c_str()); y = std::stoi(v2.c_str()); };
template<> template<> vex2<long int>::vex2(std::string v1, std::string v2) { x = std::stoi(v1.c_str()); y = std::stoi(v2.c_str()); };
template<> template<> vex2<long long int>::vex2(std::string v1, std::string v2) { x = std::stoi(v1.c_str()); y = std::stoi(v2.c_str()); };
template<> template<> vex2<double>::vex2(std::string v1, std::string v2) { x = std::stof(v1.c_str()); y = std::stof(v2.c_str()); };
template<> template<> vex2<long double>::vex2(std::string v1, std::string v2) { x = std::stof(v1.c_str()); y = std::stof(v2.c_str()); };

template<> template<> vex2<float>& vex2<float>::operator=(std::string v) { x = y = std::stof(v.c_str()); return *this; };
template<> template<> vex2<int>& vex2<int>::operator=(std::string v) { x = y = std::stoi(v.c_str()); return *this; };
template<> template<> vex2<size_t>& vex2<size_t>::operator=(std::string v) { x = y = std::stoi(v.c_str()); return *this; };
template<> template<> vex2<long int>& vex2<long int>::operator=(std::string v) { x = y = std::stoi(v.c_str()); return *this; };
template<> template<> vex2<long long int>& vex2<long long int>::operator=(std::string v) { x = y = std::stoi(v.c_str()); return *this; };
template<> template<> vex2<double>& vex2<double>::operator=(std::string v) { x = y = std::stof(v.c_str()); return *this; };
template<> template<> vex2<long double>& vex2<long double>::operator=(std::string v) { x = y = std::stof(v.c_str()); return *this; };


template<> template<> vex3<float>::vex3(std::string v) { x = y = z = std::stof(v); };
template<> template<> vex3<int>::vex3(std::string v) { x = y = z = std::stoi(v); };
template<> template<> vex3<size_t>::vex3(std::string v) { x = y = z = std::stoi(v); };
template<> template<> vex3<long int>::vex3(std::string v) { x = y = z = std::stoi(v); };
template<> template<> vex3<long long int>::vex3(std::string v) { x = y = z = std::stoi(v); };
template<> template<> vex3<double>::vex3(std::string v) { x = y = z = std::stof(v); };
template<> template<> vex3<long double>::vex3(std::string v) { x = y = z = std::stof(v); };

template<> template<> vex3<float>::vex3(std::string v1, std::string v2) { x = std::stof(v1.c_str()); y = std::stof(v2.c_str()); };
template<> template<> vex3<int>::vex3(std::string v1, std::string v2) { x = std::stoi(v1.c_str()); y = std::stoi(v2.c_str()); };
template<> template<> vex3<size_t>::vex3(std::string v1, std::string v2) { x = std::stoi(v1.c_str()); y = std::stoi(v2.c_str()); };
template<> template<> vex3<long int>::vex3(std::string v1, std::string v2) { x = std::stoi(v1.c_str()); y = std::stoi(v2.c_str()); };
template<> template<> vex3<long long int>::vex3(std::string v1, std::string v2) { x = std::stoi(v1.c_str()); y = std::stoi(v2.c_str()); };
template<> template<> vex3<double>::vex3(std::string v1, std::string v2) { x = std::stof(v1.c_str()); y = std::stof(v2.c_str()); };
template<> template<> vex3<long double>::vex3(std::string v1, std::string v2) { x = std::stof(v1.c_str()); y = std::stof(v2.c_str()); };

template<> template<> vex3<float>::vex3(std::string v1, std::string v2, std::string v3) { x = std::stof(v1.c_str()); y = std::stof(v2.c_str()); z = std::stof(v3.c_str()); };
template<> template<> vex3<int>::vex3(std::string v1, std::string v2, std::string v3) { x = std::stoi(v1.c_str()); y = std::stoi(v2.c_str()); z = std::stoi(v3.c_str()); };
template<> template<> vex3<size_t>::vex3(std::string v1, std::string v2, std::string v3) { x = std::stoi(v1.c_str()); y = std::stoi(v2.c_str()); z = std::stoi(v3.c_str()); };
template<> template<> vex3<long int>::vex3(std::string v1, std::string v2, std::string v3) { x = std::stoi(v1.c_str()); y = std::stoi(v2.c_str()); z = std::stoi(v3.c_str()); };
template<> template<> vex3<long long int>::vex3(std::string v1, std::string v2, std::string v3) { x = std::stoi(v1.c_str()); y = std::stoi(v2.c_str()); z = std::stoi(v3.c_str()); };
template<> template<> vex3<double>::vex3(std::string v1, std::string v2, std::string v3) { x = std::stof(v1.c_str()); y = std::stof(v2.c_str()); z = std::stof(v3.c_str()); };
template<> template<> vex3<long double>::vex3(std::string v1, std::string v2, std::string v3) { x = std::stof(v1.c_str()); y = std::stof(v2.c_str()); z = std::stof(v3.c_str()); };

template<> template<> vex3<float>& vex3<float>::operator=(std::string v) { x = y = z = std::stof(v.c_str()); return *this; };
template<> template<> vex3<int>& vex3<int>::operator=(std::string v) { x = y = z = std::stoi(v.c_str()); return *this; };
template<> template<> vex3<size_t>& vex3<size_t>::operator=(std::string v) { x = y = z = std::stoi(v.c_str()); return *this; };
template<> template<> vex3<long int>& vex3<long int>::operator=(std::string v) { x = y = z = std::stoi(v.c_str()); return *this; };
template<> template<> vex3<long long int>& vex3<long long int>::operator=(std::string v) { x = y = z = std::stoi(v.c_str()); return *this; };
template<> template<> vex3<double>& vex3<double>::operator=(std::string v) { x = y = z = std::stof(v.c_str()); return *this; };
template<> template<> vex3<long double>& vex3<long double>::operator=(std::string v) { x = y = z = std::stof(v.c_str()); return *this; };


template<> template<> vex4<float>::vex4(std::string v) { x = y = z = w = std::stof(v.c_str()); };
template<> template<> vex4<int>::vex4(std::string v) { x = y = z = w = std::stoi(v.c_str()); };
template<> template<> vex4<size_t>::vex4(std::string v) { x = y = z = w = std::stoi(v.c_str()); };
template<> template<> vex4<long int>::vex4(std::string v) { x = y = z = w = std::stoi(v.c_str()); };
template<> template<> vex4<long long int>::vex4(std::string v) { x = y = z = w = std::stoi(v.c_str()); };
template<> template<> vex4<double>::vex4(std::string v) { x = y = z = w = std::stof(v.c_str()); };
template<> template<> vex4<long double>::vex4(std::string v) { x = y = z = w = std::stof(v.c_str()); };

template<> template<> vex4<float>::vex4(std::string v1, std::string v2) { x = std::stof(v1.c_str()); y = std::stof(v2.c_str()); };
template<> template<> vex4<int>::vex4(std::string v1, std::string v2) { x = std::stoi(v1.c_str()); y = std::stoi(v2.c_str()); };
template<> template<> vex4<size_t>::vex4(std::string v1, std::string v2) { x = std::stoi(v1.c_str()); y = std::stoi(v2.c_str()); };
template<> template<> vex4<long int>::vex4(std::string v1, std::string v2) { x = std::stoi(v1.c_str()); y = std::stoi(v2.c_str()); };
template<> template<> vex4<long long int>::vex4(std::string v1, std::string v2) { x = std::stoi(v1.c_str()); y = std::stoi(v2.c_str()); };
template<> template<> vex4<double>::vex4(std::string v1, std::string v2) { x = std::stof(v1.c_str()); y = std::stof(v2.c_str()); };
template<> template<> vex4<long double>::vex4(std::string v1, std::string v2) { x = std::stof(v1.c_str()); y = std::stof(v2.c_str()); };

template<> template<> vex4<float>::vex4(std::string v1, std::string v2, std::string v3) { x = std::stof(v1.c_str()); y = std::stof(v2.c_str()); z = std::stof(v3.c_str()); };
template<> template<> vex4<int>::vex4(std::string v1, std::string v2, std::string v3) { x = std::stoi(v1.c_str()); y = std::stoi(v2.c_str()); z = std::stoi(v3.c_str()); };
template<> template<> vex4<size_t>::vex4(std::string v1, std::string v2, std::string v3) { x = std::stoi(v1.c_str()); y = std::stoi(v2.c_str()); z = std::stoi(v3.c_str()); };
template<> template<> vex4<long int>::vex4(std::string v1, std::string v2, std::string v3) { x = std::stoi(v1.c_str()); y = std::stoi(v2.c_str()); z = std::stoi(v3.c_str()); };
template<> template<> vex4<long long int>::vex4(std::string v1, std::string v2, std::string v3) { x = std::stoi(v1.c_str()); y = std::stoi(v2.c_str()); z = std::stoi(v3.c_str()); };
template<> template<> vex4<double>::vex4(std::string v1, std::string v2, std::string v3) { x = std::stof(v1.c_str()); y = std::stof(v2.c_str()); z = std::stof(v3.c_str()); };
template<> template<> vex4<long double>::vex4(std::string v1, std::string v2, std::string v3) { x = std::stof(v1.c_str()); y = std::stof(v2.c_str()); z = std::stof(v3.c_str()); };

template<> template<> vex4<float>::vex4(std::string v1, std::string v2, std::string v3, std::string v4) { x = std::stof(v1.c_str()); y = std::stof(v2.c_str()); z = std::stof(v3.c_str()); w = std::stof(v4.c_str()); };
template<> template<> vex4<int>::vex4(std::string v1, std::string v2, std::string v3, std::string v4) { x = std::stoi(v1.c_str()); y = std::stoi(v2.c_str()); z = std::stoi(v3.c_str()); w = std::stoi(v4.c_str()); };
template<> template<> vex4<size_t>::vex4(std::string v1, std::string v2, std::string v3, std::string v4) { x = std::stoi(v1.c_str()); y = std::stoi(v2.c_str()); z = std::stoi(v3.c_str()); w = std::stoi(v4.c_str()); };
template<> template<> vex4<long int>::vex4(std::string v1, std::string v2, std::string v3, std::string v4) { x = std::stoi(v1.c_str()); y = std::stoi(v2.c_str()); z = std::stoi(v3.c_str()); w = std::stoi(v4.c_str()); };
template<> template<> vex4<long long int>::vex4(std::string v1, std::string v2, std::string v3, std::string v4) { x = std::stoi(v1.c_str()); y = std::stoi(v2.c_str()); z = std::stoi(v3.c_str()); w = std::stoi(v4.c_str()); };
template<> template<> vex4<double>::vex4(std::string v1, std::string v2, std::string v3, std::string v4) { x = std::stof(v1.c_str()); y = std::stof(v2.c_str()); z = std::stof(v3.c_str()); w = std::stof(v4.c_str()); };
template<> template<> vex4<long double>::vex4(std::string v1, std::string v2, std::string v3, std::string v4) { x = std::stof(v1.c_str()); y = std::stof(v2.c_str()); z = std::stof(v3.c_str()); w = std::stof(v4.c_str()); };

template<> template<> vex4<float>& vex4<float>::operator=(std::string v) { x = y = z = w = std::stof(v.c_str()); return *this; };
template<> template<> vex4<int>& vex4<int>::operator=(std::string v) { x = y = z = w = std::stoi(v.c_str()); return *this; };
template<> template<> vex4<size_t>& vex4<size_t>::operator=(std::string v) { x = y = z = w = std::stoi(v.c_str()); return *this; };
template<> template<> vex4<long int>& vex4<long int>::operator=(std::string v) { x = y = z = w = std::stoi(v.c_str()); return *this; };
template<> template<> vex4<long long int>& vex4<long long int>::operator=(std::string v) { x = y = z = w = std::stoi(v.c_str()); return *this; };
template<> template<> vex4<long double>& vex4<long double>::operator=(std::string v) { x = y = z = w = std::stof(v.c_str()); return *this; };

typedef vex2<bool>          vex2b;
typedef vex2<float>         vex2f;
typedef vex2<int>           vex2i;
typedef vex2<size_t>        vex2ui;
typedef vex2<double>        vex2d;
typedef vex2<long double>   vex2ld;
typedef vex2<long int>      vex2li;
typedef vex2<long long int> vex2lli;
typedef vex2<std::string>   vex2s;

typedef vex3<bool>          vex3b;
typedef vex3<float>         vex3f;
typedef vex3<int>           vex3i;
typedef vex3<size_t>        vex3ui;
typedef vex3<double>        vex3d;
typedef vex3<long double>   vex3ld;
typedef vex3<long int>      vex3li;
typedef vex3<long long int> vex3lli;
typedef vex3<std::string>   vex3s;

typedef vex4<bool>          vex4b;
typedef vex4<float>         vex4f;
typedef vex4<int>           vex4i;
typedef vex4<size_t>        vex4ui;
typedef vex4<double>        vex4d;
typedef vex4<long double>   vex4ld;
typedef vex4<long int>      vex4li;
typedef vex4<long long int> vex4lli;
typedef vex4<std::string>   vex4s;