//prueba
// TRABAJO INFORMÁTICA
#include <stdio.h>
#include <string.h>
struct Tfuente{
	char fuente[10];
	float pH;
	int conductividad;
	int turbidez;
	int coliformes;
    int puntos1;
	int puntos2;
	int puntos3;
	int ptotal;
};

struct TJugador {
    char nombre[50];
    char contrasenya[50];
};

void banner () {
//printf("                  AAA                 QQQQQQQQQ     UUUUUUUU     UUUUUUUU           AAA               DDDDDDDDDDDDD                  AAA         TTTTTTTTTTTTTTTTTTTTTTT         AAA               \n");
//printf("                 A:::A              QQ:::::::::QQ   U::::::U     U::::::U          A:::A              D::::::::::::DDD              A:::A        T:::::::::::::::::::::T        A:::A              \n");
//printf("                A:::::A           QQ:::::::::::::QQ U::::::U     U::::::U         A:::::A             D:::::::::::::::DD           A:::::A       T:::::::::::::::::::::T       A:::::A             \n");
//printf("               A:::::::A         Q:::::::QQQ:::::::Q U:::::U     U:::::UU        A:::::::A            DDD:::::DDDDD:::::D         A:::::::A      T:::::TT:::::::TT:::::T      A:::::::A            \n");
printf("              A:::::::::A        Q::::::O   Q::::::Q U:::::U     U:::::U        A:::::::::A             D:::::D    D:::::D       A:::::::::A     TTTTTT  T:::::T  TTTTTT     A:::::::::A           \n");
printf("             A:::::A:::::A       Q:::::O     Q:::::Q U:::::D     D:::::U       A:::::A:::::A            D:::::D     D:::::D     A:::::A:::::A            T:::::T            A:::::A:::::A          \n");
printf("            A:::::A A:::::A      Q:::::O     Q:::::Q U:::::D     D:::::U      A:::::A A:::::A           D:::::D     D:::::D    A:::::A A:::::A           T:::::T           A:::::A A:::::A         \n");
printf("           A:::::A   A:::::A     Q:::::O     Q:::::Q U:::::D     D:::::U     A:::::A   A:::::A          D:::::D     D:::::D   A:::::A   A:::::A          T:::::T          A:::::A   A:::::A        \n");
printf("          A::::::A     A::::A    Q:::::O     Q:::::Q U:::::D     D:::::U    A:::::A     A:::::A         D:::::D     D:::::D  A:::::A     A:::::A         T:::::T         A:::::A     A:::::A       \n");
printf("         A:::::AAAAAAAAA:::::A   Q:::::O     Q:::::Q U:::::D     D:::::U   A:::::AAAAAAAAA:::::A        D:::::D     D:::::D A:::::AAAAAAAAA:::::A        T:::::T        A:::::AAAAAAAAA:::::A      \n");
printf("        A:::::::::::::::::::::A  Q:::::O  QQQQ:::::Q U:::::D     D:::::U  A:::::::::::::::::::::A       D:::::D     D:::::DA:::::::::::::::::::::A       T:::::T       A:::::::::::::::::::::A     \n");
printf("       A:::::AAAAAAAAAAAAA:::::A Q::::::O Q::::::::Q U::::::U   U::::::U A:::::AAAAAAAAAAAAA:::::A      D:::::D    D:::::DA:::::AAAAAAAAAAAAA:::::A      T:::::T      A:::::AAAAAAAAAAAAA:::::A    \n");
printf("      A:::::A             A:::::AQ:::::::QQ::::::::Q U:::::::UUU:::::::UA:::::A             A:::::A   DDD:::::DDDDD:::::DA:::::A             A:::::A   TT:::::::TT   A:::::A             A:::::A   \n");
printf("     A:::::A               A:::::AQQ::::::::::::::Q   UU:::::::::::::UUA:::::A               A:::::A  D:::::::::::::::DDA:::::A               A:::::A  T:::::::::T  A:::::A               A:::::A  \n");
printf("    A:::::A                 A:::::A QQ:::::::::::Q      UU:::::::::UU A:::::A                 A:::::A D::::::::::::DDD A:::::A                 A:::::A T:::::::::T A:::::A                 A:::::A \n");
printf("   AAAAAAA                   AAAAAAA  QQQQQQQQ::::QQ      UUUUUUUUU  AAAAAAA                   AAAAAAADDDDDDDDDDDDD   AAAAAAA                   AAAAAAATTTTTTTTTTTAAAAAAA                   AAAAAAA\n");
printf("                                           Q:::::Q                                                                                                                                                 \n");
printf("                                            QQQQQQ                                                                                                                                                 \n");
    return;
}


void buscarph(struct Tfuente barrio[], float, int);
void buscarcond(struct Tfuente barrio[],int, int);
void buscarturb (struct Tfuente barrio[],int, int);
void buscarcoliforme (struct Tfuente barrio[],int, int);
float mediac(struct Tfuente barrio[],int);
float mediaspH(struct Tfuente barrio[], int);
float mediasturbidez(struct Tfuente barrio[],int);
float mediascoliformes(struct Tfuente barrio[],int);

int main () {
	int TAM_FUENTE;
	struct Tfuente barrio[500];
	struct Tfuente mejorfuente;
	struct Tfuente peorfuente;
	int nfuentes;
	char parametro;
	char max[25];
	int i,j;
	int fnuevas;
	float ph1;
	int conductividad, turbidez, coliformes;
	FILE *fentrada;
	FILE *fsalida;
	int puntos=0;
	int nespecies;
	int fuentes;
	char nconductividad[20], nturbidez[20], ncoliformes[20], npH[20], nparametro[20];
	fentrada = fopen("202301_Lavapies.txt", "r");
	if (fentrada == NULL) {
		printf("Error, no puede abrir el fichero.\n");
		return 0;
	}
	fscanf(fentrada, "%s %s %s %s %s",  nparametro, npH, nconductividad, nturbidez, ncoliformes);
	i=0;
	fuentes=0;
	 while(fscanf(fentrada, "%s %f %d %d %d", barrio[i].fuente, &barrio[i].pH, &barrio[i].conductividad, &barrio[i].turbidez, &barrio[i].coliformes)!= EOF){
	 	i++;
		fuentes=i;	
	}

	fclose(fentrada);
	TAM_FUENTE=fuentes;
	printf("%d", TAM_FUENTE);

	//Inicializadores que se utilizan para el inicio de sesion
		int opcionprofesor, opcionalumno;
		FILE * pDatosUsuarios;
		struct TJugador usuario[200];
		int resultado1, resultado2;
		int posicion, resultado3;
		int EsProfesor=0;
		int Contrasenyacorrecta=0;
		int usuarios;
		char opciondato, nombre[100], contrasenya[100];

            pDatosUsuarios = fopen("profesores.txt","r");
        if (pDatosUsuarios == NULL){
            printf ("Error en la apertura de fichero\n");
            return 0;
        }
    i=0;
    while (fscanf(pDatosUsuarios, "%s %s", usuario[i].nombre, usuario[i].contrasenya)!=EOF){
        i++;
        usuarios=i;
    }
    fclose(pDatosUsuarios);


    printf("                   Iniciar Sesi%cn\n                   Usuario:", 162);
    scanf("%s", nombre);
    //fflush(stdin);
    printf("                   Contrase%ca:", 164);
    scanf("%s", contrasenya);


    for(i=0;i<usuarios;i++){
        resultado1=strcmp(nombre,usuario[i].nombre);
        if(resultado1==0){
            EsProfesor =1;
            posicion = i;
        }
    }
    if(EsProfesor==1){
        resultado2=strcmp(contrasenya,usuario[posicion].contrasenya);
        if(resultado2==0){
            Contrasenyacorrecta = 1;
            }
	}
    if(Contrasenyacorrecta == 0 &&   EsProfesor ==1 ){ //contrasenacorrecta = 0 FALSO
        do {
        printf("Contrasena incorrecta vuelve a intentarlo\n");
        printf("                   Contrase%ca:", 164);
        scanf("%s", contrasenya);
        
        resultado3=strcmp(contrasenya,usuario[posicion].contrasenya);
        if(resultado3==1){
            Contrasenyacorrecta = 1;
        }
        }   while (Contrasenyacorrecta == 1 &&   EsProfesor ==1);
	}
     if (EsProfesor == 0){
        printf("No existe esa cuenta con esa contrasenya, entras como alumno\n");
        printf("Con este modo de entrada solo tienes dos opciones a elegir\n");
        do{
        printf("Introduce la opcion que desee\n");
		printf("1: Informacion\n");
		printf("2: Salir del programa\n");
		scanf("%d", &opcionalumno);
		switch(opcionalumno){
			case 1:
				printf("¡Hola usuario!");
				printf("En este apartado podras conocer informacion sobre el peligro de la preesencia de las fuentes y sus consecuencias\n");
				printf("Para empezar, Los coliformes son un grupo de bacterias utilizadas como indicadores de contaminación fecal en el agua.\n");
				printf("En una fuente local, se pueden encontrar diferentes tipos de coliformes, pero los mas comunes son Escherichia coli y Enterococcus faecalis.\n");
				printf("Estos microorganismos pueden ser peligrosos para la salud si se consumen en grandes cantidades, ya que pueden causar enfermedades como gastroenteritis, diarrea y fiebre tifoidea.\n");
				printf("Por lo tanto, es importante que el agua de la fuente local se analice regularmente para detectar la presencia de estos y otros contaminantes y tomar medidas adecuadas para garantizar su seguridad.\n");
				printf("\n");
				printf("Ahora que conoces un poco mas sobre estas especies, te gustaria saber un poco mas sobre las especies especificas de cada fuente?\n ");
				printf("¿De que fuentes quieres advertirte, sobre las fuentes que tienen 0 , 1 o 2 colonias?\n");
				scanf("%d", &nespecies);
				if(nespecies == 0){
            		printf("Las fuentes que tienen %d especies son:\n", nespecies);
            		for(i=0;i<TAM_FUENTE;i++){
            			if (barrio[i].coliformes == 0)
            				printf("%s %f %d %d %d\n", barrio[i].fuente, barrio[i].pH, barrio[i].conductividad, barrio[i].turbidez, barrio[i].coliformes);}
            		printf("No hay ninguna especie coliforme en estas fuentes.\n");
            		printf("Por lo tanto, los beneficios de no tener coliformes en las fuentes son múltiples, como una reducción en el riesgo de enfermedades transmitidas por el agua,\n");
					printf("una mejora en la calidad del agua para uso recreativo y agrícola, y una mayor confianza en la seguridad del suministro de agua potable.\n");
					printf("Además, la eliminación de los coliformes puede reducir los costos asociados con el tratamiento y la purificación del agua.\n");}
            	else if(nespecies == 1){
					for(i=0;i<TAM_FUENTE;i++){
            			if (barrio[i].coliformes == 1)
            				printf("%s %f %d %d %d\n", barrio[i].fuente, barrio[i].pH, barrio[i].conductividad, barrio[i].turbidez, barrio[i].coliformes);}
           			 printf("En estas fuentes se encuentra una sola especie, la Escherichia coli, una bacteria que se localiza comúnmente en el tracto intestinal de los seres humanos y animales.\n");
					printf("Si esta bacteria se encuentra en grandes cantidades en una fuente, puede indicar la presencia de contaminación fecal y, por lo tanto, de otros patógenos peligrosos para la salud.\n");
					printf("\n");
					printf("La exposición a la Escherichia coli puede provocar enfermedades como gastroenteritis, diarrea, fiebre y en casos extremos, insuficiencia renal y anemia hemolítica.\n");
					printf("Es importante tomar medidas adecuadas para garantizar la seguridad del agua de la fuente y evitar la exposición a estos riesgos potenciales para la salud.\n");}
           		 else if(nespecies == 2){
            		for(i=1;i<TAM_FUENTE;i++){
            			if (barrio[i].coliformes == 2)
            				printf("%s %f %d %d %d\n", barrio[i].fuente, barrio[i].pH, barrio[i].conductividad, barrio[i].turbidez, barrio[i].coliformes);}
            		printf("En estas fuentes, se observan 2 diferentes colonias\n");
            		printf("Encontrar la  Escherichia Coli y la  Enterococcus faecalis puede ser muy nocivo para la salud, ya que se combinan las causas perjudiciales de ambos patógenos.\n");
					printf("Beber agua con altos niveles de Enterococcus faecalis puede causar enfermedades gastrointestinales, infecciones del tracto urinario, sepsis y endocarditis.\n");
					printf("Algunas cepas de Enterococcus faecalis pueden ser resistentes a los antibióticos, lo que hace que las infecciones sean difíciles de tratar.\n");
					printf("Además, la exposición a la Escherichia coli puede provocar enfermedades como gastroenteritis, diarrea, fiebre, insuficiencia renal y anemia hemolítica.\n");
					printf("Es importante tomar medidas adecuadas para garantizar la seguridad del agua potable en estas fuentes y evitar la exposición a estos riesgos potenciales para la salud.\n");}

            		else{

						 printf("No hay esa cantidad de colonias coliformes \n");}
			break;
			
		}
        } while (opcionalumno> 2|| opcionalumno < 1);
		if(opcionalumno == 4){
		return 0;} 
	 
        
    }else{ //if(Contrasenyacorrecta == 1 && EsProfesor == 1){
    	printf("Contrasena correcta entras como profesor\n");
    	do{
		printf("Introduce la opcion que desee\n");
		printf("1: Buscar Datos de la fuente\n");
		printf("2: Anadir otra fuente\n");
		printf("3: Informacion\n");
		printf("4: Salir del programa\n");
		scanf("%d", &opcionprofesor);


	switch(opcionprofesor){
		case 1:
		    do{
			printf("¿Que datos desea buscar?\n");
			printf("B. Buscar datos \n");
			printf("E. Estadisticas\n");
			fflush(stdin);
			scanf ("%c", &opciondato);
			switch(opciondato){

	//	}while ( opciondato != 'B' && opciondato != 'E');


            case 'B':
            case 'b':
            	do{

            	printf("¿Que parametro quieres buscar?\n");
            	printf("Pulse P. pH\n");
            	printf("Pulse C. conductividad\n");
            	printf("Pulse T. turbidez\n");
            	printf("Pulse F. coliformes\n");
            	fflush(stdin);
            	scanf("%c", &parametro);
            	if (parametro == 'P'){
            			printf("Introduce el pH del agua buscado que se encuentra entre 6 y 8\n");
            			fflush(stdin);
            			scanf("%f", &ph1);
                        buscarph(barrio, ph1, TAM_FUENTE);}

	 			else if(parametro=='C'){
	 				printf("Introduce la conductIvidad del agua buscada que se encuentra entre 100 y 300\n");
	 					fflush(stdin);
            			scanf("%d", &conductividad);
                        buscarcond(barrio, conductividad, TAM_FUENTE);}

                else if(parametro=='T'){
	 				printf("Introduce la turbidez del agua buscada que se encuentra entre 0 y 10\n");
	 					fflush(stdin);
            			scanf("%d", &turbidez);
                        buscarturb(barrio, turbidez, TAM_FUENTE);}

                else if(parametro=='F'){
	 				printf("Introduce la turbidez del agua buscada que se encuentra entre 0 y 2\n");
	 					fflush(stdin);
            			scanf("%d", &coliformes);
                        buscarcoliforme(barrio, coliformes, TAM_FUENTE);}
break;
}while(parametro!='P' || parametro!='C' || parametro!='T' ||parametro!='F');

          break;
            case 'e':
            case 'E':
            	printf("En las estadisticas de las fuentes apreciaremos las medias de cada parametro de la fuente y un ranking de la mejor y la peor fuente\n");
            	for(i=1;i<TAM_FUENTE;i++){
                    if(barrio[i].pH >= 6.8 && barrio[i].pH <= 7.2){
                       barrio[i].puntos1=3;
                    } else if(barrio[i].pH > 7.2 && barrio[i].pH <= 8){
                        barrio[i].puntos1 = 2;
                    }else if(barrio[i].pH >=6 && barrio[i].pH < 6.8){
                        barrio[i].puntos1 = 1;
                    }else {
                        barrio[i].puntos1= 0;}
                    if(barrio[i].conductividad >= 190){
                        barrio[i].puntos2= 3;
                    } else if (barrio[i].conductividad >= 145){
                         barrio[i].puntos2= 2;
                    } else if (barrio[i].conductividad >= 100){
                         barrio[i].puntos2= 1;
                    }else {
                         barrio[i].puntos2= 0;
                    }
                    if(barrio[i].turbidez == 0){
                        barrio[i].puntos3= 3;
                    }else if (barrio[i].turbidez >= 1 && barrio[i].turbidez <= 4){
                        barrio[i].puntos3= 1;
                    }else {
                        barrio[i].puntos3= 0;}
                    if(barrio[i].coliformes == 0){
                         barrio[i].puntos3= 3;
                    }else {
                         barrio[i].puntos3= 0;}
                         barrio[i].ptotal = barrio[i].puntos1 + barrio[i].puntos2 + barrio[i].puntos3;
                        }

                    mejorfuente = barrio[0];
                       for(i=1; i< TAM_FUENTE; i++){
                        if (mejorfuente.ptotal  < barrio[i].ptotal){
                            mejorfuente=barrio[i];
                            }
                        }

                    printf("La mejor fuente es la %s.\n", mejorfuente.fuente);

                    peorfuente = barrio[0];
                       for(i=1; i< TAM_FUENTE; i++){
                        if (peorfuente.ptotal  > barrio[i].ptotal){
                            peorfuente=barrio[i];
                            }
                        }

                    printf("La peor fuente es la %s.\n", peorfuente.fuente);


            	printf("Media conductividad: %f\n", mediac (barrio, TAM_FUENTE)/TAM_FUENTE);
            	printf("Media conductividad: %f\n", mediaspH (barrio, TAM_FUENTE)/TAM_FUENTE);
				printf("Media conductividad: %f\n", mediasturbidez (barrio, TAM_FUENTE)/TAM_FUENTE);
				printf("Media conductividad: %f\n", mediascoliformes (barrio, TAM_FUENTE)/TAM_FUENTE);
            	break;
           }
		   }while ( opciondato != 'B' && opciondato != 'E');
		break;
		case 2:

			printf("Introduce el numero de fuentes que quieres anadir\n");
			scanf("%d", &fnuevas);//ESTAS HAY QUE SUMARLAS AL TAM FUENTE
			//para que salgan otra vez en el fichero es imprimirlo como un vector de estructuras en un fprintf 
			//Despues de ese fprintf , se pone otro fprintf para las fuentes nuevas a añadir

			for(i=TAM_FUENTE; i<=fnuevas; i++){
				printf("Introduce el ph de la fuente %d", i);
				scanf("%f", &barrio[i].pH);
				printf("Introduce la conductividad de la fuente %d", i);
				scanf("%d", &barrio[i].conductividad);
				printf("Introduce la turbidez de la fuente %d", i);
				scanf("%d", &barrio[i].turbidez);
				printf("Introduce el numero de colonias coliformes de la fuente %d", i);
				scanf("%d",  &barrio[i].coliformes);
			}
			//TAM_FUENTE


		fsalida=fopen("202301_Lavapies.txt", "w"); //modo escritura
		if(fsalida==NULL){
		printf("Error, no puede crear el fichero.\n");
		return 0;
	}
	//PASO 2:Escribir el archivo

	//for(i=0;)
////	fprintf(fsalida,"La nota media es: %f", media/nestudiantes);
//	fprintf(fsalida,"Nota maxima es: %f", notaMax);

	//PASO3: Cerrar el archivo
	fclose(fsalida);


			break;

		case 3:
			printf("¡Hola usuario!");
			printf("En este apartado podras conocer informacion sobre el peligro de la preesencia de las fuentes y sus consecuencias\n");
			printf("Para empezar, Los coliformes son un grupo de bacterias utilizadas como indicadores de contaminación fecal en el agua.\n");
			printf("En una fuente local, se pueden encontrar diferentes tipos de coliformes, pero los mas comunes son Escherichia coli y Enterococcus faecalis.\n");
			printf("Estos microorganismos pueden ser peligrosos para la salud si se consumen en grandes cantidades, ya que pueden causar enfermedades como gastroenteritis, diarrea y fiebre tifoidea.\n");
			printf("Por lo tanto, es importante que el agua de la fuente local se analice regularmente para detectar la presencia de estos y otros contaminantes y tomar medidas adecuadas para garantizar su seguridad.\n");
			printf("\n");
			printf("Ahora que conoces un poco mas sobre estas especies, te gustaria saber un poco mas sobre las especies especificas de cada fuente?\n ");
			printf("¿De que fuentes quieres advertirte, sobre las fuentes que tienen 0 , 1 o 2 colonias?\n");
			scanf("%d", &nespecies);
			if(nespecies == 0){
            	printf("Las fuentes que tienen %d especies son:\n ", nespecies);
            	for(i=0;i<TAM_FUENTE;i++){
            		if (barrio[i].coliformes == 0)
            			printf("%s %f %d %d %d\n", barrio[i].fuente, barrio[i].pH, barrio[i].conductividad, barrio[i].turbidez, barrio[i].coliformes);}
            	printf("No hay ninguna especie coliforme en estas fuentes.\n");
            	printf("Por lo tanto, los beneficios de no tener coliformes en las fuentes son múltiples, como una reducción en el riesgo de enfermedades transmitidas por el agua,\n");
				printf("una mejora en la calidad del agua para uso recreativo y agrícola, y una mayor confianza en la seguridad del suministro de agua potable.\n");
				printf("Además, la eliminación de los coliformes puede reducir los costos asociados con el tratamiento y la purificación del agua.\n");}
            else if(nespecies == 1){
            	 printf("Las fuentes que tienen %d especies son:\n. ", nespecies);
				for(i=0;i<TAM_FUENTE;i++){
            		if (barrio[i].coliformes == 1)
            			printf("%s %f %d %d %d\n", barrio[i].fuente, barrio[i].pH, barrio[i].conductividad, barrio[i].turbidez, barrio[i].coliformes);}
            	printf("En estas fuentes se encuentra la Escherichia coli, una bacteria que se localiza comúnmente en el tracto intestinal de los seres humanos y animales.\n");
				printf("Si esta bacteria se encuentra en grandes cantidades en una fuente, puede indicar la presencia de contaminación fecal y, por lo tanto, de otros patógenos peligrosos para la salud.\n");
				printf("\n");
				printf("La exposición a la Escherichia coli puede provocar enfermedades como gastroenteritis, diarrea, fiebre y en casos extremos, insuficiencia renal y anemia hemolítica.\n");
				printf("Es importante tomar medidas adecuadas para garantizar la seguridad del agua de la fuente y evitar la exposición a estos riesgos potenciales para la salud.\n");}
            else if(nespecies == 2){
            	 printf("Las fuentes que tienen %d especies son:\n .", nespecies);
            	for(i=1;i<TAM_FUENTE;i++){
            		if (barrio[i].coliformes == 2)
            			printf("%s %f %d %d %d\n", barrio[i].fuente, barrio[i].pH, barrio[i].conductividad, barrio[i].turbidez, barrio[i].coliformes);}
            	printf("En estas fuentes, se observan 2 diferentes colonias\n");
            	printf("Encontrar la  Escherichia Coli y la  Enterococcus faecalis puede ser muy nocivo para la salud, ya que se combinan las causas perjudiciales de ambos patógenos.\n");
				printf("Beber agua con altos niveles de Enterococcus faecalis puede causar enfermedades gastrointestinales, infecciones del tracto urinario, sepsis y endocarditis.\n");
				printf("Algunas cepas de Enterococcus faecalis pueden ser resistentes a los antibióticos, lo que hace que las infecciones sean difíciles de tratar.\n");
				printf("Además, la exposición a la Escherichia coli puede provocar enfermedades como gastroenteritis, diarrea, fiebre, insuficiencia renal y anemia hemolítica.\n");
				printf("Es importante tomar medidas adecuadas para garantizar la seguridad del agua potable en estas fuentes y evitar la exposición a estos riesgos potenciales para la salud.\n");}

            else{

			 	printf("No hay esa cantidad de colonias coliformes \n");}
			break;




}}while(opcionprofesor > 4 || opcionprofesor < 1);//corchete del primer switch case y del primer do
	if(opcionprofesor == 4){
		return 0;}
}}//corchetes del int main y del else

void buscarph(struct Tfuente barrio[], float ph, int TAM_FUENTE){
                        int i=0;

                        if(ph>=6 && ph<=6.5){
                            printf("Las fuentes con un ph mas cercanas a %f que se encuentran entre 6 y 6.5 son:\n", ph);
                            for(i=0;i<TAM_FUENTE;i++){
                              if (barrio[i].pH >=6 && barrio[i].pH<=6.5)
                                printf("%s %f %d %d %d\n", barrio[i].fuente, barrio[i].pH, barrio[i].conductividad, barrio[i].turbidez, barrio[i].coliformes);}}
                        else if(ph<=7){
                            printf("Las fuentes con un ph mas cercanas a %f que se encuentran entre 6.5 y 7 son:\n", ph);
                          	for(i=0;i<=TAM_FUENTE;i++){
                                    if (barrio[i].pH >=6.5 && barrio[i].pH<=7)
                                        printf("%s %f %d %d %d\n", barrio[i].fuente, barrio[i].pH, barrio[i].conductividad, barrio[i].turbidez, barrio[i].coliformes);}}

                        else if(ph<=7.5){
                            printf("Las fuentes con un ph mas cercanas a %f que se encuentran entre 7 y 7.5 son:\n", ph);
                        	for(i=0;i<TAM_FUENTE;i++){
							  if (barrio[i].pH >=7 && barrio[i].pH<=7.5)
                                printf("%s %f %d %d %d\n", barrio[i].fuente, barrio[i].pH, barrio[i].conductividad, barrio[i].turbidez, barrio[i].coliformes);}}

                         else if(ph<=8){
                            printf("Las fuentes con un ph mas cercanas a %f que se encuentran entre 7.5 y 8 son:\n", ph);
                        for(i=0;i<TAM_FUENTE;i++){
							  if (barrio[i].pH >=7.5 && barrio[i].pH<=8)
                                printf("%s %f %d %d %d\n", barrio[i].fuente, barrio[i].pH, barrio[i].conductividad, barrio[i].turbidez, barrio[i].coliformes);}}}


void buscarcond(struct Tfuente barrio[],int conductividad, int TAM_FUENTE){
	int i=0;

                        if(conductividad>=100 && conductividad<=150){
                            printf("Las conductividades mas cercanas de %d que se encuentran entre 100 y 150 son:\n", conductividad);
                          for(i=0;i<TAM_FUENTE;i++){

                              if (barrio[i].conductividad >=100 && barrio[i].conductividad<=150)
                                printf("%s %f %d %d %d\n", barrio[i].fuente, barrio[i].pH, barrio[i].conductividad, barrio[i].turbidez, barrio[i].coliformes);}}

                        else if(conductividad>150 && conductividad<=200){
                            printf("Las conductividades mas cercanas de %d que se encuentran entre 150 y 200 son\n", conductividad);
                              for(i=0;i<TAM_FUENTE;i++){
							  if (barrio[i].conductividad >=150 && barrio[i].conductividad<=200)
                         printf("%s %f %d %d %d\n", barrio[i].fuente, barrio[i].pH, barrio[i].conductividad, barrio[i].turbidez, barrio[i].coliformes);}}

                         else if(conductividad>200 && conductividad<=250){
                            printf("Las conductividades mas cercanas de %d que se encuentran entre 200 y 250 son\n", conductividad);
                          for(i=0;i<TAM_FUENTE;i++){
							  if (barrio[i].conductividad >=200 && barrio[i].conductividad<=250)
                                printf("%s %f %d %d %d\n", barrio[i].fuente, barrio[i].pH, barrio[i].conductividad, barrio[i].turbidez, barrio[i].coliformes);}}

                        else if(conductividad>250 && conductividad<=300){
                            printf("Las conductividades mas cercanas de %d que se encuentran entre 250 y 300 son\n", conductividad);
                              for(i=0;i<TAM_FUENTE;i++){
							  if (barrio[i].conductividad >=250 && barrio[i].conductividad<=300)
                                printf("%s %f %d %d %d\n", barrio[i].fuente, barrio[i].pH, barrio[i].conductividad, barrio[i].turbidez, barrio[i].coliformes);}}


}

void buscarturb (struct Tfuente barrio[],int turbidez, int TAM_FUENTE){
                        int i=0;

                        if(turbidez == 0){
                            printf("Las fuentes de turbidez %d son:\n", turbidez);
                          for(i=0;i<TAM_FUENTE;i++){
							  if (barrio[i].conductividad == 0)
                                printf("%s %f %d %d %d\n", barrio[i].fuente, barrio[i].pH, barrio[i].conductividad, barrio[i].turbidez, barrio[i].coliformes);}}

                        else if(turbidez == 1){
                            printf("Las fuentes de turbidez %d son\n", turbidez);
                            for(i=0;i<TAM_FUENTE;i++){
							  if (barrio[i].conductividad == 1)
                                printf("%s %f %d %d %d\n", barrio[i].fuente, barrio[i].pH, barrio[i].conductividad, barrio[i].turbidez, barrio[i].coliformes);}}

                         else if(turbidez == 2){
                            printf("Las fuentes de turbidez %d son\n", turbidez);
                         for(i=0;i<TAM_FUENTE;i++){

                              if (barrio[i].conductividad == 2)
                                printf("%s %f %d %d %d\n", barrio[i].fuente, barrio[i].pH, barrio[i].conductividad, barrio[i].turbidez, barrio[i].coliformes);}}

                        else if(turbidez == 3){
                            printf("Las fuentes de turbidez %d son\n", turbidez);

                             for(i=0;i<TAM_FUENTE;i++){
							  if (barrio[i].conductividad == 3)
                                printf("%s %f %d %d %d\n", barrio[i].fuente, barrio[i].pH, barrio[i].conductividad, barrio[i].turbidez, barrio[i].coliformes);}}

                        else if(turbidez == 4){
                            printf("Las fuentes de turbidez %d son\n", turbidez);

                              if (barrio[i].conductividad == 4)
                                printf("%s %f %d %d %d\n", barrio[i].fuente, barrio[i].pH, barrio[i].conductividad, barrio[i].turbidez, barrio[i].coliformes);}

                            else if(turbidez == 5){
                            printf("Las fuentes de turbidez %d son \n", turbidez);
                           for(i=0;i<TAM_FUENTE;i++){
                              if (barrio[i].conductividad == 5)
                                printf("%s %f %d %d %d\n", barrio[i].fuente, barrio[i].pH, barrio[i].conductividad, barrio[i].turbidez, barrio[i].coliformes);}}

                            else if(turbidez == 10){
                            printf("Las fuentes de turbidez %d son\n", turbidez);
                           for(i=0;i<TAM_FUENTE;i++){
                              if (barrio[i].conductividad == 10)
                                printf("%s %f %d %d %d\n", barrio[i].fuente, barrio[i].pH, barrio[i].conductividad, barrio[i].turbidez, barrio[i].coliformes);}}

                            else {
                                printf("No existen fuentes con esa conductividad\n");
                            }
                        }






void buscarcoliforme(struct Tfuente barrio[], int coliformes, int TAM_FUENTE){
                        int i=0;


                        if(coliformes == 0){
                            printf("Las fuentes con una cantidad de %d de colonias coliformes \n", coliformes);
                          for(i=0;i<TAM_FUENTE;i++){
                              if (barrio[i].coliformes == 0)
                                printf("%s %f %d %d %d\n", barrio[i].fuente, barrio[i].pH, barrio[i].conductividad, barrio[i].turbidez, barrio[i].coliformes);}}
                        else if(coliformes == 1){
                            printf("Las fuentes con una cantidad de %d de colonias coliformes \n", coliformes);
                            for(i=0;i<TAM_FUENTE;i++){
                                    if (barrio[i].coliformes == 1)
                                        printf("%s %f %d %d %d\n", barrio[i].fuente, barrio[i].pH, barrio[i].conductividad, barrio[i].turbidez, barrio[i].coliformes);}}
                        else if(coliformes == 2){
                            printf("Las fuentes con una cantidad de %d de colonias coliformes \n", coliformes);
                           for(i=0;i<TAM_FUENTE;i++){
                                    if (barrio[i].coliformes == 2)
                                        printf("%s %f %d %d %d\n", barrio[i].fuente, barrio[i].pH, barrio[i].conductividad, barrio[i].turbidez, barrio[i].coliformes);}}
                        else printf("No hay esa cantidad de colonias coliformes \n");
}
float mediac (struct Tfuente barrio[], int dim) {
	int i=0;
	float media=0;

for(i=1;i<=dim;i++){
		media += barrio[i].conductividad;}


	return (media);
}
float mediaspH (struct Tfuente barrio[], int dim) {
	int i=0;
	float media=0;
for(i=1;i<=dim;i++){
		media += barrio[i].pH;}


	return (media);
}
float mediasturbidez(struct Tfuente barrio[], int dim) {
	int i=0;
	float media=0;

for(i=1;i<=dim;i++){
		media += barrio[i].turbidez;}


	return (media);
}
float mediascoliformes(struct Tfuente barrio[], int dim) {
	int i=0;
	float media=0;
	for(i=1;i<=dim;i++){

		media += barrio[i].coliformes;}


	return media;}
