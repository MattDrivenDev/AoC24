#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

extern void bubble_sort(int arr[], int n);
extern void test_bubble_sort();

/* https://adventofcode.com/2024/day/1 */
int main () 
{
    const char read[] = "r";
    const char filename[] = "input.txt";    
    
    FILE *file = fopen(filename, read);
    char line[15]; 
    char first, last;

    int len, result;
    int *x, *y, *z;

    result = -666;

    // First pass to get length of arrays?
    len = 0;    
    while (fgets(line, sizeof(line), file))
    {
        len++;
    }    
    printf("Line Count = %d\n", len);    
    fclose(file);

    x = (int *)malloc(len * sizeof(int));
    y = (int *)malloc(len * sizeof(int));
    z = (int *)malloc(len * sizeof(int));
   
    int i = 0;
    file = fopen(filename, read);
    while (fgets(line, sizeof(line), file))
    {
        int n;
        char s[6];
        
        strncpy(s, line, 5);
        n = atoi(s);        
        x[i] = n;
        
        strncpy(s, line+8, 5);
        n = atoi(s);
        y[i] = n;

        i++;
    }

    bubble_sort(x, len);
    bubble_sort(y, len);

    int acc = 0;
    for (i = 0; i < len; i++)
    {
        z[i] = x[i] <= y[i] ? y[i] - x[i] : x[i] - y[i];
        printf("%d %d = %d\n", x[i], y[i], z[i]);
        acc = acc + z[i];
    }

    fclose(file);
    printf("Result: %d\n", acc);
    return 0;
}