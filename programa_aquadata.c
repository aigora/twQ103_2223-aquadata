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

void buscarph(struct Tfuente barrio[], float);
void buscarcond(struct Tfuente barrio[],int);
void buscarturb (struct Tfuente barrio[],int);
void buscarcoliforme (struct Tfuente barrio[],int);
float mediac(struct Tfuente barrio[],int);
float mediaspH(struct Tfuente barrio[], int);
float mediasturbidez(struct Tfuente barrio[],int);
float mediascoliformes(struct Tfuente barrio[],int);



int main () {
	struct Tfuente barrio[500];
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
                        buscarph(barrio, ph1);}
	 			else if(parametro=='C'){
	 				printf("Introduce la conductIvidad del agua buscada que se encuentra entre 100 y 300\n");
            			scanf("%d", &conductividad);
                        buscarcond(barrio, conductividad);}

                else if(parametro=='T'){
	 				printf("Introduce la turbidez del agua buscada que se encuentra entre 0 y 10\n");
            			scanf("%d", &turbidez);
                        buscarturb(barrio, turbidez);}

                else if(parametro=='F'){
	 				printf("Introduce la turbidez del agua buscada que se encuentra entre 0 y 2\n");
            			scanf("%d", &coliformes);
                        buscarcoliforme(barrio, coliformes);}

//}while(parametro!='P' || parametro!='C' || parametro!='T' ||parametro!='F')

            break; // BREAK CASE B
            case 'e':
            case 'E':

                  while(fscanf(ficherodado, "%s %f %d %d %d", barrio[i].fuente, &barrio[i].pH, &barrio[i].conductividad, &barrio[i].turbidez, &barrio[i].coliformes)!= EOF){ //en el fscanf nunca se ponen \n
                    if(barrio[i].pH >= 6.8 && barrio[i].pH <= 7.2){
                        barrio[i].puntos = 3;
                    } else if(barrio[i].pH > 7.2 && barrio[i].pH <= 8){
                        lavapies[i].puntos = 2;
                    }else if(barrio[i].pH >=6 && barrio[i].pH < 6.8){
                        barrio[i].puntos = 1;
                    }else {
                        barrio[i].puntos = 0;}
                    if(barrio[i].conductividad >= 190){
                        barrio[i].puntos += 3;
                    } else if (barrio[i].conductividad >= 145){
                        barrio[i].puntos += 2;
                    } else if (barrio[i].conductividad >= 100){
                        barrio[i].puntos += 1;
                    }else {
                        barrio[i].puntos += 0;
                    }
                    if(barrio[i].turbidez == 0){
                        barrio[i].puntos += 3;
                    }else if (barrio[i].turbidez >= 1 && barrio[i].turbidez <= 4){
                        barrio[i].puntos += 1;
                    }else {
                        barrio[i].puntos += 0;}
                    if(barrio[i].coliformes == 0){
                        barrio[i].puntos += 3;
                    }else {
                        barrio[i].puntos += 0;}
                        }

                    while(fscanf(ficherodado, "%s %f %d %d %d", barrio[i].fuente, &barrio[i].pH, &barrio[i].conductividad, &barrio[i].turbidez, &barrio[i].coliformes)!= EOF){
                        max = barrio[1].puntos;
                        for(i=1; i< 26; i++){
                        if (max < barrio[i].puntos){
                            max = barrio[i].fuente;
                            barrio[i].fuente = i;
                }
    }
            printf("El maximo de puntos es %s, de la fuente %s", max, barrio[i].fuente);}

            	printf("Media conductividad: %f\n", mediac (barrio, 25)/25);
            	printf("Media conductividad: %f\n", mediaspH (barrio, 25)/25);
				printf("Media conductividad: %f\n", mediasturbidez (barrio, 25)/25);
				printf("Media conductividad: %f\n", mediascoliformes (barrio, 25)/25);
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
void buscarph(struct Tfuente barrio[], float ph){
                        int i=0;

                        if(ph>=6 && ph<=6.5){
                            printf("Las fuentes con un ph mas cercanas a %f que se encuentran entre 6 y 6.5 son:\n", ph);
                           while (fscanf(ficherodado, "%s %f %d %d %d", barrio[i].fuente, &barrio[i].pH,&barrio[i].conductividad, &barrio[i].turbidez, &barrio[i].coliformes) != EOF){
                              if (barrio[i].pH >=6 && barrio[i].pH<=6.5)
                                printf("%s %f %d %d %d\n", barrio[i].fuente, barrio[i].pH  barrio[i].conductividad,  barrio[i].turbidez,  barrio[i].coliformes);}
                        }else if(ph<=7){
                            printf("Las fuentes con un ph mas cercanas a %f que se encuentran entre 6.5 y 7 son:\n", ph);
                           while (fscanf(ficherodado, "%s %f %d %d %d", barrio[i].fuente, &barrio[i].pH,&barrio[i].conductividad, &barrio[i].turbidez, &barrio[i].coliformes) != EOF){
                                    if (barrio[i].pH >=6.5 && barrio[i].pH<=7)
                                printf("%s %f %d %d %d\n", barrio[i].fuente, barrio[i].pH  barrio[i].conductividad,  barrio[i].turbidez,  barrio[i].coliformes);}

                        }else if(ph<=7.5){
                            printf("Las fuentes con un ph mas cercanas a %f que se encuentran entre 7 y 7.5 son:\n", ph);
                           while (fscanf(ficherodado, "%s %f %d %d %d", barrio[i].fuente, &barrio[i].pH,&barrio[i].conductividad, &barrio[i].turbidez, &barrio[i].coliformes) != EOF){
                              if (barrio[i].pH >=7 && barrio[i].pH<=7.5)
                                printf("%s %f %d %d %d\n", barrio[i].fuente, barrio[i].pH  barrio[i].conductividad,  barrio[i].turbidez,  barrio[i].coliformes);}

                        } else if(ph<=8){
                            printf("Las fuentes con un ph mas cercanas a %f que se encuentran entre 7.5 y 8 son:\n", ph);
                           while (fscanf(ficherodado, "%s %f %d %d %d", barrio[i].fuente, &barrio[i].pH, &barrio[i].conductividad,&barrio[i].turbidez, &barrio[i].coliformes) != EOF){
                              if (barrio[i].pH >=7.5 && barrio[i].pH<=8)
                                printf("%s %f %d %d %d\n", barrio[i].fuente, barrio[i].pH  barrio[i].conductividad,  barrio[i].turbidez,  barrio[i].coliformes);}
                                }

void buscarcond(struct Tfuente barrio[],int conductividad){
	int i=0;
                        FILE *ficherodado;
                        ficherodado = fopen("202301_Lavapies.txt", "r"); // Modo: "r" "w" (hay otros modos)

                        if (ficherodado == NULL) {
                        printf("Error, no puede abrir el fichero.\n");
                        }
                        if(conductividad>=100 && conductividad<=150){
                            printf("Las conductividades mas cercanas de %d que se encuentran entre 100 y 150 son:\n", conductividad);
							while (fscanf(ficherodado, "%s %f %d %d %d", barrio[i].fuente, &barrio[i].pH,&barrio[i].conductividad, &barrio[i].turbidez, &barrio[i].coliformes) != EOF){                           
							if (barrio[i].conductividad >=100 && barrio[i].conductividad<=150)
							 printf("%s %f %d %d %d\n", barrio[i].fuente, barrio[i].pH  barrio[i].conductividad,  barrio[i].turbidez,  barrio[i].coliformes);}
                        }else if(conductividad>150 && conductividad<=200){
                            printf("Las conductividades mas cercanas de %d que se encuentran entre 150 y 200 son\n", conductividad);
							while (fscanf(ficherodado, "%s %f %d %d %d", barrio[i].fuente, &barrio[i].pH,&barrio[i].conductividad, &barrio[i].turbidez, &barrio[i].coliformes) != EOF){ 
							 if (barrio[i].conductividad >=150 && barrio[i].conductividad<=200)
							 printf("%s %f %d %d %d\n", barrio[i].fuente, barrio[i].pH  barrio[i].conductividad,  barrio[i].turbidez,  barrio[i].coliformes);}

                        } else if(conductividad>200 && conductividad<=250){
                            printf("Las conductividades mas cercanas de %d que se encuentran entre 200 y 250 son\n", conductividad);
							while (fscanf(ficherodado, "%s %f %d %d %d", barrio[i].fuente, &barrio[i].pH,&barrio[i].conductividad, &barrio[i].turbidez, &barrio[i].coliformes) != EOF){                             
                              if (barrio[i].conductividad >=200 && barrio[i].conductividad<=250)
							 printf("%s %f %d %d %d\n", barrio[i].fuente, barrio[i].pH  barrio[i].conductividad,  barrio[i].turbidez,  barrio[i].coliformes);}

                        else if(conductividad>250 && conductividad<=300){
                            printf("Las conductividades mas cercanas de %d que se encuentran entre 250 y 300 son\n", conductividad);
							while (fscanf(ficherodado, "%s %f %d %d %d", barrio[i].fuente, &barrio[i].pH,&barrio[i].conductividad, &barrio[i].turbidez, &barrio[i].coliformes) != EOF){                              
                              if (barrio[i].conductividad >=250 && barrio[i].conductividad<=300)
							 printf("%s %f %d %d %d\n", barrio[i].fuente, barrio[i].pH  barrio[i].conductividad,  barrio[i].turbidez,  barrio[i].coliformes);}


}

void buscarturb (struct Tfuente barrio[],int turbidez){
                        int i=0;
                        FILE *ficherodado;
                        ficherodado = fopen("202301_Lavapies.txt", "r"); // Modo: "r" "w" (hay otros modos)

                        if (ficherodado == NULL) {
                        printf("Error, no puede abrir el fichero.\n");
                        }
                        if(turbidez == 0){
                            printf("Las turbidadez mas cercanas de %d que se encuentran en 0:\n", turbidez);
							while (fscanf(ficherodado, "%s %f %d %d %d", barrio[i].fuente, &barrio[i].pH,&barrio[i].conductividad, &barrio[i].turbidez, &barrio[i].coliformes) != EOF){                             
                              if (barrio[i].turbidez== 0)
							 printf("%s %f %d %d %d\n", barrio[i].fuente, barrio[i].pH  barrio[i].conductividad,  barrio[i].turbidez,  barrio[i].coliformes);}

                        }else if(turbidez == 1){
                            printf("Las turbidadez mas cercanas de %d que se encuentran en 1\n", turbidez);
							while (fscanf(ficherodado, "%s %f %d %d %d", barrio[i].fuente, &barrio[i].pH,&barrio[i].conductividad, &barrio[i].turbidez, &barrio[i].coliformes) != EOF){                              
							if (barrio[i].conductividad >=100 && barrio[i].conductividad<=150)
                              if (barrio[i].conductividad == 1)
							 printf("%s %f %d %d %d\n", barrio[i].fuente, barrio[i].pH  barrio[i].conductividad,  barrio[i].turbidez,  barrio[i].coliformes);}

                        } else if(turbidez == 2){
                            printf("Las turbidadez mas cercanas de %d que se encuentran en 2\n", turbidez);
							while (fscanf(ficherodado, "%s %f %d %d %d", barrio[i].fuente, &barrio[i].pH,&barrio[i].conductividad, &barrio[i].turbidez, &barrio[i].coliformes) != EOF){                              
							if (barrio[i].conductividad >=100 && barrio[i].conductividad<=150)
                              if (barrio[i].conductividad == 2)
							 printf("%s %f %d %d %d\n", barrio[i].fuente, barrio[i].pH  barrio[i].conductividad,  barrio[i].turbidez,  barrio[i].coliformes);}

                        else if(turbidez == 3){
                            printf("Las turbidadez mas cercanas de %d que se encuentran en 3\n", turbidez);
							while (fscanf(ficherodado, "%s %f %d %d %d", barrio[i].fuente, &barrio[i].pH,&barrio[i].conductividad, &barrio[i].turbidez, &barrio[i].coliformes) != EOF){                             
							if (barrio[i].conductividad >=100 && barrio[i].conductividad<=150)
                              if (barrio[i].conductividad == 3)
							 printf("%s %f %d %d %d\n", barrio[i].fuente, barrio[i].pH  barrio[i].conductividad,  barrio[i].turbidez,  barrio[i].coliformes);}

                        else if(turbidez == 4){
                            printf("Las turbidez mas cercanas de %d que se encuentran en 4\n", turbidez);
							while (fscanf(ficherodado, "%s %f %d %d %d", barrio[i].fuente, &barrio[i].pH,&barrio[i].conductividad, &barrio[i].turbidez, &barrio[i].coliformes) != EOF){                              
							if (barrio[i].conductividad >=100 && barrio[i].conductividad<=150)
                              if (barrio[i].conductividad == 4)
							 printf("%s %f %d %d %d\n", barrio[i].fuente, barrio[i].pH  barrio[i].conductividad,  barrio[i].turbidez,  barrio[i].coliformes);}

                            else if(turbidez == 5){
                            printf("Las turbidez mas cercanas de %d que se encuentran en 5\n", turbidez);
							while (fscanf(ficherodado, "%s %f %d %d %d", barrio[i].fuente, &barrio[i].pH,&barrio[i].conductividad, &barrio[i].turbidez, &barrio[i].coliformes) != EOF){                              
							if (barrio[i].conductividad >=100 && barrio[i].conductividad<=150)
                              if (barrio[i].conductividad == 5)
							 printf("%s %f %d %d %d\n", barrio[i].fuente, barrio[i].pH  barrio[i].conductividad,  barrio[i].turbidez,  barrio[i].coliformes);}

                            else if(turbidez == 10){
                            printf("Las turbidadez mas cercanas de %d que se encuentran en 10\n", turbidez);
							while (fscanf(ficherodado, "%s %f %d %d %d", barrio[i].fuente, &barrio[i].pH,&barrio[i].conductividad, &barrio[i].turbidez, &barrio[i].coliformes) != EOF){                             
							 if (barrio[i].conductividad >=100 && barrio[i].conductividad<=150)
                              if (barrio[i].conductividad == 10)
							 printf("%s %f %d %d %d\n", barrio[i].fuente, barrio[i].pH  barrio[i].conductividad,  barrio[i].turbidez,  barrio[i].coliformes);}

                            else {
                                printf("No existen fuentes con esa conductividad\n");
                            }



}


void buscarcoliforme(struct Tfuente barrio[], int coliformes){
                        int i=0;
                        FILE *ficherodado;
                        ficherodado = fopen("202301_Lavapies.txt", "r"); // Modo: "r" "w" (hay otros modos)

                        if (ficherodado == NULL) {
                        printf("Error, no puede abrir el fichero.\n");
                        }
                        if(coliformes == 0){
                            printf("Las fuentes con una cantidad de %d de colonias coliformes \n", coliformes);
							while (fscanf(ficherodado, "%s %f %d %d %d", barrio[i].fuente, &barrio[i].pH,&barrio[i].conductividad, &barrio[i].turbidez, &barrio[i].coliformes) != EOF){                              
                              if (barrio[i].coliformes == 0)
							 printf("%s %f %d %d %d\n", barrio[i].fuente, barrio[i].pH  barrio[i].conductividad,  barrio[i].turbidez,  barrio[i].coliformes);}
                        }else if(coliformes == 1){
                            printf("Las fuentes con una cantidad de %d de colonias coliformes \n", coliformes);
							while (fscanf(ficherodado, "%s %f %d %d %d", barrio[i].fuente, &barrio[i].pH,&barrio[i].conductividad, &barrio[i].turbidez, &barrio[i].coliformes) != EOF){                              
                                    if (barrio[i].coliformes == 1)
							 printf("%s %f %d %d %d\n", barrio[i].fuente, barrio[i].pH  barrio[i].conductividad,  barrio[i].turbidez,  barrio[i].coliformes);}
                        }else if(coliformes == 2){
                            printf("Las fuentes con una cantidad de %d de colonias coliformes \n", coliformes);
							while (fscanf(ficherodado, "%s %f %d %d %d", barrio[i].fuente, &barrio[i].pH,&barrio[i].conductividad, &barrio[i].turbidez, &barrio[i].coliformes) != EOF){                             
                                    if (barrio[i].coliformes == 2)
							 printf("%s %f %d %d %d\n", barrio[i].fuente, barrio[i].pH  barrio[i].conductividad,  barrio[i].turbidez,  barrio[i].coliformes);}
                        }else printf("No hay esa cantidad de colonias coliformes \n");
}
float mediac (struct Tfuente barrio[], int dim) {
	int i=0;
	float media=0;

	FILE *fichero;
	fichero = fopen("202301_Lavapies.txt", "r");

	if (fichero == NULL) {
		printf("Error, no puede abrir el fichero.\n");

	}

		while (fscanf(ficherodado, "%s %f %d %d %d", barrio[i].fuente, &barrio[i].pH,&barrio[i].conductividad, &barrio[i].turbidez, &barrio[i].coliformes) != EOF){                             
		 

			media += barrio[i].conductividad;
	}

	return (media);
}
float mediaspH (struct Tfuente barrio[], int dim) {
	int i=0;
	float media=0;

	FILE *fichero;
	fichero = fopen("202301_Lavapies.txt", "r");

	if (fichero == NULL) {
		printf("Error, no puede abrir el fichero.\n");

	}

		while (fscanf(ficherodado, "%s %f %d %d %d", barrio[i].fuente, &barrio[i].pH,&barrio[i].conductividad, &barrio[i].turbidez, &barrio[i].coliformes) != EOF){                             
		 
		media += barrio[i].pH;
	}

	return (media);
}
float mediasturbidez(struct Tfuente barrio[], int dim) {
	int i=0;
	float media=0;

	FILE *fichero;
	fichero = fopen("202301_Lavapies.txt", "r");

	if (fichero == NULL) {
		printf("Error, no puede abrir el fichero.\n");

	}

	while (fscanf(ficherodado, "%s %f %d %d %d", barrio[i].fuente, &barrio[i].pH,&barrio[i].conductividad, &barrio[i].turbidez, &barrio[i].coliformes) != EOF){                          
		media += barrio[i].turbidez;
	}

	return (media);
}
float mediascoliformes(struct Tfuente barrio[], int dim) {
	int i=0;
	float media=0;

	FILE *fichero;
	fichero = fopen("202301_Lavapies.txt", "r");

	if (fichero == NULL) {
		printf("Error, no puede abrir el fichero.\n");

	}

		while (fscanf(ficherodado, "%s %f %d %d %d", barrio[i].fuente, &barrio[i].pH,&barrio[i].conductividad, &barrio[i].turbidez, &barrio[i].coliformes) != EOF){                          

		media += barrio[i].coliformes;
	}

	return (media);
}
