#include "vec2.hpp"
#include <iostream>
#include <math.h>

//Standardwerte für Vektor
Vec2::Vec2():
	x{0.0f},
	y{0.0f}
	{}

//Vektor auf Basis der Eingabeparameter
Vec2::Vec2(float x, float y):
	x{x},
	y{y}
	{}

//Addition=
Vec2& Vec2::operator+=(Vec2 const& v){
	x = x + v.x;
	y = y + v.y;
	return *this;
}

//Subtraktion=
Vec2& Vec2::operator-=(Vec2 const& v){
	x = x - v.x;
	y = y - v.y;
	return *this;
}

//Mulitplikation mit einer Zahl=
Vec2& Vec2::operator*=(float v){
	x = x*v;
	y = y*v;
	return *this;
}

//Division durch eine Zahl=
Vec2& Vec2::operator/=(float v){
	if (v == 0.0f){
		std::cout << "WARNUNG: Division durch '0' " <<
		"ist nicht erlaubt!" << std::endl;
		return *this;
	}
	else {
		x = x/v;
		y = y/v;
		return *this;
	}
}

//Addition zweier Vektoren
Vec2 operator+(Vec2 const& u, Vec2 const& v){
	Vec2 w{};
	w.x = u.x + v.x;
	w.y = u.y + v.y;
	return w;
}

//Subtraktion zweier Vektoren
Vec2 operator-(Vec2 const& u, Vec2 const& v){
	Vec2 w{};
	w.x = u.x - v.x;
	w.y = u.y - v.y;
	return w;
}

//Multiplikation eines Vektors mit einer Zahl
Vec2 operator*(Vec2 const& u, float s){
	Vec2 w{};
	w.x = u.x * s;
	w.y = u.y * s;
	return w;
}

//Division eines Vektors durch eine Zahl
Vec2 operator/(Vec2 const& u, float s){
	if (s == 0.0f){
		std::cout << "WARNUNG: Division durch '0' " <<
		"ist nicht erlaubt!" << std::endl;
	}
	else{
		Vec2 w{};
		w.x = u.x / s;
		w.y = u.y / s;
		return w;
	}
}

//Multiplikation einer Zahl mit einem Vektor
Vec2 operator*(float s, Vec2 const& u){
	Vec2 w{};
	w.x = u.x * s;
	w.y = u.y * s;
	return w;
}

//Distanz zwischen zwei Punkten über deren Vektoren
float distance(Vec2 const& u, Vec2 const& v){
	return sqrt((u.x-v.x)*(u.x-v.x) + (u.y-v.y)*(u.y-v.y));
}