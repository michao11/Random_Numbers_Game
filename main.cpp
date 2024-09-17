#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

class RandomGame {
private:
    int* tab;
    int difficulty;
    vector<int> usedNumbers;

public:
    RandomGame() {
        difficulty = 5;
        tab = new int[difficulty];
        Reset();
    }

    RandomGame(int difficulty) {
        this->difficulty = difficulty;
        tab = new int[difficulty];
        Reset();
    }

    ~RandomGame() {
        delete[] tab;
    }

    void Reset() {
        for(int i = 0; i < difficulty; i++) {
            tab[i] = -1;
        }
    }

    void Display() {
        for(int i = 0; i < difficulty; i++) {
            cout << i << ": ";
            if(tab[i] == -1) {
                cout << "" << endl;
            }
            else {
                cout << tab[i] << endl;
            }
        }
    }

    bool isInUsedNumbers(int number) {
        for(int x : usedNumbers) {
            if(x == number) {
                return true;
            }
        }
        return false;
    }

    void Play() {
        while (usedNumbers.size() < difficulty) {
            int random_number = rand() % 101;
            while (isInUsedNumbers(random_number)) {
                random_number = rand() % 101;
            }

            usedNumbers.push_back(random_number);
            Display();
            cout << "Wylosowana liczba to: " << random_number << endl;
            cout << "Podaj index tablicy (0 - " << difficulty - 1 << "): ";
            int index = 0;
            cin >> index;

            if (index < 0 || index >= difficulty || tab[index] != -1) {
                cout << "Podano niepoprawny index. Koniec gry" << endl;
                return;
            }

            else if (index > 0 && tab[index - 1] != -1 && tab[index - 1] > random_number) {
                cout << "Podano niepoprawny index. Koniec gry" << endl;
                return;
            }

            else if (index < difficulty - 1 && tab[index + 1] != -1 && tab[index + 1] < random_number) {
                cout << "Podano niepoprawny index. Koniec gry" << endl;
                return;
            }

            tab[index] = random_number;

            //system("clear");
            //system("cls");
        }

        Display();
        cout << "Poprawnie wpisano wszystkie liczby. Wygrales" << endl;
    }
};

int main()
{
    srand(time(NULL));
    RandomGame game(5);
    game.Play();
}
