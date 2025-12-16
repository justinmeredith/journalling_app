#ifndef JOURNALENTRY_H
#define JOURNALENTRY_H

#include <string>
#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class JournalEntry {
    public:
        JournalEntry(string input_title);
        JournalEntry(string file_name, string file_contents);
        void setDateCreated();
        string getDateCreated() const;
        string getPrettyDateCreated() const;
        string getTitle() const;
        string getText() const;
        void displayJournalEntry();
        void writeInJournal();
        void addToJournalEntry();
    private:
        char date_created[50];
        char pretty_date_created[100];
        string title;
        string text;
};

#endif