#include <iostream>
#include "matrix.h"

int main()
{
	Matrix<int, 0> matrix;
	const size_t SIZE = 10;

	for (int i = 0; i < SIZE; i++)
		matrix[i][i] = matrix[SIZE - 1 - i][i] = i; // N = 10, i = [0, N)

	std::cout << "Matrix size: " << matrix.size() << std::endl;

	for (int i = 1; i < SIZE-1; i++)
	{
		for (int j = 1; j < SIZE-1; j++)
		{
			std::cout << matrix[i][j] << ' ';
		}
		std::cout << std::endl;
	}

	for(auto it : matrix)
	{
			std::cout<<'[' << it.first[0] << ',' << it.first[1]
				<<"] = "<<it.second;
		std::cout<<std::endl;
	}
	return 0;
}
