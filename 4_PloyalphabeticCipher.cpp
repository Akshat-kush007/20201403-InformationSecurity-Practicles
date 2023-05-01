#include <iostream>
#include <string>
using namespace std;

int main() {
  string message, key;
  cout << "Enter Message : ";
  getline(cin, message);
  cout << "Enter Key : ";
  getline(cin, key);

  string encrypted_message = "";
  for(int i = 0, j = 0; i < message.length(); i++, j++) {
    if(j == key.length())
      j = 0;
    encrypted_message += ((message[i] + key[j]) % 26) + 'A';
  }

  string decrypted_message = "";
  for(int i = 0, j = 0; i < message.length(); i++, j++) {
    if(j == key.length())
      j = 0;
    decrypted_message += ((encrypted_message[i] - key[j] + 26) % 26) + 'A';
  }

  cout << "\nEncrypted Message : " << encrypted_message;
  cout << "\nDecrypted Message : " << decrypted_message;
  return 0;
}
