#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 2

struct TJugador{
	char nombre[50];
	float puntuacion;

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
    struct TJugador Jugadores[TAM_MAX];
	int opcion,n,i;
	char modo_juego,pregunta;

	//Defino variables ligadas a las vocales con tilde
	char a=160, e=130, it=161, o=162, u=163, aa=181, ee=144 , ii=214 , oo=224 , uu=233;
	char interrogacion=168;
	char enne=164; 

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
				printf ("%cC%cmo deseas jugar?\n", interrogacion, o);
				printf ("A. Individual\n");
				printf ("B. Multijugador\n"); //Habrá un máximo de tres jugadores
				fflush(stdin);
				scanf ("%c", &modo_juego);

				if (modo_juego=='a'||modo_juego=='A'){
					printf("\n");
					n=1;
				}

				else if (modo_juego=='b'||modo_juego=='B'){
					printf("%cCu%cntos jugadores sois?\n", interrogacion, a);
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
                
                // Nivel fácil
                
                // Pregunta 1
                printf("%cA qu%c se dedicaba Aracne antes de ser convertida?\n", interrogacion, e);
                printf("a. Tejedora\n"); // Correcta
                printf("b. Costurera\n");
                printf("c. Sastre\n");
                printf("d. Diseñadora\n");
                
                // Pregunta 2
                printf("%cCu%cl es el nombre de la actriz que interpreta a La Viuda Negra en Los Vengadores?\n", interrogacion, a);
                printf("a. Sof%ca Vergara\n", it);
                printf("b. Scarlett Johansson\n"); // Correcta
                printf("c. Elizabeth Olsen\n");
                printf("d. Natalie Portman\n");
                
                // Pregunta 3
                printf("%cC%cmo se llama el miedo a las ara%cas?\n", interrogacion, o, enne);
                // Aracnofobia
                
                // Pregunta 4
                printf("Realiza la clasificaci%cn taxon%cmica de las ara%cas en: reino, filo, clase\n", o, o, enne);
                printf("a. Animalia - Artr%cpodos - Ar%cnidos\n", o, a); // Correcta
                printf("b. Ar%cnidos - Moluscos - Animalia\n", a); 
                printf("c. Artr%cpodos - Mam%cferos - Ar%cnidos\n", o, it, a);
                printf("d. Animalia - Mam%cferos - Ar%cnidos\n", it, a);
                
                // Pregunta 5
                printf("%cEn cu%cal reconocida organizaci%cn estuvo trabajando Viuda Negra junto con otros supreh%croes?\n", interrogacion, it, e);
                printf("a. S.H.I.E.L.D\n"); // Correcta
                printf("b. S.I.D\n"); 
                printf("c. S.I.D.E\n");
                printf("d. F.I.L.E\n");
                
                // Pregunta 6
                printf("Nombre de la escritora que public%c en 2020 de la mano de Disney Libros un libro sobre el famoso personaje Viuda Negra\n", o);
                printf("a. Cassandra Clare\n");
                printf("b. Holly Black\n"); 
                printf("c. Rick Riordan\n");
                printf("d. Margaret Stohl\n"); // Correcta
                
                // Pregunta 7
                printf("%cCu%ctos ojos tiene una ara%ca?\n", interrogacion, enne);
                printf("a. 5\n");
                printf("b. 2\n"); 
                printf("c. 4\n");
                printf("d. 8\n"); // Correcta
                
                // Pregunta 8
                printf("%cQu%c personaje no forma parte de Los Vengadores?\n", interrogacion, e);
                printf("a. Soldado de invierno\n"); // Correcta
                printf("b. Ojo de Halc%cn\n", o); 
                printf("c. Thor\n");
                printf("d. Capit%cn Am%crica\n", a, e);
                
                // Pregunta 9
                printf("%cEn qu%c pel%ccula de Harry Potter aparecen ara%cas? (Solo dos palabras)\n", interrogacion, it, enne);
                // Cámara Secreta
                
                // Pregunta 10
                printf("%CC%cmo Peter Parker se convirti%c en Spiderman?\n", interrogacion, o, o);
                printf("a. Por comerse una ara%ca\n", enne);
                printf("b. Por el mordisco de una ara%ca\n", enne); 
                printf("c. Por tocar una telara%ca\n", enne);
                printf("d. Al ser maldecido por una bruja\n");
                
                // Nivel intermedio
                
                // Pregunta 10
                printf("\n");
                printf("a. \n");
                printf("b. \n"); 
                printf("c. \n");
                printf("d. \n");








            break;
		}
	}

	while (opcion!=5);
	system("cls");

printf ("El juego ha terminado\n");
return 0;
}


