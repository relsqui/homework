#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;


void empty_cin() {
    while (cin.get() != '\n');
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
    if (!(cin >> number)) {
        cin.clear();
    }
    empty_cin();
    return number;
}


void strupper(const char in_string[], char out_string[]) {
    int i = 0;
    for (; i < strlen(in_string); i++) {
        out_string[i] = toupper(in_string[i]);
    }
    out_string[i] = '\0';
}


void strlower(const char in_string[], char out_string[]) {
    int i = 0;
    for (; i < strlen(in_string); i++) {
        out_string[i] = tolower(in_string[i]);
    }
    out_string[i] = '\0';
}


bool partial_match(const char input[], const char target[]) {
    char * input_lower;
    char * target_lower;
    if (!strlen(input)) {
        return false;
    }
    input_lower = new char[strlen(input)];
    target_lower = new char[strlen(target)];
    strlower(input, input_lower);
    strlower(target, target_lower);
    if (strncmp(input_lower, target_lower, strlen(input))) {
        delete [] input_lower;
        delete [] target_lower;
        return false;
    } else {
        delete [] input_lower;
        delete [] target_lower;
        return true;
    }
}


bool boolean_prompt(const char prompt[]) {
    char response[4] = "\0";
    do {
        cout << prompt;
        if (cin.peek() != '\n') {
            cin >> response;
        }
        empty_cin();
        if (partial_match(response, "yes")) {
            return true;
        } else if (partial_match(response, "no")) {
            return false;
        } else {
            cout << "Please type y or n." << endl;
            response[0] = '\0';
        }
    } while (response[0] == '\0');
}
