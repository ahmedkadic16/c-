#include <iostream>
using namespace std;
void unos(int[], int,int);
int main() {
	int broj1, broj2;
	cout << "Unesi dva broja" << endl;
	cin >> broj1 >> broj2;

	unos();



	system("Pause>0");
	return 0;
}

void unos(int niz[], int duzina, int broj)
{
	int duzina = 0;
	while (broj != 0) {
		broj /= 10;
		cin >> niz[duzina];
		duzina += 1;
	}
	
}

