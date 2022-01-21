#include <iostream>
/*
Задание 17

1. Дан массив размера N и целые числа K и L (1 ≤ K ≤ L ≤ N). Найти среднее арифметическое элементов массива с номерами от K до L включительно.
2. Дан целочисленный массив размера N, не содержащий одинаковых чисел. Проверить, образуют ли его элементы арифметическую прогрессию. Если образуют, то вывести разность прогрессии, если нет — вывести 0.
3. Дан массив A размера N. Найти минимальный элемент из его элементов с четными номерами: A2, A4, A6,
4. Дан массив размера N. Найти номер его последнего локального максимума (локальный максимум — это элемент, который больше любого из своих соседей).
5. Дан целочисленный массив размера N, содержащий ровно два одинаковых элемента. Найти номера одинаковых элементов и вывести эти номера в порядке возрастания


Каждая задача решена в отдельном классе
*/


class z1
{
private:
    int n, k, l;
    int* arr;

public:

    z1(int size = 10, int left = 1, int right = 10) {
        n = size;
        k = left - 1;
        l = right - 1;
        arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = i + 1;
        }
    }

    z1(int size, int left, int right, int* m) {
        n = size;
        k = left - 1;
        l = right - 1;
        arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = m[i];
        }
    }

    void print_arr() {
        std::cout << "Массив:\n";
        for (int i = 0; i < n; i++) {
            std::cout << arr[i] << ' ';
        }
        std::cout << "\n";
    }

    void med() {
        int s = 0;
        for (int i = k; i < l + 1; i++) {
            s += arr[i];
        }
        std::cout << "Среднее значение ячеек от " << k + 1 << " до " << l + 1 << " равно " << (double)s/(l-k+1) << "\n";
    }

    void test() {
        std::cout << "Задача 1\n";
        print_arr();
        med();
    }
};

class z2
{
private:
    int n;
    int* arr;

public:

    z2(int size = 10) {
        n = size;
        arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = i + 1;
        }
    }

    z2(int size, int* m) {
        n = size;
        arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = m[i];
        }
    }

    void print_arr() {
        std::cout << "Массив:\n";
        for (int i = 0; i < n; i++) {
            std::cout << arr[i] << ' ';
        }
        std::cout << "\n";
    }

    void prog() {
        int r = 0;
        for (int i = 1; i < n; i++) {
            if (r == 0) {
                r = arr[i - 1] - arr[i];
            }
            else if (arr[i - 1] - arr[i] != r) {
                std::cout << "Арифмитическая прогрессия не образуется\n";
                return;
            }
        }
        std::cout << "Образует арифмитическую прогрессию с разностью прогрессии равной " << -1 * r << "\n";
    }

    void test() {
        std::cout << "Задача 2\n";
        print_arr();
        prog();
    }
};

class z3
{
private:
    int n;
    int* arr;

public:

    z3(int size = 10) {
        n = size;
        arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = i + 1;
        }
    }

    z3(int size, int* m) {
        n = size;
        arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = m[i];
        }
    }

    void print_arr() {
        std::cout << "Массив:\n";
        for (int i = 0; i < n; i++) {
            std::cout << arr[i] << ' ';
        }
        std::cout << "\n";
    }

    void min() {
        int *p = NULL;
        for (int i = 0; i < n; i ++) {
            if ((i + 1) % 2 == 0) {
                if (p == NULL) {
                    p = arr + i;
                }else if (*p > arr[i]) {
                    p = arr + i;
                }
            }
        }
        std::cout << "Минимальнай элемент находится под номером " << (p - arr) + 1 << " , значение равно " << *p << "\n";
    }

    void test() {
        std::cout << "Задача 3\n";
        print_arr();
        min();
    }
};

class z4
{
private:
    int n;
    int* arr;

public:

    z4(int size = 10) {
        n = size;
        arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = i + 1;
        }
    }

    z4(int size, int* m) {
        n = size;
        arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = m[i];
        }
    }

    void print_arr() {
        std::cout << "Массив:\n";
        for (int i = 0; i < n; i++) {
            std::cout << arr[i] << ' ';
        }
        std::cout << "\n";
    }

    void max() {
        int* p = NULL;
        for (int i = 1; i < n - 1; i++) {
             if (arr[i] > arr[i - 1] && arr[i + 1] < arr[i]) {
                 if (p == NULL) {
                     p = arr + i;
                 }
                 else {
                     p = arr + i;
                 }
            }
        }
        if (p == NULL) {
            std::cout << "Локальных максимумов нет \n";
        }
        else {
            std::cout << "Последний локальный максимум находится под номером " << (p - arr) + 1 << " , значение равно " << *p << "\n";
        }
    }

    void test() {
        std::cout << "Задача 4\n";
        print_arr();
        max();
    }
};

class z5
{
private:
    int n;
    int* arr;

public:

    z5(int size = 10) {
        n = size;
        arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = i + 1;
        }
    }

    z5(int size, int* m) {
        n = size;
        arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = m[i];
        }
    }

    void print_arr() {
        std::cout << "Массив:\n";
        for (int i = 0; i < n; i++) {
            std::cout << arr[i] << ' ';
        }
        std::cout << "\n";
    }

    void dd() {
        int* p = NULL;
        int* l = NULL;
        for (int i = 1; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i] == arr[j]) {
                    p = arr + i;
                    l = arr + j;
                }
            }
        }
        if (p == NULL) {
            std::cout << "Одинаковых элементов не нашлось \n";
        }
        else {
            std::cout << "Первый элемент стоит на месте " << (p - arr) + 1 << "  -  " << *p << "\n" << "Второй элемент стоит на месте " << (l - arr) + 1 << "  -  " << *l << "\n";
        }
    }

    void test() {
        std::cout << "Задача 5\n";
        print_arr();
        dd();
    }
};


int main()
{
    setlocale(LC_ALL, "rus");

    z1 first;
    z2 second;
    z3 third;
    z4 fourth;
    z5 fifth;

    first.test();
    second.test();
    third.test();
    fourth.test();
    fifth.test();

    return 0;
}
