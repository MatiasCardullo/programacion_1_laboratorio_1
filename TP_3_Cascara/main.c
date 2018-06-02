#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(){
    system("color 0a");
    system("title Base de datos de peliculas");
    char opcion='0';
    EMovie lista[CANTIDAD];
    inicializarLista(lista);
    readFile(lista);
    while(opcion!='6'){
        system("mode con cols=41 lines=15");
        printf("_________________________________________\n");
        printf("   1- Agregar pelicula\n");
        printf("   2- Borrar pelicula\n");
        printf("   3- Modificar pelicula\n");
        printf("   4- Generar pagina web\n");
        printf("   5- Listar peliculas\n");
        printf("   6- Salir\n");
        printf("_________________________________________\n");
        printf(" Ingrese opcion: ");
        fflush(stdin);
        scanf("%c",&opcion);
        switch(opcion){
            case '1':
                system("mode con cols=90 lines=30");
                printf("__________________________________________________________________________________________\n");
                addMovie(lista);
                saveFile(lista);
                break;
            case '2':
                system("mode con cols=90 lines=30");
                quitMovie(lista);
                saveFile(lista);
                break;
            case '3':
                system("mode con cols=90 lines=30");
                changeMovie(lista);
                saveFile(lista);
                break;
            case '4':
                createHtml(lista);
                printf("\n          Archivo html creado\n ");
                system("pause");
                break;
            case '5':
                system("mode con cols=90 lines=30");
                listMovies(lista);
                printf("\nPeliculas: %d\n\n",contarPeliculas(lista));
                system("pause");
                break;
            case '6':
                break;
            default:
                printf("\n    Error, ingrese opcion nuevamente.\n ");
                system("pause");
                break;

        }
    }

    return 0;
}
