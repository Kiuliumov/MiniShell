#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
    char *line = NULL;
    size_t len = 0;
    char *args[100];
    int i;
    int EOS = -1;

    while (1)
    {
        i = 0;
        write(1, "$ ", 2);

        if (getline(&line, &len, stdin) == EOS)
        {
            break;
        }

        line[strcspn(line, "\n")] = '\0';

        char *token = strtok(line, " ");

        while (token != NULL)
        {
            args[i++] = token;
            token = strtok(NULL, " ");
        }

        if (args[0] != NULL)
        {
            pid_t pid = fork();

            if (pid == 0)
            {
                if (execvp(args[0], args) == -1)
                {
                    perror("shell");
                }
                exit(EXIT_FAILURE);
            }
            else if (pid < 0)
            {
                perror("shell");
            }

            else
            {
                int status;
                waitpid(pid, &status, 0);
            }
        }
    }

    free(line);
    return 0;
}
