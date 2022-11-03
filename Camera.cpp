//implementation of the Camera class

//include header file
#include "Camera.h"


//constructors
//default constructor
Camera::Camera()
{
    position = Vector3(0, 0, 0);
    direction = Vector3(0, 0, 1);

    //set up
    float sinHalfFOV = sin(45.0f / 2.0f);
    up = Vector3(0, sinHalfFOV, 0);
    right = Vector3(sinHalfFOV, 0, 0);
   
    fieldOfView = 90;

    nearPlane = 1;
    farPlane = 100;

    width = 1;
    height = 1;

    pixelWidth = 1;
    pixelHeight = 1;
    pixelSize = 1;
    pixelCount = 1;

    //set pixel array
    // pixelArray = std::vector<Vector3>(1);
    // //set snapshots
    // snapshots = std::vector<std::vector<Vector3>>(1);
}
//constructor with parameters
Camera::Camera(Vector3 position, Vector3 direction, Vector3 up, float fieldOfView, float nearPlane, float farPlane, float pixelWidth, float pixelHeight, float pixelSize)
{
    this->position = position;
    this->direction = direction;
    
    //set up
    float sinHalfFOV = sin(45.0f / 2.0f);
    this->up = up;
    // up *= sin(fieldOfView / 2);
    // //set right
    this->right = direction.cross(up);
    this->right *= sin(fieldOfView / 2);
    this->up *= sin(fieldOfView / 2);
   
    
    this->fieldOfView = fieldOfView;

    this->nearPlane = nearPlane;

    this->farPlane = farPlane;

    this->width = 0;
    this->height = 0;


    this->pixelWidth = pixelWidth;
    this->pixelHeight = pixelHeight;
    this->pixelSize = pixelSize;
    this->pixelCount = pixelWidth * pixelHeight;

    //init pixel array
    //pixelArray = std::vector<Vector3>(pixelCount);
}

//destructor
Camera::~Camera()
{
    //delete pixel array
    //pixelArray.clear();
}


int Camera::getPixelWidth()
{
    return pixelWidth;
}

int Camera::getPixelHeight()
{
    return pixelHeight;
}
//TODO make sure this is correct, and add field of view explicitly (and maybe focus distance)
//get x of pixel
float Camera::getXoPix(int pixel)
{
    return ((pixel % (int)pixelWidth) - pixelWidth / 2);
}
//get y of pixel
float Camera::getYoPix(int pixel)
{
    return ((pixel / (int)pixelWidth) - pixelWidth / 2);
}

//public methods
//get ray from camera
Ray Camera::getRayFromPixel(int pixel)
{
    //get x of pixel
    float x = getXoPix(pixel);
    //get y of pixel
    float y = getYoPix(pixel);
  
    //get direction of ray
    Vector3 direction = this->direction + right * x/50 + up * y/50;//this is very much hacked together right now
    //Vector3 direction = this->direction + right * x *pixelSize + up * y*pixelSize;
    direction.normalize();

    //get position of ray which is the direction projected onto the near plane
    Vector3 position = this->position+right * x/2 + up * y/2;

    //direction.print();

    return Ray(position, direction, pixel);
}
//get pixel array
// std::vector<Vector3> Camera::getPixelArray()
// {
//     return pixelArray;
// }







