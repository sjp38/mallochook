all: program mallochook.so

program: program.c
	gcc -o program program.c


mallochook.so: mallochook.c
	gcc -shared -fPIC mallochook.c -o mallochook.so
