/**
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
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <string_view>

struct ProgramOptions {
  std::string file_name{""};
  bool file_received{false};
};

const std::string kProgramUse{"This program reads a file containing a description of a graph and does operations with it."};
void CheckExecution(int argc, char* argv[], const int kcorrect_number);
void ProgramParameters(int argc, char* argv[], ProgramOptions& options);
void ShowMenu();