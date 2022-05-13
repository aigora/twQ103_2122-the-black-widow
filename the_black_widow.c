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

	//Informaci�n hist�rica
struct THistorica{
	char nombre[50];
	int puntuacion;
	int ultima_pregunta;

};

//FUNCIONES
	//Funci�n para las respuestas de los jugadores
int PreguntasTest (char respuesta, char solucion, int nivel) {
	int puntuacion=0, bien, mal;
	
	if (nivel == 1){
		bien = 5;
		mal = 1;
	} 
	else if (nivel == 2){
		bien = 7;
		mal = 3;
	}
	else if (nivel == 3) {
		bien = 10;
		mal = 5;
	}
	else {
		bien = 15;
		mal = 10;
	}
	
	if (respuesta==solucion) {
		printf ("Has ganado 5 puntos\n");
		puntuacion += bien;
	}
	else {
		printf ("Respuesta incorrecta\n");
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
		printf ("Has ganado 5 puntos\n");
		puntuacion += 5;
	}
	else {
		printf ("Respuesta incorrecta\n");
		puntuacion -= 1;
	}

return puntuacion;
};
	
	//Funci�n para el banner
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
	printf ("            --       -- -- -- --  	    --\n");
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

	//Funci�n para imprimir la historia inicial
void Historia1 () {
	printf("A�o 4505, el mundo tal y como lo conoc�amos ha acabado. El culpable: un virus, conocido\n");
    printf("como la Viuda Negra. No sabemos c�mo se origin� el virus, ni c�mo se transmite. Solo\n");
    printf("sabemos que se transmite muy r�pido y que en sus fases iniciales los infectados presentan una\n");
    printf("marca que parece una ara�a, y se va extendiendo en forma de l�neas como si de una telara�a se\n");
	printf("tratase hasta llegar al coraz�n. Llegado este momento, produce la muerte del contagiado.\n");
	printf("\n");
    printf("Al principio los hospitales estaban colapsados, pero ahora simplemente est�n abandonados,\n");
    printf("faltos de vida; las tiendas est�n destrozadas vac�as a excepci�n de los estantes que aun siguen\n");
    printf("all�, pero desprovistos de suministros.\n");
    printf("\n");
    printf("La poca gente que queda sin infectar se comporta de forma extra�a, son violentos, ajenos a los\n");
    printf("dem�s a excepci�n de ellos mismos; solitarios. Sin embargo, no todos hemos reaccionado igual\n");
    printf("ante la crisis, algunos hemos decidido pasar a la acci�n y buscar una cura, pero no fue tan f�cil,\n");
    printf("de hecho fue imposible. A partir de ah�, nuestra fe en encontrar la cura fue decayendo hasta\n");
    printf("que el teniente Rogers tuvo la idea de formar un peque�o grupo de selectos soldados al que\n");
    printf("denomin� La Resistencia.\n");
    printf("\n");
    printf("Vosotros sois la resistencia.\n");
    printf("\n");
    printf("Nuestro principal deber es detener la expansi�n del virus, pero antes... Ten�is que pasar una prueba.\n");
    printf("\n");
    printf("El examen consta de cuatro niveles, elaborados con el fin de medir vuestras capacidades.\n");
    printf("\n");
}




int main() {

//ZONA DE DECLARACI�N DE VARIABLES
	FILE*pfichero;
	int opcion,n;
	char pregunta;
	
	//Variable encargada de contar el numero de filas en el archivo donde se almacenan los datos hist�ricos
	int contador=0;

	//Variable para almacenar las respuestas de cada persona
	char respuesta1, respuesta2[50];

	int puntuacion=0;


	//Nos permite poner tildes
	setlocale (LC_CTYPE,"spanish");

	//Variables para bucles
	int i, j;

	//Estructura de jugadores e historica de jugadores
	struct TJugador Jugador;
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

		printf("MEN� DE OPCIONES\n");
		printf("Escriba el n�mero que representa la acci�n que desea realizar:\n");
    	printf("1. Instrucciones del juego\n");
    	printf("2. Iniciar  sesi�n\n");
    	printf("3. Ranking de puntuaciones\n");
   		printf("4. Iniciar juego\n");
    	printf("5. Salir\n");

		scanf("%d", &opcion);

		switch(opcion) {

            case 1:
            	system("cls");
                printf ("\n");
    			printf ("INSTRUCCIONES DE JUEGO\n");
        		printf("1-Pulse iniciar sesi�n e introduzca su nombre.\n");
        		printf("2-El propio programa le volver� a mostrar el men�, a continuaci�n pulse iniciar juego y disfrute de este.\n");
				printf ("\n\n");
        	break;

            case 2:
            	system("cls");
            	printf("\n");

				//A�ado la informaci�n almacenada en el txt a un vector de estructuras
				pfichero=fopen ("puntuaciones.txt", "r");

				printf ("Intruduce tu nombre jugador: \n");
				fflush(stdin);
				gets(Jugador.nombre);
				printf("\n");

				i=0;
				while (fscanf (pfichero, "%s %d %d", Historicas[i].nombre, &Historicas[i].puntuacion, &Historicas[i].ultima_pregunta) != EOF){
					comparar = strcmp (Jugador.nombre, Historicas[i].nombre);

					if (comparar==0) {
						Jugador.puntuacion=Historicas[i].puntuacion;
						Jugador.ultima_pregunta=Historicas[i].ultima_pregunta;
					}
					else {
						Jugador.puntuacion=0;
						Jugador.ultima_pregunta=0;
					}
					contador++;
					i++;
				}

				fclose (pfichero);


				printf ("\n");

				printf ("Bienvenido al juego, jugador\n");
				printf ("(Usa una voz de villano de Disney)\n");
				printf ("En breves te adentraras en esta terror�fica experiencia a solas\n");
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
                Historia1();

                fflush(stdin);
                printf("�Est�s seguro de querer adentrarte? Responde si (s) o no (n):\n");
                scanf("%c", &pregunta);
                if (pregunta == 'n') {
                    break;
                }
                system("cls");

                printf("La prueba empieza en: \n");
                printf("3\n");
                printf("2\n");
                printf("1\n");

                printf("\n\n");

                // NIVEL F�CIL

				system("cls");
				printf ("NIVEL F�CIL\n");
				printf ("\n\n");

                // Pregunta 1
                fflush(stdin);
                printf("�A qu� se dedicaba Aracne antes de ser convertida?\n");
                printf("a. Tejedora\n"); // Correcta
                printf("b. Costurera\n");
                printf("c. Sastre\n");
                printf("d. Dise�adora\n");
                scanf ("%c", &respuesta1);

				puntuacion += PreguntasTest (NivelFacil.pregunta1, respuesta1, 1);
				printf ("Tu puntuaci�n actual es de %d puntos\n", puntuacion);
				printf ("\n\n");
				
				if (puntuacion<=0){
					Jugador.ultima_pregunta = 1;
					
					pfichero = fopen ("puntuaciones.txt", "w");
					for (i=0;i<contador;i++){
						fprintf (pfichero, "%s %d %d", Historicas[i].nombre, Historicas[i].puntuacion, Historicas[i].ultima_pregunta);
					}
					fprintf (pfichero, "%s %d %d", Jugador.nombre, Jugador.puntuacion, Jugador.ultima_pregunta);
					fclose (pfichero);
					
					printf ("G A M E    O V E R");
					printf ("\n\n");
					break;
				}
				
				
				// Pregunta 2
				fflush(stdin);
                printf("�Cu�l es el nombre de la actriz que interpreta a La Viuda Negra en Los Vengadores?\n");
                printf("a. Sof�a Vergara\n");
                printf("b. Scarlett Johansson\n"); // Correcta
                printf("c. Elizabeth Olsen\n");
                printf("d. Natalie Portman\n");
                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest (NivelFacil.pregunta2, respuesta1, 1);
        		printf ("Tu puntuaci�n actual es de %d puntos\n", puntuacion);
				printf ("\n\n");
				

                // Pregunta 3
                printf ("\n");
                fflush(stdin);
                printf("�C�mo se llama el miedo a las ara�as? (Introduca una �nica palabra en min�sculas y sin acentos)\n");
                // Aracnofobia
                gets (respuesta2);

                puntuacion += PreguntasEscritas (NivelFacil.pregunta3, respuesta2, 1);
                printf ("Tu puntuaci�n actual es de %d puntos\n", puntuacion);
				printf ("\n\n");
				

                // Pregunta 4
                fflush(stdin);
                printf("Realiza la clasificaci�n taxon�mica de las ara�as en: reino, filo, clase\n");
                printf("a. Animalia - Artr�podos - Ar�nidos\n"); // Correcta
                printf("b. Ar�nidos - Moluscos - Animalia\n");
                printf("c. Artr�podos - Mam�feros - Ar�nidos\n");
                printf("d. Animalia - Mam�feros - Ar�nidos\n");

                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest (NivelFacil.pregunta4, respuesta1, 1);
				printf ("Tu puntuaci�n actual es de %d puntos\n", puntuacion);
				printf ("\n\n");
               

                // Pregunta 5
                fflush(stdin);
                printf("�En cu�l reconocida organizaci�n estuvo trabajando Viuda Negra junto con otros supreh�roes?\n");
                printf("a. S.H.I.E.L.D\n"); // Correcta
                printf("b. S.I.D\n");
                printf("c. S.I.D.E\n");
                printf("d. F.I.L.E\n");

                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest (NivelFacil.pregunta5, respuesta1, 1);
                printf ("Tu puntuaci�n actual es de %d puntos\n", puntuacion);
				printf ("\n\n");


               // Pregunta 6
                fflush(stdin);
                printf("Nombre de la escritora que public� en 2020 de la mano de Disney Libros un libro sobre el famoso personaje Viuda Negra\n");
                printf("a. Cassandra Clare\n");
                printf("b. Holly Black\n");
                printf("c. Rick Riordan\n");
                printf("d. Margaret Stohl\n"); // Correcta

                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest(NivelFacil.pregunta6, respuesta1, 1);
                printf ("Tu puntuaci�n actual es de %d puntos\n", puntuacion);
				printf ("\n\n");

                if (puntuacion<=0){
					Jugador.ultima_pregunta = 1;
					
					pfichero = fopen ("puntuaciones.txt", "w");
					for (i=0;i<contador;i++){
						fprintf (pfichero, "%s %d %d", Historicas[i].nombre, Historicas[i].puntuacion, Historicas[i].ultima_pregunta);
					}
					fprintf (pfichero, "%s %d %d", Jugador.nombre, Jugador.puntuacion, Jugador.ultima_pregunta);
					fclose (pfichero);
					
					printf ("G A M E    O V E R");
					printf ("\n\n");
					break;
				}


                // Pregunta 7
                fflush(stdin);
                printf("�Cu�ntos ojos tiene una ara�a?\n");
                printf("a. 5\n");
                printf("b. 2\n");
                printf("c. 4\n");
                printf("d. 8\n"); // Correcta

                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest(NivelFacil.pregunta7, respuesta1, 1);
				printf ("Tu puntuaci�n actual es de %d puntos\n", puntuacion);
				printf ("\n\n");

                if (puntuacion<=0){
					Jugador.ultima_pregunta = 1;
					
					pfichero = fopen ("puntuaciones.txt", "w");
					for (i=0;i<contador;i++){
						fprintf (pfichero, "%s %d %d", Historicas[i].nombre, Historicas[i].puntuacion, Historicas[i].ultima_pregunta);
					}
					fprintf (pfichero, "%s %d %d", Jugador.nombre, Jugador.puntuacion, Jugador.ultima_pregunta);
					fclose (pfichero);
					
					printf ("G A M E    O V E R");
					printf ("\n\n");
					break;
				}

                // Pregunta 8
                fflush(stdin);
                printf("�Qu� personaje no forma parte de Los Vengadores?\n");
                printf("a. Soldado de invierno\n"); // Correcta
                printf("b. Ojo de Halc�n\n");
                printf("c. Thor\n");
                printf("d. Capit�n Am�rica\n");

                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest(NivelFacil.pregunta8, respuesta1, 1);
                printf ("Tu puntuaci�n actual es de %d puntos\n", puntuacion);
				printf ("\n\n");

                if (puntuacion<=0){
					Jugador.ultima_pregunta = 1;
					
					pfichero = fopen ("puntuaciones.txt", "w");
					for (i=0;i<contador;i++){
						fprintf (pfichero, "%s %d %d", Historicas[i].nombre, Historicas[i].puntuacion, Historicas[i].ultima_pregunta);
					}
					fprintf (pfichero, "%s %d %d", Jugador.nombre, Jugador.puntuacion, Jugador.ultima_pregunta);
					fclose (pfichero);
					
					printf ("G A M E    O V E R");
					printf ("\n\n");
					break;
				}


                // Pregunta 9
                printf("\n");
                fflush(stdin);
                printf("�En qu� pel�cula de Harry Potter aparecen ara�as? (Solo dos palabras)\n");
                // C�mara Secreta
                gets (respuesta2);

                puntuacion += PreguntasEscritas (NivelFacil.pregunta9, respuesta2, 1);
                printf ("Tu puntuaci�n actual es de %d puntos\n", puntuacion);
				printf ("\n\n");

                if (puntuacion<=0){
					Jugador.ultima_pregunta = 1;
					
					pfichero = fopen ("puntuaciones.txt", "w");
					for (i=0;i<contador;i++){
						fprintf (pfichero, "%s %d %d", Historicas[i].nombre, Historicas[i].puntuacion, Historicas[i].ultima_pregunta);
					}
					fprintf (pfichero, "%s %d %d", Jugador.nombre, Jugador.puntuacion, Jugador.ultima_pregunta);
					fclose (pfichero);
					
					printf ("G A M E    O V E R");
					printf ("\n\n");
					break;
				}
				

                // Pregunta 10
                fflush(stdin);
                printf("�C�mo Peter Parker se convirti� en Spiderman?\n");
                printf("a. Por comerse una ara�a\n");
                printf("b. Por el mordisco de una ara�a\n"); //Correcta
                printf("c. Por tocar una telara�a\n");
                printf("d. Al ser maldecido por una bruja\n");

                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest(NivelFacil.pregunta10, respuesta1, 1);
                printf ("Tu puntuaci�n actual es de %d puntos\n", puntuacion);
				printf ("\n\n");

                if (puntuacion<=0){
					Jugador.ultima_pregunta = 1;
					
					pfichero = fopen ("puntuaciones.txt", "w");
					for (i=0;i<contador;i++){
						fprintf (pfichero, "%s %d %d", Historicas[i].nombre, Historicas[i].puntuacion, Historicas[i].ultima_pregunta);
					}
					fprintf (pfichero, "%s %d %d", Jugador.nombre, Jugador.puntuacion, Jugador.ultima_pregunta);
					fclose (pfichero);
					
					printf ("G A M E    O V E R");
					printf ("\n\n");
					break;
				}


                //NIVEL MEDIO
                
                system("cls");
				printf ("NIVEL MEDIO\n");
				printf ("\n\n");

                // Pregunta 11
                printf("\n");
                fflush(stdin);
                printf("�De qu� animal huyen las ara�as en Harry Potter?\n");
                printf("a. Basilisco\n"); //Correcta
                printf("b. Iguana\n");
                printf("c. Lagarto\n");
                printf("d. Cobra\n");

                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest(NivelMedio.pregunta1, respuesta1, 2);
                printf ("Tu puntuaci�n actual es de %d puntos\n", puntuacion);
				printf ("\n\n");

                if (puntuacion<=0){
					Jugador.ultima_pregunta = 1;
					
					pfichero = fopen ("puntuaciones.txt", "w");
					for (i=0;i<contador;i++){
						fprintf (pfichero, "%s %d %d", Historicas[i].nombre, Historicas[i].puntuacion, Historicas[i].ultima_pregunta);
					}
					fprintf (pfichero, "%s %d %d", Jugador.nombre, Jugador.puntuacion, Jugador.ultima_pregunta);
					fclose (pfichero);
					
					printf ("G A M E    O V E R");
					printf ("\n\n");
					break;
				}
				

                // Pregunta 12
                fflush(stdin);
                printf("�Cu�l es el nombre de pila de La Viuda Negra?\n");
                printf("a. Natasha Romanova\n");
                printf("b. Natalia Romanoff\n");
                printf("c. Natalia Romanova\n");
                printf("d. Natasha Romanoff\n"); //Correcta

                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest(NivelMedio.pregunta2, respuesta1, 2);
                printf ("Tu puntuaci�n actual es de %d puntos\n", puntuacion);
				printf ("\n\n");

                if (puntuacion<=0){
					Jugador.ultima_pregunta = 1;
					
					pfichero = fopen ("puntuaciones.txt", "w");
					for (i=0;i<contador;i++){
						fprintf (pfichero, "%s %d %d", Historicas[i].nombre, Historicas[i].puntuacion, Historicas[i].ultima_pregunta);
					}
					fprintf (pfichero, "%s %d %d", Jugador.nombre, Jugador.puntuacion, Jugador.ultima_pregunta);
					fclose (pfichero);
					
					printf ("G A M E    O V E R");
					printf ("\n\n");
					break;
				}
				

                // Pregunta 13
                fflush(stdin);
                printf("�Qu� color atrae a las ara�as?\n");
                printf("a. Rojo\n");
                printf("b. Negro\n");
                printf("c. Verde\n"); //Correcta
                printf("d. Blanco\n");

                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest(NivelMedio.pregunta3, respuesta1, 2);
                printf ("Tu puntuaci�n actual es de %d puntos\n", puntuacion);
				printf ("\n\n");

                if (puntuacion<=0){
					Jugador.ultima_pregunta = 1;
					
					pfichero = fopen ("puntuaciones.txt", "w");
					for (i=0;i<contador;i++){
						fprintf (pfichero, "%s %d %d", Historicas[i].nombre, Historicas[i].puntuacion, Historicas[i].ultima_pregunta);
					}
					fprintf (pfichero, "%s %d %d", Jugador.nombre, Jugador.puntuacion, Jugador.ultima_pregunta);
					fclose (pfichero);
					
					printf ("G A M E    O V E R");
					printf ("\n\n");
					break;
				}
				

                // Pregunta 14
                fflush(stdin);
                printf("�Cu�ntos a�os puede vivir una tar�ntula?\n");
                printf("a. 34 a�os\n");
                printf("b. 35 a�os\n");
                printf("c. 30 a�os\n"); //Correcta
                printf("d. 29 a�os\n");

                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest(NivelMedio.pregunta4, respuesta1, 2);
                printf ("Tu puntuaci�n actual es de %d puntos\n", puntuacion);
				printf ("\n\n");

                if (puntuacion<=0){
					Jugador.ultima_pregunta = 1;
					
					pfichero = fopen ("puntuaciones.txt", "w");
					for (i=0;i<contador;i++){
						fprintf (pfichero, "%s %d %d", Historicas[i].nombre, Historicas[i].puntuacion, Historicas[i].ultima_pregunta);
					}
					fprintf (pfichero, "%s %d %d", Jugador.nombre, Jugador.puntuacion, Jugador.ultima_pregunta);
					fclose (pfichero);
					
					printf ("G A M E    O V E R");
					printf ("\n\n");
					break;
				}
				

                // Pregunta 15
                fflush(stdin);
                printf("Nombre de la ara�a que pic� a Fran Cuesta en 2020?\n");
                printf("a. Tar�ntula\n");
                printf("b. Viuda Negra\n");
                printf("c. Ara�a Huntsman\n"); //Correcta
                printf("d. Ara�a saltarina\n");

                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest(NivelMedio.pregunta5, respuesta1, 2);
                printf ("Tu puntuaci�n actual es de %d puntos\n", puntuacion);
				printf ("\n\n");

                if (puntuacion<=0){
					Jugador.ultima_pregunta = 1;
					
					pfichero = fopen ("puntuaciones.txt", "w");
					for (i=0;i<contador;i++){
						fprintf (pfichero, "%s %d %d", Historicas[i].nombre, Historicas[i].puntuacion, Historicas[i].ultima_pregunta);
					}
					fprintf (pfichero, "%s %d %d", Jugador.nombre, Jugador.puntuacion, Jugador.ultima_pregunta);
					fclose (pfichero);
					
					printf ("G A M E    O V E R");
					printf ("\n\n");
					break;
				}
				

                // Pregunta 16
                fflush(stdin);
                printf("�Qu� tipo de ara�a pic� a Peter Parker?\n");
                printf("a. Ara�a del Banano\n");
                printf("b. Ara�a lobo\n");
                printf("c. Viuda Negra\n"); //Correcta
                printf("d. Ara�a espalda roja\n");

                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest(NivelMedio.pregunta6, respuesta1, 2);
                printf ("Tu puntuaci�n actual es de %d puntos\n", puntuacion);
				printf ("\n\n");

                if (puntuacion<=0){
					Jugador.ultima_pregunta = 1;
					
					pfichero = fopen ("puntuaciones.txt", "w");
					for (i=0;i<contador;i++){
						fprintf (pfichero, "%s %d %d", Historicas[i].nombre, Historicas[i].puntuacion, Historicas[i].ultima_pregunta);
					}
					fprintf (pfichero, "%s %d %d", Jugador.nombre, Jugador.puntuacion, Jugador.ultima_pregunta);
					fclose (pfichero);
					
					printf ("G A M E    O V E R");
					printf ("\n\n");
					break;
				}


                //NIVEL DIF�CIL
                
                system("cls");
				printf ("NIVEL DIF�CIL\n");
				printf ("\n\n");

				// Pregunta 17
				fflush(stdin);
                printf("�Por qu� Atenea convirti� a Aracne?\n");
                printf("a. Por desafiarla\n");
                printf("b. Por perder en una competici�n contra ella\n"); //Correcta
                printf("c. Por proponer un tema inapropiado en la conversaci�n\n");
                printf("d. Por intentar matar a uno de los hijos de Atenea\n");
                
                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest(NivelDificil.pregunta1, respuesta1, 3);
                printf ("Tu puntuaci�n actual es de %d puntos\n", puntuacion);
				printf ("\n\n");

                if (puntuacion<=0){
					Jugador.ultima_pregunta = 1;
					
					pfichero = fopen ("puntuaciones.txt", "w");
					for (i=0;i<contador;i++){
						fprintf (pfichero, "%s %d %d", Historicas[i].nombre, Historicas[i].puntuacion, Historicas[i].ultima_pregunta);
					}
					fprintf (pfichero, "%s %d %d", Jugador.nombre, Jugador.puntuacion, Jugador.ultima_pregunta);
					fclose (pfichero);
					
					printf ("G A M E    O V E R");
					printf ("\n\n");
					break;
				}
                
                
                // Pregunta 18
                fflush(stdin);
                printf("�Cu�ntas familias de ara�as han sido reconocidas?\n");
                printf("a. 221\n");
                printf("b. 110\n"); //Correcta
                printf("c. 95\n");
                printf("d. 257\n");
                
                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest(NivelDificil.pregunta2, respuesta1, 3);
                printf ("Tu puntuaci�n actual es de %d puntos\n", puntuacion);
				printf ("\n\n");

                if (puntuacion<=0){
					Jugador.ultima_pregunta = 1;
					
					pfichero = fopen ("puntuaciones.txt", "w");
					for (i=0;i<contador;i++){
						fprintf (pfichero, "%s %d %d", Historicas[i].nombre, Historicas[i].puntuacion, Historicas[i].ultima_pregunta);
					}
					fprintf (pfichero, "%s %d %d", Jugador.nombre, Jugador.puntuacion, Jugador.ultima_pregunta);
					fclose (pfichero);
					
					printf ("G A M E    O V E R");
					printf ("\n\n");
					break;
				}
                
                
                // Pregunta 19
                fflush(stdin);
                printf("�Qu� nombre recibe la instalaci�n donde la esp�a sovi�tica apodada Viuda Negra fue entrenada?\n");
                printf("a. Sala roja\n");
                printf("b. Habitaci�n roja\n"); //Correcta
                printf("c. Cuarto rojo\n");
                printf("d. Cuarto negro\n");
                
                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest(NivelDificil.pregunta3, respuesta1, 3);
                printf ("Tu puntuaci�n actual es de %d puntos\n", puntuacion);
				printf ("\n\n");

                if (puntuacion<=0){
					Jugador.ultima_pregunta = 1;
					
					pfichero = fopen ("puntuaciones.txt", "w");
					for (i=0;i<contador;i++){
						fprintf (pfichero, "%s %d %d", Historicas[i].nombre, Historicas[i].puntuacion, Historicas[i].ultima_pregunta);
					}
					fprintf (pfichero, "%s %d %d", Jugador.nombre, Jugador.puntuacion, Jugador.ultima_pregunta);
					fclose (pfichero);
					
					printf ("G A M E    O V E R");
					printf ("\n\n");
					break;
				}
                
                
                // Pregunta 20
                fflush(stdin);
                printf("�C�mo se dice ara�a en lat�n? (Solo una palabra)\n");
                //aranea
                gets (respuesta2);

                puntuacion += PreguntasEscritas (NivelDificil.pregunta4, respuesta2, 3);
                printf ("Tu puntuaci�n actual es de %d puntos\n", puntuacion);
				printf ("\n\n");

                if (puntuacion<=0){
					Jugador.ultima_pregunta = 1;
					
					pfichero = fopen ("puntuaciones.txt", "w");
					for (i=0;i<contador;i++){
						fprintf (pfichero, "%s %d %d", Historicas[i].nombre, Historicas[i].puntuacion, Historicas[i].ultima_pregunta);
					}
					fprintf (pfichero, "%s %d %d", Jugador.nombre, Jugador.puntuacion, Jugador.ultima_pregunta);
					fclose (pfichero);
					
					printf ("G A M E    O V E R");
					printf ("\n\n");
					break;
				}
                
                
                // Pregunta 21
                fflush(stdin);
                printf("En la pel�cula de Marvel sobre la Viuda Negra, �c�mo se llama la hermana de Natasha Romanoff?\n");
                printf("a. Melina Vostokoff\n");
                printf("b. Yelena Belova\n"); //Correcta
                printf("c. Alexei Shostakov\n");
                printf("d. Katia Novikov\n");
                
                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest(NivelDificil.pregunta5, respuesta1, 3);
                printf ("Tu puntuaci�n actual es de %d puntos\n", puntuacion);
				printf ("\n\n");

                if (puntuacion<=0){
					Jugador.ultima_pregunta = 1;
					
					pfichero = fopen ("puntuaciones.txt", "w");
					for (i=0;i<contador;i++){
						fprintf (pfichero, "%s %d %d", Historicas[i].nombre, Historicas[i].puntuacion, Historicas[i].ultima_pregunta);
					}
					fprintf (pfichero, "%s %d %d", Jugador.nombre, Jugador.puntuacion, Jugador.ultima_pregunta);
					fclose (pfichero);
					
					printf ("G A M E    O V E R");
					printf ("\n\n");
					break;
				}
                
                
                // Pregunta 22
                fflush(stdin);
                printf("Dentro de este programa hemos escondido una ara�a, �d�nde est�? (Solo una palabra aunque puede haber sin�nimos)\n");
                //Inicio, arriba, etc
                gets (respuesta2);

                puntuacion += PreguntasEscritas (NivelDificil.pregunta6, respuesta2, 3);
                printf ("Tu puntuaci�n actual es de %d puntos\n", puntuacion);
				printf ("\n\n");

                if (puntuacion<=0){
					Jugador.ultima_pregunta = 1;
					
					pfichero = fopen ("puntuaciones.txt", "w");
					for (i=0;i<contador;i++){
						fprintf (pfichero, "%s %d %d", Historicas[i].nombre, Historicas[i].puntuacion, Historicas[i].ultima_pregunta);
					}
					fprintf (pfichero, "%s %d %d", Jugador.nombre, Jugador.puntuacion, Jugador.ultima_pregunta);
					fclose (pfichero);
					
					printf ("G A M E    O V E R");
					printf ("\n\n");
					break;
				}
                
                
                // Pregunta 23
                fflush(stdin);
                printf("�Cu�l es la ara�a m�s peligrosa del mundo?\n");
                printf("a. Ara�a ba�anera\n");
                printf("b. Errante del banano\n"); //Correcta
                printf("c. Errante de seda\n");
                printf("d. Ara�a violinista\n");
                
                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest(NivelDificil.pregunta7, respuesta1, 3);
                printf ("Tu puntuaci�n actual es de %d puntos\n", puntuacion);
				printf ("\n\n");

                if (puntuacion<=0){
					Jugador.ultima_pregunta = 1;
					
					pfichero = fopen ("puntuaciones.txt", "w");
					for (i=0;i<contador;i++){
						fprintf (pfichero, "%s %d %d", Historicas[i].nombre, Historicas[i].puntuacion, Historicas[i].ultima_pregunta);
					}
					fprintf (pfichero, "%s %d %d", Jugador.nombre, Jugador.puntuacion, Jugador.ultima_pregunta);
					fclose (pfichero);
					
					printf ("G A M E    O V E R");
					printf ("\n\n");
					break;
				}
                
                
                // Pregunta 24
                fflush(stdin);
                printf("�Cu�ntas especies de ara�as existen?\n");
                printf("a. 47957\n");
                printf("b. 41800\n");
                printf("c. 46500\n"); //Correcta
                printf("d. 45500\n");
                
                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest(NivelDificil.pregunta8, respuesta1, 3);
                printf ("Tu puntuaci�n actual es de %d puntos\n", puntuacion);
				printf ("\n\n");

                if (puntuacion<=0){
					Jugador.ultima_pregunta = 1;
					
					pfichero = fopen ("puntuaciones.txt", "w");
					for (i=0;i<contador;i++){
						fprintf (pfichero, "%s %d %d", Historicas[i].nombre, Historicas[i].puntuacion, Historicas[i].ultima_pregunta);
					}
					fprintf (pfichero, "%s %d %d", Jugador.nombre, Jugador.puntuacion, Jugador.ultima_pregunta);
					fclose (pfichero);
					
					printf ("G A M E    O V E R");
					printf ("\n\n");
					break;
				}
                
                
                //NIVEL MUY DIF�CIL
                
                system("cls");
				printf ("NIVEL MUY DIF�CIL\n");
				printf ("\n\n");

                // Pregunta 25
                fflush(stdin);
                printf("�En qu� se convirti� Benedict Lightwood?\n");
                printf("a. Un gusano\n"); // Correcta
                printf("b. Una ara�a\n");
                printf("c. Un pato\n");
                printf("d. Un demonio\n");
                
                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest(NivelMuyDificil.pregunta1, respuesta1, 4);
                printf ("Tu puntuaci�n actual es de %d puntos\n", puntuacion);
				printf ("\n\n");

                if (puntuacion<=0){
					Jugador.ultima_pregunta = 1;
					
					pfichero = fopen ("puntuaciones.txt", "w");
					for (i=0;i<contador;i++){
						fprintf (pfichero, "%s %d %d", Historicas[i].nombre, Historicas[i].puntuacion, Historicas[i].ultima_pregunta);
					}
					fprintf (pfichero, "%s %d %d", Jugador.nombre, Jugador.puntuacion, Jugador.ultima_pregunta);
					fclose (pfichero);
					
					printf ("G A M E    O V E R");
					printf ("\n\n");
					break;
				}
                
                
                // Pregunta 26
                fflush(stdin);
                printf("�C�mo se llaman las ara�as cuya seda es tan resistente como una armadura? (Libro: Trono de Cristal)\n");
                printf("a. Las ara�as Stygia\n"); // Correcta
                printf("b. No hay ara�as\n");
                printf("c. Las ara�as Stigya\n");
                printf("d. Las ara�as de Stigia\n");
                
                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest(NivelMuyDificil.pregunta2, respuesta1, 4);
                printf ("Tu puntuaci�n actual es de %d puntos\n", puntuacion);
				printf ("\n\n");

                if (puntuacion<=0){
					Jugador.ultima_pregunta = 1;
					
					pfichero = fopen ("puntuaciones.txt", "w");
					for (i=0;i<contador;i++){
						fprintf (pfichero, "%s %d %d", Historicas[i].nombre, Historicas[i].puntuacion, Historicas[i].ultima_pregunta);
					}
					fprintf (pfichero, "%s %d %d", Jugador.nombre, Jugador.puntuacion, Jugador.ultima_pregunta);
					fclose (pfichero);
					
					printf ("G A M E    O V E R");
					printf ("\n\n");
					break;
				}
                
                
                // Pregunta 27
                fflush(stdin);
                printf("�Cu�l de estas no es un arma de Viuda Negra?\n");
                printf("a. Mordida de la viuda\n");
                printf("b. L�nea Viuda\n");
                printf("c. La caricia de la viuda\n"); // Correcta
                printf("d. EL beso de la viuda\n");
                
                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest(NivelMuyDificil.pregunta3, respuesta1, 4);
                printf ("Tu puntuaci�n actual es de %d puntos\n", puntuacion);
				printf ("\n\n");

                if (puntuacion<=0){
					Jugador.ultima_pregunta = 1;
					
					pfichero = fopen ("puntuaciones.txt", "w");
					for (i=0;i<contador;i++){
						fprintf (pfichero, "%s %d %d", Historicas[i].nombre, Historicas[i].puntuacion, Historicas[i].ultima_pregunta);
					}
					fprintf (pfichero, "%s %d %d", Jugador.nombre, Jugador.puntuacion, Jugador.ultima_pregunta);
					fclose (pfichero);
					
					printf ("G A M E    O V E R");
					printf ("\n\n");
					break;
				}
                
                
                // Pregunta 28
                fflush(stdin);
                printf("�C�omo se apellida el l�der de la organizaci�n sovi�tica que reclut� a la despu�s conocida como Viuda Negra?\n");
                printf("a. Malakov\n");
                printf("b. Dreykov\n"); // Correcta
                printf("c. Davanova\n");
                printf("d. Petrova\n");
                
                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest(NivelMuyDificil.pregunta4, respuesta1, 4);
                printf ("Tu puntuaci�n actual es de %d puntos\n", puntuacion);
				printf ("\n\n");

                if (puntuacion<=0){
					Jugador.ultima_pregunta = 1;
					
					pfichero = fopen ("puntuaciones.txt", "w");
					for (i=0;i<contador;i++){
						fprintf (pfichero, "%s %d %d", Historicas[i].nombre, Historicas[i].puntuacion, Historicas[i].ultima_pregunta);
					}
					fprintf (pfichero, "%s %d %d", Jugador.nombre, Jugador.puntuacion, Jugador.ultima_pregunta);
					fclose (pfichero);
					
					printf ("G A M E    O V E R");
					printf ("\n\n");
					break;
				}
                
                
                // Pregunta 29
                fflush(stdin);
                printf("�Qu� tipo de ara�a es Aragog?\n");
                printf("a. Tar�ntula\n");
                printf("b. Acrom�tula\n");  // Correcta
                printf("c. Tar�ntula Goliat\n");
                printf("d. Bagheera Kiplingi\n");
                
                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest(NivelMuyDificil.pregunta5, respuesta1, 4);
                printf ("Tu puntuaci�n actual es de %d puntos\n", puntuacion);
				printf ("\n\n");

                if (puntuacion<=0){
					Jugador.ultima_pregunta = 1;
					
					pfichero = fopen ("puntuaciones.txt", "w");
					for (i=0;i<contador;i++){
						fprintf (pfichero, "%s %d %d", Historicas[i].nombre, Historicas[i].puntuacion, Historicas[i].ultima_pregunta);
					}
					fprintf (pfichero, "%s %d %d", Jugador.nombre, Jugador.puntuacion, Jugador.ultima_pregunta);
					fclose (pfichero);
					
					printf ("G A M E    O V E R");
					printf ("\n\n");
					break;
				}
                
                
                // Pregunta 30
                fflush(stdin);
                printf("�Qu� le preguntan a Luke Garroway que colecciona despu�s  de que Clary Fairchild le pusiera la runa sin miedo a Alec Lightwood?\n");
                printf("a. �Coleccionas ara�as?\n");
                printf("b. �Tienes una ara�a?\n");
                printf("c. �Sabes d�nde hay una ara�a?\n");
                printf("d. No le preguntan nada\n");
                
                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest(NivelMuyDificil.pregunta6, respuesta1, 4);
                printf ("Tu puntuaci�n actual es de %d puntos\n", puntuacion);
				printf ("\n\n");

                if (puntuacion<=0){
					Jugador.ultima_pregunta = 1;
					
					pfichero = fopen ("puntuaciones.txt", "w");
					for (i=0;i<contador;i++){
						fprintf (pfichero, "%s %d %d", Historicas[i].nombre, Historicas[i].puntuacion, Historicas[i].ultima_pregunta);
					}
					fprintf (pfichero, "%s %d %d", Jugador.nombre, Jugador.puntuacion, Jugador.ultima_pregunta);
					fclose (pfichero);
					
					printf ("G A M E    O V E R");
					printf ("\n\n");
					break;
				}

				Jugador.ultima_pregunta = 1;
					
				pfichero = fopen ("puntuaciones.txt", "w");
				for (i=0;i<contador;i++){
					fprintf (pfichero, "%s %d %d", Historicas[i].nombre, Historicas[i].puntuacion, Historicas[i].ultima_pregunta);
				}
				fprintf (pfichero, "%s %d %d", Jugador.nombre, Jugador.puntuacion, Jugador.ultima_pregunta);
				fclose (pfichero);


            break;
		}
	}

	while (opcion!=5);
	system("cls");

printf ("El juego ha terminado\n");
return 0;
}
