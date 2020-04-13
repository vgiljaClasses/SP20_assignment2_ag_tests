//
// Created by Vikash Gilja on 4/12/20.
//

#include "Deck.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    Deck deck;

    // Test 1
    cout << "Deck Test 1: Testing card count after deck initialization:" << endl;
    if(deck.NumCards() != 52) {
        cout << "\tERROR: deck.NumCards() reporting " << deck.NumCards() << ", should be 52 after deck initialization!" << endl;
        return 1;
    }
    if(deck.IsEmpty()) {
        cout << "\tERROR: Expected IsEmpty method to return false" << endl;
    }
    cout << "\tPassed!" << endl;

    // Test 2
    cout << "Deck Test 2: Testing Pop Method by popping all of the cards" << endl;
    cout << " \tPopping: ";
    int pop_count = 0;
    Card a_card;
    while (deck.Pop(a_card)) {
        cout << ++pop_count << " ";
    }
    cout << endl;
    if (pop_count !=52) {
        cout << "\tERROR: Expected pop to succeed exactly 52 times, it succeeded " << pop_count << " times!" << endl;
        return 1;
    }
    if (deck.NumCards() != 0) {
        cout << "\tERROR: Expected NumCards method to return 0, it returned " << deck.NumCards() << endl;
        return 1;
    }
    if (!deck.IsEmpty()) {
        cout << "\tERROR: Expected IsEmpty method to return true" << endl;
        return 1;
    }
    cout << "\tPassed!" << endl;

    // Test 3
    cout << "Deck Test 3: Testing Push on empty deck" << endl;
    if (!deck.Push(a_card)) {
        cout << "\tERROR: Could not push a card on an empty deck!" << endl;
        return 1;
    }
    cout << "\tPassed!" << endl;

    // Test 4
    cout << "Deck Test 4: Trying to push the same card a second time" << endl;
    if (deck.Push(a_card)) {
        cout << "\tERROR: We were able to push an identical card back onto the deck a second time" << endl;
        return 1;
    }
    cout << "\tPassed!" << endl;

    // Test 5
    Deck deck2;
    cout << "Deck Test 5: Testing if we can push to a full deck" << endl;
    if(deck2.Push(a_card)) {
        cout << "\tERROR: Push was a success for a full deck!";
        return 1;
    }
    cout << "\tPassed!" << endl;

    // Test 6
    Deck deck3;
    Card card_from_2, card_from_3;
    cout << "Deck Test 6: Testing Shuffle" << endl;
    deck3.Shuffle();
    int match_count = 0;
    while (!deck2.IsEmpty()) {
        deck2.Pop(card_from_2);
        deck3.Pop(card_from_3);
        if(card_from_2.DoesCardMatch(card_from_3)) match_count++;
    }
    if (match_count == 52) {
        cout << "\tERROR: Shuffle failed! " << match_count << "/52 cards matched after shuffle!" << endl;
        return 1;
    }
    cout << "\tPassed with " << match_count << "/52 cards matching after shuffle!" << endl;

    // Test 7
    Deck deck4;
    Card card_from_4;
    deck4.Shuffle();
    cout << "Deck Test 7: Testing IsCardInDeck method with positive and negative cases" << endl;
    deck4.Pop(card_from_4);
    if (deck4.IsCardInDeck(card_from_4))
    {
        cout << "\tERROR: A card that was popped should not still be in the deck!" << endl;
        return 1;
    }
    deck4.Push(card_from_4);
    if (!deck4.IsCardInDeck(card_from_4))
    {
        cout << "\tERROR: A card that was pushed back onto the deck should be in the deck!" << endl;
        return 1;
    }
    cout << "\tPassed" << endl;

    return 0;
}