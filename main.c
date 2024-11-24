#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Estructura para almacenar un punto en el espacio con sus atributos y clase
typedef struct{
    // atributos que tiene cada punto
    double atrib1;  // longitud del sépalo
    double atrib2;  // ancho del sépalo
    double atrib3;  // longitud del petalo
    double atrib4;  // anchoo del petalo
    char clase[20]; // clase o nombre de la especie de la orquidea
} Punto;

// Estructura quee almacena pares de distancia e índice
typedef struct{
    double distancia;
    int indice;
} DistanciaIndice;

// Función de comparación para la función qsort
int comparaPares(const void *a, const void *b) {
    double diff = ((DistanciaIndice*)a)->distancia - ((DistanciaIndice*)b)->distancia;
    return (diff > 0) - (diff < 0);
}

// distancia euclidiana entre puntos
double DistanciaEuclidiana(Punto *p1, Punto *p2) {
    return sqrt(pow(p1->atrib1 - p2->atrib1, 2) + pow(p1->atrib2 - p2->atrib2, 2) +
                pow(p1->atrib3 - p2->atrib3, 2) + pow(p1->atrib4 - p2->atrib4, 2));
}

// Función para clasificar un punto usando k-NN
char *KNN(Punto *punto_testing, Punto *Training, int k, int tam_training){

    // calculamos las distancias entre el punto testing y todos los puntos de training y las guardamos en un arreglo
    double distancias[tam_training];
    for(int i=0; i<tam_training; i++){
        distancias[i] = DistanciaEuclidiana(punto_testing, &Training[i]);
    }

    // Crear un arreglo de estructuras para almacenar distancias e índices
    DistanciaIndice pares[tam_training];
    for(int i=0; i<tam_training; i++){
        pares[i].distancia = distancias[i];
        pares[i].indice = i;
    }

    // Ordenar el arreglo de estructuras basándose en las distancias de menor a mayor
    qsort(pares, tam_training, sizeof(DistanciaIndice), comparaPares);

    // Cuenta las clases de los k vecinos más cercanos
    int Setosa_num = 0;
    int Versicolor_num = 0;
    int Virginica_num = 0;

    for (int i=0; i<k; i++) {
        if(strcmp(Training[pares[i].indice].clase, "Iris-setosa") == 0){
            Setosa_num++;
        } 
        else{
            if(strcmp(Training[pares[i].indice].clase, "Iris-versicolor") == 0){
                Versicolor_num++;
            } 
            else{
                if(strcmp(Training[pares[i].indice].clase, "Iris-virginica") == 0){
                    Virginica_num++;
                }
            }
        }
    }

    // Calculamos la clase final de acuerdo a los que tuvieron mayor aparición en los k menores
    if(Setosa_num >= Versicolor_num && Setosa_num >= Virginica_num){
        return "Iris-setosa";
    } 
    else{
        if(Versicolor_num >= Setosa_num && Versicolor_num >= Virginica_num){
            return "Iris-versicolor";
        } 
        else{
            return "Iris-virginica";
        }
    }
}


int main()
{
    // primero abrimos el archivo de los datos
    FILE *file = fopen("iris.data", "r");

    // revisamos si es NULL es decir no se pudo abrir el archivo
    if(file==NULL){
        printf("NO SE PUDO LEER EL ARCHIVO\n");
        return 1; // terminamos y regresamos 1.
    }

    // hacemos un conteo de las lieas del archivo, es decir, un conteo de los puntos en el archivo
    int num_puntos = 0;
    char linea[256];
    while(fgets(linea, sizeof(linea), file) != NULL){ // fgets lee una linea del archivo file y la almacena en linea 
        num_puntos++;
    }
    num_puntos--;
    rewind(file); // movemos el puntero de posición en el archivo al inicio del mismo. 

    // creamos el espacio en memoria del total de puntos mediante un arreglo de structs
    Punto *dato = (Punto *)malloc(num_puntos * sizeof(Punto)); 


    for(int i=0; i<num_puntos; i++){
        // haciendo uso de fscanf leemos y guardamos cada uno de los datos de cada punto (sus atributos) del cocumento file
        fscanf(file, "%lf,%lf,%lf,%lf,%s", &dato[i].atrib1, &dato[i].atrib2, &dato[i].atrib3, &dato[i].atrib4, dato[i].clase);
    }
    fclose(file); // cerrmos el documento file

    //pedimos al usuario el valor de k
    int k;
    printf("Ingrese el valor de k para el algoritmo: ");
    scanf("%d", &k);


    // Define el porcentaje de entrenamiento
    double porcen_entrena;
    printf("Ingrese el porcentaje de entrenamiento para el algoritmo (0 a 100): ");
    scanf("%lf", &porcen_entrena);
    porcen_entrena = porcen_entrena/100; // obtenemos el valor del porcentaje de entrenamiento de 0 a 1.

    // dependiendo el % de entrenamiento damos la cantidad de puntos que son de training y la cantidad de testing 
    // y creamos el espacio en memoria de los puntos training y testing
    int tam_training = num_puntos * porcen_entrena;
    Punto *Training = (Punto *)malloc(tam_training * sizeof(Punto));

    int tam_testing = num_puntos - tam_training;
    Punto *Testing = (Punto *)malloc(tam_testing * sizeof(Punto));


    // llenamos los conjuntos de testing y training (recordando que el training debe tener la misma cantidad de cada clase)
    int Num_clase1 = 0; //cuenta el numero de elementos guardados de la clase setosa
    int Num_clase2 = 0; //cuenta el numero de elementos guardados de la clase versicolor
    int Num_clase3 = 0; //cuenta el numero de elementos guardados de la clase virginica
    int cantidad_clase = tam_training / 3; // la cantidad de cada clase en el training
    int j = 0;
  
    for(int i=0; i<num_puntos; i++){ 
        //tomamos los primeros "antidad_clase" de cada clase y los restantes se colocan en el testing
        if(Num_clase1<cantidad_clase && strcmp(dato[i].clase, "Iris-setosa") == 0){ 
            // colocamos los primeros puntos de training de la primer clase
            Training[j] = dato[i];
            Num_clase1++;
            j++;
        } 
        else{
            if(Num_clase2<cantidad_clase  && strcmp(dato[i].clase, "Iris-versicolor") == 0){
                // colocamos los primeros puntos de training de la primer clase
                Training[j] = dato[i];
                Num_clase2++;
                j++;
            } 
            else{
                if(Num_clase3<cantidad_clase  && strcmp(dato[i].clase, "Iris-virginica") == 0){
                    // colocamos los primeros puntos de training de la primer clase
                    Training[j] = dato[i];
                    Num_clase3++;
                    j++;
                } 
                else{
                    // el resto de los puntos se colocan en el conjunto del testing
                    Testing[i - Num_clase1 - Num_clase2 - Num_clase3] = dato[i];
                }
            } 
        }
    }

    // Usemos el knn para encontrar la clasificación de los puntos testing y calcular la cantidad de correctos
    int correctos = 0;
    for(int i=0; i<tam_testing; i++){
        char *claseknn = KNN(&Testing[i], Training, k, tam_training);
        // claseknn es la clase que predijo el algoritmo de KNN
        if(strcmp(claseknn, Testing[i].clase) == 0){
            correctos++;
            //mostramos el punto original y el obtenido (son iguales,ie, es correcto)
            int num_test = i+1;
            printf("testing *%i = %s -----> testing %i = %s // Es correcto\n",num_test, Testing[i].clase,num_test, claseknn);
        }else{
            //mostramos el punto original y el obtenido (son diferentes,ie, es incorrecto)
            int num_test = i+1;
            printf("testing *%i = %s -----> testing %i = %s // Es incorrecto\n",num_test, Testing[i].clase,num_test, claseknn);
        }
    }

    // calculamos ell porcentaje de clasificacion correcta
    double prom = (double)correctos / tam_testing * 100.0;
    printf("\nEl porcentaje de clasificacion correcta es: %.2f%%\n", prom);

    // liberamos memoria
    free(dato);
    free(Training);
    free(Testing);

    return 0;
}