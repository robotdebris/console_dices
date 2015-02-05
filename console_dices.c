#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DICES 6
#define DICE_IMG_W 9
#define DICE_IMG_H 5
#define DICE_IMG_S 3

#define DICE_SPACE_STR "   "
#define ROW_LEN MAX_DICES*(DICE_IMG_W + DICE_IMG_S) + 1

char *dice_sides[] = 
{
"+-------+",
"+       +",
"+   0   +",
"+       +",
"+-------+",
"+-------+",
"+ 0     +",
"+       +",
"+     0 +",
"+-------+",
"+-------+",
"+ 0     +",
"+   0   +",
"+     0 +",
"+-------+",
"+-------+",
"+ 0   0 +",
"+       +",
"+ 0   0 +",
"+-------+",
"+-------+",
"+ 0   0 +",
"+   0   +",
"+ 0   0 +",
"+-------+",
"+-------+",
"+ 0   0 +",
"+ 0   0 +",
"+ 0   0 +",
"+-------+",
};

void make_rows(int nd, char *rows)
{
    int row, k, d;
    
    for(k = 0; k < nd; k++)
    {
        d = rand() % 6;
        for(row = 0; row < DICE_IMG_H; row++)
        {
            strcat(&(rows[ROW_LEN*row]), dice_sides[DICE_IMG_H*d + row]);
            strcat(&(rows[ROW_LEN*row]), DICE_SPACE_STR);
        }
    }
}

void print_rows(char *rows)
{
    int row;
    for(row = 0; row < DICE_IMG_H; row++)
    {
        printf("%s\n", &(rows[ROW_LEN*row]));
    }
}

int main(int argc, char **argv)
{
    int nd;
    char rows[ROW_LEN*DICE_IMG_H];
    
    sscanf(argv[1], "%d", &nd);
    
    if(argc == 1 || nd < 1 || nd > MAX_DICES)
    {
        printf("Input number of dices between 1 and %d\n", MAX_DICES);
        return(EXIT_FAILURE);
    }
    
    memset(rows, 0, sizeof(rows));
    
    make_rows(nd, rows);
 
    print_rows(rows);   
    
    return(EXIT_SUCCESS);
}
