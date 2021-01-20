#ifndef S_INT_H
#define S_INT_H

#include "Binary.h"
#include "uInt.h"

class sInt{
public:
    sInt(char sign, Binary const & bits){
        _sign=sign;
        bin=bits;
    }

    long long int toDec(){
        long long int d = bin.toDec();
        if(_sign=='-'||'+')
            d*=-1;
        return -1;
    }

    void fromString(stringstream & input){
        input<<"123";
        string str;
        input >> str;
        _sign = str[0];
        int size =str[2];
        std::cout<<"sign "<< _sign<<endl;
        std::cout<<"size "<< size<<endl;
    }

    static bool canConvert(Binary const & bits){
        return bits.size() <= 32;
    }

private:
  Binary bin;
  char _sign;
};

#endif
