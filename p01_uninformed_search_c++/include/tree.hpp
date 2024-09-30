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

Tree::Tree() : root_(nullptr) {}

Tree::~Tree() {
  if (!IsEmpty(root_)) {
    DestroyTree(root_);
  }
}

void Tree::DestroyTree(Node*& node) {
  if (node != nullptr) {
    for (unsigned i = 0; i < node -> get_childs().size(); ++i) {
      DestroyTree(node -> get_childs()[i]);
    }
    delete node;
    node = nullptr;
  }
}

bool Tree::Insert(const unsigned element, unsigned child_number, Node* node) {
  //std::cout << "Insertando" << std::endl;
  if (Search(element, node)) {
    std::cout << "Element already in" << std::endl;
    return false;
  }
  if (this -> root_ == nullptr) {
    this -> root_ = new Node(element, child_number);
  } else {
    if (node -> get_childs().size() < node -> get_child_number()) {
      std::cout << "Metiendo" << std::endl;
      node -> get_childs().emplace_back(new Node(element, child_number, node));
    }
  }
  return true;
}

bool Tree::Search(const unsigned element, Node* node) {
  if (PreorderSearch(node, element)) {
    return true;
  }
  return false;
}

bool Tree::PreorderSearch(Node* node, unsigned element) const {
  if (node == nullptr) {
    return false;
  }
  if (node -> get_identifier() == element) {
    std::cout << node -> get_identifier() << " <- ";
    return true;
  }
  for (unsigned i = 0; i < node -> get_childs().size(); ++i) {
    if (PreorderSearch(node -> get_childs()[i], element)) {
      return true;
    }
  }
  return false;
}

bool Tree::AlreadyInBranch(const unsigned element, Node* node) {
  return true;
}

void Tree::LevelTraversal(Node* root) const {
  std::queue<std::pair<Node*, int>> node_queue;
  Node* node;
  int level{0}, current_level{0};
  node_queue.push(std::make_pair(root, 0));
  while (!node_queue.empty()) {
    node = node_queue.front().first;
    level = node_queue.front().second;
    node_queue.pop();
    if (level > current_level) {  // Line jump
      current_level = level;
      std::cout << std::endl;
    }
    if (node != nullptr) {  // Introduces both children in the queue
      std::cout << " " << *node;
      for (unsigned i = 0; i < node -> get_childs().size(); ++i) {
        node_queue.push(std::make_pair(node -> get_childs()[i], level + 1));
      }
      for (unsigned i = 0; i < (node -> get_child_number() - node -> get_childs().size()); ++i) {
        node_queue.push(std::make_pair(nullptr, level + 1));
      }
    } else {
      std::cout << " [.]";  // The child is null
    }
  }
}

bool Tree::IsEmpty(Node* node) {
  return node == nullptr;
}

std::ostream& operator<<(std::ostream& os, const Tree& tree) {
  tree.LevelTraversal(tree.root_);
  os << std::endl;
  return os;
}