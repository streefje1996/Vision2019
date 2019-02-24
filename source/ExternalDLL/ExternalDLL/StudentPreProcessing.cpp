#include "StudentPreProcessing.h"


IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepScaleImage(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepEdgeDetection(const IntensityImage &image) const {
	//int kernel[5][5] = { 
	//	{-1,	-1,		-1,		-1,		-1},
	//	{-1,	-1,		-1,		-1,		-1},
	//	{-1,	-1,		24,		-1,		-1},
	//	{-1,	-1,		-1,		-1,		-1},
	//	{-1,	-1,		-1,		-1,		-1}

	//};
	//IntensityImage * new_image = ImageFactory::newIntensityImage(image.getWidth(), image.getHeight());

	//int width = image.getWidth();
	//int height = image.getHeight();

	//for (int x = 2; x < width-2; x++)
	//{
	//	for (int y = 2; y < height-2; y++)
	//	{
	//		int d = 0;
	//		for (int i = 2; i < 7; i++)
	//		{
	//			for (int j = 2; j < 7; j++)
	//			{
	//				d += image.getPixel(x + (i - 2), y + (j - 2)) * kernel[i - 2][j - 2];
	//			}
	//		}


	//		new_image->setPixel(x, y, d);
	//	}
	//}

	int kernel[3][3] = { {0,1,0},{1,-4,1},{0,1,0} };
	IntensityImage * new_image = ImageFactory::newIntensityImage(image.getWidth(), image.getHeight());

	int width = image.getWidth();
	int height = image.getHeight();

	for (int x = 2; x < width-2; x++)
	{
		for (int y = 2; y < height-2; y++)
		{
			
			new_image->setPixel(x, y, 
				kernel[0][0] * image.getPixel(x - 1, y - 1) +
				kernel[0][1] * image.getPixel(x, y - 1) +
				kernel[0][2] * image.getPixel(x + 1, y - 1) +

				kernel[1][0] * image.getPixel(x - 1, y) +
				kernel[1][1] * image.getPixel(x, y) +
				kernel[1][2] * image.getPixel(x + 1, y) +

				kernel[2][0] * image.getPixel(x - 1, y + 1) +
				kernel[2][1] * image.getPixel(x, y + 1) +
				kernel[2][2] * image.getPixel(x + 1, y + 1));
		}
	}

	return new_image;
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
	return nullptr;
}