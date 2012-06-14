#ifndef TREEITERATOR_H
#define TREEITERATOR_H

//#include "TreeNode.h"
#include "stdio.h"

namespace mystl {

    template<typename T , typename Order = Less<T> >
    class TreeIterator
    {
    public:
        typedef TreeNode<T,Order> node;
        typedef Tree<T,Order> tree;

    protected:
        Order m_order;
        tree* m_tree;
        node* m_node;

        node* getLeftSize(node* n){
            if(n->m_left == 0){
                return n;
            }else{
                return getLeftSize(n->m_left);
            }
        }
        node* getRightSize(node* n){
            if(n->m_right == 0){
                return n;
            }else{
                return getRightSize(n->m_right);
            }
        }
        node* getUpSize(node* n){
            if(!m_order(n->m_up->m_value, n->m_value)){
                return n->m_up;
            }else{
                getUpSize(n->m_up);
            }
        }
        node* getDownSize(node* n){
            if(m_order(n->m_up->m_value, n->m_value)){
                return n->m_up;
            }else{
                getDownSize(n->m_up);
            }
        }

    public:
        TreeIterator(node* treeNode):m_node(treeNode){}
        TreeIterator(node* treeNode=0, tree* t=0):m_node(treeNode),m_tree(t){}

        /**
          getter for m_node
        **/
        node* it_node(){ return m_node; }
        T& operator*(){
            return m_node->m_value;
        }

        /**
          operator overloading
          @return the specific value of the m_node
        **/
        T* operator->(){
            return &(m_node->m_value);
        }

        /**
          operator overloading
          @return gives back an iterator of the current node
        **/
        TreeIterator<T,Order>& operator++(){
            if(m_tree->root() == 0){
                m_node = m_tree->node_end();
                return *this;
            }
            if(m_node == m_tree->node_end()){
                m_node = m_tree->first().m_node;
                return *this;
            }
            if(m_node == m_tree->last().m_node){
                m_node = m_tree->node_end();
                return *this;
            }

                if(m_node->m_right){
                    m_node = getLeftSize(m_node->m_right);
                    return *this;
                }else{
                    if(m_node == m_tree->root()){
                        m_node = m_tree->root();
                        return *(new TreeIterator<T,Order>);
                    }

                    m_node = getUpSize(m_node);
                    return *this;
                }
        }

        /**
          operator overloading
          @return gives back an iterator of the current node
        **/
        TreeIterator<T,Order>& operator--(){

            if(m_node == m_tree->begin().m_node){

                m_node = m_tree->first().m_node;
                return *this;
            }

            if(m_node == m_tree->node_end()){

                m_node = m_tree->last().m_node;
                return *this;
            }
                if(m_node->m_left){

                    m_node = getRightSize(m_node->m_left);
                    return *this;
                }else{

                    if(m_node == m_tree->root()){
                        m_node = m_tree->root();
                         //printf("node: %d",m_node->m_value );
                         return *(new TreeIterator<T,Order>);
                    }
                    m_node = getDownSize(m_node);

                    return *this;
                }
            //}
        }

        /**
          operator overloading
          @return bool - compares two iterators, true if equal
        **/
        bool operator==(const TreeIterator<T,Order> &rhs){
            return (m_tree == rhs.m_tree && m_node == rhs.m_node);
        }

        /**
          operator overloading
          @return bool - compares two iterators, true if not equal
        **/
        bool operator!=(const TreeIterator<T,Order> &rhs){
            return (m_tree != rhs.m_tree || m_node != rhs.m_node);
        }
    };
}

#endif // TREEITERATOR_H
