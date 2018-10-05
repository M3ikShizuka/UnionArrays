#include <iostream>
#include <Windows.h>

int main()
{
	const int iArray1[] = { -41, -13, -4, -3, -3, -2,  1,  2,  3, 5, 6, 9, 13, 14, 31 },
		iArray2[] = { -31, -21, -12, -2, 4, 6, 10, 12, 15, 21 };
    int *iArrayResult = nullptr,
        *iArrayResultNew = nullptr;
	size_t szArray1 = ARRAYSIZE(iArray1),
		szArray2 = ARRAYSIZE(iArray2),
		szArrayUnionSize = szArray1 + szArray2,
		szArrayLarger = 0,
		szArraySmaller = 0,
        szNewSize = 0;
    int iIndexArrayLarger = 0,
        iIndexArraySmaller = 0,
        iIndexArrayResult = 0,
        iLastValue = 0;
	int *iArrayLarger = nullptr,
		*iArraySmaller = nullptr;

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

    iArrayResult = new int[szArrayUnionSize]{0};
	
    while(iIndexArraySmaller != szArraySmaller && iIndexArrayLarger != szArrayLarger)
    {
		if (iIndexArraySmaller < (szArraySmaller - 1) && iArraySmaller[iIndexArraySmaller] <= iArrayLarger[iIndexArrayLarger])
		{
			if (iArraySmaller[iIndexArraySmaller] != iLastValue)
			{
				iArrayResult[iIndexArrayResult] = iArraySmaller[iIndexArraySmaller];
				iLastValue = iArraySmaller[iIndexArraySmaller];
				iIndexArrayResult++;
				szNewSize++;
			}

			iIndexArraySmaller++;
		}
		else
		{
			if (iArrayLarger[iIndexArrayLarger] != iLastValue)
			{
				iArrayResult[iIndexArrayResult] = iArrayLarger[iIndexArrayLarger];
				iLastValue = iArrayLarger[iIndexArrayLarger];
				iIndexArrayResult++;
				szNewSize++;
			}

			iIndexArrayLarger++;
		}
    }

    iArrayResultNew = new int[szNewSize]{0};
    for (int iIndex = 0; iIndex < szNewSize; iIndex++)
    {
        iArrayResultNew[iIndex] = iArrayResult[iIndex];
    }
    delete[] iArrayResult;
    
     // Вывод:
    for (int iIndex = 0; iIndex < szNewSize; iIndex++)
    {
        std::cout << iArrayResultNew[iIndex] << " ";
    }
	std::cout << std::endl;

    delete[] iArrayResultNew;
	system("pause");
    return 0;
}