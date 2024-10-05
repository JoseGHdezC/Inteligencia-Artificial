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
 * Archivo tree.hpp: 
 * Contiene la definición de la clase Tree.

 * Historial de revisiones
 *   24/09/2024 - Creación (primera versión) del código
 *   30/09/2024 - Desarrollo de funciones
 *   03/10/2024 - Comentarios
*/

#include <queue>
#include <utility>

#include "node.hpp"

/**
 * @class Tree
 * @brief Represents the solution tree created from a traversal
 */
class Tree {
 public:
  // Constructor
  Tree();
  // Destructor
  ~Tree();

  // Getter
  Node* get_root() { return root_; }
  // Basic operations
  bool IsEmpty(Node*);
  void GetPath(Node*, std::vector<unsigned>&, double&);
  bool Insert(const unsigned element, unsigned child_number, Node* node, double cost);
  bool Search(const unsigned, Node*);
  bool AlreadyInBranch(const unsigned element, Node* node);
  
  // I/O operator overload
  friend std::ostream& operator<<(std::ostream&, const Tree&);

 private:
  Node* root_;  // Start of the tree
  // Methods
  void DestroyTree(Node*& node);  // Used to destroy the tree
  bool PreorderSearch(
      Node*, const unsigned) const;  // Used to seach an element
  // Traversals
  void LevelTraversal(Node*) const;
};

#endif 