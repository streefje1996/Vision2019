#include "IntensityImageStudent.h"

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {

}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : IntensityImage(other.getWidth(), other.getHeight()) {
	image = other.getImage();
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : IntensityImage(width, height) {
	image = new Intensity[width * height];
}

IntensityImageStudent::~IntensityImageStudent() {
	delete image;
}

void IntensityImageStudent::set(const int width, const int height) {
	IntensityImage::set(width, height);
	delete image;
	image = new Intensity[width * height];
}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
	IntensityImage::set(other.getWidth(), other.getHeight());
	delete image;
	image = new Intensity[other.getWidth() * other.getHeight()];
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	image[y * getWidth() + x] = pixel;
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
	image[i] = pixel;
}

Intensity IntensityImageStudent::getPixel(int x, int y) const {
	return image[y * getWidth()] + x;
}

Intensity IntensityImageStudent::getPixel(int i) const {
	return image[i];
}

unsigned char * IntensityImageStudent::getImage() const
{
	return image;
}
