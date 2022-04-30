#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "rsh.h"

int main(int argc, char** argv)
{
    while (1)
    {
        char line[LINE];
        char* tokens[LINE];

        getcmd(line, tokens);

        parseArgs(line, tokens);
        putc('\n', stdout);

        start(tokens);
    }
}