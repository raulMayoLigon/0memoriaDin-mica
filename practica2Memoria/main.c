//Hay exceso de comentarios, son más que nada para ir yo repasando.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct datos {
    double x;
    double y;
};

//Función cambiar valor (apartado 3 ejercicio 1).
void cambiarValor(int *puntero);
//Función inicializarPtro (ap. 1 ej. 2).
void inicializarPtro(struct datos **ptroIncializarNULL); //Pasar puntero por referencia.
//Función inicializarPunto y modificar ptroPoint. (ap. 2 ej. 2).
void inicializarPunto(struct datos *variable);
void modificarptroPoint(struct datos *modificar);
//Función visualizar (ap. 3 ej. 2)
void visualizar(int *ptro);

int main(void) {
    
    printf("------------------------------PRÁCTICA 1------------------------------\n");
    
    printf("\n---Ejercicio 1:---\n");
    
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
    
    printf("\n\n---Ejercicio 2:---\n");
    
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
    
    printf("\n\n---Ejercicio 3:---\n");
    
    printf("int number es igual a: %d\n", number);
    cambiarValor(&number);
    printf("int number es igual a: %d\n", number);
    printf("number se modifica ya que al llamar a la funcion pasandole la dirección de memoria de number el puntero se la modifica.\n");
    
    printf("\n\n---Ejercicio 4:---\n");
    
    printf("number: %d\n", number);
    
    cambiarValor(ptroInt);
    
    printf("number: %d\n", number);
    printf("Llamar a la función en este caso con ptroInt vuelve a cambiar el valor de number, porque en el ejercicio 2 hicimos que ptroInt apuntase a la dirección de memoria de number.\n\n");
    
    printf("\n\n---Ejercicio 5:---\n");
    
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
    
    
    printf("------------------------------PRÁCTICA 2------------------------------\n");

    printf("\n\n---Ejercicio 1:---\n");
    
    /* Para modificarlo hay que usar puntero a puntero, por que si no sería simplemente una copia de ptroPoint que no le afectaría al llamar a la función. */
    inicializarPtro(&ptroPoint);
    printf("La dirección de ptroPoint es: %p\n", ptroPoint); //NULL
    
    /* Asignación de x e y en main:
    point.x = 4.75;
    point.y = 3.5;
    printf("x vale: %.2lf, y vale: %.2lf.\n", point.x, point.y); */
    
    /*Rellenar los campos x e y en los datos apuntados por el puntero de manera dinámica es similar a añadir un nodo a una lista.*/
    
    ptroPoint = (struct datos*)malloc(sizeof(struct datos));
    if (ptroPoint == NULL) {
        printf("ERROR... no hay memoria asignada, saliendo ----->>");
        return 1;
    }
    
    ptroPoint->x = 2.5;
    ptroPoint->y = 3.75;
    printf("x vale: %.2lf, y vale: %.2lf.\n", ptroPoint->x, ptroPoint->y);
    
    free(ptroPoint);
    
    printf("\n\n---Ejercicio 2:---\n");
    
    inicializarPunto(&point);
    //Reservar memoria del montón para ptroPoint:
    ptroPoint = (struct datos*)malloc(sizeof(struct datos));
    if (ptroPoint == NULL) {
        printf("ERROR... Asignación incorrecta, saliendo---->>");
        return 1;
    }

    ptroPoint->x = point.x;
    ptroPoint->y = point.y;

    printf("-Datos de point: x vale: %.2lf, y vale: %.2lf.\n", point.x, point.y);
    printf("-Datos de ptroPoint: x vale: %.2lf, y vale: %.2lf.\n", ptroPoint->x, ptroPoint->y);
    
    //Modificar ptroPoint:
    modificarptroPoint(ptroPoint);
    printf("Datos de point: \n");
    printf("    -x: %.2lf\n", point.x);
    printf("    -y: %.2lf\n", point.y);
    
    printf("Datos de ptroPoint: \n");
    printf("    -x: %.2lf\n", ptroPoint->x);
    printf("    -y: %.2lf\n", ptroPoint->y);
    
    printf("Tienen distintos valores, ya que no comparten la misma ubicación, por que le asignamos una a ptroPoint (con malloc)\n");
    
    free(ptroPoint);
    
    printf("\n\n---Ejercicio 3:---\n");
    
    /* Pienso que al asignar el puntero al array va a asignarse al primer valor del array por defecto, por lo que al hacer el bucle for con el puntero vamos a ir recorriendo todo el array */
    int i;
    int a[10] = {0,1,2,3,4,5,6,7,8,9};
    int *ptro;
    ptro = a;
    printf("\nLa dirección de ptro antes del bucle es %p\n", ptro);

    printf("\n\n");
    for (i=0;i<10;i++){
    printf("[%d]",ptro[i]); //acceso con sintaxis de array
    }
    printf("\n\n");
                    //Desplaza la dirección (cada vez 4 bytes).
    for (i=0;i<10;i++,ptro++){ //aritmética de punteros
    printf("[%d]",*ptro);
    }
    printf("\n\n");
    /* Ejecutándolo vemos que efectivamente apunta al primero y que es lo mismo recorrerlo en forma de array o en forma de puntero */
    
    printf("La dirección de ptro después del bucle es %p\n", ptro);
    printf("La dirección se modifica en el segundo bucle por que al usar aritmética de punteros estamos haciendo que el puntero apunte a cada valor del array, cada vez que se ejecuta el bucle (ptro++) modificando su dirección\n");
    
    ptro = a;
    visualizar(ptro);
    printf("No cambia ya que en la función realemente solo tenemos una copia de ptro, tendriamos que hacer un puntero a puntero para modificarlo.\n");
    visualizar(a);
    
    printf("\n\n---Ejercicio 4:---\n");
    
    int *p1,*p2,*p3;
    p1 = (int *)malloc(sizeof(int));
    p2 = (int *)malloc(sizeof(int));
    p3 = (int *)malloc(sizeof(int));
    *p1 = 10;
    *p2 = 20;
    *p3 = 30;
    // *p el valor que apunta cada puntero, p, la dirección.
    printf("\n Dato apuntado por p1 es %d dirección del dato %p",*p1,p1);
    printf("\n Dato apuntado por p2 es %d dirección del dato %p",*p2,p2);
    printf("\n Dato apuntado por p3 es %d dirección del dato %p",*p3,p3);
    //Aquí vamos a ver que cada puntero tiene un valor y una dirección diferente.
    
    //libero p1
    free(p1);
    printf("\n Dato apuntado por p1 es %d dirección del dato %p",*p1,p1);
    printf("\n Dato apuntado por p2 es %d dirección del dato %p",*p2,p2);
    printf("\n Dato apuntado por p3 es %d dirección del dato %p",*p3,p3);
    /*Ahora p1 va a apuntar a una dirección aleatoria, dirección basura, en mi caso, al ejecutar sigue apuntando a la anterior dirección. */
    
    //libero p3
    free(p3);
    //reservo p1
    p1 = (int *)malloc(sizeof(int));
    *p1 = 99;
    printf("\n Dato apuntado por p1 es %d dirección del dato %p",*p1,p1);
    printf("\n Dato apuntado por p2 es %d dirección del dato %p",*p2,p2);
    printf("\n Dato apuntado por p3 es %d dirección del dato %p",*p3,p3);
    //p1 vuelve a tener una dirección y un valor asignado y p3 apunta a basura.
    //En mi caso p1 toma la dirección liberada de p3.
    printf("\n");
    
    printf("\n\n---Ejercicio 5:---\n");
    
    int *puntero;
    puntero = (int *)malloc(sizeof(int));
    *puntero = 23;
    //Es incorrecto volver a asignarle memoria sin haberla liberado, lo que debemos hacer:
    //free(puntero) y luego:
    puntero = (int *)malloc(sizeof(int));
    
    printf("\n Dato apuntado es %d dirección del dato %p\n",*puntero,puntero);
    
    
    return 0;
}

void cambiarValor(int *puntero) {
    
    printf("Introduce un valor: ");
    scanf("%d", puntero);
}

void inicializarPtro(struct datos **ptroIncializarNULL) {
    
    *ptroIncializarNULL = NULL;
}

void inicializarPunto(struct datos *variable) {
    
    printf("Introduce un valor para x: ");
    scanf("%lf", &variable->x);
    printf("Introduce un valor para y: ");
    scanf("%lf", &variable->y);
}

void modificarptroPoint(struct datos *modificar) {
    
    printf("Introduce un nuevo valor para x: ");
    scanf("%lf", &modificar->x);
    printf("Introduce un nuevo valor para y: ");
    scanf("%lf", &modificar->y);
}

void visualizar(int *punteroPtro){ //declaración función
    
    int i;
    printf("\n\n");
    printf("\n Dirección ptro %p\n",punteroPtro);
    for (i=0;i<10;i++,punteroPtro++){ //aritmética de punteros
        printf("[%d]",*punteroPtro);
    }
    printf("\n\n");
}
