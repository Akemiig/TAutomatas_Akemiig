#include <string.h>
#include <stdio.h>

void unionC(char a[], char u[]);  
void diferencia(char a[], char u[]);
void interseccion(char a[], char u[]);
void complemento(char a[], char u[]);      
int encontrado(char a[], char u); 

int main(){
	int opcion;
	char A[100];
	char U[100];
    printf("Ingresa el lenguaje A:");
    scanf("%s", A);
    printf("\nIngresa el lenguaje U:");
    scanf("%s", U);
    printf("\n\nEl lenguaje A es:%s", A);
    printf("\nEl lenguaje U es:%s", U);
    do{
		printf("\n\n1.-Union\n2.-Interseccion\n3.-Complemento\n4.-Diferencia\n0.-Salir");
        printf("\n\nElige una opcion:");
        scanf("%i", &opcion);
		switch(opcion){
			case 1:printf("\n\nLa union de A y U es:");
			unionC(A,U);
			break;
			case 2:printf("\n\nLa interseccion de A y U es:");
			interseccion(A,U);
			break;
			case 3:printf("\n\nEl complemento de A es:");
			complemento(A,U);
		        printf("...");
			break;
			case 4:printf("\nLa diferencia de A y U es:");
			diferencia(A,U);
			break;
			case 0:printf("\n\nSaliendo...");
			break;
			default:printf("\n\nOpcion no valida");
		}
	}while(opcion!=0);  
	return 0;
}
void unionC(char a[], char u[]){
    int i;
    for(i= 0; i<strlen(a); i++){
        printf("%c ", a[i]);
    }
    for(i= 0; i<strlen(u); i++){
        if(!encontrado(a, u[i])){  
            printf("%c ", u[i]);
        }
    }
}
void diferencia(char a[], char u[]){
    int i;
    for(i= 0; i<strlen(u); i++){
        if(!encontrado(u, a[i])){  
            printf("%c ", a[i]);
        }
    }
}
void interseccion(char a[], char u[]){
	int i,j;
	for(i=0;i<strlen(a);i++){
		for(j=0;j<strlen(u);j++){
			if(a[i]==u[j]){
				printf("%c", a[i]);
			}
		}
	}
}
void complemento(char a[], char u[]){
	int i;
	for(i=0;i<strlen(u);i++){
		if(!encontrado(a,u[i])){
			printf("%c", u[i]);
		}
	}
}
int encontrado(char a[], char u){
    int i;
    for(i= 0; i<strlen(a); i++){
        if(a[i]== u){
            return 1;  
        }
    }
    return 0;  
}
