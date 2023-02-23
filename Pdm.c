//Gabriel Vasconcelos de Arruda. nUSP 12676192
//Gabriel Carvalho Fernandes. nUSP 13696662
//Beatriz Vieira da Silva Andrade. nUSP 13692362
//Gustavo Alves da Silva Souza. nUSP 13727485

#include <stdio.h>
#include <stdlib.h>

int **createMatrix(int rows, int cols)
{
	int dim = rows * cols;
	int **matrix = (int **)malloc(dim * sizeof(int *));

	for (int idx = 0; idx < dim; idx++)
	{
		matrix[idx] = (int *)malloc(dim * sizeof(int));
	}

	return matrix;
}

int **fillMatrix(int **matrix, int rows, int cols)
{
	int total = (rows * (cols - 1)) + (cols * (rows - 1));
	int x, y, value;

	for (int idx = 0; idx < total; idx++)
	{
		scanf("%d %d %d", &x, &y, &value);
		matrix[x][y] = value;
	}

	return matrix;
}

int friendsAux(int *cache, int rows, int cols, int **m, int q)
{
	int total = rows * cols;
	int right = 0, down = 0, max;

	if (cache[q] == -1)
	{
		if (q != (total - 1))
		{
			if ((q % cols) != (cols - 1))
			{
				right = m[q][q + 1] + friendsAux(cache, rows, cols, m, q + 1);
			}
			if (q < ((total) - cols))
			{
				down = m[q][q + cols] + friendsAux(cache, rows, cols, m, q + cols);
			}
			
			if (down > right)
				max = down;
			else
				max = right;
		}
		else
		{
			max = 0;
		}
	}
   
	cache[q] = max;
	return cache[q];
}
void desaloca_mtx(int** m,int rows){
    for (int i = 0; i < rows; i++)
        {
            free(m[i]);
        }
        free(m);
}
int friends(int rows, int cols, int **m)
{
	int a, total = rows * cols;
	int *cache = (int *)malloc(sizeof(int) * (total) + 1);

	for (int idx = 0; idx <= total; idx++)
	{
		cache[idx] = -1;
	}
	a = friendsAux(cache, rows, cols, m, 0);
	return a;
}

int main()
{
	int rows;
	int cols;
    
	scanf("%d %d", &rows, &cols);
	int **matrix = createMatrix(rows, cols);
	fillMatrix(matrix, rows, cols);
	int result = friends(rows, cols, matrix);
	printf("%d", result);
	desaloca_mtx(matrix,rows);

    return 0;
}