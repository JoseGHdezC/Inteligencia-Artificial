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

#include "../lib/tools.hpp"
#include "../lib/graph.hpp"

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
  Graph graph(options.file_name);
  std::cout << graph << std::endl;
  return 0;
}