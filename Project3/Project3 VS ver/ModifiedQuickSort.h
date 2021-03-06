// Jian Zhong
// Prof. Mackay
// CS132 Project 3
// 12/11/2019
// ModifiedQuickSort.h

#ifndef ModifiedQuickSort_h
#define ModifiedQuickSort_h

template <typename ElementType>
void modifiedSplit(ElementType x[], int first, int last, int & pos)
    /*--------------------------------------------------------
    Rearrange x[first], ... , x[last] to position pivot.

    Precondition:   < and == are defined for ElementType;
    first <= pos <= last.  Note that this version
    chooses pivot = x[first]; better pivot choices
    are described later in this section.
    Postcondition: Elements of sublist are rearranged and
    pos modified so x[first], ... , x[pos-1 <= pivot
    and pivot < x[pos + 1]\, ... , x[last].
    ----------------------------------------------------------*/
{
    ElementType pivot = x[first];    // pivot element
    int left = first,                // index for left search
        right = last;                // index for right search
    while(left < right)
    {
        while (pivot < x[right])      // Search from right for
            right--;                  // element <= pivot
                                      // Search from left for
        while (left < right &&        // element > pivot
              (x[left] < pivot || x[left] == pivot))
            left++;

        if (left < right)             // If searches haven't met
            swap(x[left], x[right]);  // interchange elements
    }
    // End of searches; place pivot in correct position
    pos = right;
    x[first] = x[pos];
    x[pos] = pivot;
}

template <typename ElementType>
void modifiedQuickSort(ElementType x[], int first, int last)
/*-------------------------------------------------------
Quicksort array elements x[first], ..., x[last] so
they are in ascending order.

Precondition: < and == are defined for ElementType.
Note: Client programs call quicksort with first = 1
and last = n - 1, where n is the list size
Postcondition: x[first], ..., x[last] is sorted
---------------------------------------------------------*/
{
    int pos;               // pivot's final position
    if (last - first < 20) // ⚠️ if small enough, use another sorting algorithm
    {
        ElementType temp[20]; // ⚠️
        for (int pos = first; pos <= last; pos++)
            temp[pos - first] = x[pos];

        //sort the temp array
        for (int pos = first; pos <= last; pos++)
            x[pos] = temp[pos - first];
    }
    else   //still large enough to use the quicksort
    {
        split(x, first, last, pos);   // Split into 2 sublists
        quicksort(x, first, pos - 1); // Sort left sublist
        quicksort(x, pos + 1, last);  // Sort right sublist
    }
    // else list has 0 or 1 element and requires no sorting


}


#endif /* ModifiedQuickSort_h */
