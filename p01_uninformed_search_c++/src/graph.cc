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
  std::cout << "Creating graph" << std::endl;
  std::ifstream input_file{filename};
  if (input_file.is_open()) {
    std::string line{""};
    input_file >> line;
    node_number = std::stoi(line);
    while (getline(input_file, line)) {
      std::cout << line << std::endl;
    }
    
//with open(filename, "r") as file:
//                number: int = int(file.readline())
//                self.node_number = number
//                for i in range(0, self.node_number):
//                    self.nodes.append([])
//                    
//                row: int = 0
//                column: int = 0
//                limit: int = 1 
//                file_iterations: int = self.node_number - limit
//                for line in file:
//                    #print()
//                    #print(line.strip())
//                    #print(f"-->File iteration: {file_iterations}")
//                    #print(f"->Current row: {row}")
//                    #print(f"->Current column: {column}")
//                    edge_cost: float = float(line.strip())
//                    if (row == column):
//                        self.nodes[row].append((column, 0))
//                        column += 1    
//                        #print(f"Incluyendo row: {row} {self.nodes[row]}")
//                    
//                    #print(f"->Current row: {row}")
//                    #print(f"->Current column: {column}")
//                    if (row < self.node_number and column < self.node_number):
//                        if (edge_cost > -1):    
//                            self.nodes[row].append((column, edge_cost))
//                            self.nodes[column].append((row, edge_cost))
//                            #print(f"Incluyendo row: {row} {self.nodes[row]} \nY row: {column} {self.nodes[column]}")
//                        column += 1     
//
//                    if (file_iterations - limit == 0):
//                        row += 1
//                        column = row
//                        file_iterations = self.node_number - row - 1
//                    else:
//                        file_iterations -= 1
//                
//                self.nodes[column].append((column, 0))  # Includes the last node
//        except FileNotFoundError as e:
//            print(f"File {filename} could not be found.")
//            print(f"{e}")
  } else {
    std::cerr << "File could not be opened. Please check file name." << std::endl;
  }
}

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

std::ostream& operator<<(std::ostream& os, Graph& graph) {
  return os;
}