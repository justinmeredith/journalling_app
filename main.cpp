// A journalling app created by Justin Meredith.
// Development started in November of 2025.

#include "JournalEntry.cpp"
#include <vector>
#include <filesystem>

 vector<JournalEntry> loadUserJournal() {
    vector<JournalEntry> loaded_entries;
    
    // Steps through every file in the entries directory
    for (const auto& entry : std::filesystem::directory_iterator("entries")) {
        // Stores the current file name in the format "file_name.txt"
        string file_name= entry.path().filename().string();
        string file_contents;

        // Opens the current file
        ifstream journal_entry(file_name);
        string line;

        // Stores each line of the file
        while (getline(journal_entry, line)) {
            file_contents += line;
        }

        JournalEntry loading_entry(file_name, file_contents);
        loaded_entries.push_back(loading_entry);
    }
    return loaded_entries;
}

int main() {
    bool running = true;
    string user_decision;
    vector<JournalEntry> user_journal;

    cout << "Your Journal." << endl;
    cout << "  An app by Justin Meredith." << endl;

    while (running) {
        cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
        cout << endl << "What would you like to do today?" << endl << endl;
        cout << "    1. Write a new journal entry" << endl;
        cout << "    2. Delete a journal entry" << endl;
        cout << "    0. Exit" << endl;
        cout << endl << "> ";

        cin >> user_decision;

        if (user_decision == "1") {
            cout << endl << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
            string user_entry_title;
            cout << "The name of today's entry: ";
            cin.ignore();
            getline(cin, user_entry_title, '\n');
            JournalEntry new_entry(user_entry_title);
            new_entry.writeInJournal();
        } else if (user_decision == "2") {
            cout << "This option is not currently functional." << endl;
            cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
        } else if (user_decision == "0") {
            cout << endl << "Thanks for stopping by! See you next time." << endl;
            cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
            running = false;
        } else {
            cout << "<*> Please choose an option from the list and enter its corresponding number. <*>" << endl;
            cout << "<*> For instance, to choose the first option, 'Write a new journal entry',    <*>" << endl;
            cout << "<*> type '1' and then hit the 'return' key.                                   <*>" << endl;
            cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
        }
    }
    return 0;
}