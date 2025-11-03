#include "JournalEntry.h"

JournalEntry::JournalEntry() {
    setDateCreated();
}

void JournalEntry::setDateCreated() {
    const time_t current_time = time(nullptr);
    strftime(date_created, 50, "%Y%m%d%H%M%S", localtime(&current_time));
    strftime(pretty_date_created, 50, "%B %e, %Y %I:%M%p", localtime(&current_time));
}

string JournalEntry::getDateCreated() {
    return date_created;
}

string JournalEntry::getPrettyDateCreated() {
    return pretty_date_created;
}