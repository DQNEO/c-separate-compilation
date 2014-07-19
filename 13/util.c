#include <stdio.h>
void p(char *s);

void p_good()
{
    p("good ");
}

void p_newline()
{
    p("\n");
}

void p(char *s)
{
    printf("%s", s);
}

