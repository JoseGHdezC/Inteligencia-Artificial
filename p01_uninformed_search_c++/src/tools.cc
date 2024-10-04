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
 * Archivo tools.cc:
 * Contiene la definición de los métodos declarados en tools.hpp.

 * Historial de revisiones
 *   24/09/2024 - Creación (primera versión) del código
 *   30/09/2024 - Desarrollo de funciones
 *   03/10/2024 - Comentarios
*/

#include "../include/tools.hpp"

/**
 * @brief Checks if the program has been executed with the correct number of
 * parameters
 * @param argc: number of parameters passed via command line
 * @param argv: list containing the parameters passed via command line
 * @param kcorrect_number: number of parameters expected for the program to run
 * correctly
 */
void CheckExecution(int argc, char* argv[], const int kcorrect_number) {
  if (argc > 1) {
    std::string param1 = argv[1];
    if (param1 == "--help" || param1 == "-h") {
      std::cout << kProgramUse << std::endl;
      std::cout << "To use this program it is required to introduce " << argv[0]
                << " params" << std::endl;
      exit(EXIT_SUCCESS);
    }
  }
  if (argc >= kcorrect_number) {
    std::cout << kProgramUse << std::endl;
    std::cout << "------------------" << std::endl;
  } else {
    std::cerr << "The program has been executed with a wrong number of "
                 "parameters. \nFor more information, please use: "
              << argv[0] << "--help" << std::endl;
    exit(EXIT_FAILURE);
  }
}

/**
 * @brief Function that takes the parameters passed via command line and checks
 * if the options are correct
 * @param argc: number of parameters passed via command line
 * @param argv: list of parameters passed via command line
 * @param options: struct that contains all the possible options
 */
void ProgramParameters(int argc, char* argv[], ProgramOptions& options) {
  std::vector<std::string_view> args(argv + 1, argv + argc);
  bool valid_option;
  for (unsigned i = 0; i < args.size(); ++i) {
    valid_option = false;
    if (args[i] == "-f") {  // File option
      if (++i < args.size()) {
        valid_option = true;
        options.file_received = true;
        options.file_name = args[i];
      } else {
        std::cerr << "No file name was given." << std::endl;
        exit(EXIT_FAILURE);
      }
    }
    if (!valid_option) {
      std::cerr << args[i] << " is not a valid option." << std::endl;
      std::cerr << "For more information, please use: " << argv[0] << "--help"
                << std::endl;
      exit(EXIT_FAILURE);
    }
  }
}

/**
 * @brief Funtion that prints the menu
 */
void ShowMenu() {
  std::cout << "---Menu---" << std::endl;
  std::cout << "c: [c]hange graph's description file." << std::endl;
  std::cout << "b: [b]ranch first search approach." << std::endl;
  std::cout << "d: [d]eep first search approach." << std::endl;
  std::cout << "s: [s]how graph's matrix." << std::endl;
  std::cout << "e: [e]xit program." << std::endl;
  std::cout << "-> ";
}