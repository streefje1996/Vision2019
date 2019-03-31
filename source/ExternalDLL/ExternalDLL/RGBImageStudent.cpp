#include "RGBImageStudent.h"

RGBImageStudent::RGBImageStudent() : RGBImage() 
{
	//TODO: Nothing
}

RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) : 
	RGBImage(other.getWidth(), other.getHeight()) 
{
	image = new RGB[other.getWidth() * other.getHeight()];
	image = other.getImage();
	//TODO: Create a copy from the other object
}


RGBImageStudent::RGBImageStudent(const int width, const int height) : 
	RGBImage(width, height) 
{
	image = new RGB[width * height];
}

RGBImageStudent::~RGBImageStudent() {
	delete image;
}

void RGBImageStudent::set(const int width, const int height) {
	RGBImage::set(width, height);
	delete image;
	image = new RGB[width * height];
}

void RGBImageStudent::set(const RGBImageStudent &other) {
	RGBImage::set(other.getWidth(), other.getHeight());
	delete image;
	image = new RGB[other.getWidth() * other.getHeight()];
	image = other.getImage();
}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) {
	image[y*getWidth() + x] = pixel;
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
	image[i] = pixel;
}

RGB RGBImageStudent::getPixel(int x, int y) const {
	return image[y*getWidth() + x];
}

RGB RGBImageStudent::getPixel(int i) const {
	return image[i];
}

RGB * RGBImageStudent::getImage() const
{
	return image;
}
