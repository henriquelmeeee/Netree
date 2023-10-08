#!/bin/sh

# Definição das variáveis
CC=g++
CFLAGS="-Wall"
LDFLAGS="-lSDL2"
SOURCES=$(find src/Browser src/Core src/HTML src/JS -name "*.cpp")
OUTPUT="Build/netree"

# Compilação
$CC $CFLAGS $SOURCES -o $OUTPUT $LDFLAGS

# Limpeza (opcional, você pode rodar isso manualmente quando precisar)
# rm -f $OUTPUT

