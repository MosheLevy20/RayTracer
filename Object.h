//header for Object class
//include standard libraries
#include <iostream>
#include <cmath>
#include <vector>

//include my classes
#include "Vector3.h"
#include "Ray.h"
class Object
{
private:
    //position of object
    Vector3 position;

    //color of object
    Vector3 color;

    //specular coefficient
    float specularCoefficient;

    //diffuse coefficient
    float diffuseCoefficient;

    //refractive index
    float refractiveIndex;

    //reflection coefficient
    float reflectionCoefficient;

    //transmission coefficient
    float transmissionCoefficient;

    //private methods
    //check for intersection with ray
    virtual bool checkIntersection(Ray ray, float& distance) = 0;

    //get normal at point of intersection
    virtual Vector3 getNormal(Vector3 point) = 0;
    //get point of intersection
    virtual Vector3 getPointOfIntersection(Ray ray) = 0;


public:
    //constructors TODO: all the inherited classes constructors don't have matching parameters
    Object();
    Object(Vector3 position, Vector3 color, float specularCoefficient, float diffuseCoefficient, float refractiveIndex, float reflectionCoefficient, float transmissionCoefficient);
    ~Object();
    //getters
    Vector3 getPosition();
    Vector3 getColor();
    float getSpecularCoefficient();
    float getDiffuseCoefficient();
    float getRefractiveIndex();
    float getReflectionCoefficient();
    float getTransmissionCoefficient();
    //setters
    void setPosition(Vector3 position);
    void setColor(Vector3 color);


}