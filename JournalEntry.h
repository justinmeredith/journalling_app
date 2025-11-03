#ifndef JOURNALENTRY_H
#define JOURNALENTRY_H

#include <string>
#include <ctime>
using namespace std;

class JournalEntry {
    public:
        JournalEntry();
        void setDateCreated();
        string getDateCreated();
        string getPrettyDateCreated();
    private:
        char date_created[50];
        char pretty_date_created[100];
        string title;
};

#endif