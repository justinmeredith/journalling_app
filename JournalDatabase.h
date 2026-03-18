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
        const char* filename = "journal_database.db";
};