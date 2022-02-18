#include <iostream>

using namespace std;

void printDisks(int length, int arr[])
{
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void swap(int *num1, int *num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

int main()
{
	int diskCount;		//positive integer n in the pseudocode
	int disk = 0;		//Color representation of disk 0 = light 1 = dark
	int swapCount = 0;

	cout << "Enter the amount of Disks: ";
	cin >> diskCount;

	int *diskArray = new int[diskCount];


	//Populate disk Array with 0 and 1s representing dark and light disks
	for (int i = 0; i < diskCount; i++)
	{
		diskArray[i] = disk;
		disk = (disk + 1) % 2;
	}
	printDisks(diskCount, diskArray);

	//First iteration going right
	for (int i = 0; i < diskCount; i++)
	{
		if (diskArray[i] < diskArray[i + 1])
		{
			swap(&diskArray[i], &diskArray[i + 1]);
			swapCount++;
		}
	}
	printDisks(diskCount, diskArray);

	//Repeated n / 2 times iterate going left
	for (int i = 0; i < (diskCount / 2) - 1; i++)
	{
		for (int j = diskCount - 1; j > 0; j--)
		{
			if (diskArray[j] > diskArray[j - 1])
			{
				swap(&diskArray[j], &diskArray[j - 1]);
				swapCount++;
			}
		}
		printDisks(diskCount, diskArray);
	}

	cout << "Number of Swaps: " << swapCount;
}