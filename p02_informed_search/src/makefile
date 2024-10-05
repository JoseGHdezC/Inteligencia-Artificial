# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Algoritmos y Estructuras de Datos Avanzadas
#
# @author José Gregorio Hernández Cruz alu0101545820@ull.edu.es
# @date Sept, 2024
# @brief A Makefile for simple C++ programs

CXX = g++
CXXFLAGS = -std=c++17 -g -O3 -Wall -pedantic
LDFLAGS =

all: p02_informed_search

p02_informed_search: maze.o tools.o tree.o main.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY: all clean

clean :
	@rm -rf *.o *gch *.out
	rm p02_informed_search
	rm -rf *~ basura
	rm -rf a.out