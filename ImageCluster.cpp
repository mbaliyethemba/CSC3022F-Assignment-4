#include "ImageCluster.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void ImageReader(char * filename){
	std::ifstream infile(filename, std::ios::in | std::ios::binary);
	std::string line;
	if(infile.is_open()){
		getline(infile,line,'\n');
		if(line == "P6"){
		}
	}
}

void comment(std::ifstream & file, std::string & line){
	while(line.at(0) == '#'){
		getline(file, line,'\n');
	}
}
