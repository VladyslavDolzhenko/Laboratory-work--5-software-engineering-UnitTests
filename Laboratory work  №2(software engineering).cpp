#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

void checkValidInput() {
	if (cin.fail()) {
		throw "Incorrect input!";
	}
}

void checkValidParams(int n, double a, double b, double h) {
	if (n <= 0) {
		throw "Error, change your n!";
	} else if (n > 0) {
		if (a > b) {
			throw "Your a > b!";
		} else if (a <= b) {
			if (h <= 0) {
				throw "Your h <= 0";
			}
		}
	}
}

int choice;

bool calculate(double a, double b, double h, int n) {

	for (double x = a; x <= b; x += h) {
		if (x >= 0) {
			int i = 0;
			double y = 0;
			if (n == 1) {
				y = x - 1;
				cout << "x = " << x << "; y = " << y << endl;
				if (choice == 1) {
					ofstream fout("results.txt", ios_base::app);
					fout << "x = " << x << "; y = " << y << endl;
				}
			} else if (n != 1) {
				y = 0;
				int k = n - 1;

				for (i = 0; i <= k; i++) {
					y += (x - 1) / (i + 1) - 18;  // changes
				}
				cout << "x = " << x << "; y = " << y << endl;
				if (choice == 1) {
					ofstream fout("results.txt", ios_base::app);
					fout << "x = " << x << "; y = " << y << endl;
				}
			}
		} else if (x < 0) {
			if (n == 1) {
				throw "Error, change your n!";
			} else if (n > 1) {
				double y = 0;
				int k = n - 1;

				for (int i = 1; i <= k; i++) {
					double sum = 0;

					for (int j = 1; j <= n; j++) {
						sum += x - pow(i, 2) + j * 20;  // changes
					}
					y += sum;
				}
				cout << "x = " << x << "; y = " << y << endl;
				if (choice == 1) {
					ofstream fout("results.txt", ios_base::app);
					fout << "x = " << x << "; y = " << y << endl;
				}
			}
		}
	}
	return true;
}


	int main() {
		int n;
		double a, b, h;
		double y = 0;

		try {
			cout << "Enter a (from), b (to), h (step) and n: ";
			cin >> a >> b >> h >> n;
			checkValidInput();
			checkValidParams(n, a, b, h);
			choice;
			cout << "Do you want to record the results of each step written to a file?\nYes - 1; No - 0" << endl;
			cin >> choice;
			checkValidInput();
			calculate(a, b, h, n);
		}
		catch (const char* ex) {
			cout << ex << endl;
			return -1;
		}
		catch (...) {
			cout << "Unknown error!" << endl;
			return -2;
		}
		return 0;
	}