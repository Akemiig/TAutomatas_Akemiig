#include <stdio.h>
#include <string.h>

int validar(char a[]);

int main() {
    char a[20];
    int respuesta=1;
    while(respuesta){
		printf("(ab)|(cd)\n\n");
        printf("Ingresa la cadena:");
        scanf("%s", a);
        if(validar(a)){
			printf("\nCadena Valida\n\n");
		}else{
			printf("\nCadena Invalida\n\n");
		}
        printf("Quieres ingresar otra cadena? (1= Si, 0= No):");
        scanf("%i", &respuesta);
    }
    return 0;
}

int validar(char a[]){
	if(a[0]=='E'){
		return 1;
	}
	if(strlen(a)%2!=0){
		return 0;
	}
	for(int i=0; i<strlen(a); i+=2){
        if(!((a[i]=='a' && a[i+1]=='b') || (a[i]=='c' && a[i+1]=='d') )){
            return 0; 
        }
    }
    return 1;
}
