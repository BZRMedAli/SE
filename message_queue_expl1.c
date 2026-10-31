/* A program example in which we declare a client and a server, the client read 2 integers numbers and send them to the server, the server calculates the sum of them
and return it to the client */

//Client's program
#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/types.h>

typedef struct {
long type;
int x;
int y;
}message;

int main(){
  int x;
  int y;
  message msg;
  key_t key = ftok ("File 1", 100);
  if (key == -1) {
    perror ("Error ftok");
    exit (1);}
  int msgid = msgget (key, 0666|IPC_CREAT);
  if (msgid ==-1){
    perror ("Error msgget");
    exit (1);
  }
    printf("Give 2 integers :");
    scanf("%d%d",&msg.x,&msg.y);
  msg.type=1;
  if ( msgsnd(msgid, &msg, sizeof(msg) - sizeof (long), 0)== -1) {
    perror ("Error in msgsnd");
    exit (1);
  } // Here 4 is the size of long who is 4 oct (32 bits)
  }  //The server is the one to destroy the message queue and not the client

// Server's program
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>

typedef struct {
long type;
int x;
int y;
} message;

int main() {
  int x,y,z;
  key_t key = ftok ("File 1", 100);
  if (key ==-1) {
    perror("Error in ftok");
  exit (1);}
  int msgid= msgget (key, 0666|IPC_CREAT);
  if (msgid ==-1) {
    perror ("Error in msgget");
      exit (1);
  }
  message msg;
  msgrcv(msgid,&msg, sizeof(msg) - sizeof(long), 1, 0);
  x = msg.x;
  y = msg.y;
  z= x + y;
  printf("The sum is:%d",z);
  msgctl(msgid, IPC_RMID, 0);
  return 0;
}

  
