//header for Plane class which inherits from Object class
//include standard libraries
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
//include my classes
#include "Vector3.h"
#include "Ray.h"
#include "Object.h"

class Plane : public Object
{
private:
    //normal of plane
    Vector3 normal;

    //private methods
    //check for intersection with ray
    bool checkIntersection(Ray ray, float& distance);
    //get normal at point of intersection
    Vector3 getNormal(Vector3 point);
    //get point of intersection
    Vector3 getPointOfIntersection(Ray ray);

public:
    //constructors
    Plane();
    Plane(Vector3 position, Vector3 color, Vector3 normal, float specularCoefficient, float diffuseCoefficient, float refractiveIndex, float reflectionCoefficient, float transmissionCoefficient);
    ~Plane();
};
