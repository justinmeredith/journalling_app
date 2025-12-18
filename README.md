# CLI Journalling App

This is a journalling app written in C++ for use in a terminal. It allows the user to read and write journal entries, add to them after they've been written, and delete them. They're automatically organized by the date and time they were created, making it a fast, efficient, and minimally intensive way to jot down your thoughts from your terminal.

In the future, I'm planning on implementing SQL for more sophisticated storage management. I'd also like to add additional metadata to the files, like mood tracking, and persistent editing rather than simply appending text to the end of entries. 

## Installation

The program includes a **Makefile**, so enter the same directory as this **Makefile** and enter the command "make" in your terminal. This will generate the file "journal", which you can run by entering the command "./journal" in your terminal from the same directory that the files **journal** and **Makefile** are in. When you use the "./journal" command, it'll start the app. You can use this command whenever you're ready to use the program.

If you ever decide to make changes to the code or download an update, you can just run the "make" command again to update the **journal** file. 

## Journal Entry Storage

Journal entries that you create with the app will be automatically stored in the **entries** directory as plain text documents (.txt). These entries are named for the date and time they were created, in the format "YYYYMMDDhhmmss.txt". This makes it easy to determine what order the files were created in and is essential for how the program loads the files in, so I would not recommend changing the default name the files are given without modifying the program to accommodate the change. 

You can view the title that you gave your entry by opening the file itself. You can also open the files and edit them in your plain text editor of choice, just be sure not to change the first two lines of the file, as this is where your entry's title and reader-friendly date are stored. 

## Credit

This project was solely created by me and is free for any and all personal use. If you'd like to connect with me about this project, you can reach me easily on LinkedIn: https://www.linkedin.com/in/justin-c-meredith/

Thanks for your support and attention to my project. 

## License

MIT License

Copyright (c) 2025 Justin Meredith

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.