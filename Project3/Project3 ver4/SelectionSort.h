// Jian Zhong
// Prof. Mackay
// CS132 Project 3
// 12/11/2019
// SelectionSort.h

#ifndef SelectionSort_h
#define SelectionSort_h

// Definition of Selection Sort algorithm
template <typename Type>
void selectionSort(Type arr[], int arrSize)
{
    // scan size - 1 values in total
    for (int i = 0; i < arrSize - 1; i++)
    {
        // find the minimum value's index in the remaining array
        int minPos = i;
        for (int j = i + 1; j < arrSize; j++)
            if (arr[minPos] > arr[j])
                minPos = j;
        
        // swap minimum value with the unsorted value
        Type temp = arr[minPos];
        arr[minPos] = arr[i];
        arr[i] = temp;
    }
}

#endif /* SelectionSort_h */
