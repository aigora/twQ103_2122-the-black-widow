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

    //Funci�n salir del juego
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


   //Funci�n historia en fichero
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

		printf("	MEN� DE OPCIONES\n");
		printf("	Escriba el n�mero que representa la acci�n que desea realizar:\n");
    	printf("	1. Instrucciones del juego\n");
    	printf("	2. Iniciar  sesi�n\n");
    	printf("	3. Ranking de puntuaciones\n");
   		printf("	4. Iniciar juego\n");
    	printf("	5. Salir\n\n");
		
		printf("	OPCI�N: ");
		scanf("%d", &opcion);
		
		switch(opcion) {

            case 1:
            	system("cls");
                printf ("\n");
    			printf ("	INSTRUCCIONES DE JUEGO\n");
        		printf("	1-Pulse iniciar sesi�n e introduzca su nombre.\n");
        		printf("	2-El propio programa le volver� a mostrar el men�, a continuaci�n pulse iniciar juego y disfrute de este.\n");
				printf ("\n\n");
        	break;

            case 2:
            	system("cls");
            	printf("\n");

				//A�ado la informaci�n almacenada en el txt a un vector de estructuras
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
					printf("	%s tienes una puntuaci�n inicial de %d y tu �ltima pregunta fue la %d\n", Jugador.nombre, Jugador.puntuacion, Jugador.ultima_pregunta);
				}

				fclose (pfichero);


				printf ("\n");

				printf ("	Bienvenido al juego, jugador\n");
				printf ("	(Usa una voz de villano de Disney)\n");
				printf ("	En breves te adentraras en esta terror�fica experiencia a solas\n");
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
                	printf ("	No ha iniciado sesi�n, regresa al menu principal\n");
                	printf ("\n\n");
                	break;
				}
				
                Historia();

                fflush(stdin);
                printf("	�Est�s seguro de querer adentrarte? Responde si (s) o no (n)\n");
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



                // NIVEL F�CIL

				printf ("	NIVEL F�CIL\n");
				printf ("\n\n");

                // Pregunta 1
                fflush(stdin);
                printf("  1. �A qu� se dedicaba Aracne antes de ser convertida?\n");
                printf("	a. Tejedora\n"); // Correcta
                printf("	b. Costurera\n");
                printf("	c. Sastre\n");
                printf("	d. Dise�adora\n");
                
                printf ("\n");
				printf ("	RESPUESTA: ");
                scanf ("%c", &respuesta1);

				puntuacion += PreguntasTest (NivelFacil.pregunta1, respuesta1, 1);
				if(salida(Historicas, contador, Jugador, puntuacion, 1)==1){
                    break;
				}
				printf ("	Tu puntuaci�n actual es de %d puntos\n", puntuacion);
				printf ("\n\n");


				// Pregunta 2
				fflush(stdin);
                printf("  2. �Cu�l es el nombre de la actriz que interpreta a La Viuda Negra en Los Vengadores?\n");
                printf("	a. Sof�a Vergara\n");
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
        		printf ("	Tu puntuaci�n actual es de %d puntos\n", puntuacion);
				printf ("\n\n");
				
				
				// Pregunta 3
                printf ("\n");
                fflush(stdin);
                printf("  3. �C�mo se llama el miedo a las ara�as? (Introduca una �nica palabra en min�sculas y sin acentos)\n");
                // Aracnofobia
                
                printf ("\n");
				printf ("	RESPUESTA: ");
                gets (respuesta2);

                puntuacion += PreguntasEscritas (NivelFacil.pregunta3, respuesta2, 1);
                if(salida(Historicas, contador, Jugador, puntuacion, 3)==1){
					break;
				}
				fflush(stdin);
                printf ("	Tu puntuaci�n actual es de %d puntos\n", puntuacion);
				printf ("\n\n");


                // Pregunta 4
                fflush(stdin);
                printf("  4. Realiza la clasificaci�n taxon�mica de las ara�as en: reino, filo, clase\n");
                printf("	a. Animalia - Artr�podos - Ar�nidos\n"); // Correcta
                printf("	b. Ar�nidos - Moluscos - Animalia\n");
                printf("	c. Artr�podos - Mam�feros - Ar�nidos\n");
                printf("	d. Animalia - Mam�feros - Ar�nidos\n");

                printf ("\n");
				printf ("	RESPUESTA: ");
                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest (NivelFacil.pregunta4, respuesta1, 1);
                if(salida(Historicas, contador, Jugador, puntuacion, 4)==1){
					break;
				}
				printf ("	Tu puntuaci�n actual es de %d puntos\n", puntuacion);
				printf ("\n\n");


                // Pregunta 5
                fflush(stdin);
                printf("  5. �En cu�l reconocida organizaci�n estuvo trabajando Viuda Negra junto con otros supreh�roes?\n");
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
                printf ("	Tu puntuaci�n actual es de %d puntos\n", puntuacion);
				printf ("\n\n");


               // Pregunta 6
                fflush(stdin);
                printf("  6. Nombre de la escritora que public� en 2020 de la mano de Disney Libros un libro sobre el famoso personaje Viuda Negra\n");
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
                printf ("	Tu puntuaci�n actual es de %d puntos\n", puntuacion);
				printf ("\n\n");


                // Pregunta 7
                fflush(stdin);
                printf("  7. �Cu�ntos ojos tiene una ara�a?\n");
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
				printf ("	Tu puntuaci�n actual es de %d puntos\n", puntuacion);
				printf ("\n\n");


                // Pregunta 8
                fflush(stdin);
                printf("  8. �Qu� personaje no forma parte de Los Vengadores?\n");
                printf("	a. Soldado de invierno\n"); // Correcta
                printf("	b. Ojo de Halc�n\n");
                printf("	c. Thor\n");
                printf("	d. Capit�n Am�rica\n");

                printf ("\n");
				printf ("	RESPUESTA: ");
                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest(NivelFacil.pregunta8, respuesta1, 1);
                if(salida(Historicas, contador, Jugador, puntuacion, 8)==1){
					break;
				}
                printf ("	Tu puntuaci�n actual es de %d puntos\n", puntuacion);
				printf ("\n\n");


                // Pregunta 9
                printf("\n");
                fflush(stdin);
                printf("  9. �En qu� pel�cula de Harry Potter aparecen ara�as? (Solo dos palabras)\n");
                // C�mara Secreta
                
                printf ("\n");
				printf ("	RESPUESTA: ");
                gets (	  respuesta2);

                puntuacion += PreguntasEscritas (NivelFacil.pregunta9, respuesta2, 1);
                if(salida(Historicas, contador, Jugador, puntuacion, 9)==1){
					break;
				}
                printf ("	Tu puntuaci�n actual es de %d puntos\n", puntuacion);
				printf ("\n\n");


                // Pregunta 10
                fflush(stdin);
                printf("  10. �C�mo Peter Parker se convirti� en Spiderman?\n");
                printf("	a. Por comerse una ara�a\n");
                printf("	b. Por el mordisco de una ara�a\n"); //Correcta
                printf("	c. Por tocar una telara�a\n");
                printf("	d. Al ser maldecido por una bruja\n");

                printf ("\n");
				printf ("	RESPUESTA: ");
                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest(NivelFacil.pregunta10, respuesta1, 10);
                if(salida(Historicas, contador, Jugador, puntuacion, 10)==1){
					break;
				}
                printf ("	Tu puntuaci�n actual es de %d puntos\n", puntuacion);
				printf ("\n\n");
				
				
				//Opci�n para salir del c�digo
				fflush(stdin);
                printf("	�Desea seguir con la aventura? Responde si (s) o no (n)\n");
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
                printf("  11. �De qu� animal huyen las ara�as en Harry Potter?\n");
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
                printf ("	Tu puntuaci�n actual es de %d puntos\n", puntuacion);
				printf ("\n\n");


                // Pregunta 12
                fflush(stdin);
                printf("  12. �Cu�l es el nombre de pila de La Viuda Negra?\n");
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
                printf ("	Tu puntuaci�n actual es de %d puntos\n", puntuacion);
				printf ("\n\n");


                // Pregunta 13
                fflush(stdin);
                printf("  13. �Qu� color atrae a las ara�as?\n");
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
                printf ("	Tu puntuaci�n actual es de %d puntos\n", puntuacion);
				printf ("\n\n");


                // Pregunta 14
                fflush(stdin);
                printf("  14. �Cu�ntos a�os puede vivir una tar�ntula?\n");
                printf("	a. 34 a�os\n");
                printf("	b. 35 a�os\n");
                printf("	c. 30 a�os\n"); //Correcta
                printf("	d. 29 a�os\n");

                printf ("\n");
				printf ("	RESPUESTA: ");
                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest(NivelMedio.pregunta4, respuesta1, 2);
                if(salida(Historicas, contador, Jugador, puntuacion, 14)==1){
					break;
				}
                printf ("	Tu puntuaci�n actual es de %d puntos\n", puntuacion);
				printf ("\n\n");


                // Pregunta 15
                fflush(stdin);
                printf("  15. Nombre de la ara�a que pic� a Fran Cuesta en 2020?\n");
                printf("	a. Tar�ntula\n");
                printf("	b. Viuda Negra\n");
                printf("	c. Ara�a Huntsman\n"); //Correcta
                printf("	d. Ara�a saltarina\n");

                printf ("\n");
				printf ("	RESPUESTA: ");
                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest(NivelMedio.pregunta5, respuesta1, 2);
                if(salida(Historicas, contador, Jugador, puntuacion, 15)==1){
					break;
				}
                printf ("	Tu puntuaci�n actual es de %d puntos\n", puntuacion);
				printf ("\n\n");


                // Pregunta 16
                fflush(stdin);
                printf("  16. �Qu� tipo de ara�a pic� a Peter Parker?\n");
                printf("	a. Ara�a del Banano\n");
                printf("	b. Ara�a lobo\n");
                printf("	c. Viuda Negra\n"); //Correcta
                printf("	d. Ara�a espalda roja\n");

                printf ("\n");
				printf ("	RESPUESTA: ");
                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest(NivelMedio.pregunta6, respuesta1, 2);
            	if(salida(Historicas, contador, Jugador, puntuacion, 16)==1){
					break;
				}
                printf ("	Tu puntuaci�n actual es de %d puntos\n", puntuacion);
				printf ("\n\n");
				
				
				//Opci�n para salir del c�digo
				fflush(stdin);
                printf("	�Desea seguir con la aventura? Responde si (s) o no (n)\n");
                printf("	RESPUESTA: ");
                scanf("%c", &pregunta);
                if (pregunta == 'n') {
                	SalidaNivel(Historicas, contador, Jugador, puntuacion, 16, 1);
                    break;
                }
                
                
                
                //NIVEL DIF�CIL

                system("cls");
				printf ("  NIVEL DIF�CIL\n");
				printf ("\n\n");


				// Pregunta 17
				fflush(stdin);
                printf("  17. �Por qu� Atenea convirti� a Aracne?\n");
                printf("	a. Por desafiarla\n");
                printf("	b. Por perder en una competici�n contra ella\n"); //Correcta
                printf("	c. Por proponer un tema inapropiado en la conversaci�n\n");
                printf("	d. Por intentar matar a uno de los hijos de Atenea\n");

                printf ("\n");
				printf ("	RESPUESTA: ");
                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest(NivelDificil.pregunta1, respuesta1, 3);
                if(salida(Historicas, contador, Jugador, puntuacion, 17)==1){
					break;
				}
                printf ("	Tu puntuaci�n actual es de %d puntos\n", puntuacion);
				printf ("\n\n");


                // Pregunta 18
                fflush(stdin);
                printf("  18. �Cu�ntas familias de ara�as han sido reconocidas?\n");
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
                printf ("	Tu puntuaci�n actual es de %d puntos\n", puntuacion);
				printf ("\n\n");


                // Pregunta 19
                fflush(stdin);
                printf("  19. �Qu� nombre recibe la instalaci�n donde la esp�a sovi�tica apodada Viuda Negra fue entrenada?\n");
                printf("	a. Sala roja\n");
                printf("	b. Habitaci�n roja\n"); //Correcta
                printf("	c. Cuarto rojo\n");
                printf("	d. Cuarto negro\n");

                printf ("\n");
				printf ("	RESPUESTA: ");
                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest(NivelDificil.pregunta3, respuesta1, 3);
                if(salida(Historicas, contador, Jugador, puntuacion, 19)==1){
					break;
				}
                printf ("	Tu puntuaci�n actual es de %d puntos\n", puntuacion);
				printf ("\n\n");


                // Pregunta 20
                fflush(stdin);
                printf("  20. �C�mo se dice ara�a en lat�n? (Solo una palabra)\n");
                //aranea
                
                printf ("\n");
				printf ("	RESPUESTA: ");
				gets (respuesta2);

                puntuacion += PreguntasEscritas (NivelDificil.pregunta4, respuesta2, 3);
            	if(salida(Historicas, contador, Jugador, puntuacion, 20)==1){
					break;
				}
                printf ("	Tu puntuaci�n actual es de %d puntos\n", puntuacion);
				printf ("\n\n");


                // Pregunta 21
                fflush(stdin);
                printf("  21. En la pel�cula de Marvel sobre la Viuda Negra, �c�mo se llama la hermana de Natasha Romanoff?\n");
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
                printf ("	Tu puntuaci�n actual es de %d puntos\n", puntuacion);
				printf ("\n\n");


                // Pregunta 22
                fflush(stdin);
                printf("  22. Dentro de este programa hemos escondido una ara�a, �d�nde est�? (Solo una palabra aunque puede haber sin�nimos)\n");
                //Inicio, arriba, etc
                
                printf ("\n");
				printf ("	RESPUESTA: ");
				gets (respuesta2);

                puntuacion += PreguntasEscritas (NivelDificil.pregunta6, respuesta2, 3);
            	if(salida(Historicas, contador, Jugador, puntuacion, 22)==1){
					break;
				}
                printf ("	Tu puntuaci�n actual es de %d puntos\n", puntuacion);
				printf ("\n\n");


                // Pregunta 23
                fflush(stdin);
                printf("  23. �Cu�l es la ara�a m�s peligrosa del mundo?\n");
                printf("	a. Ara�a ba�anera\n");
                printf("	b. Errante del banano\n"); //Correcta
                printf("	c. Errante de seda\n");
                printf("	d. Ara�a violinista\n");

                printf ("\n");
				printf ("	RESPUESTA: ");
                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest(NivelDificil.pregunta7, respuesta1, 3);
            	if(salida(Historicas, contador, Jugador, puntuacion, 23)==1){
					break;
				}
                printf ("	Tu puntuaci�n actual es de %d puntos\n", puntuacion);
				printf ("\n\n");


                // Pregunta 24
                fflush(stdin);
                printf("  24. �Cu�ntas especies de ara�as existen?\n");
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
                printf ("	Tu puntuaci�n actual es de %d puntos\n", puntuacion);
				printf ("\n\n");
				
				
				//Opci�n para salir del c�digo
				fflush(stdin);
                printf("	�Desea seguir con la aventura? Responde si (s) o no (n)\n");
                printf("	RESPUESTA: ");
                scanf("%c", &pregunta);
                if (pregunta == 'n') {
                	SalidaNivel(Historicas, contador, Jugador, puntuacion, 24, 1);
                    break;
                }
                
                
                //NIVEL MUY DIF�CIL

                system("cls");
				printf ("  NIVEL MUY DIF�CIL\n");
				printf ("\n\n");

                // Pregunta 25
                fflush(stdin);
                printf("  25. �En qu� se convirti� Benedict Lightwood?\n");
                printf("	a. Un gusano\n"); // Correcta
                printf("	b. Una ara�a\n");
                printf("	c. Un pato\n");
                printf("	d. Un demonio\n");

                printf ("\n");
				printf ("	RESPUESTA: ");
                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest(NivelMuyDificil.pregunta1, respuesta1, 4);
            	if(salida(Historicas, contador, Jugador, puntuacion, 25)==1){
					break;
				}
                printf ("	Tu puntuaci�n actual es de %d puntos\n", puntuacion);
				printf ("\n\n");


                // Pregunta 26
                fflush(stdin);
                printf("  26. �C�mo se llaman las ara�as cuya seda es tan resistente como una armadura? (Libro: Trono de Cristal)\n");
                printf("	a. Las ara�as Stygia\n"); // Correcta
                printf("	b. No hay ara�as\n");
                printf("	c. Las ara�as Stigya\n");
                printf("	d. Las ara�as de Stigia\n");

                printf ("\n");
				printf ("	RESPUESTA: ");
                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest(NivelMuyDificil.pregunta2, respuesta1, 4);
            	if(salida(Historicas, contador, Jugador, puntuacion, 26)==1){
					break;
				}
                printf ("	Tu puntuaci�n actual es de %d puntos\n", puntuacion);
				printf ("\n\n");


                // Pregunta 27
                fflush(stdin);
                printf("  27. �Cu�l de estas no es un arma de Viuda Negra?\n");
                printf("	a. Mordida de la viuda\n");
                printf("	b. L�nea Viuda\n");
                printf("	c. La caricia de la viuda\n"); // Correcta
                printf("	d. El beso de la viuda\n");

                printf ("\n");
				printf ("	RESPUESTA: ");
                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest(NivelMuyDificil.pregunta3, respuesta1, 4);
               	if(salida(Historicas, contador, Jugador, puntuacion, 27)==1){
					break;
				}
                printf ("	Tu puntuaci�n actual es de %d puntos\n", puntuacion);
				printf ("\n\n");


                // Pregunta 28
                fflush(stdin);
                printf("  28. �C�mo se apellida el l�der de la organizaci�n sovi�tica que reclut� a la despu�s conocida como Viuda Negra?\n");
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
                printf ("	Tu puntuaci�n actual es de %d puntos\n", puntuacion);
				printf ("\n\n");


                // Pregunta 29
                fflush(stdin);
                printf("  29. �Qu� tipo de ara�a es Aragog?\n");
                printf("	a. Tar�ntula\n");
                printf("	b. Acrom�tula\n");  // Correcta
                printf("	c. Tar�ntula Goliat\n");
                printf("	d. Bagheera Kiplingi\n");

                printf ("\n");
				printf ("	RESPUESTA: ");
                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest(NivelMuyDificil.pregunta5, respuesta1, 4);
            	if(salida(Historicas, contador, Jugador, puntuacion, 29)==1){
					break;
				}
                printf ("	Tu puntuaci�n actual es de %d puntos\n", puntuacion);
				printf ("\n\n");


                // Pregunta 30
                fflush(stdin);
                printf("  30. �Qu� le preguntan a Luke Garroway que colecciona despu�s  de que Clary Fairchild le pusiera la runa sin miedo a Alec Lightwood?\n");
                printf("	a. �Coleccionas ara�as?\n");
                printf("	b. �Tienes una ara�a?\n");
                printf("	c. �Sabes d�nde hay una ara�a?\n");
                printf("	d. No le preguntan nada\n");

                printf ("\n");
				printf ("	RESPUESTA: ");
                scanf ("%c", &respuesta1);

                puntuacion += PreguntasTest(NivelMuyDificil.pregunta6, respuesta1, 4);
                if(salida(Historicas, contador, Jugador, puntuacion, 30)==1){
					break;
				}
				printf ("	Tu puntuaci�n actual es de %d puntos\n", puntuacion);
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
