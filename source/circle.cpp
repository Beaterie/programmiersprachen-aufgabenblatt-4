#include "circle.hpp"
#include <iostream>
#include "vec2.hpp"
#include <math.h>
#include "color.hpp"

//default-Konstruktor
Circle::Circle():
	ctr{},
	radius{1},
	clr{}
	{}

//Konstruktor mit allen Eingabeparametern
Circle::Circle(Vec2 ctr, float radius, Color clr):
	ctr{ctr},
	radius{radius},
	clr{clr}
	{}

//Durchmesser
float Circle::get_diameter() const{
	return radius * 2;
}

//Flächeninhalt
float Circle::get_area() const{
	return radius * radius * M_PI;
} 

//Umfang
float Circle::get_circumference() const{
	return 2 * M_PI * radius;
}

//Setzt neuen Radius
float Circle::set_radius(float newradius){
	radius = newradius;
	return newradius;
}

//Ausgabe des Radius'
float Circle::get_radius() const{
	return radius;
}

//Ausgabe des Stützvektors (Mittelpunkt)
Vec2 Circle::get_center() const{
	return ctr;
}

//Farbwert für r
float Circle::get_color_r() const{
	return clr.r;
}
//Farbwert für g
float Circle::get_color_g() const{
	return clr.g;
}
//Farbwert für b
float Circle::get_color_b() const{
	return clr.b;
}

//Überprüfung ob eingegebener Punkt im Kreis liegt
bool Circle::is_inside(Vec2 const& point){
    if(get_radius() >= distance(get_center(),point)){
    	return true;
    }
    else{
    	return false;
    }
}