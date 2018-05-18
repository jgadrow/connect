CC=g++
CFLAGS=--std=c++17
OBJS=console_view.o board_controller.o board.o connect.o
OUT=connect.exe
.PHONY : clean all
all : ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${OUT}
board_controller.o : board_controller.cpp
	${CC} ${CFLAGS} -c board_controller.cpp
connect.exe : ${OBJS}
	${CC} ${CFLAGS} board.o connect.o -o ${OUT}
connect.o : connect.cpp
	${CC} ${CFLAGS} -c connect.cpp
console_view.o : console_view.cpp
	${CC} ${CFLAGS} -c console_view.cpp
board.o : board.cpp
	${CC} ${CFLAGS} -c board.cpp
clean :
	rm -f core ${OUT} *.o
