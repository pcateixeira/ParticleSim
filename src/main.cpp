#include <iostream>
#include "vector3d.h"
#include "point3d.h"

using namespace std;

int main() {

	Point3D p1(1,2,3), p2(1,1,1), p3(-1,0,0);

	std::cout << p1.toString() << std::endl;

	return 0;

}
