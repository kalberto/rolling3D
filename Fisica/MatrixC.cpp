#include "MatrixC.h"
#include <iostream>
#include <math.h>

using namespace std;

//pow(a,b) retorna o valor de a elevado a b

//Verifica se é triangular                                                                                          FUNCIONANDO
TriangularInfo isTriangular(const Matrix* matrix)
{
	TriangularInfo* triangular = new TriangularInfo;
	int ver = 0, ver2=0, cont=0, cont2=0;
	for (int i = 0; i < matrix->height; i++)
	{
		for (int j = 0; j < matrix->width; j++)
		{
			if (j>i)
			{
				cont++;
				if (matrix->matrix[i][j] != 0)
				{
					triangular->isPositive = false;
				}
				else
				{
					ver++;
				}
			}			
			if (j < i)
			{
				cont2++;
				if (matrix->matrix[i][j] != 0)
				{
					triangular->isTriangular = false;
					
				}
				else
				{
					ver2++;
				}
			}
			
		}
	}
	if (cont / ver == 1)
	{
		triangular->isTriangular = true;
		triangular->isPositive = true;
		return *(triangular);
	}
	else if (cont2 / ver2 == 1)
	{
		triangular->isTriangular = true;
		triangular->isPositive = false;
		return *(triangular);
	}
	return *(triangular);
}

// ve se é nula                                                                                                      FUNCIONANDO
bool isNull(const Matrix* matrix)
{
	
	for (int i = 0; i < matrix->width; i++)
	{
		for (int g = 0; g < matrix->height; g++)
		{

			if (matrix->matrix[i][g] != 0)
			{
				return false;
			}
		}
	}
	return true;
}

//verifica se é quadrada                                                                                             FUNCIONANDO
bool isSquare(const Matrix* matrix)
{
	if (matrix->height == matrix->height)
	{
		return true;
	}
	else
	
	return false;
}

//Verifica se é a identidade                                                                                         FUNCIONANDO
bool isIdentity(const Matrix* matrix)
{
	for (int i = 0; i < matrix->height; i++)
	{
		for (int g = 0; g < matrix->width; g++)
		{
			if (i == g)
			{
				if (matrix->matrix[i][g] != 1)
				{
					return false;
				}
			}
			else if (matrix->matrix[i][g] != 0)
			{
				return false;
			}
		}
	}

	return true;
}

//DET matriz triangular                                                                                              FUNCIONANDO
float triangularDeterminant(const Matrix* matrix)
{
	float det = 1;
	for (int i = 0; i < matrix->height; i++)
	{
		det = matrix->matrix[i][i]*det;
	}

	return det;
}

//Calcula Det>3                                                                                                      FUNCIONANDO
float DeterminanteM3(const Matrix* matrix, int contador, int verificador)
{
	float det;
	double cont=0;
	double a, b, c, d;
	if (matrix->height-contador==2)
	{
		if (verificador == 0)
		{
			a = matrix->matrix[contador][contador] * matrix->matrix[contador + 1][contador + 1];
			return a;
		}
		else if (verificador == 1)
		{
			b = matrix->matrix[contador][contador - 1] * matrix->matrix[contador + 1][contador + 2];
			return b;
		}
		else if (verificador == 2)
		{
			c = matrix->matrix[contador][contador-1] * matrix->matrix[contador+1][contador];
			return c;
		}
	}	
	
	for (int i = 0; i < matrix->height; i++)
	{
		cont= matrix->matrix[0 + contador][i + contador] * pow(-1, 1 + i + 1)*DeterminanteM3(matrix, contador+1, i)+cont;
	}
	det = cont;
	return det;
}                                   

//Calcula DET                                                                                                        FUNCIONANDO
float determinante(const Matrix* matrix)
{
	float det;
	if (matrix->height != matrix->width)
	{
		printf("nao foi possivel calcular o det, porque a matriz nao e quadrada");
		return 0;
	}
	else	{
		if (matrix->height == 2)
		{
			det = (matrix->matrix[0][0] * matrix->matrix[1][1]) - (matrix->matrix[0][1] * matrix->matrix[1][0]);
		}
		else if (matrix->height == 3)
		{
			det = ((matrix->matrix[0][0] * matrix->matrix[1][1] * matrix->matrix[2][2]) +
				(matrix->matrix[0][1] * matrix->matrix[1][2] * matrix->matrix[2][0]) +
				(matrix->matrix[0][2] * matrix->matrix[1][0] * matrix->matrix[2][1])) +
				(-(matrix->matrix[0][2] * matrix->matrix[1][1] * matrix->matrix[2][0]) -
				(matrix->matrix[0][0] * matrix->matrix[1][2] * matrix->matrix[2][1]) -
				(matrix->matrix[0][1] * matrix->matrix[1][0] * matrix->matrix[2][2]));
		}
		else
		{
			det = DeterminanteM3(matrix, 0, 0);
		}				
	}
	return det;
};

//Verifica se é comutativa                                                                                           FUNCIONANDO
bool isCommutative(const Matrix* matrix, const Matrix* other)
{
	if (matrix->height != other->width)
	{
		return false;
	}
	else if (other->height != matrix->width)
	{
		return false;
	}
	else if (matrix->height != matrix->width)
	{
		return false;
	}
	else
	{
		bool ver = true;

		Matrix matrix1;
		matrix1.height = matrix->height;
		matrix1.width = matrix->width;

		matrix1.matrix = (float**)calloc(matrix1.height, sizeof(float*));

		for (int i = 0; i < matrix1.height; i++)
		{
			matrix1.matrix[i] = (float*)calloc(matrix1.height, sizeof(float*));
		}

		Matrix matrix2;

		matrix2.height = matrix->height;
		matrix2.width = matrix->width;

		matrix2.matrix = (float**)calloc(matrix2.height, sizeof(float*));

		for (int i = 0; i < matrix2.height; i++)
		{
			matrix2.matrix[i] = (float*)calloc(matrix2.height, sizeof(float*));
		}
		matrix1=newMultiplyMatrices(matrix, other);
		matrix2=newMultiplyMatrices(other, matrix);
		ver=compareMatrices(&matrix1, &matrix2);
		return ver;
	}	
}

//Verifica se é simetrica                                                                                          FUNCIONANDO
bool isSymmetric(const Matrix* matrix)
{
	bool ver = false;

	

	Matrix matrix2;

	matrix2.height = matrix->height;
	matrix2.width = matrix->width;

	matrix2.matrix = (float**)calloc(matrix2.height, sizeof(float*));

	for (int i = 0; i < matrix2.height; i++)
	{
		matrix2.matrix[i] = (float*)calloc(matrix2.height, sizeof(float*));
	}

	matrix2 = newTranspose(matrix);
	
	ver = compareMatrices(matrix, &matrix2);
	return ver;
}

//Verifica se é Asimetrica                                                                                         FUNCIONANDO
bool isSquewSymmetric(const Matrix* matrix)
{
	bool ver = false;

	Matrix matrix1;
	matrix1.height = matrix->height;
	matrix1.width = matrix->width;

	matrix1.matrix = (float**)calloc(matrix1.height, sizeof(float*));

	for (int i = 0; i < matrix1.height; i++)
	{
		matrix1.matrix[i] = (float*)calloc(matrix1.height, sizeof(float*));
	}

	matrix1=newOpposite(matrix);

	Matrix matrix2;

	matrix2.height = matrix->height;
	matrix2.width = matrix->width;

	matrix2.matrix = (float**)calloc(matrix2.height, sizeof(float*));

	for (int i = 0; i < matrix2.height; i++)
	{
		matrix2.matrix[i] = (float*)calloc(matrix2.height, sizeof(float*));
	}

	matrix2 = newTranspose(matrix);

	ver = compareMatrices(&matrix1, &matrix2);
	
	return ver;
}

//Retorna um elemento                                                                                            FUNCIONANDO
float get(const Matrix* matrix, int row, int col)
{
	float elemento;

	elemento = matrix->matrix[row][col];

	return elemento;
}

//Verifica se é singular                                                                                           FUNCIONANDO
bool isInvertible(const Matrix* matrix)
{
	int det = 0;
	det = determinante(matrix);
	if (det == 0)
	{
		return true;
	}
	else 
		return false;
}

//Det vandermonde recursivo                                                                                 FUNCIONANDO 
float detVandermonde(const Matrix* matrix, int tam, int tipo)
{
	float a = 1 , b=0;

	if (tam == 1)
	{
		return 1;
	}
	else if (tipo == 1)
	{
		for (int i = 0; i < tam-1; i++)
		{
			a = (matrix->matrix[1][tam-1] - matrix->matrix[1][i])*a;
		}

		b = detVandermonde(matrix, tam - 1, tipo)*a;
	}
	else if (tipo == 2)
	{
		for (int e = 0; e < tam-1; e++)
		{
			a = (matrix->matrix[tam-1][1] - matrix->matrix[e][1])*a;
		}

		b = detVandermonde(matrix, tam - 1, tipo)*a;
	}
	return b;
}

//DET vandermonde                                                                                           FUNCIONANDO 
float vandermondeDeterminant(const Matrix* matrix)
{
	float det;
	int ver1=0, ver2=0, ver3=0, tam=0;

	for (int i = 0; i < matrix->width; i++)
	{
		ver1 += matrix->matrix[0][i];
	}
	for (int e = 0; e < matrix->height; e++)
	{
		ver2 += matrix->matrix[e][0];
	}
	if (ver1 / matrix->width == 1)
	{
		ver3 = 1;
		tam = matrix->width;
	}
	else if (ver2 / matrix->height==1)
	{
		ver3 = 2;
		tam = matrix->height;
	}	

	det=detVandermonde(matrix,tam , ver3);

	return det;
}

//Printa A Matrix                                                                                           FUNCIONANDO 
void printMatrix(const Matrix* matrix)
{
	for (int i = 0; i < matrix->height; i++)
	{
		for (int j = 0; j < matrix->width; j++)
		{
			cout << "[ " << matrix->matrix[i][j] << " ] ";
		}
		cout << endl;
	}
}

//Desaloca a Matriz
void deallocMatrix(Matrix* matrix)
{
	free(matrix);
}

// matriz nula, com linhas e colunas                                                                         FUNCIONANDO
Matrix newNullMatrix(int height, int width)
{
	Matrix matrix;
	matrix.width = width;
	matrix.height = height ;

	matrix.matrix = (float**) calloc(matrix.height,sizeof(float*));

	for (int i = 0; i < matrix.height; i++)
	{
		matrix.matrix[i] = (float*)calloc(matrix.width,sizeof(float));
	}

	return matrix;
}
Matrix* allocNullMatrix(int height, int width)
{
	Matrix* matrix = new Matrix;

	matrix->width = width;
	matrix->height = height;

	matrix->matrix = (float**)calloc(matrix->height, sizeof(float*));

	for (int i = 0; i < matrix->height; i++)
	{
		matrix->matrix[i] = (float*)calloc(matrix->width, sizeof(float));
	}



	return matrix;
}

//matriz nula com tamanho                                                                                    FUNCIONANDO
Matrix newNullMatrix(int size)
{
	Matrix matrix2;
	matrix2.height = size;
	matrix2.width = size;

	matrix2.matrix = (float**)calloc(matrix2.height, sizeof(float*));

	for (int i = 0; i < matrix2.height; i++)
	{
		matrix2.matrix[i] = (float*)calloc(matrix2.height, sizeof(float*));
	}

	return matrix2;
};
Matrix* allocNullMatrix(int size)
{
	Matrix* matrix= new Matrix;
	matrix->height = size;
	matrix->width = size;

	matrix->matrix = (float**)calloc(matrix->height, sizeof(float*));

	for (int i = 0; i < matrix->height; i++)
	{
		matrix->matrix[i] = (float*)calloc(matrix->height, sizeof(float*));
	}

	return matrix;
}

//copia outra matriz                                                                                          FUNCIONANDO
Matrix newMatrix(const Matrix* other)
{
	Matrix matrixD;
	matrixD.height = other->height;
	matrixD.width = other->width;

	matrixD.matrix = (float**)calloc(matrixD.height, sizeof(float*));

	for (int i = 0; i < matrixD.height; i++)
	{
		matrixD.matrix[i] = (float*)calloc(matrixD.width, sizeof(float));
	}

	for (int i = 0; i < matrixD.height; i++)
	{
		for (int k = 0; k < matrixD.width; k++)
		{
			matrixD.matrix[i][k] = other->matrix[i][k];
		}
	}

	return matrixD;
};
Matrix* allocMatrix(const Matrix* other)
{
	Matrix* matrix=new Matrix;
	matrix->height = other->height;
	matrix->width = other->width;
	for (int i = 0; i < matrix->height; i++)
	{
		for (int k = 0; k < matrix->width; k++)
		{
			matrix->matrix[i][k] = other->matrix[i][k];
		}
	}

	return matrix;
}

//matriz diagonal                                                                                            FUNCIOANADO
Matrix newDiagonal(int size, float* diagonal)
{
	Matrix matrix = newNullMatrix(size);

	for (int g = 0; g < size; g++)
	{
		matrix.matrix[g][g] = diagonal[g];
	}

	return matrix;
}
Matrix* allocDiagonal(int size, float* diagonal)
{
	Matrix* matrix=new Matrix;

	for (int g = 0; g < size; g++)
	{
		matrix->matrix[g][g] = diagonal[g];
	}

	return matrix;
}

//matriz escalar                                                                                             FUNCIONADO
Matrix newScalar(int size, float scalar)
{
	Matrix matrixE = newNullMatrix(size);
	
	for (int g = 0; g < size; g++)
	{
		matrixE.matrix[g][g] = scalar;
	}
	return matrixE;
}
Matrix* allocScalar(int size, float scalar)
{
	Matrix* matrix = allocNullMatrix(size);
	
	for (int g = 0; g < size; g++)
	{
		matrix->matrix[g][g] = scalar;
	}

	return matrix;
}

//matriz identidade                                                                                           FUNCIONANDO
Matrix newIdentity(int size)
{
	Matrix matrixI=newNullMatrix(size);
	
	for (int g = 0; g < size; g++)
	{
		matrixI.matrix[g][g] = 1;
	}
	return matrixI;
}
Matrix* allocIdentity(int size)
{
	Matrix* matrix = allocNullMatrix(size);

	for (int g = 0; g < size; g++)
	{
		matrix->matrix[g][g] = 1;
	}

	return matrix;
}

// transpondo uma matriz                                                                                     FUNCIONANDO
Matrix newTranspose(const Matrix* matrix)
{
	Matrix matrixT = newNullMatrix(matrix->height, matrix->width);
	
	for (int i = 0; i < matrixT.height; i++)
	{
		for (int k = 0; k < matrixT.width; k++)
		{
			matrixT.matrix[i][k] = matrix->matrix[k][i];
		}
	}

	return matrixT;
}
Matrix* allocTranspose(const Matrix* matrix)
{
	Matrix* matrixT = allocNullMatrix(matrix->height, matrix->width);

	for (int i = 0; i < matrixT->height; i++)
	{
		for (int k = 0; k < matrixT->width; k++)
		{
			matrixT->matrix[i][k] = matrix->matrix[k][i];
		}
	}

	return matrixT;
}

// Matrix oposta *(-1)                                                                                      FUNCIONANDO
Matrix newOpposite(const Matrix* matrix)
{
	Matrix matrixO = newNullMatrix(matrix->height, matrix->width);

	for (int i = 0; i < matrixO.height; i++)
	{
		for (int g = 0; g < matrixO.width; g++)
		{
			if (matrix->matrix[i][g] != 0)
			{
				matrixO.matrix[i][g] = (-1)*matrix->matrix[i][g];
			}
			
		}
	}


	return matrixO;
}
Matrix* allocOpposite(const Matrix* matrix)
{
	Matrix* matrixO = allocNullMatrix(matrix->height, matrix->width);

	for (int i = 0; i < matrixO->height; i++)
	{
		for (int g = 0; g < matrixO->width; g++)
		{
			if (matrix->matrix[i][g] != 0)
			{
				matrixO->matrix[i][g] = (-1)*matrix->matrix[i][g];
			}

		}
	}

	return matrixO;
}

//Cria Inversa                                                                                             FUNCIONANDO
Matrix newInverse(const Matrix* matrix)
{
	Matrix matrixIn;
	matrixIn=newNullMatrix(matrix->height);	
	Matrix matrixA;
	matrixA = newNullMatrix(matrix->height);
	
	for (int i = 0; i < matrixA.height; i++)
	{
		for (int g = 0; g < matrixA.width; g++)
		{
			matrixA.matrix[i][g] = matrix->matrix[i][g];
		}
	}
	matrixA=adjunta(&matrixA);
	float Idet = 0;

	if (determinante(matrix) == 0)
	{
		cout << "Det igual a zero, sem inversa" << endl;
		return *(matrix);
	}
	else
	{
		Idet = 1 / determinante(matrix);
		for (int w = 0; w < matrix->height; w++)
		{
			for (int e = 0; e < matrix->width; e++)
			{
				matrixIn.matrix[w][e] = Idet*matrixA.matrix[w][e];
			}
		}
	}

	return matrixIn;
}
Matrix* allocInverse(const Matrix* matrix)
{
	Matrix* matrixIn;
	matrixIn = allocNullMatrix(matrix->height, matrix->width);
	Matrix* matrixA;
	matrixA = allocNullMatrix(matrix->height, matrix->width);

	for (int i = 0; i < matrixA->height; i++)
	{
		for (int g = 0; g < matrixA->width; g++)
		{
			matrixA->matrix[i][g] = matrix->matrix[i][g];
		}
	}
	matrixA = adjuntaA(matrixA);
	float Idet = 0;

	if (determinante(matrix) == 0)
	{
		cout << "Det igual a zero, sem inversa" << endl;
		return matrixA;
	}
	else
	{
		Idet = 1 / determinante(matrix);
		for (int w = 0; w < matrix->height; w++)
		{
			for (int e = 0; e < matrix->width; e++)
			{
				matrixIn->matrix[w][e] = Idet*matrixA->matrix[w][e];
			}
		}
	}

	return matrixIn;
}

//Soma 2 matrizes                                                                                           FUNCIONANDO
Matrix newAddMatrices(const Matrix* matrix, const Matrix* other)
{
	Matrix matrixA=newNullMatrix(matrix->height,matrix->width);
	

	for (int g = 0; g < matrix->width; g++)
	{
		for (int w = 0; w < matrix->height; w++)
		{
			matrixA.matrix[g][w] = matrix->matrix[g][w] + other->matrix[g][w];

		}
	}



	return matrixA;
}
Matrix* allocAddMatrices(const Matrix* matrix, const Matrix* other)
{
	Matrix* matrixA=allocNullMatrix(matrix->height, matrix->width);

	for (int g = 0; g < matrix->width; g++)
	{
		for (int w = 0; w < matrix->height; w++)
		{
			matrixA->matrix[g][w] = matrix->matrix[g][w] + other->matrix[g][w];

		}
	}

	return matrixA;
}

//Subtraçao de matrizes                                                                                       FUNCIONANDO
Matrix newSubtractMatrices(const Matrix* matrix, const Matrix* other)
{
	Matrix matrixS = newNullMatrix(matrix->height, matrix->width);

	for (int g = 0; g < matrix->width; g++)
	{
		for (int w = 0; w < matrix->height; w++)
		{
			matrixS.matrix[g][w] = matrix->matrix[g][w] - other->matrix[g][w];

		}
	}



	return matrixS;
}
Matrix* allocSubtractMatrices(const Matrix* matrix, const Matrix* other)
{
	Matrix* matrixA = allocNullMatrix(matrix->height, matrix->width);



	return matrixA;
}

//Multiplicaçao matrizes                                                                                      FUNCIONANDO
Matrix newMultiplyMatrices(const Matrix* matrix, const Matrix* other)
{
	Matrix matrixN = newNullMatrix(matrix->height, matrix->width);

	for (int g = 0; g < matrix->width; g++)
	{
		for (int w = 0; w < matrix->height; w++)
		{
			for (int e = 0; e < matrix->width; e++)
			{
				matrixN.matrix[g][w] += matrix->matrix[g][e] * other->matrix[e][g];

			}
		}
	}


	return matrixN;
}
Matrix* multiplyMatrices(Matrix* matrix, const Matrix* other)
{

	Matrix* matrixN = allocNullMatrix(matrix->height, matrix->width);

	for (int g = 0; g < matrix->width; g++)
	{
		for (int w = 0; w < matrix->height; w++)
		{
			for (int e = 0; e < matrix->width; e++)
			{
				matrixN->matrix[g][w] += matrix->matrix[g][e] * other->matrix[e][g];

			}
		}
	}
	return matrixN;
}                                         

//Multiplicar por um numero                                                                                   FUNCIONANDO
Matrix newMultiplyMatrixByScalar(const Matrix* matrix, float scalar)
{

	Matrix matrixE = newNullMatrix(matrix->height, matrix->width);

	for (int g = 0; g < matrix->width; g++)
	{
		for (int w = 0; w < matrix->height; w++)
		{
			matrixE.matrix[g][w] = matrix->matrix[g][w] * scalar;

		}
	}

	return matrixE;
	
}
Matrix* multiplyMatrixByScalar(Matrix* matrix, float scalar)
{
	for (int g = 0; g < matrix->width; g++)
	{
		for (int w = 0; w < matrix->height; w++)
		{
			matrix->matrix[g][w] = matrix->matrix[g][w] * scalar;

		}
	}

	return matrix;
}

//Compara 2 matrizes                                                                                       FUNCIONANDO
bool compareMatrices(const Matrix* matrix, const Matrix* other)
{
	if (matrix->height != other->height)
	{
		return false;
	}
	else if (matrix->width != other->width)
	{
		return false;
	}
	else 
	for (int i = 0; i < matrix->height; i++)
	{
		for (int g = 0; g < matrix->width; g++)
		{
			if (matrix->matrix[i][g] != other->matrix[i][g])
			{
				return false;
			}
		}
	}


	return true;
}

//Verifica se é vandermonde                                                                                FUNCIONANDO
bool isVandermonde(const Matrix* matrix)
{
	float ver1 = 0, ver2 = 0;

	for (int i = 0; i < matrix->width;i++)
	{
		ver1 = matrix->matrix[0][i] + ver1;
	}
	for (int e = 0; e < matrix->height; e++)
	{
		ver2 = matrix->matrix[e][0] + ver2;
	}
	if (ver1 / matrix->width == 1)
	{
		for (int q = 0; q < matrix->width; q++)
		{
			if (matrix->matrix[2][q] / matrix->matrix[1][q] != matrix->matrix[1][q])
			{
				return false;
			}
		}
		return true;
	}
	else if (ver2 / matrix->height==1)
	{
		for (int w = 0; w < matrix->width; w++)
		{
			if (matrix->matrix[w][2] / matrix->matrix[w][1] != matrix->matrix[w][1])
			{
				return false;
			}
		}
		return true;
	}
 else 
	return false;

	

	return true;
}

//Seta um numero para um elemento retorna a matriz                                                             FUNCIONANDO
Matrix* set(Matrix* matrix, int row, int col, float value)
{
	matrix->matrix[row][col] = value;

	return matrix;
}

//Matriz transposta masssss a funçao é a matriz                                                                FUNCIONANDO
Matrix* transpose(Matrix* matrix)
{
	int d = 0;
	int e = 0;
	for (int i = 0; i < matrix->width; i++)
	{
		while (e < matrix->height)
		{
			d = matrix->matrix[i][e];
			matrix->matrix[i][e] = matrix->matrix[e][i];
			matrix->matrix[e][i] = d;
			e++;
		}
		e = e - (matrix->height - 1);
		e++;
	}

	return matrix;
}

//Retorna a opsiçao -1                                                                                     FUNCIONANDO
Matrix* opposite(Matrix* matrix)
{
	for (int i = 0; i < matrix->width; i++)
	{
		for (int e = 0; e < matrix->height; e++)
		{
			if (matrix->matrix[i][e] != 0)
			{
				matrix->matrix[i][e] = (-1)*matrix->matrix[i][e];
			}
		}
	}

	return matrix;
}

//Inversa retornando a matrix na funçao                                                                        FUNCIONANDO 
Matrix* inverse(Matrix* matrix)
{
	float Idet = 1/determinante(matrix);
	
	Matrix matrixA;
	matrixA = newNullMatrix(matrix->height);

	matrixA = adjunta(matrix);

	for (int i = 0; i < matrix->height; i++)
	{
		for (int j = 0; j < matrix->width; j++)
		{
			matrix->matrix[i][j] = Idet*(matrixA.matrix[i][j]);
		}
	}
	

	return matrix;
}

//Adjunta                                                                                                   FUNCIONANDO 
Matrix adjunta(Matrix* matrix)
{
	Matrix matrix2 = newNullMatrix(matrix->height-1);
	Matrix matrix3 = newTranspose(matrix);
	
	for  (int i = 0;i < matrix->height;i++)
	{
		for (int j = 0; j < matrix->width; j++)
		{
			matrix2 = *(cofator(&matrix3, i, j));
			matrix->matrix[i][j] = pow(-1,i+j)*determinante(&matrix2);
		}
	}

	return *(matrix);
}
Matrix* adjuntaA(Matrix* matrix)
{
	Matrix* matrix2 = allocNullMatrix(matrix->height - 1);
	Matrix* matrix3 = allocTranspose(matrix);

	for (int i = 0; i < matrix->height; i++)
	{
		for (int j = 0; j < matrix->width; j++)
		{
			matrix2 = cofatorA(matrix3, i, j);
			matrix->matrix[i][j] = pow(-1, i + j)*determinante(matrix2);
		}
	}

	return matrix;
}

//Cofator                                                                                               FUNCIONANDO
Matrix* cofator(Matrix* matrix, int linha, int coluna)
{
	Matrix cofator = newNullMatrix(matrix->height-1);
	int size = matrix->height - 1;
	

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i >= linha)
			{
				if (j >= coluna)
				{
					cofator.matrix[i][j] = matrix->matrix[i + 1][j + 1];
				}
				else if (j<coluna)
				{
					cofator.matrix[i][j] = matrix->matrix[i + 1][j];
				}
			}
			else if (i<linha)
			{
				if (j >= coluna)
				{
					cofator.matrix[i][j] = matrix->matrix[i][j + 1];
				}
				else if (j<coluna)
				{
					cofator.matrix[i][j] = matrix->matrix[i][j];
				}
			}
		}
	}

	return &cofator;
}
Matrix* cofatorA(Matrix* matrix, int linha, int coluna)
{
	Matrix* cofator = allocNullMatrix(matrix->height - 1);
	int size = matrix->height - 1;


	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i >= linha)
			{
				if (j >= coluna)
				{
					cofator->matrix[i][j] = matrix->matrix[i + 1][j + 1];
				}
				else if (j<coluna)
				{
					cofator->matrix[i][j] = matrix->matrix[i + 1][j];
				}
			}
			else if (i<linha)
			{
				if (j >= coluna)
				{
					cofator->matrix[i][j] = matrix->matrix[i][j + 1];
				}
				else if (j<coluna)
				{
					cofator->matrix[i][j] = matrix->matrix[i][j];
				}
			}
		}
	}

	return cofator;
}