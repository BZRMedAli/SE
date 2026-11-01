#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>

int main() {
  int *cpt;
  int seg_id;
  key_t seg_cle = ftok("First-Segment", 100);
  if (seg_cle <0){
    perror ("Error in ftok!");
    exit (1);
  }
  seg_id = shmget(seg_cle, 16, 0666|IPC_CREAT);
  if (seg_id == -1){
    perror ("Error in shmget);
      exit (1);
  }
  cpt = (int*)shmat(seg_id, 0, 0);
  if (cpt == (void*)-1) {
    perror ("Error in shmat");
    exit (1);
  }
  *cpt =0;
  while (*cpt <10) {
    sleep (2);
    *cpt =*cpt +1;
    printf("%d", *cpt);
  }
  shmdt (cpt);
  shmctl(seg_id, IPC_RMID, NULL);
  printf("\n");
  return 0;
  
}
