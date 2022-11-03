//implementation of the Ray class
#include "Ray.h"


//constructors
Ray::Ray() {
    origin = Vector3();
    direction = Vector3();
}
Ray::Ray(Vector3 origin, Vector3 direction, int pixelIndex) {
    this->origin = origin;
    this->direction = direction;
    this->pixelIndex = pixelIndex;

    bounces = 0;
    distance = 0;
}

Ray::~Ray() {}

//getters
Vector3 Ray::getOrigin() const {
    return origin;
}
Vector3 Ray::getDirection() const {
    return direction;
}
//setters
void Ray::setOrigin(Vector3 origin) {
    this->origin = origin;
}
void Ray::setDirection(Vector3 direction) {
    this->direction = direction;
}

//advance ray
void Ray::advance(float distance) {
    origin = origin + direction * distance;
    this->distance += distance;
}
//reflect ray
void Ray::reflect(Vector3 normal, float diffuse) {
    //get random vector3
    Vector3 randomVector = Vector3(rand() % 1000, rand() % 1000, rand() % 1000);
    randomVector.normalize();

    direction = direction - normal * 2 * direction.dot(normal);

    direction.normalize();
    //add random vector to mimic diffuse reflection
    direction = direction + randomVector * diffuse;
    direction.normalize();
}
//refract ray
void Ray::refract(Vector3 normal, float n1, float n2) {
    float n = n1 / n2;
    float cosI = -normal.dot(direction);
    float sinT2 = n * n * (1.0 - cosI * cosI);
    if (sinT2 > 1.0) {
        //total internal reflection
        reflect(normal, 0);
    }
    else {
        float cosT = sqrt(1.0 - sinT2);
        direction = direction * n + normal * (n * cosI - cosT);
    }
}
//increment bounces
void Ray::incrementBounces() {
    bounces++;
}
//check for intersection with objects in scene
void Ray::traceRay(std::vector<Object*> objects) {
    float minDistance = 1000000;
    int minIndex = -1;
    for (int k = 0; k < objects.size(); k++) {
        float distance = objects[k]->checkIntersection(*this);//TODO: should this be by reference?

        ////std::cout << distance << std::endl;
        if (distance > 0 && distance < minDistance) {
            minDistance = distance;
            minIndex = k;
        }
    }
    
    if (minIndex != -1){
        advance(minDistance);
        objectsHit.push_back(objects[minIndex]);
        //std::cout<<"min obj type "<<objects[minIndex]->getType()<<" bounces "<<bounces<<std::endl;
        // if object is a light or bounce limit is reached, return
        if (objects[minIndex]->getType() == "light" || bounces >= 30) {
            //std::cout<<"hit light"<<std::endl;
            return ;
        }
        //std::cout<<"minDistance: "<<minDistance<<" minIndex: "<<minIndex<<std::endl;
    
        Vector3 pointOfIntersection = origin;

        //get normal at point of intersection
        Vector3 normal = objects[minIndex]->getNormal(pointOfIntersection);

        //get material properties of object
        float reflectiveCoefficient = objects[minIndex]->getReflectionCoefficient();
        float transmissionCoefficient = objects[minIndex]->getTransmissionCoefficient();
        float diffuseCoefficient = objects[minIndex]->getDiffuseCoefficient();

        bool reflect = true;
        if (reflectiveCoefficient > 0 && transmissionCoefficient > 0){
            float random = (float)rand();
            float probability = reflectiveCoefficient / (reflectiveCoefficient + transmissionCoefficient);
            if (random > probability){
                reflect = false;
            }
        }
        //std::cout<<reflectiveCoefficient<<"rr"<< reflect<<std::endl;
        if (reflectiveCoefficient > 0 && reflect) {
            //reflect ray
            //std::cout<<"reflect"<<std::endl;
            this->reflect(normal, diffuseCoefficient);
            
            incrementBounces();
            //call traceRay function again
            return traceRay(objects);
        }
        else if (transmissionCoefficient > 0) {
            //refract ray (this is not working yet)
            refract(normal, currentRefractiveIndex, objects[minIndex]->getRefractiveIndex());
            
            incrementBounces();
            //call traceRay function again
            return traceRay(objects);
        }
    }
    else {
        //cout here
        ////std::cout<<"no intersection"<<std::endl;
        return ;
    }
}

//update ray color
Vector3 Ray::getColor() {
    //pop the last item off objectsHit vector until it is empty
    //add the color of the object to the color of the ray and divide by the number of objects hit
    int numObjectsHit = objectsHit.size();
    //return the color of the ray
    Vector3 color = Vector3(0, 0, 0);
    // if last object is not a light, return black
    if (numObjectsHit == 0){
        return color;
    }
    //print all objects hit
    ////std::cout<<"objects hit: "<<std::endl;
    // for (int i = 0; i < numObjectsHit; i++){
    //     //std::cout<<objectsHit[i]->getType()<<std::endl;
    // }
    if (objectsHit.back()->getType() != "light") {
        ////std::cout<<"not a light: "<<objectsHit.back()->getType()<<std::endl;
        return color;
    }
    while (!objectsHit.empty()) {
        ////std::cout<<"type"<<objectsHit.back()->getType()<<std::endl;
        color = color + objectsHit.back()->getColor();
        objectsHit.pop_back();
    }
    return color/numObjectsHit;
}


//trace ray
//recursive function that advances ray through scene
//TODO how to deal with refracted rays traveling inside objects (i.e. how to get intersection points, refraction is from n2 to n1 as well)



