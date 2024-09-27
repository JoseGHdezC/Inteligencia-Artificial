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

#include "../lib/tools.hpp"

void CheckExecution(int argc, char* argv[], const int kcorrect_number) {
  if (argc > 1) {
    std::string param1 = argv[1];
    if (param1 == "--help" || param1 == "-h") {
      std::cout << kProgramUse << std::endl;
      std::cout << "To use this program it is required to introduce " << argv[0] << " params" << std::endl;
      exit(EXIT_SUCCESS);
    }
  }
  if (argc >= kcorrect_number) {
    std::cout << kProgramUse << std::endl;
    std::cout << "------------------" << std::endl;
  } else {
    std::cerr << "The program has been executed with a wrong number of parameters. \nFor more information, please use: " << argv[0] << "--help" << std::endl;
    exit(EXIT_FAILURE);
  }
}


void ProgramParameters(int argc, char* argv[], ProgramOptions& options) {
  std::vector<std::string_view> args(argv + 1, argv + argc);
  bool valid_option;
  for (unsigned i = 0; i < args.size(); ++i) {
    valid_option = false;
    if (args[i] == "-f") {
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
      std::cerr << "For more information, please use: " << argv[0] << "--help"  << std::endl;
      exit(EXIT_FAILURE);
    }
  }
}

//def ManageExecution(arguments: "list[str]") -> str:
//    value: str
//    valid_option: bool = False
//    if (len(arguments) < 2):
//        value = "menu"
//        valid_option = True
//    
//    for i in range(1, len(arguments)):
//        #print(arguments[i])
//        if (arguments[i] == "--help" or arguments[i] == "-h"):
//            print("Por implementar")
//            exit(0)
//        elif (arguments[i] == "-f"):
//            if (i + 1 < len(arguments)):
//                #print(arguments[i])
//                i += 1
//                value = arguments[i]
//                valid_option = True
//        
//    if not(valid_option):
//        print("The program has been executed with an incorrect option.")
//        print(f"For more information, please use: {arguments[0]} --help")
//        exit(1)
//            
//    return value

void ShowMenu() {

}