# One Card WAR (Vector Version)

## Overview
This project builds on the simple One Card WAR game by using a `Deck` class that stores `Card` objects inside a **`std::vector`** rather than an array.  
Two players draw one card each per round; the higher rank wins, ties are possible.  
The game continues for a user-selected number of rounds or until the deck is empty.

If the requested number of games exceeds the number of remaining cards, `Deck::deal()` **throws** an exception, which is **caught** in `main()` and reported.  

Everything resides in a single file `war.cpp`.

---

## Requirements
- **Classes**
  - `class Card`  
    - `Card(char rank, char suit)`  
    - `void display()` → prints cards like `AC`, `10S`, `KD`  
    - `int compare(Card)` → returns 1 (win), 0 (tie), -1 (lose)
  - `class Deck`  
    - `Deck()` → builds 52 cards into a `vector<Card>`  
    - `Card deal()` → returns top card or throws if empty  
    - `void display()` → prints deck 13 cards per line  
    - `void shuffle()` → randomizes order (`rand()` / `srand(time(0))`)  
    - `bool isEmpty()` → true if no cards remain
- **Struct**
  ```cpp
  struct Player {
      std::string name;
      int win, lose, tie;
  };
