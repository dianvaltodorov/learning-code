#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <cstring>
#include <cstdio>


class Book
{
public:
    Book(const char* = "", const char* = "", size_t = 0, const int* = NULL);
    ~Book();
    Book(const Book & other);
    Book& operator =(const Book&);



    const char* getTitle() const //we don't modify the object, so we put the const keyword infront
    {
        return title;
    }


    const char* getAuthor() const //we don't modify the object, so we put the const keyword infront
    {
        return author;
    }

    const int* getISGN()
    {
        return ISBN;
    }

    const int getPages()
    {
        return countPages;
    }

    // the const in fron is really important. supposing there is no char infornt, we give direct access
    // to the address of the daata in memory and we can modify them
    const int*  getISBN()
    {
        return ISBN;
    }

    void setTitle(const char*);


    void setAuthor(const char*);


    void setPages(size_t pages);
    void setISBN(int* isbn);

    // b = copy; (copy constructor)
    // Book b(); (empty constructor))
    // Book copy = b; (copy constructor)

    // const char * x- указателят не може да промени данните, тоес
    // char * const x - указтелят не може да се промени
private:
    char* title;
    char* author;
    size_t countPages;
    int ISBN[13];
private:
    void copyText(char*& , const char*);
};

std::ostream& operator<<(std::ostream&, const Book&)
{

}


#endif // BOOK_H
