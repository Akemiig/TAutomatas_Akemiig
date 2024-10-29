#include <stdio.h>
void letraA();
void letraK();
void letraE();
void letraM();
void letraI();
void completo();

int main(){
    char nombre[]= "Akemi";  
    int estado= 0;        
    int i=0;               

    while(nombre[i]!='\0'){
        switch(estado){
            case 0:
                if (nombre[i]=='A'){
                    letraA();
                    estado=1;
                }
                break;

            case 1:
                if(nombre[i]=='k'){
                    letraK();
                    estado=2;
                }
                break;

            case 2:
                if(nombre[i]=='e'){
                    letraE();
                    estado=3;
                }
                break;

            case 3:
                if(nombre[i]=='m') {
                    letraM();
                    estado=4;
                }
                break;

            case 4:
                if(nombre[i]=='i'){
                    letraI();
                    estado=5;
                }
                break;

            case 5:
                completo(); 
                return 0;; 
			}
			i++;
        }
    return 0;
}

void letraA(){
    printf("A");
}
void letraK(){
    printf("k");
}
void letraE(){
    printf("e");
}
void letraM(){
    printf("m");
}
void letraI(){
    printf("i");
}
void completo(){
    printf("\nEl nombre completo es: Akemi\n");
}
