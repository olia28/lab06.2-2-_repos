#include <iostream>
#include <ctime>

using namespace std;

int FindAverageRec(int arr[], int size, int evenCount, double summ);

int main()
{
    int n = 0;

    srand(time(NULL));

    cout << "Input size of array: " << "\n";
    cin >> n;

    int* arr = new int[n];

    cout << "Created array: ";
    for (int k = 0; k < n; k++) //k <= n - 1
    {
        arr[k] = (rand() % 100) - 49;
        cout << arr[k];
        if (k != n - 1)
        {
            cout << ", ";
        }
        else
        {
            cout << "\n\n";
        }
    }

    cout << "Even index array element :" << endl;
    for (int i = 0; i < n; i++)
    {

        if (i % 2 == 0)
        {
            cout << "arr[" << i << "]= " << arr[i] << "\n";
        }
    }
    cout << "\nResultRec:" << FindAverageRec(arr, n, 0, 0) << endl;

    delete[] arr;
    system("pause");
}

int FindAverageRec(int arr[], int size, int evenCount, double summ)
{
    if ((size - 1) % 2 == 0)
    {
        evenCount++;
        summ += arr[size - 1];
    }

    if (size == 1)
        return summ / evenCount;
    return FindAverageRec(arr, size - 1, evenCount, summ);
}