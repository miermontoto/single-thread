/*
 * Main.cpp
 *
 *  Created on: Fall 2019
 */

#include <stdio.h>
#include <math.h>
#include <pthread.h>
#include <CImg.h>

using namespace cimg_library;

<<<<<<< HEAD:single-thread/main.cpp
#define R 17 // number of times the algorithm is repeated.
typedef float data_t;

const char* SOURCE_IMG      = "bailarina.bmp"; // source image's file name.
const char* HELP_IMG        = "background_V.bmp"; // aid image's file name.
const char* DESTINATION_IMG = "result.bmp"; // resulting image's file name.

<<<<<<< HEAD:single-thread/main.cpp
=======
void threadTask(ThreadParams params) {
	//ThreadParams params = *((ThreadParams*) param);
	for (uint i = params._startRow; i < params._width * params._height; i++) {
		// pointer initialization:

		// source image pointers
		float pRsrc = params._SOURCE.data();                  // red component
		float pGsrc = pRsrc + params._height * params._width; // green component
		float pBsrc = pGsrc + params._height * params._width; // blue component

		// help image pointers
		float pRaid = params._HELP.data();                    // red component
		float pGaid = pRaid + params._height * params._width; // green component
		float pBaid = pGaid + params._height * params._width; // blue component

		// destination image pointers
		float pRdest = params._DEST.data();                     // red component
		float pGdest = pRdest + params._height * params._width; // green component
		float pBdest = pGdest + params._height * params._width; // blue component


		int red, blue, green; // temporal component initialization

		// Algorithm
		// Blend: blacken mode #12
		red = 255 - ((256 * (255 - pRaid[i])) / (pRsrc[i] + 1));
		green = 255 - ((256 * (255 - pGaid[i])) / (pGsrc[i] + 1));
		blue = 255 - ((256 * (255 - pBaid[i])) / (pBsrc[i] + 1));

		// Values are checked and trimmed.

		red = max(min(red, 255), 0);
		green = max(min(green, 255), 0);
		blue = max(min(blue, 255), 0);

		// Results are added to the destination image.

		pRdest[i] = red;
		pGdest[i] = green;
		pBdest[i] = blue;
	}
}
=======
// Data type for image components
// FIXME: Change this type according to your group assignment
typedef long data_t;
>>>>>>> parent of edd8839 (estructura general, vectores, creación de hilos):main.cpp

>>>>>>> parent of 0cab11c (arreglados fallos de equivalencia de tipos):main.cpp

int main() {

	/***************************************************
	 * TODO: Variables initialization.
	 *   - Prepare variables for the algorithm
	 *   - This is not included in the benchmark time
	 */

<<<<<<< HEAD:single-thread/main.cpp
	// Allocate memory for the resulting image.
	pDstImage = (data_t *) malloc (width * height * nComp * sizeof(data_t));
	if (pDstImage == NULL) {
		perror("Error: couldn't allocate memory for the destination image.");
		exit(1);
	}

	// pointer initialization:

	// source image pointers
	pRsrc = srcImage.data();        // red component
	pGsrc = pRsrc + height * width; // green component
	pBsrc = pGsrc + height * width; // blue component

	// help image pointers
	pRaid = aidImage.data();        // red component
	pGaid = pRaid + height * width; // green component
	pBaid = pGaid + height * width; // blue component

	// destination image pointers
	pRdest = pDstImage;               // red component
	pGdest = pRdest + height * width; // green component
	pBdest = pGdest + height * width; // blue component

	// Starting time
	if (clock_gettime(CLOCK_REALTIME, &tStart)==-1) {
		printf("Error: couldn't obtain starting time");
		exit(1);
	}

	// The algorithm repeats itself to be within time completition valid margins
	// It should last between 5 and 10 seconds with this configuration.
	for(int i = 0; i < R; i++) {
<<<<<<< HEAD:single-thread/main.cpp
		for (uint i = 0; i < width * height; i++) {

			int red, blue, green; // temporal component initialization

			// Algorithm
			// Blend: blacken mode #12
			red = 255 - ((256 * (255 - pRaid[i])) / (pRsrc[i] + 1));
			green = 255 - ((256 * (255 - pGaid[i])) / (pGsrc[i] + 1));
			blue = 255 - ((256 * (255 - pBaid[i])) / (pBsrc[i] + 1));

			// Values are checked and trimmed.

			red = max(min(red, 255), 0);
			green = max(min(green, 255), 0);
			blue = max(min(blue, 255), 0);

			// Results are added to the destination image.

			pRdest[i] = red;
			pGdest[i] = green;
			pBdest[i] = blue;
=======
		pthread_t threads[numThreads];
		const int rowsPerThread = height / numThreads;

		ThreadParams params[numThreads];

		for(int i = 0; i < numThreads; i++) {
			params[i]._SOURCE = srcImage;
			params[i]._DEST = pDstImage;
			params[i]._HELP = aidImage;
			params[i]._height = height;
			params[i]._width = width;
			params[i]._numRows = rowsPerThread;
			params[i]._startRow = i * rowsPerThread;
			pthread_create(&(threads[i]), NULL, threadTask, &(params[i]));
		}
>>>>>>> parent of 0cab11c (arreglados fallos de equivalencia de tipos):main.cpp

		}
	}

	// Ending time 
	if (clock_gettime(CLOCK_REALTIME, &tEnd) == -1){
		printf("Error: couldn't obtain ending time");
		exit(1);
	}
=======

	/***********************************************
	 * TODO: Algorithm start.
	 *   - Measure initial time
	 */
>>>>>>> parent of edd8839 (estructura general, vectores, creación de hilos):main.cpp


	/************************************************
	 * TODO: Algorithm.
	 */


	/***********************************************
	 * TODO: End of the algorithm.
	 *   - Measure the end time
	 *   - Calculate the elapsed time
	 */

	return 0;
}
