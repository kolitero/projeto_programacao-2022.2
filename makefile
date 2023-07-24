run: all
	clear
	./projeto

all:
	gcc -Wall `pkg-config --cflags gtk+-3.0` source/main.c source/components/*.c source/functions/*.c  source/components/funcionarios/*.c source/functions/funcionarios/*.c  -c `pkg-config --libs gtk+-3.0`
	gcc `pkg-config --cflags gtk+-3.0` *.o -o projeto `pkg-config --libs gtk+-3.0`

clean.o:
	rm *.o

clean:
	rm projeto
	rm *.dat
	rm *.o

compile:
	gcc -Wall `pkg-config --cflags gtk+-3.0` source/main.c source/components/*.c source/functions/*.c  source/components/funcionarios/*.c source/functions/funcionarios/*.c  -o projeto `pkg-config --libs gtk+-3.0`