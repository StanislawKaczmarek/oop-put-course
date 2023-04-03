// Lekcja ktorastam.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

class Figure {
private :
	float height=0;
	float length=0;
	string figure="Square";
public :
	Figure();
	Figure(float value)
	{
		height = value;
	};
	Figure(float value1, float value2, string type)
	{
		height = value1;
		length = value2;
		figure = type;
	};
	~Figure()
	{
		
	};
	float Area()
	{
		if (figure == "Square")
			return height * height;
		if (figure == "Rectangle" || figure == "Parallelogram" || figure == "Rhombus")
			return height * length;
		if (figure == "Triangle")
			return (height * length) / 2;
		if (figure != "Rectangle" || figure != "Parallelogram" || figure != "Rhombus" || figure != "Triangle" || figure == "Square")
		{
			cout << "Sorry, I don't know the formula\n";
			return 0;
		}
	};
};

int main()
{
	float value1=0, value2 = 0;
	string name="";
	cout << "enter the type of the figure ( first letter is a Capital letter \n)";
	cin >> name;
	
	if (name == "Square")
	{
		std::cout << "Enter the height of the figure \n";
		std::cin >> value1;
		Figure Square(value1);
		std::cout << "the area of your figure is : " << Square.Area() << "\n";
		Square.~Figure();
		return 0;
	}
	if (name != "Square");
	{
		std::cout << "Enter the height of the figure \n";
		std::cin >> value1;
		std::cout << "Now Enter the length of the figure\n";
		std::cin >> value2;
		Figure Rectangle(value1, value2, name);
		std::cout << "the area of your figure is : " << Rectangle.Area() << "\n";
		Rectangle.~Figure();
		return 0;
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
