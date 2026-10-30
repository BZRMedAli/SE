#include <sys/msg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// 1. Define an appropriate data structure for messages passage
typedef struct {
    long type; // obligation
    int x;
    int y;
} message;

int main(){
    // The message to put in the queue
    message msg;  

    //Define an access key for the queue
    key_t key = 1234;  //Simple forme

    // We can try also
    // FILE *f = fopen(" My file", "w"); 
    // fclose(f);
    // key_t cle = ftok(“my file”, 100); 

    //3. Create the queue (or recuperate his reference if the queue is already exist in the system)
    int fileId = msgget(key,0666|IPC_CREAT);
    while(1){
        printf("give two numbers\n");
        scanf("%d %d",&msg.x,&msg.y);

        // Choose a type depending of the users needs
        msg.type =1;

        //4. Sending message to the queue
        msgsnd(fileId,&msg,sizeof(msg)-sizeof(long),0);
        if(msg.x==0 && msg.y==0){
            break;
        }
        
    }

    //5. Destroy the queue
    msgctl(fileId, IPC_RMID, NULL);
}
