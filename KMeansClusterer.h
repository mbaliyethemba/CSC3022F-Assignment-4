#ifndef KMEANSCLUSTERER_H
#define KMEANSCLUSTERER_H

#include <fstream>
#include <vector>
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
			std::vector<std::string> ppmImages;
			std::vector<int *> ppmHist;
			
		public:
			KMeansClusterer();
			~KMeansClusterer();
			void ppmReader(std::string filename);
			void grayscale();
			void charToInt();
			void hist();
			void binH(int num);
			void ReadingList(std::string dataset, int b);
			void centriod(int n);
			void centriodArray();
			double calculate_distance(int* x, int* y);
			void load_distances();
			void clusterprint();
			friend std::ostream& operator <<(std::ofstream& os, const KMeansClusterer& kt);
			//void bintoGroup();
	};
}
#endif
