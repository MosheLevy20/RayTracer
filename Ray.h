//header file for ray class
//include standard libraries
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
//include Vector3 class
#include "Vector3.h"
//if not defined
#ifndef OBJECT_H //TODO does this work?
#include "Object.h"
#endif

class Ray
{
private:
    Vector3 origin;
    Vector3 direction;

    //color of ray
    Vector3 color;

    int pixelIndex;

    //distance traveled
    float distance;

    //number of bounces
    int bounces;

    //vector of all the objects the ray has hit
    std::vector<Object*> objectsHit;





public:
    Ray();
    Ray(Vector3 origin, Vector3 direction, int pixelIndex);
    ~Ray();
    //accessors
    Vector3 getOrigin() const;
    Vector3 getDirection() const;
    Vector3 getColor() const;
    int getPixelIndex() const;
    //get reflection count
    int getBounces() const;


    //mutators
    void setOrigin(Vector3 origin);
    void setDirection(Vector3 direction);
    void setColor(Vector3 color);

    //trace ray
    void traceRay(std::vector<Object*> objects);
    //advance ray
    void advance(float distance);
    //reflect ray
    void reflect(Vector3 normal);
    //refract ray
    void refract(Vector3 normal, float n1, float n2);

    //update ray color
    void updateColor(Vector3 color, float coefficient1, float coefficient2);

    

};
