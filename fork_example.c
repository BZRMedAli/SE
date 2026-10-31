#include <stdio.h>      // For input/output
#include <stdlib.h>     // For memory allocation, and exit()
#include <unistd.h>     // For API POSIX (linux + macos + BSD + GNU), (fork(), wait(), ....)
int main() {
    char *args[] = {"ls", NULL};
    
    pid_t pid = fork();  // unistd.h - Process creation
    
    if (pid == 0) {
        // Child process
        execvp(args[0], args);  // unistd.h - Program execution
        exit(1);                // stdlib.h - Quit if exec fails
    } else {
        // parent
        wait(NULL);             // unistd.h - Wait the child
    }
    
    return 0;
}
