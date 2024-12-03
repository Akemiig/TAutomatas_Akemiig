#include <stdio.h>
#include <string.h>
#include <ctype.h>

int validar(char a[]);

int main() {
	char a[20];
    int respuesta=1;
    while(respuesta){
		printf("(L|)|(L|D|)*\n\n");
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
	if(isdigit(a[0])){
		return 0;
	}
	for(int i=0; i<strlen(a); i++){
		if(!(isalnum(a[i]) || a[i]=='_')){
			return 0;
		}
	}
	return 1;
}
