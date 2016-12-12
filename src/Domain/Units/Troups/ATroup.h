#ifndef GRIMWALL_ATROUP_H
#define GRIMWALL_ATROUP_H


class ATroup {
private:
    int moveSpeed;
    int price;
public:
    virtual int getMoveSpeed() = 0;
    virtual int getPrice() = 0;
};


#endif //GRIMWALL_ATROUP_H
