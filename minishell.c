#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    while (1)
    {
        write(1, "$ ", 2);
        pause();
    }
    return 0;
}
