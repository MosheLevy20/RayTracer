//implementation of the Camera class

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
    //set pixel size
    pixelSize = 1;
    //set pixel count
    pixelCount = 1;
    //set pixel array
    pixelArray = std::vector<Vector3>(1);
    //set snapshots
    snapshots = std::vector<std::vector<Vector3>>(1);
}
//constructor with parameters
Camera::Camera(Vector3 position, Vector3 direction, Vector3 up, float fieldOfView, float nearPlane, float farPlane, float pixelWidth, float pixelHeight, float pixelSize)
{
    //set position
    this->position = position;
    //set direction
    this->direction = direction;
    //set up
    this->up = up;
    //set right
    this->right = direction.cross(up);
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
    //set pixel size
    this->pixelSize = pixelSize;
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
//TODO make sure this is correct, and add field of view explicitly (and maybe focus distance)
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
Ray Camera::getRayFromPixel(int pixel)
{
    //get x of pixel
    float x = getXoPix(pixel);
    //get y of pixel
    float y = getYoPix(pixel);
    //get direction of ray
    Vector3 direction = this->direction + right * x + up * y;
    //get position of ray which is the direction projected onto the near plane
    Vector3 position = right * x * pixelSize + up * y * pixelSize + this->position;

    //return ray
    return Ray(position, direction, pixel);
}
//get pixel array
// std::vector<Vector3> Camera::getPixelArray()
// {
//     return pixelArray;
// }







