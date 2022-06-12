#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Book
{
public:
    string book_name, author;
    int book_id;
    bool is_available;

    Book()
    {
        book_name = "";
        author = "";
        book_id = -1;
        is_available = false;
    }

    Book(int id, string name, string a, bool av)
    {
        book_id = id;
        book_name = name;
        author = a;
        is_available = av;
    }
};

class Library
{
protected:
    static vector<Book> books;
    static int tot_users;

public:
    static void show_books();
    void add_book();
    void sort_books();
    virtual void get_details() = 0;
};

class User: public Library
{
    string user_name, mobile;
    int user_id, borrow_book_id;
public:
    User()
    {
        user_name = "";
        mobile = "";
        borrow_book_id = -1;
        user_id = ++tot_users;
    }
    int getUser_id();
    string getUser_name();
    void get_details();
    void show_details();
    void borrow_book(int bid);
    void return_book();
};