#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Don't forget to add ..\utils\sort.c to build command
extern void bubble_sort(int arr[], int n);

/* https://adventofcode.com/2024/day/1 */
int main () 
{
    const char read[] = "r";
    const char filename[] = "input.txt";
    FILE *file = fopen(filename, read);
    char line[15]; 
    char first, last;
    int len, result, acc, i, j;
    int *x, *y, *z;
    i = 0;
    result = 0;
    len = 0;    
    acc = 0;

    // First pass to get length of arrays so we can dynamically
    // allocate the memory for the arrays of numbers.
    while (fgets(line, sizeof(line), file))
    {
        len++;
    }    
    fclose(file);

    x = (int *)malloc(len * sizeof(int));
    y = (int *)malloc(len * sizeof(int));   
    
    // I'm new to this, okay? Instead of going back to the
    // start of the filestream I've closed it and will just
    // open it again.
    file = fopen(filename, read);
    while (fgets(line, sizeof(line), file))
    {
        int n;
        char s[6]; // I think? this needs to be 6 to have a \0
        
        // Copy the first 5 characters from the line and 
        // convert to an int which we put into the left-hand array.
        strncpy(s, line, 5);
        n = atoi(s);        
        x[i] = n;
        
        // Copy the second 5 characters from the line and
        // convert to an int and slot in the right-hand array.
        strncpy(s, line+8, 5);
        n = atoi(s);
        y[i] = n;

        i++;
    }
    fclose(file);

    // Unless I'm beind a dummy this would probably be better
    // as insertion sorts? Where the above while loop does the
    // magic of sorting instead? I don't know... Bubble sort is
    // fine and the algorithm that is easiest to reach for (not
    // to mention absolutely fine for this quiz).
    bubble_sort(x, len);
    bubble_sort(y, len);

    // Basically a map-reduce operation. Take two arrays and map
    // both values into a single and then accumulate them to get 
    // the answer.
    for (i = 0; i < len; i++)
    {
        int n = x[i] - y[i];
        if (n < 0) 
        {
            // Negate negative distance.
            n = -n;
        }
        acc = acc + n;
    }

    printf("Part One: %d\n", acc);

    /* Part 2 of Day 1 occurs from here...
    https://adventofcode.com/2024/day/1#part2 */    
    z = (int *)malloc(len * sizeof(int));   
    for (i = 0; i < len; i++) z[i] = 0;

    // This is a super naive O(n^2) implementation. That said,
    // event with a proper data structure I'd have to populate
    // the data in the first place...? Brainy-no-worky right now.
    for (i = 0; i < len; i++)
    {
        int n = x[i];
        for (j = 0; j < len; j++)
        {
            if (y[j] == n)
            {
                z[i] += n;
            }
        }
    }

    // Finally, thread the accumulator through our z array just to sum.
    acc = 0;
    for (i = 0; i < len; i++)
    {
        acc += z[i];
    }

    printf("Part Two: %d\n", acc);

    free(x);
    free(y);
    free(z);

    return 0;
}