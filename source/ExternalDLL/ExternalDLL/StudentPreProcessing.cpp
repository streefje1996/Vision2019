#include "StudentPreProcessing.h"


IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	const int width = image.getWidth();
	const int height = image.getHeight();
	const int both = width * height;
	IntensityImage * grayscale = ImageFactory::newIntensityImage(width, height);
	RGB pixel;
	for (int i = 0; i < both; i++) {
		pixel = image.getPixel(i);
		grayscale->setPixel(i, (pixel.r + pixel.g + pixel.b) / 3);
	}
	return grayscale;
}

IntensityImage * StudentPreProcessing::stepScaleImage(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepEdgeDetection(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
	return nullptr;
}