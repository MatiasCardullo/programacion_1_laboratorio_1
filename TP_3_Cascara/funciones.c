#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "funciones.h"

int validateNumber(int min,int max,int dato){
    if((dato+1)>min&&(dato-1)<max)
        {return dato;}
    return -1;
}

int getString(char* dato, int caracteres){
    if(dato!=NULL){
        fflush(stdin);
        fgets(dato,caracteres,stdin);
        int largo=0;
        while (*(dato+largo)!='\n'){largo++;}
        *(dato+largo)='\0';
        return 0;
    }return -1;
}

int stringNumber(char* dato){
    int a=0;
    while(isdigit(*(dato+a))){
        a++;
        if(*(dato+a)=='\0')
            {return atoi(dato);}
    }return -1;
}

void askTitle(EMovie* movie,int index){
    char aux[100];
    printf("\nIngrese titulo: ");
    getString(aux,100);
    if(setTitle(movie,aux,index)==1)
        {setTitle(movie,aux,index);}
}

void askGenre(EMovie* movie,int index){
    char aux[100];
    printf("\nIngrese genero: ");
    getString(aux,100);
    if(setGenre(movie,aux,index)==1)
        {setGenre(movie,aux,index);}
}

void askDuration(EMovie* movie,int index){
    char aux[21];
    printf("\nIngrese duracion (0-300 mins): ");
    getString(aux,50);
    while(stringNumber(aux)==-1 || validateNumber(0,300,stringNumber(aux))==-1){
        printf("\nDURACION INVALIDA\n");
        printf("\nIngrese duracion (0-300 mins): ");
        getString(aux,50);
    }setDuration(movie,stringNumber(aux),index);
}

void askDescription(EMovie* movie,int index){
    char aux[200];
    printf("\nIngrese descripcion: ");
    getString(aux,300);
    if(setDescription(movie,aux,index)==1)
        {setDescription(movie,aux,index);}
}

void askScore(EMovie* movie,int index){
    char aux[20];
    printf("\nIngrese puntaje (1-10): ");
    getString(aux,20);
    int p=stringNumber(aux);
    while(p==-1 || validateNumber(0,10,p)==-1){
        printf("\nPUNTAJE INVALIDO\n");
        printf("\nIngrese puntaje (1-10): ");
        getString(aux,20);
        p=stringNumber(aux);
    }setScore(movie,p,index);
}

void askLinkImage(EMovie* movie,int index){
    char aux[300];
    printf("\nIngrese link de la imagen: ");
    getString(aux,300);
    if(setLinkImage(movie,aux,index)==1)
        {setLinkImage(movie,aux,index);}
}

// INICIALIZAR Y BUSQUEDA DE ESTADO LIBRE

int buscaEstadoLibre (EMovie* lista){
    int i=0;
    while (getState(lista,i)&& i<CANTIDAD){
        i++;
        if (i==CANTIDAD)
            {return -1;}
    }return i;
}

void inicializarLista(EMovie* lista){
    for(int i=0;i<CANTIDAD;i++){
        setState(lista,0,i);
    }
}

int hayRegistro(EMovie* lista){
    int i=0;
    while (!getState(lista,i)&&i<CANTIDAD){
        i++;
        if (i==CANTIDAD){return 0;}
    }return 1;
}

int buscarxId(EMovie* movie,int id){
    for(int a=0;a<CANTIDAD;a++){
        int id_a=getId(movie,a);
        if(id_a==id){return a;}
    }return -1;
}


int contarPeliculas(EMovie* movie){
    int i=0;
    for(int a=0;a<CANTIDAD;a++){
        if(getState(movie,a)==1){i++;}
    }return i;
}

//SETTERS

int setTitle(EMovie* lista, char* titulo,int posicion){
    if(lista!=NULL){
        strcpy((lista+posicion)->titulo,titulo);
        return 1;
    }return 0;
}

int setGenre(EMovie* lista, char* genero, int posicion){
    if(lista!=NULL){
        strcpy((lista+posicion)->genero, genero);
        return 1;
    }return 0;
}

int setDescription(EMovie* lista, char* descripcion, int posicion){
    if(lista!=NULL){
        strcpy((lista+posicion)->descripcion, descripcion);
        return  1;
    }return 0;
}
int setLinkImage(EMovie* lista, char* linkImagen, int posicion){
    if(lista!=NULL){
        strcpy((lista+posicion)->linkImagen, linkImagen);
        return  1;
    }return 0;
}

int setDuration(EMovie* lista, int duracion,int posicion){
    if(lista!=NULL){
        (lista+posicion)->duracion = duracion;
        return  1;
    }return 0;
}

int setScore(EMovie* lista, int puntaje, int posicion){
    if(lista!=NULL){
        (lista+posicion)->puntaje = puntaje;
        return 1;
    }return 0;
}

int setState(EMovie* lista, int estado, int posicion){
    if(lista!=NULL){
        (lista+posicion)->estado = estado;
        return  1;
    }return 0;
}

int setId(EMovie* lista, int id, int posicion){
    if(lista!=NULL){
        (lista+posicion)->id = id;
        return 1;
    }return 0;
}

//GETTERS

void getLinkImage(EMovie* lista,int posicion, char* l){
    strcpy(l,(lista+posicion)->linkImagen);
}

void getGenre(EMovie* lista,int posicion,char* g){
    strcpy(g,(lista+posicion)->genero);
}

void getDescription(EMovie* lista, int posicion, char* d){
    strcpy(d,(lista+posicion)->descripcion);
}

void getTitle(EMovie* lista,int posicion,char* t){
    strcpy(t,(lista+posicion)->titulo);
}

int getDuration(EMovie* lista,int posicion){
    int dur;
    dur = (lista+posicion)->duracion;
    return dur;
}

int getScore(EMovie* lista,int posicion){
    int pun;
    pun = (lista+posicion)->puntaje;
    return pun;
}

int getState(EMovie* lista,int posicion){
    int est;
    est = (lista+posicion)->estado;
    return est;
}

int getId(EMovie* lista, int posicion){
    int i;
    i = (lista+posicion)->id;
    return i;
}

//LISTAR PELICULAS

void listMovies(EMovie* movie){
    printf("\n\tTitle\t\t\tGenre\t\tMIN\t\tCAL\t\tID\n");
    printf("__________________________________________________________________________________________\n");
    for(int i=0;i<CANTIDAD;i++){
        if(getState(movie,i)){
            char title[100];getTitle(movie,i,title);
            char genre[100];getGenre(movie,i,genre);
            printf(" %s\t\t\t%s\t\t%d\t\t%d\t\t%d\n\n",title,genre,getDuration(movie,i),getScore(movie,i),getId(movie,i));
        }
    }printf("__________________________________________________________________________________________\n");
}

// FUNCIONES DEL MENU

void addMovie(EMovie* movie){
    int index;
    index=buscaEstadoLibre(movie);
    if(index!=-1){
        askTitle(movie,index);
        askGenre(movie,index);
        askDuration(movie,index);
        askDescription(movie,index);
        askScore(movie, index);
        askLinkImage(movie, index);
        if(setState(movie,1,index)==1)
            {setState(movie,1,index);}
        if(setId(movie,0+index,index)==1)
            {setId(movie,0+index,index);}
    }else{
        printf("\nNo hay espacio en la base de datos\n\n");
    }
}

void quitMovie(EMovie* movie){
    if(hayRegistro(movie)){
        system("cls");
        char dato[10];
        int id;
        listMovies(movie);
        printf("\n\tIngrese id de pelicula a borrar: ");
        getString(dato,10);
        id = stringNumber(dato);
        if(id!=-1 && validateNumber(0,2001,id)!=-1){
            int index = buscarxId(movie,id);
            if(index!=-1){
                    setState(movie,0,index);
            }else{
                printf("\nID INEXISTENTE\n");
            }
        }else{
            printf("\nID INVALIDO\n");
        }
    }else{
        printf("\nNO ES POSIBLE EJECUTAR LA ACCION REQUERIDA PORQUE NO HAY ELEMENTOS EN LA BASE DE DATOS\n\n");
    }system("pause");
}

void changeMovie(EMovie* movie){
    if(hayRegistro(movie)){
        system("cls");
        listMovies(movie);
        printf("\n\nIngrese id de pelicula a modificar: ");
        char dato[10];
        int id;
        getString(dato,10);
        id=stringNumber(dato);
        if(id!=-1 && validateNumber(0,2001,id)!=-1){
            int index = buscarxId(movie,id);
            if(index!=-1){
                char opcion=0;
                while(opcion!= '7'){
                    system("mode con cols=41 lines=25");
                    printf("\n\t    Menu Modificacion\n");
                    printf("_________________________________________\n");
                    printf("   1- Titulo\n");
                    printf("   2- Genero\n");
                    printf("   3- Duracion\n");
                    printf("   4- Descripcion\n");
                    printf("   5- Puntaje\n");
                    printf("   6- Link Imagen\n");
                    printf("   7- Salir\n");
                    printf("_________________________________________\n");
                    printf(" Ingrese campo a modificar: ");
                    fflush(stdin);
                    scanf("%c",&opcion);
                    switch(opcion){
                        case '1':
                            askTitle(movie,index);
                            break;
                        case '2':
                            askGenre(movie,index);
                            break;
                        case '3':
                            askDuration(movie,index);
                            break;
                        case '4':
                            askDescription(movie,index);
                            break;
                        case '5':
                            askScore(movie,index);
                            break;
                        case '6':
                            askLinkImage(movie,index);
                            break;
                        case '7':
                            break;
                        default:
                            printf("\n    Error, ingrese opcion nuevamente.\n ");
                            system("pause");
                            break;
                    }
                }
            }
            else{printf("\nID INEXISTENTE\n");}
        }
        else{printf("\n\nID INVALIDO\n");}
    }
    else{printf("\nNo hay peliculas ingresadas en la base.\n");}
    system("pause");
}

//ARCHIVOS

void saveFile(EMovie*  movie){
    int cantidadPelis=contarPeliculas(movie);
    FILE* archivo;
    archivo = fopen("movies.bin","wb");
    fwrite(&cantidadPelis,sizeof(int),1,archivo);
    fwrite(movie,sizeof(EMovie),cantidadPelis,archivo);
    fclose(archivo);
}

void readFile(EMovie* movie){
    int d;
    FILE* archivo;
    archivo = fopen("movies.bin","rb");
    fread(&d,sizeof(int),1,archivo);
    fread(movie,sizeof(EMovie),d,archivo);
}

void createHtml(EMovie* movie){
    FILE* archivo;
    char titulo[100];
    char genero[100];
    char descripcion[200];
    char imagen[200];
    int duracion,puntaje;
    archivo = fopen("index.html","w");
    fprintf(archivo,"<!DOCTYPE html><html lang='en'><FONT COLOR=\"00ff00\"><body bgcolor=\"black\"><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><link href='css/bootstrap.min.css' rel='stylesheet'><link href='css/custom.css' rel='stylesheet'></head><body><div class='container'><div class='row'>");
    for(int i=0;i<CANTIDAD;i++){
        if(getState(movie,i)==1){
            getTitle(movie,i,titulo);
            getDescription(movie,i,descripcion);
            duracion = getDuration(movie,i);
            puntaje = getScore(movie,i);
            getGenre(movie,i,genero);
            getLinkImage(movie,i,imagen);
            fprintf(archivo,"<article class='col-md-4 article-intro'>\n");
            fprintf(archivo,"<a href='#'><img class='img-responsive img-rounded' src='");
            fprintf(archivo,imagen);
            fprintf(archivo,"' alt=''></a>\n");
            fprintf(archivo,"<h3><a href='#'>%s</a></h3>\n",titulo);
            fprintf(archivo,"<ul>\n");
            fprintf(archivo,"<li>Genero: %s</li>\n",genero);
            fprintf(archivo,"<li>Puntaje: %d</li>\n",puntaje);
            fprintf(archivo,"<li>Duracion: %d</li>\n",duracion);
            fprintf(archivo,"</ul>\n");
            fprintf(archivo,"<p>%s</p>\n",descripcion);
            fprintf(archivo,"</article>\n");
        }
    }
    fprintf(archivo,"</div></div><script src='js/jquery-1.11.3.min.js'></script><script src='js/bootstrap.min.js'></script><script src='js/ie10-viewport-bug-workaround.js'></script><script src='js/holder.min.js'></script></body></html>");
    fclose(archivo);
}
