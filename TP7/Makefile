all : main

main: main.o Pile.o TableauDynamique.o ElementTD.o File.o ElementL.o Liste.o
	g++ $^ -o $@

main.o: main.cpp
	g++ $< -c 

Pile.o: Pile.cpp Pile.h
	g++ $< -c 

TableauDynamique.o: TableauDynamique.cpp TableauDynamique.h
	g++ $< -c 

ElementTD.o: ElementTD.cpp ElementTD.h
	g++ $< -c 

File.o: File.cpp File.h
	g++ $< -c 

ElementL.o: ElementL.cpp ElementL.h
	g++ $< -c 

Liste.o: Liste.cpp Liste.h
	g++ $< -c 

clean:
	rm *.o
	rm main