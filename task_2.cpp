#include <iostream>
#include <vector>
#include <stack>
#include <string>

void space_deleter(std::string& str) {
  std::string modified;
  for (char& ch : str) {
     if (ch != ' ')
       modified.push_back(ch);
  }
  str = modified;
}

class Parser {
  private:
    std::string expression;
    std::vector<std::vector<int>> conditions;

    int count(char sym) {
      int count = 0;
      for (char ch : expression) {
        if (ch == sym)
          ++count;
      }
      return count;
    }  

    bool check_stars_and_bars() {
      std::string syms = "()|";
      for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == '|') {
          if (i == 0 || i == expression.length() - 1)
            return false;
          if (expression[i + 1] == '|' || expression[i - 1] == '|')
            return false;
          if (expression[i + 1] == ')' || expression[i - 1] == '(')
            return false;
        }
        if (expression[i] == '*') {
          if (i == 0)
            return false;
          if (expression[i - 1] == '|' || expression[i - 1] == '(')
            return false;
        }
      }
      return true;
    }

    bool check_brackets() {
      std::stack<char> st;
      for (int i = 0; i < expression.length(); i++) {
        char ch = expression[i];
        if (ch == '(')
          st.push(ch);
        if (ch == ')') {
          if (!st.empty()) {
            if (st.top() == '(') {
              st.pop();
            }
          }
          else {
            return false;
          }
          if (expression[i - 1] == '(') {
            std::cout << "empty brackets\n";
            return false;
          }
        }
      }
      return st.empty();
    }

  public:
    Parser(std::string&& s) {
      space_deleter(s);
      expression = s;
    }
    Parser() = default;

    
    void set_expression(std::string s)  {
      space_deleter(s);
      expression = s;
    }

    std::string get_expression() {
      return expression;
    }

    bool parse() {
      if (expression == "") {
        std::cout << "There is no expression, use \"set_expression\"" << std::endl;
        return false;
      }

      if (!check_brackets()) 
        return false;

      if (!check_stars_and_bars())
        return false;

      return true;
    }

};

int main() {
  Parser parser;
  std::string text;
  std::cin >> text;
  parser.set_expression(text);

  if (parser.parse()) 
    std::cout << "TRUE" << std::endl;
  else 
    std::cout << "NO" << std::endl;

  return 0;
}
