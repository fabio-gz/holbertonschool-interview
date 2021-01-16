#include "sandpiles.h"

/**
 * sp_stable - stable sandpile
 * @grid: grid
 * Return: 1 if stable
 */
int sp_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid[i][j] > 3)
				return (0);
	return (1);
}

/**
 * sum_grids - sum two sandpiles
 * @grid1: first sp
 * @grid2: second sp
 */
void sum_grids(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];

}

/**
 * stable - stable sp
 * @grid: sp
 */
void stable(int grid[3][3])
{
	int i, j;
	int tgrid[3][3];

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			tgrid[i][j] = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] >= 4)
			{
				grid[i][j] -= 4;
				if ((i - 1 >= 0) && (i - 1 < 3))
					tgrid[i - 1][j] += 1;
				if ((j - 1 >= 0) && (j - 1 < 3))
					tgrid[i][j - 1] += 1;
				if ((i + 1 >= 0) && (i + 1 < 3))
					tgrid[i + 1][j] += 1;
				if ((j + 1 >= 0) && (j + 1 < 3))
					tgrid[i][j + 1] += 1;
			}
		}
	}
	sum_grids(grid, tgrid);
}

/**
 * print_sp - prints sp
 * @grid: sp
 */
void print_sp(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * sandpiles_sum - sum two sandpiles
 * @grid1: First sp
 * @grid2: Second sp
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	sum_grids(grid1, grid2);

	while (!sp_stable(grid1))
	{
		printf("=\n");
		print_sp(grid1);
		stable(grid1);
	}
}