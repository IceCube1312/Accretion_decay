# Compiler and flags
CC = gcc
CFLAGS = -Wall -std=c99 -O2 -I"C:/raylib/raylib/src"
LDFLAGS = -L"C:/raylib/raylib/src"
LDLIBS = -lraylib -lopengl32 -lgdi32 -lwinmm

# Target and objects
TARGET = accretion.exe
OBJS = main.o accr.o

# Default rule
all: $(TARGET)

# Linking rule
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LDFLAGS) $(LDLIBS)

# Compilation rule for .c to .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Cleanup rule
clean:
	del /Q $(OBJS) $(TARGET)
