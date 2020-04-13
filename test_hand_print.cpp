//
// Created by Vikash Gilja on 4/12/20.
//

#include "Hand.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    Hand hand;
    Card card1(Card::FaceEnum::ACE, Card::SuitEnum::CLUB);
    Card card2(Card::FaceEnum::KING, Card::SuitEnum::SPADE);
    Card card3(Card::FaceEnum::FIVE, Card::SuitEnum::DIAMOND);
    Card card4(Card::FaceEnum::TWO, Card::SuitEnum::HEART);
    hand.Add(card1);
    hand.Add(card2);
    hand.Add(card3);
    hand.Add(card4);
    hand.PrintHand();
    return 0;
}