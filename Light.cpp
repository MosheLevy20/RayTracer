//implementation of the Light class
#include "Light.h"

//constructors
Light::Light()
{
    //set position to origin
    this->setPosition(Vector3());
    //set color to white
    this->setColor(Vector3(1, 1, 1));
    //set intensity to 1
    this->intensity = 1;
    //set size to 1
    this->size = 1;

}

Light::Light(Vector3 position, Vector3 color, float size, float intensity)
{
    //set position
    this->setPosition(position);
    //set color
    this->setColor(color);
    //set intensity
    this->intensity = intensity;
    //set size
    this->size = size;
}

//destructor
Light::~Light()
{
    //do nothing
}

//private methods
//check for intersection with ray
float Light::checkIntersection(Ray ray)
{
    //treat the light as a sphere
    //get ray origin
    Vector3 rayOrigin = ray.getOrigin();
    //get ray direction
    Vector3 rayDir = ray.getDirection();
    //get sphere position
    Vector3 spherePosition = this->getPosition();
    //get sphere radius
    float sphereRadius = size;

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
        return 1;
    }

}

//type
std::string Light::getType()
{
    return "light";
}

