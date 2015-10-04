#include <iostream>

#include "vector3d.h"
#include "point3d.h"
#include "particle.h"
#include "scene.h"
#include "color.h"

using namespace std;

int main() {

	Point3D point1(1,2,3);
	// Point3D point1;
    ColorRGB color1(1000, -5, 1);
    ColorRGB color2(255, 255, 255);

    color2 = color2 + color1;
    cout << color2.toString() << endl;
	Particle particle1(point1, 50.5, 1);
	// Particle particle1;

	Scene scene;

    //cout << color1.toString() << endl;
    //cout << point1.toString() << endl;
    //cout << particle1.toString() << endl;
    scene.drawScene();

	return 0;

}
