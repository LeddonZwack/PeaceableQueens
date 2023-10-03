//
// Created by Leddon Zwack on 9/24/23.
//

#include "../include/Square.h"

Square::Square() : attacked(false), queen(false) {}

bool Square::getAttack() const {
    return attacked;
}
bool Square::getQueen() const {
    return queen;
}

void Square::setAttack(bool flag) {
    attacked = flag;
}
void Square::setQueen(bool flag) {
    queen = flag;
}

bool Square::operator==(const Square &other) const {
    if (this->queen == other.queen && this->attacked == other.attacked) {
        return true;
    }
    return false;
}