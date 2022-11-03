//header for Object class
//include standard libraries
#ifndef OBJECT_H
#define OBJECT_H 
#include <iostream>
#include <cmath>
#include <vector>
#include <string>

//include my classes
#include "Vector3.h"
//#include "Ray.h"
class Ray;

class Object
{
private:
    Vector3 position;
    Vector3 color;


    float diffuseCoefficient;
    float refractiveIndex;
    float reflectionCoefficient;
    float transmissionCoefficient;


public:
    Object();
    Object(Vector3 position, Vector3 color, float diffuseCoefficient, float refractiveIndex, float reflectionCoefficient, float transmissionCoefficient);
    Object(Vector3 position, Vector3 Normal, Vector3 color, float diffuseCoefficient, float refractiveIndex, float reflectionCoefficient, float transmissionCoefficient);
    ~Object();
    
    //setters
    void setPosition(Vector3 position);
    void setColor(Vector3 color);
    void setDiffuseCoefficient(float diffuseCoefficient);
    void setRefractiveIndex(float refractiveIndex);
    void setReflectionCoefficient(float reflectionCoefficient);
    void setTransmissionCoefficient(float transmissionCoefficient);
    float getIntensity();
    //getters
    Vector3 getColor();
    float getRefractiveIndex();
    float getReflectionCoefficient();
    float getTransmissionCoefficient();
    float getDiffuseCoefficient();
    Vector3 getPosition();

    virtual float checkIntersection(Ray ray) = 0;
    //get normal at point of intersection
    virtual Vector3 getNormal(Vector3 point) = 0;
    //returns type of object
    virtual std::string getType() = 0;
};
#endif