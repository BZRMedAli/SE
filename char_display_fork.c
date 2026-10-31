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

// We can adjust the program to ensure that the small letters are displayed before the capital ones using the wait function in the parent process
// The C program is: 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
  setbuf(stdout, NULL);
  pid_t pid=fork();
  if (pid < 0){
    perror("Error");
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

// We can adjust the program in this time to ensure displaying capital letters before small letters by using pipe
// The C program is:

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/wait.h>

int main(){

  char vchar[26];
  int i=0;
  int ped[2];
  setbuf(stdout, NULL);
  if (pipe(ped) <0) {
    perror("Error");
    exit (1);
  }else // Here we have pipe greater then or equal to 0 
  {
    pid_t pid=fork();
    if (pid <0){
      perror ("Error");
      exit(1);
    }else if (0<pid){ //The parent process
      close(ped[0]);
      for (char c='A'; c<='Z'; c++){
        vchar[i] = c;
        i++;
        printf("%c",c);
      }
      write(ped[1],vchar,sizeof(vchar));
      close(ped[1]);
      wait(NULL);
    }else // The child process
    {
      close(ped[1]);
      read(ped[0],vchar,sizeof(vchar));
      close(ped[0]);
      for (int j=0;j<26;j++){
        printf("%c",tolower(vchar[j]));
      }
      exit(0);
    }
  }
  printf("\n");
  return 0;
}
