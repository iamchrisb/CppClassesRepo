#ifndef TREE_H
#define TREE_H

#include "TreeNode.h"
#include "TreeIterator.h"
#include "stdio.h"

namespace mystl {
    template<typename T , template<typename> class Order = Less >
    class Tree
    {
        typedef TreeNode<T,Order> node;
        typedef TreeIterator<T, Order> iterator;

    private:
        Order<T> m_order;
        node* m_root;

        void deleteNode(node* tn){
            if(tn == m_root && m_root->m_left == 0 && m_root->m_right == 0){
                m_root=0;
            }else{
                node tmp = tn->findFirst();
                if(tmp.m_right != 0){
                    deleteNode(tmp.m_right);
                }else{
                    node* tmpup = tmp.m_up;
                    printf("deleting: %d", tmp.m_value);
                    tmp = 0;

                    deleteNode(tmpup);
                }
            }

        }

        node* rekInsert(node* tn, const T& value){
            if(m_order(value , tn->m_value )){
                if(tn->m_left != 0){
                    printf("REK LEFT | value: %d | tn->m_value: %d \n" , value , tn->m_value);
                    //iterator it();
                    return rekInsert(tn->m_left , value);
                }else{

//                    printf("NOT REK LEFT | value: %d | tn->m_value %d \n" , value , tn->m_value);
                    node* tmp = new node(value);
                    tn->m_left = tmp;
                    //iterator it();
                    return tn->m_left;
                }
            }else if(m_order(tn->m_value , value )){
                if(tn->m_right != 0){
                    printf("rek right \n");
                    //iterator it();
                    return rekInsert(tn->m_right , value);

                }else{

//                    printf("not rek right \n");
                    node * tmp = new node(value);
                    tn->m_right = tmp;
                    //iterator it();
                    return tn->m_right;
                }
            }else{
                printf("the same\n");
                //iterator it(tn);
                return tn;
            }

        }

    public:

        Tree():
            m_root(0)
            {}

        iterator insert(const T& value){
            iterator it(rekInsert(m_root, value));
            return it;
        }

        void clear(){
            if(m_root!=0){
                deleteNode(&(m_root->findFirst()));
            }

        }
    };
}

#endif // TREE_H
