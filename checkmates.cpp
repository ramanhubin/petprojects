using namespace std;
#include <cmath>
#include <iostream>

int main()
{

	int x, y;
	cout << "input first coordinates ";
	cin >> x >> y;
	int x1, y1;
	cout << "input second coordinates ";
	cin >> x1 >> y1; //объявление координат шахмат

	if (x > 8 || y > 8 || x1 > 8 || y1 > 8 || x<1 ||y<1 || x1<1 || y1<1) {
		cout << "wrong coordinates";
		return 0;
	}
		//проверка координат
		if (y - y1 == 0 || x - x1 == 0 || abs(x - x1) == abs(y - y1)) {
			cout << "this move is possible ";

		}				//проверка хода

		else if ((x - x1) > (y - y1) && x - x1 > 0) {
			x = abs(x - x1) - x;
			cout << "This figure should be moved to ";
			cout << abs(x) <<" "<< y;

		}

		else if ((x - x1) > (y - y1) && x - x1 < 0) {
			x = abs(x - x1) + x;
			cout << "This figure should be moved to ";
			cout << x <<" "<< y;
		}

		else if ((x - x1) < (y - y1) && y - y1 > 0) {
			y = abs(y - y1) - y;
			cout << "This figure should be moved to ";
			cout << x <<" "<< abs(y);
		}

		else if ((x - x1) < (y - y1) && y - y1 < 0) {
			y = abs(y - y1) + y;
			cout << "This figure should be moved to ";
			cout << x<<" "<<abs(y);
			
		}  //поиск самого оптимального хода
	}

