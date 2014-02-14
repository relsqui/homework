#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;


void empty_cin() {
    while (cin.get() != '\n');
}


bool boolean_prompt(const char prompt[]) {
    char response = '\0';
    do {
        cout << prompt;
        if (cin.peek() != '\n') {
            cin >> response;
        }
        switch (tolower(response)) {
            case 'y':
                return true;
                break;
            case 'n':
                return false;
                break;
            default:
                cout << "Please type y or n." << endl;
                response = '\0';
        }
        empty_cin();
    } while (response == '\0');
}


void read_chars(char array[], int length, const char prompt[]) {
    bool toolong = false;
    do {
        cout << prompt;
        if (cin.get(array, length, '\n')) {
            if (cin.peek() == '\n') {
                toolong = false;
            } else {
                cout << "Please enter no more than " << length - 1
                     << " characters." << endl;
                toolong = true;
            }
        } else {
            // Nothing was entered.
            array[0] = '\0';
            cin.clear();
            toolong = false;
        }
        empty_cin();
    } while (toolong);
}


int read_int(const char prompt[]) {
    int number = 0;
    cout << prompt;
    if (!cin >> number) {
        cin.clear();
    }
    empty_cin();
}


void strlower(char in_string[], char out_string[]) {
    int i = 0;
    for (; i < strlen(in_string); i++) {
        out_string[i] = tolower(in_string[i]);
    }
    out_string[i] = '\0';
}
