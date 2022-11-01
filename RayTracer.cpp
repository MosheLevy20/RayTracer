//Author: Moshe Levy
//main file where objects in scene are specified and ray tracing is performed
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
#include "Plane.h"
#include "Light.h"
#include "RayTracer.h"

//TODO make reflections random depending on diffuse coefficient
int main() {
  //create vector of objects in scene
  std::vector<Object*> objects;
  
  //create spheres
  Sphere sphere1(Vector3(100, 100, 100), Vector3(1, 0, 0), 50, 0.5, 0.5, 1.0, 0.0, 0.0);
  Sphere sphere2(Vector3(200,50,100), Vector3(0, 1, 0), 50, 0.5, 0.5, 1.0, 0.0, 0.0);
  Sphere sphere3(Vector3(300, 100, 100), Vector3(0, 0, 1), 50, 0.5, 0.5, 1.0, 0.0, 0.0);

  //create planes as walls of room TODO this needs to be fixed
  Plane plane1(Vector3(0, 0, 0), Vector3(0, 0, 1), Vector3(0, 1, 0), 0.5, 0.5, 1.0, 0.0, 0.0);
  Plane plane2(Vector3(0, 0, 0), Vector3(1, 0, 0), Vector3(0, 0, 1), 0.5, 0.5, 1.0, 0.0, 0.0);
  Plane plane3(Vector3(0, 0, 200), Vector3(1, 0, 0), Vector3(0, 0, 1), 0.5, 0.5, 1.0, 0.0, 0.0);
  Plane plane4(Vector3(0, 0, 0), Vector3(0, 1, 0), Vector3(1, 0, 0), 0.5, 0.5, 1.0, 0.0, 0.0);
  Plane plane5(Vector3(0, 200, 0), Vector3(0, 1, 0), Vector3(1, 0, 0), 0.5, 0.5, 1.0, 0.0, 0.0);
  Plane plane6(Vector3(0, 0, 0), Vector3(0, 0, 1), Vector3(0, 1, 0), 0.5, 0.5, 1.0, 0.0, 0.0);
  
  //add lights
  Light light1(Vector3(100, 100, 0), Vector3(1, 1, 1));
  Light light2(Vector3(200, 100, 0), Vector3(1, 1, 1));

  //add objects to vector
  objects.push_back(&sphere1);
  objects.push_back(&sphere2);
  objects.push_back(&sphere3);
  objects.push_back(&plane1);
  objects.push_back(&plane2);
  objects.push_back(&plane3);
  objects.push_back(&plane4);
  objects.push_back(&plane5);
  objects.push_back(&plane6);
  objects.push_back(&light1);
  objects.push_back(&light2);

  //create camera
  Vector3 cameraPosition(100, 100, 0);
  Vector3 cameraDirection(0, 0, 1);
  Vector3 cameraUp(0, 1, 0);
  float cameraFOV = 90;
  float cameraNearPlane = 1;
  float cameraFarPlane = 100;
  float cameraPixelWidth = 1;
  float cameraPixelHeight = 1;
  Camera camera(cameraPosition, cameraDirection, cameraUp, cameraFOV, cameraNearPlane, cameraFarPlane, cameraPixelWidth, cameraPixelHeight);

  //run ray tracing algorithm
  //step 1: create ray for each pixel
  //step 2: find intersection of ray with objects in scene
  //step 3: reflect or refract ray based on material properties
  //step 4: repeat steps 2 and 3 until ray intersects a light or reaches max number of reflections
  //step 5: calculate color of pixel based on light intensity
  //step 6: repeat steps 1-5 for each pixel
  //step 7: save image to file

  //loop through pixels 
  for (int i = 0; i < camera.getPixelWidth(); i++) {
    for (int j = 0; j < camera.getPixelHeight(); j++) {
      //create ray for each pixel
      Ray currentRay = camera.createRay(i, j);
      //while ray has not reached max number of reflections
      

    }
  }





  return 0;
}

//recursive function that advances ray through scene
//returns color of pixel
//TODO how to deal with refracted rays traveling inside objects (i.e. how to get intersection points, refraction is from n2 to n1 as well)
Vector3 RayTracer::traceRay(Ray ray) {
  if (currentRay.getBounces() < 5) {
    //find intersection of ray with objects in scene
    //loop through objects in scene
    for (int k = 0; k < objects.size(); k++) {
      //check if ray intersects object
      if (objects[k]->checkIntersection(currentRay)) {
        // if object is a light
        if (objects[k]->getType() == "light") {
          //calculate color of pixel based on light intensity and color
          vector3 pixColor = objects[k]->getColor();
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
  }
  else {
    //return black
    return Vector3(0, 0, 0);
  }
}

//to compile this project in terminal, type:
// g++ -std=c++11 -o RayTracer RayTracer.cpp Vector3.cpp Ray.cpp Object.cpp Sphere.cpp
//to run this project in terminal, type:
// ./RayTracer
