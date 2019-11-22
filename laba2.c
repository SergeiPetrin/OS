#include <pthread.h>
#include <stdlib.h>
#include <mcheck.h>
#include <stdio.h>
#include <math.h>

void *threadFunc(void* args){
    long double *num = (long double*) args;
    *num = (sin(*num) + cos(*num));

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
    pthread_t massivPotokov[to4ki];
    long double dots[to4ki];
    long double result[to4ki];
    for(int i = 1; i <= to4ki; i++) {
        dlinaOtrezka = granica2 - granica1;
        dots[i] = (((dlinaOtrezka * i) / (to4ki - 1)) + granica1) - 1;
        printf("Точка dots[i] = %Lf\n", dots[i]);
        result[i] = pthread_create(&massivPotokov[i], NULL, threadFunc, &dots[i]);                                                                                                                                     }
    for(int j = 0; j < to4ki; j++) {
        printf("Результат в точке %Lf\n", result[j]);
    }

}
