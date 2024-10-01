#ifndef GRAPH_HPP
#define GRAPH_HPP

/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Inteligencia Artificial
 * Curso: 3º
 * Práctica 1: Búsquedas no informadas
 * Autor: José Gregorio Hernández Cruz
 * Correo: alu0101545820@ull.edu.es
 * Fecha: 24/09/2024
 * Archivo graph.py: 
 * Contiene la definición de los métodos que están declarados en la clase Cell.
 * 
 * Historial de revisiones
 *   24/09/2024 - Creación (primera versión) del código
*/

// Implementar como matriz
// No hay arista de i a i
#include <vector>
#include <utility>
#include <string>
#include <fstream>
#include <iostream>
#include <queue>
#include <stack>
#include <set>


#include "../include/tree.hpp"

class Graph {
 public:
  Graph(std::string filename);
  ~Graph();
  
  unsigned CountChilds(unsigned);
  void BranchSearch();
  void DeepSearch();
  friend std::ostream& operator<<(std::ostream&, Graph&);

 private:
  std::vector<std::vector<double>> nodes_;
  unsigned node_number_{0};
  unsigned edge_number_{0};

  void BFS(unsigned, unsigned, std::vector<unsigned>&, std::vector<unsigned>&, Tree&);
  void DFS(unsigned, unsigned, std::vector<unsigned>&, std::vector<unsigned>&, Tree&);
};

void PrintVector(const std::vector<unsigned>&);


#endif