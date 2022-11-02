//header for Object class
//include standard libraries
#include <iostream>
#include <cmath>
#include <vector>

//include my classes
#include "Vector3.h"
class Ray;
//since Ray.h includes Object.h, i can't include Object.h in Ray.h, what do i do?
//i can't include Object.h in Ray.h because it will cause a circular dependency
//therefore, i have to include Object.h in Ray.h and Sphere.h and Plane.h
//but i can't include Ray.h in Object.h because it will cause a circular dependency
//the solution is to forward declare the Ray class
//this is done by including the following line in Object.h
//class Ray;
//this is called a forward declaration
//this tells the compiler that the Ray class exists
//but it doesn't know anything about the Ray class
//this is enough for the compiler to compile the Object class

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

    virtual float checkIntersection(Ray ray);
    //get normal at point of intersection
    virtual Vector3 getNormal(Vector3 point) = 0;
    //returns type of object
    virtual std::string getType() = 0;
    //getIntensity
    

};
