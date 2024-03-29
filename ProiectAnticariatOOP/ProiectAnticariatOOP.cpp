#include <iostream>
#include <string>
using namespace std;
/*
Proiectul trebuie sa contina urmatoarele elemente :


Fiecare clasa va contine :

Supraincarcarea operatorului de atribuire

In plus, clasa care contine vectorul va contine :

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

enum Categorie	//TODO: Implementare in cadrul clasei de baza.
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
		this->idProdus = 0; // TODO: de randomizat cu random();
		this->stoc = 0;
		this->pret = 0;
		this->statusProdus = Status::Inactiv;
	}

	Produs(unsigned int idProdus, unsigned int stoc, float pret, Status status)
	{
		if (idProdus > 0)
			this->idProdus = idProdus;
		else
			this->idProdus = 0;
		if (stoc > 0)
			this->stoc = stoc;
		else
			this->stoc = 0;
		if (pret > 0)
			this->pret = pret;
		else
			this->pret = 0;

		this->statusProdus = status;
	}

	Produs(const Produs& p)
	{
		this->idProdus = p.idProdus;
		this->stoc = p.stoc;
		this->pret = p.pret;
		this->statusProdus = p.statusProdus;
	}

	Produs& operator=(const Produs& p) {
		if (&p != this)
		{
			this->idProdus = p.idProdus; //TODO: de gandit daca merita sa schimb id-ul produsului aici, desi nu cred. 
			this->stoc = p.stoc;
			this->pret = p.pret;
			this->statusProdus = p.statusProdus;
		}
		else
			throw exception("Autoasignare");
		return *this;
	}

	unsigned int getIDProdus() { return this->idProdus; }
	void setIDProdus(unsigned int id)
	{
		if (id != 0)
			this->idProdus = id;

	}

	unsigned int getStoc() { return this->stoc; }
	void setStoc(unsigned int stoc)
	{
		if (stoc > 0)
			this->stoc = stoc;
	}

	float getPret() { return this->pret; }
	void setPret(float pret)
	{
		if (pret > 0)
			this->pret = pret;
	}

	Status getStatusProdus() { return this->statusProdus; }
	void setStatusProdus(Status s)
	{
		this->statusProdus = s; //TODO: daca exista validari, ar trebui sa le fac.
	}

	virtual void display(ostream& os)
	{
		os << "idProdus: " << this->idProdus << endl;
		os << "stoc: " << this->stoc << endl;
		os << "pret: " << this->pret << endl;
		os << "status: " << this->statusProdus << endl;
	}

	friend ostream& operator<<(ostream& os, Produs* produs)
	{
		produs->display(os);
		return os;
	}

	virtual void read(istream& is)
	{
		cout << "Introduceti id-ul produsului: ";
		is >> this->idProdus;
		cout << "Introduceti pretul: ";
		is >> this->pret;
		cout << "Introduceti cantitatea in stoc: ";
		is >> this->stoc;
		is >> this->statusProdus;
	}

	friend istream& operator>>(istream& is, Produs* produs)
	{
		produs->read(is);
		return is;
	}

	~Produs(){}
};

class Carte : public Produs
{
private:
	char* titlu;
	char* autor;
	char* editura;
	unsigned int numarPagini;
	unsigned int anAparitie;
	genLiterar gen_literar;

public:
	Carte() : Produs()
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

	Carte(unsigned int idProdus, unsigned int stoc, float pret, Status status, 
		  const char* titlu, const char* autor, const char* editura, 
		  unsigned int nrPag, unsigned int anAparitie, genLiterar gl) : Produs(idProdus, stoc, pret, status)
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
	
	Carte(const Carte& carte) {
		if (this->titlu != NULL)
			delete[] this->titlu;
		this->titlu = new char[strlen(carte.titlu) + 1];
		strcpy_s(this->titlu, strlen(carte.titlu) + 1, carte.titlu);
		
		if (this->autor != NULL)
			delete[] this->autor;
		this->autor = new char[strlen(carte.autor) + 1];
		strcpy_s(this->autor, strlen(carte.autor) + 1, carte.autor);

		if (this->editura != NULL)
			delete[] this->editura;
		this->editura = new char[strlen(carte.editura) + 1];
		strcpy_s(this->editura, strlen(carte.editura) + 1, carte.editura);

		this->numarPagini = carte.numarPagini;
		this->anAparitie = carte.anAparitie;
		this->gen_literar = carte.gen_literar;
	}

	Carte& operator=(const Carte& c)
	{
		if (&c != this)
		{
			if (this->titlu != NULL)
				delete[] this->titlu;
			this->titlu = new char[strlen(c.titlu) + 1];
			strcpy_s(this->titlu, strlen(c.titlu) + 1, c.titlu);

			if (this->autor != NULL)
				delete[] this->autor;
			this->autor = new char[strlen(c.autor) + 1];
			strcpy_s(this->autor, strlen(c.autor) + 1, c.autor);

			if (this->editura != NULL)
				delete[] this->editura;
			this->editura = new char[strlen(c.editura) + 1];
			strcpy_s(this->editura, strlen(c.editura) + 1, c.editura);

			this->numarPagini = c.numarPagini;
			this->anAparitie = c.anAparitie;
			this->gen_literar = c.gen_literar;
		}
		else
			throw exception("Autoasignare");
		return *this;
	}

	char* getTitlu() { return this->titlu; }
	void setTitlu(char* titlu)
	{
		if (strlen(titlu) > 0)
		{
			if (this->titlu != NULL)
				delete[] this->titlu;
			this->titlu = new char[strlen(titlu) + 1];
			strcpy_s(this->titlu, strlen(titlu) + 1, titlu);
		}
			
	}
	
	char* getAutor() { return this->autor; }
	void setAutor(char* autor)
	{
		if (strlen(autor) > 0)
		{
			if (this->autor != NULL)
				delete[] this->autor;
			this->autor = new char[strlen(autor) + 1];
			strcpy_s(this->autor, strlen(autor) + 1, autor);
		}
	}

	char* getEditura() { return this->editura; }
	void setEditura(char* editura)
	{
		if (strlen(editura) > 0)
		{
			if (this->editura != NULL)
				delete[] this->editura;
			this->editura = new char[strlen(editura)+1];
			strcpy_s(this->editura, strlen(editura) + 1, editura);
		}
	}

	unsigned int getNumarPagini() { return this->numarPagini; }
	void setNumarPagini(unsigned int nrPag)
	{
		if (nrPag > 0)
			this->numarPagini = nrPag;
	}

	unsigned int getAnAparitie() { return this->anAparitie; }
	void setAnAparitie(unsigned int an)
	{
		if (an > 0)
			this->anAparitie = an;
	}

	genLiterar getGenLiterar() { return this->gen_literar; }
	void setGenLiterar(genLiterar gen) { this->gen_literar = gen; }

	virtual void display(ostream& os) override
	{
		Produs::display(os);
		os << "titlu: " << this->titlu << endl;
		os << "autor: " << this->autor << endl;
		os << "editura: " << this->editura << endl;
		os << "nr. pagini: " << this->numarPagini << endl;
		os << "an aparitie: " << this->anAparitie << endl;
		os << "gen literar: " << this->gen_literar << endl;
	}
	friend ostream& operator<<(ostream& os, Carte* c)
	{
		c->display(os);
		return os;
	}

	virtual void read(istream& is) override
	{
		Produs::read(is);
		cout << "Introduceti titlul: ";
		char* titluTemp = new char[100];
		is >> ws;
		is.getline(titluTemp, 100);
		if (strlen(titluTemp)>0) 
		{
			if (this->titlu != 0)
				delete[] this->titlu;
			this->titlu = new char[strlen(titluTemp) + 1];
			strcpy_s(this->titlu, strlen(titluTemp) + 1, (char*)titluTemp);
		}
		
		cout << "Introduceti autorul: ";
		char* autorTemp = new char[100];
		is >> ws;
		is.getline(autorTemp, 100);
		if (strlen(autorTemp) > 0)
		{
			if (this->autor != NULL)
				delete[] this->autor;
			this->autor = new char[strlen(autorTemp) + 1];
			strcpy_s(this->autor, strlen(autorTemp) + 1, autorTemp);
		}

		cout << "Introduceti editura: ";
		char* edituraTemp = new char[100];
		is >> ws;
		is.getline(edituraTemp, 100);
		if (strlen(edituraTemp) > 0)
		{
			if (this->editura != NULL)
				delete[] this->editura;
			this->editura = new char[strlen(edituraTemp) + 1];
			strcpy_s(this->editura, strlen(edituraTemp) + 1, edituraTemp);
		}
		cout << "Introduceti numarul de pagini: ";
		is >> numarPagini; //TODO: validari
		
		cout << "Introduceti anul aparitiei: ";
		is >> anAparitie;

		is >> gen_literar;
	}

	friend istream& operator>>(istream& is, Carte* c)
	{
		c->read(is);
		return is;
	}

	~Carte()
	{
		delete[] this->titlu;
		delete[] this->autor;
		delete[] this->editura;
	}
	

};

class Vinyl : public Produs
{
private:
	char* numeAlbum;
	char* artist;
	unsigned int numarPiese;
	float durata;
	genMuzical gen_muzical;
public:
	Vinyl() : Produs()
	{
		this->numeAlbum = new char[10];
		strcpy_s(this->numeAlbum, 10, "undefined");
		this->artist = new char[10];
		strcpy_s(this->artist, 10, "undefined");
		this->numarPiese = 0;
		this->durata = 0;
		this->gen_muzical = genMuzical::MuzicalNedefinit;
	}

	Vinyl(unsigned int idProdus, unsigned int stoc, float pret, Status status, 
		  const char* numeAlbum, const char* numeArtist, unsigned int nrPiese, float length, genMuzical gm) : Produs(idProdus, stoc, pret, status)
	{
		if (strlen(numeAlbum) > 0) 
		{
			if (this->numeAlbum != NULL)
				delete[] this->numeAlbum;
			this->numeAlbum = new char[strlen(numeAlbum) + 1];
			strcpy_s(this->numeAlbum, strlen(numeAlbum) + 1, numeAlbum);
		}
		else
		{
			if (this->numeAlbum != NULL)
				delete[] this->numeAlbum;
			this->numeAlbum = new char[10];
			strcpy_s(this->numeAlbum, 10, "undefined");
		}

		if (strlen(numeArtist) > 0)
		{
			if (this->artist != NULL)
				delete[] this->artist;
			this->artist = new char[strlen(numeArtist) + 1];
			strcpy_s(this->artist, strlen(numeArtist) + 1, numeArtist);
		}
		else
		{
			if (this->artist != NULL)
				delete[] this->artist;
			this->artist = new char[sizeof(numeArtist) + 1];
			strcpy_s(this->artist, sizeof(numeArtist) + 1, numeArtist);
		}
		if (nrPiese > 0)
			this->numarPiese = nrPiese;
		else
			this->numarPiese = 0;
		if (length > 0)
			this->durata = length;
		else
			this->durata = 0;
		this->gen_muzical = gm;
	}

	Vinyl(const Vinyl& vinyl)
	{
		if (this->numeAlbum != NULL)
			delete[] this->numeAlbum;
		this->numeAlbum = new char[strlen(vinyl.numeAlbum) + 1];
		strcpy_s(this->numeAlbum, strlen(vinyl.numeAlbum) + 1, vinyl.numeAlbum);

		if (this->artist != NULL)
			delete[] this->artist;
		this->artist = new char[strlen(vinyl.artist) + 1];
		strcpy_s(this->artist, strlen(vinyl.artist) + 1, vinyl.artist);
		this->numarPiese = vinyl.numarPiese;
		this->durata = vinyl.durata;
		this->gen_muzical = vinyl.gen_muzical;
	}

	Vinyl& operator=(const Vinyl& v)
	{
		if (&v != this)
		{
			if (this->numeAlbum != NULL)
				delete[] this->numeAlbum;
			this->numeAlbum = new char[strlen(v.numeAlbum) + 1];
			strcpy_s(this->numeAlbum, strlen(v.numeAlbum) + 1, v.numeAlbum);

			if (this->artist != NULL)
				delete[] this->artist;
			this->artist = new char[strlen(v.artist) + 1];
			strcpy_s(this->artist, strlen(v.artist) + 1, v.artist);

			this->numarPiese = v.numarPiese;
			this->durata = v.durata;
			this->gen_muzical = v.gen_muzical;
		}
		else
			throw exception("Autoasignare");
		return *this;

	}
	char* getNumeAlbum() { return this->numeAlbum; }
	void setNumeAlbum(char* numeAlbum)
	{ 
		if (strlen(numeAlbum) > 0) 
		{
			if (this->numeAlbum != NULL)
				delete[] this->numeAlbum;
			this->numeAlbum = new char[strlen(numeAlbum) + 1];
			strcpy_s(this->numeAlbum, strlen(numeAlbum) + 1, numeAlbum);
		}
	}

	char* getNumeArtist() { return this->artist; }
	void setNumeArtist(char* numeArtist)
	{
		if (strlen(numeArtist) > 0)
		{
			if (this->artist != NULL)
				delete[] this->artist;
			this->artist = new char[strlen(numeArtist) + 1];
			strcpy_s(this->artist, strlen(numeArtist) + 1, numeArtist);
		}
	}

	unsigned int getNumarPiese() { return this->numarPiese; }
	void setNumarPiese(int nr)
	{
		if (nr > 0)
			this->numarPiese = nr;
	}

	float getDurata() { return this->durata; }
	void setDurata(float durata)
	{
		if (durata > 0)
			this->durata = durata;
	}

	genMuzical getGenMuzical() { return this->gen_muzical; }
	void setGenMuzical(genMuzical gen) { this->gen_muzical = gen; }

	virtual void display(ostream& os) override
	{
		Produs::display(os);
		os << "numele albumului: " << this->numeAlbum << endl;
		os << "numele artistului: " << this->artist << endl;
		os << "numar de piese: " << this->numarPiese << endl;
		os << "durata: " << this->durata << endl;
		os << "gen muzical: " << this->gen_muzical << endl;
	}

	friend ostream& operator<<(ostream& os, Vinyl* vinyl)
	{
		vinyl->display(os);
		return os;
	}


	virtual void read(istream& is) override
	{
		Produs::read(is);
		cout << "Introduceti numele albumului: ";
		char* albumTemp = new char[100];
		is >> ws;
		is.getline(albumTemp, 100);
		if (strlen(albumTemp) > 0)
		{
			if (strlen(this->numeAlbum) > 0)
				delete[] this->numeAlbum;
			this->numeAlbum = new char[strlen(albumTemp) + 1];
			strcpy_s(this->numeAlbum, strlen(albumTemp) + 1, albumTemp);
		}

		cout << "Introduceti numele artistului: ";
		char* artistTemp = new char[100];
		is >> ws;
		is.getline(artistTemp, 100);
		if (strlen(artistTemp) > 0)
		{
			if (strlen(this->artist) > 0)
				delete[] this->artist;
			this->artist = new char[strlen(artistTemp) + 1];
			strcpy_s(this->artist, strlen(artistTemp) + 1, artistTemp);
		}
		cout << "Introduceti numarul de piese: ";
		is >> numarPiese;
		cout << "Introduceti durata: ";
		is >> durata;

		is >> gen_muzical;
	}

	friend istream& operator>>(istream& is, Vinyl* vinyl)
	{
		vinyl->read(is);
		return is;
	}

	~Vinyl()
	{
		delete[] this->numeAlbum;
		delete[] this->artist;
	}


};

class Comanda
{
private:
	char* numeClient;
	char* prenumeClient;
	float valoareComanda; //TODO: De transformat in calculeazaValoareComanda();
	int numarProduse;
public:
	Produs** produse;

	Comanda()
	{
		this->numeClient = new char[10];
		strcpy_s(this->numeClient, 10, "undefined");
		this->prenumeClient = new char[10];
		strcpy_s(this->prenumeClient, 10, "undefined");
		this->valoareComanda = 0;
		this->produse = new Produs * [0];
		this->numarProduse = 0;
	}

	Comanda(const char* numeClient, const char* prenumeClient, float valoareComanda, Produs** produse, int numarProduse)
	{
		if (strlen(numeClient) > 0)
		{
			if (this->numeClient != NULL)
				delete[] this->numeClient;
			this->numeClient = new char[strlen(numeClient) + 1];
			strcpy_s(this->numeClient, strlen(numeClient) + 1, numeClient);
		}
		else
		{
			if (this->numeClient != NULL)
				delete[] this->numeClient;
			this->numeClient = new char[10];
			strcpy_s(this->numeClient, 10, "undefined");
		}

		if (strlen(prenumeClient) > 0)
		{
			if (this->prenumeClient != NULL)
				delete[] this->prenumeClient;
			this->prenumeClient = new char[strlen(prenumeClient)+1];
			strcpy_s(this->prenumeClient, strlen(prenumeClient) + 1, prenumeClient);
		}
		else
		{
			if (this->prenumeClient != NULL)
				delete[] this->prenumeClient;
			this->prenumeClient = new char[10];
			strcpy_s(this->prenumeClient, 10, "undefined");
		}
		if (valoareComanda > 0)
			this->valoareComanda = valoareComanda;
		else
			this->valoareComanda = 0;
		if (numarProduse > 0)
			this->numarProduse = numarProduse;
		else
		{
			this->numarProduse = 0;
			if (this->produse != NULL)
				delete[] produse;
			this->produse = new Produs * [0];
		}
			
		for (int i = 0; i < this->numarProduse; i++)
		{
			this->produse[i] = produse[i];
		}
	}

	Comanda(const Comanda& comanda)
	{
		if (this->numeClient != NULL)
			delete[] this->numeClient;
		this->numeClient = new char[strlen(comanda.numeClient) + 1];
		strcpy_s(this->numeClient, strlen(comanda.numeClient) + 1, comanda.numeClient);

		if (this->prenumeClient != NULL)
			delete[] this->prenumeClient;
		this->prenumeClient = new char[strlen(comanda.prenumeClient) + 1];
		strcpy_s(this->prenumeClient, strlen(comanda.prenumeClient) + 1, comanda.prenumeClient);
		this->valoareComanda = comanda.valoareComanda;
		this->numarProduse = comanda.numarProduse;
		for (int i = 0; i < this->numarProduse; i++)
			this->produse[i] = comanda.produse[i];
	}

	Comanda& operator=(const Comanda& co)
	{
		if (&co != this)
		{
			if (this->numeClient != NULL)
				delete[] this->numeClient;
			this->numeClient = new char[strlen(co.numeClient) + 1];
			strcpy_s(this->numeClient, strlen(co.numeClient) + 1, co.numeClient);

			if (this->prenumeClient != NULL)
				delete[] this->prenumeClient;
			this->prenumeClient = new char[strlen(co.prenumeClient) + 1];
			strcpy_s(this->prenumeClient, strlen(co.prenumeClient) + 1, co.prenumeClient);
			this->valoareComanda = co.valoareComanda;
			this->numarProduse = co.numarProduse;
			for (int i = 0; i < this->numarProduse; i++)
				this->produse[i] = co.produse[i];

		}
		else {
			throw exception("Autoasignare");

		}
		return *this;
	}
	char* getNumeClient() { return this->numeClient; }
	void setNumeClient(const char* numeClient) 
	{
		if (strlen(numeClient) > 0)
		{
			if (this->numeClient != NULL)
				delete[] this->numeClient;
			this->numeClient = new char[strlen(numeClient) + 1];
			strcpy_s(this->numeClient, strlen(numeClient) + 1, numeClient);
		}
	}

	char* getPrenumeClient() { return this->prenumeClient; }
	void setPrenumeClient(const char* prenumeClient)
	{
		if (strlen(prenumeClient) > 0)
		{
			if (this->prenumeClient != NULL)
				delete[] this->prenumeClient;
			this->prenumeClient = new char[strlen(prenumeClient) + 1];
			strcpy_s(this->prenumeClient, strlen(prenumeClient) + 1, prenumeClient);
		}
	}

	float getValoareComanda() { return this->valoareComanda; } //momentan ramane asa, desi am banuiala ca valoareComanda o sa devina calculeazaValoareComanda();
	void setValoareComanda(float valoareComanda) {
		this->valoareComanda = valoareComanda; //Nu mai stau sa fac validarea
	}

	int getNumarProduse() { return this->numarProduse; }
	// setNumarProduse nu are sens, caci nu vreau ca utilizatorul sa poata sa modifice numarul de produse, caci va strica vectorul.
	
	//TODO Operator<< Operator>> 
	
	void operator+=(Produs* produs)
	{
		Produs** temp = new Produs * [this->numarProduse+1];
		for (int i = 0; i < this->numarProduse; i++)
		{
			temp[i] = this->produse[i];
		}
		temp[this->numarProduse] = produs;
		delete[] this->produse;
		this->produse = temp;
		this->numarProduse++;
	}

	void operator-=(Produs* produs)
	{
		Produs** temp = new Produs * [this->numarProduse-1];
		int deSters = produs->getIDProdus();
		int indexTemp = 0;
		for (int i = 0; i < this->numarProduse; i++)
		{
			if (deSters == this->produse[i]->getIDProdus())
				continue;
			else {
				temp[indexTemp] = this->produse[i];
				indexTemp++;
			}
				
		}
		delete[] this->produse;
		this->produse = temp;
		this->numarProduse--;
	}

	Produs* operator[](int index)
	{
		if (index >= this->numarProduse || index < 0)
			throw out_of_range("Index invalid");
		return this->produse[index];
	}

	friend ostream& operator<<(ostream& os, const Comanda& c)
	{
		os << "nume client: " << c.numeClient << endl;
		os << "prenume client: " << c.prenumeClient << endl;
		os << "valoare comanda: " << c.valoareComanda << endl;
		os << "numar produse: " << c.numarProduse << endl;
		os << "produse: " << endl;
		for (int i = 0; i < c.numarProduse; i++)
		{
			cout << i + 1 << ". " << c.produse[i]->getIDProdus() << endl;
		}
		return os;
	}

	friend istream& operator>>(istream& is, Comanda& c)
	{
		cout << "Introduceti numele clientului: ";
		cin >> c.numeClient;
		cout << "Introduceti prenumele clientului:";
		cin >> c.prenumeClient;
		cout << "Introduceti valoarea comenzii";
		cin >> c.valoareComanda;
		//Introducem categoria. Facem Carte::read() sau Vinyl::read();
	}

	~Comanda()
	{
		delete[] this->numeClient;
		delete[] this->prenumeClient;
		delete[] this->produse;
	}


};

int main()
{
	try
	{
		Carte* c = new Carte(1, 1, 10, Status::Activ, "Baltagul", "Mihail Sadoveanu", "Facla", 131, 1973, genLiterar::Proza);
		Vinyl* v = new Vinyl(2, 1, 25, Status::Activ, "Mugur de fluier", "Phoenix", 7, 131, genMuzical::Rock);
		
		Carte* c1 = c;
		Vinyl* v1 = v;

		cout << c1 << endl;
		cout << endl << v1 << endl; 

		Produs* p1 = new Produs();
		Produs* p2 = p1;
//		cout << p2 << endl << endl;

		Carte* c3 = c1;
//		cout << c3;

		Vinyl* v3 = v1;
		cout << v3;

		Comanda co;
		co.setNumeClient("Oprea");
		co.setPrenumeClient("Ovidiu-Cristian");
		co.setValoareComanda(1060);

		//cout << co[3];

		Comanda co2;
		co2 = co2;

		Produs* pEx = new Produs();
		pEx = pEx;


	}
	catch (out_of_range &ex)
	{
		cout << ex.what() << endl;
	}
	catch (exception &ex) 
	{
		cout << ex.what() << endl;
	}
	

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