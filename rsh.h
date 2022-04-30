#ifndef RSH_H
#define RSH_H

#define SIZEOF(x) (sizeof(x) / sizeof(*x))

#define LINE 4096

static char shell$[] = "[\e[38;5;33m\\u\e[38;5;15m@\e[38;5;76m\\h \e[38;5;124m\\d\e[38;5;15m]$ ";

static char history[] = "~/.bash_history";

int cd(char** argv);

void echo(int b);

void getcmd(char* line, char** tokens);

void getHistory(char* line, const size_t max);

void parseArgs(char* line, char** tokens);

int start(char** tokens);

#endif
