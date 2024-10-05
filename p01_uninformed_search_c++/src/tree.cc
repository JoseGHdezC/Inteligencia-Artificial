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
 * Archivo tree.cc: 
 * Contiene la definición de los métodos que están declarados en la clase Tree.

 * Historial de revisiones
 *   24/09/2024 - Creación (primera versión) del código
 *   30/09/2024 - Desarrollo de funciones
 *   03/10/2024 - Comentarios
*/

#include "../include/tree.hpp"

/**
 * @brief Default class constructor
 */
Tree::Tree() : root_(nullptr) {}

/**
 * @brief Default class destructor
 */
Tree::~Tree() {
  if (!IsEmpty(root_)) {
    DestroyTree(root_);
  }
}

/**
 * @brief Private method used to ensure the nodes are deleted when the class are deleted
 * @param node: object node
 */
void Tree::DestroyTree(Node*& node) {
  if (node != nullptr) {
    for (unsigned i = 0; i < node -> get_childs().size(); ++i) {
      DestroyTree(node -> get_childs()[i]);
    }
    delete node;
    node = nullptr;
  }
}

/**
 * @brief Function that recovers a path following the predecessors of a node
 * @param node: node from which the path will begin
 * @param path: stores the path created
 * @param path_cost: stores the total cost following said path
 */
void Tree::GetPath(Node* node, std::vector<unsigned>& path, double& path_cost) {
  if (node != nullptr) {
    path.insert(path.begin(), (node -> get_identifier() + 1));
    path_cost += node -> get_cost();
    GetPath(node -> get_parent(), path, path_cost);
  }
}

/**
 * @brief Function that inserts a node in the tree
 * @param element: tag of the node that is being inserted
 * @param child_number: number of children the node has
 * @param node: points to the father node
 * @param cost: cost to return to the father node
 * @returns true if the node could be inserted, false otherwise
 */
bool Tree::Insert(const unsigned element, unsigned child_number, Node* node, double cost) {
  //std::cout << "Insertando" << std::endl;
  if (Search(element, node)) {
    std::cout << "Element already in" << std::endl;
    return false;
  }
  if (this -> root_ == nullptr) {
    this -> root_ = new Node(element, child_number);
  } else {
    if (node -> get_childs().size() < node -> get_child_number()) {
      //std::cout << "Metiendo" << std::endl;
      node -> get_childs().emplace_back(new Node(element, child_number, node, cost));
    }
  }
  return true;
}

/**
 * @brief Function that searches a given node in the tree
 * @param element: tag of the node that is being searched
 * @param node: node from which the search will be done
 * @returns true if the node is found, returs false otherwise
 */
bool Tree::Search(const unsigned element, Node* node) {
  //std::cout << "Searching" << std::endl;
  if (PreorderSearch(node, element)) {
    return true;
  }
  return false;
}

/**
 * @brief Function that does a preorder traversal in order to find a node
 * @param node: node from which the search is being done
 * @param element: tag of the element that is being searched
 * @returns true if the node is found, returns false otherwise
 */
bool Tree::PreorderSearch(Node* node, unsigned element) const {
  if (node == nullptr) {
    return false;
  }
  if (node -> get_identifier() == element) {
    std::cout << (node -> get_identifier()) + 1 << " <- ";
    return true;
  }
  for (unsigned i = 0; i < node -> get_childs().size(); ++i) {
    if (PreorderSearch(node -> get_childs()[i], element)) {
      std::cout << (node -> get_identifier()) + 1 << " <- ";
      return true;
    }
  }
  return false;
}

/**
 * @brief Funtion that looks for an existing node in the current brach
 * @param element: tag of the node that is being searched
 * @param node: points to the node that is being evaluated
 * @returns true is the node is already in the branch
 */
bool Tree::AlreadyInBranch(const unsigned element, Node* node) {
  //std::cout << "Looking for element" << std::endl;
  if (node == nullptr) {
    return false;
  } 
  //std::cout << "Actual node: " << node -> get_identifier() << std::endl;
  
  if (node -> get_identifier() == element) {
    return true;
  } else {
    if (AlreadyInBranch(element, node -> get_parent())) {
      return true;
    } 
  } 
  return false;
}

/**
 * @brief Funtion used to print the tree while doing a level traversal
 * @param root: starting pointer of the tree
 */
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
      for (unsigned i = 1; i < (node -> get_child_number() - node -> get_childs().size()); ++i) {
        node_queue.push(std::make_pair(nullptr, level + 1));
      }
    } else {
      std::cout << " [.]";  // The child is null
    }
  }
}

/**
 * @brief Function that checks if the tree is empty
 * @param node: node from which the tree is evaluated
 * @return 
 */
bool Tree::IsEmpty(Node* node) {
  return node == nullptr;
}

/**
 * @brief Standard Output stream operator overload
 * @param os: representation of the output stream
 * @param tree: object from the class Tree
 * @return os: in other to make the changes
 */
std::ostream& operator<<(std::ostream& os, const Tree& tree) {
  tree.LevelTraversal(tree.root_);
  os << std::endl;
  return os;
}