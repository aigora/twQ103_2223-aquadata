// TRABAJO INFORMÁTICA
#include <stdio.h>
#include <string.h>

struct Tfuente{
	char fuente[10];
	float pH;
	int conductividad;
	int turbidez;
	int coliformes;
	int puntos;
};

void buscarph(struct Tfuente lavapies[], float);
void buscarcond(struct Tfuente lavapies[],int);
void buscarturb (struct Tfuente lavapies[],int);
void buscarcoliforme (struct Tfuente lavapies[],int);
float mediac(struct Tfuente lavapies[],int);
float mediaspH(struct Tfuente lavapies[], int);
float mediasturbidez(struct Tfuente lavapies[],int);
float mediascoliformes(struct Tfuente lavapies[],int);



int main () {
	struct Tfuente lavapies[500];
	int nfuentes;
	char parametro;
	char max[25];
	int i,j;
	int opcion;
	char opciondato;
	float ph1;
	int conductividad, turbidez, coliformes;
	FILE *ficherodado;
	ficherodado = fopen("202301_Lavapies.txt", "r"); // Modo: "r" "w" (hay otros modos)

	if (ficherodado == NULL) {
		printf("Error, no puede abrir el fichero.\n");
		return 0;
	}

	do{

	printf("Introduce la opcion que desee\n");
	printf("1: Buscar Datos de la fuente\n");
	printf("2: Anadir datos de parametro u otra fuente\n");
	printf("3: Información\n");
	printf("4: Salir del programa\n");
	scanf("%d", &opcion);

	switch(opcion){
		case 1:
		    do{
			printf("¿Que datos desea buscar?\n");
			printf("B. Buscar datos \n");
			printf("E. Estadisticas\n");
			fflush(stdin);
			scanf ("%c", &opciondato);

		}while ( opciondato != 'B' && opciondato != 'E');


            case 'B':
            case 'b':
            //	do{

            	printf("¿Que parametro quieres buscar?\n");
            	printf("Pulse P. pH\n");
            	printf("Pulse C. conductividad\n");
            	printf("Pulse T. turbidez\n");
            	printf("Pulse F. coliformes\n");
            	fflush(stdin);
            	scanf("%c", &parametro);
            	if (parametro == 'P'){
            			printf("Introduce el pH del agua buscado que se encuentra entre 6 y 8\n");
            			scanf("%f", &ph1);
                        buscarph(lavapies, ph1);}
	 			else if(parametro=='C'){
	 				printf("Introduce la conductIvidad del agua buscada que se encuentra entre 100 y 300\n");
            			scanf("%d", &conductividad);
                        buscarcond(lavapies, conductividad);}

                else if(parametro=='T'){
	 				printf("Introduce la turbidez del agua buscada que se encuentra entre 0 y 10\n");
            			scanf("%d", &turbidez);
                        buscarturb(lavapies, turbidez);}

                else if(parametro=='F'){
	 				printf("Introduce la turbidez del agua buscada que se encuentra entre 0 y 2\n");
            			scanf("%d", &coliformes);
                        buscarcoliforme(lavapies, coliformes);}

//}while(parametro!='P' || parametro!='C' || parametro!='T' ||parametro!='F')

            break; // BREAK CASE B
            case 'e':
            case 'E':

                  while(fscanf(ficherodado, "%s %f %d %d %d", lavapies[i].fuente, &lavapies[i].pH, &lavapies[i].conductividad, &lavapies[i].turbidez, &lavapies[i].coliformes)!= EOF){ //en el fscanf nunca se ponen \n
                    if(lavapies[i].pH >= 6.8 && lavapies[i].pH <= 7.2){
                        lavapies[i].puntos = 3;
                    } else if(lavapies[i].pH > 7.2 && lavapies[i].pH <= 8){
                        lavapies[i].puntos = 2;
                    }else if(lavapies[i].pH >=6 && lavapies[i].pH < 6.8){
                        lavapies[i].puntos = 1;
                    }else {
                        lavapies[i].puntos = 0;}
                    if(lavapies[i].conductividad >= 190){
                        lavapies[i].puntos += 3;
                    } else if (lavapies[i].conductividad >= 145){
                        lavapies[i].puntos += 2;
                    } else if (lavapies[i].conductividad >= 100){
                        lavapies[i].puntos += 1;
                    }else {
                        lavapies[i].puntos += 0;
                    }
                    if(lavapies[i].turbidez == 0){
                        lavapies[i].puntos += 3;
                    }else if (lavapies[i].turbidez >= 1 && lavapies[i].turbidez <= 4){
                        lavapies[i].puntos += 1;
                    }else {
                        lavapies[i].puntos += 0;}
                    if(lavapies[i].coliformes == 0){
                        lavapies[i].puntos += 3;
                    }else {
                        lavapies[i].puntos += 0;}
                        }

                    while(fscanf(ficherodado, "%s %f %d %d %d", lavapies[i].fuente, &lavapies[i].pH, &lavapies[i].conductividad, &lavapies[i].turbidez, &lavapies[i].coliformes)!= EOF){
                        max = lavapies[1].puntos;
                        for(i=1; i< 26; i++){
                        if (max < lavapies[i].puntos){
                            max = lavapies[i].fuente;
                            lavapies[i].fuente = i;
                }
    }
            printf("El maximo de puntos es %s, de la fuente %s", max, lavapies[i].fuente);}

            	printf("Media conductividad: %f\n", mediac (lavapies, 25)/25);
            	printf("Media conductividad: %f\n", mediaspH (lavapies, 25)/25);
				printf("Media conductividad: %f\n", mediasturbidez (lavapies, 25)/25);
				printf("Media conductividad: %f\n", mediascoliformes (lavapies, 25)/25);
            	break;}



		/*case 2:
			printf("bien 2");
			break;

		case 3:
			printf("bien 3");
			break;
		}*/



}while(opcion > 4 || opcion < 1);
    fclose(ficherodado);
	if(opcion == 4){
		return 0;}
}
void buscarph(struct Tfuente lavapies[], float ph){
                        int i=0;

                        if(ph>=6 && ph<=6.5){
                            printf("Las fuentes con un ph mas cercanas a %f que se encuentran entre 6 y 6.5 son:\n", ph);
                           while (fscanf(ficherodado, "%s %f %d %d %d", lavapies[i].fuente, &lavapies[i].pH, &lavapies[i].conductividad, &lavapies[i].turbidez, &lavapies[i].coliformes) != EOF){
                              if (lavapies[i].pH >=6 && lavapies[i].pH<=6.5)
                                printf("%s %f %d %d %d\n", lavapies[i].fuente, lavapies[i].pH, lavapies[i].conductividad, lavapies[i].turbidez, lavapies[i].coliformes);}
                        }else if(ph<=7){
                            printf("Las fuentes con un ph mas cercanas a %f que se encuentran entre 6.5 y 7 son:\n", ph);
                           while (fscanf(ficherodado, "%s %f %d %d %d", lavapies[i].fuente, &lavapies[i].pH, &lavapies[i].conductividad, &lavapies[i].turbidez, &lavapies[i].coliformes) != EOF){
                                    if (lavapies[i].pH >=6.5 && lavapies[i].pH<=7)
                                        printf("%s %f %d %d %d\n", lavapies[i].fuente, lavapies[i].pH, lavapies[i].conductividad, lavapies[i].turbidez, lavapies[i].coliformes);}

                        }else if(ph<=7.5){
                            printf("Las fuentes con un ph mas cercanas a %f que se encuentran entre 7 y 7.5 son:\n", ph);
                           while (fscanf(ficherodado, "%s %f %d %d %d", lavapies[i].fuente, &lavapies[i].pH, &lavapies[i].conductividad, &lavapies[i].turbidez, &lavapies[i].coliformes) != EOF){
                              if (lavapies[i].pH >=7 && lavapies[i].pH<=7.5)
                                printf("%s %f %d %d %d\n", lavapies[i].fuente, lavapies[i].pH, lavapies[i].conductividad, lavapies[i].turbidez, lavapies[i].coliformes);}

                        } else if(ph<=8){
                            printf("Las fuentes con un ph mas cercanas a %f que se encuentran entre 7.5 y 8 son:\n", ph);
                           while (fscanf(ficherodado, "%s %f %d %d %d", lavapies[i].fuente, &lavapies[i].pH, &lavapies[i].conductividad, &lavapies[i].turbidez, &lavapies[i].coliformes) != EOF){
                              if (lavapies[i].pH >=7.5 && lavapies[i].pH<=8)
                                printf("%s %f %d %d %d\n", lavapies[i].fuente, lavapies[i].pH, lavapies[i].conductividad, lavapies[i].turbidez, lavapies[i].coliformes);}}
                                }

void buscarcond(struct Tfuente lavapies[],int conductividad){
	int i=0;
                        FILE *ficherodado;
                        ficherodado = fopen("202301_Lavapies.txt", "r"); // Modo: "r" "w" (hay otros modos)

                        if (ficherodado == NULL) {
                        printf("Error, no puede abrir el fichero.\n");
                        }
                        if(conductividad>=100 && conductividad<=150){
                            printf("Las conductividades mas cercanas de %d que se encuentran entre 100 y 150 son:\n", conductividad);
                           while (fscanf(ficherodado, "%s %f %d %d %d", lavapies[i].fuente, &lavapies[i].pH, &lavapies[i].conductividad, &lavapies[i].turbidez, &lavapies[i].coliformes) != EOF){
                              if (lavapies[i].conductividad >=100 && lavapies[i].conductividad<=150)
                                printf("%s %f %d %d %d\n", lavapies[i].fuente, lavapies[i].pH, lavapies[i].conductividad, lavapies[i].turbidez, lavapies[i].coliformes);}

                        }else if(conductividad>150 && conductividad<=200){
                            printf("Las conductividades mas cercanas de %d que se encuentran entre 150 y 200 son\n", conductividad);
                           while (fscanf(ficherodado, "%s %f %d %d %d", lavapies[i].fuente, &lavapies[i].pH, &lavapies[i].conductividad, &lavapies[i].turbidez, &lavapies[i].coliformes) != EOF){
                              if (lavapies[i].conductividad >=150 && lavapies[i].conductividad<=200)
                                printf("%s %f %d %d %d\n", lavapies[i].fuente, lavapies[i].pH, lavapies[i].conductividad, lavapies[i].turbidez, lavapies[i].coliformes);}

                        } else if(conductividad>200 && conductividad<=250){
                            printf("Las conductividades mas cercanas de %d que se encuentran entre 200 y 250 son\n", conductividad);
                           while (fscanf(ficherodado, "%s %f %d %d %d", lavapies[i].fuente, &lavapies[i].pH, &lavapies[i].conductividad, &lavapies[i].turbidez, &lavapies[i].coliformes) != EOF){
                              if (lavapies[i].conductividad >=200 && lavapies[i].conductividad<=250)
                                printf("%s %f %d %d %d\n", lavapies[i].fuente, lavapies[i].pH, lavapies[i].conductividad, lavapies[i].turbidez, lavapies[i].coliformes);}}

                        else if(conductividad>250 && conductividad<=300){
                            printf("Las conductividades mas cercanas de %d que se encuentran entre 250 y 300 son\n", conductividad);
                           while (fscanf(ficherodado, "%s %f %d %d %d", lavapies[i].fuente, &lavapies[i].pH, &lavapies[i].conductividad, &lavapies[i].turbidez, &lavapies[i].coliformes) != EOF){
                              if (lavapies[i].conductividad >=250 && lavapies[i].conductividad<=300)
                                printf("%s %f %d %d %d\n", lavapies[i].fuente, lavapies[i].pH, lavapies[i].conductividad, lavapies[i].turbidez, lavapies[i].coliformes);}}


}

void buscarturb (struct Tfuente lavapies[],int turbidez){
                        int i=0;
                        FILE *ficherodado;
                        ficherodado = fopen("202301_Lavapies.txt", "r"); // Modo: "r" "w" (hay otros modos)

                        if (ficherodado == NULL) {
                        printf("Error, no puede abrir el fichero.\n");
                        }
                        if(turbidez == 0){
                            printf("Las turbidadez mas cercanas de %d que se encuentran entre 100 y 125 son:\n", turbidez);
                           while (fscanf(ficherodado, "%s %f %d %d %d", lavapies[i].fuente, &lavapies[i].pH, &lavapies[i].conductividad, &lavapies[i].turbidez, &lavapies[i].coliformes) != EOF){
                              if (lavapies[i].conductividad == 0)
                                printf("%s %f %d %d %d\n", lavapies[i].fuente, lavapies[i].pH, lavapies[i].conductividad, lavapies[i].turbidez, lavapies[i].coliformes);}

                        }else if(turbidez == 1){
                            printf("Las turbidadez mas cercanas de %d que se encuentran entre 125 y 150 son\n", turbidez);
                           while (fscanf(ficherodado, "%s %f %d %d %d", lavapies[i].fuente, &lavapies[i].pH, &lavapies[i].conductividad, &lavapies[i].turbidez, &lavapies[i].coliformes) != EOF){
                              if (lavapies[i].conductividad == 1)
                                printf("%s %f %d %d %d\n", lavapies[i].fuente, lavapies[i].pH, lavapies[i].conductividad, lavapies[i].turbidez, lavapies[i].coliformes);}

                        } else if(turbidez == 2){
                            printf("Las turbidadez mas cercanas de %d que se encuentran entre 150 y 175 son\n", turbidez);
                           while (fscanf(ficherodado, "%s %f %d %d %d", lavapies[i].fuente, &lavapies[i].pH, &lavapies[i].conductividad, &lavapies[i].turbidez, &lavapies[i].coliformes) != EOF){
                              if (lavapies[i].conductividad == 2)
                                printf("%s %f %d %d %d\n", lavapies[i].fuente, lavapies[i].pH, lavapies[i].conductividad, lavapies[i].turbidez, lavapies[i].coliformes);}}

                        else if(turbidez == 3){
                            printf("Las turbidadez mas cercanas de %d que se encuentran entre 175 y 200 son\n", turbidez);
                           while (fscanf(ficherodado, "%s %f %d %d %d", lavapies[i].fuente, &lavapies[i].pH, &lavapies[i].conductividad, &lavapies[i].turbidez, &lavapies[i].coliformes) != EOF){
                              if (lavapies[i].conductividad == 3)
                                printf("%s %f %d %d %d\n", lavapies[i].fuente, lavapies[i].pH, lavapies[i].conductividad, lavapies[i].turbidez, lavapies[i].coliformes);}}

                        else if(turbidez == 4){
                            printf("Las turbidez mas cercanas de %d que se encuentran entre 175 y 200 son\n", turbidez);
                           while (fscanf(ficherodado, "%s %f %d %d %d", lavapies[i].fuente, &lavapies[i].pH, &lavapies[i].conductividad, &lavapies[i].turbidez, &lavapies[i].coliformes) != EOF){
                              if (lavapies[i].conductividad == 4)
                                printf("%s %f %d %d %d\n", lavapies[i].fuente, lavapies[i].pH, lavapies[i].conductividad, lavapies[i].turbidez, lavapies[i].coliformes);}}

                            else if(turbidez == 5){
                            printf("Las turbidez mas cercanas de %d que se encuentran entre 175 y 200 son\n", turbidez);
                           while (fscanf(ficherodado, "%s %f %d %d %d", lavapies[i].fuente, &lavapies[i].pH, &lavapies[i].conductividad, &lavapies[i].turbidez, &lavapies[i].coliformes) != EOF){
                              if (lavapies[i].conductividad == 5)
                                printf("%s %f %d %d %d\n", lavapies[i].fuente, lavapies[i].pH, lavapies[i].conductividad, lavapies[i].turbidez, lavapies[i].coliformes);}}

                            else if(turbidez == 10){
                            printf("Las turbidadez mas cercanas de %d que se encuentran entre 175 y 200 son\n", turbidez);
                           while (fscanf(ficherodado, "%s %f %d %d %d", lavapies[i].fuente, &lavapies[i].pH, &lavapies[i].conductividad, &lavapies[i].turbidez, &lavapies[i].coliformes) != EOF){
                              if (lavapies[i].conductividad == 10)
                                printf("%s %f %d %d %d\n", lavapies[i].fuente, lavapies[i].pH, lavapies[i].conductividad, lavapies[i].turbidez, lavapies[i].coliformes);}}

                            else {
                                printf("No existen fuentes con esa conductividad\n");
                            }



}


void buscarcoliforme(struct Tfuente lavapies[], int coliformes){
                        int i=0;
                        FILE *ficherodado;
                        ficherodado = fopen("202301_Lavapies.txt", "r"); // Modo: "r" "w" (hay otros modos)

                        if (ficherodado == NULL) {
                        printf("Error, no puede abrir el fichero.\n");
                        }
                        if(coliformes == 0){
                            printf("Las fuentes con una cantidad de %d de colonias coliformes \n", coliformes);
                           while (fscanf(ficherodado, "%s %f %d %d %d", lavapies[i].fuente, &lavapies[i].pH, &lavapies[i].conductividad, &lavapies[i].turbidez, &lavapies[i].coliformes) != EOF){
                              if (lavapies[i].coliformes == 0)
                                printf("%s %f %d %d %d\n", lavapies[i].fuente, lavapies[i].pH, lavapies[i].conductividad, lavapies[i].turbidez, lavapies[i].coliformes);}
                        }else if(coliformes == 1){
                            printf("Las fuentes con una cantidad de %d de colonias coliformes \n", coliformes);
                           while (fscanf(ficherodado, "%s %f %d %d %d", lavapies[i].fuente, &lavapies[i].pH, &lavapies[i].conductividad, &lavapies[i].turbidez, &lavapies[i].coliformes) != EOF){
                                    if (lavapies[i].coliformes == 1)
                                        printf("%s %f %d %d %d\n", lavapies[i].fuente, lavapies[i].pH, lavapies[i].conductividad, lavapies[i].turbidez, lavapies[i].coliformes);}
                        }else if(coliformes == 2){
                            printf("Las fuentes con una cantidad de %d de colonias coliformes \n", coliformes);
                           while (fscanf(ficherodado, "%s %f %d %d %d", lavapies[i].fuente, &lavapies[i].pH, &lavapies[i].conductividad, &lavapies[i].turbidez, &lavapies[i].coliformes) != EOF){
                                    if (lavapies[i].coliformes == 2)
                                        printf("%s %f %d %d %d\n", lavapies[i].fuente, lavapies[i].pH, lavapies[i].conductividad, lavapies[i].turbidez, lavapies[i].coliformes);}
                        }else printf("No hay esa cantidad de colonias coliformes \n");
}
float mediac (struct Tfuente lavapies[], int dim) {
	int i=0;
	float media=0;

	FILE *fichero;
	fichero = fopen("202301_Lavapies.txt", "r");

	if (fichero == NULL) {
		printf("Error, no puede abrir el fichero.\n");

	}

	while (fscanf(fichero, "%s %f %d %d %d %d %f", &lavapies[i].fuente, &lavapies[i].pH, &lavapies[i].conductividad,
	&lavapies[i].turbidez, &lavapies[i].coliformes) != EOF){
		media += lavapies[i].conductividad;
	}

	return (media);
}
float mediaspH (struct Tfuente lavapies[], int dim) {
	int i=0;
	float media=0;

	FILE *fichero;
	fichero = fopen("202301_Lavapies.txt", "r");

	if (fichero == NULL) {
		printf("Error, no puede abrir el fichero.\n");

	}

	while (fscanf(fichero, "%s %f %d %d %d %d %f", &lavapies[i].fuente, &lavapies[i].pH, &lavapies[i].conductividad,
	&lavapies[i].turbidez, &lavapies[i].coliformes) != EOF){
		media += lavapies[i].pH;
	}

	return (media);
}
float mediasturbidez(struct Tfuente lavapies[], int dim) {
	int i=0;
	float media=0;

	FILE *fichero;
	fichero = fopen("202301_Lavapies.txt", "r");

	if (fichero == NULL) {
		printf("Error, no puede abrir el fichero.\n");

	}

	while (fscanf(fichero, "%s %f %d %d %d %d %f", &lavapies[i].fuente, &lavapies[i].pH, &lavapies[i].conductividad,
	&lavapies[i].turbidez, &lavapies[i].coliformes) != EOF){
		media += lavapies[i].turbidez;
	}

	return (media);
}
float mediascoliformes(struct Tfuente lavapies[], int dim) {
	int i=0;
	float media=0;

	FILE *fichero;
	fichero = fopen("202301_Lavapies.txt", "r");

	if (fichero == NULL) {
		printf("Error, no puede abrir el fichero.\n");

	}

	while (fscanf(fichero, "%s %f %d %d %d %d %f", &lavapies[i].fuente, &lavapies[i].pH, &lavapies[i].conductividad,
	&lavapies[i].turbidez, &lavapies[i].coliformes) != EOF){
		media += lavapies[i].coliformes;
	}

	return (media);
}
