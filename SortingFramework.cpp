// SortingFramework.cpp
// Program to generate an array of random integers and print it on the output screen.
// sort it using different types of sorting algorithms.

#include <iostream>
#include <algorithm>


static int *makeRandomArray(const int size, const int max, const int seed);
static void printArrayContents(const int * const array, const int size);

static void bubbleSort(int *array, const int size);
static void shuttleSort(int *array, const int size);
static void selectionSort(int *array, const int size);
static void insertionSort(int *array, const int size);




int main (int argc, char * const argv[])
{
	// to be altered according to needs
	const int arraySize = 23;
	const int maxArrayVal = 23;
	const int seed = 23;

	int *array = makeRandomArray(arraySize, maxArrayVal, seed);

	printArrayContents(array, arraySize);

	//bubbleSort(array, arraySize);
	shuttleSort(array, arraySize);
	//selectionSort(array, arraySize);
	//insertionSort(array, arraySize);

  printArrayContents(array, arraySize);

	delete[] array;

	return 0;
}


static int *makeRandomArray(const int size, const int max, const int seed)
{
	srand(seed);
	int *array = new int[size];
	for (int i = 0; i < size; i++)
	   array[i] = rand() % max;

	return array;
}

static void printArrayContents(const int * const array, const int size)
{
	std::cout << "Array contents : { ";
	for (int i = 0; i < size; i++)
	   std::cout << array[i] << " ";
	std::cout << "}" << std::endl;
}

static void bubbleSort(int *array, const int size)
{
	for(int n = 0; n < size; n++)
	{
        for(int i = 0; i < size; i++)
        {
            if(array[i] > array[i + 1])
            {
                int x = array[i];
                array[i] = array[i + 1];
                array[i + 1] = x;
            }
        }
    }
}

static void shuttleSort(int *array, const int size)
{
	/*for(int n = 0; n < size; n++)
	{
        for(int i = 0; i < size; i++)
        {
            if(array[i] > array[i + 1])
            {
                int x = array[i];
                array[i] = array[i + 1];
                array[i + 1] = x;
            }
        }
        for(int i = size; i > 0; i--)
        {
            if(array[i] < array[i - 1])
            {
                int x = array[i];
                array[i] = array[i - 1];
                array[i - 1] = x;
            }
        }
	}*/

	for(int i = 0; i < size; i++)
        {
            int n = 0;
            if(array[i] > array[i+1] && i-n > 0)
            {
                int x = array[i];
                array[i] = array[i + 1];
                array[i + 1] = x;
                n++;
                if(array[i-n] > array[i])
                {
                    int x = array[i-n];
                    array[i-n] = array[i];
                    array[i] = x;
                }
            }
            else if(array[i] > array[i+1])
            {
                int x = array[i];
                array[i] = array[i + 1];
                array[i + 1] = x;
            }
        }

}

static void selectionSort(int *array, const int size)
{
  // TODO : implement the selection sort algorithm
}

static void insertionSort(int *array, const int size)
{
	// TODO : implement the insertion sort algorithm
}


