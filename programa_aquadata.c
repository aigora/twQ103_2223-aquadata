// TRABAJO INFORMÁTICA
#include <stdio.h>


int main () {
	int opcion;

	do{
	
	printf("Introduce la opcion que desee\n");
	printf("1: si quiere Buscar Datos de la fuente\n");
	printf("2: si quiere anadir datos de parametro u otra fuente\n");
	printf("3: si quiere Información\n");
	printf("4:para salir del programa\n");
	fflush(stdin);
	
	scanf("%d", &opcion);
	
	
	switch(opcion){
		case 1:{
			printf("bien 1");
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



}while(opcion>4 || opcion<1);
	if(opcion==4){
		return 0;
}
}
