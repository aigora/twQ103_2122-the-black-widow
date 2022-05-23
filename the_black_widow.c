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
	char pregunta6 [30];
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
		puntuacion += 5;
	}
	else {
		printf ("	Respuesta incorrecta\n");
		puntuacion -= 1;
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
            fprintf (pfichero, "%s %d %d", Historicas[i].nombre, Historicas[i].puntuacion, Historicas[i].ultima_pregunta);
        }
        fprintf (pfichero, "%s %d %d", Jugador.nombre, Jugador.puntuacion, Jugador.ultima_pregunta);
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
    fprintf (pfichero, "%s %d %d", Jugador.nombre, Jugador.puntuacion, Jugador.ultima_pregunta);
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




int main() {

//ZONA DE DECLARACIÓN DE VARIABLES
	FILE*pfichero;
	int opcion,n;
	char pregunta;

	//Variable encargada de contar el numero de filas en el archivo donde se almacenan los datos históricos
	int contador=0;

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
	struct TNivelDificil NivelDificil = {'b', 'b', 'b', "aranea",'b', "inicio, arriba", 'b', 'c'};
	struct TNivelMuyDificil NivelMuyDificil = {'a', 'a', 'c', 'b', 'b', 'b'};

	//Varible para comparar cadenas
	int comparar;

	//Funcion que contiene el banner
	Banner ();



	do {

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
				printf ("\n\n");
        	break;

            case 2:
            	system("cls");
            	printf("\n");

				//Añado la información almacenada en el txt a un vector de estructuras
				pfichero=fopen ("puntuaciones.txt", "r");

				printf("	Intruduce tu nombre jugador: \n");
				printf("	NOMBRE: ");
				fflush(stdin);
				gets(Jugador.nombre);
				printf("\n");

				i=0;
				while (fscanf (pfichero, "%s %d %d", Historicas[i].nombre, &Historicas[i].puntuacion, &Historicas[i].ultima_pregunta) != EOF){
					comparar = strcmp (Jugador.nombre, Historicas[i].nombre);

					if (comparar==0) {
						Jugador.puntuacion=Historicas[i].puntuacion;
						Jugador.ultima_pregunta=Historicas[i].ultima_pregunta;
						puntuacion = Jugador.puntuacion;
					}
					contador++;
					i++;
				}
				if (comparar == 0){
					printf("	%s tienes una puntuación inicial de %d y tu última pregunta fue la %d\n", Jugador.nombre, Jugador.puntuacion, Jugador.ultima_pregunta);
				}

				fclose (pfichero);


				printf ("\n");

				printf ("	Bienvenido al juego, jugador\n");
				printf ("	(Usa una voz de villano de Disney)\n");
				printf ("	En breves te adentraras en esta terrorífica experiencia a solas\n");
				printf("\n");

            break;


            case 3:
            	system("cls");
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
                	printf ("	No ha iniciado sesión, regresa al menu principal\n");
                	printf ("\n\n");
                	break;
				}
				
                Historia();

                fflush(stdin);
                printf("	¿Estás seguro de querer adentrarte? Responde si (s) o no (n)\n");
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
                printf("  1. ¿A qué se dedicaba Aracne antes de ser convertida?\n");
                printf("	a. Tejedora\n"); // Correcta
                printf("	b. Costurera\n");
                printf("	c. Sastre\n");
                printf("	d. Diseñadora\n");
                
                printf ("\n");
				printf ("	RESPUESTA: ");
                scanf ("%c", &respuesta1);

				puntuacion += PreguntasTest (NivelFacil.pregunta1, respuesta1, 1);
				if(salida(Historicas, contador, Jugador, puntuacion, 1)==1){
                    break;
				}
				printf ("	Tu puntuación actual es de %d puntos\n", puntuacion);
				printf ("\n\n");


				// Pregunta 2
				fflush(stdin);
                printf("  2. ¿Cuál es el nombre de la actriz que interpreta a La Viuda Negra en Los Vengadores?\n");
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
                printf("  3. ¿Cómo se llama el miedo a las arañas? (Introduca una única palabra en minúsculas y sin acentos)\n");
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
                printf("  4. Realiza la clasificación taxonómica de las arañas en: reino, filo, clase\n");
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
                printf("  5. ¿En cuál reconocida organización estuvo trabajando Viuda Negra junto con otros suprehéroes?\n");
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
                printf("  7. ¿Cuántos ojos tiene una araña?\n");
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
                printf("  8. ¿Qué personaje no forma parte de Los Vengadores?\n");
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
                printf("  9. ¿En qué película de Harry Potter aparecen arañas? (Solo dos palabras)\n");
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
                printf("  10. ¿Cómo Peter Parker se convirtió en Spiderman?\n");
                printf("	a. Por comerse una araña\n");
                printf("	b. Por el mordisco de una araña\n"); //Correcta
                printf("	c. Por tocar una telaraña\n");
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
                printf("	¿Desea seguir con la aventura? Responde si (s) o no (n)\n");
                printf("	RESPUESTA: ");
                scanf("%c", &pregunta);
                if (pregunta == 'n') {
                	SalidaNivel(Historicas, contador, Jugador, puntuacion, 10, 1);
                    break;
                }
				
				
				
				//NIVEL MEDIO

                system("cls");
				printf ("	NIVEL MEDIO\n");
				printf ("\n\n");

                // Pregunta 11
                printf("\n");
                fflush(stdin);
                printf("  11. ¿De qué animal huyen las arañas en Harry Potter?\n");
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
                printf("  12. ¿Cuál es el nombre de pila de La Viuda Negra?\n");
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
                printf("  13. ¿Qué color atrae a las arañas?\n");
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
                printf("  14. ¿Cuántos años puede vivir una tarántula?\n");
                printf("	a. 34 años\n");
                printf("	b. 35 años\n");
                printf("	c. 30 años\n"); //Correcta
                printf("	d. 29 años\n");

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
                printf("  15. Nombre de la araña que picó a Fran Cuesta en 2020?\n");
                printf("	a. Tarántula\n");
                printf("	b. Viuda Negra\n");
                printf("	c. Araña Huntsman\n"); //Correcta
                printf("	d. Araña saltarina\n");

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
                printf("  16. ¿Qué tipo de araña picó a Peter Parker?\n");
                printf("	a. Araña del Banano\n");
                printf("	b. Araña lobo\n");
                printf("	c. Viuda Negra\n"); //Correcta
                printf("	d. Araña espalda roja\n");

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
                printf("	¿Desea seguir con la aventura? Responde si (s) o no (n)\n");
                printf("	RESPUESTA: ");
                scanf("%c", &pregunta);
                if (pregunta == 'n') {
                	SalidaNivel(Historicas, contador, Jugador, puntuacion, 16, 1);
                    break;
                }
                
                
                
                //NIVEL DIFÍCIL

                system("cls");
				printf ("  NIVEL DIFÍCIL\n");
				printf ("\n\n");


				// Pregunta 17
				fflush(stdin);
                printf("  17. ¿Por qué Atenea convirtió a Aracne?\n");
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
                printf("  18. ¿Cuántas familias de arañas han sido reconocidas?\n");
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
                printf("  19. ¿Qué nombre recibe la instalación donde la espía soviética apodada Viuda Negra fue entrenada?\n");
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
                printf("  20. ¿Cómo se dice araña en latín? (Solo una palabra)\n");
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
                printf("  21. En la película de Marvel sobre la Viuda Negra, ¿cómo se llama la hermana de Natasha Romanoff?\n");
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
                printf("  22. Dentro de este programa hemos escondido una araña, ¿dónde está? (Solo una palabra aunque puede haber sinónimos)\n");
                //Inicio, arriba, etc
                
                printf ("\n");
				printf ("	RESPUESTA: ");
				gets (respuesta2);

                puntuacion += PreguntasEscritas (NivelDificil.pregunta6, respuesta2, 3);
            	if(salida(Historicas, contador, Jugador, puntuacion, 22)==1){
					break;
				}
                printf ("	Tu puntuación actual es de %d puntos\n", puntuacion);
				printf ("\n\n");


                // Pregunta 23
                fflush(stdin);
                printf("  23. ¿Cuál es la araña más peligrosa del mundo?\n");
                printf("	a. Araña bañanera\n");
                printf("	b. Errante del banano\n"); //Correcta
                printf("	c. Errante de seda\n");
                printf("	d. Araña violinista\n");

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
                printf("  24. ¿Cuántas especies de arañas existen?\n");
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
                printf("	¿Desea seguir con la aventura? Responde si (s) o no (n)\n");
                printf("	RESPUESTA: ");
                scanf("%c", &pregunta);
                if (pregunta == 'n') {
                	SalidaNivel(Historicas, contador, Jugador, puntuacion, 24, 1);
                    break;
                }
                
                
                //NIVEL MUY DIFÍCIL

                system("cls");
				printf ("  NIVEL MUY DIFÍCIL\n");
				printf ("\n\n");

                // Pregunta 25
                fflush(stdin);
                printf("  25. ¿En qué se convirtió Benedict Lightwood?\n");
                printf("	a. Un gusano\n"); // Correcta
                printf("	b. Una araña\n");
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
                printf("  26. ¿Cómo se llaman las arañas cuya seda es tan resistente como una armadura? (Libro: Trono de Cristal)\n");
                printf("	a. Las arañas Stygia\n"); // Correcta
                printf("	b. No hay arañas\n");
                printf("	c. Las arañas Stigya\n");
                printf("	d. Las arañas de Stigia\n");

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
                printf("  27. ¿Cuál de estas no es un arma de Viuda Negra?\n");
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
                printf("  28. ¿Cómo se apellida el líder de la organización soviética que reclutó a la después conocida como Viuda Negra?\n");
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
                printf("  29. ¿Qué tipo de araña es Aragog?\n");
                printf("	a. Tarántula\n");
                printf("	b. Acromátula\n");  // Correcta
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
                printf("  30. ¿Qué le preguntan a Luke Garroway que colecciona después  de que Clary Fairchild le pusiera la runa sin miedo a Alec Lightwood?\n");
                printf("	a. ¿Coleccionas arañas?\n");
                printf("	b. ¿Tienes una araña?\n");
                printf("	c. ¿Sabes dónde hay una araña?\n");
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
                    


            break;
		}
	}

	while (opcion!=5);
	system("cls");

printf ("El juego ha terminado\n");
return 0;
}
