// necessary includes can go here
#ifndef STLSET_H_
#define STLSET_H_
#include <set>

using namespace std;


template <class T>
class Set : public set<T> {
  public: 
    Set () {}                     // constructor for an empty set
    ~Set () {}                    // destructor

    Set<T> setIntersection (const Set<T> & other) const{
      /* Returns the intersection of the current set with other.
         That is, returns the set of all items that are both in this
         and in other. */
      Set<T> newset;
      for(typename set<T>::iterator it = other.begin(); it!=other.end(); ++it){
        for(typename set<T>::iterator it2 = this->begin(); it2!=this->end(); ++it2){
          if(this->find(*it)!=other.end() && other.find(*it2)!=this->end()) 
            newset.insert(*it);
        break;
        }
      }
      return newset;
    }

    Set<T> setUnion (const Set<T> & other) const {
      /* Returns the union of the current set with other.
         That is, returns the set of all items that are in this set
         or in other (or both).
         The resulting set should not contain duplicates. */
      Set<T> newset;
      for(typename set<T>::iterator it = other.begin(); it!=other.end(); ++it){
        newset.insert(*it);
      }
      for(typename set<T>::iterator it2 = this->begin(); it2!=this->end(); ++it2){     
        if(newset.find(*it2)!=newset.end()){
          continue;
        } 
        else{
          newset.insert(*it2);
        }
      }
      return newset;
    }
};
#endif
/*
template<class T>
Set<T> Set<T>::setIntersection(const Set<T> & other) const{
  Set<T> newset;
  for(int i = 0; i < other.size(); i++){
    for(int j = 0; j < size(); j++){
      if (contains(other.internalStorage.get(i)) && contains(internalStorage.get(j)))   //if both items in each set returns true..
        newset.add(other.internalStorage.get(i));   //add it to the newset and then return it
      break;
    }
  }
  return newset;
}

template<class T>
Set<T> Set<T>::setUnion(const Set<T> & other) const{
  Set<T> newset;
  for(int i = 0; i < other.size(); i++)
    newset.add(other.internalStorage.get(i)); //add everything from the first set to the newset
  for(int i = 0; i < size(); i++){
    if(newset.contains(internalStorage.get(i))) //check if the newset contains everything from the other set
      continue;                                  //if it does then just continue
    else
      newset.add(internalStorage.get(i));       //if it doesn't then add 
  }
  return newset;
}
*/