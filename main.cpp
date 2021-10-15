#include <stdio.h>
#include <math.h>
#include <CImg.h>

using namespace cimg_library;

// Data type for image components
// FIXME: Change this type according to your group assignment
typedef float data_t;

const char* SOURCE_IMG      = "bailarina.bmp"; // nombre de la imagen que editar
const char* HELP_IMG        = "background_V.bmp"; // nombre de la imagen a mezclar
const char* DESTINATION_IMG = "result.bmp"; // nombre de la imagen resultante


int main() {
	// Se inicializan los objetos principales y se abren las imágenes.
	CImg<data_t> srcImage(SOURCE_IMG);
	CImg<data_t> aidImage(HELP_IMG);

	// Se inicializan punteros y variables.
	data_t *pRsrc, *pGsrc, *pBsrc; // Punteros a los componentes de la imagen original.
	data_t *pRaid, *pGaid, *pBaid; // Punteros a los componentes de la imagen de apoyo.
	data_t *pRdest, *pGdest, *pBdest; // Punteros a los componentes de la imagen resultante.
	data_t *pDstImage; // Puntero a la imagen resultante.
	uint width, height;
	uint nComp;

	//srcImage.display(); // Muestra la imagen original.
	//aidImage.display(); // Muestra la imagen a mezclar.

	// Se comprueba que las dimensiones de las dos imagenes sean iguales:
	if(srcImage.width() != aidImage.width() && srcImage.height() != aidImage.height()) {
		perror("Images to blend don't have the same size.");
		exit(1);
	}

	// Se almacena información sobre la foto original:
	// Como se han comprobado las dimensiones, width y height son iguales para ambas imgs
	width  = srcImage.width();
	height = srcImage.height();
	nComp  = srcImage.spectrum(); // número de componentes en la imagen:
	/*
	 * (1) en caso de una imagen en blanco y negro.
	 * (3) en caso de una imagen a color.
	 * (4) en caso de una imagen a color CON transparencia.
	 */

	// Reservar espacio en memoria para la imagen resultante.
	pDstImage = (data_t *) malloc (width * height * nComp * sizeof(data_t));
	if (pDstImage == NULL) {
		perror("Allocating destination image");
		exit(-2);
	}

	// Inicialización de punteros a componentes:

	// Punteros a la imagen original
	pRsrc = srcImage.data();        // componente roja
	pGsrc = pRsrc + height * width; // componente verde
	pBsrc = pGsrc + height * width; // componente azul

	// Punteros a la imagen de apoyo
	pRaid = aidImage.data();        // componente roja
	pGaid = pRaid + height * width; // componente verde
	pBaid = pGaid + height * width; // componente azul

	// Punteros a la imagen resultante
	pRdest = pDstImage;               // componente roja
	pGdest = pRdest + height * width; // componente verde
	pBdest = pGdest + height * width; // componente azul


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


	CImg<data_t> dstImage(pDstImage, width, height, 1, nComp);

	dstImage.save(DESTINATION_IMG);   // se guarda la foto
	dstImage.display(); // se muestra la imagen resultante
	free(pDstImage);    // se libera el espacio en memoria

	return 0;
}
