// Decorators.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <algorithm>
#include <cctype>
#include <string>
#include<vector>
int i=0;
using namespace std;
class Integer_Sequence
{
public :
	virtual vector<int> Numbers()=0;
};
class Vector_Sequence : public Integer_Sequence
{
private:
	vector<int> data;
public :
	Vector_Sequence();
	Vector_Sequence(vector <int>input)
	{
		data = input;
	}
	vector<int>Numbers()override
	{
		return data;
	}
};
class Positive_Sequence:public Integer_Sequence
{
private:
	Integer_Sequence* data;
public:
	Positive_Sequence(Integer_Sequence* input)
	{
		data = input;
	}
	vector<int>Numbers()override
	{
		vector<int>tmp = data->Numbers();
		for(int i=0;i<tmp.size;i++)
		{
			if (tmp[i] < 0)
			{
				tmp.erase(tmp[i], tmp[i]);
			}
		}
		return tmp;
	}
};

class Even_Sequence :public Integer_Sequence
{
private:
	Integer_Sequence* data;
public:
	Even_Sequence(Integer_Sequence* input)
	{
		data = input;
	}
	vector<int>Numbers()override
	{
		vector<int>tmp = data->Numbers();
		for (int i = 0; i < tmp.size; i++)
		{
			if (tmp[i] %2 !=0)
			{
				tmp.erase(tmp[i], tmp[i]);
			}
		}
		return tmp;
	}
};

class Sorted_Sequence :public Integer_Sequence
{
private:
	Integer_Sequence* data;
public:
	Sorted_Sequence(Integer_Sequence* input)
	{
		data = input;
	}
	vector<int>Numbers()override
	{
		vector<int>tmp = data->Numbers();
		sort(tmp.begin, tmp.end);
		return tmp;
	}
};

int main()
{
	vector<int>sequence;
	for (int i = 0; i < 10; i++)
		cin >> sequence.push_back;
	Vector_Sequence vector(sequence);
	Integer_Sequence* ptr = vector;
	
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
