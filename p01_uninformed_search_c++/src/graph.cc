/**
//    Universidad de La Laguna
//    Escuela Superior de Ingeniería y Tecnología
//    Grado en Ingeniería Informática
//    Asignatura: Inteligencia Artificial
//    Curso: 3º
//    Práctica 1: Búsquedas no informadas
//    Autor: José Gregorio Hernández Cruz
//    Correo: alu0101545820@ull.edu.es
//    Fecha: 24/09/2024
//    Archivo graph.py: 
//    Contiene la definición de los métodos que están declarados en la clase Cell.
//
//    Historial de revisiones
//      24/09/2024 - Creación (primera versión) del código
*/

#include "../include/graph.hpp"

Graph::Graph(std::string filename) {
  std::cout << "Creating graph" << std::endl;
  std::ifstream input_file{filename};
  if (input_file.is_open()) {
    //with open(filename, "r") as file:
    std::string line{""};
    input_file >> line;
    node_number_ = std::stoi(line);
    
    for (unsigned i = 0; i < node_number_; ++i) {
      std::vector<double> aux(node_number_);
      nodes_.emplace_back(aux);
    }
    //          number: int = int(file.readline())
    //          self.node_number = number
    //          for i in range(0, self.node_number):
    //              self.nodes.append([])
    unsigned row{0};
    unsigned column{0};
    unsigned limit{1};
    unsigned file_iterations{node_number_ - limit}; 
    //          row: int = 0
    //          column: int = 0
    //          limit: int = 1 
    //          file_iterations: int = self.node_number - limit
    bool first_line{true};
    while (getline(input_file, line)) {
      // for line in file:
      //std::cout << "Line: " << line << std::endl;
      //if (!line.empty()) {
      if (!first_line) {
        double edge_cost = std::stod(line);
        //std::cout << "Coste: " << edge_cost << std::endl;
        if (row == column) {
        nodes_[row][column] = 0;
        ++column;
        }
      //std::cout << "Row: " << row << " Column: " << column << std::endl;
      if (row < node_number_ && column < node_number_) {
        nodes_[row][column] = edge_cost;
        nodes_[column][row] = edge_cost;
        ++column;
      }
      //std::cout << *this << std::endl;
      if (file_iterations - limit == 0) {
        ++row;
        column = row;
        file_iterations = node_number_ - row - 1;
      } else {
        --file_iterations;
      }
      }
      first_line = false;
    }
    std::cout << "Graph created" << std::endl;
  } else {
    std::cerr << "File could not be opened. Please check file name." << std::endl;
  }
}

Graph::~Graph() {}

std::ostream& operator<<(std::ostream& os, Graph& graph) {
  os << "Node number: " << graph.node_number_ << std::endl;
  for (unsigned i = 0; i < graph.node_number_; ++i) {
    os << "Node: " << i + 1 << " [";
    for (unsigned j = 0; j < graph.nodes_.size(); ++j) {
      os << graph.nodes_[i][j] << " ";
    }
    os << "]" << std::endl;
  }
  return os;
}