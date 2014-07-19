#include <stdio.h>

void p(char *s)
{
    printf("%s", s);
}

void p_good()
{
    p("good ");
}

void p_newline()
{
    p("\n");
}

