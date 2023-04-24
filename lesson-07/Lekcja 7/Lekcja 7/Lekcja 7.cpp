// Lekcja 7.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <string>
#include<sstream>
#include<memory>
#include <cassert>
using namespace std;

class Sequence
{
	public:
	virtual int Length()=0;
};

class FakeSequence :public Sequence
{
	int Length()
	{
		return 100;
	}
};
class Gene
{
private: 
	string name;
	shared_ptr<Sequence> sequence_;
public :
	Gene(string name, shared_ptr<Sequence> sequence) :
		name(name), sequence_(sequence) {};
	string JSON()
	{
		stringstream ss;
		ss << "{";
		ss <<"\"name\":\""<<name<<"\",";
		ss << "\"length\":" << sequence_->Length() << "";
		ss << "}";
		return ss.str();
	}
};
int main()
{
	shared_ptr<Sequence> fakeSequence = make_shared<FakeSequence>();
	Gene gene("BALF5", fakeSequence);
		cout << gene.JSON();
		assert(fakeSequence->Length() == 100);
		return 0;


}
// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
