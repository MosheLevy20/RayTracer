//implementation of the Ray class
//include standard libraries
#include <iostream>
#include <cmath>
//include my classes
#include "Vector3.h"
#include "Ray.h"

//constructors
Ray::Ray() {
    origin = Vector3();
    direction = Vector3();
}
Ray::Ray(Vector3 origin, Vector3 direction, Vector3 color, int pixelIndex) {
    this->origin = origin;
    this->direction = direction;
    this->pixelIndex = pixelIndex;
}

Ray::~Ray() {}

//accessors
Vector3 Ray::getOrigin() const {
    return origin;
}
Vector3 Ray::getDirection() const {
    return direction;
}
//mutators
void Ray::setOrigin(Vector3 origin) {
    this->origin = origin;
}
void Ray::setDirection(Vector3 direction) {
    this->direction = direction;
}
//private methods
//advance ray
void Ray::advance(float distance) {
    origin = origin + direction * distance;
    this->distance += distance;
}
//reflect ray
void Ray::reflect(Vector3 normal) {
    direction = direction - normal * 2 * direction.dot(normal);
}
//refract ray
void Ray::refract(Vector3 normal, float n1, float n2) {
    float n = n1 / n2;
    float cosI = -normal.dot(direction);
    float sinT2 = n * n * (1.0 - cosI * cosI);
    if (sinT2 > 1.0) {
        //total internal reflection
        reflect(normal);
    }
    else {
        float cosT = sqrt(1.0 - sinT2);
        direction = direction * n + normal * (n * cosI - cosT);
    }
}
//check for intersection with objects in scene
void Ray::checkIntersection(std::vector<Object*> objects, int& objectIndex) {
    float minDistance = 1000000;
    int tempIndex = -1;
    for (int i = 0; i < objects.size(); i++) {
        float distance = objects[i]->intersect(*this);
        if (distance > 0 && distance < minDistance) {
            minDistance = distance;
            tempIndex = i;
        }
    }
    if (tempIndex != -1){
        objectIndex = tempIndex;
        advance(minDistance);
    }
}
//update ray color
void Ray::updateColor(Vector3 color, float coefficient1, float coefficient2) {
    this->color = this->color * coefficient1 + color * coefficient2;
}



