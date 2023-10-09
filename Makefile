CC = g++
CFLAGS = -Wall
LDFLAGS = -lSDL2
CFLAGS += $(shell pkg-config --cflags webkitgtk-6.0)
LDFLAGS += $(shell pkg-config --libs webkitgtk-6.0)
SOURCES = $(wildcard src/Browser/*.cpp src/Core/*.cpp src/HTML/*.cpp src/JS/*.cpp)
OUTPUT = Build/netree

all:
	$(CC) $(CFLAGS) $(SOURCES) -o $(OUTPUT) $(LDFLAGS)

clean:
	rm -f $(OUTPUT)
