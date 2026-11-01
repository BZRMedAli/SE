/* A program that allows incrementing or decrementing a counter in two differnte process joined by a shared memory, the first one increment the counter 
and display his value in each 2 seconds, the other one decrement the counter and dispay his value in each 3 seconds  */

// If we use one process only
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    char c;
    int *cpt;

    FILE *f = fopen("segment 1", "w");
    if (f) fclose(f);

    key_t seg_cle = ftok("segment 1", 100);
    if (seg_cle == -1) { 
      perror("Error in ftok");
      exit(1); 
    }

    int seg_id = shmget(seg_cle, 16, 0666 | IPC_CREAT);
    if (seg_id == -1) {
      perror("Error in shmget");
      exit(1);
    }

    cpt = (int *)shmat(seg_id, 0, 0);
    if (cpt == (void *)-1) {
      perror("Error in shmat");
      exit(1);
    }

    *cpt = 0;

    while (*cpt < 10) {
        do {
            printf("I or D: ");
            scanf(" %c", &c);
        } while (c != 'I' && c != 'D');

        if (c == 'I') {
            *cpt = *cpt + 1;
            sleep(2);
        } else {
            *cpt = *cpt - 1;
            sleep(3);
        }
        printf("cpt = %d\n", *cpt);
    }

    shmdt(cpt);
    shmctl(seg_id, IPC_RMID, NULL);
    return 0;
}

// If we have to use 2 process we have to create 2 c files differents joined by ftok (process1.c) and (process2.c)
