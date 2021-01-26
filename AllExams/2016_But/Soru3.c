#include <stdio.h>
#include <stdlib.h>

void thePrintf(int array[], int size)
{
    int i;

    for (i = 0;i < size;i++)
    {
        printf ("%d ", array[i]);
    }
    printf ("\r\n\r\n");
}

void mergeArray(int array[], int left, int mid, int right, int p[])
{
    int i,j;
    int m,n;

    i = left;
    j = mid + 1;
    n = left;
    while(i <=mid && j <= right)
    {
        if (array[i] < array[j])
        {
            p[n++] = array[i++];
        }
        else
        {
            p[n++] = array[j++];
        }
    }

    while(i <= mid)
    {
        p[n++] = array[i++];
    }

    while(j <= right)
    {
        p[n++] = array[j++];
    }

    for (m = left;m <= right;m++)
    {
        array[m] = p[m];
    }
}

void merge(int array[], int left, int right, int p[])
{
    int mid;    
    if (right > left)
    {
        mid = (left + right)/2;
        merge(array, left,mid, p);
        merge(array, mid+1, right,p);
        mergeArray(array, left, mid, right, p);
    }
}

int mergeSort(int array[], int size)
{
    int *p;

    p = (int *)malloc(size * sizeof(int));
    if (NULL == p)
    {
        return 0;
    }

    merge(array, 0, size - 1, p);

    free(p);
    return 1;
}


int main()
{
    int a[] = {2,4,1,6,8,5,3,7};

    int size = sizeof(a)/sizeof(a[0]);

    thePrintf(a,size);
    mergeSort(a,size);
    thePrintf(a,size);
    return 0;
    
    
}