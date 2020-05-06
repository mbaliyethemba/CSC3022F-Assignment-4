.SUFFIXES:
.SUFFIXES: .cpp .o
CC=g++
CCFLAGS=-std=c++11
LIBS=-lm

clusterer: KMeansClusterer.o driver.o
		$(CC) $(CCFLAGS) KMeansClusterer.o driver.o -o clusterer $(LIBS)
		
KMeansClusterer.o: KMeansClusterer.cpp KMeansClusterer.h
				$(CC) $(CCFLAGS) KMeansClusterer.cpp -c
		
driver.o: driver.cpp
		$(CC) $(CCFLAGS) driver.cpp -c
		
clean: 
		@rm -f *.o
		@rm -f clusterer
