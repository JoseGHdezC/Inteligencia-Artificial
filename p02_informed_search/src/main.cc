/**
 * 
 * 
 */

/*  Laberinto de E a S, evitando obstáculos
    -> Insp: 
        - meta?
        - No meta -> generar sucesores
    f(n) = g(n) + h(n)
    g(n): coste real para llegar
    h(n): función heurística, coste estimado para llegar a la meta (<= coste real)
       -> heurística admiscible: (h(n) <= coste real) - si no lo fuera podríamos saltarnos la rama con el camino óptimo
       -> mapa: distancia euclidiana
       -> cuanto más cercana, mejor
    Inspeccionado: nodo cerrado, ya no se mira
    -> Escoger la f(n) más pequeña
    -> Asociado: nodo, g(n), h(n), saber quién es su padre. g(n') = g(n) + d(i, j)
    -> Si se repite un nodo:
    - mirar el g(n) en ambos caminos
    - actualizar el nodo existente:
        - cambiar g(n)
        - cambiar el padre al nuevo que hace que g(n) sea menor
    -> No se para al estado meta:
        - mirar si hay otras rutas con menor coste f(n)
    -> Parar:
        - en el nodo meta y no hay otro f(n) más pequeño
    Ejemplo:
    1
    2 5 8
        
    ---Práctica---
    -> Menor coste de S a E
    -> Horizontal o Vertical: 5
    -> Diagonal: 7
    -> h(n): distancia de manhattan -> h(n) = (|xE − xn| + |yE − yn|) ∗ W, W = 3.
    -> Algoritmo A*:
        - En el guión
    - Matriz -> Árbol
    -> Tareas:
        - a) Manhattan y una alternativa admicible, las dos deben funcionar
            - Estadísticas finales y paso a paso
            - Cuál es mejor y por qué?
        - *) Laberintos enrevesados
        - *) Poder permitir cambiar la entrada y salida, sin cambiar el fichero
            - 3 entrada, 4 salida y 1's en los anteriores
        - *) Modificaciones algorítmicas
        - b) Fichero de salida con la tabla, con * por el camino mínimo
        - c) Memoria
            - Resultados de las heurísticas
            - Implementación
        - d) Si no hay salida, escribir "No se ha encontrado solución"
*/

