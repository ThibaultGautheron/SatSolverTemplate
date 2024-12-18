/**
* @author Tim Luchterhand
* @date 26.11.24
* @brief
*/

#include "basic_structures.hpp"
#include "util/exception.hpp"

namespace sat {
    // @TODO implementation here


    Variable::Variable(unsigned val) {
        vid = val;
    }

    unsigned Variable::get() const {
        return vid;
    }

    bool Variable::operator==(Variable other) const {
        return (vid == other.get());
    }

    Literal::Literal(unsigned val) {
        lid = val;
    }
    Literal::Literal(){}

    unsigned Literal::get() const {
        return lid;
    }

    Literal Literal::negate() const {
        return ((lid%2 == 0) ? Literal(lid+1) : Literal(lid-1));
    }

    short Literal::sign() const {
        return (lid%2 == 0) ? -1 : 1;
    }

    bool Literal::operator==(Literal other) const {
        return (lid == other.get() && Literal(lid).sign() == other.sign());
    }

    Literal pos(Variable x) {
        return Literal(2*x.get()+1);
    }

    Literal neg(Variable x) {
        return Literal(2*x.get());
    }

    Variable var(Literal l) {
        return Variable(l.get()/2);
    }
}
