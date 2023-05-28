// Dice roller.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <time.h>
#include <cstdlib>
#include <string>
#include <cstdio>
using namespace std;
/*Plan : Make a couple of modes - 1 which just adds all of the rolls,
another one which displays the results of each subsequent roll and final one which supports the Neuroshima system*/
int repeat = 1; // Global variable controlling when to end the program.

class IDie // Interface for the Die.
{
    int sides = 0;
public:
    virtual int Roll() = 0;
    virtual int Roll_Plus(int plus) = 0;//used in 2d20 + plus

};
class  Die :public IDie //Normal die - just rolls a die no additional actions (like adding).
{
    int sides;

public:
    int Roll()
    {
        int roll;
        roll = rand();
        roll = (roll % sides) + 1;
        cout << roll << " ";
        return roll;
    }
    int Roll_Plus(int plus)
    {
        int roll;
        roll = rand();
        roll = (roll % sides) + 1 + plus;
        cout << roll << " ";
        return roll;
    }
    Die()
    {

    }
    Die(int input)
    {
        sides = input;

    }
};
class IMenu // Interface of Menu It will be used to switch between different modes.
{
private:
    int mode; //used for switching between the type of dicerollers
public:
    virtual void Help() = 0;
    virtual void Process(char command, int n_rolled, int sides) = 0; // takes the data pieces and decides which operation to carry out
};
class Menu

{
private:
    int n_rolled = 0;
    int sides = 0;
    string bufor;//for converting string to int
public:

    virtual void Help()//Display a list of available operations
    {
        cout << "This program allows you to roll dice.\n";
        cout << "To roll, first choose a command from the list below, then type the number of dice you want to throw, then type the number of sides each dice has.\n";
        cout << "c - close program\n";
        cout << "r - roll a die \n";
        cout << "a - roll &add - the program will request you to input an additional number. This number will be added to every die.\n";
        cout << "? Display this text again \n";
    }
    void Process(char command)
    {
        int plus=0,n_rolled=0,sides = 0;

        
            
            switch (command)
            {
                case 'r':
                {
                cout << "Input number of sides to roll\n";
                cin >> bufor;//then it takes numbers of dice and their sides
                sscanf_s(&bufor[0], "%d", &n_rolled);
                if (n_rolled == 0)
                {
                    cout << "cannot roll this number of dice\n";
                }
                cout << "Rolling " << n_rolled << "d";
                cin >> bufor;
                sscanf_s(&bufor[0], "%d", &sides);
                if (sides == 0)
                {
                    cout << "\n";
                    cout << "there doesn't exist a die with this many sides\n";
                    return;
                }

                Die die(sides);

                cout << "\n";

                for (int i = 0; i < n_rolled; i++)
                {
                    die.Roll();

                }
                die.~Die();
                break;
                }
            case 'a':
            {    
                cout << "Input number of sides to roll\n";
                cin >> bufor;//then it takes numbers of dice and their sides
                sscanf_s(&bufor[0], "%d", &n_rolled);
                if (n_rolled == 0)
                {
                    cout << "cannot roll this number of dice\n";
                    return;
                }
                cout << "Rolling " << n_rolled << "d";
                cin >> bufor;
                sscanf_s(&bufor[0], "%d", &sides);
                if (sides == 0)
                {
                    cout << "\n";
                    cout << "canot roll this dice\n";
                    return;
                }


                Die die(sides); cout << "+ \n";
            cin >> plus;
            for (int i = 0; i < n_rolled; i++)
            {

                die.Roll_Plus(plus);
            }
            die.~Die();
            return;
            }
            
            case '?':
            {
                Help();
                
                return;
            }
           
            case 'c':
            {
                repeat = 0;
                return;
            }
            default:
                cout <<"Unrecognized command To display a list of commands press ?\n"; 
            }
     
        return;
    }
};




int main()
{
   
    char command = '?';
    char bufor[100000];
    srand((unsigned)time(NULL));
    Menu menu;
    menu.Help();
    while (repeat == 1)
    {

        sscanf_s(&bufor[0], "%c", &command);
        cin >> &bufor[0];
        command = bufor[0];

        menu.Process(command);
        cout << "\n";

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
