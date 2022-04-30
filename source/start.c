#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#include "rsh.h"

int start(char** tokens)
{
    pid_t pid, wpid;
    int status;

    if(!strcmp(tokens[0], "cd")) { cd(tokens); return 0; }

    pid = fork();

    if(pid == 0)
    {
        if(execvp(tokens[0], tokens) == -1)
        {
            printf("execvp() failed\n");
        }
        exit(1);
    }
    else if(pid < 0)
    {
        printf("fork() failed");
    }
    else
    {
        do 
        {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return status;

}