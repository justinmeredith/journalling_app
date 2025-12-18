#include "JournalDatabase.h"

void JournalDatabase::initialize() {
    const char* create_table_sql =
    "CREATE TABLE IF NOT EXISTS journal_entries ("
    "id INTEGER PRIMARY KEY AUTOINCREMENT,"
    "timestamp TEXT NOT NULL,"
    "prettytimestamp TEXT NOT NULL,"
    "title TEXT,"
    "body TEXT"
    ");";
    
    char* error = nullptr;
    sqlite3_open(filename.c_str(), &database);

    int rc = sqlite3_exec(database, create_table_sql, nullptr, nullptr, &error);

    if  (rc != SQLITE_OK) {
        printf("SQL error: %s\n", error);
        sqlite3_free(error);
    } else {
        printf("Journal table ready.\n");
    }
}

void JournalDatabase::addEntry(const JournalEntry& entry) {
    const char* sql = "INSERT INTO journal_entries (timestamp, title, body) VALUES (:timestamp, :prettytimestamp, :title, :bodytext);";

    sqlite3_stmt* stmt = nullptr;

    if (sqlite3_prepare_v2(database, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(database) << std::endl;
        return;
    }

    sqlite3_bind_text(stmt, 1, entry.getDateCreated().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, entry.getPrettyDateCreated().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, entry.getTitle().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, entry.getText().c_str(), -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        std::cerr << "Failed to execute statement: " << sqlite3_errmsg(database) << std::endl;
    }

    sqlite3_finalize(stmt);
}