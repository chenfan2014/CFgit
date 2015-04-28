#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum Suit{Clubs, Diamond, Heart, Spade, Unknown};

enum Rank{Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace, Invaild};

enum Color{Red, Black};

class Card{
    public:
        //void FaceUp();
        //void FaceDown();

        Card(Rank r, Suit s, Color c);
        void print() const;
    private:
        Rank cardRank;
        Suit cardSuit;
        Color cardColor;

};

Card::Card(Rank r, Suit s, Color c)
    :cardRank(r),
     cardSuit(s),
     cardColor(c)
{}

void Card::print() const
{
    cout << cardRank << " " << cardSuit << " " << cardColor << endl;
}

int main(int argc, const char *argv[])
{
    Card spadeAce(Ace, Spade, Red);
    spadeAce.print();
    return 0;
}
