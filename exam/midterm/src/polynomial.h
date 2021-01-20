#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include"term.h"

class Polynomial {
public:
    // consturctor
    Polynomial(Term *terms, int degree){
        if(terms!=NULL){
            _degree = degree;
            this->_terms = new Term[degree+1];
            for(int i=0; i<=degree; i++)
                this->_terms[i] = terms[i];
        }
        else{
            this->_terms = new Term[degree+1];
        }
    }

    // copy constructor
    Polynomial(Polynomial const &p){
        this->_degree = p._degree;
        this->_terms = new Term[p._degree+1];
        for(int i=0; i<=p._degree; i++)
            this->_terms[i] = p._terms[i];
    }

    // destructor
    ~Polynomial(){
        delete [] this->_terms;
    }

    // operator +
    Polynomial operator+(const Polynomial &p){
        int degree;
        if(this->_degree >= p._degree)
            degree = this->_degree;
        else
            degree = p._degree;
        Term t[degree];
        for(int i=0; i<=this->_degree; i++)
            t[i] = Term(this->_terms[i].getCoefficient() + p._terms[i].getCoefficient(), i);
        return Polynomial(t, degree);
    }

    // operator =
    Polynomial & operator=(const Polynomial &p){
        if(_terms!=NULL){
            if(!this->_terms){
                delete [] this->_terms;
            }
            this->_degree = p._degree;
            this->_terms = new Term[p._degree+1];
            for(int i=0; i<=p._degree; i++)
                this->_terms[i] = p._terms[i];
            return *this;
        }
        else{
            delete [] this->_terms;
        }
    }

    int getDegree() const{
        return this->_degree;
    }

    Term getTermByExponent(int exp) const{
        if(exp > this->_degree || exp < 0)
            throw "invalid";
        return this->_terms[exp];
    }

    double evaluate(double base){
        double result;
        for(int i=0; i<=this->_degree; i++)
            result += this->_terms[i].evaluate(base);
        return result;
    }

private:
    Term *_terms;
    int _degree;
};

#endif
