//Author: Moshe Levy
//main file where objects in scene are specified and ray tracing is performed
//include standard libraries
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>
//include my classes
#include "Vector3.h"
#include "Object.h"
#include "Sphere.h"
#include "Plane.h"
#include "Light.h"
#include "Camera.h"
#include "Ray.h"

//#include "RayTracer.h"
//save snapshots to png file
void saveSnapshotsToFile(std::string fileName, std::vector<Vector3> snapshot, int pixelWidth, int pixelHeight) {
  //first print snapshot to std out
  int pixelCount = pixelWidth * pixelHeight;
  // for (int i = 0; i < pixelCount; i++){
  //     std::cout << (int)(snapshot[i].getX() * 255) << " " << (int)(snapshot[i].getY() * 255) << " " << (int)(snapshot[i].getZ() * 255) << std::endl;
  // }
  //create file
  std::ofstream file(fileName);
  //write header
  file << "P3 " << pixelWidth << " " << pixelHeight << " 255" << std::endl;
  //write pixel data
  for (int i = 0; i < pixelCount; i++){
      file << (int)(snapshot[i].getX() * 255) << " " << (int)(snapshot[i].getY() * 255) << " " << (int)(snapshot[i].getZ() * 255) << std::endl;
  }
  file.close();
}

//TODO destructors
int main() {
  //create vector of objects in scene
  std::vector<Object*> objects;
  //what is the refractive index of glass?
  //1.5
  Sphere sphere1(Vector3(50, 10, 100), Vector3(1, 0.5, 0.5), 50, 0.1, 0, 1.0, 0.0);
  Sphere sphere2(Vector3(50, -100, 90), Vector3(1, 0.5, 0.5), 50, 0.1, 0, 1.0, 0.0);
  // Sphere sphere2(Vector3(0, 0, 200), Vector3(1, 1, 1), 50, 0.0, 1.5, 1.0, 0.0);

  //create 6 planes as walls of room, floor, and ceiling
  //what is the plane constructor parameter list?
  //Plane(Vector3 position, Vector3 normal, Vector3 color, float diffuseCoefficient, float refractiveIndex, float reflectionCoefficient, float transmissionCoefficient)
  Plane plane1(Vector3(0, 0, -200), Vector3(0, 0, 1), Vector3(1, 1, 0), 0.9, 0, 1, 0.0);
  Plane plane2(Vector3(0, 0, 200), Vector3(0, 0, -1), Vector3(1, 0, 1), 0.9, 0, 1, 0.0);
  Plane plane3(Vector3(0, -200, 0), Vector3(0, 1, 0), Vector3(1, 1, 1), 0.9, 0, 1, 0.0);
  Plane plane4(Vector3(0, 200, 0), Vector3(0, -1, 0), Vector3(0, 1, 1), 0.9, 0, 1, 0.0);
  Plane plane5(Vector3(-200, 0, 0), Vector3(1, 0, 0), Vector3(0, 0, 1), 0.9, 0, 1, 0.0);
  Plane plane6(Vector3(200, 0, 0), Vector3(-1, 0, 0), Vector3(0, 1, 0), 0.9, 0, 1, 0.0);

  //what is the light constructor parameter list?
  //Light(Vector3 position, Vector3 color, float size, float intensity)
  Light light1(Vector3(350, 0, 0), Vector3(1, 1, 1), 150, 1);

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
  Vector3 cameraDirection(0, -0.5, 1);
  cameraDirection.normalize();
  Vector3 cameraUp(1, 0, 0);
  float cameraFOV = 3.14/8;
  float cameraNearPlane = 1;
  float cameraFarPlane = 100;
  int cameraPixelWidth =512;
  int cameraPixelHeight = 512;
  float cameraPixelSize = 1;
  std::cout << "Progress init: " << 0  << std::endl;
  Camera camera(cameraPosition, cameraDirection, cameraUp, cameraFOV, cameraNearPlane, cameraFarPlane, cameraPixelWidth, cameraPixelHeight, cameraPixelSize);
  
  //snapshots vector
  std::vector<std::vector<Vector3>> snapshots;
  //current snapshot
  std::vector<Vector3> currentSnapshot;

  //run ray tracing algorithm
  //step 1: create rays for each pixel
  //step 2: find intersection of ray with objects in scene
  //step 3: reflect or refract ray based on material properties TODO: refraction
  //step 4: repeat steps 2 and 3 until ray intersects a light or reaches max number of reflections
  //step 5: calculate color of pixel based on light intensity and all reflections and refractions TODO also based on total distance traveled
  //step 6: repeat steps 1-5 for each pixel
  //step 7: save image to file

  //loop through pixels 
  std::cout << "Progress init: " << camera.getPixelWidth() << std::endl;
  for (int i = 0; i < camera.getPixelWidth(); i++) {
    std::cout << "Progress: " << (float)i / (float)camera.getPixelWidth() * 100 << "%" << std::endl;
    for (int j = 0; j < camera.getPixelHeight(); j++) {
      Vector3 rayColor(0, 0, 0);
      //send n rays per pixel
      int n =100;
      for (int k = 0; k < n; k++) {
        Ray currentRay = camera.getRayFromPixel(i*camera.getPixelWidth()+j);
        currentRay.traceRay(objects);
        rayColor += currentRay.getColor();
      }
      currentSnapshot.push_back(rayColor/n);
    }
  }
  snapshots.push_back(currentSnapshot);
  //save snapshots to file
  saveSnapshotsToFile("twoSpheres.txt", currentSnapshot, camera.getPixelWidth(), camera.getPixelHeight());
  saveSnapshotsToFile("twoSpheres.png", currentSnapshot, camera.getPixelWidth(), camera.getPixelHeight());

  return 0;
}





//save snapshots to mp4 video file
// void saveSnapshotsToVideo(std::string fileName, int fps){
//     //create file
//     std::ofstream file(fileName);
//     //write header for mp4 file
//     file << "ffmpeg -r " << fps << " -f image2 -s " << pixelWidth << "x" << pixelHeight << " -i " << fileName << "%d.png -vcodec libx264 -crf 25  -pix_fmt yuv420p " << fileName << ".mp4" << std::endl;
//     //write pixel data for each snapshot to mp4 file
//     for (int i = 0; i < snapshots.size(); i++){
//         //write header for png file
//         file << "P3 " << pixelWidth << " " << pixelHeight << " 255" << std::endl;
//         //write pixel data for png file
//         for (int j = 0; j < pixelCount; j++){
//             file << (int)(snapshots[i][j].getX() * 255) << " " << (int)(snapshots[i][j].getY() * 255) << " " << (int)(snapshots[i][j].getZ() * 255) << std::endl;
//         }
//         //save png file
//         file << "mv " << fileName << i << ".png " << fileName << i << ".png" << std::endl;
//     }
//     //close file
//     file.close();
// }

//to compile this project in terminal, type:
// g++ -std=c++11 -o RayTracer RayTracer.cpp Vector3.cpp Ray.cpp Object.cpp Sphere.cpp Plane.cpp Light.cpp Camera.cpp
//to run this project in terminal, type:
// ./RayTracer