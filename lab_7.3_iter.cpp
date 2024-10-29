#include <iostream>
#include <iomanip>
using namespace std;

void Input(int** a, const int n);
void Print(int** a, const int n);
void FindEqualRowsAndColumns(int** a, const int n);
int SumNegativeRows(int** a, const int n);

int main()
{
    int n;

    cout << "n = ";
    cin >> n;

    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];

    Input(a, n);
    Print(a, n);

    FindEqualRowsAndColumns(a, n);

    int sum = SumNegativeRows(a, n);
    cout << "sum = " << sum << endl;

    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}


void Input(int** a, const int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
        cout << endl;
    }
}

void Print(int** a, const int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

void FindEqualRowsAndColumns(int** a, const int n)
{
    cout << "Rows equal to their corresponding columns:" << endl;
    for (int k = 0; k < n; k++)
    {
        bool equal = true;
        for (int j = 0; j < n; j++)
        {
            if (a[k][j] != a[j][k])
            {
                equal = false;
                break;
            }
        }
        if (equal)
        {
            cout << "Row " << k << " is equal to Column " << k << endl;
        }
    }
}

int SumNegativeRows(int** a, const int n)
{
    int totalSum = 0;
    for (int i = 0; i < n; i++)
    {
        bool hasNegative = false;
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] < 0)
            {
                hasNegative = true;
                break;
            }
        }
        if (hasNegative)
        {
            for (int j = 0; j < n; j++)
            {
                totalSum += a[i][j];
            }
        }
    }
    return totalSum;
}
