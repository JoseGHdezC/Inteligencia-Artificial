/**
//    Universidad de La Laguna
//    Escuela Superior de Ingeniería y Tecnología
//    Grado en Ingeniería Informática
//    Asignatura: Inteligencia Artificial
//    Curso: 3º
//    Práctica 1: Búsquedas no informadas
//    Autor: José Gregorio Hernández Cruz
//    Correo: alu0101545820@ull.edu.es
//    Fecha: 24/09/2024
//    Archivo graph.py: 
//    Contiene la definición de los métodos que están declarados en la clase Cell.
//
//    Historial de revisiones
//      24/09/2024 - Creación (primera versión) del código
*/

#include "../include/graph.hpp"

Graph::Graph(std::string filename) {
  std::cout << "Creating graph" << std::endl;
  std::ifstream input_file{filename};
  if (input_file.is_open()) {
    std::string line{""};
    input_file >> line;
    node_number_ = std::stoi(line);
    
    for (unsigned i = 0; i < node_number_; ++i) {
      std::vector<double> aux(node_number_);
      nodes_.emplace_back(aux);
    }
    
    unsigned row{0};
    unsigned column{0};
    unsigned limit{1};
    unsigned file_iterations{node_number_ - limit}; 

    bool first_line{true};
    while (getline(input_file, line)) {
      if (!first_line) {
        double edge_cost = std::stod(line);
      
        if (row == column) {
        nodes_[row][column] = 0;
        ++column;
        }
        if (row < node_number_ && column < node_number_) {
          nodes_[row][column] = edge_cost;
          nodes_[column][row] = edge_cost;
          ++column;
        }
        if (file_iterations - limit == 0) {
          ++row;
          column = row;
          file_iterations = node_number_ - row - 1;
        } else {
          --file_iterations;
        }
        if (edge_cost > -1) {
          ++edge_number_;
        }
      }
      first_line = false;
    }
    std::cout << "Graph created" << std::endl;
  } else {
    std::cerr << "File could not be opened. Please check file name." << std::endl;
  }
}

Graph::~Graph() {}

void Graph::BranchSearch() {
  unsigned start_node{0};
  unsigned end_node{0};
  std::cout << "Doing a Branch Search" << std::endl;
  std::cout << "---------------------" << std::endl;
  std::cout << "Introduce start node [1-" << node_number_ << "]: ";
  std::cin >> start_node;
  std::cout << "Introduce destin node [1-" << node_number_ << "]: ";
  std::cin >> end_node;
  
  std::cout << "----------------------" << std::endl;
  std::cout << "Graph's node number: " << node_number_ << std::endl;
  std::cout << "Graph's edge number: " << edge_number_ << std::endl;
  std::cout << "Starting node: " << start_node << std::endl;
  std::cout << "Destin node: " << end_node << std::endl;

  --start_node;
  --end_node;

  std::vector<unsigned> generated_nodes;
  std::vector<unsigned> inspected_nodes;
  //Tree solution_tree;
  int cost{0};

  BFS(start_node, end_node, generated_nodes, inspected_nodes, cost);
  std::cout << "--------------" << std::endl;
  std::cout << "Path: " << std::endl;
  std::cout << "--------------" << std::endl;
  std::cout << "Cost: " << cost << std::endl;
}

void Graph::BFS(unsigned start, unsigned end, std::vector<unsigned>& generated_nodes, std::vector<unsigned>& inspected_nodes, int& cost) {
  unsigned iteration{1};
  std::queue<unsigned> queue;
  queue.push(start);
  generated_nodes.emplace_back(start);

  std::cout << "---------------" << std::endl;
  std::cout << "Iteration: " << iteration << std::endl;
  std::cout << "Generated nodes: ";
  PrintVector(generated_nodes);
  std::cout << "Inspected nodes: ";
  PrintVector(inspected_nodes);

  for (int i = 0; i < 10; ++i) {
  //while (!queue.empty() && !destin_found) {
    unsigned node = queue.front();
    queue.pop();
    inspected_nodes.emplace_back(node + 1);
    std::cout << "Node: " << node << std::endl;
    //if (node == end) {
    //  break;
    //}

    std::vector<unsigned> aux;
    for (unsigned i = 0; i < nodes_[node].size(); ++i) {
      if (nodes_[node][i] > 0) {
        std::cout << i << " ";
        
        aux.emplace_back(i);
        generated_nodes.emplace_back(i + 1);
      }
    }
    std::cout << std::endl;
    std::sort(aux.begin(), aux.end());
    for (unsigned i = 0; i < aux.size(); ++i) {
      queue.push(i);
      cost += nodes_[node][i];
    }
    ++iteration;
    std::cout << "---------------" << std::endl;
    std::cout << "Iteration: " << iteration << std::endl;
    std::cout << "Generated nodes: ";
    PrintVector(generated_nodes);
    std::cout << "Inspected nodes: ";
    PrintVector(inspected_nodes);
  //}
  }
}

void Graph::DeepSearch() {
  unsigned start_node{0};
  unsigned end_node{0};
  std::cout << "Doing a Deep Search" << std::endl;
  std::cout << "---------------------" << std::endl;
  do {
  std::cout << "Introduce start node [1-" << node_number_ << "]: ";
  std::cin >> start_node;
  std::cout << "Introduce destin node [1-" << node_number_ << "]: ";
  std::cin >> end_node;
  } while ((start_node <= 0 && start_node > node_number_) && (end_node <= 0 && end_node > node_number_));
  
  std::cout << "----------------------" << std::endl;
  std::cout << "Graph's node number: " << node_number_ << std::endl;
  std::cout << "Graph's edge number: " << edge_number_ << std::endl;
  std::cout << "Starting node: " << start_node << std::endl;
  std::cout << "Destin node: " << end_node << std::endl;

  --start_node;
  --end_node;

  std::vector<unsigned> generated_nodes;
  std::vector<unsigned> inspected_nodes;
  //Tree solution_tree;
  int cost{0};

  generated_nodes.emplace_back(start_node);
  DFS(start_node, end_node, generated_nodes, inspected_nodes, cost);
  std::cout << "--------------" << std::endl;
  std::cout << "Path: " << std::endl;
  std::cout << "--------------" << std::endl;
  std::cout << "Cost: " << cost << std::endl;
}

void Graph::DFS(unsigned start, unsigned end, std::vector<unsigned>& generated_nodes, std::vector<unsigned>& inspected_nodes, int& cost) {
  unsigned iteration{1};
  std::vector<unsigned> aux;
  std::set<unsigned> visited;
  std::cout << "Node: " << start << std::endl;
  std::cout << "---------------" << std::endl;
  std::cout << "Iteration: " << iteration << std::endl;
  std::cout << "Generated nodes: ";
  PrintVector(generated_nodes);
  std::cout << "Inspected nodes: ";
  PrintVector(inspected_nodes);

  
  auto x = visited.find(start);
  if (start != end && x == visited.end()) {
    inspected_nodes.emplace_back(start);
    visited.insert(start);
    for (unsigned i = 0; i < nodes_[start].size(); ++i) {
      if (nodes_[start][i] > 0) {
        generated_nodes.emplace_back(i);
        aux.emplace_back(i);
      }
    }
    std::sort(aux.begin(), aux.end());
    for (unsigned i = 0; i < aux.size(); ++i) {
      cost += nodes_[start][i];
      DFS(i, end, generated_nodes, inspected_nodes, cost);
      visited.erase(i);
      cost -= nodes_[start][i];
    }
  }
}

std::ostream& operator<<(std::ostream& os, Graph& graph) {
  os << "Node number: " << graph.node_number_ << std::endl;
  for (unsigned i = 0; i < graph.node_number_; ++i) {
    os << "Node: " << i + 1 << " [";
    for (unsigned j = 0; j < graph.nodes_.size(); ++j) {
      os << graph.nodes_[i][j] << " ";
    }
    os << "]" << std::endl;
  }
  return os;
}

void PrintVector(const std::vector<unsigned>& vector) {
  for (unsigned i = 0; i < vector.size(); ++i) {
    std::cout << i;
    if (i != vector.size() - 1) {
      std::cout << ", ";
    }
  }
  std::cout << std::endl;
}