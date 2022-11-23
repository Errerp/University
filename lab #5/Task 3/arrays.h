#include <stdlib.h>
#include <time.h>
#include <stdio.h>

//выделение памяти под матрицу
int* memory(int n, int m)
{
	int** matr = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
		*(matr + i) = (int*)calloc(m, sizeof(int));
	return matr;
}
void* libertad(int n, int** matr) {
	for (int i = 0; i < n; i++)
		free(*(matr + i));
	free(matr);
}
// печать матрицы
void print_matr(int** matr, int n, int m)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%5d", *(*(matr + i) + j));
		}
		printf("\n");
	}
}

// ввод элементов матрицы c клавиатуры
void input_matr(int** matr, int n, int m)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("input element [%d][%d]\n", i + 1, j + 1);
			while (scanf_s("%d", *(matr + i) + j) != 1) {
				printf("input error\n");
				rewind(stdin);
			}
		}
	}
}
// ввод элементов матрицы рандомом
void rand_matr(int** matr, int n, int m) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			*(*(matr + i) + j) = rand() % 201 - 100;
		}
	}
}
// работа в матрице
void work_in_matr(int** matr, int n, int m)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i + j < n) {
				printf("%5d ", *(*(matr + i) + j));
			}
			else {
				*(matr + i) = realloc(*(matr + i), (m - 1) * sizeof(int));
				m--;
			}
		}
		printf("\n");
	}
}
