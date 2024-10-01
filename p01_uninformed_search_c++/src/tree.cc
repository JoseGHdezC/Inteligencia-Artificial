#include "../include/tree.hpp"

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

void Tree::GetPath(Node* node, std::vector<unsigned>& path, double& path_cost) {
  if (node != nullptr) {
    path.insert(path.begin(), (node -> get_identifier() + 1));
    path_cost += node -> get_cost();
    GetPath(node -> get_parent(), path, path_cost);
  }
}

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

//Pasa el coste por referencia, si no, ponlo a cero
bool Tree::Search(const unsigned element, Node* node) {
  //std::cout << "Searching" << std::endl;
  if (PreorderSearch(node, element)) {
    return true;
  }
  return false;
}

// Problema con el camino mostrado
// Hacerlo por postorden
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