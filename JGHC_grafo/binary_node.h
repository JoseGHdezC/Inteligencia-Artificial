#ifndef BINARY_NODE_H_
#define BINARY_NODE_H_

/** Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructuras de Datos Avanzadas
 * Curso: 2º
 * Práctica 6: Implementación del TDA Árbol
 * Autor: José Gregorio Hernández Cruz
 * Correo: alu0101545820@ull.edu.es
 * Fecha: 12/04/2024
 * Archivo binary_node.h:
 * Contiene la declaración y definición de la clase NodeB 
 * Referencias:
 * Enlaces de interés:
 *
 * Historial de revisiones
 * 12/04/2024 - Creación (primera versión) del código
 * 19/04/2024 - Desarrollo de funciones
 * 19/04/2024 - Finalización y depuración del código
 * 19/04/2024 - Inclusión de comentarios extraordinarios
 */

#include <iostream>

/**
 * @class NodeB
 * @brief Represents a node that belongs to a binary tree
 * @tparam Key: Type of the element to operate
 */
template <class Key>
class NodeB {
 public:
  // Constructor
  NodeB(const Key& data, NodeB<Key>* left = nullptr,
        NodeB<Key>* right = nullptr);

  // Getters
  const Key& getData() const { return data_; }
  NodeB<Key>*& getLeft() { return left_; }
  NodeB<Key>*& getRight() { return right_; }
  // Operator overload
  template <class T>
  friend std::ostream& operator<<(std::ostream&, NodeB<T>*);

 private:
  // Attributes
  Key data_;           // Element that is contained
  NodeB<Key>* left_;   // Pointer to the node left child
  NodeB<Key>* right_;  // Pointer to the node right child
};

/**
 * @brief Class constructor
 * @param data: element to be contained
 * @param left: pointer to the left child
 * @param right: pointer to the right child
 */
template <class Key>
NodeB<Key>::NodeB(const Key& data, NodeB<Key>* left, NodeB<Key>* right)
    : data_(data), left_(left), right_(right) {}

/**
 * @brief Standard output stream operator overload
 * @param os: representation of the output stream
 * @param node: object from the NodeB class to be printed
 * @returns os to apply the changes
 */
template <class T>
std::ostream& operator<<(std::ostream& os, NodeB<T>* node) {
  os << node -> data_;
  return os;
}

#endif