//
// Created by roel on 20-11-16.
//

#ifndef GRIMWALL_HEROVISITOR_H
#define GRIMWALL_HEROVISITOR_H


class HeroVisitor : public IVisitor {
public:
    void visit();
    void visit(Dralas* dralas);
};


#endif //GRIMWALL_HEROVISITOR_H
