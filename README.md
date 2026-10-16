# Flashcards în C++

Proiect individual în dezvoltare: o aplicație de consolă pentru crearea și recapitularea întrebărilor și răspunsurilor prin sistemul flashcard. Este un prototip pentru un viitor site de autoevaluare; în acest stadiu nu există interfață web sau server HTTP.

## Ce funcționează

- Adăugarea întrebărilor și răspunsurilor, inclusiv a textelor cu spații.
- Listarea cardurilor și selectarea aleatorie a unei întrebări.
- Afișarea răspunsului după confirmarea utilizatorului.
- Ștergerea cardurilor din colecție.

Cardurile sunt păstrate doar în memorie și se pierd la închiderea programului. Nu există încă evaluare automată a răspunsurilor sau algoritm de repetiție spațiată.

## Tehnologii și concepte

C++, biblioteca standard, o clasă `Flashcard`, `std::vector`, `std::map` și `std::function` pentru asocierea comenzilor cu funcții. Selecția aleatorie folosește `rand()` și `srand()`.

Proiectul este configurat pentru compilare în modul C++20.

## Rulare pe Linux

Se folosește GCC/g++ cu libstdc++, deoarece sursa originală include antetul specific `<bits/stdc++.h>`.

```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic main.cpp -o flashcards
./flashcards
```

## De ce îl construiesc și ce exersez

Vreau să pornesc de la logica unui instrument simplu de autoevaluare și să o extind treptat către o aplicație web. Prin acest proiect exersez modelarea datelor prin clase, containerele STL, gestionarea intrărilor și organizarea unui meniu cu funcții. Aceste concepte îmi sunt utile pentru structurarea unor aplicații mai mari și pentru tratarea cazurilor de eroare.

## Următorii pași

- Salvarea și încărcarea cardurilor din fișier.
- Separarea logicii cardurilor de interfața de consolă.
- Teste pentru operațiile asupra colecției.
- Ulterior, un API și o interfață web pentru autoevaluare.

## Structura proiectului

- `main.cpp`: implementarea aplicației.
- `CMakeLists.txt`: configurare opțională pentru compilarea cu CMake.
- `.gitignore`: exclude executabilul și fișierele de compilare.

Alternativ, cu CMake instalat:

```bash
cmake -S . -B build
cmake --build build
./build/flashcards
```

## Stadiul implementării

`main.cpp` păstrează codul original al autorului. Proiectul este înca in dezvoltare.
