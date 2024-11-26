// Author: Antonia Watts
// Date: 07/21/2023
// Method: c++
// This program is a clock that has both 12 and 24 hour clocks that allows international
// clients to enter a time of their choice to be displayed.

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Function for the clock's formatted border
void printClockBorder() {
    for (int i = 0; i < 16; ++i) { // outputs spaces
        cout << " ";    
    }    
    for (int i = 0; i < 27; ++i) { // outputs * for the pattern
        cout << "*";    
    }    
    for (int i = 0; i < 5; ++i) {  // outputs spaces                
        cout << " ";    
    }    
    for (int i = 0; i < 27; ++i) { // outputs * for the pattern                 
        cout << "*";    
    }    
    cout << endl;
}

// Function for outputting both clocks (12hr/24hr) 
void printTimes(int hours, int minutes, int seconds) {
    // attributes for converting the time from 24 hours to 12 hours
    int hourTime;
    int minTime;
    int secTime;
    string dayNight = "AM";

    // converts 24 hours to 12 hours
    if (hours == 0) {
        hourTime = 12;
    }
    else if (hours == 12) {
        hourTime = hours;
        dayNight = "PM";
    }
    else if (hours > 12){
        hourTime = hours - 12;
        dayNight = "PM";
    }
    else {
        hourTime = hours;
    }

    // clock presentation
    cout << "\t\t*\t" << "12-Hour clock";
    cout << "\t  *";
    cout << "\t*"   << "\t24-Hour Clock";    
    cout << "\t  *" << endl;    
    // 12-hour clock    
    cout << "\t\t* \t ";    cout << setw(2)  << setfill('0') << hourTime << ":";    
    cout << setw(2)  << minutes  << ":";    
    cout << setw(2)  << seconds;    
    cout << " " << dayNight;    
    cout << "\t  *";    
    // 24-hour clock    
    cout << "\t*"   << "\t   ";    
    cout << setw(2) << setfill('0') << hours    << ":";    
    cout << setw(2) << minutes  << ":";    
    cout << setw(2) << seconds;       
    cout << "\t  *" << endl;
    }

// Function that accepts input from user
void inputTime(int& setHour, int& setMinute, int& setSecond){
    string inputString;
    string tempString;
    bool userTime = false; // validation
    int colonOne; // will find the first colon
    int colonTwo; // will find the second colon
    
    // while loop for reading user input
    while (!userTime) {
        cout << "Enter time as HH:MM:SS in 24-hour format: ";
        getline(cin, inputString);
        colonOne = inputString.find(':');
        colonTwo = inputString.find(':', colonOne + 1);

        try
        {
            setHour = stoi(inputString.substr(0, colonOne));
            setMinute = stoi(inputString.substr(colonOne + 1, colonTwo));
            setSecond = stoi(inputString.substr(colonTwo + 1, inputString.size()-1));
        }
        catch (const std::exception&)
        {

        }
        // if-else statements for checking user input is in the correct time format
        if (inputString.size() != 8) { // checking for input length
            cout << "Invalid time" << endl;
            !userTime;
        }
        else if (setHour < 0 || setHour > 23) { // checking if input hour is valid
            cout << "Invalid time" << endl;
            !userTime;
        }
        else if (setMinute < 0 || setMinute > 59){ // checking if input minutes is valid
            cout << "Invalid time" << endl;
            !userTime;
        }
        else if (setSecond < 0 || setSecond > 59){
            cout << "Invalid time" << endl;
            !userTime;
        }
        else {
            userTime = true; 
        }

    }
}
// Function for main menu of program
void printMenu() {    
    cout << endl;    
    cout << "*********************************" << endl;    
    cout << "* 1: Add One Hour\t\t*" << endl;    
    cout << "* 2: Add One Minute\t\t*" << endl;    
    cout << "* 3: Add One Second\t\t*" << endl;    
    cout << "* 4: Exit\t\t\t*" << endl;    
    cout << "*********************************" << endl;    
    cout << endl;
}

// Accepting and validating input
void userInput(int& userChoice, int& setHour, int& setMinute, int& setSecond){
    cout << "Select an option: ";
    
    // if-else statements for resetting time segments
    if (!(cin >> userChoice)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        userChoice = 0;
    }
    switch (userChoice){
    case 1:                 
        cout << "1 hour added" << endl;
        if (setHour < 23) {
            ++setHour;
        }
        else {
            setHour = 00; // resets hour
        }
        break;
    case 2:
        cout << "1 minute added" << endl;
        if (setMinute < 59){
            ++setMinute;
        }
        else {
            setMinute = 00; // resets minutes
        }
        break;
    case 3:
        if (setSecond < 59) {
            ++setSecond;
        }
        else {
            setSecond = 00; // resets seconds
        }
        break;
    case 4:
        cout << "Goodbye!" << endl;
        break;
    default:
        cout << "Invalid input, please enter a number between 1-4" << endl;
        cin.clear();
        break;
    }
}

// main function
int main() {
    int userChoice = 0;
    int setHour = 0;
    int setMinute = 0;
    int setSecond = 0;
    // prompts user to set time
    inputTime(setHour, setMinute, setSecond);
    // while loop for outputting clock functions
    while (userChoice != 4) {
        printClockBorder();
        printTimes(setHour, setMinute, setSecond);
        printClockBorder();
        printMenu();
        userInput(userChoice, setHour, setMinute, setSecond);
    }
    return 0;
}
