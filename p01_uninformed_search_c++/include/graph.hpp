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
 * Archivo graph.hpp:
 * Contiene la definición de la clase Graph.
 *
 * Historial de revisiones
 *   24/09/2024 - Creación (primera versión) del código
 *   30/09/2024 - Desarrollo de funciones
 *   03/10/2024 - Comentarios
 */

// Implementar como matriz
// No hay arista de i a i
#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#include "../include/tree.hpp"

/**
 * @class Graph
 * @brief Contains the graph's situation by using a matrix
 */
class Graph {
 public:
  // Constructor
  Graph(std::string filename);
  // Destructor
  ~Graph();

  // Operations
  unsigned CountChilds(unsigned);
  void BranchSearch();
  void DeepSearch();

  // I/O
  friend std::ostream& operator<<(std::ostream&, Graph&);

 private:
  std::vector<std::vector<double>> nodes_;  // Cost matrix
  unsigned node_number_{0};                 // Number of nodes
  unsigned edge_number_{0};                 // Number of edges
  // Methods
  void BFS(unsigned, unsigned, std::vector<unsigned>&, std::vector<unsigned>&,
           Tree&);  // Branch First Travesal
  void DFS(unsigned, unsigned, std::vector<unsigned>&, std::vector<unsigned>&,
           Tree&);  // Deep First Traversal
};

/**
 * @brief Function that prints a given vector
 * @param vector to be printed
 */
void PrintVector(const std::vector<unsigned>&);

#endif