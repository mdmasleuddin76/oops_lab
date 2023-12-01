#include <bits/stdc++.h>
#include "element_inherit_poly.h"

using namespace std;

void sort_algo_2(Element *to_sort[], const int N = 10000)
{
    int i, j;
    Element *key = nullptr;
    for (i = 1; i < N; i++)
    {
        key = to_sort[i];
        j = i - 1;
        while (j >= 0 && to_sort[j]->norm() > key->norm())
        {
            to_sort[j + 1] = to_sort[j];
            j -= 1;
        }
        to_sort[j + 1] = key;
    }
}

void sort_algo_3(Element *to_sort[], const int N = 10000)
{
    for (int i = 1; i < N; i++)
    {
        Element *key = to_sort[i];
        int j = i - 1;
        bool flag = to_sort[j]->norm() > key->norm();
        while (j >= 0 && flag)
        {
            to_sort[j + 1] = to_sort[j];
            j--;
            flag = to_sort[j]->norm() > key->norm();
        }
        to_sort[j + 1] = key;
    }
}

void sort_algo_1(Element *to_sort[], const int N = 10000)
{
    int i, j;
    Element *key = nullptr;
    for (i = 1; i < N; i++)
    {
        key = to_sort[i];
        j = i - 1;
        while (j >= 0)
        {
            if (to_sort[j]->norm() > key->norm())
            {
                to_sort[j + 1] = to_sort[j];
                j -= 1;
            }
            else
            {
                break;
            }
        }
        to_sort[j + 1] = key;
    }
}

// void sort_algo_exp(Element *to_sort[], const int N = 10000)
// {
//     for (int i = 1; i < N; i++)
//     {
//         Element *key = to_sort[i];
//         int j = i - 1;
//         bool flag = to_sort[j]->norm() > key->norm();
//         while (j >= 0 && flag)
//         {
//             to_sort[j + 1] = to_sort[j];
//             j--;
//             flag = to_sort[j]->norm() > key->norm();
//         }
//         to_sort[j + 1] = key;
//     }
// }

double sortingExecutor3(const int K, bool toPrint = false)
{
    const int N = K;
    Element *to_sort[N];
    for (int i = 0; i < N; i++)
    {
        if (i % 3 == 0)
        {
            to_sort[i] = new Point(rand_gen(), rand_gen());
        }
        else if (i % 3 == 1)
        {
            to_sort[i] = new Vector(rand_gen(), rand_gen(), rand_gen());
        }
        else
        {
            int dimension = rand() % 8 + 2;
            PointN *temp = new PointN(dimension);
            temp->generate_random_points();
            to_sort[i] = temp;
        }
    }
    auto start_time = chrono::high_resolution_clock::now();
    sort_algo_3(to_sort, N);
    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);

    if (toPrint)
    {
        for (int i = 0; i < N; i++)
        {
            to_sort[i]->print();
        }
    }
    return static_cast<double>(duration.count());
}

double sortingExecutor2(const int K, bool toPrint = false)
{
    const int N = K;
    Element *to_sort[N];
    for (int i = 0; i < N; i++)
    {
        if (i % 3 == 0)
        {
            to_sort[i] = new Point(rand_gen(), rand_gen());
        }
        else if (i % 3 == 1)
        {
            to_sort[i] = new Vector(rand_gen(), rand_gen(), rand_gen());
        }
        else
        {
            int dimension = rand() % 8 + 2;
            PointN *temp = new PointN(dimension);
            temp->generate_random_points();
            to_sort[i] = temp;
        }
    }
    auto start_time = chrono::high_resolution_clock::now();
    sort_algo_2(to_sort, N);
    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);

    if (toPrint)
    {
        for (int i = 0; i < N; i++)
        {
            to_sort[i]->print();
        }
    }
    return static_cast<double>(duration.count());
}

double sortingExecutor1(const int K, bool toPrint = false)
{
    const int N = K;
    Element *to_sort[N];
    for (int i = 0; i < N; i++)
    {
        if (i % 3 == 0)
        {
            to_sort[i] = new Point(rand_gen(), rand_gen());
        }
        else if (i % 3 == 1)
        {
            to_sort[i] = new Vector(rand_gen(), rand_gen(), rand_gen());
        }
        else
        {
            int dimension = rand() % 8 + 2;
            PointN *temp = new PointN(dimension);
            temp->generate_random_points();
            to_sort[i] = temp;
        }
    }
    auto start_time = chrono::high_resolution_clock::now();
    sort_algo_1(to_sort, N);
    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);

    if (toPrint)
    {
        for (int i = 0; i < N; i++)
        {
            to_sort[i]->print();
        }
    }
    return static_cast<double>(duration.count());
}

int main()
{
    const int SIZES[5] = {10, 100, 1000, 10000, 20000};
    for (int i = 0; i < 5; i++)
    {
        double time1 = static_cast<double>(sortingExecutor1(SIZES[i]));
        double time2 = static_cast<double>(sortingExecutor2(SIZES[i]));
        double time3 = static_cast<double>(sortingExecutor3(SIZES[i]));
        cout << "Sorting Executor 1 = " << static_cast<long long>(sortingExecutor1(SIZES[i])) << " \xC2\xB5s"
             << " | ";
        cout << "Sorting Executor 2 = " << static_cast<long long>(sortingExecutor2(SIZES[i])) << " \xC2\xB5s"
             << " | ";
        cout << "Sorting Executor 3 = " << static_cast<long long>(sortingExecutor3(SIZES[i])) << " \xC2\xB5s" << endl;

        cout << "Speed Ratio = " << time1 / time2 << endl;
        cout << "Speed Ratio = " << time1 / time3 << endl;
        cout << "Speed Ratio = " << time2 / time3 << endl;
        cout << "Speed Ratio = " << time3 / time1 << endl;
        cout << "Speed Ratio = " << time3 / time2 << endl;
        cout << "Speed Ratio = " << time2 / time1 << endl;
        cout << endl;
    }
    return 0;
}