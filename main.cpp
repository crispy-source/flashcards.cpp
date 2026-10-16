#include <bits/stdc++.h>
#include <map>
using namespace std;
class Flashcard
{
public:
    string question;
    string answer;

    Flashcard(string q, string a)
    {
        question = q;
        answer = a;
    }
};

vector<Flashcard> colectie;

void adaugaCard()
{
    string intrebare, raspuns;
    cout << "Introduceti intrebarea " << endl;
    cin.clear();
    cin.ignore();

    getline(cin, intrebare);

    cout << "Introduceti raspunsul " << endl;
    getline(cin, raspuns);

    colectie.push_back(Flashcard(intrebare, raspuns));
    cout << "Flashcard adaugat! " << endl;
}

void afisareFlashcarduri()
{
    if (colectie.empty())
        cout << "Nu ai flashcarduri! " << endl;

    else
    {
        for (int i = 0; i < colectie.size(); i++)

            cout << "Q: " << colectie[i].question << "~~~~~~" << "A " << colectie[i].answer << endl;
    }
}


void AlegeRandom()
{
    if (colectie.empty())
        cout << "Nu ai flashcarduri! " << endl;
    else
    {
        int random_index = rand() % colectie.size();
        cout << "Intrebare: " << colectie[random_index].question << endl;

        cout << "Afisezi raspunsul? Apasa enter " << endl;
        cin.ignore();
        cin.get();

        cout << "Raspuns: " << colectie[random_index].answer << endl;
    }
}

void eliminaCard()
{
    if (colectie.empty())
        cout << "Nu ai flashcarduri! " << endl;

    else
    {   
        int nr_sters;
        cout << "Alege ce card vrei sa elimini ";

        for (int i = 0; i < colectie.size(); i++)
            cout << i << '.' << colectie[i].question << endl;

        cin >> nr_sters;

        if (nr_sters <= 0 || nr_sters > colectie.size())
            cout << "Alege o varianta valida! " << endl;

        else
        {
            colectie.erase(colectie.begin() + nr_sters - 1);
        }
    }
}

void iesire()
{
    cout << "Hai noroc~~ ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    srand(time(NULL));

    map<int, function<void()>> meniu; // prin cheia de tip int accesez functiile de tip void

    // umplem harta cu comenzi...fara() la functii
    meniu[1] = adaugaCard;
    meniu[2] = afisareFlashcarduri;
    meniu[3] = AlegeRandom;
    meniu[4] = eliminaCard;
    meniu[5] = iesire;

    int choice = -1;

    while (choice != 5)
    {
        cout << "-------MENIU CU MAP-------" << endl;
        cout << "1. Adauga flashcard" << endl;
        cout << "2. Afiseaza toate" << endl;
        cout << "3. Alege random" << endl;
        cout << "4. Sterge un card" << endl;
        cout << "5. Iesire" << endl;
        cout << "Alege o optiune: ";
        cin >> choice;

        if (meniu.count(choice)) //.count() returnează 1 dacă există
            meniu[choice]();

        else
            cout << "Introdu o optiune valida! " << endl;
        

    }
    return 0;
}
