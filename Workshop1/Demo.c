#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 1000

//BubbleSort

void bubbleSort(int arr[], int n)
{
    for (int i =0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

//InsertionSort

void insertionSort(int arr[], int n)
{
    for(int i = 1; i<n; i++)
    {
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

//QuickSort

int partition(int arr[],  int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j < high; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    return i+1;
}


void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

//linearSearch

int linearSearch(int arr[], int n, int target)
{
    for(int i=0; i<n; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

//BinarySearch

int binarySearch(int arr[], int left, int right, int key)
{
    while(left<=right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            left = mid +1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

//JumpSearch

int jumpSearch(int arr[], int n, int key){
    int step = (int)sqrt(n);
    int prev = 0;

    while(arr[(step < n ? step : n) - 1]< key)
    {
        prev = step;
        step += (int)sqrt(n);
        if (prev >= n)
        {
            return -1;
        }
    }
    int end = (step < n ? step : n);
    for(int i = prev; i < end; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

//main

int main()
{
    int *arr = malloc(SIZE * sizeof(int));
    int *copy = malloc(SIZE * sizeof(int));
    srand(time(NULL));


    for(int i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % 10000;
        copy[i] = arr[i];

    }

    clock_t start, end;
    double cpu_time_used;

    //Bubble
    int *bubble_arr = malloc(SIZE * sizeof(int));
    for (int i = 0; i < SIZE; i++)
    {
        bubble_arr[i] = arr[i];

    }
    start = clock();
    bubbleSort(bubble_arr, SIZE);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Bubble Sort : %f seconds\n",cpu_time_used);

    //Insertion
    int *insertion_arr = malloc(SIZE * sizeof(int));
    for (int i=0; i < SIZE; i++)
    {
        insertion_arr[i]=arr[i];
    }
    start = clock();
    insertionSort(insertion_arr, SIZE);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Insertion Sort : %f seconds \n",cpu_time_used);

    //Quick
    int *quick_arr = malloc(SIZE * sizeof(int));
    for (int i=0; i < SIZE; i++)
    {
        quick_arr[i] = arr[i];
    }
    start = clock();
    quickSort(quick_arr, 0, SIZE -1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Quick Sort : %f seconds \n",cpu_time_used);

    int key =copy[SIZE / 2];

    //linear
    start = clock();
    int index = linearSearch(arr, SIZE, key);
    end = clock();
    cpu_time_used = ((double)(end-start)) / CLOCKS_PER_SEC;
    printf("Linear Search: key %d found at index %d in %f seconds\n", key, index, cpu_time_used);

    //Binary
    start = clock();
    index = binarySearch(quick_arr, 0, SIZE, key);
    end = clock();
    cpu_time_used = ((double)(end-start)) / CLOCKS_PER_SEC;
    printf("Binary Search: key %d found at index %d in %f seconds\n", key, index, cpu_time_used);
    
    //Jump
    start = clock();
    index = jumpSearch(quick_arr, SIZE, key);
    end = clock();
    cpu_time_used = ((double)(end-start)) / CLOCKS_PER_SEC;
    printf("Jump Search: key %d found at index %d in %f seconds\n", key, index, cpu_time_used);
    
    //
    free(arr);
    free(copy);
    free(bubble_arr);
    free(quick_arr);
    free(insertion_arr);

    return 0;

    
}