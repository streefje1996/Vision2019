#include "RGBImageStudent.h"

RGBImageStudent::RGBImageStudent() : RGBImage() 
{
	//TODO: Nothing
}

RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) : 
	RGBImage(other.getWidth(), other.getHeight()) 
{
	this->image = new RGB[other.getWidth() * other.getHeight()];
	for (int i = 0; i < getWidth() * getHeight(); i++) {
		this->image[i] = other.getPixel(i);
	}
	//TODO: Create a copy from the other object
}


RGBImageStudent::RGBImageStudent(const int width, const int height) : 
	RGBImage(width, height) 
{
	this->image = new RGB[width * height];
}

RGBImageStudent::~RGBImageStudent() {
	delete[] this->image;
}

void RGBImageStudent::set(const int width, const int height) {
	RGBImage::set(width, height);
	delete[] this->image;
	this->image = new RGB[width * height];
}

void RGBImageStudent::set(const RGBImageStudent &other) {
	RGBImage::set(other.getWidth(), other.getHeight());
	this->set(other.getWidth(), other.getHeight());
	for (int i = 0; i < getWidth() * getHeight(); i++) {
		this->image[i] = other.getPixel(i);
	}
}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) {
	this->image[y * getWidth() + x] = pixel;
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
	this->image[i] = pixel;
}

RGB RGBImageStudent::getPixel(int x, int y) const {
	return this->image[y*getWidth() + x];
}

RGB RGBImageStudent::getPixel(int i) const {
	return this->image[i];
}
