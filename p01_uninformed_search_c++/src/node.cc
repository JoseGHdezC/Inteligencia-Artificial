#include "../include/node.hpp"

Node::Node(const unsigned data, const unsigned child_number, 
           Node* predecesor) : identifier_(data), child_number_(child_number), 
                               predecesor_node_(predecesor) {}

Node::~Node() {
  for (unsigned i = 0; i < childs_.size(); ++i) {
    delete childs_[i];
  }
}

std::ostream& operator<<(std::ostream& os, Node& node) {
  os << node.get_identifier();
  return os;
}