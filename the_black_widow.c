#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define TAM_JUGADORES 2
#define TAM_MAX 300

//ESTRUCTURAS
	//Soluciones a las preguntas
struct TNivelFacil { //Nivel 1
	char pregunta1;
	char pregunta2;
	char pregunta3 [30];
	char pregunta4;
	char pregunta5;
	char pregunta6;
	char pregunta7;
	char pregunta8;
	char pregunta9 [20];
	char pregunta10;
};

struct TNivelMedio { //Nivel 2
	char pregunta1;
	char pregunta2;
	char pregunta3;
	char pregunta4;
	char pregunta5;
	char pregunta6;
};

struct TNivelDificil { //Nivel 3
	char pregunta1;
	char pregunta2;
	char pregunta3;
	char pregunta4 [30];
	char pregunta5;
	char pregunta7;
	char pregunta8;
};

struct TNivelMuyDificil { //Nivel 4
    char pregunta1;
    char pregunta2;
    char pregunta3;
    char pregunta4;
    char pregunta5;
    char pregunta6;
};


	//Informacion de los jugadores
struct TJugador{
	char nombre[50];
	int puntuacion;
	int ultima_pregunta;

};

	//Información histórica
struct THistorica{
	char nombre[50];
	int puntuacion;
	int ultima_pregunta;

};


//FUNCIONES
	//Función para las respuestas de los jugadores
int PreguntasTest (char respuesta, char solucion, int nivel) {
	int puntuacion=0, bien, mal;

	switch (nivel) {
		case 1:
			bien = 5;
			mal = 1;
		break;

		case 2:
			bien = 7;
			mal = 3;
		break;

		case 3:
			bien = 10;
			mal = 5;
		break;

		case 4:
			bien = 15;
			mal = 10;
		break;
	}



	if (respuesta==solucion) {
		printf ("	Has ganado %d puntos\n", bien);
		puntuacion +=bien;
	}
	else {
		printf ("	Respuesta incorrecta\n");
		puntuacion -= mal;
	}


return puntuacion;
};

int PreguntasEscritas (char respuesta[], char solucion[], int nivel){
	int comparar, puntuacion=0, bien, mal;

	if (nivel == 1){
		bien = 5;
		mal = 1;
	}
	else if  (nivel == 2){
		bien = 7;
		mal = 3;
	}
	else if  (nivel == 3) {
		bien = 10;
		mal = 5;
	}
	else {
		bien = 15;
		mal = 10;
	}

	comparar = strcmp (respuesta, solucion);
	if (comparar==0){
		printf ("	Has ganado %d puntos\n", bien);
		puntuacion += bien;
	}
	else {
		printf ("	Respuesta incorrecta\n");
		puntuacion -= mal;
	}

return puntuacion;
};

    //Función salir del juego
int salida(struct THistorica Historicas[], int dimension, struct TJugador Jugador, int puntuacion, int pregunta){

	FILE * pfichero;
	int i;

	if (puntuacion<=0){
        Jugador.puntuacion=0;
        Jugador.ultima_pregunta=pregunta;

        pfichero = fopen ("puntuaciones.txt", "w");

        for (i=0;i<dimension;i++){
            fprintf (pfichero, "%s %d %d\n", Historicas[i].nombre, Historicas[i].puntuacion, Historicas[i].ultima_pregunta);
        }
        fprintf (pfichero, "%s %d %d\n", Jugador.nombre, Jugador.puntuacion, Jugador.ultima_pregunta);
        fclose (pfichero);

		printf ("\n\n");
		printf ("	G A M E    O V E R");
		printf ("\n\n");
		return 1;
	}


    return 0;
}

int SalidaNivel(struct THistorica Historicas[], int dimension, struct TJugador Jugador, int puntuacion, int pregunta, int decision){
	FILE * pfichero;
	int i;

	Jugador.puntuacion=puntuacion;
    Jugador.ultima_pregunta=pregunta;

    pfichero = fopen ("puntuaciones.txt", "w");
    for (i=0;i<dimension;i++){
        fprintf (pfichero, "%s %d %d", Historicas[i].nombre, Historicas[i].puntuacion, Historicas[i].ultima_pregunta);
    }
    fprintf (pfichero, "%s %d %d\n", Jugador.nombre, Jugador.puntuacion, Jugador.ultima_pregunta);
    fclose (pfichero);

	if (decision==1){
		printf ("\n\n");
		printf ("	C O B A R D E");
		printf ("\n\n");
	}
	else{
		printf ("\n\n");
		printf ("	E N H O R A B U E N A   N O   E R E S   C O B A R D E");
		printf ("\n\n");
	}


return 0;
}

	//Función para el banner
void Banner () {
	printf ("\n");
	printf ("                   .            .\n");
	printf ("                   -            -\n");
	printf ("             .    --            --     .\n");
	printf ("             -   --              --    -\n");
	printf ("            --  --                --   --\n");
	printf ("           --    --              --     --\n");
	printf ("          --      --            --       --\n");
	printf ("           --      --  .    .  --       --\n");
	printf ("            --       -- -- -- --       --\n");
	printf ("             --     --         --     --\n");
	printf ("              --   --           --   --\n");
	printf ("               -- --             -- --\n");
	printf ("                   --           --\n");
	printf ("                    --         --\n");
	printf ("        -- -- -- -- --         -- -- -- -- --\n");
	printf ("       --    -- -- --           -- -- --    --\n");
	printf ("      --    --    --             --    --    --\n");
	printf ("     --    --    --               --    --    --\n");
	printf ("    --    --    --                 --    --    --\n");
	printf ("    --   --    --                   --    --    --\n");
	printf ("    --  --      --                  --     --    --\n");
	printf ("         --      --                --       --\n");
	printf ("          --      --              --       --\n");
	printf ("           --      --            --       --\n");
	printf ("            --      --          --       --\n");
	printf ("             --      --        --       --\n");
	printf ("              --      -- -- -- -       --\n");
	printf ("               --                     --\n");
	printf ("                --                   --\n");
	printf ("                 --                 --\n");
	printf ("\n");

	return;
}


   //Función historia en fichero
int Historia(){
    FILE *phistoria;
    phistoria = fopen("Historia.txt", "r");
    char lineahistoria[80];
    if(phistoria == NULL){
       printf("	Error en la apertura del fichero\n");
       return -1;
    }

    char c;

    while(((c = fgetc(phistoria))) != EOF) {
        printf("%c", c);
    }
    return 0;
}

int Historia1(){
    FILE *phistoria;
    phistoria = fopen("Historia1.txt", "r");
    char lineahistoria[80];
    if(phistoria == NULL){
       printf("	Error en la apertura del fichero\n");
       return -1;
    }

    char c;

    while(((c = fgetc(phistoria))) != EOF) {
        printf("%c", c);
    }
    return 0;
}

int Historia2(){
    FILE *phistoria;
    phistoria = fopen("Historia2.txt", "r");
    char lineahistoria[80];
    if(phistoria == NULL){
       printf("	Error en la apertura del fichero\n");
       return -1;
    }

    char c;

    while(((c = fgetc(phistoria))) != EOF) {
        printf("%c", c);
    }
    return 0;
}

int Historia3(){
    FILE *phistoria;
    phistoria = fopen("Historia3.txt", "r");
    char lineahistoria[80];
    if(phistoria == NULL){
       printf("	Error en la apertura del fichero\n");
       return -1;
    }

    char c;

    while(((c = fgetc(phistoria))) != EOF) {
        printf("%c", c);
    }
    return 0;
}

int Historia4(){
    FILE *phistoria;
    phistoria = fopen("Historia4.txt", "r");
    char lineahistoria[80];
    if(phistoria == NULL){
       printf("	Error en la apertura del fichero\n");
       return -1;
    }

    char c;

    while(((c = fgetc(phistoria))) != EOF) {
        printf("%c", c);
    }
    return 0;
}




int main() {

//ZONA DE DECLARACIÓN DE VARIABLES
	FILE*pfichero;
	int opcion,n;
	char pregunta;

	//Variable encargada de contar el numero de filas en el archivo donde se almacenan los datos históricos
	int contador=0;

	//Variable auxiliar
	int aux=0;

	//Variable para almacenar las respuestas de cada persona
	char respuesta1, respuesta2[50];

	int puntuacion=0;


	//Nos permite poner tildes
	setlocale (LC_CTYPE,"spanish");

	//Variables para bucles
	int i, j;

	//Estructura de jugadores
	struct TJugador Jugador = {"-", 0, 0};

	//Estructura historica
	struct THistorica Historicas[TAM_MAX];

	//Estructuras con las soluciones a los niveles
	struct TNivelFacil NivelFacil = {'a', 'b', "aracnofobia", 'a', 'a', 'd', 'd', 'a', "camara secreta",'b'};
	struct TNivelMedio NivelMedio = {'a', 'd', 'c', 'c', 'c', 'c'};
	struct TNivelDificil NivelDificil = {'b', 'b', 'b', "aranea",'b', 'b', 'c'};
	struct TNivelMuyDificil NivelMuyDificil = {'a', 'a', 'c', 'b', 'b', 'b'};

	//Varible para comparar cadenas
	int comparar;

	//Funcion que contiene el banner
	Banner ();



	do {
		printf ("\n");
		printf("	MENÚ DE OPCIONES\n");
		printf("	Escriba el número que representa la acción que desea realizar:\n");
    	printf("	1. Instrucciones del juego\n");
    	printf("	2. Iniciar  sesión\n");
    	printf("	3. Ranking de puntuaciones\n");
   		printf("	4. Iniciar juego\n");
    	printf("	5. Salir\n\n");

		printf("	OPCIÓN: ");
		scanf("%d", &opcion);

		switch(opcion) {

            case 1:
            	system("cls");
                printf ("\n");
    			printf ("	INSTRUCCIONES DE JUEGO\n");
        		printf("	1-Pulse iniciar sesión e introduzca su nombre.\n");
        		printf("	2-El propio programa le volverá a mostrar el menú, a continuación pulse iniciar juego y disfrute de este.\n");
        		printf ("	Aclaración: las preguntas del juego deben ser respondidas usando letras minúsculas\n");
				printf ("\n\n");
        	break;

            case 2:
            	system("cls");
            	printf("\n");

				//Ańado la información almacenada en el txt a un vector de estructuras
				pfichero=fopen ("puntuaciones.txt", "r");

				printf("	Intruduce tu nombre jugador: \n");
				printf("	NOMBRE: ");
				fflush(stdin);
				gets(Jugador.nombre);
				printf("\n");

				i=0;
				while (fscanf (pfichero, "%s %d %d", Historicas[i].nombre, &Historicas[i].puntuacion, &Historicas[i].ultima_pregunta) != EOF){
					contador++;
					i++;
				}

				aux=0;
				for (i=0; i<contador; i++) {
					if (strcmp (Jugador.nombre, Historicas[i].nombre) == 0){
						aux++;
						printf("	%d. %s tuviste una puntuación de %d y tu última pregunta fue la %d\n", aux, Historicas[i].nombre, Historicas[i].puntuacion, Historicas[i].ultima_pregunta);
					}
				}

				fclose (pfichero);
				printf ("	%s recuerda que una vez inicie el juego tu puntuación volverá a cero, sin importar los datos anteriores\n", Jugador.nombre);

				printf ("\n");

				printf ("	Bienvenido al juego, jugador\n\n");
				printf ("	(Usa una voz de villano de Disney)\n");
				printf ("	En breves te adentraras en esta terrorífica experiencia a solas\n");
				printf("\n");


            break;

			case 3:
            	system("cls");
            	printf("\n\n");
                pfichero = fopen ("puntuaciones.txt", "r");
                if (pfichero == NULL) {
                    printf ("Error en la apertura del fichero\n");
                    return 0;
                }
                i=0;
                while (fscanf(pfichero, "%s %d %d",Historicas[i].nombre, &Historicas[i].puntuacion, &Historicas[i].ultima_pregunta) != EOF) {
                    printf("%s %d\n", Historicas[i].nombre, Historicas[i].puntuacion);
                    i++;
                }
                printf("\n");
                fclose (pfichero);

            break;

            case 4:
                system("cls");

                if (strcmp (Jugador.nombre, "-")==0){
                	printf ("\n\n");
                	printf ("	No ha iniciado sesión, regrese al menú principal\n");
                	printf ("\n\n");
                	break;
				}

				printf ("\n");
                Historia();

                fflush(stdin);
                printf("	żEstás seguro de querer adentrarte? Responde si (s) o no (n)\n");
                printf("	RESPUESTA: ");
                scanf("%c", &pregunta);
                if (pregunta == 'n') {
                    break;
                }

				system("cls");

                printf("	La prueba empieza en: \n");
                printf("	3\n");
                printf("	2\n");
                printf("	1\n");

                printf("\n\n");



                // NIVEL FÁCIL

				printf ("	NIVEL FÁCIL\n");
				printf ("\n\n");

                // Pregunta 1
                fflush(stdin);
                printf("  1. żA qué se dedicaba Aracne antes de ser convertida?\n");
                printf("	a. Tejedora\n"); // Correcta
                printf("	b. Costurera\n");
                printf("	c. Sastre\n");
                printf("	d. Diseńadora\n");

                printf ("\n");
				printf ("	RESPUESTA: ");
                scanf ("%c", &respuesta1);

				puntuacion=0;
				puntuacion += PreguntasTest (NivelFacil.pregunta1, respuesta1, 1);
				if(salida(Historicas, contador, Jugador, puntuacion, 1)==1){
                    break;
				}
				printf ("	Tu puntuación actual es de %d puntos\n", puntuacion);
				printf ("\n\n");


				// Pregunta 2
				fflush(stdin);
                printf("  2. żCuál es el nombre de la actriz que interpreta a La Viuda Negra en Los Vengadores?\n");
                printf("	a. Sofía Vergara\n");
                printf("	b. Scarlett Johansson\n"); // Correcta
                printf("	c. Elizabeth Olsen\n");
                printf("	d. Natalie Portman\n");

                printf ("\n");
				printf ("	RESPUESTA: ");
                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest (NivelFacil.pregunta2, respuesta1, 1);

				if(salida(Historicas, contador, Jugador, puntuacion, 2)==1){
					break;
				}
        		printf ("	Tu puntuación actual es de %d puntos\n", puntuacion);
				printf ("\n\n");


				// Pregunta 3
                printf ("\n");
                fflush(stdin);
                printf("  3. żCómo se llama el miedo a las arańas? (Introduca una única palabra en minúsculas y sin acentos)\n");
                // Aracnofobia

                printf ("\n");
				printf ("	RESPUESTA: ");
                gets (respuesta2);

                puntuacion += PreguntasEscritas (NivelFacil.pregunta3, respuesta2, 1);
                if(salida(Historicas, contador, Jugador, puntuacion, 3)==1){
					break;
				}
				fflush(stdin);
                printf ("	Tu puntuación actual es de %d puntos\n", puntuacion);
				printf ("\n\n");


                // Pregunta 4
                fflush(stdin);
                printf("  4. Realiza la clasificación taxonómica de las arańas en: reino, filo, clase\n");
                printf("	a. Animalia - Artrópodos - Aránidos\n"); // Correcta
                printf("	b. Aránidos - Moluscos - Animalia\n");
                printf("	c. Artrópodos - Mamíferos - Aránidos\n");
                printf("	d. Animalia - Mamíferos - Aránidos\n");

                printf ("\n");
				printf ("	RESPUESTA: ");
                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest (NivelFacil.pregunta4, respuesta1, 1);
                if(salida(Historicas, contador, Jugador, puntuacion, 4)==1){
					break;
				}
				printf ("	Tu puntuación actual es de %d puntos\n", puntuacion);
				printf ("\n\n");


                // Pregunta 5
                fflush(stdin);
                printf("  5. żEn cuál reconocida organización estuvo trabajando Viuda Negra junto con otros suprehéroes?\n");
                printf("	a. S.H.I.E.L.D\n"); // Correcta
                printf("	b. S.I.D\n");
                printf("	c. S.I.D.E\n");
                printf("	d. F.I.L.E\n");

                printf ("\n");
				printf ("	RESPUESTA: ");
                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest (NivelFacil.pregunta5, respuesta1, 1);
            	if(salida(Historicas, contador, Jugador, puntuacion, 5)==1){
					break;
				}
                printf ("	Tu puntuación actual es de %d puntos\n", puntuacion);
				printf ("\n\n");


               // Pregunta 6
                fflush(stdin);
                printf("  6. Nombre de la escritora que publicó en 2020 de la mano de Disney Libros un libro sobre el famoso personaje Viuda Negra\n");
                printf("	a. Cassandra Clare\n");
                printf("	b. Holly Black\n");
                printf("	c. Rick Riordan\n");
                printf("	d. Margaret Stohl\n"); // Correcta

                printf ("\n");
				printf ("	RESPUESTA: ");
                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest(NivelFacil.pregunta6, respuesta1, 1);
                if(salida(Historicas, contador, Jugador, puntuacion, 6)==1){
					break;
				}
                printf ("	Tu puntuación actual es de %d puntos\n", puntuacion);
				printf ("\n\n");


                // Pregunta 7
                fflush(stdin);
                printf("  7. żCuántos ojos tiene una arańa?\n");
                printf("	a. 5\n");
                printf("	b. 2\n");
                printf("	c. 4\n");
                printf("	d. 8\n"); // Correcta

				printf ("\n");
				printf ("	RESPUESTA: ");
                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest(NivelFacil.pregunta7, respuesta1, 1);
                if(salida(Historicas, contador, Jugador, puntuacion, 7)==1){
					break;
				}
				printf ("	Tu puntuación actual es de %d puntos\n", puntuacion);
				printf ("\n\n");


                // Pregunta 8
                fflush(stdin);
                printf("  8. żQué personaje no forma parte de Los Vengadores?\n");
                printf("	a. Soldado de invierno\n"); // Correcta
                printf("	b. Ojo de Halcón\n");
                printf("	c. Thor\n");
                printf("	d. Capitán América\n");

                printf ("\n");
				printf ("	RESPUESTA: ");
                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest(NivelFacil.pregunta8, respuesta1, 1);
                if(salida(Historicas, contador, Jugador, puntuacion, 8)==1){
					break;
				}
                printf ("	Tu puntuación actual es de %d puntos\n", puntuacion);
				printf ("\n\n");


                // Pregunta 9
                printf("\n");
                fflush(stdin);
                printf("  9. żEn qué película de Harry Potter aparecen arańas? (Solo dos palabras)\n");
                // Cámara Secreta

                printf ("\n");
				printf ("	RESPUESTA: ");
                gets (	  respuesta2);

                puntuacion += PreguntasEscritas (NivelFacil.pregunta9, respuesta2, 1);
                if(salida(Historicas, contador, Jugador, puntuacion, 9)==1){
					break;
				}
                printf ("	Tu puntuación actual es de %d puntos\n", puntuacion);
				printf ("\n\n");


                // Pregunta 10
                fflush(stdin);
                printf("  10. żCómo Peter Parker se convirtió en Spiderman?\n");
                printf("	a. Por comerse una arańa\n");
                printf("	b. Por el mordisco de una arańa\n"); //Correcta
                printf("	c. Por tocar una telarańa\n");
                printf("	d. Al ser maldecido por una bruja\n");

                printf ("\n");
				printf ("	RESPUESTA: ");
                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest(NivelFacil.pregunta10, respuesta1, 10);
                if(salida(Historicas, contador, Jugador, puntuacion, 10)==1){
					break;
				}
                printf ("	Tu puntuación actual es de %d puntos\n", puntuacion);
				printf ("\n\n");


				//Opción para salir del código
				fflush(stdin);
                printf("	żDesea seguir con la aventura? Responde si (s) o no (n)\n");
                printf("	RESPUESTA: ");
                scanf("%c", &pregunta);
                if (pregunta == 'n') {
                	SalidaNivel(Historicas, contador, Jugador, puntuacion, 10, 1);
                    break;
                }



				//NIVEL MEDIO

                system("cls");

                printf ("\n");
                Historia1();

                printf("\n\n");
				printf ("	NIVEL MEDIO\n");
				printf ("\n\n");

                // Pregunta 11
                printf("\n");
                fflush(stdin);
                printf("  11. żDe qué animal huyen las arańas en Harry Potter?\n");
                printf("	a. Basilisco\n"); //Correcta
                printf("	b. Iguana\n");
                printf("	c. Lagarto\n");
                printf("	d. Cobra\n");

                printf ("\n");
				printf ("	RESPUESTA: ");
                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest(NivelMedio.pregunta1, respuesta1, 2);
                if(salida(Historicas, contador, Jugador, puntuacion, 11)==1){
					break;
				}
                printf ("	Tu puntuación actual es de %d puntos\n", puntuacion);
				printf ("\n\n");


                // Pregunta 12
                fflush(stdin);
                printf("  12. żCuál es el nombre de pila de La Viuda Negra?\n");
                printf("	a. Natasha Romanova\n");
                printf("	b. Natalia Romanoff\n");
                printf("	c. Natalia Romanova\n");
                printf("	d. Natasha Romanoff\n"); //Correcta

                printf ("\n");
				printf ("	RESPUESTA: ");
                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest(NivelMedio.pregunta2, respuesta1, 2);
                if(salida(Historicas, contador, Jugador, puntuacion, 12)==1){
					break;
				}
                printf ("	Tu puntuación actual es de %d puntos\n", puntuacion);
				printf ("\n\n");


                // Pregunta 13
                fflush(stdin);
                printf("  13. żQué color atrae a las arańas?\n");
                printf("	a. Rojo\n");
                printf("	b. Negro\n");
                printf("	c. Verde\n"); //Correcta
                printf("	d. Blanco\n");

                printf ("\n");
				printf ("	RESPUESTA: ");
                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest(NivelMedio.pregunta3, respuesta1, 2);
                if(salida(Historicas, contador, Jugador, puntuacion, 13)==1){
					break;
				}
                printf ("	Tu puntuación actual es de %d puntos\n", puntuacion);
				printf ("\n\n");


                // Pregunta 14
                fflush(stdin);
                printf("  14. żCuántos ańos puede vivir una tarántula?\n");
                printf("	a. 34 ańos\n");
                printf("	b. 35 ańos\n");
                printf("	c. 30 ańos\n"); //Correcta
                printf("	d. 29 ańos\n");

                printf ("\n");
				printf ("	RESPUESTA: ");
                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest(NivelMedio.pregunta4, respuesta1, 2);
                if(salida(Historicas, contador, Jugador, puntuacion, 14)==1){
					break;
				}
                printf ("	Tu puntuación actual es de %d puntos\n", puntuacion);
				printf ("\n\n");


                // Pregunta 15
                fflush(stdin);
                printf("  15. Nombre de la arańa que picó a Fran Cuesta en 2020?\n");
                printf("	a. Tarántula\n");
                printf("	b. Viuda Negra\n");
                printf("	c. Arańa Huntsman\n"); //Correcta
                printf("	d. Arańa saltarina\n");

                printf ("\n");
				printf ("	RESPUESTA: ");
                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest(NivelMedio.pregunta5, respuesta1, 2);
                if(salida(Historicas, contador, Jugador, puntuacion, 15)==1){
					break;
				}
                printf ("	Tu puntuación actual es de %d puntos\n", puntuacion);
				printf ("\n\n");


                // Pregunta 16
                fflush(stdin);
                printf("  16. żQué tipo de arańa picó a Peter Parker?\n");
                printf("	a. Arańa del Banano\n");
                printf("	b. Arańa lobo\n");
                printf("	c. Viuda Negra\n"); //Correcta
                printf("	d. Arańa espalda roja\n");

                printf ("\n");
				printf ("	RESPUESTA: ");
                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest(NivelMedio.pregunta6, respuesta1, 2);
            	if(salida(Historicas, contador, Jugador, puntuacion, 16)==1){
					break;
				}
                printf ("	Tu puntuación actual es de %d puntos\n", puntuacion);
				printf ("\n\n");


				//Opción para salir del código
				fflush(stdin);
                printf("	żDesea seguir con la aventura? Responde si (s) o no (n)\n");
                printf("	RESPUESTA: ");
                scanf("%c", &pregunta);
                if (pregunta == 'n') {
                	SalidaNivel(Historicas, contador, Jugador, puntuacion, 16, 1);
                    break;
                }



                //NIVEL DIFÍCIL

                system("cls");

				printf ("\n");
                Historia2();

                printf("\n\n");
				printf ("  NIVEL DIFÍCIL\n");
				printf ("\n\n");


				// Pregunta 17
				fflush(stdin);
                printf("  17. żPor qué Atenea convirtió a Aracne?\n");
                printf("	a. Por desafiarla\n");
                printf("	b. Por perder en una competición contra ella\n"); //Correcta
                printf("	c. Por proponer un tema inapropiado en la conversación\n");
                printf("	d. Por intentar matar a uno de los hijos de Atenea\n");

                printf ("\n");
				printf ("	RESPUESTA: ");
                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest(NivelDificil.pregunta1, respuesta1, 3);
                if(salida(Historicas, contador, Jugador, puntuacion, 17)==1){
					break;
				}
                printf ("	Tu puntuación actual es de %d puntos\n", puntuacion);
				printf ("\n\n");


                // Pregunta 18
                fflush(stdin);
                printf("  18. żCuántas familias de arańas han sido reconocidas?\n");
                printf("	a. 221\n");
                printf("	b. 110\n"); //Correcta
                printf("	c. 95\n");
                printf("	d. 257\n");

                printf ("\n");
				printf ("	RESPUESTA: ");
                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest(NivelDificil.pregunta2, respuesta1, 3);
                if(salida(Historicas, contador, Jugador, puntuacion, 18)==1){
					break;
				}
                printf ("	Tu puntuación actual es de %d puntos\n", puntuacion);
				printf ("\n\n");


                // Pregunta 19
                fflush(stdin);
                printf("  19. żQué nombre recibe la instalación donde la espía soviética apodada Viuda Negra fue entrenada?\n");
                printf("	a. Sala roja\n");
                printf("	b. Habitación roja\n"); //Correcta
                printf("	c. Cuarto rojo\n");
                printf("	d. Cuarto negro\n");

                printf ("\n");
				printf ("	RESPUESTA: ");
                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest(NivelDificil.pregunta3, respuesta1, 3);
                if(salida(Historicas, contador, Jugador, puntuacion, 19)==1){
					break;
				}
                printf ("	Tu puntuación actual es de %d puntos\n", puntuacion);
				printf ("\n\n");


                // Pregunta 20
                fflush(stdin);
                printf("  20. żCómo se dice arańa en latín? (Solo una palabra)\n");
                //aranea

                printf ("\n");
				printf ("	RESPUESTA: ");
				gets (respuesta2);

                puntuacion += PreguntasEscritas (NivelDificil.pregunta4, respuesta2, 3);
            	if(salida(Historicas, contador, Jugador, puntuacion, 20)==1){
					break;
				}
                printf ("	Tu puntuación actual es de %d puntos\n", puntuacion);
				printf ("\n\n");


                // Pregunta 21
                fflush(stdin);
                printf("  21. En la película de Marvel sobre la Viuda Negra, żcómo se llama la hermana de Natasha Romanoff?\n");
                printf("	a. Melina Vostokoff\n");
                printf("	b. Yelena Belova\n"); //Correcta
                printf("	c. Alexei Shostakov\n");
                printf("	d. Katia Novikov\n");

                printf ("\n");
				printf ("	RESPUESTA: ");
                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest(NivelDificil.pregunta5, respuesta1, 3);
            	if(salida(Historicas, contador, Jugador, puntuacion, 21)==1){
					break;
				}
                printf ("	Tu puntuación actual es de %d puntos\n", puntuacion);
				printf ("\n\n");


                // Pregunta 22
                fflush(stdin);
                printf("  22. Dentro de este programa hemos escondido una arańa, żdónde está? (Solo una palabra aunque puede haber sinónimos)\n");
                //Inicio, arriba o principio

                printf ("\n");
				printf ("	RESPUESTA: ");
				gets (respuesta2);

				if (strcmp(respuesta2, "inicio") == 0 || strcmp(respuesta2, "principio") == 0 || strcmp(respuesta2, "arriba") == 0){
					puntuacion += 10;
					printf ("	Has ganado 10 puntos\n");
				}
                else{
                	puntuacion-=5;
                	printf ("	Respuesta incorrecta\n");
				}
				Jugador.puntuacion=puntuacion;
            	if(salida(Historicas, contador, Jugador, puntuacion, 22)==1){
					break;
				}
                printf ("	Tu puntuación actual es de %d puntos\n", puntuacion);
				printf ("\n\n");


                // Pregunta 23
                fflush(stdin);
                printf("  23. żCuál es la arańa más peligrosa del mundo?\n");
                printf("	a. Arańa bańanera\n");
                printf("	b. Errante del banano\n"); //Correcta
                printf("	c. Errante de seda\n");
                printf("	d. Arańa violinista\n");

                printf ("\n");
				printf ("	RESPUESTA: ");
                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest(NivelDificil.pregunta7, respuesta1, 3);
            	if(salida(Historicas, contador, Jugador, puntuacion, 23)==1){
					break;
				}
                printf ("	Tu puntuación actual es de %d puntos\n", puntuacion);
				printf ("\n\n");


                // Pregunta 24
                fflush(stdin);
                printf("  24. żCuántas especies de arańas existen?\n");
                printf("	a. 47957\n");
                printf("	b. 41800\n");
                printf("	c. 46500\n"); //Correcta
                printf("	d. 45500\n");

                printf ("\n");
				printf ("	RESPUESTA: ");
                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest(NivelDificil.pregunta8, respuesta1, 3);
            	if(salida(Historicas, contador, Jugador, puntuacion, 24)==1){
					break;
				}
                printf ("	Tu puntuación actual es de %d puntos\n", puntuacion);
				printf ("\n\n");


				//Opción para salir del código
				fflush(stdin);
                printf("	żDesea seguir con la aventura? Responde si (s) o no (n)\n");
                printf("	RESPUESTA: ");
                scanf("%c", &pregunta);
                if (pregunta == 'n') {
                	SalidaNivel(Historicas, contador, Jugador, puntuacion, 24, 1);
                    break;
                }


                //NIVEL MUY DIFÍCIL

                system("cls");

                printf ("\n");
                Historia3();

                printf("\n\n");
				printf ("  NIVEL MUY DIFÍCIL\n");
				printf ("\n\n");

                // Pregunta 25
                fflush(stdin);
                printf("  25. żEn qué se convirtió Benedict Lightwood?\n");
                printf("	a. Un gusano\n"); // Correcta
                printf("	b. Una arańa\n");
                printf("	c. Un pato\n");
                printf("	d. Un demonio\n");

                printf ("\n");
				printf ("	RESPUESTA: ");
                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest(NivelMuyDificil.pregunta1, respuesta1, 4);
            	if(salida(Historicas, contador, Jugador, puntuacion, 25)==1){
					break;
				}
                printf ("	Tu puntuación actual es de %d puntos\n", puntuacion);
				printf ("\n\n");


                // Pregunta 26
                fflush(stdin);
                printf("  26. żCómo se llaman las arańas cuya seda es tan resistente como una armadura? (Libro: Trono de Cristal)\n");
                printf("	a. Las arańas Stygia\n"); // Correcta
                printf("	b. No hay arańas\n");
                printf("	c. Las arańas Stigya\n");
                printf("	d. Las arańas de Stigia\n");

                printf ("\n");
				printf ("	RESPUESTA: ");
                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest(NivelMuyDificil.pregunta2, respuesta1, 4);
            	if(salida(Historicas, contador, Jugador, puntuacion, 26)==1){
					break;
				}
                printf ("	Tu puntuación actual es de %d puntos\n", puntuacion);
				printf ("\n\n");


                // Pregunta 27
                fflush(stdin);
                printf("  27. żCuál de estas no es un arma de Viuda Negra?\n");
                printf("	a. Mordida de la viuda\n");
                printf("	b. Línea Viuda\n");
                printf("	c. La caricia de la viuda\n"); // Correcta
                printf("	d. El beso de la viuda\n");

                printf ("\n");
				printf ("	RESPUESTA: ");
                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest(NivelMuyDificil.pregunta3, respuesta1, 4);
               	if(salida(Historicas, contador, Jugador, puntuacion, 27)==1){
					break;
				}
                printf ("	Tu puntuación actual es de %d puntos\n", puntuacion);
				printf ("\n\n");


                // Pregunta 28
                fflush(stdin);
                printf("  28. żCómo se apellida el líder de la organización soviética que reclutó a la después conocida como Viuda Negra?\n");
                printf("	a. Malakov\n");
                printf("	b. Dreykov\n"); // Correcta
                printf("	c. Davanova\n");
                printf("	d. Petrova\n");

                printf ("\n");
				printf ("	RESPUESTA: ");
                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest(NivelMuyDificil.pregunta4, respuesta1, 4);
            	if(salida(Historicas, contador, Jugador, puntuacion, 28)==1){
					break;
				}
                printf ("	Tu puntuación actual es de %d puntos\n", puntuacion);
				printf ("\n\n");


                // Pregunta 29
                fflush(stdin);
                printf("  29. żQué tipo de arańa es Aragog?\n");
                printf("	a. Tarántula\n");
                printf("	b. Acromántula\n");  // Correcta
                printf("	c. Tarántula Goliat\n");
                printf("	d. Bagheera Kiplingi\n");

                printf ("\n");
				printf ("	RESPUESTA: ");
                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest(NivelMuyDificil.pregunta5, respuesta1, 4);
            	if(salida(Historicas, contador, Jugador, puntuacion, 29)==1){
					break;
				}
                printf ("	Tu puntuación actual es de %d puntos\n", puntuacion);
				printf ("\n\n");


                // Pregunta 30
                fflush(stdin);
                printf("  30. żQué le preguntan a Luke Garroway que colecciona después  de que Clary Fairchild le pusiera la runa sin miedo a Alec Lightwood?\n");
                printf("	a. żColeccionas arańas?\n");
                printf("	b. żTienes una arańa?\n"); //Correcta
                printf("	c. żSabes dónde hay una arańa?\n");
                printf("	d. No le preguntan nada\n");

                printf ("\n");
				printf ("	RESPUESTA: ");
                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest(NivelMuyDificil.pregunta6, respuesta1, 4);
                if(salida(Historicas, contador, Jugador, puntuacion, 30)==1){
					break;
				}
				printf ("	Tu puntuación actual es de %d puntos\n", puntuacion);
				printf ("\n\n");


                SalidaNivel(Historicas, contador, Jugador, puntuacion, 30, 0);

                Historia4();
                printf("\n\n");

            break;

		}
	}

	while (opcion!=5);
	system("cls");

printf ("F I N    D E L    J U E G O\n");
return 0;
}
