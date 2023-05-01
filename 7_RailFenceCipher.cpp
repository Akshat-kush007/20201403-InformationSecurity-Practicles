#include <iostream>
#include <string>
using namespace std;

int main() {
  string message;
  int rails;

  cout << "Enter a Secret Message: ";
  getline(cin, message);

  cout << "Enter number of rails: ";
  cin >> rails;

  int len = message.length();
  int count = 0, j = 0;
  int code[100][1000] = {0};

  while(j < len) {
    if(count % 2 == 0) {
      for(int i = 0; i < rails; i++) {
        code[i][j] = (int)message[j];
        j++;
      }
    } else {
      for(int i = rails - 2; i > 0; i--) {
        code[i][j] = (int)message[j];
        j++;
      }
    }   
    count++;
  }

  for(int i = 0; i < rails; i++) {
    for(int j = 0; j < len; j++) {
      if(code[i][j] != 0)
        cout << (char)code[i][j];
    }
  }
  return 0;
}