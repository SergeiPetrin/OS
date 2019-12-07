#include <pthread.h>
#include <stdlib.h>
#include <mcheck.h>
#include <stdio.h>
#include <math.h>

void *threadFunc(void* args){
    long double *num = (long double*) args;
    *num = sin(*num) + cos(*num);
    return NULL;
}

int main() {
    long double granica1;
    long double granica2;
    long double dlinaOtrezka;
    int to4ki;
    printf("Введите первую границу\n");
    scanf("%Le", &granica1);
    printf("Введите вторую границу\n");
    scanf("%Le", &granica2);
    printf("Введите количество точек\n");
    scanf("%d", &to4ki);
    pthread_t massivPotokov[to4ki - 1];
    long double dots[to4ki - 1];
    long double result[to4ki];
    for(int i = 0; i < to4ki; i++) {
        dlinaOtrezka = granica2 - granica1;
        dots[i] = ( (dlinaOtrezka + 1) * i / to4ki) + granica1;
    }
    for(int i = 0; i < to4ki; i++) {
        pthread_create(&massivPotokov[i], NULL, threadFunc, &dots[i]);
        pthread_join(massivPotokov[i], NULL);
    }
    printf("Точка Х1 = %Lf\n", dots[0]);
    for(int i = 1; i < to4ki; i++) {
            dots[i] = dots[i] * dots[i - 1];
            printf("Точка X%d = %Lf\n", i, dots[i]);
    }
}
