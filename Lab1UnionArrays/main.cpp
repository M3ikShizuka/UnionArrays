#include "main.hpp"

int main()
{
	const int iArray1[] = { -41, -13, -4, -3, -3, -2,  1,  2,  3, 5, 6, 9, 13, 14, 31 },
		iArray2[] = { -31, -21, -12, -2, 4, 6, 10, 12, 15, 21 };
    int *piArrayResult = nullptr;
	size_t szArrayResultSize = 0;
	
	SetConsoleTheme();
	// Объединение массивов
	UnionArrays(iArray1, iArray2, ARRAYSIZE(iArray1), ARRAYSIZE(iArray2), &piArrayResult, szArrayResultSize);
    // Вывод:
	ArrayOut(piArrayResult, szArrayResultSize);
	// Освобождение выделенной памати под массив
    delete[] piArrayResult;
	system("pause");
    return 0;
}

void SetConsoleTheme()
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFOEX csfiex;

	csfiex.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
	GetConsoleScreenBufferInfoEx(hStdOut, &csfiex);
	// Console window size:
	csfiex.dwMaximumWindowSize.X = 920;
	csfiex.dwMaximumWindowSize.Y = 720;
	csfiex.srWindow.Left = 50;
	csfiex.srWindow.Top = 5;
	csfiex.srWindow.Right = 100;
	csfiex.srWindow.Bottom = 55;
	// Console color:
	csfiex.ColorTable[0] = 0x202020;
	csfiex.ColorTable[1] = 0xFF0096;
	SetConsoleScreenBufferInfoEx(hStdOut, &csfiex);
	system("color 01");
}

void UnionArrays(const int iArray1[], const int iArray2[], const size_t& szArray1, const size_t& szArray2, int **ppiArrayResult, size_t& szArrayResultSize)
{
	size_t szArrayUnionSize = szArray1 + szArray2,
		szArrayLarger = 0,
		szArraySmaller = 0;
	int iIndexArrayLarger = 0,
		iIndexArraySmaller = 0,
		iIndexArrayResult = 0,
		iLastValue = 0;
	int *iArrayData = nullptr,
		*iArrayLarger = nullptr,
		*iArraySmaller = nullptr,
		*piArrayResult = nullptr;

	// Определение какой из массивов больше.
	if (szArray1 > szArray2)
	{
		iArrayLarger = const_cast<int*>(iArray1);
		iArraySmaller = const_cast<int*>(iArray2);
		szArrayLarger = szArray1;
		szArraySmaller = szArray2;
	}
	else
	{
		iArrayLarger = const_cast<int*>(iArray2);
		iArraySmaller = const_cast<int*>(iArray1);
		szArrayLarger = szArray2;
		szArraySmaller = szArray1;
	}

	// Выделение
	iArrayData = new int[szArrayUnionSize] {0};

	// Объединение массивов
	while (iIndexArraySmaller != szArraySmaller && iIndexArrayLarger != szArrayLarger)
	{
		if (iIndexArraySmaller < (szArraySmaller - 1) && iArraySmaller[iIndexArraySmaller] <= iArrayLarger[iIndexArrayLarger])
		{
			if (iArraySmaller[iIndexArraySmaller] != iLastValue)
			{
				iArrayData[iIndexArrayResult] = iArraySmaller[iIndexArraySmaller];
				iLastValue = iArraySmaller[iIndexArraySmaller];
				iIndexArrayResult++;
				szArrayResultSize++;
			}

			iIndexArraySmaller++;
		}
		else
		{
			if (iArrayLarger[iIndexArrayLarger] != iLastValue)
			{
				iArrayData[iIndexArrayResult] = iArrayLarger[iIndexArrayLarger];
				iLastValue = iArrayLarger[iIndexArrayLarger];
				iIndexArrayResult++;
				szArrayResultSize++;
			}

			iIndexArrayLarger++;
		}
	}

	// Выделение памяти для конечного массива данныз.
	piArrayResult = new int[szArrayResultSize] {0};
	for (int iIndex = 0; iIndex < szArrayResultSize; iIndex++)
	{
		piArrayResult[iIndex] = iArrayData[iIndex];
	}
	*ppiArrayResult = piArrayResult;

	// Освобождение массива данных
	delete[] iArrayData;
}

void ArrayOut(int iArrayResult[], const size_t& szArrayResultSize)
{
	for (int iIndex = 0; iIndex < szArrayResultSize; iIndex++)
	{
		std::cout << iArrayResult[iIndex] << " ";
	}
	std::cout << std::endl;
}