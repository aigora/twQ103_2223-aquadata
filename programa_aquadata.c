// TRABAJO INFORMÁTICA
#include <stdio.h>
struct Tfuente{
	char fuente[10];
	float pH;
	int conductividad;
	int turbidez;
	int coliformes;
};


int main () {
	struct Tfuente lavapies[500];
	int nfuentes;
	int i;
	int opcion;
	char opciondato;
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
			printf("A. Buscar datos por fuente\n");
			printf("B. Buscar datos por parámetros\n");
			printf("E. Estadisticas\n");
			fflush(stdin);
			scanf ("%c", &opciondato);
		}
	

			while (opciondato != 'A' && opciondato != 'B' && opciondato != 'E');

            case 'A':
            case 'a':
            	//printf("Que fuente quieres buscar");
            	while (fscanf(ficherodado, "%s %f %d %d %d", lavapies[i].fuente, &lavapies[i].pH, &lavapies[i].conductividad, &lavapies[i].turbidez, &lavapies[i].coliformes) != EOF){
		printf("%s %f %d %d %d\n", lavapies[i].fuente, lavapies[i].pH, lavapies[i].conductividad, lavapies[i].turbidez, lavapies[i].coliformes);}
            	/*for (i=0; i<nfuentes; i++) {
	    	    if (clase[i].nmatricula == 50007) {
		     	clase[i].nota += 1;*/

                break;

            case 'B':
            case 'b':

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
