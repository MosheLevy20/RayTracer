//header for Light class which inherits from Object class
//include standard libraries
#ifndef LIGHT_H
#define LIGHT_H
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
    float checkIntersection(Ray ray);
    //get normal at point of intersection
    Vector3 getNormal(Vector3 point);
    //get point of intersection is not needed for light but must be defined
    Vector3 getPointOfIntersection(Ray ray);

    //size of light
    float size;
    //intensity of light
    float intensity;

public:
    //constructors
    Light();
    Light(Vector3 position, Vector3 color, float size, float intensity);
    ~Light();

    //getters
    float getSize();
    float getIntensity();


    //type
    std::string getType();
};

#endif