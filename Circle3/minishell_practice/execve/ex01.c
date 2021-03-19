#include <stdio.h>

extern char **environ;

int main()
{
    int i = 0;

    printf("=== environment list ===\n");

    for(i=0; environ[i];i++)
    {
        printf("<%2d>: %s\n", i, environ[i]);
    }
    return 0;
}
