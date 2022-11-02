//implementations of the Object class
#include "Object.h"
//constructors
Object::Object() {
    position = Vector3();
    color = Vector3();
    diffuseCoefficient = 0;
    refractiveIndex = 0;
    reflectionCoefficient = 0;
    transmissionCoefficient = 0;
}
Object::Object(Vector3 position, Vector3 color, float diffuseCoefficient, float refractiveIndex, float reflectionCoefficient, float transmissionCoefficient) {
    //do nothing
}
Object::Object(Vector3 position, Vector3 Normal , Vector3 color, float diffuseCoefficient, float refractiveIndex, float reflectionCoefficient, float transmissionCoefficient) {
    //do nothing
}
//destructor
Object::~Object() {
    //do nothing
}
//public methods
//getters
Vector3 Object::getPosition()
{
    return position;
}

Vector3 Object::getColor()
{
    return color;
}

float Object::getDiffuseCoefficient()
{
    return diffuseCoefficient;
}

float Object::getRefractiveIndex()
{
    return refractiveIndex;
}

float Object::getReflectionCoefficient()
{
    return reflectionCoefficient;
}

float Object::getTransmissionCoefficient()
{
    return transmissionCoefficient;
}

//setters
void Object::setPosition(Vector3 position)
{
    this->position = position;
}

void Object::setColor(Vector3 color)
{
    this->color = color;
}

void Object::setDiffuseCoefficient(float diffuseCoefficient)
{
    this->diffuseCoefficient = diffuseCoefficient;
}

void Object::setRefractiveIndex(float refractiveIndex)
{
    this->refractiveIndex = refractiveIndex;
}

void Object::setReflectionCoefficient(float reflectionCoefficient)
{
    this->reflectionCoefficient = reflectionCoefficient;
}

void Object::setTransmissionCoefficient(float transmissionCoefficient)
{
    this->transmissionCoefficient = transmissionCoefficient;
}


