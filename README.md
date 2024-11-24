
# Proyecto de Clasificación K-Nearest Neighbors (K-NN) en C

## Descripción

Este proyecto implementa el algoritmo de clasificación K-Nearest Neighbors (K-NN) utilizando el lenguaje C. El objetivo principal de este proyecto es clasificar flores del conjunto de datos Iris, basado en sus características físicas, como la longitud y el ancho de los sepalos y pétalos. El programa divide el conjunto de datos en dos partes: uno para entrenamiento y otro para prueba (testing), luego clasifica las flores de acuerdo con el algoritmo K-NN y evalúa su precisión.

## Estructura del Proyecto

El programa consta de una sola implementación en C que realiza las siguientes tareas:

1. **Lectura del archivo de datos**: Los datos de las flores (atributos y clases) son leídos desde un archivo llamado `iris.data`.
2. **Implementación del algoritmo K-NN**: El algoritmo K-NN es utilizado para clasificar las flores según sus características.
3. **Cálculo de la precisión**: Se calcula el porcentaje de clasificación correcta comparando las predicciones del modelo con las clases reales de las flores de prueba.

### Archivos

- `iris.data`: Archivo con los datos del conjunto Iris. Este archivo debe estar en el mismo directorio que el archivo ejecutable.
- `main.c`: Implementación del programa que contiene la lógica del algoritmo K-NN.

## Uso

### Requisitos

- Compilador de C (como `gcc`).
- Archivo `iris.data` con el conjunto de datos Iris.

### Instrucciones

1. **Compilar el programa**:
   Para compilar el código, usa el siguiente comando en el terminal:

   ```bash
   gcc -o knn_classifier main.c -lm
   ```

   El flag `-lm` es necesario para enlazar la biblioteca matemática, ya que se utiliza la función `sqrt` en el cálculo de distancias.

2. **Ejecutar el programa**:
   Una vez compilado, ejecuta el programa con el siguiente comando:

   ```bash
   ./knn_classifier
   ```

3. **Ingreso de parámetros**:
   Al ejecutar el programa, se solicitará lo siguiente:
   
   - El valor de `k` (número de vecinos más cercanos a considerar).
   - El porcentaje de datos a usar para el entrenamiento (porcentaje entre 0 y 100).
   
   Por ejemplo:
   
   ```
   Ingrese el valor de k para el algoritmo: 3
   Ingrese el porcentaje de entrenamiento para el algoritmo (0 a 100): 80
   ```

   El programa usará el valor de `k` para el algoritmo K-NN y dividirá los datos en entrenamiento y prueba basado en el porcentaje ingresado.

4. **Resultados**:
   El programa mostrará el resultado de la clasificacion de cada punto de prueba, indicando si la clasificación fue correcta o incorrecta. Al final, se mostrará el porcentaje de clasificación correcta.

### Ejemplo de Salida

```
Ingrese el valor de k para el algoritmo: 3
Ingrese el porcentaje de entrenamiento para el algoritmo (0 a 100): 80
testing *1 = Iris-setosa -----> testing 1 = Iris-setosa // Es correcto
testing *2 = Iris-setosa -----> testing 2 = Iris-setosa // Es correcto
...
El porcentaje de clasificacion correcta es: 96.00%
```

## Explicación del Código

- **Estructuras de datos**:
  - `Punto`: Estructura que almacena las características de cada flor, incluyendo su clase.
  - `DistanciaIndice`: Estructura utilizada para almacenar la distancia de cada punto respecto al punto de prueba y su índice en el conjunto de datos.
  
- **Funciones principales**:
  - `DistanciaEuclidiana`: Calcula la distancia euclidiana entre dos puntos del espacio (flores).
  - `KNN`: Realiza la clasificación utilizando el algoritmo K-NN, calculando las distancias entre el punto de prueba y todos los puntos del conjunto de entrenamiento, y luego determinando la clase más frecuente entre los k vecinos más cercanos.

- **Algoritmo de clasificación**:
  - El conjunto de datos se divide en entrenamiento y prueba, y se aplica el algoritmo K-NN para predecir la clase de cada punto de prueba. Luego, se calcula el porcentaje de clasificaciones correctas.

## Consideraciones

- El conjunto de datos utilizado es el famoso conjunto Iris, que contiene 150 puntos de datos con 4 atributos numéricos y una clase para cada muestra (Setosa, Versicolor, Virginica).
- El valor de `k` debe ser un número impar para evitar empates en la clasificación.

## Conclusión

Este proyecto demuestra como implementar el algoritmo K-Nearest Neighbors (K-NN) en C para realizar la clasificacion de datos. Es un ejemplo practico de cómo usar K-NN para tareas de clasificación en aprendizaje automático.

