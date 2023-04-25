// TRABAJO INFORMÁTICA
#include <stdio.h>


int main () {
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
			printf("E. Estadísticas\n");
			scanf ("%c", &opciondato);

			}while (opciondato != 'A' && opciondato != 'B' && opciondato != 'E');

            case 'A':
            case 'a':

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
