// TRABAJO INFORMÁTICA
#include <stdio.h>

struct Tfuente{
	char fuente[10];
	float pH;
	int conductividad;
	int turbidez;
	int coliformes;
};

void buscarparametro(struct Tfuente lavapies[], float ph);

int main () {
	struct Tfuente lavapies[500];
	int nfuentes;
	char parametro;
	int i,j;
	int opcion;
	char opciondato;
	float ph1;
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
	fflush(stdin);
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
            	printf("Pulse T. turbidez\n ");
            	printf("Pulse F. coliformes\n");
            	fflush(stdin);
            	scanf("%c", &parametro);
            	if (parametro == 'P'){
            			printf("Introduce el pH del agua buscado que se encuentra entre 6 y 8\n");
                        fflush(stdin);
            			scanf("%f", &ph1);
                        buscarparametroph(lavapies, ph1);
	 //}while(parametro!='P' || parametro!='C' || parametro!='T' ||parametro!='F')
	 }
            break; // BREAK CASE B

		}

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
void buscarparametroph(struct Tfuente lavapies[], float ph){
                        int i=0;
                        FILE *ficherodado;
                        ficherodado = fopen("202301_Lavapies.txt", "r"); // Modo: "r" "w" (hay otros modos)

                        if (ficherodado == NULL) {
                        printf("Error, no puede abrir el fichero.\n");
                        return 0;
                        }
                        if(ph>=6 && ph<=6.5){
                            printf("Las fuentes que se encuentran entre 6 y 6.5 son:\n");
                           while (fscanf(ficherodado, "%s %f %d %d %d", lavapies[i].fuente, &lavapies[i].pH, &lavapies[i].conductividad, &lavapies[i].turbidez, &lavapies[i].coliformes) != EOF){
                              if (lavapies[i].pH >=6 && lavapies[i].pH<=6.5)
                                printf("%s %f %d %d %d\n", lavapies[i].fuente, lavapies[i].pH, lavapies[i].conductividad, lavapies[i].turbidez, lavapies[i].coliformes);}
                        }else if(ph<=7){
                            printf("Las fuentes que se encuentran entre 6.5 y 7 son:\n");
                           while (fscanf(ficherodado, "%s %f %d %d %d", lavapies[i].fuente, &lavapies[i].pH, &lavapies[i].conductividad, &lavapies[i].turbidez, &lavapies[i].coliformes) != EOF){
                                    if (lavapies[i].pH >=6.5 && lavapies[i].pH<=7)
                                        printf("%s %f %d %d %d\n", lavapies[i].fuente, lavapies[i].pH, lavapies[i].conductividad, lavapies[i].turbidez, lavapies[i].coliformes);}

                        }else if(ph<=7.5){
                            printf("Las fuentes que se encuentran entre 7 y 7.5 son:\n");
                           while (fscanf(ficherodado, "%s %f %d %d %d", lavapies[i].fuente, &lavapies[i].pH, &lavapies[i].conductividad, &lavapies[i].turbidez, &lavapies[i].coliformes) != EOF){
                              if (lavapies[i].pH >=7 && lavapies[i].pH<=7.5)
                                printf("%s %f %d %d %d\n", lavapies[i].fuente, lavapies[i].pH, lavapies[i].conductividad, lavapies[i].turbidez, lavapies[i].coliformes);}

                        } else if(ph<=8){
                            printf("Las fuentes que se encuentran entre 7.5 y 8 son:\n");
                           while (fscanf(ficherodado, "%s %f %d %d %d", lavapies[i].fuente, &lavapies[i].pH, &lavapies[i].conductividad, &lavapies[i].turbidez, &lavapies[i].coliformes) != EOF){
                              if (lavapies[i].pH >=7.5 && lavapies[i].pH<=8)
                                printf("%s %f %d %d %d\n", lavapies[i].fuente, lavapies[i].pH, lavapies[i].conductividad, lavapies[i].turbidez, lavapies[i].coliformes);}}
                                }

void buscarparametrocondutividad

