#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "comb_numbers.h"

void SplitLine(std::string& str, std::vector<std::string>& words) {
  std::istringstream iss(str);
  //std::istream_iterator<std::string> begin(str), end;

  std::copy(std::istream_iterator<std::string>(iss), std::istream_iterator<std::string>(), std::back_inserter(words));
}

void Help(void) {
  std::cout << "Help:" << std::endl;
  std::cout << "Function arguments can only be positive integers" << std::endl;
  std::cout << "Commands:" << std::endl;
  std::cout << "\tQ - end session" << std::endl;
  std::cout << "\tH - help" << std::endl;
  std::cout << "\tU <m> <n> - calculation the number of placements with repetitions from m to n" << std::endl;
  std::cout << "\tA <m> <n> - calculation the number of placements without repetitions from m to n" << std::endl;
  std::cout << "\tP <n> - calculation the number of permutations for n" << std::endl;
  std::cout << "\tC <m> <n> - calculation of the number of combinations from m to n" << std::endl;
  std::cout << "\tS <m> <n> - calculation of the Stirling number of the second kind" << std::endl;
  std::cout << "\tB <m> - calculation of Bell's number " << std::endl;
}

unsigned int getNum(std::string str, bool& error) {
  unsigned result = 0;

  for (int i = 0; i < str.length(); i++) {
    unsigned int num = str[i] - '0';
    if (result > (_UI32_MAX - num) / 10) {
      error = true;
      return 0;
    }
    result *= 10;
    result += str[i] - '0';
  }

  return result;
}

int main(void) {
  bool error;
  std::string str;

  while (true) {
    std::vector<std::string> words;
    error = false;

    std::getline(std::cin, str);
    SplitLine(str, words);
    if (words[0].size() != 1 || words.size() > 3) {
      std::cout << "Unknown opertion, enter H to learn more" << std::endl;
    }
    else {
      for (auto w = words.begin() + 1; w != words.end(); w++) {
        if ((*w).find_first_not_of("0123456789") != std::string::npos) {
          std::cout << "Wrong argument, use H to learn more" << std::endl;
          error = true;
          break;
        }
      }
      if (error != true) {
        switch (words[0][0]) {
          case 'H':
            if (words.size() != 1)
              std::cout << "Wrong argument, use H to learn more" << std::endl;
            else
              Help();
            break;
          case 'Q':
            if (words.size() != 1)
              std::cout << "Wrong argument, use H to learn more" << std::endl;
            else
              return 0;
          case 'U':
            if (words.size() != 3)
              std::cout << "Wrong argument, use H to learn more" << std::endl;
            else {
              unsigned m = getNum(words[1], error), n = getNum(words[2], error), result;
              if (!error) {
                result = U(m, n, error);
                if (!error)
                  std::cout << result << std::endl;
                else
                  std::cout << "Out of range result" << std::endl;
              }
              else
                std::cout << "Out of range argument" << std::endl;
            }
            break;
          case 'A':
            if (words.size() != 3)
              std::cout << "Wrong argument, use H to learn more" << std::endl;
            else {
              unsigned m = getNum(words[1], error), n = getNum(words[2], error), result;
              if (!error) {
                result = A(m, n, error);
                if (!error)
                  std::cout << result << std::endl;
                else
                  std::cout << "Out of range result" << std::endl;
              }
              else
                std::cout << "Out of range argument" << std::endl;
            }
            break;
          case 'P':
            if (words.size() != 2)
              std::cout << "Wrong argument, use H to learn more" << std::endl;
            else {
              unsigned n = getNum(words[1], error), result;
              if (!error) {
                result = P(n, error);
                if (!error)
                  std::cout << result << std::endl;
                else
                  std::cout << "Out of range result" << std::endl;
              }
              else
                std::cout << "Out of range argument" << std::endl;
            }
            break;
          case 'C':
            if (words.size() != 3)
              std::cout << "Wrong argument, use H to learn more" << std::endl;
            else {
              unsigned m = getNum(words[1], error), n = getNum(words[2], error), result;
              if (!error) {
                result = C(m, n, error);
                if (!error)
                  std::cout << result << std::endl;
                else
                  std::cout << "Out of range result" << std::endl;
              }
              else
                std::cout << "Out of range argument" << std::endl;
            }
            break;
          case 'S':
            if (words.size() != 3)
              std::cout << "Wrong argument, use H to learn more" << std::endl;
            else {
              unsigned m = getNum(words[1], error), n = getNum(words[2], error), result;
              if (!error) {
                result = S(m, n, error);
                if (!error)
                  std::cout << result << std::endl;
                else
                  std::cout << "Out of range result" << std::endl;
              }
              else
                std::cout << "Out of range argument" << std::endl;
            }
            break;
          case 'B':
            if (words.size() != 2)
              std::cout << "Wrong argument, use H to learn more" << std::endl;
            else {
              unsigned n = getNum(words[1], error), result;
              if (!error) {
                result = B(n, error);
                if (!error)
                  std::cout << result << std::endl;
                else
                  std::cout << "Out of range result" << std::endl;
              }
              else
                std::cout << "Out of range argument" << std::endl;
            }
            break;
        }
      }
    }
  }
}