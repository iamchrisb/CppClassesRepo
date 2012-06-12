#ifndef MAP_H
#define MAP_H
#include "Tree.h"
#include "pair.h"
#include "TreeIterator.h"
#include "MapToFirst.h"
namespace mystl {
template<typename KeyT, typename ValueT , typename OrderT = MapToFirst<KeyT, ValueT> >
class Map{
private:

    OrderT m_order;
    Pair<KeyT,ValueT> m_pair;
    Tree<Pair<KeyT,ValueT>, OrderT > m_tree;
public:

    typedef Pair<KeyT,ValueT> typePair;
    typedef TreeIterator<typePair, OrderT> iterator;

    Map(KeyT key=KeyT(), ValueT value=ValueT()):m_pair(key, value){}

    iterator insert(const typePair& pair){
        return m_tree.insert(pair);
    }

    ValueT& operator[](const KeyT& key){

        iterator it = this->find(key);

        if(it == m_tree.end()){
            iterator it2=this->insert(key);
            return it2.m_node->value().second();
        }else{
            return this->find(key).m_node->value().second();
        }
    }
    iterator find(const KeyT& key){
        return m_tree.find(typePair(key));
    }
    iterator begin(){
        return m_tree.begin();
    }
    iterator end(){
        return m_tree.end();
    }
    iterator first(){
        return m_tree.first();
    }
    iterator last(){
        return m_tree.last();
    }
    const KeyT& min(){
        return this->first().m_node->value().first();
    }

    const KeyT& max(){
        return this->last().m_node->value().first();
    }
    void clear();
};
}
#endif // MAP_H
