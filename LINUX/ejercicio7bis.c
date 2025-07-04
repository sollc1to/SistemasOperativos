#include <stdio.h>.

int main(){
int pid; 

pid = fork();


if(pid == 0){
execv(pid, "/bin/date/");
}else{ 
exit(0);
}

}
