#include <iostream>
using namespace std;

void queue() {
    struct Queue {
        string tab[10];
        string *first = &tab[0];
        string *last = &tab[9];
    };
    struct Queue queue;
    cout << "Podaj jedna z instrukcji:\n"
         << "d - aby dodac napis do kolejki\n"
         << "u - aby usunac napis z kolejki\n"
         << "w - aby wyswietlic zawartosc kolejki\n"
         << "x - aby zakonczyc\n";
    char instrukcja; //info od uzytkownika
    bool loop = true; //czy zapetlac
    int elements = 0; //ilosc elementow
    int size=10;
    while (loop) {
        cin >> instrukcja;
        switch (instrukcja) {
            case 'd': //dodawanie
                if (elements == size) {
                    cout << "kolejka jest pelna!\n";
                } else {
                    string str;
                    cout << "podaj napis\n";
                    cin >> str;
                    for (int i = elements - 1; i >= 0; i--) {
                        queue.tab[i + 1] = queue.tab[i];
                    }
                    queue.tab[0] = str;
                    elements++;
                    cout << "dodano!\n";
                }
                break;
            case 'u': //usuwanie
                if (elements == 0) {
                    cout << "kolejka jest pusta!\n";
                }
                else{
                    elements--;
                    cout << "usunieto: " << queue.tab[elements] << "!\n";
                    queue.tab[elements]= "";
                }
                break;
            case 'w': //wyswietlanie
                if (elements == 0) {
                    cout << "kolejka jest pusta!\n";
                }
                else
                {
                    cout << "aktualna kolejka:\n";
                    for(int i = 0; i < elements; i++) {
                        cout << queue.tab[i] << " ";
                    }
                    cout <<"\n";
                }
                break;
            case 'x': //wyjscie
                loop = false;
                break;
            default:
//nieznana instrukcja
                cout << "Podaj jedna z instrukcji:\n"
                     << "d- aby dodac napis do kolejki\n"
                     << "u- aby usunac napis z kolejki\n"
                     << "w- aby wyswietlic zawartosc kolejki\n"
                     << "x- aby zakonczyc\n";
                break;

        }
    }
}

int main(){
    queue();
}
