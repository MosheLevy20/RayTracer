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
void Ray::traceRay(std::vector<Object*> objects) {
    float minDistance = 1000000;
    int tempIndex = -1;
    for (int k = 0; k < objects.size(); k++) {
        float distance = objects[k]->checkIntersection(*this);
        if (distance > 0 && distance < minDistance) {
            minDistance = distance;
            tempIndex = k;
        }
    }
    if (tempIndex != -1){
        advance(minDistance);
    

        // if object is a light
        if (objects[k]->getType() == "light") {
            //calculate color of pixel based on light intensity and color
            Vector3 pixColor = objects[k]->getColor();
            //TODO calculate based on colors light has already hit
            pixColor *= objects[k]->getIntensity()/currentRay.getBounces();
            return pixColor;
        }
        //get point of intersection
        Vector3 pointOfIntersection = objects[k]->getPointOfIntersection(currentRay);
        //get normal at point of intersection
        Vector3 normal = objects[k]->getNormal(pointOfIntersection);
        //get color of object
        Vector3 color = objects[k]->getColor();
        //get material properties of object
        float reflectiveCoefficient = objects[k]->getReflectiveCoefficient();
        float transmissionCoefficient = objects[k]->getTransmissionCoefficient();
        //if reflective coefficient is greater than 0, reflect ray
        if (reflectiveCoefficient > 0) {
            //reflect ray
            currentRay.reflect(normal);
            //set ray origin to point of intersection
            currentRay.setOrigin(pointOfIntersection);
            //set ray direction to reflected ray direction
            currentRay.setDirection(currentRay.getDirection());
            //increment reflection count
            currentRay.incrementBounces();
            //call traceRay function again
            return traceRay(currentRay);
        }
        //if reflective coefficient is 0 and refractive coefficient is greater than 0, refract ray
        //if reflective coefficient is greater than 0 and refractive coefficient is greater than 0, create new ray and refract it
        if (reflectiveCoefficient == 0 && transmissionCoefficient > 0) {
            //refract ray
            currentRay.refract(normal);
            //set ray origin to point of intersection
            currentRay.setOrigin(pointOfIntersection);
            //set ray direction to refracted ray direction
            currentRay.setDirection(currentRay.getDirection());
            //increment reflection count
            currentRay.incrementBounces();
            //call traceRay function again
            return traceRay(currentRay);
        }
        else if (reflectiveCoefficient > 0 && transmissionCoefficient > 0) {
            //create new ray
            Ray newRay(pointOfIntersection, currentRay.getDirection());
            //set new ray reflection count to current ray reflection count
            newRay.setBounces(currentRay.getBounces());
            //refract new ray
            newRay.refract(normal);
            //refract ray to exit medium
            newRay.refract(normal);
            //set ray origin to point of intersection
            newRay.setOrigin(pointOfIntersection);
            //call traceRay function again
            return traceRay(newRay);
        }
    }
}

//update ray color
void Ray::updateColor(Vector3 color, float coefficient1, float coefficient2) {
    this->color = this->color * coefficient1 + color * coefficient2;
}


//trace ray
//recursive function that advances ray through scene
//TODO how to deal with refracted rays traveling inside objects (i.e. how to get intersection points, refraction is from n2 to n1 as well)



