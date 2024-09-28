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
    Archivo tools.py: 
    Contiene la definición de los métodos que están declarados en la clase Cell.

    Historial de revisiones
      24/09/2024 - Creación (primera versión) del código
"""

import sys

def ManageExecution(arguments: "list[str]") -> str:
    value: str
    valid_option: bool = False
    if (len(arguments) < 2):
        value = "menu"
        valid_option = True
    
    for i in range(1, len(arguments)):
        #print(arguments[i])
        if (arguments[i] == "--help" or arguments[i] == "-h"):
            print("Por implementar")
            exit(0)
        elif (arguments[i] == "-f"):
            if (i + 1 < len(arguments)):
                #print(arguments[i])
                i += 1
                value = arguments[i]
                valid_option = True
        
    if not(valid_option):
        print("The program has been executed with an incorrect option.")
        print(f"For more information, please use: {arguments[0]} --help")
        exit(1)
            
    return value