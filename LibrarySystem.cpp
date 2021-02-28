#include <iostream>
#include<vector>
#include <algorithm>

using namespace std;

class  User
{
public:
    User add()
    {
        cout << "enter id :";
        cin >> this->id;
        cout << "\nenter name :";
        cin >> this->name;
        return *this;
    }
    void BrrowBook(int bId)
    {
        booksId.push_back(bId);
    }
    void print()
    {
        int num = booksId.size();
        cout << id << "  " << name << "Books Ids whitch borrowed :";
        sort(booksId.begin(), booksId.end());
        for (int i = 0; i < num; i++)
        {
            cout << booksId[i] << "   ";
        }
        cout << endl;

    }
    void returnBook(int idOfReturnBook)
    {
        int num = booksId.size();
        for (int i = 0; i < num; i++)
        {
            if (booksId[i] == idOfReturnBook)
            {
                booksId[i] = 0;
                break;
            }
        }
    }
private:
    int id;
    string name;
    vector<int>booksId;
};
class Book
{
public:
    Book add()
    {
        cout << "enter id :";
        cin >> this->id;
        cout << "\nenter name :";
        cin >> this->name;
        cout << "\nenter quantity :";
        cin >> this->quantity;
        return *this;
    }
    void returnBook(int idOfUserReturnBook)
    {
        int num = usersId.size();
        for (int i = 0; i < num; i++)
        {
            if (usersId[i] == idOfUserReturnBook)
            {
                usersId[i] = 0;
                break;
            }
        }
    }
    void BorrowBook(int userId)
    {
        usersId.push_back(userId);
    }
    void whoBorrowedBook()
    {
        int num = usersId.size();
        for (int i = 0; i < num; i++)
        {
            cout << endl << "user id whitch borrowed this book: " << usersId[i] << "  ";
        }
    }
    void searchByPrifx(string pre, vector<Book>& vBook)
    {
        int num = vBook.size();
        cout << " The Book is : \n";
        for (int i = 0; i < num; i++)
        {
            string find_ = vBook[i].name.substr(0, pre.length());
            if (find_ == pre)
            {
                cout << vBook[i].id << "  " << vBook[i].name << "  " << vBook[i].quantity << endl;

            }
        }
    }


    void printbyId(vector<Book> vBook)
    {
        sort(vBook.begin(), vBook.end(), [](Book b1, Book b2) {return b1.id < b2.id; });
        int num = vBook.size();
        for (int i = 0; i < num; i++)
        {
            cout << vBook[i].id << "  " << vBook[i].name << "  "
                << vBook[i].quantity << "   " << usersId.size() << endl;
        }
    }
    void printbyName(vector<Book> vBook)
    {
        sort(vBook.begin(), vBook.end(), [](Book b1, Book b2) {return b1.getName() < b2.getName(); });
        int num = vBook.size();
        for (int i = 0; i < num; i++)
        {
            cout << vBook[i].id << "  " << vBook[i].name
                << "  " << vBook[i].quantity << "   " << usersId.size() << endl;
        }
    }
    string getName()
    {
        return name;
    }
private:
    int id, quantity;
    string name;
    vector<int>usersId;
};

int main()
{
    vector<User>vUser;
    vector<Book>vBook;
    User user;
    Book book;
    int n, id, uId;
    string pre;
    while (true)
    {
        cout << "\n Linrary Menu .\n";
        cout << "1- add Book\n";
        cout << "2- search by using prifx code\n";
        cout << "3- print who borrowed a book by name\n";
        cout << "4- print library by id\n";
        cout << "5- print library by name\n";
        cout << "6- add user\n";
        cout << "7- user borrow book\n";
        cout << "8- user return book\n";
        cout << "9- print users\n";
        cout << "10- Exite\n";
        cin >> n;

        switch (n)
        {
        case 1:
            vBook.push_back(book.add());
            break;
        case 2:
            cout << "enter prefix code: ";
            cin >> pre;
            book.searchByPrifx(pre, vBook);
            break;
        case 3:
            cout << "enter id of the Book:";
            cin >> id;
            vBook[id].whoBorrowedBook();
            break;
        case 4:
            book.printbyId(vBook);
            break;
        case 5:
            book.printbyName(vBook);
            break;
        case 6:
            vUser.push_back(user.add());
            break;
        case 7:
            cout << "enter id of the Book:";
            cin >> id;
            cout << "enter id of the User:";
            cin >> uId;
            vUser[uId].BrrowBook(id);
            vBook[id].BorrowBook(uId);
            break;
        case 8:
            cout << "enter id of the Book:";
            cin >> id;
            cout << "enter id of the User:";
            cin >> uId;
            vUser[uId].returnBook(id);
            vBook[id].returnBook(uId);
            break;
        case 9:
            cout << "enter id of the User:";
            cin >> uId;
            vUser[uId].print();
            break;
        case 10:
            return 0;
            break;
        default:
            cout << "invalid number\n";
            break;
        }
    }
}
