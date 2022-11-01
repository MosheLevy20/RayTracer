//header for Camera class
//include standard libraries
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
//include my classes
#include "Vector3.h"
#include "Ray.h"

class Camera
{
private:
    //position of camera
    Vector3 position;
    //direction of camera
    Vector3 direction;
    //up vector of camera
    Vector3 up;
    //right vector of camera
    Vector3 right;
    //field of view of camera
    float fieldOfView;
    //near plane of camera
    float nearPlane;
    //far plane of camera
    float farPlane;
    //width of camera
    float width;
    //height of camera
    float height;
    //pixel width of camera
    float pixelWidth;
    //pixel height of camera
    float pixelHeight;
    //pixel count of camera
    int pixelCount;
    //pixel array of camera
    std::vector<Vector3> pixelArray;
    //snapshots of camera
    std::vector<std::vector<Vector3>> snapshots;

    
    //private methods
    //get pixel width
    float getPixelWidth();
    //get pixel height
    float getPixelHeight();
    //get x of pixel
    float getXoPix(int pixel);
    //get y of pixel
    float getYoPix(int pixel);


    
public:
    //constructors
    Camera();
    Camera(Vector3 position, Vector3 direction, Vector3 up, float fieldOfView, float nearPlane, float farPlane, float pixelWidth, float pixelHeight);
    ~Camera();
    
    //getters
    //get position
    Vector3 getPosition();
    //get direction
    Vector3 getDirection();
    //get up
    Vector3 getUp();
    //get right
    Vector3 getRight();
    //get field of view
    float getFieldOfView();
    //get aspect ratio
    float getAspectRatio();
    //get near plane
    float getNearPlane();
    //get far plane
    float getFarPlane();
    //get width
    float getWidth();
    //get height
    float getHeight();
    //get pixel width
    float getPixelWidth();
    //get pixel height
    float getPixelHeight();
    //get pixel size
    float getPixelSize();
    //get pixel count
    int getPixelCount();
    
    //setters
    //set position
    void setPosition(Vector3 position);
    //set direction
    void setDirection(Vector3 direction);
    //set up
    void setUp(Vector3 up);
    //set right
    void setRight(Vector3 right);
    //set field of view
    void setFieldOfView(float fieldOfView);
    //set aspect ratio
    void setAspectRatio(float aspectRatio);
    //set near plane
    void setNearPlane(float nearPlane);
    //set far plane
    void setFarPlane(float farPlane);
    //set width
    void setWidth(float width);
    //set height
    void setHeight(float height);
    //set pixel width
    void setPixelWidth(float pixelWidth);
    //set pixel height
    void setPixelHeight(float pixelHeight);
    
    //other methods
    //get ray from pixel
    Ray getRayFromPixel(int pixel);

    //take snapshot
    void takeSnapshot();
    //clear snapshots
    void clearSnapshots();

    

    //save single snapshot to file
    void saveSnapshotToFile(std::string fileName, int snapshot);
    //save all snapshots to video
    void saveSnapshotsToVideo(std::string fileName, int fps);

    

};

