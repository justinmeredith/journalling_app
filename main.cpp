#include <iostream>
#include <ctime>
#include "JournalEntry.cpp"

string returnCurrentTime() {
    const time_t current_time = time(nullptr);
    return ctime(&current_time);
}

int main() {
    string current_time;
    current_time = returnCurrentTime();
    cout << current_time;
    return 0;
}