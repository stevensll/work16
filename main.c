#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    printf("Parent with pid %d\n", getpid());
    int parent, status, w;
    parent = fork();
    if(parent){ //only fork the parent
        parent = fork();
    }
    if(parent){
        w = wait(&status); //wait returns the pid of the first finished child process
        printf("Child %d slept for %ds, parent %d finished\n", w, WEXITSTATUS(status), getpid());
    }

    if(!parent){
        srand(getpid());
        int r = rand() % 3 + 2;
        printf("Child %d sleeping for %ds\n", getpid(), r);
        sleep(r);
        printf("Child %d done\n", getpid());
        return r; // want to return the amount of time it took to sleep
    }
    return 0;
}