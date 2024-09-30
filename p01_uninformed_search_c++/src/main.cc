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
 * Archivo main.py: 
 * Contiene la definición de los métodos que están declarados en la clase Cell.

 * Historial de revisiones
 *   24/09/2024 - Creación (primera versión) del código
*/

//Objetivos:
//  - G = (V, E)
//    - V es el conjunto de vértices (n)
//    - E es el conjunto de aristas (m)
//    - Cada arista tiene un coste d(i, j)
//  - Camino que conecte dos vértices
//  - d(i, j) = d(j, i)
//  - d(i, i) = 0
//  - d(i, j) = -1 si no existe
//  - Implementar BFS y DFS
//  - Si un nodo está en otra rama hay que repetir el nodo en la que se está haciendo
//  - Verificar si un nodo ya está contenido en esa rama
//  - Escoger el nodo de índice más pequeño en BFS y DFS
//  - Una iteración es un pop de la cola
//  - Nodos generados: se vuelve a añadir los nodos si son repetidos 
//  - Nodos inspeccionados: también se añaden los repetidos
//"""
//    
//# leer n -1 filas
//# leer n - 2 filas
//# ...
//# leer n - (n - 1)

#include <iostream>

#include "../include/tools.hpp"
#include "../include/graph.hpp"
#include "../include/tree.hpp"

void ExecuteMode(char mode, Graph& graph) { 
  std::string file_name{""};
  switch (mode) {
    case 'c':
      std::cout << "Introduce file: ";
      std::cin >> file_name;
      graph = Graph(file_name);
      break;
    case 'b':
      graph.BranchSearch();
      break;
    case 'd':
      graph.DeepSearch();
      break;
    case 's':
      std::cout << graph << std::endl;
      break;
    case 'e':
      std::cout << "Ending program" << std::endl;
      break;
    default:
      std::cerr << "Introduced option is not valid." << std::endl;
  }
}

int main(int argc, char* argv[]) {
  int kCorrectNumber = 1;
  CheckExecution(argc, argv, kCorrectNumber);
  ProgramOptions options;
  ProgramParameters(argc, argv, options);
  
  if (!options.file_received) {
    std::string aux_name{""};
    std::cout << "Introduce file containing the graph's description: ";
    std::cin >> aux_name;
    options.file_name = aux_name;
  }
  
  std::cout << "File introduced: " << options.file_name << std::endl;
  //Graph graph(options.file_name);
  Tree tree; // TODO: recuerda usarlo
  tree.Insert(4, 3, tree.get_root());
  std::cout << tree << std::endl;
  tree.Insert(4, 3, tree.get_root());
  tree.Insert(5, 2, tree.get_root());
  tree.Insert(5, 2, tree.get_root());
  std::cout << tree << std::endl;
  tree.Insert(6, 1, tree.get_root());
  tree.Insert(7, 4, tree.get_root());
  std::cout << tree << std::endl;
  tree.Insert(8, 4, tree.get_root() -> get_childs()[1]);
  std::cout << tree << std::endl;
  tree.Insert(8, 2, tree.get_root() -> get_childs()[0]);
  std::cout << tree << std::endl;
  tree.Insert(8, 2, tree.get_root() -> get_childs()[0]);
  //Node node(4, 3);
  //node.get_childs().emplace_back(new Node(5, 2, &node));
  //std::cout << "Node: " << node << std::endl;
  //std::cout << "Nodes child max: " << node.get_child_number() << std::endl;
  //std::cout << "Node childs: " << node.get_childs().size() << std::endl;
  //for (unsigned i = 0; i < node.get_childs().size(); ++i) {
  //  std::cout << "Node: " << *node.get_childs()[i] << std::endl;
  //  std::cout << "Parent node: " << *node.get_childs()[i] -> get_parent() << std::endl;
  //}

  //if (tree.Search(4, tree.get_root())) {
  //  std::cout << "Encontrado" << std::endl;
  //}
  //char mode{'\0'};
  //do {
  //  ShowMenu();
  //  std::cin >> mode;
  //  ExecuteMode(mode, graph);
  //} while (mode != 'e');

  return 0;
}