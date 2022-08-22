#include <iostream>
using namespace std;

// Declaration of swap function
void swap_p(int *m, int *n);
// TO DO
//void swap_r(int &m, int &n);

int main() 
{
    const int N = 10;
    int a[10] = {52, 1, 12, 16, 99, 1002,
        2001, 0, 79, 99};

    // Selection Sort
    for (int i = 0; i < (N - 1); i++)
    {
        int min_idx = i;

        // Find the index of the minimum element
        for (int j = i + 1; j < N; j++)
        {
            if (a[j] < a[min_idx])
            {
                min_idx = j;
            }
        }

        // Swap if i-th element not already smallest
        if (min_idx > i) 
        {
            swap_p(&a[i], &a[min_idx]);
        }
    }

    // Print sorted results
    for (int i = 0; i < N; i++)
    {
        cout << i << " " << a[i] << endl;
    }

    return 0;
}

void swap_p(int *x, int *y)
{
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}