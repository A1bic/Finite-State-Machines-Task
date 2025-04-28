#include <iostream>
void DFA_conditions(std::string& a) {
  int current_state = 0;
  for (char& ch : a) {
    switch (current_state) {
      case (0) :
        switch (ch) {
          case ('a'):
            current_state = 0;
            break;
          case ('b'):
            current_state = 1;
            break;
          default:
            current_state = 3;
            break;
        };
        break;
      case (1) :
        switch (ch) {
          case ('a'):
            current_state = 1;
            break;
          case ('b'):
            current_state = 2;
            break;
          default:
            current_state = 3;
            break;
        }
        break;
      case (2) :
        switch (ch) {
          case ('a'):
            current_state = 2;
            break;
          default:
            current_state = 3;
            break;
        }
        break;
      case (3) :
        break;
    }
  }
  
  if (current_state == 2) 
    std::cout << "Автомат принял строку" << std::endl;
  else
    std::cout << "Автомат не принял строку" << std::endl;
}

void DFA2(std::string& str) {
  int table[4][3] = {
    [0] = {0, 1, 3},
    [1] = {1, 2, 3},
    [2] = {2, 3, 3},
    [3] = {3, 3, 3},
  };
  
  int current_state = 0;
  for (char& ch : str) {
    if (ch == 'a')
      current_state = table[current_state][0];
    else if (ch == 'b')
      current_state = table[current_state][1];
    else 
      current_state = table[current_state][2];
  }

  if (current_state == 2) 
    std::cout << "Автомат принял строку" << std::endl;
  else
    std::cout << "Автомат не принял строку" << std::endl;

}

int main() {
  std::string input;
  std::cin >> input;
  DFA2(input);
  //DFA_conditions(input);


  return 0;
}
