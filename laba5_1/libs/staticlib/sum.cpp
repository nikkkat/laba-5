int sum(int a, int b)
{
	return a + b;
}

void fillarr(int** arr, int* arr2, int& rows, int& cols)
{
	for (int j = 0; j < cols; j++)
	{
		int sum = 0;
		for (int i = 0; i < rows; i++)
		{
			sum += arr[i][j];
		}
		arr2[j] = sum;
	}
}

int minimal(int* arr, int& cols)
{
	int min = arr[0];
	for (int j = 0; j < cols; j++)
	{
		if (arr[j] < min) { min = arr[j]; }
	}

	return min;
}