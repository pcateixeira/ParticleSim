#include <iostream>

#include "vector3d.h"
#include "point3d.h"
#include "particle.h"
#include "scene.h"
#include "sceneTest.h"

using namespace std;

int main() {

	Point3D point1(1,2,3);
	// Point3D point1;
	Particle particle1(point1, 50.5);
	// Particle particle1;
//	Scene scene;

	SceneTest sceneTest;

//	cout << particle1 << endl;
//	scene.renderScene();
    sceneTest.drawShit();

	return 0;

}
