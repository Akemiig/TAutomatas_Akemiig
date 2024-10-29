#include <stdio.h>
#include <string.h>

void interseccion(char a[], char u[]);
void complemento(char a[], char u[]);
int encontrado(char a[], char u);

int main(){
	char A[]="123456";
	char U[]="123789";
	printf("Interseccion\n");
	interseccion(A,U);
	printf("\nComplemento\n");
	complemento(A,U);
	return 0;
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
	for(i=0;i<=strlen(a);i++){
		if(a[i]==u){
			return 1;
		}
	}
	return 0;
}
