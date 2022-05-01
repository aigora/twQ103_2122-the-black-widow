#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 2

struct TJugador{
	char nombre[50];
	float puntuacion;

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



int main() {
    FILE*pfichero;
    struct TJugador Jugadores[TAM_MAX];
	int opcion,n,i;
	char modo_juego,respuesta;

	//Defino variables ligadas a las vocales con tilde
	char a=160, e=130, it=161, o=162, u=163, aa=181, ee=144 , ii=214 , oo=224 , uu=233;

	//Extraer el banner a una funci�n para que sea m�s claro
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
        		printf("1-Pulse iniciar sesi%cn y a continuaci%cn seleccione si quiere jugar de forma individual o multijugador, e introduzca el nombre de los participantes.\n", o, o);
        		printf("El propio programa le volver%c a mostrar el men%c\n", a, u);
        		printf("2-Pulse iniciar juego y disfrute de este.\n");
				printf ("\n");
				printf ("\n");
        	break;

            case 2:
            	system("cls");
            	printf("\n");
				printf ("%cC%cmo deseas jugar?\n",168, o);
				printf ("A. Individual\n");
				printf ("B. Multijugador\n"); //Habr� un m�ximo de tres jugadores
				fflush(stdin);
				scanf ("%c", &modo_juego);

				if (modo_juego=='a'||modo_juego=='A'){
					printf("\n");
					n=1;
				}

				else if (modo_juego=='b'||modo_juego=='B'){
					printf("%cCu%cntos jugadores sois?\n",168, a);
					scanf("%d", &n);
				}

				for (i=1;i<=n;i++){
					printf("\n");
					printf ("Intruduce tu nombre\n");
					fflush(stdin);
					gets(Jugadores[i].nombre);
					printf("\n");
				}

				if (n==1) {
					printf ("Bienvenido al juego, jugador\n");
					printf ("En breves te adentraras en esta terror%cfica experiencia a solas\n", it);
					printf("\n");
				}
				else {
					printf ("Bienvenidos al juego, juegadores\n");
					printf ("Sabia decisi%cn no adentrarse a solas en esta experiencia\n",o);
					printf("\n");
				}

            break;


            case 3:
            	system("cls");
                pfichero = fopen ("puntuaciones.txt", "r");
                if (pfichero == NULL) {
                    printf ("Error en la apertura del fichero\n");
                    return 0;
                }
                i=0;
                while (fscanf(pfichero, "%s %f",Jugadores[i].nombre, &Jugadores[i].puntuacion) != EOF) {
                    printf("%s %f\n", Jugadores[i].nombre, &Jugadores[i].puntuacion);
                    i++;
                }
                printf("\n");

            break;

            case 4:
                system("cls");
                printf("A�o 4505, el mundo tal y como lo conoc�amos ha acabado. El culpable: un virus, conocido\n");
                printf("como la Viuda Negra. No sabemos c�mo se origin� el virus, ni c�mo se transmite. S�lo\n");
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

                fflush(stdin);
                printf("Est�s seguro de querer adentrarte? Responde si (s) o no (n):\n");
                scanf("%c", &respuesta);
                if (respuesta == 'n') {
                    break;
                }
                system("cls");







            break;
		}
	}

	while (opcion!=5);
	system("cls");

printf ("El juego ha terminado\n");
return 0;
}


