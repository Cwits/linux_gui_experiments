CC = gcc
OPT = -g3 -Wall -g


all: gtk_cairo

main.o: ./main.c						#main.c here
	$(CC) `pkg-config --cflags gtk+-3.0` -c $(OPT) ./main.c -o ./main.o  -lm
	
gtk_cairo: main.o 
	$(CC) `pkg-config --cflags gtk+-3.0` $(OPT) ./main.o -o gtk_cairo `pkg-config --cflags --libs gtk+-3.0 jack sndfile cairo fftw3` -lm
	
#additional libs -lX11 -lGL -lGLU

install:
	cp gtk_cairo ./../../../home/cwits/Desktop/linux_gui_experiments/gtk_cairo/
	cp -a src/. ./../../../home/cwits/Desktop/linux_gui_experiments/gtk_cairo/src/
	echo "Copied!"

clean: 
	#rm stool
	#rm -rf ./obj/*.o
	#rm -rf ./obj/core/*.o
	#rm -rf ./../../home/cwits/Desktop/