all:	cipher

cipher:	cipher.o Playfair.o RowTransposition.o RailFence.o Vigenre.o Caesar.o Hill.o
	g++ -std=c++11 cipher.o Playfair.o RowTransposition.o RailFence.o Vigenre.o Caesar.o Hill.o -o cipher

cipher.o:	cipher.cpp
	g++ -std=c++11 -g -c cipher.cpp 

Playfair.o:	Playfair.cpp Playfair.h CipherInterface.h
	g++ -std=c++11 -g -c Playfair.cpp
	
RowTransposition.o: RowTransposition.cpp RowTransposition.h CipherInterface.h
	g++ -std=c++11 -g -c RowTransposition.cpp
	
RailFence.o: RailFence.cpp RailFence.h CipherInterface.h
	g++ -std=c++11 -g -c RailFence.cpp

Vigenre.o: Vigenre.cpp Vigenre.h CipherInterface.h
	g++ -std=c++11 -g -c Vigenre.cpp

Caesar.o: Caesar.cpp Caesar.h CipherInterface.h
	g++ -std=c++11 -g -c Caesar.cpp

Hill.o: Hill.cpp Hill.h CipherInterface.h
	g++ -std=c++11 -g -c Hill.cpp	

clean:
	rm -rf *.o cipher
