//implementation of the Plane class
#include "Plane.h"

//constructors
//default constructor
Plane::Plane()
{
    //set position
    this->setPosition(Vector3());
    //set normal
    this->normal = Vector3();
    //set color
    this->setColor(Vector3());
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
Plane::Plane(Vector3 position, Vector3 normal, Vector3 color, float diffuseCoefficient, float refractiveIndex, float reflectionCoefficient, float transmissionCoefficient)
{
    //set position
    this->setPosition(position);
    //set normal
    this->normal = normal;
    //set color
    this->setColor(color);
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
Plane::~Plane()
{
    //do nothing
}

//public methods

Vector3 Plane::getNormal(Vector3 point)
{
    return normal;
}

//type 
std::string Plane::getType()
{
    return "Plane";
}

float Plane::checkIntersection(Ray ray)
{

    //get ray origin and direction
    Vector3 rayOrigin = ray.getOrigin();
    Vector3 rayDirection = ray.getDirection();
    //get plane position and normal
    Vector3 planePosition = this->getPosition();
    Vector3 planeNormal = this->getNormal(planePosition);
    //get distance from ray origin to plane
    //std::cout<<"plane dots "<< (planePosition - rayOrigin).dot(planeNormal)<<", " << rayDirection.dot(planeNormal) << std::endl;
    float distance = (planePosition - rayOrigin).dot(planeNormal) / rayDirection.dot(planeNormal);
    //if distance is negative, return -1
    //std::cout<<"plane dist "<< distance << std::endl;
    if (distance < 0)
    {
        return -1;
    }
    //otherwise return distance
    return distance;
}

