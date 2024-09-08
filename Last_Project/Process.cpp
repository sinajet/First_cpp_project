#include "Process.hpp"

void Process::run() {
    while (true) {
        showMenu();
        int choice;
        std::cin >> choice;
        handleChoice(choice);
    }
}

void Process::showMenu() {
    std::cout << "\n######################################################\n"
                 " __          __                                     \n"
                 "/\\ \\      __/\\ \\                                    \n"
                 "\\ \\ \\    /\\_\\ \\ \\____  _ __   __    _ __  __  __    \n"
                 " \\ \\ \\  _\\/\\ \\ \\ '__`\\/\\`'__/'__`\\ /\\`'__/\\ \\/\\ \\   \n"
                 "  \\ \\ \\L\\ \\ \\ \\ \\ \\L\\ \\ \\ \\/\\ \\L\\.\\\\ \\ \\/\\ \\ \\_\\ \\  \n"
                 "   \\ \\____/\\ \\_\\ \\_,__/\\ \\_\\ \\__/.\\_\\ \\_\\ \\/`____ \\ \n"
                 "    \\/___/  \\/_/\\/___/  \\/_/\\/__/\\/_/\\/_/  `/___/> \\\n"
                 "                                              /\\___/\n"
                 "                                              \\/__/ \n"
                 "######################################################\n"
                 "Write your selected number then Press Enter\n"
                 "1. Create Author\n"
                 "2. Create Book\n"
                 "3. Search Book (ID)\n"
                 "4. Search Book (Title)\n"
                 "5. Remove Book (ID)\n"
                 "7. Export Data As .txt File\n"
                 "8. Exit\n";
    std::cout << "Enter The Number==> ";
}

void Process::handleChoice(int choice) {
    switch (choice) {
        case 1: createAuthor(); break;
        case 2: createBook(); break;
        case 3: findBookId(); break;
        case 4: findBookTitle(); break;
        case 5: removeBookId(); break;
        case 6: showAllBooks(); break;
        case 7: exportToFile(); break;
        case 8: std::exit(0);
        default: std::cout << "Invalid choice. Try again.\n"; break;
    }
}

void Process::createAuthor() {
    int id;
    std::string firstName, lastName;
    std::cout << "Enter ID==> ";
    std::cin >> id;
    std::cin.ignore();
    std::cout << "Enter First Name==> ";
    std::getline(std::cin, firstName);
    std::cout << "Enter Last Name==> ";
    std::getline(std::cin, lastName);
    authors_.emplace(id, Author(firstName, lastName));
    std::cout << "Author created.\n";
    Process::nextPage();
}

void Process::createBook() {
    int id, authorId;
    std::string title, isbn;
    std::cout << "Enter Book ID==> ";
    std::cin >> id;
    std::cin.ignore();
    std::cout << "Enter ISBN==> ";
    std::cin >> isbn;
    std::cin.ignore();
    std::cout << "Enter Book Title==> ";
    std::getline(std::cin, title);
    std::cout << "Enter Author ID==> ";
    std::cin >> authorId;

    auto authorIt = authors_.find(authorId);
    if (authorIt != authors_.end()) {
        library_.addBook(id, Book(id, title, isbn, authorIt->second));
        std::cout << "Book created.\n";
    } else {
        std::cout << "Author not found.\n";
    }
    Process::nextPage();
}

void Process::findBookId() {
    int id;
    std::cout << "Enter Book ID==> ";
    std::cin >> id;
    auto book = library_.searchBookId(id);
    if (book) {
        std::cout << *book << "\n";
        Process::nextPage();
    } else {
        std::cout << "Book not found.\n";
        Process::nextPage();
    }

}

void Process::findBookTitle() {
    std::string title;
    std::cout << "Enter Book Title==> ";
    std::cin.ignore();
    std::getline(std::cin, title);
    auto book = library_.searchBookTitle(title);
    if (book) {
        std::cout << *book << "\n";
    } else {
        std::cout << "Book not found.\n";
    }
    Process::nextPage();
}

void Process::removeBookId() {
    int id;
    std::cout << "Enter Book ID to remove==> ";
    std::cin >> id;
    library_.removeElementId(id);
    std::cout << "Book removed.\n";
    Process::nextPage();
}

void Process::showAllBooks() {
    if (library_.getAllBooks().empty()) std::cout << "Library Is Empty!\n";
    else {
        for (auto & book: library_.getAllBooks()) {
            std::cout << book << '\n';
        }
    }
}

void Process::exportToFile() {
    std::string fileName;
    std::cout << "Please enter the file name(Dont Write the format of file like .txt) ==> ";
    std::cin.ignore();
    std::getline(std::cin, fileName);
    writeToFile(fileName+".txt");
    Process::nextPage();
}

void Process::writeToFile(const std::basic_string<char> &fileName) {
    std::ofstream outFile(fileName);

    if (!outFile.is_open()) {
        std::cerr << "Error: Could not open the file " << fileName << "\n";
        return;
    }

    auto books = library_.getAllBooks();
    for (const auto& book : books) {
        outFile << "ID: " << book.getId() << "\n";
        outFile << "ISBN: " << book.getIsbn() << "\n";
        outFile << "Title: " << book.getTitle() << "\n";
        outFile << "Author: " << book.getAuthor().getFirstName() << " " << book.getAuthor().getLastName() << "\n";
        outFile << "###########################\n";
    }

    outFile.close();
    std::cout << "File save as" << fileName << ".\n";
    Process::nextPage();
}

void Process::nextPage() {
    std::cout << "Press Enter to Continue";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
}
