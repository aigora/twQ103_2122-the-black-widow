#include <stdio.h>
#define TAM_MAX 2

struct TJugador{
	char nombre[50];
	float puntuacion;

};


int main() {
    FILE*pfichero;
    struct TJugador Jugadores[TAM_MAX];
	int opcion,n,i;
	char modo_juego;

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

	do {

		printf("MENU DE OPCIONES\n");
		printf("Escriba el numero que representa la acción que desea realizar:\n");
    	printf("1. Instrucciones del juego\n");
    	printf("2. Iniciar  sesion\n");
    	printf("3. Ranking de puntuaciones\n");
   		printf("4. Iniciar juego\n");
    	printf("5. Salir\n");

		scanf("%d", &opcion);

		switch(opcion) {

            case 1:
                printf ("\n");
    			printf ("INSTRUCCIONES DE JUEGO\n");
        		printf("1-Pulse iniciar sesion y a continuacion seleccione si quiere jugar de forma individual o multijugador, e introduzca el nombre de los participantes.\n");
        		printf("Regrese a la pantalla de inicio pulsando la letra W.\n");
        		printf("2-Pulse iniciar juego y disfrute de este.\n");
				printf ("\n");
        	break;

            case 2:
            	printf("\n");
				printf ("%cComo deseas jugar?\n",168);
				printf ("A. Individual\n");
				printf ("B. Multijugador\n"); //Habrá un máximo de tres jugadores
				fflush(stdin);
				scanf ("%c", &modo_juego);

				if (modo_juego=='a'||modo_juego=='A'){
					printf("\n");
					n=1;
					printf ("En breves te adentraras en esta terrorifica experiencia a solas\n");
				}

				else if (modo_juego=='b'||modo_juego=='B'){
					printf("%cCuantos jugadores sois?\n",168);
					scanf("%d", &n);
				}

				for (i=1;i<=n;i++){
					printf("\n");
					printf ("Intruduce tu nombre\n");
					fflush(stdin);
					gets(Jugadores[i].nombre);
					printf("\n");
				}

				if (n=1) {
					printf ("Bienvenido al juego, jugador\n");
					printf("\n");
				}
				else {
					printf ("Bienvenidos al juego, juegadores\n");
					printf("\n");
				}

            break;


            case 3:
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

            break;
		}
	}

	while (opcion!=5);

printf ("El juego ha terminado\n");
return 0;
}


