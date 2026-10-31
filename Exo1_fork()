/*A program for the use of two process (parent + child) to execute in parallelisme by the SE, the objectif is to use the parent for the sum of 10 first
integer numbers, and the child for the product of the 10 first integer numbers*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main()
{
int n=1;
pid_t pid;
printf("Hello World \n");  
pid = fork();  
if (pid == -1){
perror("Error during fork");
return 1;
}else if (pid>0){
// The process parent
for (int i=0;i<10;i++){
n= n + i;
}
printf("The sum is:%d\n",n);
wait(NULL); //Waiting the process child, it is used by the parent only
}else {
// The process child
for (int i=1;i<10;i++){
n=n*i;
}
printf("The product is:%d\n",n); 
}
return 0;
}
