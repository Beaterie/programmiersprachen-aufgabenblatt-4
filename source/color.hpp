#ifndef COLOR_HPP
#define COLOR_HPP
#include <iostream>

struct Color{

	//default-Konstruktor
	Color():
	r{0.0f},
	g{0.0f},
	b{0.0f}
	{}

	//Konstruktor mit einer Werteingabe
	Color(float r):
	r{r}, g{r}, b{r}
	{	//Fehlermeldung bei ungültigem Wert
		if (r > 1 || r < 0){
        	throw std::out_of_range("WARNUNG: Der eingegebene Wert darf nur zwischen 0 und 1 liegen!");
		}
	}

	//Konstruktor mit drei Werteingaben
	Color(float r, float g, float b):
	r{r},
	g{g},
	b{b}
	{	//Fehlermeldung bei ungültigen Werten
		if (r > 1 || r < 0){
			throw std::out_of_range("WARNUNG: Der Wert für 'r' darf nur zwischen 0 und 1 liegen!");
		}
		if (g > 1 || g < 0){
			throw std::out_of_range("WARNUNG: Der Wert für 'g' darf nur zwischen 0 und 1 liegen!");
		}
		if (b > 1 || b < 0){
			throw std::out_of_range("WARNUNG: Der Wert für 'b' darf nur zwischen 0 und 1 liegen!");
		}
	}

	float r;
	float g;
	float b;
};

#endif // COLOR_HPP