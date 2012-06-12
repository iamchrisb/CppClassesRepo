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
        node* m_root;
        node* m_end;
    private:
        Order m_order;



        void deleteNode(node* tn){
            if(tn == m_root && m_root->m_left == 0 && m_root->m_right == 0){
                m_root=0;
                delete m_root;
            }else{
                node tmp = tn->findFirst();
                if(tmp.m_right != 0){
                    deleteNode(tmp.m_right);
                }else{
                    node* tmpup = tmp.m_up;
                    printf("deleting: %d", tmp.m_value);
                    delete tmp;

                    deleteNode(tmpup);
                }
            }

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
            if(m_root!=0){
                deleteNode(&(m_root->findFirst()));
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
            //printf("find first: %d\n", n->m_value);
            return it;
        }
        iterator last(){
            node* n = &(m_root->findLast());
            iterator it(n, this);
            //printf("find first: %d\n", n->m_value);
            return it;
        }
        iterator find(const T& value){
            node* n = (m_root->find(value));
            if(n){
            iterator it(n, this);
            //printf("find first: %d\n", n->m_value);
            return it;
            } else {
                return this->end();
            }
        }

    };
}

#endif // TREE_H
