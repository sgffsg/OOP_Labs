#include <array>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <optional>


using MatrixX3 = std::array<std::array<float, 3>, 3>;
using MatrixX2 = std::array<std::array<float, 2>, 2>;

enum class WorkMode
{
	INFO,
	STDIN,
	CLI,
};

struct Args
{
	std::string matrixFileName;
	WorkMode workMode;
};

void ShowInfo()
{
	std::cout << "Usage:" << std::endl;
	std::cout << "Invert.exe <matrix File>" << std::endl;
}

std::optional<Args> ParseArgs(int argc, char* argv[])
{
	Args args;
	if (argc == 1)
	{
		args.workMode = WorkMode::STDIN;
		return args;
	}
	else if (argc == 2 && std::string(argv[1]) == "-h")
	{
		args.workMode = WorkMode::INFO;
		return args;
	}
	else if (argc == 2)
	{
		args.workMode = WorkMode::CLI;
		args.matrixFileName = argv[1];
		return args;
	}
	else
		return std::nullopt;
}

float CalculateDeterminantOfMatrixX2(const MatrixX2& matrix)
{
	return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
}

float CalculateDeterminantOfMatrixX3(const MatrixX3& matrix)
{
	return matrix[0][0] * matrix[1][1] * matrix[2][2] + matrix[0][1] * matrix[1][2] * matrix[2][0]
		+ matrix[0][2] * matrix[1][0] * matrix[2][1] - matrix[0][2] * matrix[1][1] * matrix[2][0]
		- matrix[0][1] * matrix[1][0] * matrix[2][2] - matrix[0][0] * matrix[1][2] * matrix[2][1];
}

MatrixX3 ReadMatrixFromStdin()
{
	int row = 0;
	const int maxRow = 3;
	const int maxColumn = 3;

	std::string line;
	MatrixX3 matrix{};

	for (row = 0; row < 3; row++)
	{
		std::getline(std::cin, line);
		std::istringstream iss(line);
		for (int column = 0; column < maxColumn; column++)
		{
			float value;

			if (!(iss >> value))
			{
				throw std::runtime_error("Invalid matrix\n");
			}
			matrix[row][column] = value;
		}
	}

	if (row != maxRow)
	{
		throw std::runtime_error("Invalid matrix format\n");
	}

	return matrix;
}

MatrixX3 ReadMatrixFromFile(const std::string& matrixFileName)
{
	std::ifstream matrixFile(matrixFileName);
	if (!matrixFile.is_open())
	{
		throw std::runtime_error("Can not open file with matrix\n");
	}

	int row = 0;
	const int maxRow = 3;
	const int maxColumn = 3;

	std::string line;
	MatrixX3 matrix{};

	while (std::getline(matrixFile, line) && row != maxRow)
	{
		std::istringstream iss(line);
		for (int column = 0; column < maxColumn; column++)
		{
			float value;

			if (!(iss >> value))
			{
				throw std::runtime_error("Invalid matrix\n");
			}
			matrix[row][column] = value;
		}
		row++;
	}

	if (row != maxRow)
	{
		throw std::runtime_error("Invalid matrix format\n");
	}

	return matrix;
}

void PrintMatrixX3(const MatrixX3& matrix)
{
	std::cout << std::fixed << std::setprecision(3);
	for (int row = 0; row < matrix.size(); row++)
	{
		for (int column = 0; column < matrix[row].size(); column++)
		{
			std::cout << matrix[row][column];
			if (column != matrix.size() - 1)
			{
				std::cout << " ";
			}
		}
		std::cout << "\n";
	}
}

MatrixX2 FindMinorOfMatrixX3Elt(const MatrixX3& matrix, const int row, const int column)
{
	int rowX2 = 0;
	MatrixX2 minor{};

	for (int rowX3 = 0; rowX3 < matrix.size(); rowX3++)
	{
		int columnX2 = 0;
		if (rowX3 == row)
		{
			continue;
		}
		for (int columnX3 = 0; columnX3 < matrix[row].size(); columnX3++)
		{
			if (columnX3 == column)
			{
				continue;
			}
			minor[rowX2][columnX2] = matrix[rowX3][columnX3];
			columnX2++;
		}
		rowX2++;
	}

	return minor;
}

MatrixX3 CalculateAlgebraicExtansionMatrix(const MatrixX3& matrix)
{
	MatrixX3 algExtMatrix{};

	for (int row = 0; row < matrix.size(); row++)
	{
		for (int column = 0; column < matrix[row].size(); column++)
		{
			MatrixX2 minor = FindMinorOfMatrixX3Elt(matrix, row, column);
			algExtMatrix[row][column] = CalculateDeterminantOfMatrixX2(minor);
			if ((row + column) % 2 == 1)
			{
				algExtMatrix[row][column] *= -1;
			}
		}
	}

	return algExtMatrix;
}

MatrixX3 TransposeMatrix(const MatrixX3& matrix)
{
	MatrixX3 transposedMatrix{};
	for (int row = 0; row < matrix.size(); row++)
	{
		for (int column = 0; column < matrix[row].size(); column++)
		{
			transposedMatrix[column][row] = matrix[row][column];
		}
	}

	return transposedMatrix;
}

std::optional<MatrixX3> InvertMatrix(MatrixX3 matrix)
{

	float determination = CalculateDeterminantOfMatrixX3(matrix);
	if (determination == 0)
	{
		return std::nullopt;
	}

	MatrixX3 algExtMatrix = CalculateAlgebraicExtansionMatrix(matrix);
	MatrixX3 transpAlgAddMatrix = TransposeMatrix(algExtMatrix);

	MatrixX3 invertMatrix{};
	for (int row = 0; row < transpAlgAddMatrix.size(); row++)
	{
		for (int column = 0; column < transpAlgAddMatrix[row].size(); column++)
		{
			invertMatrix[row][column] = transpAlgAddMatrix[row][column] / determination;
		}
	}

	return invertMatrix;
}

int main(int argc, char* argv[])
{
	try
	{
		MatrixX3 matrix;
		auto args = ParseArgs(argc, argv);

		if (args->workMode == WorkMode::INFO)
		{
			ShowInfo();
			return 0;
		}
		else if (args->workMode == WorkMode::STDIN)
			matrix = ReadMatrixFromStdin();
		else
			matrix = ReadMatrixFromFile(args->matrixFileName);

		auto invertedMatrix = InvertMatrix(matrix);
		if (invertedMatrix == std::nullopt)
		{
			std::cout << "Non-invertible";
			return 0;
		}

		PrintMatrixX3(invertedMatrix.value());
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
		return 1;
	}

	return 0;
}
