all:	cipher

cipher:	cipher.o Playfair.o RowTransposition.o Railfence.o Vigenre.o Caesar.o
	g++ -std=c++11 cipher.o Playfair.o RowTransposition.o Railfence.o Vigenre.o Caesar.o -o cipher

cipher.o:	cipher.cpp
	g++ -std=c++11 -g -c cipher.cpp 

Playfair.o:	Playfair.cpp Playfair.h CipherInterface.h
	g++ -std=c++11 -g -c Playfair.cpp
	
RowTransposition.o: RowTransposition.cpp RowTransposition.h CipherInterface.h
	g++ -std=c++11 -g -c RowTransposition.cpp
	
Railfence.o: Railfence.cpp Railfence.h CipherInterface.h
	g++ -std=c++11 -g -c Railfence.cpp

Vigenre.o: Vigenre.cpp Vigenre.h CipherInterface.h
	g++ -std=c++11 -g -c Vigenre.cpp

Caesar.o: Caesar.cpp Caesar.h CipherInterface.h
	g++ -std=c++11 -g -c Caesar.cpp
	

clean:
	rm -rf *.o cipher
