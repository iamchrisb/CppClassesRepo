#ifndef MAP_H
#define MAP_H
#include "Tree.h"
#include "pair.h"
#include "TreeIterator.h"
#include "MapToFirst.h"
#include <iostream>
using namespace std;

namespace mystl {
template<typename KeyT, typename ValueT , typename OrderT = MapToFirst<KeyT, ValueT> >
class Map{

private:
    Tree<Pair<KeyT,ValueT>, OrderT > m_tree;
public:

    typedef Pair<KeyT,ValueT> typePair;
    typedef TreeIterator<typePair, OrderT> iterator;

    /**
      try to find the pair by key
      if not in, insert
    **/
    ValueT& operator[](const KeyT& key){

        iterator it = this->find(key);

        if(it != m_tree.end()){
            typePair &pair = *it;
            return pair.second();
        }else{
            typePair pairToInsert(key);
            return this->insert(pairToInsert)->second();

        }
    }

    /**
      @param pair to insert
      @return iterator for the inserted node
    **/
    iterator insert(const typePair& pair){
        return m_tree.insert(pair);
    }

    /**
      find a specific value by key
      @param key for the pair
      @return pair
    **/
    iterator find(const KeyT& key){
        return m_tree.find(typePair(key));
    }

    /**
      @return iterator for pair on left side
    **/
    iterator begin(){
        return m_tree.begin();
    }

    /**
      @return iterator for pair on right side
    **/
    iterator end(){
        return m_tree.end();
    }

    /**
      @return iterator for pair on left side
    **/
    iterator first(){
        return m_tree.first();
    }

    /**
      @return iterator for pair on right side
    **/
    iterator last(){
        return m_tree.last();
    }

    /**
      @return the lowest key
    **/
    const KeyT& min(){
        return this->first().it_node()->value().first();
    }

    /**
      @return the greatest key
    **/
    const KeyT& max(){
//        iterator it = this->first();
//        cout << *it.first(); << endl;
//        KeyT k = (*it).first();
//        return k;
        return this->last().it_node()->value().first();
    }

    /**
      allocates the memory
      deletes the map
      sets rood node to 0
    **/
    void clear(){
        m_tree.clear();
    }
};
}
#endif // MAP_H
