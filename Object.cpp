//implementations of the Object class
//include standard libraries
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
//include my classes
#include "Vector3.h"
#include "Ray.h"
#include "Object.h"

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

