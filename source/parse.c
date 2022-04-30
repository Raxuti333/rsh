#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "rsh.h"

void parseArgs(char* line, char** tokens)
{
    char copy[LINE];
    memset(copy, 0, LINE);

    size_t copyIndex = 0;

    for(size_t i = 0; tokens[i] != NULL; ++i)
    {
        size_t length = strlen(tokens[i]);

        if(tokens[i][0] == '~') 
        {
            char* homedir = getenv("HOME");
            size_t homelen = strlen(homedir);

            if(length == 1)
            {
                length = homelen;
                memcpy(copy + copyIndex, homedir, length);
            }
            else
            {
                memcpy(copy + copyIndex, homedir, homelen);
                memcpy(copy + copyIndex + homelen, tokens[i] + 1, length - 1);
                length = length - 1 + homelen;
            }
        }
        else
        {
            memcpy(copy + copyIndex, tokens[i], length); 
        }
        
        copy[copyIndex + length] = ' ';
        copyIndex += length + 1;
    }

    memcpy(line, copy, LINE);

    tokens[0] = strtok(line, " ");
    for(size_t i = 1; ((tokens[i] = strtok(NULL, " ")) != NULL) && (i < LINE); ++i);
}