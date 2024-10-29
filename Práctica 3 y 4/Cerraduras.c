#include <stdio.h>
#include <string.h>
#define MAX_LONG 100  // número de caracteres por palabra
#define MAX_P 50  // número de palabras únicas

int existeEnConjunto(char *palabra, char conjunto[][MAX_LONG], int numPalabras){
    for(int i=0; i<numPalabras; i++){
        if(strcmp(palabra, conjunto[i])==0){
            return 1;
        }
    }
    return 0;
}
void generarCadenas(char *conjunto[], int t, int numCadenas, const char *nombre){
    char kleene[MAX_P][MAX_LONG];  
    char positiva[MAX_P][MAX_LONG];  
    int numKleene=0, numPositiva=0;
    strcpy(kleene[numKleene], "ɛ"); // agrega la cadena vacia 
    numKleene++;

    // genera cadenas para A*
    for(int longitud=1; longitud <=3 && numKleene < numCadenas; longitud++){
        for(int i=0; i<t && numKleene < numCadenas; i++){
            for(int j=0; j<t; j++){ // generar combinaciones
                char palabra[MAX_LONG]="";
                strcat(palabra, conjunto[i]);
                strcat(palabra, conjunto[j]);

                if(!existeEnConjunto(palabra, kleene, numKleene)){
                    strcpy(kleene[numKleene], palabra);
                    numKleene++;
                }
            }
        }
    }
    // genera cadenas para A+ 
    for(int longitud=1; longitud <=3 && numPositiva < numCadenas; longitud++){
        for(int i=0; i<t && numPositiva < numCadenas; i++){
            for(int j=0; j<t; j++){ // generar combinaciones
                char palabra[MAX_LONG]="";
                strcat(palabra, conjunto[i]);
                strcat(palabra, conjunto[j]);
                if(!existeEnConjunto(palabra, positiva, numPositiva)){
                    strcpy(positiva[numPositiva], palabra);
                    numPositiva++;
                }
            }
        }
    }
    printf("Cadenas de %s A*:\n{", nombre);
    for(int i=0; i< numKleene; i++){
        printf("%s", kleene[i]);
        if(i<numKleene-1){
            printf(", ");
        }
    }
    printf("}\n");
    printf("\nCadenas de %s A+:\n{", nombre);
    for(int i=0; i<numPositiva; i++){
        printf("%s", positiva[i]);
        if(i<numPositiva-1){
            printf(", ");
        }
    }
    printf("}\n");
}
int main(){
	//AKEMIIII
    int numCadenas;
    printf("Cuantas cadenas distintas desea generar?\n");
    scanf("%i", &numCadenas);
    char *conjunto1[]={"1", "2", "3"}; 
    char *conjunto2[]={"a", "b"};                    
    char *conjunto3[]={"1a", "2b"};                  
    generarCadenas(conjunto1, 3, numCadenas, "A={1, 2, 3}");
    printf("\n");
    generarCadenas(conjunto2, 2, numCadenas, "A1={a, b}");
    printf("\n");
    generarCadenas(conjunto3, 2, numCadenas, "A2={1a, 2b}");
    return 0;
}
