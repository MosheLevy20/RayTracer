//implementation of the Sphere class
//include standard libraries
#include <iostream>
#include <cmath>
#include <vector>
#include <string>

//include my classes
#include "Vector3.h"
#include "Ray.h"
#include "Object.h"
#include "Sphere.h"

//constructors
//default constructor
Sphere::Sphere()
{
    //set position
    this->setPosition(Vector3());
    //set color
    this->setColor(Vector3());
    //set radius
    this->radius = 0;
    //set diffuse coefficient
    this->setDiffuseCoefficient(0);
    //set refractive index
    this->setRefractiveIndex(0);
    //set reflection coefficient
    this->setReflectionCoefficient(0);
    //set transmission coefficient
    this->setTransmissionCoefficient(0);

}

//constructor with parameters
Sphere::Sphere(Vector3 position, Vector3 color, float radius, float diffuseCoefficient, float refractiveIndex, float reflectionCoefficient, float transmissionCoefficient)
{
    //set position
    this->setPosition(position);
    //set color
    this->setColor(color);
    //set radius
    this->radius = radius;
    //set diffuse coefficient
    this->setDiffuseCoefficient(diffuseCoefficient);
    //set refractive index
    this->setRefractiveIndex(refractiveIndex);
    //set reflection coefficient
    this->setReflectionCoefficient(reflectionCoefficient);
    //set transmission coefficient
    this->setTransmissionCoefficient(transmissionCoefficient);
}

//destructor
Sphere::~Sphere()
{
    //do nothing
}

//public methods
//check if ray intersects sphere, returns distance to intersection point if it does, returns -1 if it doesn't
float Sphere::checkIntersection(Ray ray)
{
    //get ray origin
    Vector3 rayOrigin = ray.getOrigin();
    //get ray direction
    Vector3 rayDir = ray.getDirection();
    //get sphere position
    Vector3 spherePosition = this->getPosition();
    //get sphere radius
    float sphereRadius = this->radius;

    //calculate discriminant
    float a = rayDir.dot(rayDir);
    float b = 2 * rayDir.dot(rayOrigin - spherePosition);
    float c = (rayOrigin - spherePosition).dot(rayOrigin - spherePosition) - sphereRadius * sphereRadius;
    float discriminant = b * b - 4 * a * c;

    //if discriminant is less than 0, no intersection
    if (discriminant < 0)
    {
        return -1;
    }
    //if discriminant is 0, one intersection
    else if (discriminant == 0)
    {
        //calculate distance to intersection point
        float distance = -b / (2 * a);
        //return distance
        return distance;
    }
    //if discriminant is greater than 0, two intersections
    else
    {
        //calculate distance to closest intersection point
        //TODO if inside sphere we don't necessarily want the closest intersection point
        float distance = (-b - sqrt(discriminant)) / (2 * a);

        return distance;
    }

}

//get normal at point of intersection
Vector3 Sphere::getNormal(Vector3 point)
{
    //get sphere position
    Vector3 spherePosition = this->getPosition();
    //get normal
    Vector3 normal = point - spherePosition;
    //normalize normal
    normal.normalize();
    return normal;
}

//type
std::string Sphere::getType()
{
    return "sphere";
}