#ifndef JOURNALENTRY_H
#define JOURNALENTRY_H

#include <string>
using namespace std;

class JournalEntry {
    public:
        JournalEntry();
    private:
        int date_created;
        string title;
};

#endif