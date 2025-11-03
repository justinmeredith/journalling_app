#include <iostream>
#include "JournalEntry.cpp"

int main() {
    JournalEntry testing_entry;
    cout << "Date Created: " << testing_entry.getDateCreated() << endl;
    cout << "Pretty Date Created: " << testing_entry.getPrettyDateCreated() << endl;
    return 0;
}