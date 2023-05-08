// Projekt 7.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <cmath>
#include<stdexcept>
#include <string>
using namespace std;
class Less_Than_Zero_E : public runtime_error
{
public:
	explicit Less_Than_Zero_E(const std::string& message)
		: std::runtime_error(message) {}

		
};

class Logarithm {
public:
	Logarithm(double base, double number) {
		base_ = base;
		number_ = number;
	}
	double Calculate() const {
		

		if (base_ < 0)
		{
			throw Less_Than_Zero_E("The base is less than 0");
		}
		if (base_ == 0)
		{
			throw Less_Than_Zero_E("the base is equal to 0");
		}
		if (number_ < 0)
		{
			throw Less_Than_Zero_E("The number is less than 0");
		}
		if (number_ == 0)
		{
			throw Less_Than_Zero_E("the number is equal to 0");
		}
		
		return std::log(number_) / std::log(base_);
	}
private:
	double base_;
	double number_;
};
int main()
{
	double base,n;
	cout << "set base\n";
	cin >> base;
	cout << "give number\n";
	cin >> n;
	Logarithm object(base, n);
	try { object.Calculate(); }
	catch(const Less_Than_Zero_E & e) {
		std::cerr << " " << e.what() << std::endl;
	}

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
