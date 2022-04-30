#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int cd(char** args)
{
    if(args[0] != NULL && args[1] != NULL) { return chdir(args[1]); }
}