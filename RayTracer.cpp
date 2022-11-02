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
#include "Camera.h"
//#include "RayTracer.h"

//which parts of this project still need to be done?



//TODO make reflections random depending on diffuse coefficient
int main() {
  //create vector of objects in scene
  std::vector<Object*> objects;
  
  //create 2 spheres, one transparent and one reflective


  //create 6 planes as walls of room, floor, and ceiling
  
  
  //add 1 light on ceiling



  //add objects to vector
  objects.push_back(&sphere1);
  objects.push_back(&sphere2);

  objects.push_back(&plane1);
  objects.push_back(&plane2);
  objects.push_back(&plane3);
  objects.push_back(&plane4);
  objects.push_back(&plane5);
  objects.push_back(&plane6);

  objects.push_back(&light1);

  //create camera
  Vector3 cameraPosition(0, 0, 0);
  Vector3 cameraDirection(0, 0, 1);
  Vector3 cameraUp(0, 1, 0);
  float cameraFOV = 90;
  float cameraNearPlane = 1;
  float cameraFarPlane = 100;
  float cameraPixelWidth = 1;
  float cameraPixelHeight = 1;
  float cameraPixelSize = 1;
  Camera camera(cameraPosition, cameraDirection, cameraUp, cameraFOV, cameraNearPlane, cameraFarPlane, cameraPixelWidth, cameraPixelHeight, cameraPixelSize);

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
      Ray currentRay = camera.getRayFromPixel(i*camera.getPixelWidth()+j);
      currentRay.traceRay(objects);

    }
  }





  return 0;
}




//save snapshots to png file
void saveSnapshotsToFile(std::string fileName, int snapshot){
    //create file
    std::ofstream file(fileName);
    //write header
    file << "P3 " << pixelWidth << " " << pixelHeight << " 255" << std::endl;
    //write pixel data
    for (int i = 0; i < pixelCount; i++){
        file << (int)(snapshots[snapshot][i].getX() * 255) << " " << (int)(snapshots[snapshot][i].getY() * 255) << " " << (int)(snapshots[snapshot][i].getZ() * 255) << std::endl;
    }
    //close file
    file.close();
}

//save snapshots to mp4 video file
void saveSnapshotsToVideo(std::string fileName, int fps){
    //create file
    std::ofstream file(fileName);
    //write header for mp4 file
    file << "ffmpeg -r " << fps << " -f image2 -s " << pixelWidth << "x" << pixelHeight << " -i " << fileName << "%d.png -vcodec libx264 -crf 25  -pix_fmt yuv420p " << fileName << ".mp4" << std::endl;
    //write pixel data for each snapshot to mp4 file
    for (int i = 0; i < snapshots.size(); i++){
        //write header for png file
        file << "P3 " << pixelWidth << " " << pixelHeight << " 255" << std::endl;
        //write pixel data for png file
        for (int j = 0; j < pixelCount; j++){
            file << (int)(snapshots[i][j].getX() * 255) << " " << (int)(snapshots[i][j].getY() * 255) << " " << (int)(snapshots[i][j].getZ() * 255) << std::endl;
        }
        //save png file
        file << "mv " << fileName << i << ".png " << fileName << i << ".png" << std::endl;
    }
    //close file
    file.close();
}

//to compile this project in terminal, type:
// g++ -std=c++11 -o RayTracer RayTracer.cpp Vector3.cpp Ray.cpp Object.cpp Sphere.cpp Plane.cpp Light.cpp Camera.cpp
//to run this project in terminal, type:
// ./RayTracer