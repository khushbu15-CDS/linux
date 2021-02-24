#include<stdio.h>
#include<unistd.h>
// 2 way -- parent to Child to Parent 
int main() {
   int pipefds1[2]; // pipefds1[0]-->read ,,,,, pipefds1[1]-->write
   int pipefds2[2]; // pipefds2[0]-->read ,,,,, pipefds2[1]-->write
   char data[5]=" ";
   char data1[5]=" ";
   int pid=0;
  
   if(pipe(pipefds1) < 0){printf("Pipe Error "); return;}
   if(pipe(pipefds2) < 0){printf("Pipe Error "); return;}
   if(  (pid = fork()  ) < 0)  {printf("Fork  Error "); return;  }
   //code for chlild 
   
   if(pid == 0){
       sleep(5);
       read(pipefds1[0],data,5);   // pipefds1[0]
       printf("\n %d  data is %s \n",getpid(),data);
       write(pipefds2[1],"HELLO",5);  // pipefds2[1]
       
   }
   if(pid > 0){   // parent 
       write(pipefds1[1],"hello",5);  // pipefds1[1]
       sleep(10);
       read(pipefds2[0],data1,5);  //  pipefds2[0]
       printf(" \n %d  data is %s \n",getpid(),data1);
   }
   //code for parent  
   
   
   return 0;
}
