#include "JournalEntry.h"

JournalEntry::JournalEntry(string input_title) {
    setDateCreated();
    title = input_title;
}

JournalEntry::JournalEntry(string file_name, string file_contents) {
    strcpy(date_created, file_name.c_str());
    stringstream file_contents_stream(file_contents);
    string pretty_date_string;
    getline(file_contents_stream, pretty_date_string);
    strcpy(pretty_date_created, pretty_date_string.c_str());
    getline(file_contents_stream, title);

    string line;
    while (getline(file_contents_stream, line)) {
        text += line + "\n";
    }
}

void JournalEntry::setDateCreated() {
    const time_t current_time = time(nullptr);
    strftime(date_created, 50, "%Y%m%d%H%M%S", localtime(&current_time));
    strftime(pretty_date_created, 100, "%B %e, %Y %I:%M%p", localtime(&current_time));
}

string JournalEntry::getDateCreated() const {
    return date_created;
}

string JournalEntry::getPrettyDateCreated() const {
    return pretty_date_created;
}

string JournalEntry::getTitle() const {
    return title;
}

string JournalEntry::getText() const {
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
    ofstream new_entry ("entries/" + getDateCreated() + ".txt");
    new_entry << getPrettyDateCreated() << endl;
    new_entry << getTitle() << endl;
    new_entry << getText() << endl;
    new_entry.close();
    cout << endl << "Entry recorded." << endl;
}

void JournalEntry::addToJournalEntry() {
    displayJournalEntry();
    cout << "Enter the text you would like to add to the end of your entry here." << endl;
    cout << "To finish your additional entry, type the '~' symbol followed by the 'return' key." << endl;
    cout << "Everything after the '~' will not be included in your entry." << endl << endl << " > ";

    string additional_text;
    getline(cin, additional_text, '~');
    text += additional_text;

    ofstream updated_entry ("entries/" + getDateCreated() + ".txt");
    updated_entry << getPrettyDateCreated() << endl;
    updated_entry << getTitle() << endl;
    updated_entry << getText() << endl;
    updated_entry.close();
    cout << endl << "Entry updated." << endl;
}