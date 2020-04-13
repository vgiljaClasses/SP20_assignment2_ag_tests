//
// Created by Vikash Gilja on 4/12/20.
//

#include "Hand.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    Hand hand;
    Card card1(Card::FaceEnum::ACE, Card::SuitEnum::CLUB);
    Card card2(Card::FaceEnum::ACE, Card::SuitEnum::SPADE);
    Card card3(Card::FaceEnum::FIVE, Card::SuitEnum::DIAMOND);
    Card card4(Card::FaceEnum::TWO, Card::SuitEnum::HEART);

    // Test 1
    cout << "Hand Test 1: Testing card count after hand initialization:" << endl;
    if (hand.NumCards() != 0) {
        cout << "\tERROR: hand.NumCards() reporting " << hand.NumCards() << ", should be 0 after deck initialization!" << endl;
        return 1;
    }
    cout << "Hand Test 1 Passed" << endl;

    //Test 2
    cout << "Hand Test 2: Testing adding and removing cards" << endl;
    cout << "\tTrying to discard a card not in the hand (1)" << endl;
    if (hand.Discard(card1)) {
        cout<< "\tERROR: Discarding a card NOT in the hand returned with a success, should have failed!! (1)" << endl;
        return 1;
    }
    cout << "\tTrying to add a card not in the hand" << endl;
    if (!hand.Add(card1)) {
        cout<< "\tERROR: Adding a card NOT in the hand returned with a failure, should have succeeded!! (1)" << endl;
        return 1;
    }
    if (hand.NumCards() != 1) {
        cout << "\tERROR: NumCards method expected to return 1, it returned " << hand.NumCards() << endl;
        return 1;
    }
    cout << "\tTrying to add a card that is in the hand" << endl;
    if (hand.Add(card1)) {
        cout<< "\tERROR: Adding a card in the hand returned with a success, should have failed!!" << endl;
        return 1;
    }
    cout << "\tTrying to discard a card that is not in the hand (2)" << endl;
    if (hand.Discard(card2)) {
        cout<< "\tERROR: Discarding a card NOT in the hand returned with a success, should have failed!! (2)" << endl;
        return 1;
    }
    cout << "\tTrying to discard a card that is in the hand" << endl;
    if (!hand.Discard(card1)) {
        cout<< "\tERROR: Discarding a card in the hand returned with a failure, should have succeeded!!" << endl;
        return 1;
    }
    if (hand.NumCards() != 0) {
        cout << "\tERROR: NumCards method expected to return 0, it returned " << hand.NumCards() << endl;
        return 1;
    }
    cout << "\tTrying to add a card that is not in the hand (2)" << endl;
    hand.Add(card1);
    if (!hand.Add(card2)) {
        cout << "\tERROR: Adding a card NOT in the hand returned with a failure, should have succeeded!! (2)" << endl;
        return 1;
    }
    if (hand.NumCards() != 2) {
        cout << "\tERROR: NumCards method expected to return 2, it returned " << hand.NumCards() << endl;
        return 1;
    }
    cout << "\tTesting GetCard" << endl;
    Card card1_ret;
    Card card2_ret;
    hand.GetCard(card1_ret, 0);
    hand.GetCard(card2_ret, 1);
    if (!card1_ret.DoesCardMatch(card1) || !card2_ret.DoesCardMatch(card2)) {
        cout << "ERROR: Cards retrieved with GetCard method do not match expected values" << endl;
        return 1;
    }
    cout << "Hand Test 2 Passed" << endl;

    cout << "Hand Test 3: Further Discard Testing" << endl;
    Hand hand2;
    hand2.Add(card1);
    hand2.Add(card2);
    hand2.Add(card3);
    hand2.Add(card4);
    cout << "\tDiscarding card4 after adding card1, card2, card3 and card4" << endl;
    if(!hand2.Discard(card4) || hand2.IsCardInHand(card4) || !hand2.IsCardInHand(card1) || !hand2.IsCardInHand(card2)
       || !hand2.IsCardInHand(card3) || hand2.NumCards() != 3) {
        cout << "\tERROR: Discard of card4 failed!" << endl;
        return 1;
    }
    hand2.Add(card4);
    cout << "\tDiscarding card1 after adding card1, card2, card3 and card4" << endl;
    if(!hand2.Discard(card1) || hand2.IsCardInHand(card1) || !hand2.IsCardInHand(card2) || !hand2.IsCardInHand(card3)
       || !hand2.IsCardInHand(card4) || hand2.NumCards() != 3) {
        cout << "\tERROR: Discard of card1 failed!" << endl;
        return 1;
    }
    cout << "\tDiscarding card3 after adding card2, card3 and card4" << endl;
    if(!hand2.Discard(card3) || hand2.IsCardInHand(card1) || hand2.IsCardInHand(card3) || !hand2.IsCardInHand(card2)
       || !hand2.IsCardInHand(card4) || hand2.NumCards() != 2) {
        cout << "\tERROR: Discard of card3 failed!" << endl;
        return 1;
    }
    cout << "Hand Test 3 Passed" << endl;

    return 0;
}