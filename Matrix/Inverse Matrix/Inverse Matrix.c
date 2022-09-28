#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<math.h>

int select_size = 0;

float Matrix_2x2[2][2] = { 0, };
float Matrix_3x3[3][3] = { 0, };
float Matrix_4x4[4][4] = { 0, };

float IMatrix_2x2[2][2] = { 0, };
float IMatrix_3x3[3][3] = { 0, }; 
float IMatrix_4x4[4][4] = { 0, };

void Inverse_Matrix_2x2(float d);
void Inverse_Matrix_3x3(float d);
float Inverse_Matrix_4x4();

int i = 0, j = 0;

int main(void) 
{
	int size = 0;
	float insert_data = 0.0;
	float d = 0.0;

	printf("Select Matrix Size (2~4) : ");
	scanf("%d", &size);

	if (size == 2)
	{
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
			{
				printf("(%d, %d) = ", i, j);
				scanf("%f", &insert_data);

				Matrix_2x2[i][j] = insert_data;
			}
		}
		d = Matrix_2x2[0][0] * Matrix_2x2[1][1] - Matrix_2x2[0][1] * Matrix_2x2[1][0];

		if (d == 0)
			printf("역행렬이 존재하지 않음\n");
		else
		{
			Inverse_Matrix_2x2(d);

			printf("Inverse\n");
			for (i = 0; i < size; i++)
			{
				for (j = 0; j < size; j++)
				{
					printf("%.2f ", IMatrix_2x2[i][j]);
				}
				printf("\n");
			}
		}
	}

	if (size == 3)
	{
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
			{
				printf("(%d, %d) = ", i, j);
				scanf("%f", &insert_data);

				Matrix_3x3[i][j] = insert_data;
			}
		}

		d   = Matrix_3x3[0][0] * Matrix_3x3[1][1] * Matrix_3x3[2][2] - Matrix_3x3[0][0] * Matrix_3x3[1][2] * Matrix_3x3[2][1] 
			+ Matrix_3x3[0][1] * Matrix_3x3[1][2] * Matrix_3x3[2][0] - Matrix_3x3[0][1] * Matrix_3x3[1][0] * Matrix_3x3[2][2] 
			+ Matrix_3x3[0][2] * Matrix_3x3[1][0] * Matrix_3x3[2][1] - Matrix_3x3[0][2] * Matrix_3x3[1][1] * Matrix_3x3[2][0];

		if (d == 0)
			printf("역행렬이 존재하지 않음\n");

		else
		{
			Inverse_Matrix_3x3(d);

			printf("Inverse\n");
			for (i = 0; i < size; i++)
			{
				for (j = 0; j < size; j++)
				{
					printf("%.2f ", IMatrix_3x3[i][j]);
				}
				printf("\n");
			}
		}
	}

	if (size == 4)
	{
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
			{
				printf("(%d, %d) = ", i, j);
				scanf("%f", &insert_data);

				Matrix_4x4[i][j] = insert_data;
			}
		}

		d = Inverse_Matrix_4x4();

		if(d == 0)
			printf("역행렬이 존재하지 않음\n");
		else
		{
			printf("Inverse\n");
			for (i = 0; i < size; i++)
			{
				for (j = 0; j < size; j++)
				{
					printf("%.2f ", IMatrix_4x4[i][j] = IMatrix_4x4[i][j] / d);
				}
				printf("\n");
			}
		}
	}
}

void Inverse_Matrix_2x2(float d)
{
	IMatrix_2x2[0][0] = Matrix_2x2[1][1] / d;
	IMatrix_2x2[0][1] = (-1) * Matrix_2x2[0][1] / d;
	IMatrix_2x2[1][0] = (-1) * Matrix_2x2[1][0] / d;
	IMatrix_2x2[1][1] = Matrix_2x2[0][0] / d;
}

void Inverse_Matrix_3x3(float d)
{
	for (i = 0; i < 3; i += 1) {
		for (j = 0; j < 3; j += 1) {
			IMatrix_3x3[i][j] = (Matrix_3x3[(i + 1) % 3][(j + 1) % 3] * Matrix_3x3[(i + 2) % 3][(j + 2) % 3] - Matrix_3x3[(i + 1) % 3][(j + 2) % 3] * Matrix_3x3[(i + 2) % 3][(j + 1) % 3]) / d;
		}
	}
}

float Inverse_Matrix_4x4()
{
	float determinant = 0.0f;

    IMatrix_4x4[0][0] = Matrix_4x4[1][1] * Matrix_4x4[2][2] * Matrix_4x4[3][3] - Matrix_4x4[1][1] * Matrix_4x4[2][3] * Matrix_4x4[3][2] - 
						Matrix_4x4[2][1] * Matrix_4x4[1][2] * Matrix_4x4[3][3] + Matrix_4x4[2][1] * Matrix_4x4[1][3] * Matrix_4x4[3][2] + 
						Matrix_4x4[3][1] * Matrix_4x4[1][2] * Matrix_4x4[2][3] - Matrix_4x4[3][1] * Matrix_4x4[1][3] * Matrix_4x4[2][2];
	
	IMatrix_4x4[0][1] = - Matrix_4x4[0][1] * Matrix_4x4[2][2] * Matrix_4x4[3][3] + Matrix_4x4[0][1] * Matrix_4x4[2][3] * Matrix_4x4[3][2]
						+ Matrix_4x4[2][1] * Matrix_4x4[0][2] * Matrix_4x4[3][3] - Matrix_4x4[2][1] * Matrix_4x4[0][3] * Matrix_4x4[3][2]
						- Matrix_4x4[3][1] * Matrix_4x4[0][2] * Matrix_4x4[2][3] + Matrix_4x4[3][1] * Matrix_4x4[0][3] * Matrix_4x4[2][2];

	IMatrix_4x4[0][2] =	Matrix_4x4[0][1] * Matrix_4x4[1][2] * Matrix_4x4[3][3] - Matrix_4x4[0][1] * Matrix_4x4[1][3] * Matrix_4x4[3][2]	- 
						Matrix_4x4[1][1] * Matrix_4x4[0][2] * Matrix_4x4[3][3] + Matrix_4x4[1][1] * Matrix_4x4[0][3] * Matrix_4x4[3][2]	+ 
						Matrix_4x4[3][1] * Matrix_4x4[0][2] * Matrix_4x4[1][3] - Matrix_4x4[3][1] * Matrix_4x4[0][3] * Matrix_4x4[1][2];

	IMatrix_4x4[0][3] =	- Matrix_4x4[0][1] * Matrix_4x4[1][2] * Matrix_4x4[2][3] + Matrix_4x4[0][1] * Matrix_4x4[1][3] * Matrix_4x4[2][2] 
						+ Matrix_4x4[1][1] * Matrix_4x4[0][2] * Matrix_4x4[2][3] - Matrix_4x4[1][1] * Matrix_4x4[0][3] * Matrix_4x4[2][2]
						- Matrix_4x4[2][1] * Matrix_4x4[0][2] * Matrix_4x4[1][3] + Matrix_4x4[2][1] * Matrix_4x4[0][3] * Matrix_4x4[1][2];

	IMatrix_4x4[1][0] = - Matrix_4x4[1][0] * Matrix_4x4[2][2] * Matrix_4x4[3][3] + Matrix_4x4[1][0] * Matrix_4x4[2][3] * Matrix_4x4[3][2]
						+ Matrix_4x4[2][0] * Matrix_4x4[1][2] * Matrix_4x4[3][3] - Matrix_4x4[2][0] * Matrix_4x4[1][3] * Matrix_4x4[3][2]
						- Matrix_4x4[3][0] * Matrix_4x4[1][2] * Matrix_4x4[2][3] + Matrix_4x4[3][0] * Matrix_4x4[1][3] * Matrix_4x4[2][2];

	IMatrix_4x4[1][1] =	Matrix_4x4[0][0] * Matrix_4x4[2][2] * Matrix_4x4[3][3] - Matrix_4x4[0][0] * Matrix_4x4[2][3] * Matrix_4x4[3][2] - 
						Matrix_4x4[2][0] * Matrix_4x4[0][2] * Matrix_4x4[3][3] + Matrix_4x4[2][0] * Matrix_4x4[0][3] * Matrix_4x4[3][2]	+ 
						Matrix_4x4[3][0] * Matrix_4x4[0][2] * Matrix_4x4[2][3] - Matrix_4x4[3][0] * Matrix_4x4[0][3] * Matrix_4x4[2][2];

	IMatrix_4x4[1][2] =	- Matrix_4x4[0][0] * Matrix_4x4[1][2] * Matrix_4x4[3][3] + Matrix_4x4[0][0] * Matrix_4x4[1][3] * Matrix_4x4[3][2]
						+ Matrix_4x4[1][0] * Matrix_4x4[0][2] * Matrix_4x4[3][3] - Matrix_4x4[1][0] * Matrix_4x4[0][3] * Matrix_4x4[3][2]
						- Matrix_4x4[3][0] * Matrix_4x4[0][2] * Matrix_4x4[1][3] + Matrix_4x4[3][0] * Matrix_4x4[0][3] * Matrix_4x4[1][2];

	IMatrix_4x4[1][3] = Matrix_4x4[0][0] * Matrix_4x4[1][2] * Matrix_4x4[2][3] - Matrix_4x4[0][0] * Matrix_4x4[1][3] * Matrix_4x4[2][2] - 
						Matrix_4x4[1][0] * Matrix_4x4[0][2] * Matrix_4x4[2][3] + Matrix_4x4[1][0] * Matrix_4x4[0][3] * Matrix_4x4[2][2]	+ 
						Matrix_4x4[2][0] * Matrix_4x4[0][2] * Matrix_4x4[1][3] - Matrix_4x4[2][0] * Matrix_4x4[0][3] * Matrix_4x4[1][2];

	IMatrix_4x4[2][0] =	Matrix_4x4[1][0] * Matrix_4x4[2][1] * Matrix_4x4[3][3] - Matrix_4x4[1][0] * Matrix_4x4[2][3] * Matrix_4x4[3][1]
						- Matrix_4x4[2][0] * Matrix_4x4[1][1] * Matrix_4x4[3][3] + Matrix_4x4[2][0] * Matrix_4x4[1][3] * Matrix_4x4[3][1]
						+ Matrix_4x4[3][0] * Matrix_4x4[1][1] * Matrix_4x4[2][3] - Matrix_4x4[3][0] * Matrix_4x4[1][3] * Matrix_4x4[2][1];

	IMatrix_4x4[2][1] =	- Matrix_4x4[0][0] * Matrix_4x4[2][1] * Matrix_4x4[3][3] + Matrix_4x4[0][0] * Matrix_4x4[2][3] * Matrix_4x4[3][1]
						+ Matrix_4x4[2][0] * Matrix_4x4[0][1] * Matrix_4x4[3][3] - Matrix_4x4[2][0] * Matrix_4x4[0][3] * Matrix_4x4[3][1]
						- Matrix_4x4[3][0] * Matrix_4x4[0][1] * Matrix_4x4[2][3] + Matrix_4x4[3][0] * Matrix_4x4[0][3] * Matrix_4x4[2][1];

	IMatrix_4x4[2][2] =	Matrix_4x4[0][0] * Matrix_4x4[1][1] * Matrix_4x4[3][3] - Matrix_4x4[0][0] * Matrix_4x4[1][3] * Matrix_4x4[3][1]
						- Matrix_4x4[1][0] * Matrix_4x4[0][1] * Matrix_4x4[3][3] + Matrix_4x4[1][0] * Matrix_4x4[0][3] * Matrix_4x4[3][1]
						+ Matrix_4x4[3][0] * Matrix_4x4[0][1] * Matrix_4x4[1][3] - Matrix_4x4[3][0] * Matrix_4x4[0][3] * Matrix_4x4[1][1];

	IMatrix_4x4[2][3] = - Matrix_4x4[0][0] * Matrix_4x4[1][1] * Matrix_4x4[2][3] + Matrix_4x4[0][0] * Matrix_4x4[1][3] * Matrix_4x4[2][1]
						+ Matrix_4x4[1][0] * Matrix_4x4[0][1] * Matrix_4x4[2][3] - Matrix_4x4[1][0] * Matrix_4x4[0][3] * Matrix_4x4[2][1]
						- Matrix_4x4[2][0] * Matrix_4x4[0][1] * Matrix_4x4[1][3] + Matrix_4x4[2][0] * Matrix_4x4[0][3] * Matrix_4x4[1][1];

	IMatrix_4x4[3][0] = - Matrix_4x4[1][0] * Matrix_4x4[2][1] * Matrix_4x4[3][2] + Matrix_4x4[1][0] * Matrix_4x4[2][2] * Matrix_4x4[3][1]
						+ Matrix_4x4[2][0] * Matrix_4x4[1][1] * Matrix_4x4[3][2] - Matrix_4x4[2][0] * Matrix_4x4[1][2] * Matrix_4x4[3][1]
						- Matrix_4x4[3][0] * Matrix_4x4[1][1] * Matrix_4x4[2][2] + Matrix_4x4[3][0] * Matrix_4x4[1][2] * Matrix_4x4[2][1];

	IMatrix_4x4[3][1] =	Matrix_4x4[0][0] * Matrix_4x4[2][1] * Matrix_4x4[3][2] - Matrix_4x4[0][0] * Matrix_4x4[2][2] * Matrix_4x4[3][1]
						- Matrix_4x4[2][0] * Matrix_4x4[0][1] * Matrix_4x4[3][2] + Matrix_4x4[2][0] * Matrix_4x4[0][2] * Matrix_4x4[3][1]
						+ Matrix_4x4[3][0] * Matrix_4x4[0][1] * Matrix_4x4[2][2] - Matrix_4x4[3][0] * Matrix_4x4[0][2] * Matrix_4x4[2][1];

	IMatrix_4x4[3][2] =	- Matrix_4x4[0][0] * Matrix_4x4[1][1] * Matrix_4x4[3][2] + Matrix_4x4[0][0] * Matrix_4x4[1][2] * Matrix_4x4[3][1]
						+ Matrix_4x4[1][0] * Matrix_4x4[0][1] * Matrix_4x4[3][2] - Matrix_4x4[1][0] * Matrix_4x4[0][2] * Matrix_4x4[3][1]
						- Matrix_4x4[3][0] * Matrix_4x4[0][1] * Matrix_4x4[1][2] + Matrix_4x4[3][0] * Matrix_4x4[0][2] * Matrix_4x4[1][1];

	IMatrix_4x4[3][3] =	Matrix_4x4[0][0] * Matrix_4x4[1][1] * Matrix_4x4[2][2] - Matrix_4x4[0][0] * Matrix_4x4[1][2] * Matrix_4x4[2][1]
						- Matrix_4x4[1][0] * Matrix_4x4[0][1] * Matrix_4x4[2][2] + Matrix_4x4[1][0] * Matrix_4x4[0][2] * Matrix_4x4[2][1]
						+ Matrix_4x4[2][0] * Matrix_4x4[0][1] * Matrix_4x4[1][2] - Matrix_4x4[2][0] * Matrix_4x4[0][2] * Matrix_4x4[1][1];

	determinant = Matrix_4x4[0][0] * IMatrix_4x4[0][0] + Matrix_4x4[0][1] * IMatrix_4x4[1][0] + Matrix_4x4[0][2] * IMatrix_4x4[2][0] + Matrix_4x4[0][3] * IMatrix_4x4[3][0];

	return determinant;
}