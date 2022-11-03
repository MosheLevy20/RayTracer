//implementation of the Light class
#include "Light.h"

//constructors
Light::Light()
{
    //set position to origin
    this->setPosition(Vector3());
    //set color to white
    this->setColor(Vector3(1, 1, 1));

    this->intensity = 1;
    this->size = 1;

}

Light::Light(Vector3 position, Vector3 color, float size, float intensity)
{
    this->setPosition(position);
    this->setColor(color);
    this->intensity = intensity;
    this->size = size;
}

//destructor
Light::~Light()
{
    //do nothing
}


//check for intersection with ray
float Light::checkIntersection(Ray ray)
{
    //treat the light as a sphere

    Vector3 rayOrigin = ray.getOrigin();
    Vector3 rayDir = ray.getDirection();
    Vector3 spherePosition = this->getPosition();
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
    //otherwise the light is hit
    else
    {
        return 1;
    }

}

//get normal at point of intersection
Vector3 Light::getNormal(Vector3 point)
{
    Vector3 spherePosition = this->getPosition();
    Vector3 normal = point - spherePosition;
    normal.normalize();

    return normal;
}

//type
std::string Light::getType()
{
    return "light";
}

