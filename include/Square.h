//
// Created by Leddon Zwack on 9/24/23.
//

#ifndef TESTPQ_SQUARE_H
#define TESTPQ_SQUARE_H


class Square {
public:
    explicit Square();
    ~Square() = default;

    bool getAttack() const;
    bool getQueen() const;

    void setAttack(bool flag);
    void setQueen(bool flag);

    bool operator==(const Square &other) const;

private:
    bool attacked;
    bool queen;
};

#endif //TESTPQ_SQUARE_H
