#ifndef TREE_HPP
#define TREE_HPP

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

#include <queue>
#include <utility>

#include "node.hpp"

class Tree {
 public:
  Tree();
  
  ~Tree();
  // Getter
  Node* get_root() { return root_; }
  // Basic operations
  bool IsEmpty(Node*);
  bool Insert(const unsigned element, unsigned child_number, Node* node);
  bool Search(const unsigned, Node*);
  bool AlreadyInBranch(const unsigned element, Node* node);
//
  friend std::ostream& operator<<(std::ostream&, const Tree&);

 private:
  Node* root_;
  // Methods
  void DestroyTree(Node*& node);  // Used to destroy the tree
  bool PreorderSearch(
      Node*, const unsigned) const;  // Used to seach an element
  // Traversals
  void LevelTraversal(Node*) const;
};

#endif 