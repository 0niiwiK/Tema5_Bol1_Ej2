#include <stdio.h>
#define TAM 10

//Prototipos
void rellenar_vector(int vector[], int *ncadenas);
float calcula_media (int vector[], int ncadenas);
void calcula_numeros_digitos (int vector[], int digitos[], int ncadenas);
void imprime_numeros_digitos (int digitos[]);
int calcula_terminacion_maxima (int digitos[]);
void calcula_terminaciones_nulas (int digitos[]);

int main() {
    int vector[TAM]; // Vector con las cadenas numéricas que introduce el usuario.
    int digitos[] = {0,0,0,0,0,0,0,0,0,0}; // Vector de contadores de terminaciones.
    int ncadenas; // No de cadenas numéricas introducidas.
    int termina; // Terminación más repetida.
    float media; // Media de los valores introducidos.

    // Se rellena el vector con todas las cadenas que introduce el usuario.
    // Finalmente ncadenas almacenará cuántas cadenas se han introducido.
    rellenar_vector (vector, &ncadenas);

    // Se calcula la media de los valores introducidos (-1 si no hay ninguno).
    media = calcula_media (vector, ncadenas);

    if (media != -1)
        printf("\nLa media de los valores introducidos es de %f.\n\n", media);

    // Se genera el vector de terminaciones.
    calcula_numeros_digitos (vector, digitos, ncadenas);

    // Se imprime cuántas cadenas terminan en cada uno de los números del 0 al 9. // Se omiten las terminaciones sin cadenas candidatas.
    imprime_numeros_digitos (digitos);

    // Se calcula la terminación más repetida (si hay varias sólo guarda la primera). // Si no hay cadenas la función devuelve -1.
    termina = calcula_terminacion_maxima (digitos);
    if (termina != -1)
    {
        printf("\nLa terminacion mas repetida es %d.\n\n", termina);
        calcula_terminaciones_nulas (digitos);
        printf("\n\n");
    }
}

void rellenar_vector(int vector[], int *ncadenas){
    int num;
    *ncadenas=0;
    for (int i = 0; i < TAM; i++) {
        printf("Introduce un valor entre 1 y 1000: ");
        scanf("%d",&num);
        if (num<1 || num>1000)
            num=0;
        else
            *ncadenas=*ncadenas+1;
        vector[i]=num;
    }
}

float calcula_media (int vector[], int ncadenas){
    int sumatorio=0;
    float media=0;
    if (ncadenas==0)
        media=-1;
    else {
        for (int i = 0; i < TAM; i++) {
            sumatorio+=vector[i];
        }
        media=(float)sumatorio/(float)ncadenas;
    }
    return media;
}

void calcula_numeros_digitos (int vector[], int digitos[], int ncadenas){
    int terminacion;
    for (int i = 0; i < TAM; i++) {
        if (vector[i]!=0){
            terminacion=vector[i]%10;
            digitos[terminacion]++;
        }
    }
}

void imprime_numeros_digitos (int digitos[]){
    for (int i = 0; i < TAM; i++) {
        if (digitos[i]>0)
            printf("Hay %d numeros terminados en %d.\n",digitos[i],i);
    }
}

int calcula_terminacion_maxima (int digitos[]){
    int max=0;
    for (int i = 0; i < TAM; ++i) {
        if (digitos[i]>digitos[max])
            max=i;
    }
    if (digitos[max]==0)
        max=-1;
    return max;
}

void calcula_terminaciones_nulas (int digitos[]){
    printf("Terminaciones que no se dan entre los valores introducidos: ");
    for (int i = 0; i < TAM; i++) {
        if (digitos[i]==0)
            printf("%d ",i);
    }
}



















