/*There are nine clocks in a 3*3 array (figure 1). The goal is to return all the dials to 12 o'clock with as few moves as possible. There are nine different allowed ways to turn the dials on the clocks. Each such way is called a move. Select for each move a number 1 to 9. That number will turn the dials 90' (degrees) clockwise on those clocks which are affected according to figure 2 below.
Your program is to read from standard input. Nine numbers give the start positions of the dials. 0=12 o'clock, 1=3 o'clock, 2=6 o'clock, 3=9 o'clock.
Your program is to write to standard output. Output a shortest sorted sequence of moves (numbers), which returns all the dials to 12 o'clock. You are convinced that the answer is unique.
Sample Input
3 3 0
2 2 2
2 1 2
Sample Output
4 5 8 9*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include <string.h>
int main()
{
    int i, a[10], b[10], c[10];
    while (scanf("%d", &a[1]) != EOF)
    {
        for (i = 2; i <= 9; i++)
            scanf("%d", &a[i]);
        for (b[1] = 0; b[1] <= 3; b[1]++)
            for (b[2] = 0; b[2] <= 3; b[2]++)
                for (b[3] = 0; b[3] <= 3; b[3]++)
                    for (b[4] = 0; b[4] <= 3; b[4]++)
                        for (b[5] = 0; b[5] <= 3; b[5]++)
                            for (b[6] = 0; b[6] <= 3; b[6]++)
                                for (b[7] = 0; b[7] <= 3; b[7]++)
                                    for (b[8] = 0; b[8] <= 3; b[8]++)
                                        for (b[9] = 0; b[9] <= 3; b[9]++)
                                        {
                                            c[1] = (a[1] + b[1] + b[2] + b[4]) % 4;
                                            c[2] = (a[2] + b[1] + b[2] + b[3] + b[5]) % 4;
                                            c[3] = (a[3] + b[2] + b[3] + b[6]) % 4;
                                            c[4] = (a[4] + b[1] + b[4] + b[5] + b[7]) % 4;
                                            c[5] = (a[5] + b[1] + b[3] + b[5] + b[7] + b[9]) % 4;
                                            c[6] = (a[6] + b[3] + b[5] + b[6] + b[9]) % 4;
                                            c[7] = (a[7] + b[4] + b[7] + b[8]) % 4;
                                            c[8] = (a[8] + b[5] + b[7] + b[8] + b[9]) % 4;
                                            c[9] = (a[9] + b[6] + b[8] + b[9]) % 4;
                                            if (c[1] + c[2] + c[3] + c[4] + c[5] + c[6] + c[7] + c[8] + c[9] == 0)
                                            {
                                                for (i = 0; i < b[1]; i++) printf("1 ");
                                                for (i = 0; i < b[2]; i++) printf("2 ");
                                                for (i = 0; i < b[3]; i++) printf("3 ");
                                                for (i = 0; i < b[4]; i++) printf("4 ");
                                                for (i = 0; i < b[5]; i++) printf("5 ");
                                                for (i = 0; i < b[6]; i++) printf("6 ");
                                                for (i = 0; i < b[7]; i++) printf("7 ");
                                                for (i = 0; i < b[8]; i++) printf("8 ");
                                                for (i = 0; i < b[9]; i++) printf("9 ");
                                                printf("\n");

                                            }
                                        }
    }
   
}