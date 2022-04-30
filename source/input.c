#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "rsh.h"

static void shinfo();

void getcmd(char* line, char** tokens)
{
    if(line == NULL) { return; }

    memset(line, 0, LINE);
    memset(tokens, 0, LINE * sizeof(char*));

    shinfo();

    echo(1);
    for(size_t i = 0; (line[i] = getchar()) && (i < LINE - 1); ++i)
    {
        putc(line[i], stdout);

        if(line[i] == 0x7f && i != 0) { if(line[0] != 0x7f) { printf("\b \b"); }; i -= 2; }
        if(line[i] == '\n') { line[i] = 0; break; }
    }
    echo(0);

    tokens[0] = strtok(line, " ");
    for(size_t i = 1; ((tokens[i] = strtok(NULL, " ")) != NULL) && (i < LINE); ++i);
}

static void shinfo()
{
    char cwd[256], user[32], host[63];
    getcwd(cwd, sizeof(cwd));
    getlogin_r(user, sizeof(user));
    gethostname(host, sizeof(host));

    unsigned int length = strlen(shell$);
    
    for(unsigned int i = 0; i < length; i++)
    {
        if(shell$[i] == '\\' && i + 1 < length) 
        {
            switch(shell$[i + 1])
            {
                case 'u': printf("%s", user); break;
                case 'h': printf("%s", host); break;
                case 'd': printf("%s", cwd); break;
            }

            i += 2;
        }

        putchar(shell$[i]);
    }
}
