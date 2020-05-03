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
char *dataPointer; // A series of rows and columns (raster) that stores important binary
int *histogram;
int *buff;
			

SHNMBA004::KMeansClusterer::KMeansClusterer(){
	}

SHNMBA004::KMeansClusterer::~KMeansClusterer(){
	}

void SHNMBA004::KMeansClusterer::ppmReader(std::string filename){
		std::ifstream inStream;
	inStream.open(filename, std::ifstream::binary);
	std::string line;
		//bool flag = false;
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
	
void SHNMBA004::KMeansClusterer::charToInt(){
	for(int i = 0; i < width*height*3; i++){
		if((int)dataPointer[i] < 0){
			buff[i] = (int)dataPointer[i] * (-1);
		}
		else{
			buff[i] = (int)dataPointer[i];
		}
	}
}

void SHNMBA004::KMeansClusterer::hist(){
	int count;
	histogram = new int[255];
	for(int q = 0; q < 255; q++){
		for(int w = 0; w < width*height*3; w++){
			if(buff[w] == q){
				count++;
			}
		}
		histogram[q] = count;
		count = 0;
	}
}

void SHNMBA004::KMeansClusterer::binH(int num){
	val = 255/num;
	int sum;
	int a = 0;
	int index = num;
	binArray = new int[val];
	for(int r = 0; r < val; r++){
		for(int t = a; t < index; t++){
			sum += histogram[t];
		}
		binArray[r] = sum;
		sum = 0;
		a += num;
		index +=num;
		
	}
}
