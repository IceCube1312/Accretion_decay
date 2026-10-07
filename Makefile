CC = gcc
CFLAGS = -O2 -Wall -I vendor/include
LDFLAGS = vendor/lib/libraylib.a -lopengl32 -lgdi32 -lwinmm

SRC = main.c accr.c
OBJ = $(SRC:.c=.o)
EXEC = accretion.exe

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(EXEC)
