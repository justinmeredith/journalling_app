// A journalling app created by Justin Meredith.
// Development started in November of 2025.

#include "JournalEntry.cpp"
#include <vector>
#include <filesystem>
#include <cstdio>
#include <cstring>
#include <algorithm>

 vector<JournalEntry> loadUserJournal() {
    vector<JournalEntry> loaded_entries;
    
    // Steps through every file in the entries directory
    for (const auto& entry : std::filesystem::directory_iterator("entries")) {
        // Stores the current file name in the format "file_name.txt"
        string file_name = entry.path().stem().string();
        string file_contents;

        // Leaves this loop if the file is not a .txt file, important for hidden files like .gitkeep
        if (entry.path().extension() != ".txt") {
            continue;
        }

        // Opens the current file
        ifstream journal_entry(entry.path());
        string line;

        // Stores each line of the file
        while (getline(journal_entry, line)) {
            file_contents += line + "\n";
        }

        JournalEntry loading_entry(file_name, file_contents);
        loaded_entries.push_back(loading_entry);
    }

    // Sorts the entries in order so that they display neatly for the user
    sort(loaded_entries.begin(), loaded_entries.end(),
     [](const JournalEntry& a, const JournalEntry& b) {
         return a.getDateCreated() < b.getDateCreated();
     });
     
    return loaded_entries;
}

void displayPreviousEntries(vector<JournalEntry> past_entries) {
    if (past_entries.size() == 0) {
        cout << "There are no past entries to display.";
    } else {
        cout << "Here are your previous journal entries: " << endl;
        for (int i = 0; i < past_entries.size(); ++i) {
            cout << "   " << i + 1 << ": " << past_entries.at(i).getPrettyDateCreated() << " - " << past_entries.at(i).getTitle() << endl;
        }
    } 
}

int main() {
    bool running = true;

    // Formatting Strings
    string menu_line = "\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";
    string journal_selection_error_message = menu_line + "<*> Please enter a valid selection by typing the number that corresponds to the     <*>\n<*> entry you would like to select. For instance, type '1' to open the first entry. <*>\n<*> Or enter '0' to return to the main menu.                                        <*>\n" + menu_line;

    string user_decision;
    vector<JournalEntry> user_journal;
    vector<JournalEntry> past_entries;

    cout << "Your Journal." << endl;
    cout << "  An app by Justin Meredith." << endl;

    while (running) {
        past_entries =  loadUserJournal();
        cout << menu_line;
        cout << endl << "What would you like to do today?" << endl << endl;
        cout << "    1. Write a new journal entry" << endl;
        cout << "    2. View previous journal entries" << endl;
        cout << "    3. Open and edit previous journal entry" << endl;
        cout << "    4. Delete a journal entry" << endl;
        cout << "    0. Exit" << endl;
        cout << endl << "> ";

        cin >> user_decision;

        // Enter a new journal entry
        if (user_decision == "1") {
            cout << menu_line;
            string user_entry_title;
            cout << "The name of today's entry: ";
            cin.ignore();
            getline(cin, user_entry_title, '\n');
            JournalEntry new_entry(user_entry_title);
            new_entry.writeInJournal();

        // View a list of past journal entries
        } else if (user_decision == "2") {
            displayPreviousEntries(past_entries);
        
        // Append text to a past journal entry
        } else if (user_decision == "3") {
            displayPreviousEntries(past_entries);
            int user_entry_selection;
            bool valid_input = false;

            // Make sure a viable journal entry was selected
            while (!valid_input) {
                cout << endl << "Type the number of the entry you would like to open." << endl;
                cout << "Or enter '0' to return to the main menu." << endl;
                cout << "> ";
                cin.clear();
                cin.ignore();
                cin >> user_entry_selection;

                // Make sure an int character was entered
                if (!cin) {
                    cout << journal_selection_error_message;
                    continue;
                }

                // Make sure that the int character entered corresponds to a possible option
                if (user_entry_selection <= past_entries.size() && user_entry_selection >= 0) {
                    valid_input = true;
                } else {
                    cout << journal_selection_error_message;
                }
            }

            // Continues if the user chooses a past entry or returns to the main menu if they entered 0
            if (user_entry_selection != 0) {
                past_entries.at(user_entry_selection - 1).addToJournalEntry();
            }

        // Deletes a past journal entry
        } else if (user_decision == "4") {
            displayPreviousEntries(past_entries);
            int user_entry_selection;
            bool valid_input = false;

            // Make sure a viable journal entry was selected
            while (!valid_input) {
                cout << endl << "Type the number of the entry you would like to delete." << endl;
                cout << "Or enter '0' to return to the main menu." << endl;
                cout << "> ";
                cin.clear();
                cin.ignore();
                cin >> user_entry_selection;

                // Make sure an int character was entered
                if (!cin) {
                    cout << journal_selection_error_message;
                    continue;
                }

                // Make sure that the int character entered corresponds to a possible option
                if (user_entry_selection <= past_entries.size() && user_entry_selection >= 0) {
                    valid_input = true;
                } else {
                    cout << journal_selection_error_message;
                }
            }

            // Continues if the user chooses a past entry or returns to the main menu if they entered 0
            if (user_entry_selection != 0) {
                string deleting_file_name = past_entries.at(user_entry_selection - 1).getDateCreated() + ".txt";
                string pretty_journal_entry_name = past_entries.at(user_entry_selection - 1).getPrettyDateCreated() + " - " + past_entries.at(user_entry_selection - 1).getTitle();
                int file_deleted_successfully = remove(("entries/" + deleting_file_name).c_str());
                if (file_deleted_successfully == 0) {
                    cout << pretty_journal_entry_name << " was successfully deleted." << endl;
                } else {
                    cout << "There was an error deleting your journal entry." << endl;
                }
            }

        // Quits the program
        } else if (user_decision == "0") {
            cout << endl << "Thanks for stopping by! See you next time." << endl;
            cout << menu_line;
            running = false;

        // Handles invalid input for the menu selection
        } else {
            cout << "<*> Please choose an option from the list and enter its corresponding number. <*>" << endl;
            cout << "<*> For instance, to choose the first option, 'Write a new journal entry',    <*>" << endl;
            cout << "<*> type '1' and then hit the 'return' key.                                   <*>" << endl;
            cout << menu_line;
        }
    } 
    return 0;
}