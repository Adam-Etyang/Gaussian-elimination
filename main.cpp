#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

std::vector<double> GaussianElimination(vector<vector<double>> &matrix)
{
	int size = matrix.size();
	// foward ellimination

	// partial pivoting making(sure that the pivot has the largest number)
	for (int i = 0; i < size; i++)
	{
		int maxrow = i;
		for (int j = i + 1; j < size; j++)
		{
			if (fabs(matrix[i][j] > fabs(matrix[maxrow][i])))
			{
				maxrow = j;
			}
		}
		swap(matrix[i], matrix[maxrow]);
		// check if the pivot is zero
		if (fabs(matrix[i][i]) < 1e-9)
		{
			throw runtime_error("the system has no solution!");
		} // if pivot == 0 then the system has no solutions or infinitely many solutions

		// row elimination
		for (int k = i + 1; k < size; k++)
		{
			double factor = matrix[k][i] / matrix[i][i];
			for (int m = i; m <= size; m++)
			{
				matrix[k][m] -= factor * matrix[i][m];
			}
		}
	}

	// back susbtitution
	vector<double> solution(size);
	for (int i = size - 1; i >= 0; i--) // start with the last row working upwards
	{
		solution[i] = matrix[i][size] / matrix[i][i]; // solving xi
		for (int k = i - 1; k >= 0; k--)
		{
			matrix[k][size] -= matrix[k][i] * solution[i]; // substituting xi into the next equation
		}
	}
	return solution;
}

int main()
{
	// use case
	vector<vector<double>> matrix =
		{
			{2, 4, -1, 8},
			{-3, -1, 2, -11},
			{-2, 1, 2, -3}};
	try
	{
		vector<double> solution = GaussianElimination(matrix);
		cout << "solution:" << endl;
		for (size_t i = 0; i < solution.size(); i++)
		{
			cout << "x " << i + 1 << " = " << solution[i];
		}
		cout << endl;
	}
	catch (const runtime_error &e)
	{
		cout << "error " << e.what() << endl;
	}

	return 0;
}
