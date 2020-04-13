//
// Created by Vikash Gilja on 4/12/20.
//

#include "Player.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    Player player;

    cout << "Test 1: Player name tests" << endl;
    cout << "\tTesting default name" << endl;
    if (player.GetName() != "No Name") {
        cout << "\tERROR: Default name not set properly" << endl;
        return 1;
    }
    player.SetName("Bob");
    if (player.GetName() != "Bob") {
        cout << "\tERROR: SetName method not working correctly" << endl;
        return 1;
    }
    Player player2("Alice");
    if (player2.GetName() != "Alice") {
        cout << "\tERROR: Player constructor with name setting not working correctly" << endl;
        return 1;
    }
    cout << "Test 1 Passed" << endl;

    cout << "Test 2: Player Score Testing" << endl;
    if (player.GetScore() != 0) {
        cout << "\tERROR: Score not initialized properly!" << endl;
        return 1;
    }
    player.UpdateScore(20);
    if (player.GetScore() != 20) {
        cout << "\tERROR: Score not updated properly!" << endl;
        return 1;
    }
    player.UpdateScore(10);
    if (player.GetScore() != 30) {
        cout << "\tERROR: Score not updated properly!" << endl;
        return 1;
    }
    cout << "Test 2 Passed" << endl;

    return 0;
}