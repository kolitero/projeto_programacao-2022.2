run: all
	clear
	./projeto

all:
	gcc -Wall `pkg-config --cflags gtk+-3.0` source/main.c source/components/*.c source/functions/*.c  source/components/funcionarios/*.c source/functions/funcionarios/*.c  -o projeto `pkg-config --libs gtk+-3.0`

clean:
	rm projeto
	rm *.o