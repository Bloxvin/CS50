#include <stdio.h>
#include <cs50.h>

int GAP_HASH = 2;
// Pyramid - Kaung Myat Kyaw

void draw_horizontal(int length, char texture);

int main()
{
    int height;
    do {
        height = get_int("Height :");
    } while (height < 1);


    for (int i=1; i<height+1; i++)
    {
        draw_horizontal(height-i, ' ');
        draw_horizontal(i, '#');
        draw_horizontal(GAP_HASH, ' ');
        draw_horizontal(i, '#');
        printf("\n");

    }

}


void draw_horizontal(int length, char texture)
{
    for (int i=0; i<length; i++)
    {
        printf("%c", texture);
    }

}

