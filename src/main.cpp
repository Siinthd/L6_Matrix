#include <iostream>
#include "matrix.h"

int main()
{
    Matrix<int, -1> test; // бесконечная матрица int заполнена значениями -1
	assert(test.size() == 0); // все ячейки свободны
	auto a = test[0, 0];
	assert(a == -1);
	assert(test.size() == 0);
	test[100, 100] = 314;
	assert((test[100, 100] ) == 314);
	assert(test.size() == 1);

	Matrix<int, 0> matrix;
	const size_t SIZE = 10;
	for (int i = 0; i < 10; i++)
		matrix[i][i] = matrix[10 - 1 - i][i] = i; // N = 10, i = [0, N)
    
    std::cout<<matrix.size()<<std::endl;

    return 0;
}

