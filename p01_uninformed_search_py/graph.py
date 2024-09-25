"""
    Universidad de La Laguna
    Escuela Superior de Ingeniería y Tecnología
    Grado en Ingeniería Informática
    Asignatura: Inteligencia Artificial
    Curso: 3º
    Práctica 1: Búsquedas no informadas
    Autor: José Gregorio Hernández Cruz
    Correo: alu0101545820@ull.edu.es
    Fecha: 24/09/2024
    Archivo graph.py: 
    Contiene la definición de los métodos que están declarados en la clase Cell.

    Historial de revisiones
      24/09/2024 - Creación (primera versión) del código
"""

# Implementar como matriz
# No hay arista de i a i
from types import NoneType


class Graph:
    
    def __init__(self, filename):
        try:
            with open("./files/" + filename, "r") as file:
                number: int = int(file.readline())
                self.node_number = number
                for i in range(0, self.node_number):
                    self.nodes.append([])
                    
                row: int = 0
                column: int = 0
                limit: int = 1 
                file_iterations: int = self.node_number - limit
                for line in file:
                    print()
                    print(line.strip())
                    print(f"-->File iteration: {file_iterations}")
                    print(f"->Current row: {row}")
                    print(f"->Current column: {column}")
                    edge_cost: float = float(line.strip())
                    if (row == column):
                        self.nodes[row].append((column, 0))
                        column += 1    
                        print(f"Incluyendo row: {row} {self.nodes[row]}")
                    
                    print(f"->Current row: {row}")
                    print(f"->Current column: {column}")
                    if (row < self.node_number and column < self.node_number):    
                        self.nodes[row].append((column, edge_cost))
                        self.nodes[column].append((row, edge_cost))
                        print(f"Incluyendo row: {row} {self.nodes[row]} \nY row: {column} {self.nodes[column]}")
                        column += 1 

                    if (file_iterations - limit == 0):
                        row += 1
                        column = row
                        file_iterations = self.node_number - row - 1
                    else:
                        file_iterations -= 1
                
                self.nodes[column].append((column, 0))  # Includes the last node
        except FileNotFoundError as e:
            print(f"File {filename} could not be found.")
            print(f"{e}")
    
    def __str__(self):
        print()
        print(f"Node number: {self.node_number}")
        for i in self.nodes:
            print(i)

        return ""
            
    def BFS(self, start_node):
        pass
    
    def DFS(self, start_node):
        pass
    
    nodes = []
    node_number = 0
    edge_number = 0