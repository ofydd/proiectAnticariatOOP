#include <iostream>
using namespace std;
/*
Proiectul trebuie sa contina urmatoarele elemente :

4 clase
o clasa de baza
doua clase derivate din clasa de baza
o clasa care sa contina un vector cu elemente de tipul clasei de baza
Fiecare clasa va contine :
Constructori(fara parametri, cu parametri, de copiere)
Destructori
Supraincarcarea operatorului de atribuire
Metode de acces pentru campurile private
Supraincarcarea operatorilor de citire si afisare
In plus, clasa care contine vectorul va contine :

supraincarcarea operatorului += pentru a adauga un element in vector
supraincarcarea operatorului -= pentru a elimina un element din vector
operatorul de acces pe baza de index, pentru citirea unui element din vector de la o pozitie data
serializare / deserializare in / din fisiere binare a vectorului

*/

enum Status {
	Activ,
	Inactiv
};

ostream& operator<<(ostream& os, const Status& status)
{
	switch (status) {
	case Activ:
		cout << "activ ";
		break;
	case Inactiv:
		cout << "inactiv ";
		break;
	}
	return os;
}

istream& operator>>(istream& is, Status& status)
{
	cout << "Alegeti status-ul pentru produs. " << endl;
	cout << "1. Activ" << endl;
	cout << "2. Inactiv" << endl;
	cout << "Va rog sa introduceti un numar: ";
	unsigned short int alegere; // pentru ca lucrez cu numere foarte mici, m-am gandit sa aloc doar 2 bytes
	cin >> alegere;
	switch (alegere) {
	case 1:
		status = Status::Activ;
		break;
	case 2:
		status = Status::Inactiv;
		break;
	default:
		cout << "Status necunoscut. Produsul a fost incadrat automat in categoria inactiv." << endl;
		status = Status::Inactiv;
		break;
	}
	return is;
}

enum Categorie
{
	Carti,
	Vinyluri,
	Nedefinit //pentru cazul default din switch(categorie) si pentru constructorul fara parametri
};

ostream& operator<<(ostream& os, const Categorie& categorie)
{
	switch (categorie)
	{
	case Categorie::Carti:
		cout << "carte ";
		break;
	case Categorie::Vinyluri:
		cout << "vinyl ";
		break;
	case Categorie::Nedefinit:
		cout << "nedefinit ";
		break;
	}
	return os;
}

istream& operator>>(istream& is, Categorie& categorie)
{
	cout << "Introduceti categoria produsului." << endl;
	cout << "1. Carte" << endl;
	cout << "2. Vinyl" << endl;
	cout << "Va rog introduceti un numar: ";

	unsigned short int alegere;
	cin >> alegere;

	switch (alegere) {
	case 1:
		categorie = Categorie::Carti;
		break;
	case 2:
		categorie = Categorie::Vinyluri;
		break;
	default:
		cout << "Categorie necunoscuta! Produsul a fost incadrat automat ca fiind nedefinit";
		categorie = Categorie::Nedefinit;
		break;
	}
	return is;
}

enum genLiterar
{
	Filosofie,
	IstoriaReligiilor,
	Istorie,
	Proza,
	Poezie,
	Psihologie,
	LiterarNedefinit
};

ostream& operator<<(ostream& os, const genLiterar& gen)
{
	switch (gen) {
	case genLiterar::Filosofie:
		cout << "filosofie ";
		break;
	case genLiterar::IstoriaReligiilor:
		cout << "istoria religiilor";
		break;
	case genLiterar::Istorie:
		cout << "istorie ";
		break;
	case genLiterar::Proza:
		cout << "proza ";
		break;
	case genLiterar::Poezie:
		cout << "poezie ";
		break;
	case genLiterar::Psihologie:
		cout << "psihologie ";
		break;
	case genLiterar::LiterarNedefinit:
		cout << "nedefinit ";
		break;
	}
	return os;
}

istream& operator>>(istream& is, genLiterar& gen)
{
	cout << "Introduceti genul literar." << endl;
	cout << "1. Filosofie" << endl;
	cout << "2. Istoria religiilor" << endl;
	cout << "3. Istorie" << endl;
	cout << "4. Proza" << endl;
	cout << "5. Poezie" << endl;
	cout << "6. Psihologie" << endl;
	cout << "Introduceti un numar: ";
	unsigned short alegere;
	cin >> alegere;
	switch (alegere) {
	case 1:
		gen = genLiterar::Filosofie;
		break;
	case 2:
		gen = genLiterar::IstoriaReligiilor;
		break;
	case 3:
		gen = genLiterar::Istorie;
		break;
	case 4:
		gen = genLiterar::Proza;
		break;
	case 5:
		gen = genLiterar::Poezie;
		break;
	case 6:
		gen = genLiterar::Psihologie;
		break;
	default:
		cout << "Gen literar necunoscut. Cartea a fost incadrata automat in genul literar nedefinit";
		gen = genLiterar::LiterarNedefinit;
		break;
	}

	return is;
}

enum genMuzical
{
	Rock,
	Metal,
	Clasica,
	Pop,
	Populara,
	MuzicalNedefinit
};

ostream& operator<<(ostream& os, const genMuzical& gen) {
	switch (gen)
	{
	case genMuzical::Clasica:
		cout << "muzica clasica ";
		break;
	case genMuzical::Metal:
		cout << "metal ";
		break;
	case genMuzical::Pop:
		cout << "pop ";
		break;
	case genMuzical::Populara:
		cout << "muzica populara";
		break;
	case genMuzical::Rock:
		cout << "rock ";
		break;
	case genMuzical::MuzicalNedefinit:
		cout << "nedefinit ";
		break;
	default:
		cout << "nedefinit";
		break;
	}
	return os;
}

istream& operator>>(istream& is, genMuzical& gen)
{
	cout << "Introduceti genul muzical." << endl;
	cout << "1. Muzica Clasica" << endl;
	cout << "2. Metal" << endl;
	cout << "3. Pop" << endl;
	cout << "4. Muzica populara" << endl;
	cout << "5. Rock" << endl;
	cout << "Introduceti un numar: ";
	unsigned short int alegere;
	cin >> alegere;
	switch (alegere)
	{
	case 1:
		gen = genMuzical::Clasica;
		break;
	case 2:
		gen = genMuzical::Metal;
		break;
	case 3:
		gen = genMuzical::Pop;
		break;
	case 4:
		gen = genMuzical::Populara;
		break;
	case 5:
		gen = genMuzical::Rock;
		break;
	default:
		cout << "Gen muzical necunoscut. Vinyl-ul a fost incadrat automat in genul muzical nedefinit";
		gen = genMuzical::MuzicalNedefinit;
		break;
	}
	return is;
}

class Produs
{

protected:
	unsigned int idProdus;
	unsigned int stoc;
	float pret;
	Status statusProdus;

public:
	Produs() {
		this->idProdus = 0;
		this->stoc = 0;
		this->pret = 0;
		this->statusProdus = Status::Inactiv;
	}

	//TODO: Constructor cu parametri;

	unsigned int getIDProdus() { return this->idProdus; }
	void setIDProdus(unsigned int id)
	{
		if (id != 0)
			this->idProdus = id;
		else
			cout << "id invalid"; //TODO: exceptie
	}

	unsigned int getStoc() { return this->stoc; }
	void setStoc(unsigned int stoc)
	{
		if (stoc > 0)
			this->stoc = stoc;
		else
			cout << "stoc invalid!" << endl; //TODO: exception;
	}

	float getPret() { return this->pret; }
	void setPret(float pret)
	{
		if (pret > 0)
			this->pret = pret;
		else
			cout << "pret invalid"; //TODO: exception;
	}

	Status getStatusProdus() { return this->statusProdus; }
	void setStatusProdus(Status s)
	{
		this->statusProdus = s; //TODO: daca exista validari, ar trebui sa le fac.
	}

	~Produs(){}
};

class Carte : public Produs
{
public:
	Carte()
	{
		if (this->titlu != NULL) 
		{
			delete[] this->titlu;
		}
		this->titlu = new char[10];
		strcpy_s(this->titlu, 10, "undefined");

		if (this->autor != NULL) 
		{
			delete[] this->autor;
		}
		this->autor = new char[10];
		strcpy_s(this->autor, 10, "undefined");

		if (this->editura != NULL)
			delete[] this->editura;
		this->editura = new char[10];
		strcpy_s(this->editura, 10, "undefined");

		this->numarPagini = 0;
		this->anAparitie = 0;
		this->gen_literar = genLiterar::LiterarNedefinit;
	}

	Carte(char* titlu, char* autor, char* editura, unsigned int nrPag, unsigned int an, genLiterar gl)
	{
		if (strlen(titlu) != 0) 
		{
			if (this->titlu != NULL)
				delete[] this->titlu;
			this->titlu = new char[strlen(titlu) + 1];
			strcpy_s(this->titlu, strlen(titlu) + 1, titlu);
		}
		else
		{
			if (this->titlu != NULL)
				delete[] this->titlu;
			this->titlu = new char[10];
			strcpy_s(this->titlu, 10, "undefined");
		}

		if (strlen(autor) > 0)
		{
			if (this->autor != NULL)
				delete[] this->autor;
			this->autor = new char[strlen(autor) + 1];
			strcpy_s(this->autor, strlen(autor) + 1, autor);
		}
		else
		{
			if (this->autor != NULL)
				delete[] this->autor;
			this->autor = new char[10];
			strcpy_s(this->autor, 10, "undefined");
		}

		if (strlen(editura) > 0)
		{
			if (this->editura != NULL)
				delete[] this->editura;
			this->editura = new char[strlen(editura) + 1];
			strcpy_s(this->editura, strlen(editura) + 1, editura);
		}
		else
		{
			if (this->editura != NULL)
				delete[] this->editura;
			this->editura = new char[10];
			strcpy_s(this->editura, 10, "undefined");
		}

		if (nrPag > 0)
			this->numarPagini = nrPag;
		else
			this->numarPagini = 0;

		if (anAparitie > 0)
			this->anAparitie = anAparitie;
		else
			this->anAparitie = 0;
		
		this->gen_literar = gl;
	}

private:
	char* titlu;
	char* autor;
	char* editura;
	unsigned int numarPagini;
	unsigned int anAparitie;
	genLiterar gen_literar;
};

class Vinyl : public Produs
{
public:
	Vinyl()
	{
		this->numeAlbum = new char[10];
		strcpy_s(this->numeAlbum, 10, "undefined");
		this->artist = new char[10];
		strcpy_s(this->artist, 10, "undefined");
		this->numarPiese = 0;
		this->durata = 0;
		this->gen_muzical = genMuzical::MuzicalNedefinit;
	}

private:
	char* numeAlbum;
	char* artist;
	unsigned int numarPiese;
	float durata;
	genMuzical gen_muzical;
};

class Comanda
{
public:
	Produs** produse;
private:
	char* numeClient;
	char* prenumeClient;
	float valoareComanda;
};

int main()
{

	return 0;
}

/*
	P.S.
	Am mers pe ideea de a folosi enum-uri pentru a putea oferi o anumita continuitate datelor.
	Practic, la scrierea in fisier, nu vreau sa apara fie Activ, fie activ sau aCtiv, ACTIV.
	Pentru fiecare enum am considerat de folos sa implementez operatorii de scriere si citire
	si am mers pe varianta scolareasca de a asocia pentru fiecare valoare posibila un numar, pe care
	sa il citesc de la tastatura, pentru a nu ma complica cu diferitele moduri de scriere ale unui cuvant
	- i.e filosofie vs filozofie vs FILOSOFIE, etc.

	Daca considerati ca este prea mult si ca se
*/