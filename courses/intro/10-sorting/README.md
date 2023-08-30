# Sorting algorithms

TODO: Note for my furune self: add complete example of how to use those algorithms

Sorting are algorithms that put elements of a list in a certain order. It is cruxial to understand the basics of sorting in order to start understanding more complex algorithms and why you have to pay attention to efficiency.

Before going deep, please watch this video:

SEIZURE WARNING!! [![Sorting Algorithms](https://img.youtube.com/vi/kPRA0W1kECg/0.jpg)](https://www.youtube.com/watch?v=kPRA0W1kECg)

and this one:

[![Sorting Algorithms](https://img.youtube.com/vi/ZZuD6iUe3Pc/0.jpg)](https://www.youtube.com/watch?v=ZZuD6iUe3Pc)

Explore the concepts interactively at [visualgo.net](https://visualgo.net/en/sorting).

Try to answer the following questions, before continuing:

- What are the slowest sorting algorithms?
- What are the fastest sorting algorithms?
- Con you infer the difference between a stable and unstable sorting algorithm?
- What is the difference between a comparison and a non-comparison sorting algorithm?
- What would be an in-place and a non-in-place sorting algorithm?
- What is the difference between a recursive and a non-recursive sorting algorithm?

## The basics

Many of the algorithms will have to swap elements from the array, vector or list. In order to do that, we will need to create a function that swaps two elements. Here is the function:

```c++
// A function to swap two elements
void swap(int *xp, int *yp) {  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  
```

The `*` operator used in the function signature means that the function will receive a pointer to an integer. So it will efectivelly change the content in another scope. The `*` operator is used to dereference a pointer, which means that it will return the value stored in the memory address pointed by the pointer. Given the declaration is `int *xp`, the `*xp` will return the value stored in the memory address pointed by `xp`.

Alternatively you could use the `&` operator to pass the reference to that variable in the similar fashion, but the usage wont be requiring the `*` before the variable name as follows:

```c++
// A function to swap two elements
void swap(int &xp, int &yp) {  
    int temp = xp;  
    xp = yp;  
    yp = temp;  
}  
```

The result is the same, but the usage is different. The first one is more common in C++, while the second one is more common in C.

## Bubble sort

Bubble sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order.

```c++
// A function to implement bubble sort
void bubbleSort(int arr[], int n) {  
    // if the array has only one element, it is already sorted
    if(n<=1)
        return;
    
    int i, j;  
    for (i = 0; i < n-1; i++)
        // Last i elements are already in place  
        for (j = 0; j < n-i-1; j++)  
            if (arr[j] > arr[j+1])  
                swap(&arr[j], &arr[j+1]);  
}  
```

As you can see, the algorithm is very simple, but it is not very efficient. It has a time complexity of O(n^2) and a space complexity of O(1).

One of the drawbacks of this algorithm is the sheer amount of swaps. In the worst scenario, it does n^2 swaps, which is a lot. If your machine have slow writes, it will be very slow.

## Insertion sort

Insertion sort is a simple sorting algorithm that works the way we sort playing cards in our hands. You pick one card and insert it in the correct position in the sorted part of the list. You repeat this process until you have sorted the whole list. Here is the code:

```c++
// A function to implement insertion sort
void insertionSort(int arr[], int n) {  
    // if the array has only one element, it is already sorted
    if(n<=1)
        return;
    
    int i, key, j;  
    for (i = 1; i < n; i++) {  
        key = arr[i];  
        j = i - 1;  
  
        /* Move elements of arr[0..i-1], that are  
        greater than key, to one position ahead  
        of their current position */
        while (j >= 0 && arr[j] > key) {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }  
}  
```

It falls in the same category of algorithms that are very simple, but not very efficient. It has a time complexity of O(n^2) and a space complexity of O(1).

Although it have the same complexity as bubble sort, it is a little bit more efficient. It does less swaps than bubble sort, but it is still not very efficient. It will swap all numbers to the left of the current number, which is a lot of swaps.

## Selection sort

Selection sort is a simple sorting algorithm. This sorting algorithm is an in-place comparison-based algorithm in which the list is divided into two parts, the sorted part at the left end and the unsorted part at the right end. Initially, the sorted part is empty and the unsorted part is the entire list. The smallest element is selected from the unsorted array and swapped with the leftmost element, and that element becomes a part of the sorted array. This process continues moving unsorted array boundary by one element to the right. Here is the code:

```c++
// A function to implement selection sort
void selectionSort(int arr[], int n) {
    // if the array has only one element, it is already sorted
    if(n<=1)
        return;
    
    int i, j, min_idx;  
  
    // One by one move boundary of unsorted subarray  
    for (i = 0; i < n-1; i++) {  
        // Find the minimum element in unsorted array  
        min_idx = i;  
        for (j = i+1; j < n; j++)  
        if (arr[j] < arr[min_idx])  
            min_idx = j;  
  
        // Swap the found minimum element with the first element  
        swap(&arr[min_idx], &arr[i]);  
    }  
}  
```

It is also a simple algorithm, but it is a little bit more efficient than the previous two. It has a time complexity of O(n^2) and a space complexity of O(1).

It does less swaps than the previous two algorithms, potentially n swaps, but it is still not very efficient. It selects for the current position, the smallest number to the right of it and swaps it with the current number. It does this for every number in the list, which fatally a lot of swaps. 

## Merge sort

Merge sort is a divide and conquer algorithm. It divides input array in two halves, calls itself for the two halves and then merges the two sorted halves. Here is the code:

```c++
// recursive merge sort
void mergeSort(int arr[], int l, int r) {  
    if (l < r) {  
        // Same as (l+r)/2, but avoids overflow for  
        // large l and h  
        int m = l+(r-l)/2;  
  
        // Sort first and second halves  
        mergeSort(arr, l, m);  
        mergeSort(arr, m+1, r);  
  
        merge(arr, l, m, r);  
    }  
}  

// merge function
void merge(int arr[], int l, int m, int r) {  
    int i, j, k;  
    int n1 = m - l + 1;  
    int n2 =  r - m;  
    
    // allocate memory for the sub arrays
    int *L = new int[n1];
    int *R = new int[n2];
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)  
        L[i] = arr[l + i];  
    for (j = 0; j < n2; j++)  
        R[j] = arr[m + 1+ j];  
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray  
    j = 0; // Initial index of second subarray  
    k = l; // Initial index of merged subarray  
    while (i < n1 && j < n2) {  
        if (L[i] <= R[j]) {  
            arr[k] = L[i];  
            i++;  
        }  
        else {  
            arr[k] = R[j];  
            j++;  
        }  
        k++;  
    }  
  
    /* Copy the remaining elements of L[], if there are any */
    while (i < n1) {  
        arr[k] = L[i];  
        i++;  
        k++;  
    }  
  
    /* Copy the remaining elements of R[], if there  
    are any */
    while (j < n2) {  
        arr[k] = R[j];  
        j++;  
        k++;  
    }
    
    // deallocate memory
    delete[] L;
    delete[] R;
}  
```

It is a very efficient algorithm that needs extra memory to work. It has a time complexity of O(n*log(n)) and a space complexity of O(n). It is a very efficient algorithm, but it is not very simple. It is quite more complex than the previous algorithms. It is a divide and conquer algorithm, which means that it divides the problem in smaller problems and solves them. It divides the list in two halves, sorts them and then merges them. It does this recursively until it has a list of size 1, which is sorted. Then it merges the lists and returns the sorted list.

## Quick sort

Quick sort is a divide and conquer algorithm. It picks an element as pivot and partitions the given array around the picked pivot. Here is the code:

```c++
// recursive quick sort
void quickSort(int arr[], int low, int high) {  
    if (low < high) {  
        /* pi is partitioning index, arr[p] is now  
        at right place */
        int pi = partition(arr, low, high);  
  
        // Separately sort elements before  
        // partition and after partition  
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }  
}

// partition function
int partition (int arr[], int low, int high) {  
    int pivot = arr[high]; // pivot  
    int i = (low - 1); // Index of smaller element  
  
    for (int j = low; j <= high- 1; j++) {  
        // If current element is smaller than or  
        // equal to pivot  
        if (arr[j] <= pivot) {  
            i++; // increment index of smaller element  
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}  
```

It is a very efficient algorithm that don't needs extra memory, which means it is in-place. In average, it can be as fast as mergesort with time complexity of O(n*log(n)), but in the worst case it can be as slow as O(n^2). But it is a better choice if you are not allowed to use extra memory. It is a divide and conquer algorithm, which means that it divides the problem in smaller problems and solves them. It selects a pivot and partitions the list around the pivot. It does this recursively until it has a list of size 1, which is sorted. Then it merges the lists and returns the sorted list.

## Counting sort

Counting sort is a specialized algorithm for sorting numbers. It only works well if you have a small range of numbers. It counts the number of occurrences of each number and then uses the count to place the numbers in the right position. Here is the code:

```c++
// counting sort
void countingSort(int arr[], int n) {  
    // if the array has only one element, it is already sorted
    if(n<=1)
        return;
    
    int max=arr[0];
    int min[0];
    
    // find the max and min number
    for(int i=0; i<n; i++) {
        if(arr[i]>max) {
            max=arr[i];
        }
        if(arr[i]<min) {
            min=arr[i];
        }
    }
    
    // allocate memory for the count array
    int *count = new int[max-min+1];
    
    // initialize the count array
    for(int i=0; i<max-min+1; i++) {
        count[i]=0;
    }

    // count the number of occurrences of each number
    for(int i=0; i<n; i++) {
        count[arr[i]-min]++;
    }

    // place the numbers in the right position
    int j=0;
    for(int i=0; i<max-min+1; i++) {
        while(count[i]>0) {
            arr[j]=i+min;
            j++;
            count[i]--;
        }
    }
    
    // deallocate memory
    delete[] count;
}
```

Counting sort is a very efficient sorting algorithm which do not rely on comparisons. It has a time complexity of O(n+k) where k is the range of numbers. Space complexity is O(k) which means it is not an in-place sorting algorithm. It is a very efficient algorithm, but it is not very simple. It counts the number of occurrences of each number and then uses the count to place the numbers in the right position.

## Radix sort

Radix sort is a specialized algorithm for sorting numbers. It only works well if you have a small range of numbers. It sorts the numbers by their digits. Here is the code:

```c++
// Radix sort
void radixSort(int arr[], int n) {
    // if the array has only one element, return
    if(n<=1)
        return;
    
    // initialize the max number as the first number. 
    int max=arr[0];
    
    // find the max number
    for(int i=0; i<n; i++) {
        if(arr[i]>max) {
            max=arr[i];
        }
    }
    
    // allocate memory for the count array
    int *count = new int[10]; // 10 digits
    
    // allocate memory for the output array
    int *output = new int[n];
    
    // do counting sort for every digit
    for(int exp=1; max/exp>0; exp*=10) {
        // initialize the count array
        for(int i=0; i<10; i++) {
            count[i]=0;
        }
        
        // count the number of occurrences of each number
        for(int i=0; i<n; i++) {
            count[(arr[i]/exp)%10]++;
        }
        
        // change count[i] so that count[i] now contains actual position of this digit in output[]
        for(int i=1; i<10; i++) {
            count[i]+=count[i-1];
        }
        
        // build the output array
        for(int i=n-1; i>=0; i--) {
            output[count[(arr[i]/exp)%10]-1]=arr[i];
            count[(arr[i]/exp)%10]--;
        }
        
        // copy the output array to the input array
        for(int i=0; i<n; i++) {
            arr[i]=output[i];
        }
    }
}
```

Radix sort is just a counting sort that is applied to every digit. It has a time complexity of O(n*k) where k is the number of digits. 

## Conclusion

This is the first time we will talk about efficiency, and for now on, you will start evaluating and taking care about your algorithms' efficiency. You will learn more about efficiency in the next semester and course when we cover data structures.
