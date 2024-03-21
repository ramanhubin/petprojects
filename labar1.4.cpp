#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

double F_1(double a, double s) {
	return (a - 1) * (a - 1) * (a - 1) - 1;
}

double F_2(double a, double s) {
	double Pi = 3.1415;
	return s * a - cos(Pi * a) * cos(Pi * a);
}

double MethodPolDel_1(double (*F_1)(double, double), double s, double a, double b, double epsilon, long int& k_iter_1) {
	double c = (a + b) / 2;

	while (abs(a - b) >= epsilon) {
		k_iter_1++;
		if (F_1(a, s) * F_1(c, s) < 0) {
			b = c;
		}
		else {
			a = c;
		}
		c = (a + b) / 2;
	}

	return c;


}

double MethodPolDel_2(double a, double b, double epsilon) {
	return 0;
}

int main() {

	cout << "First equation: y = (x - 1) * (x - 1) * (x - 1) - 1" << endl;

	double a = 0;
	double b = 3;
	double epsilon = 0.000001;

	long int k_iter_1 = 0;
	double s = 0;
	double x = MethodPolDel_1(F_1, s, a, b, epsilon, k_iter_1);
	double y = F_1(x, s);

	cout << "|" << setw(15) << "S" << "|" << setw(15) << "x" << "|" << setw(15) << "y" << "|" << setw(15) << "k_iter" << "|" << endl;
	cout << "|" << setw(15) << s << "|" << setw(15) << x << "|" << setw(15) << y << "|" << setw(15) << k_iter_1 << "|" << endl;

	cout << endl;
	cout << "Second equation: y = s * x - cos(Pi * x) * cos(Pi * x)" << endl;

	a = -1;
	b = 0.7;
	cout << "|" << setw(15) << "S" << "|" << setw(15) << "x" << "|" << setw(15) << "y" << "|" << setw(15) << "k_iter" << "|" << endl;
	for (int s = 1; s < 4; s++) {
		k_iter_1 = 0;
		double x = MethodPolDel_1(F_2, s, a, b, epsilon, k_iter_1);
		double y = F_2(x, s);
		cout << "|" << setw(15) << s << "|" << setw(15) << x << "|" << setw(15) << y << "|" << setw(15) << k_iter_1 << "|" << endl;
	}
	return 0;
}