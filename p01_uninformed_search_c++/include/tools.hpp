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
 * Archivo tools.hpp: 
 * Contiene los prototipos de funciones utilizadas en el programa principal.
 * 
 * Historial de revisiones
 *   24/09/2024 - Creación (primera versión) del código
 *   30/09/2024 - Desarrollo de funciones
 *   03/10/2024 - Comentarios
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <string_view>

/**
 * @brief Contains the possible options the program can take
 */
struct ProgramOptions {
  std::string file_name{""};
  bool file_received{false};
};

const std::string kProgramUse{"This program reads a file containing a description of a graph and does operations with it."};

/**
 * @brief Checks if the program has been executed with the correct number of
 * parameters
 * @param argc: number of parameters passed via command line
 * @param argv: list containing the parameters passed via command line
 * @param kcorrect_number: number of parameters expected for the program to run
 * correctly
 */
void CheckExecution(int argc, char* argv[], const int kcorrect_number);

/**
 * @brief Function that takes the parameters passed via command line and checks
 * if the options are correct
 * @param argc: number of parameters passed via command line
 * @param argv: list of parameters passed via command line
 * @param options: struct that contains all the possible options
 */
void ProgramParameters(int argc, char* argv[], ProgramOptions& options);

/**
 * @brief Funtion that prints the menu
 */
void ShowMenu();