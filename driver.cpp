#include "KMeansClusterer.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <dirent.h>

using namespace std;

int main(int argc, char* argv[]){
	SHNMBA004::KMeansClusterer k;
	if(argc < 2){
		std::cout << "Not enough parameters" << std::endl;
	}
	else if(argc == 2){
		k.ReadingList(string(argv[1]),1);
		k.centriod(10);
		k.centriodArray();
		k.load_distances();
		k.clusterprint();
	}
	//k.ReadingList();
	k.centriod(10);
	k.centriodArray();
	k.load_distances();
	k.clusterprint();
}
