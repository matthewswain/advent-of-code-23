run: build
	bin/main

build: shared
	mkdir -p bin
	gcc -o bin/main -Wall -Werror -Wextra -Lbin -lshared src/main.c src/**/*.c

clean:
	rm -rf bin/*

shared:
	mkdir -p bin/shared
	gcc -c -Wall -Werror -Wextra src/shared/*.c
	mv *.o bin/shared
	ar -rcs bin/libshared.a bin/shared/*.o

test: shared
	mkdir -p bin
	gcc -o bin/test -Wall -Werror -Wextra -Lbin -lshared src/test.c src/**/*.c
	bin/test

debug: shared
	mkdir -p bin
	gcc -g -o bin/main -Wall -Werror -Wextra -Lbin -lshared src/main.c src/**/*.c
	lldb bin/main

debug_test: shared
	mkdir -p bin
	gcc -g -o bin/test -Wall -Werror -Wextra -Lbin -lshared src/test.c src/**/*.c
	lldb bin/test
