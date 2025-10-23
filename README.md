# Grafo RyanAir

Proyecto en C++ que modela la red de destinos de Ryanair como un grafo dirigido y ponderado. El grafo se almacena simultaneamente en listas de adyacencia y en una matriz de adyacencia para facilitar distintas operaciones como insercion, eliminacion, consultas y persistencia en archivos de texto.

## Caracteristicas principales
- Gestion de vertices y aristas con pesos enteros (distancias aproximadas en kilometros).
- Representaciones paralelas mediante lista enlazada (`lista.cpp`) y matriz (`matriz.cpp`).
- Lectura y escritura de grafos en archivos de texto (`grafo.txt`) con separador `#`.
- Utilidades para imprimir listas y matriz de adyacencia desde consola.

## Estructura del codigo
- `main.cpp`: punto de entrada; muestra como cargar un grafo desde archivo y visualizar sus listas de adyacencia.
- `grafo.*`: clase `Grafo` que coordina la gestion de vertices, aristas, listas y matriz.
- `lista.*` y `arista.*`: implementan la lista enlazada de aristas salientes por vertice.
- `matriz.*`: encapsula la matriz de adyacencia, usando `INF` para denotar ausencia de conexion.
- `vertice.h`: estructura simple con identificador y etiqueta textual.
- `grafo.txt`: dataset con todos los destinos y distancias aproximadas entre ellos.

## Compilacion y ejecucion
Compilar con g++ (C++17 o superior):

```bash
g++ main.cpp grafo.cpp lista.cpp matriz.cpp arista.cpp -std=c++17 -o grafo
./grafo
```

La ejecucion de `./grafo` cargara `grafo.txt` y mostrara las listas de adyacencia calculadas.

## Formato del archivo `grafo.txt`
1. Bloque de vertices: una linea por vertice con `id etiqueta`.
2. Linea que solo contiene `#` como separador.
3. Bloque de aristas: cada linea tiene `origen destino peso`.

Ejemplo minimo:
```
0 origen
1 destino
#
0 1 1234
```

## Scripts de apoyo (`distancias/`)
- `rutas.py`: descarga el listado de destinos publicado en brilliantmaps.com y lo guarda en CSV (requiere `requests` y `beautifulsoup4`).
- `coords.py`: cruza el listado con un catalogo de coordenadas (`worldcities.csv`) y genera `destinosFinal.csv`.
- `distancia.py`: calcula distancias con la formula de Haversine y produce un `grafo.txt` compatible con la carga en C++.

Los CSV de apoyo se encuentran en `distancias/csv/`. Los scripts asumen que se ejecutan dentro de `distancias/` y que el entorno cuenta con Python 3.

## Ideas para extender
- Agregar algoritmos de caminos minimos (Dijkstra, Floyd-Warshall) reutilizando la matriz.
- Filtrar aristas para representar solo rutas reales (no todas las combinaciones posibles).
- Implementar una interfaz interactiva para consultar conexiones entre dos aeropuertos.
