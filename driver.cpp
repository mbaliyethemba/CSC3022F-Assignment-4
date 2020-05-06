#include "KMeansClusterer.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <dirent.h>

using namespace std;

int main(int argc, char* argv[]){
	SHNMBA004::KMeansClusterer * k = new SHNMBA004::KMeansClusterer();
	std::ofstream outStream;
	if(argc < 2){
		std::cout << "Not enough parameters" << std::endl;
	}
	else if(argc == 2){
		k->ReadingList(string(argv[1]),1);
		k->centriod(10);
		k->centriodArray();
		k->load_distances();
		k->clusterprint();
	}
	else if(argc == 4){
		if((string(argv[2]).compare("-o")) == 0){
			k->ReadingList(string(argv[1]),1);
			k->centriod(10);
			k->centriodArray();
			k->load_distances();
			outStream.open(string(argv[3]));
			outStream << k;
			outStream.close();
			std::cout << "The outputfile has been printed" << std::endl;
		}
		
		else if((string(argv[2]).compare("-k")) == 0){
			k->ReadingList(string(argv[1]),1);
			k->centriod(stoi(argv[3]));
			k->centriodArray();
			k->load_distances();
			k->clusterprint();
		}
		else if((string(argv[2]).compare("-bin")) == 0){
			k->ReadingList(string(argv[1]),stoi(argv[3]));
			k->centriod(10);
			k->centriodArray();
			k->load_distances();
			k->clusterprint();
		}
		else{
			std::cout << "Incorrect parameters entered" << std::endl;
		}
	}
	
	else if(argc == 6){
		if((string(argv[2]).compare("-o")) == 0 && (string(argv[4]).compare("-k")) == 0){
			k->ReadingList(string(argv[1]),1);
			k->centriod(stoi(argv[5]));
			k->centriodArray();
			k->load_distances();
			outStream.open(string(argv[3]));
			outStream << k;
			outStream.close();
			std::cout << "The outputfile has been printed" << std::endl;
		}
		
		else if((string(argv[2]).compare("-o")) == 0 && (string(argv[4]).compare("-bin")) == 0){
			k->ReadingList(string(argv[1]),stoi(argv[5]));
			k->centriod(10);
			k->centriodArray();
			k->load_distances();
			outStream.open(string(argv[3]));
			outStream << k;
			outStream.close();
			std::cout << "The outputfile has been printed" << std::endl;
		}
		else if((string(argv[2]).compare("-k")) == 0 && (string(argv[4]).compare("-bin")) == 0){
			k->ReadingList(string(argv[1]),stoi(argv[5]));
			k->centriod(stoi(argv[3]));
			k->centriodArray();
			k->load_distances();
			k->clusterprint();
		}
		else{
			std::cout << "Incorrect parameters entered" << std::endl;
		}
	}
	
	else if(argc == 8){
		if((string(argv[2]).compare("-o")) == 0 && (string(argv[4]).compare("-k")) == 0 && (string(argv[6]).compare("-bin")) == 0 ){
			k->ReadingList(string(argv[1]),stoi(argv[7]));
			k->centriod(stoi(argv[5]));
			k->centriodArray();
			k->load_distances();
			outStream.open(string(argv[3]));
			outStream << k;
			outStream.close();
			std::cout << "The outputfile has been printed" << std::endl;
		}
		else{
			std::cout << "Incorrect parameters entered" << std::endl;
		}
	}
}
