//header for Light class which inherits from Object class
//include standard libraries
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
//include my classes
#include "Vector3.h"
#include "Ray.h"
#include "Object.h"

class Light : public Object
{
private:
    //private methods
    //check for intersection with ray
    bool checkIntersection(Ray ray, float& distance);
    //get normal at point of intersection
    Vector3 getNormal(Vector3 point);
    //get point of intersection is not needed for light but must be defined
    Vector3 getPointOfIntersection(Ray ray);

public:
    //constructors
    Light();
    Light(Vector3 position, Vector3 color);
    ~Light();
};