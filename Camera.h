//header for Camera class
//include standard libraries
#ifndef CAMERA_H
#define CAMERA_H
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
//include my classes
#include "Vector3.h"
#include "Ray.h"
#include "Object.h"

class Camera
{
private:
    //some of these variables are not used but are included for future use
    //position of camera
    Vector3 position;
    //direction of camera
    Vector3 direction;
    //up vector of camera
    Vector3 up;
    //right vector of camera
    Vector3 right;

    float fieldOfView;

    float nearPlane;

    float farPlane;

    float width;
    float height;
 
    int pixelWidth;
    int pixelHeight;
 
    float pixelSize;
    int pixelCount;

    //pixel array of camera
    //std::vector<Vector3> pixelArray;

    
    //private methods

    //get x of pixel
    float getXoPix(int pixel);
    //get y of pixel
    float getYoPix(int pixel);


    
public:
    //constructors
    Camera();
    Camera(Vector3 position, Vector3 direction, Vector3 up, float fieldOfView, float nearPlane, float farPlane, float pixelWidth, float pixelHeight, float pixelSize);
    ~Camera();
    
    //getters

    Vector3 getPosition();
 
    Vector3 getDirection();

    Vector3 getUp();

    Vector3 getRight();

    float getFieldOfView();

    float getAspectRatio();

    float getNearPlane();

    float getFarPlane();

    float getWidth();

    float getHeight();
    
    int getPixelWidth();

    int getPixelHeight();
 
    float getPixelSize();

    int getPixelCount();
    
    //setters
   
    void setPosition(Vector3 position);

    void setDirection(Vector3 direction);

    void setUp(Vector3 up);
  
    void setRight(Vector3 right);
 
    void setFieldOfView(float fieldOfView);
   
    void setAspectRatio(float aspectRatio);

    void setNearPlane(float nearPlane);
  
    void setFarPlane(float farPlane);

    void setWidth(float width);

    void setHeight(float height);

    void setPixelWidth(float pixelWidth);

    void setPixelHeight(float pixelHeight);
    
    //other methods
    //get ray from pixel
    Ray getRayFromPixel(int pixel);
};

#endif