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
	
void SHNMBA004::KMeansClusterer::ImageReader(){
	ppmImages = new string[100];
	int s = 0;
	DIR *fileDirectory;
	struct dirent *entry;
	if ( fileDirectory = opendir("Gradient_Numbers_PPMS/")){
		while(entry = readdir(fileDirectory)){
			if(strcmp(entry->d_name,".") != 0 && strcmp(entry->d_name,"..")){
					//std::cout << entry->d_name << std::endl;
					ppmImages[s] = entry->d_name;
					s++;
					
			}
		}
	}
	for(int i = 0; i < 100; i++){
		
	}
}


	

