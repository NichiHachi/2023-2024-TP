all : main

main: main.o ElementTD.o TableauDynamique.o
	g++ main.o ElementTD.o TableauDynamique.o -o $@

main.o: main.cpp
	g++ -Wall $< -c 

ElementTD.o: ElementTD.cpp ElementTD.h
	g++ -Wall $< -c 

TableauDynamique.o: TableauDynamique.cpp TableauDynamique.h
	g++ -Wall $< -c 

clean:
	rm *.o
	rm main