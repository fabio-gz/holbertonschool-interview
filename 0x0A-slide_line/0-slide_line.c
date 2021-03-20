#include "slide_line.h"
/**
 * slide_line - 2048 game mechanics
 * @line: points to an array of integers containing size elements
 * @size: array size
 * @direction: left or right
 * Return: 1 upon success
 */
int slide_line(int *line, size_t size, int direction)
{
	int i = 0, j = 0, size_n = size, data = 0;

	if (line == NULL || (direction != 0 && direction != 1))
		return (0);

	if (direction == 0)
	{
		for (i = 0; i < size_n; i++)
		{
			if (line[i] == line[i + 1]  && line[i] != 0)
			{
				line[j++] = line[i] + line[i + 1], i++;
				line[j] = 0;
			}
			else if (line[i] != 0)
			{
				if (data == line[i])
				{
					line[--j] = data * 2;
					j++;
					data = 0;
				}
				else
					line[j++] = line[i], data = line[i];
			}
		}
		for (i = j; i < size_n; i++)
			line[i] = 0;
	}
	else
	{
		j = size - 1;
		for (i = size_n - 1; i > -1; i--)
		{
			if (line[i] == line[i - 1]  && line[i] != 0)
			{
				line[j--] = line[i] + line[i - 1], i--;
				line[j] = 0;
			}
			else if (line[i] != 0)
			{
				if (data == line[i])
				{
					line[++j] = data * 2;
					j--;
					data = 0;
				}
				else
					line[j--] = line[i], data = line[i];
			}
		}
		for (i = j; i > -1; i--)
			line[i] = 0;
	} return (1);
}
