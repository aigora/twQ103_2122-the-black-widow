#include <stdio.h>

int main() {
    int opcion;
	
	do {
	
		printf ("MENU DE OPCIONES\n");
		printf("Escriba el numero que representa la acción que desea realizar:\n");
    		printf("1. Instrucciones del juego\n");
    		printf("2. Iniciar  sesion\n");
    		printf("3. Ranking de puntuaciones\n");
   		printf("4. Iniciar juego\n");
    		printf("5. Salir\n");

		scanf("%d", &opcion);
		
		printf ("\n");
    
    		if (opcion==1) { //Como limpiar pantalla
    			printf ("\n");
    			printf ("INSTRUCCIONES DE JUEGO\n");
        		printf("1-Pulse iniciar sesion y a continuacion seleccione si quiere jugar de forma individual o multijugador, e introduzca el nombre de los participantes.\n");
        		printf("Regrese a la pantalla de inicio pulsando la letra W.\n");
        		printf("2-Pulse iniciar juego y disfrute de este.\n");
    		}
    
    		if (opcion==2) {
        
    		}
    
    		if (opcion==3) {
        
    		}
    
    		if (opcion==4) {
        
    		}

	}

	while (opcion!=5);
	
return 0;
}






