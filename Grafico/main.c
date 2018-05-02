#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, rango1=6, rango2=4, rango3=3, flag=0, mayor;

    if(rango1 >= rango2 && rango1 >= rango3){
        mayor = rango1;
    }else{
        if(rango2 >= rango1 && rango2 >= rango3){
            mayor = rango2;
        }else{
        mayor = rango3;
        }
    }

    for(i=mayor; i>0; i--){
        if(i<= rango1){
            printf("*");
        }
        if(i<= rango2){
            flag=1;
            printf("\t*");

        }
        if(i<= rango3){
            if(flag==0)
                printf("\t\t*");
            if(flag==1)
                printf("\t*");
        }
        //Bajo una linea luego de cada iteracion
        printf("\n");
    }
    printf("<18\t19-35\t>35");
    return 0;
}
