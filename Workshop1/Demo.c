

#define SIZE 1000

//BubbleSort



//InsertionSort


//QuickSort



//linearSearch



//BinarySearch



//JumpSearch


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
    start clock();
    insertionSort(insertion_arr, SIZE);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Insertion Sort : %f seconds \n",cpu_time_used)

    //Quick
    int *quick_arr = malloc(SIZE * sizeof(int));
    for (int i=0; i < SIZE; i++)
    {
        quick_arr[i] = arr[i];
    }
    start clock();
    quickSort(insertion_arr, SIZE);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Insertion Sort : %f seconds \n",cpu_time_used)

    int key =copy[SIZE / 2];

    //linear
    start = clock;
    int index = linearSearch(arr, SIZE, key)
    end = clock();
    cpu_time_used = ((double)(end-start)) / CLOCKS_PER_SEC;
    printf("Binary Search: key %d ")

}