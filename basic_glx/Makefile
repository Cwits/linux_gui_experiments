CC = gcc
OPT = -g3 -Wall -g


all: gui_basic_window

main.o: ./main.c						#main.c here
	$(CC) -c $(OPT) ./main.c -o ./main.o  -lm -lX11 -lGL -lGLU
	
gui_basic_window: main.o 
	$(CC) $(OPT) ./main.o -o gui_basic_window `pkg-config --cflags --libs jack sndfile fftw3` -lm -lX11 -lGL -lGLU
	
#additional libs -lX11 -lGL -lGLU

install:
	cp gui_basic_window ./../../home/cwits/Desktop/linux_gui_experiments/basic_glx/
	cp -a src/. ./../../home/cwits/Desktop/linux_gui_experiments/basic_glx/src/
	echo "Copied!"

clean: 
	#rm stool
	#rm -rf ./obj/*.o
	#rm -rf ./obj/core/*.o
	#rm -rf ./../../home/cwits/Desktop/