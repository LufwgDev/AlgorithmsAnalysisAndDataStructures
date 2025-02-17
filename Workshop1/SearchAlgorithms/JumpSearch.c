int JumpSearch(int arr[], int n, int key){
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
        return -1
    }
}