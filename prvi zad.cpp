#include <iostream>
#include <cmath>
using namespace std;
void unos(int niz[], int);
void pronaci(int niz[], int);
float suma(int niz[], int);
int prebroji(int[], int);


int main() {
	int const n = 6;
	int niz[n];
	/*float suma = 0;*/
	/*int brojac = 0;*/
	cout << "Unesi 6 clanova niza" << endl;
	unos(niz, n);
	pronaci(niz, n);
	cout << "Suma rec vr " << suma(niz, n) << endl;
	/*for (int i = 0; i < n; i++)
		suma += (1.0 / niz[i]);*/
	/*cout << suma << endl;*/
	cout << "Pozitivnih elementa ima "<<prebroji(niz,n) << endl;
	for (int i = 0; i < n; i++)
	{
		if (niz[i] > 0)
		{ 
			cout << i + 1<<"." << " Broj niza = " << niz[i] << " je pozitivan" << endl;
		}
	}

	system("Pause");
	return 0;
}

void unos(int niz[], int n)
{
	for (int i=0; i < n; i++)
		cin >> niz[i];
}

void pronaci(int niz[], int n)
{
	int max = INT_MIN, max2 = INT_MIN,indeks;
	for (int i = 0; i < n; i++)
	{
		if (niz[i] > max)
		{
			max = niz[i];
			indeks = i;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (niz[i] > max2&& i != indeks)
			max2 = niz[i];
	}
	cout << "Najveci je " << max << " A drugi " << max2 << endl;
}

float suma(int niz[], int n)
{
	float suma1 = 0.00;
	for (int i = 0; i < n; i++)
	{
		suma1 += (1.0/niz[i]);
	}
	return suma1;
}
int prebroji(int niz[], int n)
{
	int brojac = 0;
	for (int i=0;i<n;i++)
		if (niz[i] > 0)
		{
			brojac++;
		}
	return brojac;
}