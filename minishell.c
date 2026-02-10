#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
    char *line = NULL;
    size_t len = 0;
    int EOS = -1;

    while (1)
    {
        write(1, "$ ", 2);

        if (getline(&line, &len, stdin) == EOS)
        {
            break;
        }

        pause();
    }
    return 0;
}
