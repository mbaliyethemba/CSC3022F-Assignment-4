#include "KMeansClusterer.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <dirent.h>

using namespace std;

std::string magicNumber;
int width;
int height;
int maxColorVal;
int val;
int *buff;

SHNMBA004::KMeansClusterer::KMeansClusterer(){
	}

SHNMBA004::KMeansClusterer::~KMeansClusterer(){
	}

void SHNMBA004::KMeansClusterer::ppmReader(std::string filename){
	std::ifstream inStream;
	inStream.open(filename, std::ifstream::binary);
	std::string line;
		if(inStream.is_open()){
			getline(inStream,line,'\n');
			if(line == "P6"){
				getline(inStream,line,'\n');
				int found = line.find(" ");
				std::string temp1 = line;
				std::string temp2 = line;
				temp1.erase(found);
				temp2.substr(found);
				width = std::stoi(temp1);
				height = std::stoi(temp2);
				maxColorVal = std::stoi(line);
				dataPointer = new char[3 * width * height];
				buff = new int[3 * width * height];
				inStream.read(dataPointer, height*width*3);
			}
		}
	inStream.close();	
}

void SHNMBA004::KMeansClusterer::grayscale(){
	char *init, *reset;
		unsigned char oldRed, oldGreen, oldBlue, newRed, newGreen, newBlue;
		reset = dataPointer; // keep track of initial pointer position
		for(int i = 0; i < width * height; i++){
			init = dataPointer;
			oldRed = *dataPointer;
			dataPointer++;
			oldGreen = *dataPointer;
			dataPointer++;
			oldBlue = *dataPointer;
			newRed = (oldRed * 0.21) + (oldGreen * 0.72) + (oldBlue * 0.07);
			newGreen = (oldRed * 0.21) + (oldGreen * 0.72) + (oldBlue * 0.07);
			newBlue = (oldRed * 0.21) + (oldGreen * 0.72) + (oldBlue * 0.07);
			dataPointer = init;
			*dataPointer = newRed;
			dataPointer++;
			*dataPointer = newGreen;
			dataPointer++;
			*dataPointer = newBlue;
			dataPointer++;
		}
		
		dataPointer = reset; // reset pointer position
}
	

