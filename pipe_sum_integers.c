/* A C program in which we use two process parent and child, the parent is used to read integers numbers and stop when reading 0, the child process used to
calculate their sum */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MAX 100

int main(){
  int ped[2];
  int vent[MAX] = {0};
  if (pipe(ped)<0){
    perror("Error in pipe");
    exit(1);
  }
    pid_t pid= fork();
    if (pid <0){
      perror("Error in fork");
      exit(1);
    }else if (pid>0){ // The parent process
      int i=0;
      int x;
      close (ped[0]);
      printf("Write integers (0 to stop):\n");
      do {
        printf("Number %d:",i+1);
        scanf("%d",&x);
        vent[i++] = x; // equivalent to vent[i]= x; i+=1
        }while ((x !=0) && (i<MAX));
      write(ped[1],vent,i * sizeof(int));
      close(ped[1]); // To close writer
      wait (NULL); // Waiting for the child process
  }else //pid==0, the child process
    {
      int sum=0;
      close(ped[1]);
      read(ped[0],vent,sizeof(vent));
      close(ped[0]);
      for (int j=0; j<MAX && vent[j]!=0;j++){
        sum+=vent[j];
      }
      printf("The sum of the integers written by the user is:%d",sum);
      exit (0);
    }
  printf("\n");
  return 0;
}
  
