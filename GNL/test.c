// This program opens, reads and then stores the bytes read into a buffer
// It then prints the specified number of bytes from the buffer, which is sizeof(buffer)

#include "get_next_line.h"

/*
int main()
{
    char str[] = "bfweyi\n";
    int a = 0;

    while(1)
    {
        write(1, &str[a], 1);
        write(1, "\n", 1);
        a++;
        if (str[a] == '\0')
        {
            write(1, &str[a], 1);
            break;
        }
    }
}*/

int main()
{
    int count;
    char line;
    int fd;

    //Opening the file called testfile with the permission to read only
    fd = fopen("testfile.txt", "r");
    while (1)
    {
        if (fd == NULL)
        {
            printf("Cannot open file\n");
            exit(0);
        }

        line =  int bytesRead = read(fd, storage, 3);
        count++;
        printf("[%d]: %s\n", count, line)
        line == NULL;
    }
    

    close (fd);
    return(0);
}

/*
#include <stdio.h>
#include <unistd.h>

int main()
{   
    FILE *fptr;
    char buffer[100];

    fptr = fopen("testfile.txt", "r");

    if (fptr == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    int fd = fileno(fptr);

    ssize_t bytesRead = read(fd, buffer, sizeof(buffer));

    if (bytesRead > 0)
            write(1, buffer, bytesRead);
    else if (bytesRead == 0)
            printf("End of file reached.\n");
    else
            perror("Error reading file");

    fclose(fptr);

    return 0;
}
*/