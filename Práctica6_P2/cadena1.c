#include <stdio.h>
#include <string.h>

int validar(char a[]);

int main() {
    char a[20];
    int respuesta=1;
    while(respuesta){
		printf("(ab|cd)+\n\n");
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

int contiene(const char *a, const char *b) {
    const char *valido=strstr(a,b);
    if(!valido) {
        return 0;
    }
    return 1;
}

int contieneAB(char a[]){
	if(contiene(a,"ab")){
		return 1;
	}
	return 0;
}

int contieneCD(char a[]){
	if(contiene(a,"cd")){
		return 1;
	}
	return 0;
}

int validar(char a[]){
	if(strlen(a)%2!=0){
		return 0;
	}
	
	if(strlen(a)==2){
		if((a[0]=='a' && a[1]=='b') || (a[0]=='c' && a[1]=='d')){
			return 1;
		}
	}
	
	
	if(contieneAB(a) || contieneCD(a)){
		return 1;
	}
	return 0;
}
