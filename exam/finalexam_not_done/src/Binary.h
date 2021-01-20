#ifndef BINARY_H
#define BINARY_H
#include <iostream>
#include <cmath>
#include <stdio.h>
#include <string>
using namespace std;

class Binary{
public:
    Binary():_bits(nullptr),_size(0){}

    Binary(int bits[],int size):_bits(nullptr),_size(size){
        _bits = new int[_size];
        for(int i=0; i<_size; i++){
            if(bits[i]!=1 && bits[i]!=0)
                throw(std::runtime_error("Bit only can be 1 or 0."));
            _bits[i]=bits[i];
        }
    }

    Binary(Binary const & b){
      this->_size = b._size;
      _bits = new int[b._size];
      for(int i=0; i<b._size; i++){
          if(b._bits[i]!=1 && b._bits[i]!=0)
              throw(std::runtime_error("Bit only can be 1 or 0."));
          _bits[i]=b._bits[i];
      }
    }

    Binary & operator=(Binary const & b){
      this->_size = b._size;
      _bits = new int[b._size];
      for(int i=0; i<b._size; i++){
          if(b._bits[i]!=1 && b._bits[i]!=0)
              throw(std::runtime_error("Bit only can be 1 or 0."));
          _bits[i]=b._bits[i];
      }
      return *this;
    }

    ~Binary(){
        if(_bits != nullptr)
            delete[] _bits;
    }

    int at(int i) const{
      if(i>=_size || i<0)
          throw(std::runtime_error("Overflow"));
      return _bits[i];
    }

    int size() const{
      return _size;
    }

    Binary fillWithZero(int n) const{
      if(n < _size){
        throw(std::runtime_error("cannot down scale."));
      }
      int bits[n] = {0};
      for(int i=0 ; i<_size ; i++){
        bits[n-_size+i] = this->_bits[i];
      }
      return Binary(bits, n);
    }

    unsigned int toDec() const{
      unsigned int result=0;
      for(int i=_size-1 ; i>=0 ; i--)
          result+=_bits[i]*pow(2,i);
      return result;
    }

    // unsigned int toDec() const{
    //   unsigned int result=0;
    //   for(int i=0 ; i>_size ; i++)
    //       result+=_bits[i]*pow(2, _size-i-1);
    //   return result;
    // }

    friend ostream & operator << (ostream & output, const Binary & bin){
        output << "{";
        output << bin._bits[bin.size()-1];
        for(int i=bin.size()-2;i>=0;i--)
            output << "," << bin._bits[i];
        output <<"}";
        return output;
    }

    friend istream & operator >> (istream & input, Binary & bin){
        throw(std::runtime_error("cannot down scale."));
    }

private:
    int* _bits;
    int _size;
};

#endif