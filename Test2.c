#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/wait.h>
int main()

{
pid_t idfils = 0;
idfils = fork();
if (idfils == 0) {
printf("Hello, world depuis le processus fils\n");
}else {
printf("Hello, world depuis le processus père\n");
wait(NULL);  //Pour attendre la terminaison du processus fils par le père
}
}
