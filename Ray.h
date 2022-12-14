//header file for ray class
//include standard libraries
#ifndef RAY_H
#define RAY_H

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
//include Vector3 class
#include "Vector3.h"
#include "Object.h"

class Ray
{
private:
    Vector3 origin;
    Vector3 direction;
    Vector3 color;

    //pixel that this ray is associated with
    int pixelIndex;

    //distance traveled
    float distance;

    //number of bounces
    int bounces;

    //vector of all the objects the ray has hit
    std::vector<Object*> objectsHit;

    float currentRefractiveIndex;

 

public:
    Ray();
    Ray(Vector3 origin, Vector3 direction, int pixelIndex);
    ~Ray();
    //getters
    Vector3 getOrigin() const;
    Vector3 getDirection() const;
    
    int getPixelIndex() const;
    //get reflection count
    int getBounces() const;
    //this function should calculate the color of the ray based on the objects it has hit and the light it has hit
    Vector3 getColor();

    //setters
    void setOrigin(Vector3 origin);
    void setDirection(Vector3 direction);
    void setColor(Vector3 color);


    void traceRay(std::vector<Object*> objects);

    void advance(float distance);

    void reflect(Vector3 normal, float diffuse);

    void refract(Vector3 normal, float n1, float n2);

   
    void incrementBounces();

    

};
#endif