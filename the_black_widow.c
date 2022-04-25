//Para limpiar la pantalla usar clear

#include <stdio.h>
#define TAM_MAX 2

struct TJugador{
	char nombre[50];
	float puntuacion;

};

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
	char modo_juego;
	
	//Defino variables ligadas a las vocales con tilde
	char a=160, e=130, it=161, o=162, u=163, aa=181, ee=144 , ii=214 , oo=224 , uu=233;
	
	//Extraer el banner a una función para que sea más claro 
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
                printf ("\n");
    			printf ("INSTRUCCIONES DE JUEGO\n");
        		printf("1-Pulse iniciar sesi%cn y a continuaci%cn seleccione si quiere jugar de forma individual o multijugador, e introduzca el nombre de los participantes.\n", o, o);
        		printf("El propio programa le volver%c a mostrar el men%c\n", a, u);
        		printf("2-Pulse iniciar juego y disfrute de este.\n");
				printf ("\n");
        	break;

            case 2:
            	printf("\n");
				printf ("%cC%cmo deseas jugar?\n",168, o);
				printf ("A. Individual\n");
				printf ("B. Multijugador\n"); //Habrá un máximo de tres jugadores
				fflush(stdin);
				scanf ("%c", &modo_juego);

				if (modo_juego=='a'||modo_juego=='A'){
					printf("\n");
					n=1;
					printf ("En breves te adentraras en esta terror%cfica experiencia a solas\n", it);
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


