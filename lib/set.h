// necessary includes can go here
#ifndef SET_H_
#define SET_H_
#include "map.h"


template <class T>
class Set {
  public: 
    Set ();                     // constructor for an empty set
    Set (const Set<T> & other); // copy constructor, making a deep copy
    ~Set ();                    // destructor

    void add (const T & item); 
      /* Adds the item to the set. 
         Throws an exception if the set already contains the item. */

    void remove (const T & item);
      /* Removes the item from the set.
         Throws an exception if the set does not contain the item. */

    bool contains (const T & item) const;
      /* Returns true if the set contains the item, and false otherwise. */

    int size () const;
      /* Returns the number of elements in the set. */

    bool isEmpty () const;
      /* Returns true if the set is empty, and false otherwise. */

    Set<T> setIntersection (const Set<T> & other) const;
      /* Returns the intersection of the current set with other.
         That is, returns the set of all items that are both in this
         and in other. */

    Set<T> setUnion (const Set<T> & other) const;
      /* Returns the union of the current set with other.
         That is, returns the set of all items that are in this set
         or in other (or both).
         The resulting set should not contain duplicates. */

    /* The next two functions together implement a suboptimal version
       of what is called an "iterator".
       Together, they should give you a way to loop through all elements
       of the set. The function "first" starts the loop, and the function
       "next" moves on to the next element.
       You will want to keep the state of the loop inside a private variable.
       We will learn the correct way to implement iterators soon, at 
       which point you will replace this.
       For now, we want to keep it simple. */

    T* first ();
      /* Returns the pointer to some element of the set, 
         which you may consider the "first" element.
         Should return NULL if the set is empty. */

    T* next ();
      /* Returns the pointer to an element of the set different from all 
         the ones that "first" and "next" have returned so far. 
         Should return NULL if there are no more element. */

  private:
    List<T> internalStorage;
    int index;
    // other private variables you think you need.
};
#endif

template<class T>
Set<T>::Set(){
  index = 0;
}

template<class T>
Set<T>::Set(const Set<T>& other) : 
              internalStorage(other.internalStorage), index(0){
}

template<class T>
Set<T>::~Set(){
}

template<class T>
void Set<T>::add(const T & item){
  if (contains(item)==true){
    cout << item;
    throw logic_error (" already exists.");
  }
  internalStorage.insert(size(), item);
}

template<class T>
void Set<T>::remove(const T & item){
  if (contains(item)==false){
    cout << item;
    throw logic_error (" doesn't exist.");
  }
  for (int i = 0; i < size(); i++){
    if(internalStorage.get(i) == item){
      internalStorage.remove(i);
    }
  }
}

template<class T>
bool Set<T>::contains(const T & item) const{
  for (int i = 0; i < size(); i++){
    if(internalStorage.get(i) == item)
      return true; 
  }
  return false;
}

template<class T>
int Set<T>::size() const{
  return internalStorage.size();
}

template<class T>
bool Set<T>::isEmpty() const{
  if (internalStorage.size()!=0)
    return false;
  else
    return true;
}

template<class T>
Set<T> Set<T>::setIntersection(const Set<T> & other) const{
  Set<T> newset; 
  for(int i = 0; i < other.size(); i++){
    for(int j = 0; j < size(); j++){
      if (contains(other.internalStorage.get(i)) == contains(internalStorage.get(j)))
        newset.add(other.internalStorage.get(i));
      break;
    }
  }
  return newset;
}

template<class T>
Set<T> Set<T>::setUnion(const Set<T> & other) const{
  Set<T> newset;
  for(int i = 0; i < other.size(); i++)
    newset.add(other.internalStorage.get(i));
  for(int i = 0; i < size(); i++){
    if(newset.contains(internalStorage.get(i)))
      continue;
    else
      newset.add(internalStorage.get(i));
  }
  return newset;
}

template<class T>
T* Set<T>::first(){
  if(isEmpty()==true)
    return NULL;
  return &internalStorage.get(0);
}

template<class T>
T* Set<T>::next(){
  index++;
  if(isEmpty()==true||index == size()){
    index = 0;
    return NULL;
  }
  return &internalStorage.get(index);
}