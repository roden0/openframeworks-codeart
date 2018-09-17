#ifndef CIRCLE_H
#define CIRCLE_H

#include "ofMain.h"

class Circle {
	public:
		Circle();

		void setup(int _x, int _y);
		void update();
		void display();

		void superp(const vector <Circle *> circles);

		int x;
		int y;

		float radius;
		float radioMax;
		float tasaCrec;

		bool esRadioMax;
		bool esSuperpuesto;

		ofColor c;
};

#endif  
