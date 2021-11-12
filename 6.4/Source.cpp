#include <iostream>
#include <time.h>

using namespace std;

void Create(int a[], int n, int Low, int High)
{
    for (int i = 0; i < n; i++)
        a[i] = Low + rand() % (High - Low + 1);

}

void vuvid(int* a, const int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int smallerC(int* a, const int n, int C) //a[5]={1,2,-3,-4,5}   C=3
{
    int S = 0;
    for (int i = 0; i < n; i++)
        if (a[i] < C)
            S++;
    return S;
}

int Sum(int* a, const int n, int k, int sum)//a[5]={1,2,-3,-4,5}   C=3
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)

            k = i;
    }
    sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (i > k)
            sum += a[i];
    }
    return sum;
}

int Max(int* a, const int n)
{
    int index = 0;
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max)
        {
            max = a[i];
            index = i;
        }
    return index;
}

int foundind(int* a, const int n, const int indx, const int start)
{
    int index = -1;
    for (int i = start; i < n; i++)
    {
        if (a[i] >= 0.8 * indx)
        {
            index = i;
            break;
        }
    }
    return index;
}

void transform(int* a, const int n)
{
    int t = -1;
    for (size_t i = 0; i < n; i++)
    {
        int i_1 = Max(a, n);
        int index = foundind(a, n, a[i_1], i);
        if (index != -1)
        {
            int tmp = a[index];
            a[index] = a[i];
            a[i] = tmp;
            t = i;
        }
        vuvid(a, n);
    }

    // {0, 3, 4, -2, 8}
    //int tmp = a[Max(a, n)];
    //a[Max(a, n)] = a[t + 1];
    //a[t + 1] = tmp;
}

int main()
{
    srand(time(NULL));

    double n;
    int C;
    int Low = -5;
    int High = 10;

    cout << "C="; cin >> C;
    cout << "n="; cin >> n;
    int* a = new int[n];

    Create(a, n, Low, High);
    vuvid(a, n);

    cout << "Sum=" << smallerC(a, n, C) << endl;
    cout << "-Sum=" << Sum(a, n, 0, 0) << endl;


    transform(a, n);
    vuvid(a, n);
    return 0;
}