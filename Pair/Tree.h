#ifndef TREE_H
#define TREE_H

#include "TreeNode.h"
#include "TreeIterator.h"
#include "stdio.h"

namespace mystl {
template<typename T , template<typename> class Order = Less >
class Tree
{
public:
    typedef TreeNode<T,Order> node;
    typedef TreeIterator<T, Order> iterator;
    node* m_root;
    node* m_end;
private:
    Order<T> m_order;



    void deleteNode(node* tn){
        printf("clear start - tn: %d \n" , tn->value());
        if(tn->m_left != 0){
            deleteNode(tn->m_left);
        }
        if(tn->m_right){
            deleteNode(tn->m_right);
        }
        delete tn;
    }

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

    Tree():
        m_root(0),m_end(0)
    {}

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

    void clear(){
        //            iterator start = this->begin();
        //            while(start != this->end()){
        //                node * tmp = start.m_node;
        //            }
        if(m_root!=0){
            deleteNode(m_root);
        }
    }

    iterator begin(){
        return this->first();
    }
    iterator end(){
        iterator it(m_end, this);
        return it;
    }
    iterator first(){
        node* n = &(m_root->findFirst());
        iterator it(n, this);
        return it;
    }
    iterator last(){
        node* n = &(m_root->findLast());
        iterator it(n, this);
        return it;
    }
    iterator find(const T& value){
        node* n = &(m_root->find(value));
        iterator it(n, this);
        return it;
    }

};
}

#endif // TREE_H
