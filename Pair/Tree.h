#ifndef TREE_H
#define TREE_H

#include "TreeNode.h"
#include "TreeIterator.h"
#include "stdio.h"

namespace mystl {
template<typename T , typename Order = Less<T> >
class Tree
{
public:
    typedef TreeNode<T,Order> node;
    typedef TreeIterator<T, Order> iterator;

protected:
    node* m_root;
    node* m_end;

    Order m_order;

    /**
      starting at root
      going through all nodes
      deleting first to last
    **/
    void deleteNode(node* tn){
        if(tn->m_left != 0){
            deleteNode(tn->m_left);
        }
        if(tn->m_right){
            deleteNode(tn->m_right);
        }
        delete tn;
    }

    /**
      inserts values in the tree
    **/
    node* rekInsert(node* tn, const T& value){
        if(m_order(value , tn->m_value )){
            if(tn->m_left != 0){
                return rekInsert(tn->m_left , value);
            }else{
                node* tmp = new node(value);
                tmp->m_up = tn;
                tn->m_left = tmp;
                return tn->m_left;
            }
        }else if(m_order(tn->m_value , value )){
            if(tn->m_right != 0){
                return rekInsert(tn->m_right , value);
            }else{
                node * tmp = new node(value);
                tmp->m_up = tn;
                tn->m_right = tmp;
                return tn->m_right;
            }
        }else{
            return tn;
        }
    }

public:

    node* root(){ return m_root; }
    node* node_end(){ return m_end; }

    /**
       Default Constructor
    **/
    Tree():
        m_root(0),m_end(0)
    {}

    /**
       this method inserts a value into a tree,
       if the root-node is 0, the value becomes
       the root-node
       @value is the value to save in the tree
       @return the specific iterator for the node
    **/
    iterator insert(const T& value){
        if(m_root == 0){
            node * tmp = new node(value);
            m_root = tmp;
            iterator it(m_root , this);
            return it;
        }else{
            iterator it(rekInsert(m_root, value) , this);
            return it;
        }
    }

    /**
       allocates the memory of the tree
       sets the root-node to 0
    **/
    void clear(){
        printf("clear start \n");
        if(m_root!=0){
            printf("root not null \n");
            deleteNode(m_root);
        }
        m_root = 0;
    }

    /**
       most left node
       @return the iterator for the
    **/
    iterator begin(){
        if(m_root == 0){
            return this->end();
        }
        return this->first();
    }

    /**
       most right node
       @return the iterator for the
    **/
    iterator end(){
       // iterator it(m_end, this);
        return iterator(m_end, this);
    }

    /**
       most left node
       @return the iterator for the
    **/
    iterator first(){
        if(m_root == 0){
            return this->end();
        }
        node* n = m_root->findFirst();
        iterator it(n, this);
        return it;
    }

    /**
       most right node
       @return the iterator for the
    **/
    iterator last(){
        if(m_root == 0){
            return this->end();
        }
        node* n = m_root->findLast();
        iterator it(n, this);
        return it;
    }

    /**
       specific node, if found,
       else return the end-iterator
       @value the value to find
       @return the iterator for the
    **/
    iterator find(const T& value){
        node* n = m_root->find(value);
        if(n){
            iterator it(n, this);
            return it;
        }else{
            return end();
        }
    }

};
}

#endif // TREE_H
