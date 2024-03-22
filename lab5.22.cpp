using namespace std;
#include <iostream>
int sortByChoice(int a[],const int max) {

	for (int i = 0; i < max - 1; i++)
	{	//присвоение переменной минимум текущего элемента
		int min = a[i];
		// запоминаем индекс текущего элемента
		int index_min = i;
		// поиск минимума в части массива от i+1 до конца
		for (int j = i + 1; j < max; j++)
			if (a[j] < min)
			{ // запоминаем текущий найденный минимум
				min = a[j];
				index_min = j;    // запоминаем его индекс
			}
		// обмен местами текущего элемента и
		// найденного минимального
		a[index_min] = a[i];
		a[i] = min;
	}
	cout << "massiv1 = " << endl;
	for (int i = 0; i < max; i++)
		cout << a[i]<<" ";

	
	return 0;
}

int sortByChange(int a[], int max) {
	for (int i = 1; i < max; i++)
		//проход с N-1-го элемента вверх до i-го
		for (int j = max- 1; j >= i; j--)
			// обмен элементов в случае неправильного порядка
			if (a[j - 1] > a[j])
			{
				int x = a[j - 1];
				a[j - 1] = a[j];
				a[j] = x;
			}

	cout << "massiv2 = ";
	for (int i = 0; i < max; i++)
		cout << a[i]<< " ";
	return 0;
}


int main()
{

	int max = 10;
	int massiv[10];

	for (int i = 0; i <max; i++)
	{
		massiv[i] = rand() % 20;
	}
	cout << "Massiv1 = ";
	for (int i = 0; i < max; i++) {
		cout << massiv[i]<<" ";
	}
	sortByChoice(massiv, max);
	sortByChange(massiv, max);
}


