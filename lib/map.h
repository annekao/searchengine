// necessary includes can go here
#ifndef MAP_H_
#define MAP_H_
#include "list.h"
using namespace std;

template<class keyType, class valueType>
struct Pair{  //associate the two values
  keyType k;
  valueType v;
};

template <class keyType, class valueType>
//keyType: email; valueType: name
class Map
{
  public:
    Map ();  // constructor for a new empty map

    ~Map (); // destructor

    int size () const; // returns the number of key-value pairs

    void add (const keyType & key, const valueType & value); 
      /* Adds a new association between the given key and the given value.
         If the key already has an association, it should throw an exception.
      */

    void remove (const keyType & key);
     /* Removes the association for the given key.
        If the key has no association, it should throw an exception. */

    valueType& get (const keyType & key) const;
     /* Returns the value associated with the given key.
        If the key has no association, it should throw an exception. */

    int find(const keyType & key) const;

  private:
    List< Pair<keyType,valueType> > internalStorage;   //list of pairs

     /* You should store all of your associations inside one list.
        It is part of your assignment to figure out what types you 
        should store in that list.
        (Hint: you may need to add an additional definition.) */

     /* If you like, you can add further data fields and private
        helper methods.
        In particular, a 'find' function could be useful, which
        will find the index in the list at which a given key sits. */
};
#endif

template <class keyType, class valueType>
Map<keyType,valueType>::Map(){}

template <class keyType, class valueType>
Map<keyType,valueType>::~Map(){
  //delete map
}

template <class keyType, class valueType>
int Map<keyType,valueType>::size() const{
  return internalStorage.size();  //size of list is the same as size of map
}

template <class keyType, class valueType>
void Map<keyType,valueType>::add(const keyType & key, const valueType & value){
  Pair<keyType,valueType> tmp;
  if (find(key)!=-1){
    cout << key;
    throw logic_error (" already has an association.");
  }
  tmp.k = key;      //p is a temp that stores into the list
  tmp.v = value;
  internalStorage.insert(size(), tmp);  //stores in the back
}

template <class keyType, class valueType>
void Map<keyType,valueType>::remove(const keyType & key){
  if (find(key)==-1){
    cout << key;
    throw logic_error (" has no association.");
  }
  internalStorage.remove(find(key));  //removes at position
}

template <class keyType, class valueType>
valueType& Map<keyType,valueType>::get(const keyType & key) const{
  if (find(key)==-1){
    cout << key;
    throw logic_error (" has no association.");
  }
  return internalStorage.get(find(key)).v;  //returns value at find(key) index
}

template <class keyType, class valueType>
int Map<keyType,valueType>::find(const keyType & key) const{
  for (int index = 0; index < size(); index++){       //loops through the list 
    if (internalStorage.get(index).k == key)      //returns index when it finds match
      return index;
  }
  return -1;    //returns -1 when no match... used for throwing
}
