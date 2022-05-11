#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define TAM_JUGADORES 2
#define TAM_MAX 300

//Estructuras con las soluciones a las preguntas
struct TNivelFacil {
	char pregunta1;
	char pregunta2;
	char pregunta3 [30];
	char pregunta4;
	char pregunta5;
	char pregunta6;
	char pregunta7;
	char pregunta8;
	char pregunta9 [20];
};

struct TNivelMedio {
	char pregunta1;
	char pregunta2;
	char pregunta3 [30];
	char pregunta4;
	char pregunta5;
	char pregunta6;
};

struct TNivelDificil {
	char pregunta1;
	char pregunta2;
	char pregunta3;
	char pregunta4 [30];
	char pregunta5;
	char pregunta6 [30];
	char pregunta7;
	char pregunta8;
};


//Estructura con la informacion de los jugadores
struct TJugador{
	char nombre[50];
	int puntuacion;
	int ultima_pregunta;

};

//Estructura histórica
struct THistorica{
	char nombre[50];
	int puntuacion;
	int ultima_pregunta;

};

//Función para las respuestas de los jugadores

int PreguntasTest (char respuesta, char solucion) {
	int puntuacion=0;
	
	if (respuesta==solucion) {
		printf ("Has ganado 5 puntos\n");
		puntuacion += 5;
	}
	else {
		printf ("Respuesta incorrecta\n");
		puntuacion -= 1;
	}
	
	
return puntuacion;
};

int PreguntasEscritas (char respuesta[], char solucion[]){
	int comparar, puntuacion=0;
	
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

//Función para imprimir la historia inicial
void Historia1 () {
	printf("Año 4505, el mundo tal y como lo conocíamos ha acabado. El culpable: un virus, conocido\n");
    printf("como la Viuda Negra. No sabemos cómo se originó el virus, ni cómo se transmite. Solo\n");
    printf("sabemos que se transmite muy rápido y que en sus fases iniciales los infectados presentan una\n");
    printf("marca que parece una araña, y se va extendiendo en forma de líneas como si de una telaraña se\n");
	printf("tratase hasta llegar al corazón. Llegado este momento, produce la muerte del contagiado.\n");
	printf("\n");
    printf("Al principio los hospitales estaban colapsados, pero ahora simplemente están abandonados,\n");
    printf("faltos de vida; las tiendas están destrozadas vacías a excepción de los estantes que aun siguen\n");
    printf("allí, pero desprovistos de suministros.\n");
    printf("\n");
    printf("La poca gente que queda sin infectar se comporta de forma extraña, son violentos, ajenos a los\n");
    printf("demás a excepción de ellos mismos; solitarios. Sin embargo, no todos hemos reaccionado igual\n");
    printf("ante la crisis, algunos hemos decidido pasar a la acción y buscar una cura, pero no fue tan fácil,\n");
    printf("de hecho fue imposible. A partir de ahí, nuestra fe en encontrar la cura fue decayendo hasta\n");
    printf("que el teniente Rogers tuvo la idea de formar un pequeño grupo de selectos soldados al que\n");
    printf("denominó La Resistencia.\n");
    printf("\n");
    printf("Vosotros sois la resistencia.\n");
    printf("\n");
    printf("Nuestro principal deber es detener la expansión del virus, pero antes... Tenéis que pasar una prueba.\n");
    printf("\n");
    printf("El examen consta de cuatro niveles, elaborados con el fin de medir vuestras capacidades.\n");
    printf("\n");
}


int main() {
	
    //ZONA DE DECLARACIÓN DE VARIABLES
	FILE*pfichero; 
	int opcion,n;
	char pregunta;
	
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
	struct TNivelFacil NivelFacil = {'a', 'b', "aracnofobia", 'a', 'a', 'd', 'd', 'a', "camara secreta"};
	struct TNivelMedio NivelMedio = {'a', 'd', 'c', 'c', 'c', 'c'};
	
	//Varible para comparar cadenas
	int comparar;

	//Funcion que contiene el banner
	Banner ();



	do {

		printf("MENÚ DE OPCIONES\n");
		printf("Escriba el número que representa la acción que desea realizar:\n");
    	printf("1. Instrucciones del juego\n");
    	printf("2. Iniciar  sesión\n");
    	printf("3. Ranking de puntuaciones\n");
   		printf("4. Iniciar juego\n");
    	printf("5. Salir\n");

		scanf("%d", &opcion);

		switch(opcion) {

            case 1:
            	system("cls");
                printf ("\n");
    			printf ("INSTRUCCIONES DE JUEGO\n");
        		printf("1-Pulse iniciar sesi%cn e introduzca su nombre.\n");
        		printf("2-El propio programa le volverá a mostrar el menú, a continuación pulse iniciar juego y disfrute de este.\n");
				printf ("\n");
				printf ("\n");
        	break;

            case 2:
            	system("cls");
            	printf("\n");
				
				//Añado la información almacenada en el txt a un vector de estructuras
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
					i++;
				}
				
				fclose (pfichero);
				
				
				printf ("\n");
	
				printf ("Bienvenido al juego, jugador\n");
				printf ("(Usa una voz de villano de Disney)\n");
				printf ("En breves te adentraras en esta terrorífica experiencia a solas\n");
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

            break;

            case 4:
            	//Hay que meter un mensaje que indique que si la persona no ha iniaciado sesión se salga 
            	//Se me ha ocurrido que podemos inicializar el nombre del jugador como un asterisco y si el nombre al llegar aquí sigue siendo * entonces meto un break
            	
                system("cls");
                Historia1();

                fflush(stdin);
                printf("¿Estás seguro de querer adentrarte? Responde si (s) o no (n):\n");
                scanf("%c", &pregunta);
                if (pregunta == 'n') {
                    break;
                }
                system("cls");

                printf("La prueba empieza en: \n");
                printf("3\n");
                printf("2\n");
                printf("1\n");

                printf("\n \n");
                
                //Si queremos hacer lo de q se salga si la puntuación es cero habria que meter un bucle do while

                // NIVEL FÁCIL

				system("cls");
				printf ("NIVEL FÁCIL\n");
				
                // Pregunta 1
                fflush(stdin);
                printf("¿A qué se dedicaba Aracne antes de ser convertida?\n");
                printf("a. Tejedora\n"); // Correcta
                printf("b. Costurera\n");
                printf("c. Sastre\n");
                printf("d. Diseñadora\n");
                
                scanf ("%c", &respuesta1);
				
				puntuacion += PreguntasTest (NivelFacil.pregunta1, respuesta1);
				
				// Pregunta 2
				fflush(stdin);
                printf("¿Cuál es el nombre de la actriz que interpreta a La Viuda Negra en Los Vengadores?\n");
                printf("a. Sofía Vergara\n");
                printf("b. Scarlett Johansson\n"); // Correcta
                printf("c. Elizabeth Olsen\n");
                printf("d. Natalie Portman\n");
                
                scanf ("%c", &respuesta1);
                
                puntuacion += PreguntasTest (NivelFacil.pregunta2, respuesta1);
                
                printf ("%d\n", puntuacion);
                
                // Pregunta 3
                printf ("\n");
                fflush(stdin);
                printf("¿Cómo se llama el miedo a las arañas? (Introduca una única palabra en minúsculas y sin acentos)\n");
                // Aracnofobia
                gets (respuesta2);
                
                puntuacion += PreguntasEscritas (NivelFacil.pregunta3, respuesta2);
                printf ("%d\n", puntuacion);
                
                // Pregunta 4
                printf("Realiza la clasificación taxonómica de las arañas en: reino, filo, clase\n");
                printf("a. Animalia - Artrópodos - Aránidos\n"); // Correcta
                printf("b. Aránidos - Moluscos - Animalia\n");
                printf("c. Artrópodos - Mamíferos - Aránidos\n");
                printf("d. Animalia - Mamíferos - Aránidos\n");
                
                scanf ("%c", &respuesta1);
                
                puntuacion += PreguntasTest (NivelFacil.pregunta4, respuesta1);
				
				
            break;
		}
	}

	while (opcion!=5);
	system("cls");

printf ("El juego ha terminado\n");
return 0;
}


