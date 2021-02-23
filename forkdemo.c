#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
int main() 
{ 
  int pid=0;
    pid = fork();
    if(pid == 0){
		printf("In Child");}	
	else
    printf("In Parent process id of child is %d "); 
    return 0; 
} 
