# Platformer Game

Dwuwymiarowa gra platformowa napisana w **C++20** z użyciem biblioteki **SFML 2.6.0**. Projekt zaliczeniowy na studia (PJATK).

Gracz przechodzi przez kolejne mapy, strzela do przeciwników, zbiera klucze i wchodzi do portalu prowadzącego do następnego poziomu.

## Funkcje

- 3 mapy z platformami, przeciwnikami, kluczem i portalem do następnego poziomu
- 3 typy przeciwników:
  - `WalkingEnemy`: chodzi po platformach,
  - `MirrorEnemy`,
  - `GhostEnemy`: leci w stronę gracza i przenika przez ściany (50 HP)
- Strzelanie w lewo i w prawo z ograniczonym magazynkiem i przeładowaniem
- Kolizje gracza, pocisków i przeciwników z platformami
- Zadawanie obrażeń przy kontakcie z przeciwnikiem (20 HP raz na sekundę)
- Ekran końca gry po utracie całego zdrowia

## Sterowanie

| Klawisz | Akcja |
|---|---|
| `A` / `D` | ruch w lewo / w prawo |
| `Spacja` | skok |
| `←` / `→` | strzał w lewo / w prawo |
| `R` | przeładowanie (gdy magazynek jest pełny) |

## Statystyki gracza

| Parametr | Wartość |
|---|---|
| Zdrowie | 100 |
| Obrażenia pocisku | 20 |
| Pojemność magazynka | 4 |

## Wymagania

- Kompilator z obsługą C++20
- CMake ≥ 3.26
- Git (CMake pobiera SFML 2.6.0 i fmt 10.0.0 automatycznie przez `FetchContent`)
- Działa na macOS i Windows

## Budowanie i uruchomienie

```bash
git clone https://github.com/a1fut/platformer-game.git
cd platformer-game
cmake -B build
cmake --build build
./build/SFMLtest
```

Na Windowsie plik wykonywalny znajdziesz w `build\Debug\` lub `build\Release\` (zależnie od generatora), jako `SFMLtest.exe`.

## Struktura projektu

```
.
├── main.cpp          # punkt wejścia
├── CMakeLists.txt
├── Game/             # pętla gry, obsługa zdarzeń, renderowanie
├── Player/           # gracz, pociski, ładowanie tekstur
├── Maps/             # mapy, przeciwnicy, klucz, portal, przedmioty
│   ├── MapOne/
│   ├── MapTwo/
│   ├── MapThree/
│   └── Enemies/
└── Sprites/          # grafiki
```

## Stan projektu

Nie wszystko udało się dokończyć w terminie. Niezaimplementowane lub szczątkowe elementy:

- menu główne (kod jest zakomentowany),
- licznik zdrowia na ekranie,
- przedmioty (`hpUp`, `highJump`, `ammoUp`) i pokój z przedmiotami (`itemRoom`): przygotowane tekstury i klasy, ale bez logiki podnoszenia.

## Autor

Maciej Alfut
