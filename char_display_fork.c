#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main() {
setbuf (stdout, NULL);
pid_t pid = fork();
switch (pid) {
case -1:
perror ("Error");
exit (1);
case 0: //The child
for (char c='a'; c<='z'; c++){
  printf("%c",c);
}
exit (0);
default: // The parent (0<pid) 
for (char c='A'; c<='Z'; c++){
printf("%c",c);
}
  wait (NULL);
}
return 0;
}

//We can adjust the program to ensure that the small letters are displayed before the capital ones using the wait function in the parent process
//The program becomes 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
  setbuf(stdout, NULL);
  pid_t pid=fork();
  if (pid < 0){
    perror("Erreur");
    exit(1);
  }
  else if (pid==0){
    for (char c='a'; c<='z'; c++){
      printf("%c",c);
}
    exit(0);
  }else // 0<pid
  {
    wait(NULL);
    for (char c='A'; c<='Z';c++){
      printf("%c",c);
    }
    printf("\n");
  }
  return 0;  
  }
