/**
 *  Programa principal.
 *
 *
 *               Autores : Antonio Sedeno Noda, Sergio Alonso.
 *               Alumno: José Gregorio Hernández Cruz
 *               Cursos  : 2012-2021
 */

#include <string.h>
#include "grafo.h"


void menu (unsigned dirigido, char &opcion) { 
//Expresion del menu de opciones segun sea un grafo dirigido o no dirigido
    cout << "Optimizacion en Grafos, 2021-2022 José Gregorio" << endl;
    cout << "c. [c]argar grafo desde fichero" << endl;
    if (dirigido == 0) {  //Grafo no dirigido
      cout << "i. Mostrar [i]nformacion basica del grafo" << endl;
      cout << "a. Mostrar la lista de [a]dyacencia del grafo" << endl;
	    cout << "m. Realizar un recorrido en a[m]plitud del grafo desde un nodo" << endl;
      cout << "r. Realizar un recorrido en p[r]ofundidad del grafo desde un nodo" << endl;
      cout << "p. Realizar un árbol generador de mínimo coste por [p]rim" << endl;
    } else { //Grafo dirigido
      cout << "i. Mostrar [i]nformacion basica del grafo" << endl;
      cout << "s. Mostrar la lista de [s]ucesores del grafo" << endl;
      cout << "e. Mostrar la lista de pr[e]decesores del grafo" << endl;
      cout << "m. Realizar un recorrido en a[m]plitud del grafo desde un nodo por sucesores" << endl;
      cout << "r. Realizar un recorrido en p[r]ofundidad del grafo desde un nodo por sucesores" << endl;
      cout << "d. Caminos mínimos: [d]ijkstra" << endl;
      cout << "v. Caminos mínimos: Comparamos Dijkstra [v]s BellmanFordEnd" << endl;
    };
    cout << "q. Finalizar el programa" << endl;
    cout << "Introduce la letra de la accion a ejecutar  > ";
    cin >> opcion;
};


// El principal es simplemente un gestor de menu, diferenciando acciones para dirigido y para no dirigido, y un men� inicial si no hay un grafo cargado
int main(int argc, char *argv[]) {
  int error_apertura;
  char nombrefichero[85], opcion;
  //clrscr();
  //Si tenemos el nombre del primer fichero por argumento, es una excepcion, y lo intentamos cargar, si no, lo pedimos desde teclado
  if (argc > 1) {
    cout << "Cargando datos desde el fichero dado como argumento" << endl;
    strcpy(nombrefichero, argv[1]);
  } else {
    cout << "Introduce el nombre completo del fichero de datos" << endl;
    cin >> nombrefichero;
  }
  GRAFO G(nombrefichero, error_apertura);
  if (error_apertura == 1) {
    cout << "Error en la apertura del fichero desde argumento: revisa nombre y formato" << endl;
    //pressanykey();
    //clrscr();
  } else {
    cout<< "Grafo cargado desde el fichero " << nombrefichero << endl;
    //pressanykey();
    //clrscr();
    do {
      menu(G.Es_dirigido(), opcion);
      switch (opcion) {
        case 'c':
          //clrscr();
          cout << endl;
          cout << "Introduce el nombre completo del fichero de datos" << endl;
          cin >> nombrefichero;
          G.actualizar(nombrefichero, error_apertura);
          if (error_apertura == 1) {
            cout << "Error en la apertura del fichero: revisa nombre y formato : puedes volver a intentarlo" << endl;
          } else {
              cout << "Fichero cargado correctamente desde " << nombrefichero << endl;
          };
          //pressanykey();
          //clrscr();
          cout << endl;
          break;
        case 'i':
          //clrscr();
          cout << endl;
		      cout << "Grafo cargado desde " << nombrefichero << endl;
          G.Info_Grafo();
          //pressanykey();
          //clrscr();
          cout << endl;
          break;
        case 's':
          cout << endl;
          cout << "Nodos de la lista de sucesores" << endl;
          G.Mostrar_Listas(1);
          cout << endl;
          break;
        case 'e':
          cout << endl;
          cout << "Nodos de la lista de predecesores" << endl;
          G.Mostrar_Listas(-1);
          cout << endl;
          break;
        case 'a':
          cout << endl;
          cout << "Nodos de la lista de adyacencia" << endl;
          G.Mostrar_Listas(0);
          cout << endl;
          break;
        case 'm':
          cout << endl;
          G.RecorridoAmplitud();
          cout << endl;
          break;
        case 'r':
          cout << endl;
          G.RecorridoProfundidad();
          cout << endl;
          break;
        case 'p':
          cout << endl;
          G.ArbolGeneradorPrim();
          cout << endl;
          break;
        case 'd':
          cout << endl;
          G.CMDijkstra();
          cout << endl;
          break;
        case 'v':
          cout << endl;
          G.ComparativaCM();
          cout << endl;
          break;
      }
    }
    while (opcion != 'q');
    }
    cout << "Fin del programa" << endl;
	return(0);
};
