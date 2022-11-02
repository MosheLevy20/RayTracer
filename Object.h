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
    virtual bool checkIntersection() = 0;
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
    

};
