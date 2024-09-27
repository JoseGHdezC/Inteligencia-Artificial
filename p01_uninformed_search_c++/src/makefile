# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Algoritmos y Estructuras de Datos Avanzadas
#
# @author José Gregorio Hernández Cruz alu0101545820@ull.edu.es
# @date Sept, 2024
# @brief A Makefile for simple C++ programs

CXX = g++
CXXFLAGS = -std=c++20 -g -O3 -Wall -pedantic
LDFLAGS =

all: p01_uninformed_search

p01_uninformed_search: graph.o tools.o main.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY: all clean

clean :
	@rm -rf *.o *gch *.out
	rm p01_uninformed_search
	rm -rf *~ basura
	rm -rf a.out