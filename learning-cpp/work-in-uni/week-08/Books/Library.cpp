#include "Library.h"

Library::Library(size_t capacity) :capacity(capacity), count(0)
{
    books = new book[capacity];
}

Library::Library()
{
    delete[] this->books;
}


Library& Library::operator+=(const Book& newBook)
{
    if(count == capacity)
    {
        capacity *= 2;
        Book * temp = new Book[capacity];
        for(size_t = 0; i < count; ++i)
        {
            temp[i] = books[i];
        }
        delete[] books;
        books = temp;
        books[count++] = newBook;

    }
}
