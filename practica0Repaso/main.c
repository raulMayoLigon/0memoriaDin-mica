#include <stdio.h>
#include <string.h>

//Declarar Estructura persona:
struct persona {
    char nick[20];
    char password[8];
    int age;
    int nCompras;
    int importeTotal;
    int s;
};

//Declarar Funciones:
int comprobarNick(struct persona pp[], int numPersonas, char newNick[]);
void annadirUsuarios(struct persona pp[], int *numPersonas);
void realizarCompra(struct persona pp[], int numPersonas);
void listarUsuarios(struct persona pp[], int numPersonas);

//Main:
int main(void) {
    struct persona personas[40];
    int nUsuarios = 0;
    int option;
    
    do {
        // Menú:
        printf("\n--- MENU ---\n");
        printf("1. Añadir un Usuario a la web.\n");
        printf("2. Realizar una Compra.\n");
        printf("3. Listar Usuarios.\n");
        printf("4. Salir.\n");
        printf("Introduce una Opción: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                annadirUsuarios(personas, &nUsuarios);
                break;
            case 2:
                realizarCompra(personas, nUsuarios);
                break;
            case 3:
                listarUsuarios(personas, nUsuarios);
                break;
            case 4:
                printf("------>>Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida, intenta de nuevo.\n");
        }
    } while (option != 4);

    return 0;
}

int comprobarNick(struct persona pp[], int numPersonas, char newNick[]) {
    for (int i = 0; i < numPersonas; i++) {
        if (strcmp(pp[i].nick, newNick) == 0) {
            return 1; // Nick existe
        }
    }
    return 0; // Nick no existe
}

/*Lo hacemos puntero ya que si no al llamar varias veces a la funcion se sobreescribiría numPersonas */
void annadirUsuarios(struct persona pp[], int *numPersonas) {
    struct persona newUser;
    
    do {
        printf("Introduce el nick del Usuario: ");
        fpurge(stdin);
        scanf("%s", newUser.nick);
        if (comprobarNick(pp, *numPersonas, newUser.nick)) {
            printf("Este Usuario ya Existe.\n");
        }
    } while (comprobarNick(pp, *numPersonas, newUser.nick));
    
    printf("Introduce la Contraseña: ");
    fpurge(stdin);
    scanf("%s", newUser.password);
    printf("Edad: ");
    fpurge(stdin);
    scanf("%d", &newUser.age);
    
    newUser.nCompras = 0;
    newUser.importeTotal = 0;
    
    //Guardar el usuario
    pp[*numPersonas] = newUser;
    (*numPersonas)++;
}
   
void realizarCompra(struct persona pp[], int numPersonas) {
    char nick[20];
    char password[8];
    int importe;
    int encontrado = 0;
    
    printf("Introduce tu nick: ");
    fpurge(stdin);
    scanf("%s", nick);
    printf("Introduce tu contraseña: ");
    fpurge(stdin);
    scanf("%s", password);
    
    for (int i = 0; i < numPersonas; i++) {
        if (strcmp(pp[i].nick, nick) == 0 && strcmp(pp[i].password, password) == 0) {
            encontrado = 1;
            printf("Introduce el importe de la compra: ");
            scanf("%d", &importe);
            
            if (importe <= 0) {
                printf("El importe debe ser mayor que 0.\n");
                return;
            }
            
            pp[i].nCompras++;
            pp[i].importeTotal += importe;
            printf("Compra realizada con éxito.\n");
            return;
        }
    }
    
    if (!encontrado) {
        printf("Usuario o contraseña incorrectos.\n");
    }
}
    
void listarUsuarios(struct persona pp[], int numPersonas) {
    if (numPersonas == 0) {
        printf("No hay ningún Usuario.\n");
        return;
    }

    printf("\n--- LISTA DE USUARIOS ---\n");
    for (int i = 0; i < numPersonas; i++) {
        printf("Usuario %d:\n", i + 1);
        printf("    -Nick: %s\n", pp[i].nick);
        printf("    -Edad: %d\n", pp[i].age);
        printf("    -Compras realizadas: %d\n", pp[i].nCompras);
        printf("    -Importe total gastado: %d\n", pp[i].importeTotal);
        printf("-------------------------\n");
    }
}



