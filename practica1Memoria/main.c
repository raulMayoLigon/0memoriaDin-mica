#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct datos {
    double x;
    double y;
};

void cambiarValor(int *puntero);

int main(void) {
    
    //Ejercicio 1:
    int number;
    int *ptroInt;
    
    struct datos point;
    struct datos *ptroPoint;
    
    printf("¿Cuánto ocupa cada variable?:\n");
    printf("    -number: %lu bytes\n", sizeof(number));
    printf("    -ptroInt: %lu bytes\n", sizeof(ptroInt));
    printf("    -point: %lu bytes\n", sizeof(point));
    printf("    -ptroPoint: %lu bytes\n", sizeof(ptroPoint));
    /* No usamos "*" en sizeof ya que si no nos diría cuanto ocupa la variable a la que estamos apuntando, y no el puntero en si. */
    
    //¿Cuál ocupa más?
    printf("\nLa que más ocupa es la variable del tipo de la estructura declarada en el main (struct datos point), tiene dos double.\n");
    //¿Cuáles ocupan lo mismo? ¿Por qué?
    printf("\nLas variables que ocupan lo mismo son los dos punteros, ptroInt y ptroPoint, ya que son el mismo tipo de variable, punteros.\n");
    /* ¿Sabrías ahora decir cuánto ocupa un double en tu máquina sin usar
    sizeof? Razona tu respuesta. */
    printf("\nSi point tiene dos double y ocupa lo que hemos visto antes (%lu), un solo double ocupará la mitad (%lu)\n", sizeof(point), sizeof(point)/2);
    
    printf("\n        /---------------------------------------/\n\n");
    
    //Ejercicio 2:
    
    number = 100;
    printf("int number es igual a: %d\n", number);
    ptroInt = &number;
    *ptroInt = 33;
    printf("int number es igual a: %d\n", number);
    printf("*ptroInt apunta a la dirección %p, \nApunta al dato: %d (de number).\n", ptroInt, *ptroInt);
    printf("Number se almacena en la dirección: %p. Vale %d\n", &number, number);
    printf("Cosas que podemos observar:\n");
    printf("    -Hemos cambiado el valor de number.\n");
    printf("    -El puntero tiene la misma dirección de memoria que number y \tapunta al mismo dato modificado (33), ya que le está apuntando, \t(el dedo).\n");
    
    printf("\n        /---------------------------------------/\n\n");
    
    //Ejercicio 3:
    
    printf("int number es igual a: %d\n", number);
    cambiarValor(&number);
    printf("int number es igual a: %d\n", number);
    printf("number se modifica ya que al llamar a la funcion pasandole la dirección de memoria de number el puntero se la modifica.\n");
    
    printf("\n        /---------------------------------------/\n\n");
    
    //Ejercicio 4:
    
    printf("number: %d\n", number);
    
    cambiarValor(ptroInt);
    
    printf("number: %d\n", number);
    printf("Llamar a la función en este caso con ptroInt vuelve a cambiar el valor de number, porque en el ejercicio 2 hicimos que ptroInt apuntase a la dirección de memoria de number.\n\n");
    
    //Ejercicio 5:
    
    int * ptroInt2;
    /* no hemos apuntado a ningún sitio con nuestro puntero (está sin inicializar),por lo que apunta por defecto a una posición desconocida (basura) */
    //Lo correcto sería escribir ptroInt2 = NULL si no queremos que apunte a ningún sitio.
    printf("ptroInt2 apunta a: %p\n", ptroInt2);
    
    ptroInt2 = (int *)malloc(sizeof(int));
    printf("ptroInt2 después de asignarle memoria con malloc apunta a: %p\n", ptroInt2);
    cambiarValor(ptroInt2);
    printf("ptroInt2 vale: %d\n", *ptroInt2);
    
    /* Aunque llamemos a la función, no estamos sobreescribiendo ptroIn2,con number, ptroInt2 sigue estando en la memoria que le asignamos: */
    printf("Dirección de number: %p\n", &number);
    printf("Dirección de ptroInt2: %p\n", ptroInt2);
    
    //Después de usar malloc hay que liberar la memoria:
    free(ptroInt2);
    
    return 0;
}

void cambiarValor(int *puntero) {
    
    printf("Introduce un valor: ");
    scanf("%d", puntero);
}
