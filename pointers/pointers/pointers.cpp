// Используя арифметику указателей, заполняет квадратичную целочисленную матрицу порядка N (6,8,10) случайными числами от 1 до  N*N согласно схемам, приведенным на рисунках. 
// Пользователь должен видеть процесс заполнения квадратичной матрицы.

#include <iostream>
#include <iomanip>
#include <ctime> // в ней функция time


using namespace std;



void mySwap(int &value1, int &value2) {
    int temp = value1;
    value1 = value2;
    value2 = temp;
}

void matrixReflection(int** a, int n) {

    int** ab = new int* [n]; // Создаем массив указателей
    for (int i = 0; i < n; i++)
    {
        ab[i] = new int[n]; // Создаем элементы
    }


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ab[i][j] = a[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {
            mySwap(ab[i][j], ab[i][j + n / 2]);
        }
    }

    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << setw(4) << ab[i][j] << ' ';
        }
        cout << '\n';
    }

}

void matrixReflectionTwo(int** a, int n) {

    int** ab1 = new int* [n]; // Создаем массив указателей
    for (int i = 0; i < n; i++)
    {
        ab1[i] = new int[n]; // Создаем элементы
    }


    for (int i = 0; i < n; i++)
    { 
        for (int j = 0; j < n; j++)
        {
            ab1[i][j] = a[i][j];
        }
    }

    for (int i = 0; i < n/2; i++)
    {
        for (int j = 0; j < n/2; j++)
        {
            mySwap(ab1[i][j], ab1[i + n/2][j + n/2]);
        }
    }
    
    for (int i = n/2; i < n; i++)
    {
        for (int j = 0; j < n/2; j++)
        {
            mySwap(ab1[i][j], ab1[i - n / 2][j + n / 2]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << setw(4) << ab1[i][j] << ' ';
        }
        cout << '\n';
    }

}

void matrixReflectionThree(int** a, int n) {

    int** ab2 = new int* [n]; // Создаем массив указателей
    for (int i = 0; i < n; i++)
    {
        ab2[i] = new int[n]; // Создаем элементы
    }


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ab2[i][j] = a[i][j];
        }
    }


    for (int i = n/2; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mySwap(ab2[i][j], ab2[i - n / 2][j]);
        }
    }


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << setw(4) << ab2[i][j] << ' ';
        }
        cout << '\n';
    }

}

void matrixRound(int** a, int n) {

    int** ab3 = new int* [n]; // Создаем массив указателей
    for (int i = 0; i < n; i++)
    {
        ab3[i] = new int[n]; // Создаем элементы
    }


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ab3[i][j] = a[i][j];
        }
    }


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {
            mySwap(ab3[i][j], ab3[i][j + n / 2]);
        }
    }

    for (int i = 0; i < n / 2; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {
            mySwap(ab3[i][j], ab3[i + n / 2][j + n / 2]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << setw(4) << ab3[i][j] << ' ';
        }
        cout << '\n';
    }

}

void matrixPointers(int** a, int n) {

    int** ab = new int* [n]; // Создаем массив указателей
    for (int i = 0; i < n; i++)
    {
        ab[i] = new int[n]; // Создаем элементы
    }


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ab[i][j] = a[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << setw(4) << ab[i][j] << ' ';
        }
        cout << '\n';
    }

}

void bubbleSort(int* a, int n)
{
    
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10 - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                //swap(a[j] , a[j+1]);
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;

            }
        }
    }
}

int main()
{
   
    srand(time(NULL)); // Инициализируем генератор случайных чисел. 

    const int N = 10;
    int n;

    cout << "Enter matrix size: ";
    cin >> n;
    
    int a[N][N];

    int k = 1;
    int i = 0;
    int j = 0;

    while (k <= n * n) {

        a[i][j] = k; //дейсвтие заполняет массив

            
        if (i <= j + 1 && i + j < n - 1)
            ++j;
        else if (i < j && i + j >= n - 1)
            ++i;
        else if (i >= j && i + j > n - 1)
            --j;
        else
            --i;
        ++k;
    }

   
    cout << "Before\n";


    for (int i = 0; i < n; ++i) {

        for (int j = 0; j < n; ++j)
        {
            //a[i][j] = 0;
            cout << setw(4) << a[i][j];

        }
        cout << endl;
    }

    cout << "======================================================\n";

    int** a1 = new int* [n]; // Создаем массив указателей
    for (int i = 0; i < n; i++)
    {
        a1[i] = new int[n]; // Создаем элементы
    }

    int** sort = new int* [n]; // Создаем массив указателей
    for (int i = 0; i < n; i++)
    {
        sort[i] = new int[n]; // Создаем элементы
    }

    while (k <= n * n)
    {
        a1[i][j] = k; //дейсвтие заполняет массив


        if (i <= j + 1 && i + j < n - 1)
            ++j;
        else if (i < j && i + j >= n - 1)
            ++i;
        else if (i >= j && i + j > n - 1)
            --j;
        else
            --i;
        ++k;
    }



    for (int i = 0; i < n; ++i) {

        for (int j = 0; j < n; ++j)
        {
            a1[i][j] = rand() % 50;
            cout << setw(4) << a1[i][j];

        }

        cout << endl;
    }

    cout << "======================================================\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a1[j] > a1[j + 1])
            {
                swap(a1[j], a1[j + 1]);
                /*int t = sort[j];
                sort[j] = sort[j + 1];
                sort[j + 1] = t;*/

            }
        }
    }

    for (int i = 0; i < n; ++i) {

        for (int j = 0; j < n; ++j)
        {
            cout << setw(4) << a1[i][j];
        }
        cout << endl;
    }

    cout << "======================================================\n";

    //matrixReflection(a1,n);

    cout << "======================================================\n";

    
    //matrixReflectionTwo(a1,n);

    cout << "======================================================\n";

    //matrixReflectionThree(a1, n);

    cout << "======================================================\n";

    //matrixPointers(a1,n);

    //matrixRound(a1,n);

    system("pause");
}


