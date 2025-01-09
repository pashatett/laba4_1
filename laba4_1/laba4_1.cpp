#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <algorithm>

using namespace std;

void RandArrInt(int* mass, int n);
int* newArrInt(int n);
double* newArrDouble(int n);
void RandArrDouble(double* mass, int n);
void ShowArrInt(int* mass, int n);
void ShowArrDouble(double* mass, int n);
void chislo_mensheC_0(int* mass, int n, int C);
int N();
void Task1();
void Task2();
void Task3();
double SumElEvDouble(double* mass, int n);
void Task4();
int MultIntAfterMax(int* mass, int n);
void Task5();
void Task6();
int linealSearch(double* mass, int n, double searchh);
void Task7();
void SelectionSortDouble(double* mass, int n);
void SelectionSortInt(int* mass, int n);
void Task8();
void deleteFromDiap(double* mass, int a, int b, int n);
void Task9();
void helpIntFastSort(int* array, int size, int low, int high);
int partition(int* array, int size, int low, int high);
void Task10();
int bin_search(const int n, int* arr, int k);
void quicksort(const int n, int* arr);

int main()
{
    setlocale(LC_ALL, "");
    srand(unsigned(time(0)));
    cout << "*******************************" << endl;
    cout << setw(45) << "Лабораторная работа №4" << endl;
    cout << setw(40) << "Одномерные массивы" << endl;
    cout << "Выполнил студент группы 151412" << endl;
    cout << setw(49) << "Пирогов Павел Алексеевич" << endl;
    cout << setw(30) << "Вариант №17" << endl;
    cout << "*******************************" << endl << endl;
    int n;
    cout << "Какую задачу хотите запустить? "; cin >> n;
        switch (n) {
        case 1:
            Task1();
            break;
        case 2:
            Task2();
            break;
        case 3:
            Task3();
            break;
        case 4:
            Task4();
            break;
        case 5:
            Task5();
            break;
        case 6:
            Task6();
            break;
        case 7:
            Task7();
            break;
        case 8:
            Task8();
            break;
        case 9:
            Task9();
            break;
        case 10:
            Task10();
            break;

        default:
            cout << "Такой задачи нет((";
            break;
        }
}

int N() {
    int n;
    do {
        cout << "Сколько чисел хотите в массиве? "; cin >> n;
    } while (n <= 0);
    return n;
}

int* newArrInt(int n) {
    int* mass = new int[n];
    RandArrInt(mass, n);
    return mass;
}

double* newArrDouble(int n) {
    double* mass = new double[n];
    RandArrDouble(mass, n);
    return mass;
}

void RandArrInt(int* mass, int n) {
    for (int i = 0; i < n; i++) {
        mass[i] = rand() % 200 - 100;
    }
}

void RandArrDouble(double* mass, int n) {
    for (int i = 0; i < n; i++) {
        mass[i] = 0.01 * (rand() % 20000 - 10000);
    }
}

void ShowArrInt(int* mass, int n) {
    for (int i = 0; i < n; i++) {
        cout << mass[i] << " ";
    }
    cout << endl;
}
void ShowArrDouble(double* mass, int n) {
    for (int i = 0; i < n; i++) {
        cout << mass[i] << " ";
    }
    cout << endl;
}

void Task1() {
    int n = N();
    int* mass = newArrInt(n);
    ShowArrInt(mass, n);
    delete[] mass;
}

void Task2() {
    int n = N();
    double* mass = newArrDouble(n);
    ShowArrDouble(mass, n);
    delete[] mass;
}

void Task3() {
    int n = N();
    double* mass = newArrDouble(n);
    ShowArrDouble(mass, n);
    cout << "сумма элементов массива с четными индексами = " << SumElEvDouble(mass, n);
    delete[] mass;
}

double SumElEvDouble(double* mass, int n) {
    double summ = 0.0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0)summ += mass[i];
    }
    return summ;
}

void Task4() {
    int n = N();
    int* mass = newArrInt(n);
    ShowArrInt(mass, n);

    int mult = MultIntAfterMax(mass, n);

    cout << "произведение, расположенных после максимального элемента = " << mult;

    delete[] mass;
}

int MultIntAfterMax(int* mass, int n) {
    int maxx = mass[0];
    int mmm = 0;

    for (int i = 1; i < n; i++) {
        if (maxx < mass[i]) {
            maxx = mass[i];
            mmm = i;
        }
    }
    if (mmm == n - 1)
        return mass[mmm];
    else {
        int mult = 1;
        for (int i = mmm + 1; i < n; i++) {
            mult *= mass[i];
        }
        return mult;
    }
}

void Task5() {
    int n = N();
    int* mass = newArrInt(n);
    ShowArrInt(mass, n);

    int C;
    cout << "Введите число С, числа которые меньше заменятся на 0: "; cin >> C;
    chislo_mensheC_0(mass, n, C);
    ShowArrInt(mass, n);

    delete[] mass;
}

void chislo_mensheC_0(int* mass, int n, int C) {
    for (int i = 0; i < n; i++) {
        if (mass[i] < C) mass[i] = 0;
    }
}

void Task6() {
    int n = N();
    double* mass = newArrDouble(n);
    ShowArrDouble(mass, n);

    double searchh;
    cout << "Введите число, индекс которого вы хотите узнать: "; cin >> searchh;
    int a = linealSearch(mass, n, searchh);
    if (a == -1) cout << "Такого элемента нет в массиве";
    else cout << "Элемент на ходится под " << a << " индексом";

    delete[] mass;
}

int linealSearch(double* mass, int n, double searchh) {
    int i = 0;
    int countt = -1;
    while (i < n) {
        if (searchh == mass[i]) { countt = i; break; }
        i++;
    }
    return countt;
}

void Task7() {
    int n = N();
    double* mass = newArrDouble(n);
    ShowArrDouble(mass, n);
    SelectionSortDouble(mass, n);
    ShowArrDouble(mass, n);

    delete[] mass;
}

void SelectionSortDouble(double* mass, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
            if (mass[j] < mass[min_index])
                min_index = j;
        if (min_index != i)
        {
            double temp = mass[i];
            mass[i] = mass[min_index];
            mass[min_index] = temp;
        }
    }
}

void Task8() {
    int n = N();
    double* mass = newArrDouble(n);
    ShowArrDouble(mass, n);
    int a, b;
    cout << "Введите целочисленный диапазон через пробел: "; cin >> a >> b;
    int minn = min(a, b);
    int maxx = max(a, b);
    ShowArrDouble(mass, n);
    delete[] mass;
}

void deleteFromDiap(double* mass, int a, int b, int n) {
    int index = 0;

    for (int i = 0; i < n; i++) {
        if (mass[i] < a || mass[i]> b) {
            mass[index] = mass[i];
            index++;
        }
    }

    for (int i = index; i < n; i++) {
        mass[i] = 0;
    }
}

void Task9() {
    int n = N();
    int* mass = newArrInt(n);
    ShowArrInt(mass, n);

    helpIntFastSort(mass, n, 0, n - 1);
    ShowArrInt(mass, n);

    delete[] mass;
}

void helpIntFastSort(int* array, int size, int low, int high) {
    if (low < high) {
        unsigned mid_index = partition(array, size, low, high);
        helpIntFastSort(array, size, low, mid_index);
        helpIntFastSort(array, size, mid_index + 1, high);
    }
}

int partition(int* array, int size, int low, int high) {
    int pivot = array[(low + high) / 2];
    int i = low;
    int j = high;
    while (1) {
        while (array[i] < pivot) i++;
        while (array[j] > pivot) j--;
        if (i >= j) return j;
        int buf = array[i];
        array[i] = array[j];
        array[j] = buf;
    }
}

void Task10() {
    int n;
    cout << "Введите размер массива" << endl;
    cin >> n;

    int* mas = new int[n];
    RandArrInt(mas,n);
    quicksort(n, mas);
    ShowArrInt(mas, n);

    int p, k;
    cout << "Введите элемент для бинарного поиска в массиве" << endl;
    cin >> k;
    p = bin_search(n, mas, k);
    if (p != -1)
        cout << "Элемент под номером " << p + 1 << endl;
    else
        cout << "Элемента нет" << endl;

    delete[] mas;
}

int bin_search(const int n, int* arr, int k) {
    int left = 0, right = n - 1, mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (arr[mid] == k)
            return mid;
        if (arr[mid] > k)
            right = mid - 1;
        if (arr[mid] < k)
            left = mid + 1;
    }
    return -1;
}

void quicksort(const int n, int* arr) {
    int i = 0, j = n - 1;
    int temp, p;
    p = arr[n >> 1];

    do {
        while (arr[i] < p)
            i++;
        while (arr[j] > p)
            j--;

        if (i <= j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    } while (i <= j);

    if (j >= 0)
        quicksort(j + 1, arr);
    if (n > i)
        quicksort(n - i, &arr[i]);
}
