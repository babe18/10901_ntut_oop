#include "ConvString.h"

// Check the input to see it's correct or not
int checkInput(string input) {
  try {
    for(char c: input) {
      // Using isalnum to rule out input other than [0-9a-zA-Z]
      if(!isalnum(c) && c != '[' && c != ']') {
        throw invalid_argument(__func__);
      }
    }
  } catch (const invalid_argument& ia) {
      cout << "The function " << ia.what() << " reports input error" << endl;
  }
  return 0;
}

int pairs(string input) {
  // Check input for [] pairs
  int left = 0;
  int right = 0;
  for(char c : input) {
      // Counting the number of [ & ]
      if(c == '[') {
          left += 1;
      } else if(c == ']') {
          right += 1;
      }
  }
  return (left - right);
}

int findRightOffset(string input) {
  int left = 0;
  int right = 0;
  int offset = 0;
  for(int i = 0;i < input.size();i++) {
      // Counting the number of [ & ]
      if(input[i] == '[') {
          left += 1;
      } else if(input[i] == ']') {
          right += 1;
          if(left == right) {
              offset = i;
          }
      }
      if(left - right == 0) {
        break;
      }
  }
  return offset;
}

// Convert the input according to HW01's request
string convert(string input) {
  string result = "";

  // if [] are not comes in pairs, return blank string directly
  if(pairs(input) != 0)
    return result;

  int i = 0;
  do {
    if(isdigit(input[i])) {
      int repeatTimes = input[i] - '0';
      int len = findRightOffset(input.substr(i + 1, input.size() - (i + 1)));
      if(repeatTimes > 0) {
        string tmp;
        tmp += input.substr(i + 2, len - 1);
        while(repeatTimes > 0) {
          result += convert(tmp);
          repeatTimes -= 1;
        }
      } else {
        result += "";
      }
      i += len + 2;
    } else {
      result += input[i];
      i += 1;
    }
    //return to_string(i);
  } while (i < input.size());

  return result;
}
