#include "JournalDatabase.h"

void JournalDatabase::initialize() {

    // Attempts to open the database or create it if it doesn't exist
    int successful_connection = sqlite3_open(filename, &database);

    // Checks that the database was successfully opened, otherwise throws an error
    if (successful_connection != SQLITE_OK) {
        std::cerr << "Unable to open the journal database." << sqlite3_errmsg(database) << endl;
        return;
    } else {
        cout << "Journal database successfully opened.";
    }

    const char* create_table = 
        "CREATE TABLE IF NOT EXISTS entries (\n"
        "date_created TEXT,\n"
        "pretty_date_created TEXT,\n"
        "title TEXT,\n"
        "body_text TEXT)";

    sqlite3_exec(database, create_table, NULL, NULL, NULL);
}