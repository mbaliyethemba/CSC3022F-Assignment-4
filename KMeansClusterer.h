#ifndef KMEANSCLUSTERER_H
#define KMEANSCLUSTERER_H

#include <fstream>
namespace SHNMBA004{
	class KMeansClusterer {
		private:
			std::string magicNumber; // A "magic number" for identifying the file type
			int width; // Width of the image
			int height; // Height of the image
			int maxColorVal; // Maximum color value
			char *dataPointer; // A series of rows and columns (raster) that stores important binary
			int *histogram;
			int *buff;
			int *binArray;
			int val;
			std::string *ppmImages;
			int **ppmHist;
			
		public:
			KMeansClusterer();
			~KMeansClusterer();
			void ImageReader();
			void ppmReader(std::string filename);
	};
}
#endif
