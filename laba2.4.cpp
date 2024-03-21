#include <iostream>
#include <ctime>
#include <random>

using namespace std;

struct link {
	char symbol;
	link* next;
};

void Filling(link*& top, int quantity) { //Заполнение списков
	srand(time(0));
	for (int i = 0; i < quantity; i++) {
		link* nv= NULL;
		nv = new link; // образуем новый элемент списка
		nv->symbol = rand() % 23 + 65;
		nv->next = NULL;
		if (!top)             // если список пуст  
			top = nv;           // первый элемент списка
		else
		{
			nv->next = top; // вставляем в начало списка
			top = nv;
		}
	}
}

void Print(link* top) { //Вывод списков на экран
	while (top) {
		cout << top->symbol << " ";
		top = top->next;
	}
	cout << endl;
}

void add(link*& top, char key) //Добавление нового элемента 
{
	link* nv = NULL;
	nv = new link; // образуем новый элемент списка
	nv->symbol = key;
	nv->next = NULL;
	if (!top)             // если список пуст  
		top = nv;           // первый элемент списка
	else
	{ // вставляем в начало списка               
		nv->next = top;
		top = nv;
	}
}

bool Poisk(char key, link* top) {
	bool k = 1;
	while (top) {
		if (key == top->symbol) { //Поиск элемента из списка L1 в списке L, чтобы не было повторов в L
			k = 0;
		}
		top = top->next;
	}
	return k;
}

void Myfunction(link*& top, link* top1, link* top2) {
	char key;
	while (top1) {
		key = top1->symbol;
		if (Poisk(key, top) && Poisk(key, top2)) {
			add(top, key);
		}
		top1 = top1->next;
	}
}

int main() {

	cout << "Enter quantity of symbols of l1 list: ";
	int l1_quantity;
	cin >> l1_quantity;

	cout << "Enter quantity of symbols of l2 list: ";
	int l2_quantity;
	cin >> l2_quantity;

	link* top1 = NULL;
	link* top2 = NULL;
	link* top = NULL;

	Filling(top1, l1_quantity);
	cout << "L1:" << endl;
	Print(top1);
	Filling(top2, l2_quantity);
	cout << "L2:" << endl;
	Print(top2);

	Myfunction(top, top1, top2);
	cout << "L:" << endl;
	Print(top);

	return 0;
}
