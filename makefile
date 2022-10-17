run: all
	clear
	./projeto

all:
	gcc source/main.c source/menus/*.c source/functions/*.c source/components/*c source/functions/validations/*.c -Wall  -c
	gcc -Wall *.o -o projeto
	
clean:
	rm projeto
	rm *.o