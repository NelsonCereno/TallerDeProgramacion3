# TallerDeProgramacion3

Solución al Problema de Flujo Máximo con Múltiples Fuentes y Sumideros
Nelson Cereño

Para la persona que revise este código trate de ser lo más pragmático posible, realmente me costó mucho esta experiencia de laboratorio, así que espero que se logre entender bien.

## Descripción General

Este programa resuelve el problema del flujo máximo con múltiples fuentes y sumideros utilizando el algoritmo de Dinic. El programa está diseñado para ser eficiente y modular, separando las responsabilidades en diferentes clases y métodos.

## Funcionamiento del Programa

### Entrada del Usuario

El programa, mediante un menú, permite al usuario ingresar el nombre de un archivo que contiene la descripción del grafo en el siguiente formato:
1. La primera fila enumera los vértices fuentes.
2. La segunda fila enumera los vértices sumideros.
3. A partir de la tercera fila, se tienen 3 columnas que indican aristas y su capacidad en el orden: origen destino capacidad.

### Lectura del Archivo

Utiliza la función `loadGraph` para leer las fuentes, sumideros y aristas del grafo desde el archivo especificado.

### Inicialización

Crea un objeto `Graph` con los vértices y aristas leídos del archivo. También se agregan una fuente y un sumidero artificiales para transformar el problema en un problema clásico de flujo máximo.

### Resolución del Problema

Llama al método `dinic` del objeto `MaxFlow` para encontrar una solución al problema de flujo máximo.

### Medición del Tiempo

Mide el tiempo de ejecución del método `dinic` y lo imprime en milisegundos.

### Salida

Imprime el flujo total encontrado y el tiempo de ejecución.

## Ejecución del Programa

Para ejecutar el programa, compílelo utilizando el Makefile ("make all" en la terminal) proporcionado e interactúe con el menú ejecutando "./main". A continuación, cargue el grafo y ejecute el cálculo del flujo máximo.

### Ejecución:

make clear all
./main

"Interactuar con el menú"

Detalle importante: Se recomienda re-ejecutar el programa si se quiere probar un nuevo grafo.

Pruebas
Si desea probar cada una de las pruebas facilitadas, aquí quedan sus códigos:

./test_graph
./test_maxflow

### Desafíos y Limitaciones

El desarrollo de este programa presentó varios desafíos significativos. Sin embargo, a pesar de los retos, se logró implementar una solución eficiente para la mayoría de los casos. El programa funciona correctamente tanto para casos simples como para casos de dificultad media y alta, logrando encontrar una solución óptima en un tiempo razonable.

Intentos y Estrategias
Se implementaron varias estrategias para optimizar el rendimiento del programa, incluyendo:

Optimización de Estructuras de Datos
Se utilizaron estructuras de datos eficientes para manejar los vértices y sus capacidades, con el objetivo de acelerar las operaciones de búsqueda e inserción.

Algoritmos de Búsqueda
Se exploraron diferentes algoritmos de búsqueda, como el algoritmo de Dinic, para encontrar la solución óptima.

### Resultados
Gracias a estos esfuerzos, el programa logró resolver casos de dificultad media y alta en un tiempo razonable. La combinación de estructuras de datos optimizadas y algoritmos de búsqueda permitió manejar la complejidad del problema y encontrar soluciones eficientes para el flujo máximo en grafos.

### Conclusión
El programa representa un esfuerzo considerable para resolver el problema del flujo máximo con múltiples fuentes y sumideros, y ha demostrado ser eficiente en términos de rendimiento y precisión. A pesar de los desafíos iniciales, se logró implementar una solución robusta y efectiva.

A modo de observación personal, resultó un desafío implementar este problema tan complicado, Sin embargo, el esfuerzo valió la pena y se logró un buen rendimiento.

Agradezco la atención.