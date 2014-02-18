// necessary includes can go here
#ifndef LIST_H_
#define LIST_H_
#include <string.h>
using namespace std; 

template <class T>
struct Item
{
  T value;
  Item<T> *prev, *next;
};

template <class T>
class List
{
  public:
    List ();   // constructor

    List (const List<T> & other);
      // A copy constructor which performs a deep copy.

    List<T> & operator= (const List<T> & other);
      // An assignment operators.

    ~List ();  // destructor

    int size () const;  // returns the number of elements in the list

    void insert (int position, const T & val);
      /* Inserts val into the list before the given position,
         shifting all later items one position to the right.
         Inserting before 0 (i.e., position = 0) makes it the 
         new first element.
         Inserting before size() (i.e., position = size()) makes 
         it the new last element.
         Your function should throw an exception if position is
         outside the legal range, which would be 0-size() here. */

    void remove (int position);
      /* Removes the item from the given position, shifting all
         later items one position to the left.
         Your function should throw an exception if position is
         outside the legal range. */

    void set (int position, const T & val);
      /* Overwrites the given position with the given value.
         Does not affect any other positions.  
         Your function should throw an exception if position is
         outside the legal range. */

    T& get (int position) const;
      /* Returns the item at the given position.
         Your function should throw an exception if position is
         outside the legal range. */

    private:
      Item<T> *head;
      Item<T> *tail;
      int _size;
      Item<T> *newptr;
      /* You may add further private data fields or helper methods if 
         you choose. You should not alter the public signature. */
};
#endif

template<class T>
List<T>::List()
{
  //initialize list to empty
  head = NULL;
  tail = NULL;
  newptr = NULL;
  _size = 0;
}

template<class T>
List<T>::List(const List<T> & other) : 
                head(NULL), tail(NULL), _size(0), newptr(NULL){
  for (int i = 0; i < other._size; i++){
    insert(i, other.get(i));
  }
}

template<class T>
List<T>& List<T>::operator=(const List<T> & other){
  if(this == &other) return *this; //check if its already equal to itself
  if(head != NULL) delete[] head; //clean up what was already in it
  if(newptr != NULL) delete[] newptr; //clean up what was already in it
  if(tail != NULL) delete[] tail; //clean up what was already in it
  _size = 0;
  for (int i = 0; i < other._size; i++){ //copies each item over
    insert(i, other.get(i));
  }
  return *this;
}

template<class T>
List<T>::~List(){
  delete newptr;
  delete head;  
  //delete tail; 
}

template<class T>
int List<T>::size() const{
  return _size;
}

template<class T>
void List<T>::insert(int position, const T & val){
  //dynamically allocate for new value
  newptr = new Item<T>;
  newptr->value = val;

  Item<T> *temp; //temporary to modify head/tail without messing up the list

  if(position == 0){
    if(head == NULL){
      newptr->prev = NULL;
      newptr->next = NULL;
      head = newptr;  //when list is empty
      tail = newptr;  //set head and tail to same value b/c this will have to be the first list item
    }
    else{
      temp = head;
      newptr->next = head;  //sets new value as head
      head->prev = newptr; //old head is linked to new head
      newptr->prev = NULL;
      head = newptr;    
    }
  }
  else if (position == size()){
    temp = tail;
    temp->next = newptr;  //adds new value
    newptr->prev = tail;  //links the values
    tail = newptr;      //new value becomes tail
    tail->next = NULL;
  }
  else if (position > 0 && position < size()){
    temp = head;
    Item<T> *temp2;
    for (int i = 0; i < position; i++){ //reaching position
      temp2 = temp;       //finds adjacencies
      temp = temp->next;
    }
    newptr->next = temp;    //creates space between temp and temp2
    newptr->prev = temp2;
    temp2->next = newptr;
    temp->prev = newptr;    //link everything together
  }
  else{
    throw logic_error ("Out of Bounds. Position was not between 0 and size.\n");
  } 
  _size++; //size of list increases 
} 

template<class T>
void List<T>::remove(int position){
  Item<T> *temp, *temp2;
  if(position == 0){
    temp = head;
    head = head->next;    //sets new head 
    head->prev = NULL;
    delete temp;

  }
  else if(position == size()-1){ 
    temp = tail;
    tail = tail->prev;    //sets new tail
    tail->next = NULL;
    delete temp;
  }
  else if (position > 0 && position < size()-1){
    temp = head;
    for (int i = 0; i < position; i++){ //shifts all items to the left
      temp2 = temp;
      temp = temp->next;
    }
    temp->prev = temp2->prev;   //kind of "overlaps" the position to be deleted
    temp2->next = temp->next;   //by setting the temps prev and nexts equal
    delete temp;
  } 
  else{
    throw logic_error ("Out of Bounds. Position was not between 0 and size-1.\n");
  }
  _size--;
}

template<class T>
void List<T>::set(int position, const T & val){
  if (position < 0 || position > size()-1){
    throw logic_error ("Out of Bounds. Position was not between 0 and size-1.\n");
  }
  Item<T> *temp;
  temp = head;
  for (int i = 0; i < position; i++)    //finds position and replaces the value
    temp = temp->next;
  temp->value = val;
}

template<class T>
T& List<T>::get(int position) const{
  if (position < 0 || position > size()-1){
    throw logic_error ("Out of Bounds. Position was not between 0 and size-1.\n");
  }
  Item<T> *temp;
  temp = head;
  for (int i = 0; i < position; i++)    //finds position and returns value
    temp = temp->next;
  return temp->value; 
}
