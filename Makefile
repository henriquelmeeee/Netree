CC = g++
CFLAGS = -Wall
LDFLAGS = -lSDL2
LDFLAGS += $(shell pkg-config --cflags --libs webkit2gtk-4.0 gtk+-3.0)
SOURCES = $(wildcard src/Browser/*.cpp src/Core/*.cpp src/HTML/*.cpp src/JS/*.cpp)
OUTPUT = Build/netree

all:
	$(CC) $(SOURCES) -o $(OUTPUT) $(LDFLAGS)

clean:
	rm -f $(OUTPUT)
