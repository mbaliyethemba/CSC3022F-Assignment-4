#include "KMeansClusterer.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <dirent.h>

using namespace std;
std::string *ppmImages;

int main(int argc, char* argv[]){
	SHNMBA004::KMeansClusterer k;
	ppmImages = new string[100];
	int s = 0;
	DIR *fileDirectory;
	struct dirent *entry;
	if ( fileDirectory = opendir("Gradient_Numbers_PPMS/")){
		while(entry = readdir(fileDirectory)){
			if(strcmp(entry->d_name,".") != 0 && strcmp(entry->d_name,"..")){
					ppmImages[s] = entry->d_name;
					s++;
					
			}
		}
	}
	for(int i = 0; i < 100; i++){
		k.ppmReader(ppmImages[i]);
		k.grayscale();
		k.charToInt();
	}
}
