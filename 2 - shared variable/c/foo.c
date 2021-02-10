//hvordan compile. Skriv cd i terminalen, også kopier file directory. Når du er riktig plass som inneholder foo.c skriv
//compile greia oppgitt nedenfor. Når du compiler lager du en exe fil. For å se at programmet funker må du kjøre det.
//skriv a og trykk enter
// Compile with `gcc foo.c -std=c99 -lpthread`, or use the makefile 

#include <pthread.h>
#include <stdio.h>

//A guees just from what you have included(pthreah.h) is that mutex is correct.
//Another reason you want mutex is that you would lock it so that only one of the threads changes the variable at the time.
//a sempafore can not do that.

int i = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
// Note the return type: void*
void* incrementingThreadFunction(){
    for (int j = 0; j < 1000002; j++) {
	// TODO: sync access to i
    pthread_mutex_lock(&mutex);
	i++;
    pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void* decrementingThreadFunction(){
    for (int j = 0; j < 1000000; j++) {
	// TODO: sync access to i
    pthread_mutex_lock(&mutex);
	i--;
    pthread_mutex_unlock(&mutex);
    }
    return NULL;
}


int main(){
    pthread_t incrementingThread, decrementingThread;
    
    pthread_create(&incrementingThread, NULL, incrementingThreadFunction, NULL);
    pthread_create(&decrementingThread, NULL, decrementingThreadFunction, NULL);
    
    pthread_join(incrementingThread, NULL);
    pthread_join(decrementingThread, NULL);
    
    printf("The magic number is: %d\n", i);
    return 0;
}
