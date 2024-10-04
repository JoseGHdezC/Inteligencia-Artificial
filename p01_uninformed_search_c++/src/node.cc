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
 * Archivo node.cc:
 * Contiene la definición de los métodos que están declarados en la clase Node.

 * Historial de revisiones
 *   24/09/2024 - Creación (primera versión) del código
 *   30/09/2024 - Desarrollo de funciones
 *   03/10/2024 - Comentarios
*/

#include "../include/node.hpp"

/**
 * @brief Default class constructor
 * @param data: tag that identifies the node
 * @param child_number: number of childs that the node has
 * @param predecesor: pointer to the parent node
 * @param predecesor_cost: cost of the transition from the node to the parent
 * node
 */
Node::Node(const unsigned data, const unsigned child_number, Node* predecesor,
           const double predecesor_cost)
    : identifier_(data),
      child_number_(child_number),
      predecesor_node_(predecesor),
      predecesor_cost_(predecesor_cost) {}

/**
 * @brief Defualt class destructor
 */
Node::~Node() {
  for (unsigned i = 0; i < childs_.size(); ++i) {
    delete childs_[i];
  }
}

/**
 * @brief Standard Output stream operator overload
 * @param os: representation of the output stream
 * @param node: object from the class Node
 * @return os: in other to make the changes
 */
std::ostream& operator<<(std::ostream& os, Node& node) {
  os << node.get_identifier();
  return os;
}