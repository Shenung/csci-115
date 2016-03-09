// Shenung Fouamvung

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

// const int M = 100000000;
const int Repetitions = 1000000;

int binarySearch(int searchVal, int data[], int first, int last)
{
	if (first <= last)
	{
		int mid = (first + last) / 2;
		if (searchVal == data[mid])
			return mid;
		else if (searchVal < data[mid])
			return binarySearch(searchVal,data,first,mid-1);
		else
			return binarySearch(searchVal,data,mid+1,last);
	}
	return -(first + 1);
}

int sequentialSearch(int searchVal, int data[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (data[i] == searchVal)
		{
			return i;
		}
	}
	return -1;
}


int main()
{
	srand(time(NULL));
  int M;
  cout << "Enter a large number(preferably over 1,000,000 but its up to you):";
  cin >> M;
  cout << endl;
	int *data = new int[M];
	for (int i = 0; i < M; ++i)
	{
		data[i] = i + 1;
	}
	cout << fixed;
	for (int n = 10; n <= M; n *= 10)
	{
		clock_t seq = clock();
		for (int i = 1; i <= Repetitions; i++)
		{
			sequentialSearch((rand() % n) + 1, data, n);
		}
		clock_t seqEnd = clock();
		double seqTime = static_cast<double>(seqEnd - seq) / CLOCKS_PER_SEC * 1000 / Repetitions;

		clock_t bin = clock();
		for (int j = 1; j <= Repetitions; j++)
		{
			binarySearch((rand() % n) + 1, data, 0, n);
		}
		clock_t binEnd = clock();
		double binTime = static_cast<double>(binEnd - bin) / CLOCKS_PER_SEC * 1000 / Repetitions;


		cout << n << ", " << seqTime << ", " << binTime << endl;
	}
	delete[] data;
	system("PAUSE");
	return 0;
}
