#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <random>
#include <string>
#include <utility>
#include <vector>

class Flashcard {
public:
    std::string question;
    std::string answer;
    Flashcard(std::string q, std::string a)
        : question(std::move(q)), answer(std::move(a)) {}
};

std::vector<Flashcard> colectie;

bool citesteNumar(int& valoare) {
    if (!(std::cin >> valoare)) {
        if (std::cin.eof()) return false;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Introdu un numar valid!\n";
        return false;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return true;
}

void adaugaCard() {
    std::string intrebare, raspuns;
    std::cout << "Introduceti intrebarea: " << std::flush;
    if (!std::getline(std::cin, intrebare)) return;
    std::cout << "Introduceti raspunsul: " << std::flush;
    if (!std::getline(std::cin, raspuns)) return;
    colectie.emplace_back(std::move(intrebare), std::move(raspuns));
    std::cout << "Flashcard adaugat!\n";
}

void afisareFlashcarduri() {
    if (colectie.empty()) { std::cout << "Nu ai flashcarduri!\n"; return; }
    for (std::size_t i = 0; i < colectie.size(); ++i)
        std::cout << i + 1 << ". Q: " << colectie[i].question
                  << " | A: " << colectie[i].answer << '\n';
}

void alegeRandom() {
    if (colectie.empty()) { std::cout << "Nu ai flashcarduri!\n"; return; }
    static std::mt19937 generator(std::random_device{}());
    std::uniform_int_distribution<std::size_t> distributie(0, colectie.size() - 1);
    const auto& card = colectie[distributie(generator)];
    std::cout << "Intrebare: " << card.question << '\n'
              << "Afisezi raspunsul? Apasa Enter.\n" << std::flush;
    std::string confirmare;
    if (!std::getline(std::cin, confirmare)) return;
    std::cout << "Raspuns: " << card.answer << '\n';
}

void eliminaCard() {
    if (colectie.empty()) { std::cout << "Nu ai flashcarduri!\n"; return; }
    for (std::size_t i = 0; i < colectie.size(); ++i)
        std::cout << i + 1 << ". " << colectie[i].question << '\n';
    std::cout << "Alege numarul cardului de eliminat: " << std::flush;
    int numar;
    if (!citesteNumar(numar)) return;
    if (numar < 1 || static_cast<std::size_t>(numar) > colectie.size()) {
        std::cout << "Alege o varianta valida!\n";
        return;
    }
    colectie.erase(colectie.begin() + numar - 1);
    std::cout << "Flashcard sters!\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    const std::map<int, std::function<void()>> meniu = {
        {1, adaugaCard}, {2, afisareFlashcarduri}, {3, alegeRandom},
        {4, eliminaCard}, {5, [] { std::cout << "La revedere!\n"; }}
    };
    while (true) {
        std::cout << "\n1. Adauga flashcard\n2. Afiseaza toate\n3. Alege random\n"
                     "4. Sterge un card\n5. Iesire\nAlege o optiune: " << std::flush;
        int optiune;
        if (!citesteNumar(optiune)) {
            if (std::cin.eof()) break;
            continue;
        }
        const auto actiune = meniu.find(optiune);
        if (actiune == meniu.end()) std::cout << "Introdu o optiune valida!\n";
        else actiune->second();
        if (optiune == 5) break;
    }
}
