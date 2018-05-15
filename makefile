connect.exe : board.o connect.o
	g++ board.o connect.o -o connect.exe
connect.o : connect.cpp
	g++ -c connect.cpp
board.o : board.cpp
	g++ -c board.cpp
clean :
	rm -f core connect.exe *.o
