#ifndef NODE_HPP
#define NODE_HPP

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

#include <iostream>
#include <vector>
#include <memory>
#include <utility>

class Node {
 public:
  Node(const unsigned data = 0, const unsigned child_number = 0);

  unsigned get_identifier() { return identifier_; }
  unsigned get_child_number() { return child_number_; }
  std::vector<Node*> get_childs() { return childs_; }

  friend std::ostream& operator<< (std::ostream&, Node&);

 private:
  unsigned identifier_{0};
  std::vector<Node*> childs_;
  unsigned child_number_{0};
};

Node::Node(const unsigned data, const unsigned child_number) : identifier_(data), child_number_(child_number) {}

std::ostream& operator<<(std::ostream& os, Node& node) {
  os << node.get_identifier();
  return os;
}
#endif