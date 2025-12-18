#include "JournalEntry.cpp"
#include <sqlite3.h>
#include <cstdio>
#include <string>
using namespace std;

class JournalDatabase {
    public:
        void initialize();
        void addEntry(const JournalEntry& entry);
    private:
        sqlite3* database;
        string filename = "journal_database.sqlite3";
};