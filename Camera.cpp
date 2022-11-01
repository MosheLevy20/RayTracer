//implementation of the Camera class
//include standard libraries
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
//include my classes
#include "Vector3.h"
#include "Ray.h"

//include header file
#include "Camera.h"

//constructors
//default constructor
Camera::Camera()
{
    //set position
    position = Vector3(0, 0, 0);
    //set direction
    direction = Vector3(0, 0, 1);
    //set up
    up = Vector3(0, 1, 0);
    //set right
    right = Vector3(1, 0, 0);
    //set field of view
    fieldOfView = 90;
    //set near plane
    nearPlane = 1;
    //set far plane
    farPlane = 100;
    //set width
    width = 1;
    //set height
    height = 1;
    //set pixel width
    pixelWidth = 1;
    //set pixel height
    pixelHeight = 1;
    //set pixel count
    pixelCount = 1;
    //set pixel array
    pixelArray = std::vector<Vector3>(1);
    //set snapshots
    snapshots = std::vector<std::vector<Vector3>>(1);
}
//constructor with parameters
Camera::Camera(Vector3 position, Vector3 direction, Vector3 up, float fieldOfView, float nearPlane, float farPlane, float pixelWidth, float pixelHeight)
{
    //set position
    this->position = position;
    //set direction
    this->direction = direction;
    //set up
    this->up = up;
    //set right
    this->right = direction.crossProduct(up);
    //set field of view
    this->fieldOfView = fieldOfView;
    //set near plane
    this->nearPlane = nearPlane;
    //set far plane
    this->farPlane = farPlane;
    //set width
    this->width = 2 * nearPlane * tan(fieldOfView / 2);
    //set height
    this->height = width * pixelHeight / pixelWidth;
    //set pixel width
    this->pixelWidth = width / pixelWidth;
    //set pixel height
    this->pixelHeight = height / pixelHeight;
    //set pixel count
    this->pixelCount = pixelWidth * pixelHeight;
    //set pixel array
    pixelArray = std::vector<Vector3>(pixelCount);
    //set snapshots
    snapshots = std::vector<std::vector<Vector3>>(pixelCount);
}

//destructor
Camera::~Camera()
{
    //delete pixel array
    pixelArray.clear();
    //delete snapshots
    snapshots.clear();
}

//private methods
//get pixel width
float Camera::getPixelWidth()
{
    return pixelWidth;
}
//get pixel height
float Camera::getPixelHeight()
{
    return pixelHeight;
}
//TODO make sure this is correct
//get x of pixel
float Camera::getXoPix(int pixel)
{
    return (pixel % (int)pixelWidth) * pixelWidth - width / 2;
}
//get y of pixel
float Camera::getYoPix(int pixel)
{
    return (pixel / (int)pixelWidth) * pixelHeight - height / 2;
}

//public methods
//get ray from camera
Ray Camera::getRay(int pixel)
{
    //get x of pixel
    float x = getXoPix(pixel);
    //get y of pixel
    float y = getYoPix(pixel);
    //get direction of ray
    Vector3 direction = this->direction + right * x + up * y;
    //get position of ray which is the direction projected onto the near plane
    Vector3 position = right * x + up * y + this->position;

    //return ray
    return Ray(position, direction, pixel);
}
//get pixel array
std::vector<Vector3> Camera::getPixelArray()
{
    return pixelArray;
}
//get snapshots
std::vector<std::vector<Vector3>> Camera::getSnapshots()
{
    return snapshots;
}

//add snapshot
void Camera::addSnapshot(std::vector<Vector3> snapshot)
{
    snapshots.push_back(snapshot);
}
//clear snapshots
void Camera::clearSnapshots()
{
    snapshots.clear();
} 
//save snapshots to png file
void Camera::saveSnapshotsToFile(std::string fileName, int snapshot){
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
void Camera::saveSnapshotsToVideo(std::string fileName, int fps){
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



