run: build
	bin/main

build: shared
	mkdir -p bin
	gcc -o bin/main -Wall -Werror -Wextra -Lbin -lshared src/main.c src/01/*.c src/02/*.c src/03/*.c

clean:
	rm -rf bin/*

shared:
	mkdir -p bin/shared
	gcc -c -Wall -Werror -Wextra src/shared/*.c
	mv *.o bin/shared
	ar -rcs bin/libshared.a bin/shared/*.o

test: shared
	mkdir -p bin
	gcc -o bin/test -Wall -Werror -Wextra -Lbin -lshared src/test.c src/01/*.c src/02/*.c src/03/*.c
	bin/test

debug: shared
	mkdir -p bin
	gcc -g -o bin/main -Wall -Werror -Wextra -Lbin -lshared src/main.c src/01/*.c src/02/*.c src/03/*.c
	lldb bin/main

debug_test: shared
	mkdir -p bin
	gcc -g -o bin/test -Wall -Werror -Wextra -Lbin -lshared src/test.c src/01/*.c src/02/*.c src/03/*.c
	lldb bin/test
