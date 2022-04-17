#include <stdio.h>
#define TAM_MAX 2

struct TJugador{
	char nombre[50];
	float puntuacion;
	
};


int main() {
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
				printf ("Como deseas jugar?\n");
				printf ("A. Individual\n");
				printf ("B. Multijugador\n"); //Habrá un máximo de tres jugadores 
				fflush(stdin);
				scanf ("%c", &modo_juego);
				
				switch(modo_juego) {
					case 'a':
					case 'A':
						n=0;
						printf ("En breves te adentraras en esta terrorifica experiencia a solas\n");
						for (i=0;i<=n;i++){
							printf ("Intruduce tu nombre\n");
							fflush(stdin);
							gets(Jugadores[i].nombre);
						}
					break;
					
					case 'B':
					case 'b':
						
					break;		
				}
				
            break;


            case 3:

            break;

            case 4:

            break;
		}
	}

	while (opcion!=5);

printf ("El juego ha terminado\n");
return 0;
}






