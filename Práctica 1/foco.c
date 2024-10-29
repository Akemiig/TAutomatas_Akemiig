#include <stdio.h>
//AKEMII
int main(){
	int estadoFoco=0;
	int respuesta;
	while(1){
		if(estadoFoco==1){
			printf("El foco esta encendido\n");
		}else{
			printf("\nEl foco esta apagado\n");
		}
			printf("Introduce tu respuesta (1 para encender, 0 para apagar):\n");
			scanf("%i", &respuesta);
			
			if(respuesta==1){
				estadoFoco=1;
			}else if(respuesta==0){
				estadoFoco=0;
			}else{
				printf("ERROR\n");
			}
		}
		return 0;
}
