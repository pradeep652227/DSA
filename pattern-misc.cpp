#include <iostream>
using namespace std;

void printPattern(int n)
{
    int y = n, m = 2 * n - 1;

    // Print the upper half of the pattern
    for (int i = 0; i < n; i++)
    {
        int x = n;
        int j = 0;
        int first_cond = i;
        if (i == n - 1)// in case of when middle has to be printed
            first_cond = i - 1;//not from j=0 to j=i but j=i-1

        for (j = 0; j <= first_cond; j++)
        {
            cout << x << " ";
            x--;
        }

        for (; j < m - 1 - i; j++)//this loop will not work in i==n-1
        {
            cout << y << " ";
        }

        if (i == n - 1)
        {
            cout << y << " ";
            j++;
        }

        for (; j < m - 1; j++)
        {
            cout << ++x << " ";
        }

        y--;
        cout << endl;
    }
}

int main()
{
    int n = 4;
    printPattern(n);

    // Print the mirror image of the pattern
    for (int i = n - 2; i >= 0; i--)
    {
        int x = n;
        int j = 0;
        int first_cond = i;

        for (j = 0; j <= first_cond; j++)
        {
            cout << x << " ";
            x--;
        }

        for (; j < 2 * n - 1 - 1 - i; j++)
        {
            cout << n - i << " ";
        }

        if (i == n - 2)
        {
            cout << n - i << " ";
            j++;
        }

        for (; j < 2 * n - 1 - 1; j++)
        {
            cout << ++x << " ";
        }

        cout << endl;
    }

    return 0;
}
