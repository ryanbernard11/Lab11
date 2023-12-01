//include headers and libraries
#include "Library.h"
#include <iostream>
#include <string>

using namespace std;
//implement class functions
  
    //constructor
    //creates a library with no books
    Library::Library()
    {
        int counter=0;
        for(int i=0;i<10;i++)
            books[i]="";
    }

    //Adds the given book to the library and returns zero
    //returns false if the book already exists or if the library
    //  already has 10 books
    bool Library::addBook(string bookName)
    {
        int counter=0;
        for(int i=0;i<10;i++)
        {
            if(books[i]!="")
                counter++;
        }
        for(int i=0;i<counter;i++)
        {
            if(bookName==books[i])
                return false;
        }
        if(counter==10)
            return false;
        books[counter]=bookName;
        return 1;
    }

    //Removes the given book name from the library by setting the 
    //corresponding string to "", and returns true
    //returns false if the library does not have the given book
    bool Library::removeBook(string bookName)
    {
        int index=0;
        int counter2=0;
        int temp;

        for(int i=0;i<10;i++)
        {
            if(books[i]==bookName)
            {
                index=i;
                counter2=1;
                break;
            }
            index=i;
        }
        if(counter2!=1)
            return false;
       for(int i=index;i<9;i++)
            books[i]=books[i+1];
        books[9]="";
        return true;
    }
    //prints the book names
    void Library::print()
    {
        int i=0;
        while(books[i]!=""&& i<10)
        {
            cout<<books[i]<<endl;
            i++;
        }
    }

    int main()
    {
        Library lib;
        string cmd;
        string booktitle;
        bool result;
        
        while(true){
        cout<<"Enter command: ";
        cin>>cmd;
        if(cmd=="p")
        {
            cout<<"Library contents: "<<endl;
            lib.print();
        }
        
        else if(cmd=="a")
        {
            cin>>booktitle;
            result=lib.addBook(booktitle);
            if(result==false)
                cout<<"Cannot add the book."<<endl;
        }
        
        else if(cmd=="r")
        {
            cin>>booktitle;
            result=lib.removeBook(booktitle);
            if(result==false)
                cout<<"Cannot remove the book."<<endl;
        }
        else if(cmd=="q")
            break;
        }
        return 0;
    }
