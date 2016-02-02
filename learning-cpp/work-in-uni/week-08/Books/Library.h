#ifndef LIBRARY_H
#define LIBRARY_H
class LIBRARY_H
{y
public:
    Library(size_t);
    Library();
    Library(const Library&);
    Library operator=(const Library&);

private:
    Book* books;
    size_t capacity;
    size_t count;

    void copy(const Library&);
};

#endif // LIBRARY_H
