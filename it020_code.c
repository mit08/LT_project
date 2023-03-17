#include <stdio.h>
#include <string.h>
void main()
{
    FILE *file;
    int i = 0, j = 0, k = 0, l;
    char ch;
    char buff[10][100];
    file = fopen("it020_input.txt", "r");
    if (file == NULL)
    {
        printf("Can't access file.\n");
        return;
    }
    while (ch != EOF)
    {
        ch = fgetc(file);
        if (ch == '\n')
        {
            buff[i][j++] = '\0';
            i++;
            j = 0;
        }
        else
        {
            buff[i][j++] = ch;
        }
    }
    for (k = 0; k <= i; k++)
    {
        printf("Input: %s \n", buff[k]);
        char *s = strtok(buff[k], " ");
        while (s != NULL)
        {
            if ((strcmp(s, "savar") == 0) || (strcmp(s, "bopor") == 0) || (strcmp(s, "sanj") == 0) || (strcmp(s, "raat") == 0))
                printf("Keyword: %s\n", s);
            else if (strcmp(s, "na") == 0)
                printf("Keyword1: %s\n", s);
            else if ((strcmp(s, "sava") == 0) || (strcmp(s, "sada") == 0) || (strcmp(s, "pona") == 0))
                printf("Operation: %s\n", s);
            else if ((strcmp(s, "dodh") == 0) || (strcmp(s, "adhi") == 0))
                printf("Operation1: %s\n", s);
            else if (isdigit(s) == 0)
                printf("Digit: %s\n", s);
            s = strtok(NULL, " ");
        }
        printf("\n");
    }
    fclose(file);
}
