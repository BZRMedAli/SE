#include <sys/types.h> 
#include <sys/ipc.h> 
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(){
    int* compteur;
    key_t cle = 34210;
    int segmentId = shmget(cle, sizeof(int),0666|IPC_CREAT);

    if (segmentId == -1) {
        perror("Error shmget");
        exit(1);
    }
    compteur = (int*)shmat(segmentId,0,0);
    if (compteur == (void *) -1) {
        perror("Error shmat");
        exit(1);
    }
    *compteur = 0;
    while(*compteur<100){
        (*compteur)++;
        printf("%d\n",*compteur);
        sleep(1); // in seconds
    }
    shmdt(compteur);
    shmctl(segmentId,IPC_RMID, NULL);

}
