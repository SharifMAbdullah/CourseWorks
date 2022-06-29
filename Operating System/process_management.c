#include<stdio.h>
#include<unistd.h>
int main()
{
int pid;
printf("original process with PID %d and PPID %d\n",getpid(),getppid());
pid = fork();
if(pid!=0)
{
	printf("I am parent process with PID %d and PPID %d\n",getpid(),getppid());
	printf("child's PID is %d \n", pid);
}
else
{
	printf("I am child process with PID %d and PPID %d\n",getpid(),getppid());
}
}
