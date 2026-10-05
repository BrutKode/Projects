#include "stdio.h"
#include "stdlib.h"

int** print2DArray(int **arr, int row, int col);

int main(void)
{
	//Abstract
	/*
	int *x1 = calloc(5, sizeof(int));
	int *x2 = calloc(5, sizeof(int));
	int *x3 = calloc(5, sizeof(int));
	int **y = calloc(3, sizeof(int*));
	y[0] = x1;
	y[1] = x2;
	y[2] = x3;
	for(int i=0; i<3; ++i)
	{
		for(int j=0; j<5; ++j)
		{
			printf("%i ", y[i][j]);
		}
		printf("\n");
	}

	free(x1);
	free(x2);
	free(x3);
	free(y);
	*/
	
	int nx, ny;
	int *px = &nx;
	int *py = &ny;
	printf("Enter the number of rows: ");
	scanf("%i", py);
	printf("Enter the number of columns: ");
	scanf("%i", px);

	printf("Your 2Dimensional matrix is of %ix%i\n", ny, nx);

	int **y = calloc(ny, sizeof(int*));
	for(int i=0; i<ny; ++i)
	{
		int *x = calloc(nx, sizeof(int));
		y[i] = x;
	}

	for(int i=0; i<ny; ++i)
	{
		for(int j=0; j<nx; ++j)
		{
			printf("The value of element a[%i][%i] is: ", i, j);
			scanf("%i", &y[i][j]);
		}
	}
	
	printf("Here is the matrix:\n");
	print2DArray(y, ny, nx);
	
	
	printf("Here is the transpose of the matrix:\n");
	int **z = calloc(nx, sizeof(int*));
	for(int i=0; i<nx; ++i)
	{
		int *x = calloc(ny, sizeof(int));
		z[i] = x;
	}
	for(int i=0; i<nx; ++i)
	{
		for(int j=0; j<ny; ++j)
		{
			z[i][j] = y[j][i];
			//printf("%i " ,y[j][i]);
		}
		//printf("\n");
	}
	print2DArray(z, nx, ny);

	for(int i=0; i<ny; ++i)
	{
		free(y[i]);
	}
	free(y);

	for(int i=0; i<nx; ++i)
	{
		free(z[i]);
	}
	free(z);
	
	return 0;
}

int** print2DArray(int **arr, int row, int col)
{
	//TODO
	for(int i=0; i<row; ++i)
	{
		for(int j=0; j<col; ++j)
		{
			printf("%i ", arr[i][j]);
		}
		printf("\n");
	}
	return arr;
}
