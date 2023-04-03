// Lekcja 5.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
using namespace std;
/*
float Addition(float a, float b)
	{
		return a + b;
	}
	float Substraction(float a, float b)
	{
		return a - b;
	}
	float Division(float a, float b)
	{
		return a / b;
	}
	float Multiplication(float a, float b)
	{
		return a * b;
	}

	void Query(float a, float b, int query)
	{
		switch (query)
		{

			case 1:
			{
				cout<<Addition(a, b)<<endl;

				break;
			}
			case 2:
			{
				cout<<Substraction(a, b)<<endl;
				break;
			}
			case 3:
			{
				cout<<Multiplication(a, b)<<endl;
				break;
			}
			case 4:
			{
				cout<<Division(a, b)<<endl;
				break;
			}
			case 5:
			{
				cout << "MENU\n";
				cout << "Close\n";
				cout << "1. + \n";
				cout << "2. - \n";
				cout << "3. * \n";
				cout << "4. : \n";
				cout << "5. MENU \n";
			}
			default :
			{
				cout << "Incorrect option, please input again\n";
			}

		}
		return;
	}
*/

int breaker = 0;
class Teacher
{
public :
	virtual float Addition(float a, float b) = 0;
	
	
	
};
class Physicist : public Teacher
{

private :
	int Kelvin= -273;
public:
	float Addition(float a, float b)override
	{
		a = a + Kelvin;
		b = b + Kelvin;
		cout << "Liczby przeliczone na Kelvin to:" << endl;
		cout << a << endl;
		cout << b << endl;
		return a ;
	}

};
class Mathematician :public Teacher {
	public:
		Mathematician() {};
		~Mathematician(){};
		float Addition(float a, float b)override
	{
		return a + b;
	}
		float Substraction(float a, float b)
		{
			return a - b;
		}
		float Division(float a, float b)
		{
			return a / b;
		}
		float Multiplication(float a, float b)
		{
			return a * b;
		}

		void Query(float a, float b, int query)
		{
			switch (query)
			{

			case 1:
			{
				cout << Addition(a, b) << endl;

				break;
			}
			case 2:
			{
				cout << Substraction(a, b) << endl;
				break;
			}
			case 3:
			{
				cout << Multiplication(a, b) << endl;
				break;
			}
			case 4:
			{
				cout << Division(a, b) << endl;
				break;
			}
			case 5:
			{
				cout << "MENU :\n";
				cout << "0. Close\n";
				cout << "1. + \n";
				cout << "2. - \n";
				cout << "3. * \n";
				cout << "4. : \n";
				cout << "5. MENU \n";
			}
			default:
			{
				cout << "Incorrect option, please input again\n";
			}

			}
			return;
		}

};
int main()
{
	int choice=0;
	float a = 0, b = 0;
	Mathematician Imbierowicz;
	Physicist Buchwald;
	cout << "MENU\n";
	cout << "Close\n";
	cout << "1. + \n";
	cout << "2. - \n";
	cout << "3. * \n";
	cout << "4. : \n";
	cout << "5. MENU : \n";
	cout << "6.Kelvin\n";


	while (1)
		{
			cout << "Choose a mathematical operation\n";
			cin >> choice;
			if (choice == 0)
				return 0;
			if (choice  <4 && choice > 0)
			{
				cout << "Input first number\n";
				cin >> a;
				cout << "Input second number\n";
				cin >> b;
			}
			if (choice == 6)
			{
				cout << "Input first number\n";
				cin >> a;
				cout << "Input second number\n";
				cin >> b;
				
				cout<<Buchwald.Addition(a, b);
				return 0;
			}
			Imbierowicz.Query(a, b, choice);
		}
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
