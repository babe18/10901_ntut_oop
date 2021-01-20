#ifndef TERM_H
#define TERM_H

#include<cmath>

class Term {
public:
    // default constuctor
    Term():_coefficient(0),_exponent(0){}

    // constructor
    Term(double coefficient, int exponent):_coefficient(coefficient),_exponent(exponent){}

    // operator =
    Term & operator=(Term const &term){
        this->_coefficient = term._coefficient;
        this->_exponent = term._exponent;
        return *this;
    }

    // operator +
    Term operator+(Term const &term){
        if(this->_exponent != term._exponent)
            throw "terms with different exponents can't be added";
        return Term(this->_coefficient + term._coefficient, this->_exponent);
    }

    // operator *
    Term operator*(Term const &term){
        return Term(this->_coefficient * term._coefficient, this->_exponent + term._exponent);
    }

    // operator ==
    bool operator==(Term const &term){
        return this->_coefficient == term._coefficient &&
            this->_exponent == term._exponent;
    }

    double getCoefficient() const {
        return _coefficient;
    }

    int getExponent() const {
        return _exponent;
    }

    double evaluate(double x){
        return this->_coefficient * pow(x, this->_exponent);
    }

private:
    double _coefficient, _exponent;
};

#endif
