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
            with open("./files/" + filename) as file:
                number = int(file.readline())
                self.node_number = number
                for i in range(0, self.node_number):
                    self.nodes.append([])
                    
                for i in range(0, self.node_number):
                    j = 0
                    for j in range(0, self.node_number - j - 1):
                        edge_cost = file.readline()
                        if (edge_cost != -1):
                            self.nodes[i].append((j, edge_cost))
                            self.nodes[j].append((i, edge_cost))
                        #print(edge_cost)
                    #j = self.node_number - 1
                    #while (j > 0):
                    #    edge_cost = file.readline()
                    #    
                    #    #print(edge_cost)
                    #    j -= 1
                    
        except FileNotFoundError as e:
            print(f"File {filename} could not be found.")
            print(f"{e}")
    
    def __str__(self):
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