#include <iostream>
#include <iomanip>
using namespace std;

void alokacija(int**& niz, int& redovi, int& kolona) {
	cout << "Unesite dimenzije niza: ";
	cin >> redovi >> kolona;
	niz = new int* [redovi];
	for (int i = 0; i < redovi; i++)
	{
		niz[i] = new int[kolona];
	}
};

void unos(int** niz, int redovi, int kolona) {
	for (int i = 0; i < redovi; i++)
		for (int j = 0; j < kolona; j++)
		{
			//cin >> niz[i][j];
			niz[i][j] = rand() % 100 + 1;
		}
};

void ispis(int** niz, int redovi, int kolona)
{
	for (size_t i = 0; i < redovi; i++)
	{
		for (size_t j = 0; j < kolona; j++)
		{
			cout << setw(4) << niz[i][j];
		}
		cout << endl;
	}
};
void dealokacija(int** niz, int redovi) {
	for (size_t i = 0; i < redovi; i++)
	{
		delete[] niz[i];
	}
	delete[] niz;
	niz = nullptr;
};


int main() {
	int redovi=0, kolona=0;
	int** pok = nullptr;
	
	alokacija(pok, redovi, kolona);
	unos(pok, redovi, kolona);
	ispis(pok, redovi, kolona);
	dealokacija(pok, redovi);


	system("Pause>0");
	return 0;
}
