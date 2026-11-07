// HMOOD__TG@i_8_f
 

#pragma once

#define _USE_MATH_DEFINES
#include <math.h>


struct Vector3
{
    union
    {
        struct
        {
            float X;
            float Y;
            float Z;
        };
        float data[3];
    };


     
    inline Vector3();
    inline Vector3(float data[]);
    inline Vector3(float value);
    inline Vector3(float x, float y);
    inline Vector3(float x, float y, float z);


     
    static inline Vector3 Zero();
    
    static inline Vector3 Right();
    static inline Vector3 Left();
    static inline Vector3 Up();
    static inline Vector3 Down();
    static inline Vector3 Forward();


 
    static inline float Angle(Vector3 a, Vector3 b);

     
    

     
    static inline float Component(Vector3 a, Vector3 b);

     
    static inline Vector3 Cross(Vector3 lhs, Vector3 rhs);

     
    static inline float Distance(Vector3 a, Vector3 b);


 
    static inline float Dot(Vector3 lhs, Vector3 rhs);

     
    

     
    static inline Vector3 Lerp(Vector3 a, Vector3 b, float t);

     
    static inline Vector3 LerpUnclamped(Vector3 a, Vector3 b, float t);

     
    static inline float Magnitude(Vector3 v);

     
    static inline Vector3 Max(Vector3 a, Vector3 b);

     
    static inline Vector3 Min(Vector3 a, Vector3 b);

     
    

     
    static inline Vector3 Normalized(Vector3 v);

     
    

     
    

     
    static inline Vector3 Project(Vector3 a, Vector3 b);

     
    static inline Vector3 ProjectOnPlane(Vector3 vector, Vector3 planeNormal);

     
    

     
    static inline Vector3 Reject(Vector3 a, Vector3 b);

     
    

     
    static inline Vector3 Scale(Vector3 a, Vector3 b);

     
    

     
    static inline Vector3 SlerpUnclamped(Vector3 a, Vector3 b, float t);

     
    static inline float SqrMagnitude(Vector3 v);

     


 
    inline struct Vector3& operator+=(const float rhs);
    inline struct Vector3& operator-=(const float rhs);
    inline struct Vector3& operator*=(const float rhs);
    inline struct Vector3& operator/=(const float rhs);
    inline struct Vector3& operator+=(const Vector3 rhs);
    inline struct Vector3& operator-=(const Vector3 rhs);
};

inline Vector3 operator-(Vector3 rhs);
inline Vector3 operator+(Vector3 lhs, const float rhs);
inline Vector3 operator-(Vector3 lhs, const float rhs);
inline Vector3 operator*(Vector3 lhs, const float rhs);
inline Vector3 operator/(Vector3 lhs, const float rhs);
inline Vector3 operator+(const float lhs, Vector3 rhs);
inline Vector3 operator-(const float lhs, Vector3 rhs);
inline Vector3 operator*(const float lhs, Vector3 rhs);
inline Vector3 operator/(const float lhs, Vector3 rhs);
inline Vector3 operator+(Vector3 lhs, const Vector3 rhs);
inline Vector3 operator-(Vector3 lhs, const Vector3 rhs);
inline bool operator==(const Vector3 lhs, const Vector3 rhs);
inline bool operator!=(const Vector3 lhs, const Vector3 rhs);


 

Vector3::Vector3() : X(0), Y(0), Z(0) {}
Vector3::Vector3(float data[]) : X(data[0]), Y(data[1]), Z(data[2]) {}
Vector3::Vector3(float value) : X(value), Y(value), Z(value) {}
Vector3::Vector3(float x, float y) : X(x), Y(y), Z(0) {}
Vector3::Vector3(float x, float y, float z) : X(x), Y(y), Z(z) {}


Vector3 Vector3::Zero() { return Vector3(0, 0, 0); }

Vector3 Vector3::Right() { return Vector3(1, 0, 0); }
Vector3 Vector3::Left() { return Vector3(-1, 0, 0); }
Vector3 Vector3::Up() { return Vector3(0, 1, 0); }
Vector3 Vector3::Down() { return Vector3(0, -1, 0); }
Vector3 Vector3::Forward() { return Vector3(0, 0, 1); }


float Vector3::Angle(Vector3 a, Vector3 b)
{
    float v = Dot(a, b) / (Magnitude(a) * Magnitude(b));
    v = fmax(v, -1.0);
    v = fmin(v, 1.0);
    return acos(v);
}


float Vector3::Component(Vector3 a, Vector3 b)
{
    return Dot(a, b) / Magnitude(b);
}

Vector3 Vector3::Cross(Vector3 lhs, Vector3 rhs)
{
    float x = lhs.Y * rhs.Z - lhs.Z * rhs.Y;
    float y = lhs.Z * rhs.X - lhs.X * rhs.Z;
    float z = lhs.X * rhs.Y - lhs.Y * rhs.X;
    return Vector3(x, y, z);
}

float Vector3::Distance(Vector3 a, Vector3 b)
{
    return Vector3::Magnitude(a - b);
}

float Vector3::Dot(Vector3 lhs, Vector3 rhs)
{
    return lhs.X * rhs.X + lhs.Y * rhs.Y + lhs.Z * rhs.Z;
}


Vector3 Vector3::Lerp(Vector3 a, Vector3 b, float t)
{
    if (t < 0) return a;
    else if (t > 1) return b;
    return LerpUnclamped(a, b, t);
}

Vector3 Vector3::LerpUnclamped(Vector3 a, Vector3 b, float t)
{
    return (b - a) * t + a;
}

float Vector3::Magnitude(Vector3 v)
{
    return sqrt(SqrMagnitude(v));
}

Vector3 Vector3::Max(Vector3 a, Vector3 b)
{
    float x = a.X > b.X ? a.X : b.X;
    float y = a.Y > b.Y ? a.Y : b.Y;
    float z = a.Z > b.Z ? a.Z : b.Z;
    return Vector3(x, y, z);
}

Vector3 Vector3::Min(Vector3 a, Vector3 b)
{
    float x = a.X > b.X ? b.X : a.X;
    float y = a.Y > b.Y ? b.Y : a.Y;
    float z = a.Z > b.Z ? b.Z : a.Z;
    return Vector3(x, y, z);
}


Vector3 Vector3::Normalized(Vector3 v)
{
    float mag = Magnitude(v);
    if (mag == 0)
        return Vector3::Zero();
    return v / mag;
}


Vector3 Vector3::Project(Vector3 a, Vector3 b)
{
    float m = Magnitude(b);
    return Dot(a, b) / (m * m) * b;
}

Vector3 Vector3::ProjectOnPlane(Vector3 vector, Vector3 planeNormal)
{
    return Reject(vector, planeNormal);
}


Vector3 Vector3::Reject(Vector3 a, Vector3 b)
{
    return a - Project(a, b);
}


Vector3 Vector3::Scale(Vector3 a, Vector3 b)
{
    return Vector3(a.X * b.X, a.Y * b.Y, a.Z * b.Z);
}


Vector3 Vector3::SlerpUnclamped(Vector3 a, Vector3 b, float t)
{
    float magA = Magnitude(a);
    float magB = Magnitude(b);
    a /= magA;
    b /= magB;
    float dot = Dot(a, b);
    dot = fmax(dot, -1.0);
    dot = fmin(dot, 1.0);
    float theta = acos(dot) * t;
    Vector3 relativeVec = Normalized(b - a * dot);
    Vector3 newVec = a * cos(theta) + relativeVec * sin(theta);
    return newVec * (magA + (magB - magA) * t);
}

float Vector3::SqrMagnitude(Vector3 v)
{
    return v.X * v.X + v.Y * v.Y + v.Z * v.Z;
}


struct Vector3& Vector3::operator+=(const float rhs)
{
    X += rhs;
    Y += rhs;
    Z += rhs;
    return *this;
}

struct Vector3& Vector3::operator-=(const float rhs)
{
    X -= rhs;
    Y -= rhs;
    Z -= rhs;
    return *this;
}

struct Vector3& Vector3::operator*=(const float rhs)
{
    X *= rhs;
    Y *= rhs;
    Z *= rhs;
    return *this;
}

struct Vector3& Vector3::operator/=(const float rhs)
{
    X /= rhs;
    Y /= rhs;
    Z /= rhs;
    return *this;
}

struct Vector3& Vector3::operator+=(const Vector3 rhs)
{
    X += rhs.X;
    Y += rhs.Y;
    Z += rhs.Z;
    return *this;
}

struct Vector3& Vector3::operator-=(const Vector3 rhs)
{
    X -= rhs.X;
    Y -= rhs.Y;
    Z -= rhs.Z;
    return *this;
}


Vector3 operator-(Vector3 rhs) { return rhs * -1; }
Vector3 operator+(Vector3 lhs, const float rhs) { return lhs += rhs; }
Vector3 operator-(Vector3 lhs, const float rhs) { return lhs -= rhs; }
Vector3 operator*(Vector3 lhs, const float rhs) { return lhs *= rhs; }
Vector3 operator/(Vector3 lhs, const float rhs) { return lhs /= rhs; }
Vector3 operator+(const float lhs, Vector3 rhs) { return rhs += lhs; }
Vector3 operator-(const float lhs, Vector3 rhs) { return rhs -= lhs; }
Vector3 operator*(const float lhs, Vector3 rhs) { return rhs *= lhs; }
Vector3 operator/(const float lhs, Vector3 rhs) { return rhs /= lhs; }
Vector3 operator+(Vector3 lhs, const Vector3 rhs) { return lhs += rhs; }
Vector3 operator-(Vector3 lhs, const Vector3 rhs) { return lhs -= rhs; }

bool operator==(const Vector3 lhs, const Vector3 rhs)
{
    return lhs.X == rhs.X && lhs.Y == rhs.Y && lhs.Z == rhs.Z;
}

bool operator!=(const Vector3 lhs, const Vector3 rhs)
{
    return !(lhs == rhs);
}