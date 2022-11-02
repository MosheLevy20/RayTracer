//header for Sphere class which inherits from Object class
//include standard libraries
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
//include my classes
#include "Vector3.h"
#include "Ray.h"
#include "Object.h"

class Sphere : public Object
{
private:
    //radius of sphere
    float radius;

    //private methods
    //check for intersection with ray
    bool checkIntersection(Ray ray);
    //get normal at point of intersection
    Vector3 getNormal(Vector3 point);
    //get point of intersection
    Vector3 getPointOfIntersection(Ray ray);

public:
    //constructors
    Sphere();
    Sphere(Vector3 position, Vector3 color, float radius, float diffuseCoefficient, float refractiveIndex, float reflectionCoefficient, float transmissionCoefficient);
    ~Sphere();
};