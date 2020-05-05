#include "KMeansClusterer.h"
#include "math.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <dirent.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

std::string magicNumber;
int width;
int height;
int maxColorVal;
int val;
int *buff;
std::vector<int *> ppmHist;
std::vector<int> randomnum;
std::vector<int *> kpoints;
int k;
std::vector<double> distances;
std::vector<int> clusters;
			

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
	histogram = new int[256];
	for(int q = 0; q < 256; q++){
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
	val = 256/num;
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

void SHNMBA004::KMeansClusterer::ReadingList(){
	DIR *fileDirectory;
	struct dirent *entry;
	if ( fileDirectory = opendir("Gradient_Numbers_PPMS/")){
		while(entry = readdir(fileDirectory)){
			if(strcmp(entry->d_name,".") != 0 && strcmp(entry->d_name,"..")){
					ppmImages.push_back(entry->d_name);
			}
		}
	}
	for(int i = 0; i < ppmImages.size(); i++){
		ppmReader(ppmImages[i]);
		grayscale();
		charToInt();
		hist();
		binH(4);
		ppmHist.push_back(binArray);
	}
}

void SHNMBA004::KMeansClusterer::centriod(int n){
	k = n;
	int num;
	while(randomnum.size()!= k){
		num = rand() % (ppmImages.size());
		if(find(randomnum.begin(), randomnum.end(), num) == randomnum.end()){
			randomnum.push_back(num);
		}
	}
}

void SHNMBA004::KMeansClusterer::centriodArray(){
	for(int i = 0 ; i < k; i++){
		kpoints.push_back(ppmHist[randomnum[i]]);
	}
}

double SHNMBA004::KMeansClusterer::calculate_distance(int* x, int* y){
	double multSum;
	for(int i = 0; i < val; i++){
		multSum = pow(x[i]-y[i], 2.0);
	}
	return sqrt(multSum);
}

void SHNMBA004::KMeansClusterer::load_distances(){
	int minval = 0;
	for(int q = 0; q < ppmImages.size(); q++){
		for(int i = 0; i < k; i++){
			if(ppmHist[q] == kpoints[i]){
				minval = i;
				break;
			}
		}
	clusters.push_back(minval);	
	}
}

void SHNMBA004::KMeansClusterer::clusterprint(){
	std::string printout;
	for(int j = 0; j < k ; j++){
		std::cout << "cluster " << j << ":";
		for(int i = 0; i < clusters.size(); i++){
			if(clusters[i] == j){
				std::cout << ppmImages[i] <<", ";
			}
		}
		std::cout << "" << std::endl;	
	}
}


