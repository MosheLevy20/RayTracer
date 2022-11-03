//implementation of the Sphere class
#include "Sphere.h"

//constructors
//default constructor
Sphere::Sphere()
{
    this->setPosition(Vector3());
    this->setColor(Vector3());
    this->radius = 0;
    this->setDiffuseCoefficient(0);
    this->setRefractiveIndex(0);
    this->setReflectionCoefficient(0);
    this->setTransmissionCoefficient(0);

}

//constructor with parameters
Sphere::Sphere(Vector3 position, Vector3 color, float radius, float diffuseCoefficient, float refractiveIndex, float reflectionCoefficient, float transmissionCoefficient)
{
    this->setPosition(position);
    this->setColor(color);
    this->radius = radius;
    this->setDiffuseCoefficient(diffuseCoefficient);
    this->setRefractiveIndex(refractiveIndex);
    this->setReflectionCoefficient(reflectionCoefficient);
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
    Vector3 rayOrigin = ray.getOrigin();
    Vector3 rayDir = ray.getDirection();
    Vector3 spherePosition = this->getPosition();
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
    Vector3 spherePosition = this->getPosition();
    //get normal
    Vector3 normal = point - spherePosition;
    normal.normalize();
    return normal;
}

//type
std::string Sphere::getType()
{
    return "sphere";
}