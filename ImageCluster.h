#ifndef IMAGECLUSTER_H
#define IMAGECLUSTER_H

#include <fstream>

using namespace std;

class ImageCluster{
	int rows;
	int cols;
	int intensity;
	public:
		//function to read the ppm image
		void ImageReader(char * filename);
		void comment(std::ifstream & file, std::string & line);
};

#endif
