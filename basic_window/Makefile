CC = gcc
OPT = -g3 -Wall -g


all: gui_basic_window

main.o: ./main.c						#main.c here
	$(CC) `pkg-config --cflags gtk+-3.0` -c $(OPT) ./main.c -o ./main.o `pkg-config --libs gtk+-3.0`
	
gui_basic_window: main.o 
	$(CC) `pkg-config --cflags gtk+-3.0` $(OPT) ./main.o -o gui_basic_window `pkg-config --cflags --libs gtk+-3.0 jack sndfile fftw3` -lm
	
#additional libs -lX11 -lGL -lGLU

install:
	cp gui_basic_window ./../../../home/cwits/Desktop/linux_gui_experiments/basic_window/
	cp -a src/. ./../../../home/cwits/Desktop/linux_gui_experiments/basic_window/src/
	echo "Copied!"

clean: 
	#rm stool
	#rm -rf ./obj/*.o
	#rm -rf ./obj/core/*.o
	#rm -rf ./../../home/cwits/Desktop/