#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

/** Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructuras de Datos Avanzadas
 * Curso: 2º
 * Práctica 6: Implementación del TDA Árbol
 * Autor: José Gregorio Hernández Cruz
 * Correo: alu0101545820@ull.edu.es
 * Fecha: 12/04/2024
 * Archivo binary_tree.h:
 * Contiene la declaración y definición de la clase BinaryTree, así como las
 * clases derivadas de esta:
 *  - BalancedTree: árbol equilibrado
 *  - BinarySearchTree: árbol binario de búsqueda
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
#include <queue>
#include <utility>

#include "../include/binary_node.h"

/**
 * @class BinaryTree
 * @brief Represents a binary tree
 * @tparam Key
 */
template <class Key>
class BinaryTree {
 public:
  // Constructor
  BinaryTree();
  // Destructor
  virtual ~BinaryTree();

  // Size getters
  virtual const int Size() { return BranchSize(root_); }
  virtual const int TreeHight() { return BranchHeight(root_); }

  // Basic operations
  virtual bool IsEmpty(NodeB<Key>*);
  virtual bool IsLeaf(NodeB<Key>*);
  virtual bool Insert(const Key&) = 0;
  virtual bool Search(const Key&) = 0;

  // Traversals
  virtual void InorderTraversalPublic() { InorderTraversal(root_); }

  // Operators overload
  template <class T>
  friend std::ostream& operator<<(std::ostream&, const BinaryTree<T>&);

 protected:
  // Attribute
  NodeB<Key>* root_;  // Pointer to the first node in the tree

  // Methods
  void DestroyTree(NodeB<Key>*& node);  // Used to destroy the tree
  const int BranchSize(NodeB<Key>*);    // Calculates the ammount of nodes
  const int BranchHeight(
      NodeB<Key>*);  // Calculates the total height of the tree
  virtual bool PreorderTraversalSearch(
      NodeB<Key>*, const Key&) const;  // Used to seach an element
  // Traversals
  virtual void InorderTraversal(NodeB<Key>*) const;
  virtual void LevelTraversal(NodeB<Key>*) const;
};

/**
 * @brief Class default constructor
 * @tparam Key
 */
template <class Key>
BinaryTree<Key>::BinaryTree() : root_(nullptr) {}

/**
 * @brief Class destructor
 * @tparam Key
 */
template <class Key>
BinaryTree<Key>::~BinaryTree() {
  if (!IsEmpty(root_)) {
    DestroyTree(root_);
  }
}

/**
 * @brief Method that implements the algorithm to destroy all nodes within the
 * tree
 * @tparam Key
 * @param node: pointer to the node that will be evaluated
 */
template <class Key>
void BinaryTree<Key>::DestroyTree(NodeB<Key>*& node) {
  if (node != nullptr) {
    DestroyTree(node -> getLeft());
    DestroyTree(node -> getRight());
    delete node;
    node = nullptr;
  }
}

/**
 * @brief Does a preorder traversal in order to search a certain element
 * @tparam Key
 * @param node: pointer to the node that will be evaluated
 * @param element: element that will be searched with the algorithm
 * @returns true if the element was found. It returns false otherwise
 */
template <class Key>
bool BinaryTree<Key>::PreorderTraversalSearch(NodeB<Key>* node,
                                              const Key& element) const {
  if (node == nullptr) {
    return false;
  }
  if (node -> getData() == element) {
    std::cout << node -> getData() << " <- ";
    return true;
  }
  if (PreorderTraversalSearch(node -> getLeft(), element)) {
    std::cout << node -> getData() << " <- ";
    return true;
  }
  if (PreorderTraversalSearch(node->getRight(), element)) {
    std::cout << node -> getData() << "<-";
    return true;
  }
  return false;
}

/**
 * @brief Does an inorder traversal to print the nodes
 * @tparam Key
 * @param node: pointer to the node that will be evaluated
 */
template <class Key>
void BinaryTree<Key>::InorderTraversal(NodeB<Key>* node) const {
  if (node != nullptr) {
    InorderTraversal(node -> getLeft());
    std::cout << node << " ";
    InorderTraversal(node -> getRight());
  }
}

/**
 * @brief Does a traversal by levels in order to print the nodes
 * @tparam Key
 * @param root: pointer to the first node within the tree
 */
template <class Key>
void BinaryTree<Key>::LevelTraversal(NodeB<Key>* root) const {
  std::queue<std::pair<NodeB<Key>*, int>> node_queue;
  NodeB<Key>* node;
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
      std::cout << " " << node;
      node_queue.push(std::make_pair(node -> getLeft(), level + 1));
      node_queue.push(std::make_pair(node -> getRight(), level + 1));
    } else {
      std::cout << " [.]";  // The child is null
    }
  }
}

/**
 * @brief Checks if the tree is empty
 * @tparam Key
 * @param node: pointer to the node that will be evaluated
 * @returns true if the tree is empty. It returns false otherwise
 */
template <class Key>
bool BinaryTree<Key>::IsEmpty(NodeB<Key>* node) {
  return node == nullptr;
}

/**
 * @brief Checks if a node is a leaf node or not
 * @tparam Key
 * @param node: pointer to the node that will be evaluated
 * @returns true if the node is a leaf node. It returns false otherwise
 */
template <class Key>
bool BinaryTree<Key>::IsLeaf(NodeB<Key>* node) {
  return !node -> getRight() && !node -> getRight();
}

/**
 * @brief Calculates the number of nodes that are on a branch
 * @tparam Key
 * @param node: pointer to the node that will be evaluated
 * @returns the total number of nodes that are after a certain node
 */
template <class Key>
const int BinaryTree<Key>::BranchSize(NodeB<Key>* node) {
  if (node == nullptr) {
    return 0;
  }
  return (1 + BranchSize(node -> getLeft()) + BranchSize(node -> getRight()));
}

/**
 * @brief Calculates the height of a branch, that is the number of levels after
 * a node
 * @tparam Key
 * @param node: pointer to the node that will be evaluated
 * @returns the number of levels that exist after a certain node
 */
template <class Key>
const int BinaryTree<Key>::BranchHeight(NodeB<Key>* node) {
  if (node == nullptr) {
    return 0;
  }
  int height_left = BranchHeight(node -> getLeft());
  int height_right = BranchHeight(node -> getRight());
  if (height_right > height_left) {
    return ++height_right;
  } else {
    return ++height_left;
  }
}

/**
 * @brief Standard output stream operator overload
 * @param os: representation of the output stream
 * @param node: object from the NodeB class to be printed
 * @returns os to apply the changes
 */
template <class T>
std::ostream& operator<<(std::ostream& os, const BinaryTree<T>& tree) {
  tree.LevelTraversal(tree.root_);
  os << std::endl;
  return os;
}

// ###########################-BalancedTree-#####################

/**
 * @class BalancedTree
 * @brief Derived class from BinaryTree that represents a binary tree that is
 * node-based balanced
 * @tparam Key: type of data to operate
 */
template <class Key>
class BalancedTree : public BinaryTree<Key> {
 public:
  // Constructor
  BalancedTree();

  // Basic operations
  virtual bool Insert(const Key&);
  virtual bool Search(const Key&);

 private:
  // Method
  void NodeBalanceInsert(const Key&, NodeB<Key>*);  // Inserts to keep balance
};

/**
 * @brief Defaut class constructor that uses the base class constructor
 * @tparam Key
 */
template <class Key>
BalancedTree<Key>::BalancedTree() {}

/**
 * @brief Inserts a given element in the tree if it is not already in it
 * @tparam Key
 * @param element: element to introduce in the tree
 * @returns true if the element could be inserted successfully. It returns false
 * otherwise.
 */
template <class Key>
bool BalancedTree<Key>::Insert(const Key& element) {
  if (Search(element)) {
    std::cout << "Element " << element << " is already in the tree."
              << std::endl;
    return false;
  }
  if (this -> root_ == nullptr) {
    this -> root_ = new NodeB<Key>(element, nullptr, nullptr);
  } else {
    NodeBalanceInsert(element, this -> root_);
  }
  return true;
}

/**
 * @brief Method that implements the algorithm to insert an element and keep the
 * balance in the tree
 * @tparam Key
 * @param element: element to be inserted in the tree
 * @param node: pointer to the node that will be evaluated
 */
template <class Key>
void BalancedTree<Key>::NodeBalanceInsert(const Key& element,
                                          NodeB<Key>* node) {
  if (this -> BranchSize(node -> getLeft()) <= this -> BranchSize(node -> getRight())) {
    if (node -> getLeft() != nullptr) {
      NodeBalanceInsert(element, node -> getLeft());
    } else {
      node -> getLeft() = new NodeB<Key>(element, nullptr, nullptr);
    }
  } else {
    if (node -> getRight() != nullptr) {
      NodeBalanceInsert(element, node -> getRight());
    } else {
      node -> getRight() = new NodeB<Key>(element, nullptr, nullptr);
    }
  }
}

/**
 * @brief Searches a given element within the tree
 * @tparam Key
 * @param element: element to search in the tree
 * @returns true if the element was found. It returns false otherwise
 */
template <class Key>
bool BalancedTree<Key>::Search(const Key& element) {
  if (this -> PreorderTraversalSearch(this -> root_, element)) {
    return true;
  }
  return false;
}

// #########################-BinarySearchTree-#################

/**
 * @class BinarySearchTree
 * @brief Derived class from BinaryTree that represents a tree sorted by keys
 * @tparam Key: data type to be used in the operations
 */
template <class Key>
class BinarySearchTree : public BinaryTree<Key> {
 public:
  // Constructor
  BinarySearchTree();

  // Basic operations
  virtual bool Insert(const Key&);
  virtual bool Search(const Key&);

 private:
  // Methods
  bool SearchBranch(NodeB<Key>*, Key);   // Searches in the subtree
  bool InsertBranch(NodeB<Key>*&, Key);  // Inserts in the subtree
};

/**
 * @brief Default class constructor that uses the base class constructor
 * @tparam Key
 */
template <class Key>
BinarySearchTree<Key>::BinarySearchTree() {}

/**
 * @brief Insert a given element in the tree if it not already in it
 * @tparam Key
 * @param element: element to insert in the tree
 * @returns true if the element could be inserted succesfully. It returns false
 * otherwise
 */
template <class Key>
bool BinarySearchTree<Key>::Insert(const Key& element) {
  if (Search(element)) {
    return false;
  }
  return InsertBranch(this -> root_, element);
}

/**
 * @brief Method that implements the algorithm used to insert an element given
 * its relation with the rest of inserted keys
 * @tparam Key
 * @param node: pointer to node that will be evaluated
 * @param element: element that will be inserted
 * @returns true if the element could be inserted successfully. It returns false
 * otherwise
 */
template <class Key>
bool BinarySearchTree<Key>::InsertBranch(NodeB<Key>*& node, Key element) {
  if (node == nullptr) {
    node = new NodeB<Key>(element, nullptr, nullptr);
    return true;
  } else if (element < node -> getData()) {
    return InsertBranch(node -> getLeft(), element);
  } else {
    return InsertBranch(node -> getRight(), element);
  }
  return false;
}

/**
 * @brief Searches a given key within the tree
 * @tparam Key
 * @param element: element to seach in the tree
 * @returns true if the element was found. It returns false otherwise
 */
template <class Key>
bool BinarySearchTree<Key>::Search(const Key& element) {
  return SearchBranch(this -> root_, element);
}

/**
 * @brief Method that implements the algorithm to search an element effectively
 * in a binary search tree
 * @tparam Key
 * @param node: pointer to node that will be evaluated
 * @param element: element that will be searched
 * @returns true if the element was found. It returns false otherwise
 */
template <class Key>
bool BinarySearchTree<Key>::SearchBranch(NodeB<Key>* node, Key element) {
  if (node == nullptr) {
    return false;
  }
  if (element == node -> getData()) {
    std::cout << node -> getData() << " <- ";
    return true;
  }
  if (element < node -> getData()) {
    if (SearchBranch(node -> getLeft(), element)) {
      std::cout << node -> getData() << " <- ";
      return true;
    }
  }
  if (SearchBranch(node -> getRight(), element)) {
    std::cout << node -> getData() << " <- ";
    return true;
  }
  return false;
}

#endif