// TRABAJO INFORMÁTICA
#include <stdio.h>
struct Tfuente{
	char fuente[10];
	float pH;
	int conductividad;
	int turbidez;
	int coliformes;
};///VVVV
void buscarparametro(struct Tfuente lavapies[], int , float);

int main () {
	struct Tfuente lavapies[500];
	int nfuentes;
	char parametro;
	int i,j;
	int opcion;
	char opciondato;
	float pH;
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
		case 1:{
		    do{
			printf("¿Que datos desea buscar?\n");
			printf("B. Buscar datos \n");
			printf("E. Estadisticas\n");
			fflush(stdin);
			scanf ("%c", &opciondato);
		}
	

			while ( opciondato != 'B' && opciondato != 'E');

            	//while (fscanf(ficherodado, "%s %f %d %d %d", lavapies[i].fuente, &lavapies[i].pH, &lavapies[i].conductividad, &lavapies[i].turbidez, &lavapies[i].coliformes) != EOF){
				//printf("%s %f %d %d %d\n", lavapies[i].fuente, lavapies[i].pH, lavapies[i].conductividad, lavapies[i].turbidez, lavapies[i].coliformes);}

            case 'B':
            case 'b':
            	do{
				
            	printf("¿Que parametro quieres buscar?\n");
            	printf("Pulse P. pH\n");
            	printf("Pulse C. conductividad\n");
            	printf("Pulse T. turbidez\n ");
            	printf("Pulse F. coliformes\n");
            	fflush(stdin);
            	scanf("%c", &parametro);
            	switch(parametro){
            		case 'P':
            			printf("Introduce el pH del agua buscado que se encuentra entre 6 y 8\n");
            			scanf("%f", &pH);
            			buscarparametro(lavapies, 25, pH);		
				}
			}while(parametro!='P' || parametro!='C' || parametro!='T' ||parametro!='F');

                break;

            case 'E':
            case 'e':

                break;

			break;
		}


		case 2:{
			printf("bien 2");
			break;
		}
		case 3: {
			printf("bien 3");
			break;
		}
}
    fclose(ficherodado);

}   while(opcion>4 || opcion<1);
	if(opcion == 4){
		return 0;
}
}
void buscarparametro(struct Tfuente lavapies[], int dim , float ph ){
	int i;
		
 		if(ph>=6 && ph<=6.5){
 			for(i=0; i<dim;i++)
 			if(lavapies[i].pH>=6 && lavapies[i].pH<=6.5){
 				printf("%s %f %d %d %d\n", lavapies[i].fuente, lavapies[i].pH, lavapies[i].conductividad, lavapies[i].turbidez, lavapies[i].coliformes);
	 }}
	 	else if(ph<=7){
	 		//for(j=0; j<dim;j++)
	 		
	 		//printf("%s %f %d %d %d\n", lavapies[i].fuente, lavapies[i].pH, lavapies[i].conductividad, lavapies[i].turbidez, lavapies[i].coliformes);
	 }
		else if(ph<=7.5){
			//for(j=0; j<dim;j++)
			//printf("%s %f %d %d %d\n", lavapies[i].fuente, lavapies[i].pH, lavapies[i].conductividad, lavapies[i].turbidez, lavapies[i].coliformes);
		
	}
		else if(ph<=8){
			//for(j=0; j<dim;j++)
		//printf("%s %f %d %d %d\n", lavapies[i].fuente, lavapies[i].pH, lavapies[i].conductividad, lavapies[i].turbidez, lavapies[i].coliformes);
		
	}
	 }
	 
