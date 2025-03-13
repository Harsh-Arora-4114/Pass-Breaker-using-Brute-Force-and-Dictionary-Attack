#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <algorithm>

using namespace std;

string trim(const string &str) 
{
    size_t first = str.find_first_not_of(" \t\n\r");
    if (first == string::npos)
    {
    return "";
    }
    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, last - first + 1);
}

bool attemptLogin(const string &pass, const string &tgpass) 
{
    return pass == tgpass;
}

void Bruteforce(const string &tgpass, const string &charset, int maxlen) 
{
    int len = 1;
    while (len <= maxlen) 
    {
        string password(len, charset[0]);
        while (true) 
        {
            if (attemptLogin(password, tgpass)) 
            {
                cout << "Password cracked: " << password << endl;
                return;
            }

            int i = len - 1;
            while (i >= 0 && password[i] == charset.back()) 
            {
                password[i] = charset[0];
                i--;
            }
            if (i < 0) break;
            password[i] = charset[charset.find(password[i]) + 1];
        }
        len++;
    }
    cout << "Password not found!!!" << endl;
}

void Dictionary(const string &tgpass) 
{
    string dictionaryFile = "C:\\Users\\arora\\OneDrive\\Documents\\Code\\.vscode\\DAA\\passwords.txt";

    ifstream file(dictionaryFile);
    if (!file) 
    {
        cout << "Error: Dictionary file is not found!" << endl;
        return;
    }

    file.seekg(0, ios::end);
    if (file.tellg() == 0) 
    {
        cout << "Error: Dictionary file is empty." << endl;
        file.close();
        return;
    }
    file.seekg(0, ios::beg);

    string word;
    while (getline(file, word)) 
    {
        word = trim(word);
        cout << "Trying pass: " << word << endl;
        if (attemptLogin(word, tgpass)) 
        {
            cout << "Password cracked: " << word << endl;
            file.close();
            return;
        }
    }

    file.close();
    cout << "Password not found in the dictionary." << endl;
}

int main() 
{
    string tgpass;
    int choice;
    cout << "--- Password Cracker ---" << endl;
    cout << "Enter the target password: ";
    cin >> ws;
    getline(cin, tgpass);

    cout << "Choose an attack method:" << endl;
    cout << "1. Brute Force Attack" << endl;
    cout << "2. Dictionary Attack" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) 
    {
        string charset;
        int maxlen;

        cout << "Enter the character set to use (e.g.: abc123): ";
        cin >> charset;

        cout << "Enter the maximum password length to try: ";
        cin >> maxlen;

        auto start = chrono::high_resolution_clock::now();
        Bruteforce(tgpass, charset, maxlen);
        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double> elapsed = end - start;
        cout << "Time taken: " << elapsed.count() << " sec." << endl;
    } 
    else if (choice == 2) 
    {

        auto start = chrono::high_resolution_clock::now();
        Dictionary(tgpass);
        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double> elapsed = end - start;
        cout << "Time taken: " << elapsed.count() << " sec." << endl;
    } 
    else 
    {
        cout << "Invalid choice." << endl;
    }

    return 0;
}
