#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    int x=0;
    int y=0;
    system("title Calculadora");
    system("mode con: cols=46 lines=26");
    system("color 0a");

    do{
        system("cls");
        printf("______________________________________________\n");
        printf("             A=%d             B=%d\n", x, y);
        printf("______________________________________________\n");
        printf("  1- Ingresar 1er operando (A=x)\n");
        printf("  2- Ingresar 2do operando (B=y)\n");
        printf("  3- Calcular la suma (A+B)\n");
        printf("  4- Calcular la resta (A-B)\n");
        printf("  5- Calcular la division (A/B)\n");
        printf("  6- Calcular la multiplicacion (A*B)\n");
        printf("  7- Calcular el factorial (A!)\n");
        printf("  8- Calcular todas las operaciones\n");
        printf("  9- Salir\n");
        printf("______________________________________________\n");
        printf("Ingrese una opcion:");
        scanf("%d",&opcion);

        while(!validarRango(opcion,1,9)){
            printf("\nError. Ingrese una opcion: ");
            scanf("%d", &opcion);
        }
        switch(opcion){
            case 1:
                printf("\nIngrese primer numero: ");
                scanf("%d", &x);
                break;
            case 2:
                printf("\nIngrese segundo numero: ");
                scanf("%d", &y);
                break;
            case 3:
                printf("\nLa suma de los operandos es: %d\n\n",sumar(x,y));
                system("pause");
                break;
            case 4:
                printf("\nLa resta de los operandos es: %d\n\n",restar(x,y));
                system("pause");
                break;
            case 5:
                if(y==0){
                    printf("\nEl divisor no puede ser cero.\nIngrese otro numero.\n\n");
                    system("pause");
                }else{
                    printf("\nLa division de los operandos es: %.2f\n\n",dividir(x,y));
                    system("pause");
                }
                break;
            case 6:
                printf("\nLa multiplicacion de los operandos es: %d\n\n",multiplicar(x,y));
                system("pause");
                break;
            case 7:
                if(x<0){
                    printf("\nNo hay factorial de numeros negativos.\nIngrese otro numero.\n\n");
                    system("pause");
                }else{
                    printf("\nEl factorial del numero: %d es: %li\n",x,factorial(x));
                    system("pause");
                }
                break;
            case 8:
                todasLasOp(x,y);
                system("pause");
                break;
            case 9:
                seguir = 'n';
                break;
            default:
            break;
        }
    }while(seguir=='s');
    return 0;
}
