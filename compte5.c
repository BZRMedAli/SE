#include <sys/types.h> 
#include <sys/ipc.h> 
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(){
    int* counter;
    key_t key = 34210;
    int segmentId = shmget(key, sizeof(int),0666|IPC_CREAT);

    if (segmentId == -1) {
        perror("Error shmget");
        exit(1);
    }
    counter = (int*)shmat(segmentId,0,0);
    if (counter == (void *) -1) {
        perror("Error shmat");
        exit(1);
    }
    //*counter = 0;
    while(*counter<100){
         sleep(5);
        (*counter)+=5;
    }
    shmdt(counter);
    shmctl(segmentId,IPC_RMID, NULL);

}
