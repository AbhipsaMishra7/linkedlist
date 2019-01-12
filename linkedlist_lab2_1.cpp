//implementing singly linked list

#include<iostream>
using namespace std ;

//custom define my linked list

class Entry 
{
    public : // so that stuff below are accessible outside this class as well
    //Data
    int data ; //setting integer type data of each entry
    //pointer to next entry
    Entry *pointer;
    //constructor to set default value of pointer to null;
    Entry ()
    {
        pointer=NULL;
    }
};

class LinkedList
{
    public :
    Entry *head; //defining head, an entry type pointer
    Entry *tail; //same^
    //setting head and tail value to null
    LinkedList ()
    {
        head = NULL;
        tail = NULL;
    }
    
    //insertion
    
    void insert (int value)
    {
        Entry *temp= new Entry(); //pehla entry 
        temp->data=value; //to insert data in this entry
        
        if (head==NULL)
        {
            this->head=temp; //first entry only
        }
        else 
        {
            tail->pointer=temp; //any other entry
        }
        this->tail=temp;
    }
    
    //instert at given location
    void insertAt (int posn, int data)
    {
        //reach the place before the given position
        Entry *current=head;
        
        int i=1;
        while (i<posn-1)
        {
            i++;
            current=current->pointer;
        }
        
        //create new entry
        Entry *numb= new Entry ();
        numb->data=data;
        numb->pointer=current->pointer;
        current->pointer=numb;
    }
    
    //Deletion of last element
    void del ()
    {
        Entry *temp=tail; //store tail in temp
        Entry *current=head; //the entry before tail has to point to null
        while (current->pointer!=tail)
        {
            current=current->pointer;
        }
        current->pointer=NULL;
        tail=current;
        delete temp;
    }
    
    //count items
    int countItems()
    {
        Entry*current=head ;
        int length=0;
        while (current !=NULL)
        {
            length++;
            current=current->pointer;
        }
        return length;
    }
    
    //Delete at a certain location
    void deleteAt(int posn)
    {
        //reach the place before the required location
        Entry *current=head;
        int i=1;
        
        while (i<posn-1)
        {
            i++;
            current=current->pointer;
        }
        
        //copy the entry to be deleted
        Entry*temp=current->pointer;
        //reach the next place after the requierd location
        Entry *next=head;
        int j=0;
        
        while (j<posn)
        {
            j++;
            next=next->pointer;
        }
        
        //pointer of the entry before the required location will point to the one after it
        current->pointer=next;
        delete temp;
    }
    
    //display
    void display ()
    {
        Entry *current=head;
        
        while(current!=NULL)
        {
            cout<<current->data << "->" ;
            current=current->pointer;
        }
        
        cout << "NULL" << endl;
    }
};

int main ()
{
    //object of the class
    LinkedList l1;
    //enter values
    l1.insert(1);
    l1.insert(2);
    l1.insert(3);
    l1.insert(4);
    //display output
    l1.display();
    cout << "the number of items before deletion =" <<l1.countItems()<<endl;
    //use of delete
    l1.del();
    l1.display();
    cout<<"The number of items after deletion="<<l1.countItems()<<endl;
    //use of insertAt
    l1.insertAt(2,5);
    l1.display();
    cout<<"The number of items after insertion at position="<<l1.countItems()<<endl;
    //use of deleteAt
    l1.deleteAt(3);
    l1.display();
    cout<<"The number of items after delete at position="<<l1.countItems()<<endl;
    
    return 7;
}
