#include <iostream>

using namespace std;

int& Max(int* Array, int N_Array) { //& указывает на то что функция ссылается на сам элемент массива, а не его копию
    int Max_Array = Array[0];
    int N_Max_Array = 0;
    for (int i = 1; i < N_Array; i++) {
        if (Array[i] > Max_Array) {
            Max_Array = Array[i];
            N_Max_Array = i;
        }
    }//поиск максимального элемента массива

    return Array[N_Max_Array];
}

int main()
{
    int N_Array;
    cout << "Vvedite rasmer massiva: ";
    cin >> N_Array;
    cout << "Vvedite massiv: ";

    int* Array = new int[N_Array];
    for (int i = 0; i < N_Array; i++) {
        cin >> Array[i];
    }
    
    int& Max_Array=Max(Array,N_Array);
    //Max_Array = Max(Array, N_Array);
    cout << Max_Array << endl;

    Max_Array = 0;//присваиваем макс элементу массива 0

    for (int i = 0; i < N_Array; i++)
        cout << Array[i] << " ";

    delete[] Array;//очищение памяти
    return 0;
}