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
  key_t key;
  int msgid;
  key = ftok("File 1", 100);
  msgid = msgget(key, 0666|IPC_CREAT);
    printf("Give 2 integers :");
    scanf("%d%d",&x,&y);
    msg.x=x;
    msg.y=y;
    msg.type=1;
  msgsnd(msgid, (message*)&msg, sizeof(msg) -4, 0); // Here 4 is the size of long who is 4 oct (32 bits)
  msgctl (msgid, IPC_RMID, 0);  // Destroy the message queue to save system resources
  }

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
  key_t key;
  int msgid;
  message msg;

  key = ftok("File 1", 100);
  msgid = msgget (key, 0666|IPC_CREAT);
  msgrcv(msgid,(message*)&msg, sizeof(msg) -4, 1, 0);
  x = msg.x;
  y = msg.y;
  z= x + y;
  printf("The sum is:%d",z);
  msgctl(msgid, IPC_RMID, 0);
  return 0;
}

  
