#include <iostream>
#include <iomanip>

using namespace std;
class datum {
	int _dan, _mjesec, _godina;
public:
	datum(int dan=1,int mjesec=1,int godina=2020)
	{
		_dan = dan;
		_mjesec = mjesec;
		_godina = godina;
	}
};
int getID = 1;
int getRef = 20;
class kolekcija {
	const int _ID;
	int& _referenca;
	datum _datumkreiranja;
	int* _niz;
	int _trenutno;
	int _max;
public:
	//unutar zaglavlja se pristupa konstantama, referencama, i drugim klasama 
	kolekcija(int max = 5) : _ID(getID), _referenca(getRef) {
		getID++;
		_trenutno = 0;
		_max = max;
		_niz = new int[max];
	}
	~kolekcija() { delete[]_niz; _niz = nullptr; }
	
	kolekcija(kolekcija& original) : _ID(original._ID), _referenca(original._referenca),
	_datumkreiranja(original._datumkreiranja) {		//konstruktor kopije
		_trenutno = original._trenutno;		//da nema pokazivaca ovo bi se moglo bez konst. kopije
		_max = original._max;				//
		_niz = new int[_max];
		for (int i = 0; i < _trenutno; i++)		//alokacija novog niza tj. na novu lokaciju kopiramo sve elemente
		{
			_niz[i] = original._niz[i];	//niz[i] pripada novom objektu koji se kreira 
		}		
	}


	void dodajelement(int element) {
		if (_trenutno == _max) {
			_max += 5;
			int* temp = new int[_max];
			for (int i = 0; i < _trenutno; i++)
			{
				temp[i] = _niz[i]; //prosirujemo niz i preisujemo elemente u novi niz 
			}
			delete[] _niz;	//brisemo na sta pokazuje stari pok
			_niz = temp;	//sad pokazuje na novi prosireni niz
		}
		_niz[_trenutno] = element;	//dodavanje novog elementa
		_trenutno++;	//povecanje trenutnog, tj upis sljedc na sljedece mejsto
	}

	void info() {
		cout<<"ID: "<<_ID<<endl;
		cout << " Ref " << _referenca << endl;
		for (int i = 0; i < _trenutno; i++)
		{
			if (i == 0)
				cout << " [ ";
			cout << _niz[i] << " , ";
			if (i == _trenutno - 1)
				cout << " ] "<<endl;
		}
	}
};


int main() {
	kolekcija a;
	a.dodajelement(15);
	a.dodajelement(17);
	a.dodajelement(19);
	a.info();

	kolekcija b(a);		//bez konstruktora kopije problem je u destruktoru 
	kolekcija c = b;	//jer se u objektu a vec obrise *_niz a pokuzuje na isto zato nam treba konst. kopije(novi _niz)
	//c = b; ne moze jer se na liniji 64 vec konstruiso objekat c
	
	b.info();
	c.info();
	kolekcija d;
	d.info();
	system("Pause>0");
	return 0;
}