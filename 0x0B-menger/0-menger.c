#include "menger.h"
/**
 * spaces - checks for spaces
 * @row: row
 * @col: col
 * Return: 1 if cell is a space
 */
int spaces(int row, int col)
{
	while (col && row)
	{
		if (row % 3 == 1 && col % 3 == 1)
			return (1);
		row = row / 3, col = col / 3;
	}
	return (0);
}

/**
 * menger - draws a 2D menger sponge
 * @level: level of the Menger Sponge to draw
 * Return: void
 */
void menger(int level)
{
	int i, j;
	int dimen = pow(3, level);

	for (i = 0; i < dimen; i++)
	{
		for (j = 0; j < dimen; j++)
		{
			if (spaces(i, j))
				printf(" ");
			else
				printf("#");
		}
		puts("");
	}
}
