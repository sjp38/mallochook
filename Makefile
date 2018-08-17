all: program mallochook.so

program: program.c
	gcc -o program program.c


mallochook.so: mallochook.c
	gcc -shared -fPIC mallochook.c -o mallochook.so -ldl

run_unhooked: program
	./program

run_hooked: program mallochook.so
	LD_PRELOAD=$(PWD)/mallochook.so ./program

clean:
	rm -fr mallochook.so program
