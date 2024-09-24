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
    Archivo main.py: 
    Contiene la definición de los métodos que están declarados en la clase Cell.

    Historial de revisiones
      24/09/2024 - Creación (primera versión) del código
"""

"""
Objetivos:
  - G = (V, E)
    - V es el conjunto de vértices (n)
    - E es el conjunto de aristas (m)
    - Cada arista tiene un coste d(i, j)
  - Camino que conecte dos vértices
  - d(i, j) = d(j, i)
  - d(i, i) = 0
  - d(i, j) = -1 si no existe
"""
    
import sys

import tools

def main():
    """
    Main function that initializes the graph and operates with it.
    """

    arguments = sys.argv
    
    
    filename = tools.ManageExecution(arguments)
    
    if (filename == "menu"):
        filename = input("Introduce the file containing the graph declaration: ")
        
    try:
        with open("./files/" + filename) as file:
            for line in file:
                print(line, end="")
    except FileNotFoundError:
        print("File {} could not be found.".format(filename))

if __name__ == '__main__':
    main()