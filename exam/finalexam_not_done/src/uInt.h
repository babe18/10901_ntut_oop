#ifndef U_INT_H
#define U_INT_H

#include "Binary.h"

class uInt{
public:
  static bool canConvert(Binary const & bits){
    return bits.size() <= 32;
  }

  uInt(Binary const & bits){
    if(uInt::canConvert(bits)){
      this->_b = bits.fillWithZero(32);
    }else{
      throw(std::runtime_error("the size is not suitable"));
    }
  }

  unsigned short toDec(){
    unsigned short result=0;
      for(int i=31 ; i>=0 ; i--)
          result+=_b.at(i)*pow(2,0);
      return result;
  }

private:
  Binary _b;
};

#endif
