#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "vec2.hpp"
#include <math.h>
#include "color.hpp"
// Circle class definition
class Circle{
public:
	Circle();	//default-Konstruktor
	Circle(Vec2 ctr, float radius, Color clr);	//Konstruktor mit allen Eingabeparametern

	float get_diameter() const;				//Rückgabe Durchmesser
	float get_area() const;					//Rückgabe Flächeninhalt
	float get_circumference() const;		//Rückgabe Umfang
	float set_radius(float newradius);		//Eingabe neuer Radius
	float get_radius() const;				//Rückgabe Radius
	Vec2 get_center() const;				//Rückgabe Mittelpunkt
	float get_color_r() const;				//Farb-Getter r
	float get_color_g() const;				//Farb-Getter g
	float get_color_b() const;				//Farb-Getter b

	bool is_inside(Vec2 const& point);		//Überprüfung ob Punkt in Kreis liegt

	Vec2 ctr; //Mittelpunkt durch Vektor
	float radius; //Radius
	Color clr; //Farbe 
};

#endif // CIRCLE_HPP