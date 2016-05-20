.PHONY: clean prepare qwrt test

bin/qwrt: prepare obj/lab2.o obj/qwrt.o
	gcc -o bin/qwrt obj/lab2.o obj/qwrt.o -lm
	
bin/test: prepare obj/qwrt_test.o obj/ctest.o obj/qwrt.o
	gcc -o bin/test obj/qwrt_test.o obj/ctest.o obj/qwrt.o -lm

obj/lab2.o: prepare
	gcc -c src/lab2.c -o obj/lab2.o

obj/qwrt.o: prepare
	gcc -c src/qwrt.c -o obj/qwrt.o

obj/qwrt_test.o: prepare
	gcc -c test/qwrt_test.c -o obj/qwrt_test.o -Ithirdparty -Isrc
	
obj/ctest.o: prepare
	gcc -c test/ctest.c -o obj/ctest.o -Ithirdparty

clean:
	rm -rf bin/* obj/*
	
qwrt: bin/qwrt
	bin/qwrt
	
test: bin/test
	bin/test

prepare: bin obj

bin:
	mkdir bin

obj:
	mkdir obj