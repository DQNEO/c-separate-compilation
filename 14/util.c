#include <stdio.h>
#include "util.h"

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

