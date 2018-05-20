CPP=g++ -std=c++11
CC=gcc
SRC=src
BUILD=build
BIN=$(BUILD)\bin
OBJ=$(BUILD)\obj
MD=md
IF_NO_EXIST=if not exist

SRC_FILES := $(wildcard $(SRC)\*.c)
OBJ_FILES := $(patsubst $(SRC)/%.c,$(OBJ)/%.o,$(wildcard $(SRC)/*.c))

MODULES = $(wildcard $(SRC)\*.c)
OBJS = $(wildcard *.o)

bin.exe: clear dirs $(OBJ_FILES)
	$(CC) main.c -o $(BIN)\$@ $(OBJ_FILES)

clear:
	cls

dirs:
	$(IF_NO_EXIST) $(BIN) $(MD) $(BIN)
	$(IF_NO_EXIST) $(OBJ) $(MD) $(OBJ)

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) -c -o $@ $<

run: bin.exe
	$(BIN)\$<

clean:
	rd /S /Q $(BUILD)
