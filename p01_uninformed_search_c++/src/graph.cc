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

#include "../lib/graph.hpp"

Graph::Graph(std::string filename) {
  
}
//# Implementar como matriz
//# No hay arista de i a i
//class Graph:
//    
//    nodes = []
//    node_number = 0
//    edge_number = 0
//    
//    def __init__(self, filename):
//        try:
//            with open("./files/" + filename) as file:
//                number = int(file.read(1))
//                node_number = number
//        except FileNotFoundError as e:
//            print(f"File {filename} could not be found.")
//            print(f"{e}")
//    
//    def __str__(self):
//        for i in self.nodes:
//            print(i)
//            
//    def BFS(self, start_node):
//        pass
//    
//    def DFS(self, start_node):
//        pass
//    
//    