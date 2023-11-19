all : main

main: main.o ElementL.o Liste.o
	g++ main.o ElementL.o Liste.o -o $@

main.o: main.cpp
	g++ $< -c 

ElementL.o: ElementL.cpp ElementL.h
	g++ $< -c 

Liste.o: Liste.cpp Liste.h
	g++ $< -c 

clean:
	rm *.o
	rm main