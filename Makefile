CC = g++
CFLAGS = -Wall
LDFLAGS = -lSDL2
SOURCES = $(wildcard src/Browser/*.cpp src/Core/*.cpp src/HTML/*.cpp src/JS/*.cpp)
OUTPUT = Build/netree

all:
	$(CC) $(CFLAGS) $(SOURCES) -o $(OUTPUT) $(LDFLAGS)

clean:
	rm -f $(OUTPUT)
