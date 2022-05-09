CC=gcc
OBJ=obj
BIN=bin

all: bin/wordCount 

obj/openHash.o: src/openHash.c src/openHash.h 
	[ -d $(OBJ) ] || mkdir -p $(OBJ)
	${CC} -c -o obj/openHash.o src/openHash.c 
bin/wordCount: obj/openHash.o src/wordCount.c
	[ -d $(BIN) ] || mkdir -p $(BIN)
	${CC} -o bin/wordCount obj/openHash.o src/wordCount.c

test01: bin/wordCount
	bin/wordCount 10 examples/001.txt
test02: bin/wordCount
	bin/wordCount 10 examples/345-0.txt
test03: bin/wordCount
	bin/wordCount 50 examples/345-0.txt
test04: bin/wordCount
	bin/wordCount 200 examples/345-0.txt
test05: bin/wordCount
	bin/wordCount 10 examples/1080-0.txt
test06: bin/wordCount
	bin/wordCount 50 examples/1080-0.txt
test07: bin/wordCount
	bin/wordCount 200 examples/1080-0.txt
test08: bin/wordCount
	bin/wordCount 10 examples/pg2265.txt
test09: bin/wordCount
	bin/wordCount 50 examples/pg2265.txt

#Remove any .0 files you make as well
clean: 
	rm -f bin/wordCount
	rm -f obj/openHash.o 	
	rm -f -d bin
	rm -f -d obj 
