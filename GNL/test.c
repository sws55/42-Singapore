// This program opens, reads and then stores the bytes read into a buffer
// It then prints the specified number of bytes from the buffer, which is sizeof(buffer)

#include "get_next_line.h"

int main()
{   
    //Declaring a FILE strcture called 'fptr'
    FILE *fptr;
    char buffer[100];

    // Open the file 'testfile' for reading only
    fptr = fopen("testfile.txt", "r");

    //If opening the file fails, write 'Error opening file' and return 1
    if (fptr == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    // Get the file descriptor associated with the FILE stream fptr
    int fd = fileno(fptr);

    // Read data using the file descriptor into the buffer and number of bytes is stored in 'bytesRead'
    // The number of bytes read at a time is the size of the buffer, so it is read all at once
    ssize_t bytesRead = read(fd, buffer, sizeof(buffer));

    // If bytes read > 0, write the same number of bytes from the buffer, if not then print EOF
    if (bytesRead > 0)
            write(1, buffer, bytesRead);
    else if (bytesRead == 0)
            printf("End of file reached.\n");
    else
            perror("Error reading file");

    // Close the FILE stream
    fclose(fptr);

    return 0;
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

/*
//In the test function, the file is opened and GNL is repeatedly called until the end of file 
int main()
{
    //fptr is a pointer to a FILE structure
    FILE *fptr;
    //Declaring variables for the file name and another used to read characters from the file
    char c;

    //Opening the file called testfile with the permission to read only
    fptr = fopen("testfile.txt", "r");
    if (fptr == NULL)
    {
        printf("Cannot open file\n");
        exit(0);
    }
    //Read the content of the file
    c = fgetc(fptr);
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(fptr);
    }
    fclose(fptr);
    return(0);
}
*/