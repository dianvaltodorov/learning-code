#include "Book.h"

Book::Book(const char* title,
           const char* author,
           size_t pages,
           const int * isbn)
{
    copyText(this->title, title);
    copyText(this->author, author);
    mempcpy(this->ISBN, isbn, sizeof(ISBN));
}

//Book::Book(const Book & other) : Book(other.title, other.author, other,countPages, other.ISBN)
//{}

Book::~Book()
{
    delete[] title;
    delete[] author;
}

Book& Book::operator=(const Book& other)
{
        if(this == &other)
            return *this;

        this->setTitle(other.title);
        this->setAuthor(other.author);
        this->setPages(other.countPages);
        this->setISBN(other.ISBN);
}

void Book::copyText(char*& dest, const char* src)
{
    size_t len = strlen(title) + 1;
    dest = new char[len + 1];
    strcpy(dest, src);
}


void Book::setTitle(const char * title)
{
    delete[] this->title;

    copyText(this->title, title);
}


std::ostream& operator <<(std::ostream out, const Book& book)
{
    out << book.getTitle() << std::endl
         << book.getAuthor() << std::endl
         << book.getPages() << std::endl
         << book.getISBN() << std::endl;
    return out;
}
