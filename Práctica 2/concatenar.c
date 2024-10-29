#include <stdio.h>
#include <string.h> 

void letraA(char*); //char para que puedan ser modificados dentro de la funcion
void letraK(char*);
void letraE(char*);
void letraM(char*);
void letraI(char*);
void completo(char*);

int main(){
	//AKEMII
    char nombre[]= "Akemi";  
    char resultado[50]="";  // inicializa en carácter nulo
    int estado=0;          
    int i=0;             

    while(nombre[i]!= '\0'){  // Mientras no lleguemos al final de la cadena
        switch(estado){
            case 0:
                if(nombre[i]=='A'){
                    letraA(resultado);  // Concatenar A a la cadena resultado
                    estado=1;
                }
                break;

            case 1:
                if(nombre[i]=='k'){
                    letraK(resultado);  
                    estado=2;
                }
                break;

            case 2:
                if(nombre[i]=='e'){
                    letraE(resultado);  
                    estado=3;
                }
                break;

            case 3:
                if(nombre[i]=='m'){
                    letraM(resultado);  
                    estado=4;
                }
                break;

            case 4:
                if(nombre[i]=='i'){
                    letraI(resultado);  
                    estado=5;
                }
                break;
			}
        i++;  
    }
    if(estado==5){
        completo(resultado);  
	}

    return 0;
}

void letraA(char* resultado){
    strcat(resultado, "A");
}
void letraK(char* resultado){
    strcat(resultado, "k");
}
void letraE(char* resultado){
    strcat(resultado, "e");
}
void letraM(char* resultado){
    strcat(resultado, "m");
}
void letraI(char* resultado){
    strcat(resultado, "i");
}
void completo(char* resultado) {
    printf("El nombre completo es: %s\n", resultado);
}
