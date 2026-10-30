#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    
    int fds[2]; // Writing and reading descriptor for pipe
    pipe(fds);
    int number = 0;
    int pid =0;
    pid = fork(); // Create the process child
    if(pid==-1){
        printf("Error in creating process");
        return 0;
    }
    if(pid==0){
        // The child
        printf("give a number:");
        scanf("%d",&number);
        close(fds[0]);   // Close the reader before writing 
        write(fds[1],&number, sizeof(number)); // Write the number's contexte in the pipe
        close(fds[1]);  // Close the wrting's descriptor after writing 
    }else{
        // The father
        close(fds[1]);  // Close the reading's descriptor before reading
        read(fds[0],&number, sizeof(number));  // Reading the pipe's contente and record in the father's copy
        close(fds[0]); // Close the reading's descriptor after reading
        printf("The square of the number is %d\n", number*number);
    }

}
