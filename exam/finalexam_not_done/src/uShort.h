#ifndef U_SHORT_H
#define U_SHORT_H

#include "Binary.h"

class uShort{
public:

  static bool canConvert(Binary const & bits){
    return bits.size() <= 16;
  }

  uShort(Binary const & bits){
    if(canConvert(bits)){
      this->_b = bits.fillWithZero(16);
    }else{
      throw(std::runtime_error("the size is not suitable"));
    }
  }

  unsigned short toDec(){
    unsigned short result=0;
      for(int i=15 ; i>=0 ; i--)
          result+=_b.at(i)*pow(2,0);
      return result;
  }

private:
    Binary _b;
};

#endif
