// IntelMKL.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <mkl.h>
#include <time.h>  
#include <conio.h>

#define MATRIX_SIZE 100
#define BUFFER_SIZE MATRIX_SIZE * MATRIX_SIZE
int main(void)
{
	float A[BUFFER_SIZE];
	float B[BUFFER_SIZE];
	float C[BUFFER_SIZE];

	// seed the random number generator
	srand(time(NULL));

	// initialize the matrices with random values
#pragma vector always
	for (int i = 0; i < BUFFER_SIZE; i++)
	{
		A[i] = rand();
		B[i] = rand();
		C[i] = 0;
	}
	// matrix multiply using MKL
	cblas_sgemm(
		CblasRowMajor,
		CblasNoTrans,
		CblasNoTrans,
		MATRIX_SIZE, MATRIX_SIZE, MATRIX_SIZE, 1.0,
		A, MATRIX_SIZE,
		B, MATRIX_SIZE, 0.0,
		C, MATRIX_SIZE
	);

	for (int i = 0; i < BUFFER_SIZE; i++)
	{
		printf("%d\n",C[i]);
		
		
	}
	getch();

}
