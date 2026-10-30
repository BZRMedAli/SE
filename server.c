#include <sys/msg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long type;
    int x;
    int y;
} message;
int main(){
    message msg;
    key_t key = 1234;
    int fileId = msgget(key,0666|IPC_CREAT);
    while(1){
        msgrcv(fileId,&msg,sizeof(msg),1,0);
        printf( "%d + %d = %d\n",msg.x,msg.y, msg.x+msg.y);
        if(msg.x==0 && msg.y==0){
            break;
        }
    }
    msgctl(fileId, IPC_RMID, NULL);



}
