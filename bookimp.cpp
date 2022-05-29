#include "book.h"

Library::Library()
{
    ifstream f;
    Book b;
    f.open("booklist.bin", ios::in | ios::binary);
    while(f.read((char*)&b, sizeof(b)))
    {
        books.push_back(b);
    }

    f.close();
}

void Library::show_books()
{
    cout<<"Book ID\tBookName\tAuthor\tAvailable"<<endl;
    cout<<"*************************************************\n";
    for(int i = 0; i < books.size(); i++)
    {
        cout<<books[i].book_id<<"\t"<<books[i].book_name<<"\t"<<books[i].author<<"\t";
        if(books[i].is_available)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
}

void Library::sort_books()
{
    for(int i = 0; i < books.size(); i++)
    {
        for(int j = i+1; j < books.size()-1; i++)
        {
            if(books[i].book_id > books[j].book_id)
            {
                Book temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
            
        }
    }
}

void Library::write_details()
{
    ofstream f;
    f.open("booklist.bin", ios::out | ios::binary);
    for(int i = 0; i < books.size(); i++)
    {
        f.write((char*)&books[i], sizeof(books[i]));
    }

    f.close();
}

void Library::add_book()
{
    string name, author;
    int id = books.size() + 1;
    cout<<"Enter name of the book: ";
    cin>>name;
    cout<<"Enter the name of the author: ";
    cin>>author;
    Book b(id, name, author, true);
    books.push_back(b);
    this->sort_books();
}

vector<Book> Library::books;
int Library::tot_users = -1;

void User::get_details()
{
    cout<<"Enter your name: ";
    cin >> user_name;
    cout<<"Enter your mobile number: ";
    cin >> mobile;

    cout<<"Your user id is: "<<user_id<<endl;
}

void User::show_details()
{
    cout<<"User ID: "<<this->user_id<<endl;
    cout<<"Name: "<<this->user_name<<endl;
    cout<<"Mobile: "<<this->mobile<<endl;
}

void User::borrow_book(int bid)
{
    for(int i = 0; i < books.size(); i++)
    {
        if(books[i].book_id == bid)
        {
            books[i].is_available = false;
            borrow_book_id = bid;
            cout<<"You have borrowed the following book\n";
            cout<<books[i].book_name<<" by "<<books[i].author<<endl;
        }
    }
}

void User::return_book()
{
    if(borrow_book_id == -1)
    {
        cout<<"You have no book to return\n";
        return;
    }
    for(int i = 0; i < books.size(); i++)
    {
        if(books[i].book_id == borrow_book_id)
        {
            books[i].is_available = true;
            borrow_book_id = -1;
            cout<<"You have returned the following book\n";
            cout<<books[i].book_name<<" by "<<books[i].author<<endl;
        }
    }
}

int User::getUser_id()
{
    return user_id;
}

string User::getUser_name()
{
    return user_name;
}