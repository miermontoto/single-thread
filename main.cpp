/*
 * Main.cpp
 *
 *  Created on: Fall 2019
 */

#include <stdio.h>
#include <math.h>
#include <CImg.h>

using namespace cimg_library;

// Data type for image components
// FIXME: Change this type according to your group assignment
typedef float data_t;

const char* SOURCE_IMG      = "bailarina.bmp";
const char* HELP_IMG        = "background_V.bmp"; // nombre de la imagen a mezclar
const char* DESTINATION_IMG = "bailarina2.bmp";


int main() {
	// Open file and object initialization
	CImg<data_t> srcImage(SOURCE_IMG);
	CImg<data_t> aidImage(HELP_IMG);

	data_t *pRsrc, *pGsrc, *pBsrc; // Pointers to the R, G and B components
	data_t *pRaid, *pGaid, *pBaid;
	data_t *pRdest, *pGdest, *pBdest;
	data_t *pDstImage; // Pointer to the new image pixels
	uint width, height; // Width and height of the image
	uint nComp; // Number of image components

	srcImage.display(); // Muestra la imagen original.
	aidImage.display(); // Muestra la imagen a mezclar.

	// Se comprueba que las dimensiones de las dos imagenes sean iguales.s
	if(srcImage.width() != aidImage.width() && srcImage.height() != aidImage.height()) {
		perror("Images to blend don't have the same size.");
		exit(1);
	}

	// Almacenar dimensiones de la foto actual.
	width  = srcImage.width();
	height = srcImage.height();
	nComp  = srcImage.spectrum(); // source image number of components
				// Common values for spectrum (number of image components):
				//  B&W images = 1
				//	Normal color images = 3 (RGB)
				//  Special color images = 4 (RGB and alpha/transparency channel)


	// Allocate memory space for destination image components
	pDstImage = (data_t *) malloc (width * height * nComp * sizeof(data_t));
	if (pDstImage == NULL) {
		perror("Allocating destination image");
		exit(-2);
	}

	// Pointers to the componet arrays of the source image
	pRsrc = srcImage.data(); // pRcomp points to the R component array
	pGsrc = pRsrc + height * width; // pGcomp points to the G component array
	pBsrc = pGsrc + height * width; // pBcomp points to B component array

	// Pointers to the componet arrays of the help image
	pRaid = aidImage.data();
	pGaid = pRaid + height * width;
	pBaid = pGaid + height * width;

	// Pointers to the RGB arrays of the destination image
	pRdest = pDstImage;
	pGdest = pRdest + height * width;
	pBdest = pGdest + height * width;


	/***********************************************
	 * TODO: Algorithm start.
	 *   - Measure initial time
	 */
	
	for (uint i = 0; i < width * height; i++) {
		// Algoritmo temporal
		/*
		*(pRdest + i) = *(pGsrc + i);  // This is equals to pRdest[i] = pGsrc[i]
		*(pGdest + i) = *(pBsrc + i);
		*(pBdest + i) = *(pRsrc + i);
		*/

		// Algoritmo real:
		// Blend: blacken mode #12


	}

	/***********************************************
	 * TODO: End of the algorithm.
	 *   - Measure the end time
	 *   - Calculate the elapsed time
	 */

		
	// Create a new image object with the calculated pixels
	// In case of normal color images use nComp=3,
	// In case of B/W images use nComp=1.
	CImg<data_t> dstImage(pDstImage, width, height, 1, nComp);

	// Store destination image in disk
	dstImage.save(DESTINATION_IMG); 

	// Display destination image
	dstImage.display();
	
	// Free memory
	free(pDstImage);

	return 0;
}
