#include "JournalEntry.h"

JournalEntry::JournalEntry(string input_title) {
    setDateCreated();
    title = input_title;
}

void JournalEntry::setDateCreated() {
    const time_t current_time = time(nullptr);
    strftime(date_created, 50, "%Y%m%d%H%M%S", localtime(&current_time));
    strftime(pretty_date_created, 100, "%B %e, %Y %I:%M%p", localtime(&current_time));
}

string JournalEntry::getDateCreated() {
    return date_created;
}

string JournalEntry::getPrettyDateCreated() {
    return pretty_date_created;
}

string JournalEntry::getTitle() {
    return title;
}

string JournalEntry::getText() {
    return text;
}

void JournalEntry::displayJournalEntry() {
    cout << endl << getTitle() << endl;
    cout << getPrettyDateCreated() << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
    cout << getText() << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
}

void JournalEntry::writeInJournal() {
    cout << endl << "Write your journal entry below." << endl;
    cout << "To finish the entry, type the '~' symbol followed by the 'return' key." << endl;
    cout << "Everything after the '~' will not be included in your entry." << endl << endl << " > ";
    getline(cin, text, '~');
    ofstream new_entry (getDateCreated() + ".txt");
    new_entry << getPrettyDateCreated() << endl;
    new_entry << getTitle() << endl;
    new_entry << getText() << endl;
    cout << endl << "Entry recorded." << endl;
}