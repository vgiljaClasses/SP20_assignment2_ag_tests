cmake_minimum_required(VERSION 3.10)
project(assignment2)

set(CMAKE_CXX_STANDARD 11)

add_executable(test_deck test_deck.cpp ../Card.cpp ../Deck.cpp ../Hand.cpp)
add_executable(test_hand test_hand.cpp ../Card.cpp ../Hand.cpp ../Deck.cpp)
add_executable(test_player test_player.cpp ../Card.cpp ../Hand.cpp ../Player.cpp)

add_executable(test_deck_print test_deck_print.cpp ../Card.cpp ../Deck.cpp ../Hand.cpp)
add_executable(test_hand_print test_hand_print.cpp ../Card.cpp ../Hand.cpp ../Deck.cpp)
