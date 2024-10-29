#include <stdio.h>
#include <string.h>

void unionC(char a[], char u[]);  
void diferencia(char a[], char u[]);      
int encontrado(char a[], char u);         

int main(){
    char A[]="12345";
    char U[]="123789";  
    printf("Union de A y U: ");
    unionC(A, U);  
    printf("\nDiferencia A - U:");
    diferencia(A, U);      
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
int encontrado(char a[], char u){
    int i;
    for(i= 0; i<strlen(a); i++){
        if(a[i]== u){
            return 1;  
        }
    }
    return 0;  
}
