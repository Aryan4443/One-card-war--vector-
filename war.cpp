#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// ---------------- Card Class ----------------
class Card
{
private:
    char rank;
    char suit;

public:
    Card(char r, char s)
    {
        rank = r;
        suit = s;
    }

    void display()
    {
        cout << rank << suit;
    }

    int getValue()
    {
        string ranks = "A23456789TJQK";
        for (int i = 0; i < (int)ranks.size(); i++)
        {
            if (ranks[i] == rank)
            {
                return i + 1;
            }
        }
        return 0;
    }

    int compare(Card other)
    {
        if (this->getValue() > other.getValue())
            return 1;
        if (this->getValue() < other.getValue())
            return -1;
        return 0;
    }
};

// ---------------- Deck Class ----------------
class Deck
{
private:
    vector<Card> cards;

public:
    Deck()
    {
        char suits[4] = {'C', 'S', 'D', 'H'};
        string ranks = "A23456789TJQK";
        for (int s = 0; s < 4; s++)
        {
            for (int r = 0; r < (int)ranks.size(); r++)
            {
                cards.push_back(Card(ranks[r], suits[s]));
            }
        }
    }

    Card deal()
    {
        if (cards.empty())
        {
            throw runtime_error("Error - Deck is empty");
        }
        Card c = cards.back();
        cards.pop_back();
        return c;
    }

    void display()
    {
        for (int i = 0; i < (int)cards.size(); i++)
        {
            cards[i].display();
            if ((i + 1) % 13 == 0)
                cout << endl;
            else
                cout << ",";
        }
        cout << endl;
    }

    void shuffle()
    {
        for (int i = 0; i < (int)cards.size(); i++)
        {
            int j = rand() % cards.size();
            swap(cards[i], cards[j]);
        }
    }

    bool isEmpty()
    {
        return cards.empty();
    }
};

// ---------------- Player Struct ----------------
struct Player
{
    string name;
    int win;
    int lose;
    int tie;
};

// ---------------- Main ----------------
int main()
{
    srand(time(0));

    Deck deck;

    Player p1, p2;
    p1.win = p1.lose = p1.tie = 0;
    p2.win = p2.lose = p2.tie = 0;

    cout << "Enter the name of the first player: ";
    cin >> p1.name;
    cout << "Enter the name of the second player: ";
    cin >> p2.name;

    int numGames;
    cout << "How many games will they play? ";
    cin >> numGames;

    cout << "\n Original Deck\n";
    deck.display();

    deck.shuffle();
    cout << "\n Shuffled Deck\n";
    deck.display();

    for (int g = 1; g <= numGames; g++)
    {
        cout << "\nGame " << g << "\n--------\n";
        try
        {
            Card c1 = deck.deal();
            Card c2 = deck.deal();

            cout << "\t" << p1.name << "=>";
            c1.display();
            cout << endl;

            cout << "\t" << p2.name << "=>";
            c2.display();
            cout << endl;

            int result = c1.compare(c2);
            if (result == 1)
            {
                cout << p1.name << "=> Winner\n";
                p1.win++;
                p2.lose++;
            }
            else if (result == -1)
            {
                cout << p2.name << "=> Winner\n";
                p2.win++;
                p1.lose++;
            }
            else
            {
                cout << "Tie game\n";
                p1.tie++;
                p2.tie++;
            }
        }
        catch (runtime_error &e)
        {
            cout << e.what() << endl;
            break;
        }
    }

    cout << "\n------Final Stats-------\n";
    cout << "\t" << p1.name << " vs. " << p2.name << endl;
    cout << "Wins   " << p1.win << "\t" << p2.win << endl;
    cout << "Losses " << p1.lose << "\t" << p2.lose << endl;
    cout << "Ties   " << p1.tie << "\t" << p2.tie << endl;

    return 0;
}
