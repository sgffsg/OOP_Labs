
#include <algorithm>
#include <array>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <optional>
#include <vector>

using Matrix3x3 = std::array<std::array<double, 3>, 3>;

std::vector<std::vector<double>> CloneMatrix(std::vector<std::vector<double>> arr, int dimension)
{
	std::vector<std::vector<double>> newArr;
	newArr.resize(dimension);
	for (int i = 0; i < dimension; i++)
	{
		newArr[i].resize(dimension);
		for (int j = 0; j < dimension; j++)
		{
			newArr[i][j] = arr[i][j];
		}
	}
	return newArr;
}

std::vector<std::vector<double>> ReadMatrix(int dimension, std::istream& inputFile)
{
	std::vector<std::vector<double>> arr;
	arr.resize(dimension);
	for (int i = 0; i < dimension; i++)
	{
		arr[i].resize(dimension);
		for (int j = 0; j < dimension; j++)
		{
			inputFile >> arr[i][j];
		}
	}
	return arr;
}

void ShowMatrix(std::vector<std::vector<double>> arr, int dimension, std::ofstream& outputFile)
{
	for (int i = 0; i < dimension; i++)
	{
		for (int j = 0; j < dimension; j++)
		{
			outputFile << round(arr[i][j]) << " ";
		}
		outputFile << "\n";
	}
}

std::vector<std::vector<double>> MultiMatrix(std::vector<std::vector<double>> A, std::vector<std::vector<double>> B, int dimension)
{
	std::vector<std::vector<double>> result;
	result.resize(dimension);
	for (int i = 0; i < dimension; i++)
	{
		result[i].resize(dimension);
		for (int j = 0; j < dimension; j++)
		{
			result[i][j] = 0;
			for (int k = 0; k < dimension; k++)
			{
				result[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	return result;
}

void MultiScalar(std::vector<std::vector<double>>& m, int dimension, double a)
{
	for (int i = 0; i < dimension; i++)
	{
		for (int j = 0; j < dimension; j++)
		{
			m[i][j] *= a;
		}
	}
}

void Sum(std::vector<std::vector<double>>& A, std::vector<std::vector<double>> B, int dimension)
{
	for (int i = 0; i < dimension; i++)
	{
		for (int j = 0; j < dimension; j++)
		{
			A[i][j] += B[i][j];
		}
	}
}

double FindDeterminant(std::vector<std::vector<double>> matrix, int dimension)
{
	std::vector<std::vector<double>> tmpMatrix = CloneMatrix(matrix, dimension);
	for (int step = 0; step < dimension - 1; step++)
	{
		for (int i = step + 1; i < dimension; i++)
		{
			double coeff = -tmpMatrix[i][step] / tmpMatrix[step][step];
			for (int j = step; j < dimension; j++)
			{
				tmpMatrix[i][j] += tmpMatrix[step][j] * coeff;
			}
		}
	}

	double Det = 1;
	for (int i = 0; i < dimension; i++)
	{
		Det *= tmpMatrix[i][i];
	}
	return Det;
}

struct Norms
{
	double rowNorm;
	double colNorm;
};

std::optional<Norms> FindNorm(int dimension, std::vector<std::vector<double>> arr)
{
	Norms norms;
	for (int i = 0; i < dimension; i++)
	{
		double colsum = 0;
		double rowsum = 0;

		for (int j = 0; j < dimension; j++)
		{
			rowsum += fabs(arr[i][j]);
			colsum += fabs(arr[j][i]);
		}

		norms.colNorm = std::max(colsum, norms.colNorm);
		norms.rowNorm = std::max(rowsum, norms.rowNorm);
	}
	return norms;
}

void Transposition(std::vector<std::vector<double>>& arr, int dimension)
{
	double tmp = 0;
	for (int i = 0; i < dimension - 1; i++)
	{
		for (int j = i + 1; j < dimension; j++)
		{
			std::swap(arr[j][i], arr[i][j]);
		}
	}
}

std::vector<std::vector<double>> InitDoubleIdentityMatrix(int dimension)
{
	std::vector<std::vector<double>> arr;
	arr.resize(dimension);
	for (int i = 0; i < dimension; i++)
	{
		arr[i].resize(dimension);
		for (int j = 0; j < dimension; j++)
		{
			if (i == j)
			{
				arr[i][j] = 2;
			}
			else
			{
				arr[i][j] = 0;
			}
		}
	}
	return arr;
}

void OpenInOutFiles(std::ifstream& inputFile, std::ofstream& outputFile, const int argc, char* argv[])
{
	if (argc != 3)
	{
		std::cout << "Invalid argument count\n"
				  << "Usage: Invert.exe <inputFile> <outputFile>\n";
		exit(1);
	}

	inputFile.open(argv[1]);
	if (!inputFile.is_open())
	{
		std::cout << "Filed to open '" << argv[1] << "' for reading\n";
		exit(1);
	}

	outputFile.open(argv[2]);
	if (!outputFile.is_open())
	{
		std::cout << "Filed to open '" << argv[2] << "' for writing\n";
		exit(1);
	}
}

std::vector<std::vector<double>> FindInvertedMatrix(std::vector<std::vector<double>> arr0, const int& dimension, std::vector<std::vector<double>> arr, std::vector<std::vector<double>> E2)
{
	std::vector<std::vector<double>> invMatrix = CloneMatrix(arr0, dimension);
	double eps = 0.001;
	std::vector<std::vector<double>> prev;

	if (FindDeterminant(arr, dimension) != 0)
	{ // если матрица не вырождена
		while (fabs(FindDeterminant(MultiMatrix(arr, invMatrix, dimension), dimension) - 1) >= eps) // пока |det(A * A[k](^-1)) - 1| >= EPS
		{
			prev = CloneMatrix(invMatrix, dimension);
			invMatrix = MultiMatrix(arr, prev, dimension);
			MultiScalar(invMatrix, dimension, -1);
			Sum(invMatrix, E2, dimension);
			invMatrix = MultiMatrix(prev, invMatrix, dimension);
		}

		return invMatrix;
	}
	else
	{
		std::cout << "Impossible the matrix is degenerate \n";
		exit(1);
	}
}

std::vector<std::vector<double>> NormalizeMatrix(const int& dimension, std::vector<std::vector<double>> arr)
{
	std::vector<std::vector<double>> normMatrix = CloneMatrix(arr, dimension);
	auto norms = FindNorm(dimension, normMatrix);
	Transposition(normMatrix, dimension);
	MultiScalar(normMatrix, dimension, (1 / (norms->colNorm * norms->rowNorm)));
	return normMatrix;
}

const int dimension = 3;

/* Численное вычисление обратной матрицы по методу Ньютона-Шульца
		1. Записать начальное приближение :
			1) Транспонировать данную матрицу
			2) Нормировать по столбцам и строкам
		2. Повторять процесс до достижения заданной точности.
	*/

int main(int argc, char* argv[])
{
	std::ifstream inputFile;
	std::ofstream outputFile;

	OpenInOutFiles(inputFile, outputFile, argc, argv);

	std::vector<std::vector<double>> arr; // переименновать
	arr = ReadMatrix(dimension, inputFile);
	// вынести в функцию
	std::vector<std::vector<double>> normMatrix = NormalizeMatrix(dimension, arr);

	std::vector<std::vector<double>> E2 = InitDoubleIdentityMatrix(dimension);

	std::vector<std::vector<double>> resultMatrix = FindInvertedMatrix(normMatrix, dimension, arr, E2);

	ShowMatrix(resultMatrix, dimension, outputFile);

	flush(outputFile);

	return 0;
}