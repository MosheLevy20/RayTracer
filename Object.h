//header for Object class
//include standard libraries
#include <iostream>
#include <cmath>
#include <vector>

//include my classes
#include "Vector3.h"

class Object
{
private:
    //position of object
    Vector3 position;

    //color of object
    Vector3 color;

    //diffuse coefficient
    float diffuseCoefficient;

    //refractive index
    float refractiveIndex;

    //reflection coefficient
    float reflectionCoefficient;

    //transmission coefficient
    float transmissionCoefficient;


public:
    virtual bool checkIntersection(Vector3 point, Vector3 rayDir) = 0;
    //get normal at point of intersection
    virtual Vector3 getNormal(Vector3 point) = 0;
    //get point of intersection
    virtual Vector3 getPointOfIntersection() = 0;
    //returns type of object
    virtual std::string getType() = 0;
    //getIntensity
    virtual float getIntensity() = 0;
    //get color
    virtual Vector3 getColor() = 0;
    //get refractive index
    virtual float getRefractiveIndex() = 0;
    //get reflection coefficient
    virtual float getReflectionCoefficient() = 0;
    //get transmission coefficient
    virtual float getTransmissionCoefficient() = 0;
    //get diffuse coefficient
    virtual float getDiffuseCoefficient() = 0;
    //get position
    virtual Vector3 getPosition() = 0;

};
