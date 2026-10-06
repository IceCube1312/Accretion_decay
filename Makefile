CC = gcc
CFLAGS = -O2 -Wall -I C:\raylib\raylib\src
LDFLAGS = -L C:\raylib\raylib\src -lraylib -lopengl32 -lgdi32 -lwinmm

SRC = main.c accr.c
OBJ = $(SRC:.c=.o)
EXEC = accretion.exe

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del *.o $(EXEC)
