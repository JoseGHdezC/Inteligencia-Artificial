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
 * Archivo node.hpp:
 * Contiene la definición de la clase Node.
 *
 * Historial de revisiones
 *   24/09/2024 - Creación (primera versión) del código
 *   30/09/2024 - Desarrollo de funciones
 *   03/10/2024 - Comentarios
 */

#include <iostream>
#include <memory>
#include <utility>
#include <vector>

/**
 * @class Node
 * @brief Represents a vertex in the graph and serves as an element in the
 * generated tree
 */
class Node {
 public:
  // Constructor
  Node(const unsigned data = 0, const unsigned child_number = 0,
       Node* predecesor = nullptr, const double predecesor_cost = 0);
  // Destructor
  ~Node();

  // Getters
  double get_cost() { return predecesor_cost_; }
  unsigned get_identifier() { return identifier_; }
  unsigned get_child_number() { return child_number_; }
  std::vector<Node*>& get_childs() { return childs_; }
  Node* get_parent() { return predecesor_node_; }

  // I/O operator overload
  friend std::ostream& operator<<(std::ostream&, Node&);

 private:
  // Attributes
  unsigned identifier_{0};     // Tag used to reference the node
  unsigned child_number_;      // Number of children
  std::vector<Node*> childs_;  // Nodes that are successors from the object
  Node* predecesor_node_;      // Points to the parent node
  double predecesor_cost_;  // Cost required to go from the node to his parent
};

#endif