#include "correlation.h"

/************************ TO BE DONE 2 **************************/
/*
 *	INPUT: 
 *		origImg:		the original image, 
 *		imgWidth:		the width of the image
 *		imgHeight:		the height of the image
 *						the image is arranged such that 
 *						origImg[3*(row*imgWidth+column)+0], 
 *						origImg[3*(row*imgWidth+column)+1], 
 *						origImg[3*(row*imgWidth+column)+2]
 *						are R, G, B values for pixel at (column, row).
 *
 *      kernel:			the 2D filter kernel,
 *		knlWidth:		the width of the kernel
 *		knlHeight:		the height of the kernel
 *		
 *		scale, offset:  after correlating the kernel with the origImg, 
 *						each pixel should be divided by scale and then added by offset
 *      
 *		selection:      a byte array of the same size as the image, 
 *						indicating where in the original image should be filtered, e.g., 
 *						selection[k] == 1 ==> pixel k should be filtered
 *                      selection[k] == 0 ==> pixel k should NOT be filtered
 *                      a special case is selection is a NULL pointer, which means all the pixels should be filtered. 
 *
 *  OUTPUT:
 *		rsltImg:		the filtered image of the same size as original image.
 *						it is a valid pointer ( allocated already ).
 */

void image_filter(double *rsltImg, const unsigned char *origImg, const unsigned char *selection, 
			int imgWidth, int imgHeight, 
			const double *kernel, int knlWidth, int knlHeight,
			double scale, double offset)
{
	// HINT: this function should make calls to pixel_filter
	for (int i = 0; i < imgWidth; i++) 
	{
		for (int j = 0; j < imgHeight; j++) 
		{
			double pixel[3];
		    pixel[0] = origImg[3*(j*imgWidth+i)];
			pixel[1] = origImg[3*(j*imgWidth+i)+1];
			pixel[2] = origImg[3*(j*imgWidth+i)+2];
			if (selection == NULL || selection[j*imgWidth + i] == 1) 
			{
				pixel_filter(pixel, i, j, origImg, imgWidth, imgHeight, kernel, knlWidth, knlHeight, scale, offset);
			}
			rsltImg[3*(j*imgWidth+i)] = pixel[0];
			rsltImg[3*(j*imgWidth+i)+1] = pixel[1];
			rsltImg[3*(j*imgWidth+i)+2] = pixel[2];
		}
	}

}


/************************ END OF TBD 2 **************************/


/************************ TO BE DONE 3 **************************/
/*
 *	INPUT: 
 *      x:				a column index,
 *      y:				a row index,
 *		origImg:		the original image, 
 *		imgWidth:		the width of the image
 *		imgHeight:		the height of the image
 *						the image is arranged such that 
 *						origImg[3*(row*imgWidth+column)+0], 
 *						origImg[3*(row*imgWidth+column)+1], 
 *						origImg[3*(row*imgWidth+column)+2]
 *						are R, G, B values for pixel at (column, row).
 *
 *      kernel:			the 2D filter kernel,
 *		knlWidth:		the width of the kernel
 *		knlHeight:		the height of the kernel
 *
 *		scale, offset:  after correlating the kernel with the origImg, 
 *						the result pixel should be divided by scale and then added by offset
 *
 *  OUTPUT:
 *		rsltPixel[0], rsltPixel[1], rsltPixel[2]:		
 *						the filtered pixel R, G, B values at row y , column x;
 */

void pixel_filter(double rsltPixel[3], int x, int y, const unsigned char *origImg, int imgWidth, int imgHeight, 
			  const double *kernel, int knlWidth, int knlHeight,
			  double scale, double offset)
{

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < knlWidth; ++j)
		{
			for (int k = 0; k < knlHeight; ++k)
			{
				int colInd = j*x - (knlWidth - 1) / 2;
				if (colInd >= imgWidth || colInd < 0)
				{
					colInd = x;
				}
				int rowInd = k*y - (knlHeight - 1) / 2;
				if (rowInd >= imgHeight || rowInd < 0)
				{
					rowInd = y;
				}
				int kind = k*knlWidth + j;
				int ind = 3 * (rowInd * imgWidth + colInd) + i;
				rsltPixel[i] += kernel[kind] * origImg[ind];
			}
		}

		rsltPixel[i] = (rsltPixel[i] / scale) + offset;
	}
//	printf("pixel_filter: to be done in correlation.cpp\n");
}

/************************ END OF TBD 3 **************************/

