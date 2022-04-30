#include <stdio.h>
#include <termios.h>

void echo(int b) 
{
    if(b)
    {
        struct termios term;
        tcgetattr(fileno(stdin), &term);
        term.c_lflag &= ~ECHO;
        term.c_lflag &= ~ICANON;
        tcsetattr(fileno(stdin), 0, &term);
    }
    else
    {
        struct termios term;
        tcgetattr(fileno(stdin), &term);
        term.c_lflag |= ECHO;
        term.c_lflag |= ICANON;
        tcsetattr(fileno(stdin), 0, &term);
    }
}