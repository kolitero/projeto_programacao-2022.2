run: all
	clear
	./projeto

all:
	gcc -Wall `pkg-config --cflags gtk+-3.0` source/main.c source/components/*.c source/functions/*.c  source/components/funcionarios/*.c source/functions/funcionarios/*.c  -c `pkg-config --libs gtk+-3.0`
	gcc *.o -o projeto

clean:
	rm projeto
	rm *.o
