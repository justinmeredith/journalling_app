#include "JournalDatabase.h"

void JournalDatabase::initialize() {
    const char* create_table_sql =
    "CREATE TABLE IF NOT EXISTS journal_entries ("
    "id INTEGER PRIMARY KEY AUTOINCREMENT,"
    "timestamp TEXT NOT NULL,"
    "title TEXT,"
    "body TEXT"
    ");";
    
    char* error = nullptr;
    // Creates the SQLite database if it doesn't already exist
    sqlite3* journal_database;

    int rc = sqlite3_exec(journal_database, create_table_sql, nullptr, nullptr, &error);

    if  (rc != SQLITE_OK) {
        printf("SQL error: %s\n", error);
        sqlite3_free(error);
    } else {
        printf("Journal table ready.\n");
    }
}