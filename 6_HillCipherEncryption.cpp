#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main() {
    // Input key matrix size
    int n;
    cout << "Enter key matrix size: ";
    cin >> n;
    
    // Input key matrix data
    vector<vector<int>> key(n, vector<int>(n));
    cout << "Enter key matrix data: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> key[i][j];
        }
    }
    
    // Input text to encrypt
    string text;
    cout << "Enter text to encrypt: ";
    cin >> text;
    
    // Convert text to uppercase and remove spaces
    string plaintext = "";
    for (int i = 0; i < text.length(); i++) {
        if (isalpha(text[i])) {
            plaintext += toupper(text[i]);
        }
    }
    
    // Pad plaintext if necessary
    int remainder = plaintext.length() % n;
    if (remainder != 0) {
        int num_pad_chars = n - remainder;
        for (int i = 0; i < num_pad_chars; i++) {
            plaintext += 'X';
        }
    }
    
    // Convert plaintext to matrix of integers
    vector<vector<int>> plaintext_matrix(n, vector<int>(plaintext.length() / n));
    for (int i = 0; i < plaintext.length(); i++) {
        int row = (i / n);
        int col = (i % n);
        plaintext_matrix[col][row] = plaintext[i] - 'A';
    }
    
    // Multiply plaintext matrix with key matrix
    vector<vector<int>> ciphertext_matrix(n, vector<int>(plaintext.length() / n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (plaintext.length() / n); j++) {
            int sum = 0;
            for (int k = 0; k < n; k++) {
                sum += (key[i][k] * plaintext_matrix[k][j]);
            }
            ciphertext_matrix[i][j] = sum % 26;
        }
    }
    
    // Convert ciphertext matrix to string
    string ciphertext = "";
    for (int i = 0; i < ciphertext_matrix.size(); i++) {
        for (int j = 0; j < ciphertext_matrix[i].size(); j++) {
            ciphertext += (ciphertext_matrix[i][j] + 'A');
        }
    }
    
    // Output encrypted text
    cout << "Encrypted text: " << ciphertext << endl;
    
    return 0;
}
