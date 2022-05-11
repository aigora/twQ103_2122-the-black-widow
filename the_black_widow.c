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
	
	printf ("%d\n", puntuacion);
	
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



int main() {
    FILE*pfichero;
	int opcion,n;
	char pregunta;
	char respuesta;

	
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
	
	//Defino variables ligadas a las vocales con tilde
	char a=160, e=130, it=161, o=162, u=163, aa=181, ee=144 , ii=214 , oo=224 , uu=233;
	char interrogacion=168;
	char enne=164;
	
	//Varible para comparar cadenas
	int comparar;

	//Funcion que contiene el banner
	Banner ();

	do {

		printf("MEN%c DE OPCIONES\n", uu);
		printf("Escriba el n%cmero que representa la acci%cn que desea realizar:\n", u, o);
    	printf("1. Instrucciones del juego\n");
    	printf("2. Iniciar  sesi%cn\n", o);
    	printf("3. Ranking de puntuaciones\n");
   		printf("4. Iniciar juego\n");
    	printf("5. Salir\n");

		scanf("%d", &opcion);

		switch(opcion) {

            case 1:
            	system("cls");
                printf ("\n");
    			printf ("INSTRUCCIONES DE JUEGO\n");
        		printf("1-Pulse iniciar sesi%cn e introduzca su nombre.\n", o);
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
				printf ("En breves te adentraras en esta terror%cfica experiencia a solas\n", it);
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
                system("cls");
                printf("A%co 4505, el mundo tal y como lo conoc%camos ha acabado. El culpable: un virus, conocido\n", enne, it);
                printf("como la Viuda Negra. No sabemos c%cmo se origin%c el virus, ni c%cmo se transmite. S%clo\n", o, o, o, o);
                printf("sabemos que se transmite muy r%cpido y que en sus fases iniciales los infectados presentan una\n", a);
                printf("marca que parece una ara%ca, y se va extendiendo en forma de l%cneas como si de una telara%ca se\n", enne, it, enne);
                printf("tratase hasta llegar al coraz%cn. Llegado este momento, produce la muerte del contagiado.\n", o);
                printf("\n");
                printf("Al principio los hospitales estaban colapsados, pero ahora simplemente est%cn abandonados,\n", a);
                printf("faltos de vida; las tiendas est%cn destrozadas vac%cas a excepci%cn de los estantes que aun siguen\n", a, it, o);
                printf("all%c, pero desprovistos de suministros.\n", it);
                printf("\n");
                printf("La poca gente que queda sin infectar se comporta de forma extraña, son violentos, ajenos a los\n");
                printf("dem%cs a excepci%cn de ellos mismos; solitarios. Sin embargo, no todos hemos reaccionado igual\n", a, o);
                printf("ante la crisis, algunos hemos decidido pasar a la acci%cn y buscar una cura, pero no fue tan f%ccil,\n", o, a);
                printf("de hecho fue imposible. A partir de ah%c, nuestra fe en encontrar la cura fue decayendo hasta\n", it);
                printf("que el teniente Rogers tuvo la idea de formar un peque%co grupo de selectos soldados al que\n", enne);
                printf("denomin%c La Resistencia.\n", o);
                printf("\n");
                printf("Vosotros sois la resistencia.\n");
                printf("\n");
                printf("Nuestro principal deber es detener la expansi%cn del virus, pero antes... Ten%cis que pasar una prueba.\n", o, e);
                printf("\n");
                printf("El examen consta de cuatro niveles, elaborados con el fin de medir vuestras capacidades.\n");
                printf("\n");

                fflush(stdin);
                printf("%cEst%cs seguro de querer adentrarte? Responde si (s) o no (n):\n", interrogacion, a);
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

                // NIVEL FÁCIL

				system("cls");
				printf ("NIVEL F%cCIL\n", aa);
				
                // Pregunta 1
                fflush(stdin);
                printf("%cA qu%c se dedicaba Aracne antes de ser convertida?\n", interrogacion, e);
                printf("a. Tejedora\n"); // Correcta
                printf("b. Costurera\n");
                printf("c. Sastre\n");
                printf("d. Dise%cadora\n", enne);
                
                scanf ("%c", &respuesta);
				
				Jugador.puntuacion += PreguntasTest (NivelFacil.pregunta1, respuesta);

            break;
		}
	}

	while (opcion!=5);
	system("cls");

printf ("El juego ha terminado\n");
return 0;
}


