#include "Card.h"
#include "Hand.h"
#include <iostream>

using namespace std;

Hand::Hand(){}
string Hand::toString() {
    string s;
    for (int i = 0; i < hand.size(); ++i) {
        s += hand[i].toString() + " ";
    }

    return s;
}

