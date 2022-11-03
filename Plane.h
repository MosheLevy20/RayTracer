//header for Plane class which inherits from Object class
//include standard libraries
#ifndef PLANE_H
#define PLANE_H


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

public:
    //constructors
    Plane();
    Plane(Vector3 position, Vector3 normal, Vector3 color, float diffuseCoefficient, float refractiveIndex, float reflectionCoefficient, float transmissionCoefficient);
    ~Plane();
    //getters
    Vector3 getNormal(Vector3 point);
    //check for intersection with ray
    float checkIntersection(Ray ray);
    //type
    std::string getType();

};

#endif

