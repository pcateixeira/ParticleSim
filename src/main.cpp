#include <iostream>
#include "vector3d.h"
#include "point3d.h"
#include "particle.h"

using namespace std;

int main() {

	Point3D point1(1,2,3);
	Particle particle1(point1, 50.5);

	cout << particle1 << endl;

	return 0;

}
