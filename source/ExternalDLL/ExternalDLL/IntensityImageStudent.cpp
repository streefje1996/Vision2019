#include "IntensityImageStudent.h"

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {

}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : 
	IntensityImage(other.getWidth(), other.getHeight()) {
	this->image = new Intensity[other.getWidth() * other.getHeight()];
	for (int i = 0; i < getWidth() * getHeight(); i++) {
		this->image[i] = other.getPixel(i);
	}
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : IntensityImage(width, height) {
	this->image = new Intensity[width * height];
}

IntensityImageStudent::~IntensityImageStudent() {
	delete[] this->image;
}

void IntensityImageStudent::set(const int width, const int height) {
	IntensityImage::set(width, height);
	delete[] this->image;
	this->image = new Intensity[width * height];
}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
	IntensityImage::set(other.getWidth(), other.getHeight());
	this->set(other.getWidth(), other.getHeight());
	for (int i = 0; i < getWidth() * getHeight(); i++) {
		this->image[i] = other.getPixel(i);
	}
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	this->image[y * getWidth() + x] = pixel;
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
	this->image[i] = pixel;
}

Intensity IntensityImageStudent::getPixel(int x, int y) const {
	return this->image[y * getWidth() + x];
}

Intensity IntensityImageStudent::getPixel(int i) const {
	return this->image[i];
}
