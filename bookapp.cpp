#include "book.h"

int main()
{
    User curr;
    int ch;
    vector<User> users;
    Library *l;


    do
    {
        cout<<"******The Digital Library*******\n";
        cout<<"1. Existing User\n";
        cout<<"2. New User\n";
        cout<<"3. Exit\n";
        cout<<"Enter you choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            int id;
            cout<<"Please enter your user ID: ";
            cin >> id;
            int flag = 0;
            for (int i = 0; i < users.size(); i++) 
            {
                if(id == users[i].getUser_id())
                {
                    curr = users[i];
                    flag = 1;
                }
            }

            if(flag == 0)
            {
                cout<<"User ID doesn't exist\n";
                break;
            }
            cout<<"\n\nWelcome "<<curr.getUser_name()<<endl;
            int choice;
            do
            {
                cout<<"1. View available books\n";
                cout<<"2. Borrow a book\n";
                cout<<"3. Return a book\n";
                cout<<"4. Donate a book\n";
                cout<<"5. Logout\n";
                cout<<"Enter your choice: ";
                cin >> choice;
                switch(choice)
                {
                    case 1:
                    {
                        curr.show_books();
                        break;
                    }
                    case 2:
                    {
                        int bid;
                        cout<<"Enter the book id you want to borrow from the list: ";
                        cin >> bid;
                        curr.borrow_book(bid);
                        break;
                    }
                    case 3:
                    {
                        curr.return_book();
                        break;
                    }
                    case 4:
                    {
                        curr.add_book();
                        cout<<"Thank you for donating a book\n";
                        break;
                    }
                    case 5:
                    {
                        cout<<"You have signed out\n";
                        break;
                    }
                }
            }while(choice < 5);

            break;
        }
        case 2:
        {
            User u;
            l = (User*)&u;
            l->get_details();
            users.push_back(u);
            break;
        }
        case 3:
        {
            cout<<"Exit\n";
            break;
        }
        }
    } while (ch < 3);
    
}