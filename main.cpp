#include "JournalEntry.cpp"

int main() {
    string user_entry_title;
    cout << "The name of today's entry: ";
    getline(cin, user_entry_title, '\n');
    JournalEntry new_entry(user_entry_title);

    new_entry.writeInJournal();
    new_entry.displayJournalEntry();
    return 0;
}