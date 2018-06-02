#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


#define CANTIDAD 20

typedef struct{
    char titulo[100];
    char genero[100];
    int duracion;
    char descripcion[200];
    int puntaje;
    char linkImagen[200];
    int estado;
    int id;
}EMovie;

//funciones para enlistar

int buscaEstadoLibre (EMovie*);
int contarPeliculas(EMovie*);
void inicializarLista(EMovie*);

//funciones para tomar y recibir datos

int getString(char*,int);
int stringNumber(char*);
int validateNumber(int,int,int);

void askTitle(EMovie*,int);
void askGenre(EMovie*,int);
void askDuration(EMovie*,int);
void askDescription(EMovie*,int);
void askScore(EMovie*,int);
void askLinkImage(EMovie*,int);

int setTitle(EMovie*,char*,int);
int setGenre(EMovie*,char*,int);
int setDescription(EMovie*, char*,int);
int setLinkImage(EMovie*, char*,int);
int setDuration(EMovie*, int,int);
int setScore(EMovie*, int,int);
int setState(EMovie*, int,int);
int setId(EMovie*, int,int);

void getTitle(EMovie*,int,char*);
void getGenre(EMovie*,int,char*);
void getDescription(EMovie*,int,char*);
void getLinkImage(EMovie*,int,char*);
int getDuration(EMovie*,int);
int getScore(EMovie*,int);
int getState(EMovie*,int);
int getId(EMovie*,int);

// funciones para las peliculas

void addMovie(EMovie*);
void listMovies(EMovie*);
void quitMovie(EMovie*);
int hayRegistro(EMovie*);
int buscarxId(EMovie*,int);
void changeMovie(EMovie*);

// funciones para archivos

void saveFile(EMovie*);
void readFile(EMovie*);
void createHtml(EMovie*);

#endif
