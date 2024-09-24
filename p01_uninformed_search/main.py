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

"""
    
import sys

def main():
    print(sys.argv[1])
   
    filename = input("Introduce file name: ")
    try:
        with open("./files/" + filename) as file:
            for line in file:
                print(line, end="")
    except FileNotFoundError:
        print("File {} could not be found.".format(filename))
        

if __name__ == '__main__':
    main()