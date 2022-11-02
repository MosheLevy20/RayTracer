//header for Sphere class which inherits from Object class
//include standard libraries
#ifndef SPHERE_H
#define SPHERE_H
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
//include my classes
#include "Vector3.h"
#include "Ray.h"
#include "Object.h"

class Ray;

class Sphere : public Object
{
private:
    //radius of sphere
    float radius;
    

public:
    //constructors
    Sphere();
    Sphere(Vector3 position, Vector3 color, float radius, float diffuseCoefficient, float refractiveIndex, float reflectionCoefficient, float transmissionCoefficient);
    ~Sphere();

    float checkIntersection(Ray ray);
    //get normal at point of intersection
    Vector3 getNormal(Vector3 point);
    //type
    std::string getType();
};
#endif