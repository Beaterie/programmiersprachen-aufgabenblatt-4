#ifndef VEC2_HPP
#define VEC2_HPP
#include <math.h>
// Vec2 class definition
class Vec2{
public:
	Vec2();
	Vec2(float x, float y);

	Vec2& operator+=(Vec2 const& v);
	Vec2& operator-=(Vec2 const& v);
	Vec2& operator*=(float v);
	Vec2& operator/=(float v);

	float x;
	float y;
};

Vec2 operator+(Vec2 const& u, Vec2 const& v);
Vec2 operator-(Vec2 const& u, Vec2 const& v);
Vec2 operator*(Vec2 const& v, float s);
Vec2 operator/(Vec2 const& v, float s);
Vec2 operator*(float s, Vec2 const& v);
float distance(Vec2 const& u, Vec2 const& v);	//Abstand zweier Punkte

#endif // VEC2_HPP