#include <iostream>
using namespace std;

int Insert(int A[], int n)
{
    int temp, i = n;
    temp = A[n];
    while (i > 1 && temp > A[i / 2])
    {
        if (A[i] > A[i / 2])
        {
            A[i] = A[i / 2];
            i = i / 2;
            A[i] = temp;
        }
    }
    return i;
}

void Heapify(int A[], int n, int l)
{
    int i = l, j = 2 * i;
    while (i >= 1)
    {
        if (j < n)
        {
            if (A[j] < A[j + 1])
                j = j + 1;
            if (A[j] > A[i])
            {
                swap(A[j], A[i]);
                Heapify(A, n, j);
            }
        }
        i--;
        j = 2 * i;
    }
}

void Delete(int A[], int n)
{
    int x, i, j;
    x = A[n];
    A[n] = A[1];
    A[1] = x;
    i = 1;
    j = 2 * i;
    while (j < n - 1)
    {
        if (A[j] < A[j + 1])
        {
            j = j + 1;
        }
        if (A[i] < A[j])
        {
            swap(A[i], A[j]);
            i = j;
            j = 2 * j;
        }
        else
        {
            break;
        }
    }
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void Bubble(int A[], int n)
{
    int i, j;
    int flag = 0;
    for (i = 0; i < n; i++)
    {
        flag = 0;
        for (j = 0; j < n - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                swap(A[j], A[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
}

void Selection(int A[], int n)
{
    int i, j;
    int k, l;
    for (i = 0; i < n; i++)
    {
        k = l = i;
        for (j = i; j < n; j++)
        {
            if (A[j] < A[k])
            {
                l = j;
                k = j;
            }
        }
        swap(A[i], A[l]);
    }
}
int partition(int A[], int n, int s)
{
    int pivot = A[s];
    int i, k;
    i = s;
    k = n;
    do
    {
        do
        {
            // if (k <= i)
            //      break;
            i++;

        } while (A[i] <= pivot);

        do
        {
            // if (k <= i)
            //    break;
            k--;
        } while (A[k] > pivot);

        if (k > i)
            swap(A[i], A[k]);
    } while (k > i);
    //k--;
    swap(A[s], A[k]);
    return k;
}

void QuickSort(int A[], int n, int s)
{ // s for pivot point
    int end;
    if (s < n)
    {
        end = partition(A, n, s);
        QuickSort(A, end, s);
        QuickSort(A, n, end + 1);
    }
}

int Merge(int A[], int l, int mid, int h)
{ // for lists in single array
    int B[h];
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= h)
    {
        if (A[i] <= A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }
    for (; i <= mid; i++)
        B[k++] = A[i];
    for (; j <= h; j++)
        B[k++] = A[j];

    for (k = l, i = 0; k <= h; k++, i++)
        A[k] = B[i];
    return 0;
}

int MergeSort(int A[], int n) //Iterative Merge Sort
{
    int p;
    int i;
    for (p = 2; p <= n; p = p * 2)
    {
        for (i = 0; i < n; i = i + p)
            Merge(A, i, i + p / 2 - 1, i + p - 1);
    }
    if (p / 2 < n)
        Merge(A, 0, p / 2 - 1, n - 1);
    return 0;
}

void MergeRecur(int A[], int l, int h)
{
    if (l < h)
    {
        int mid = (l + h) / 2;
        MergeRecur(A, l, mid);
        MergeRecur(A, mid + 1, h);
        Merge(A, l, mid, h);
    }
}

int main()
{
    int i;
    int A[] = {12, 22, 4, 16, 88, 9, 10, 25, 33, 13, 7, 3, 15, 11, INT16_MAX};
    int n = 14;
    //for (i = 2; i < n; i++) // for inserting in heap
    //    Insert(A, i);
    //for (i = n - 1; i > 0; i--) //Sorting the heap using Delete
    //    Delete(A, i);
    //Heapify(A, n, n-1);
    //Bubble(A, n);
    //Selection(A, n);
    //MergeRecur(A,0, n);
    //MergeSort(A,n);
    //Merge(A, 0, 3, 7);
    //QuickSort(A, n, 0);
    for (i = 0; i < n; i++) // display heap
        cout << A[i] << endl;
    return 0;
}