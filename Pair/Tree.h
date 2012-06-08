#ifndef TREE_H
#define TREE_H

#include "TreeNode.h"
#include "stdio.h"

namespace mystl {
    template<typename T , template<typename> class Order = Less >
    class Tree
    {
        typedef TreeNode<T,Order> node;
    private:
        node* m_root;

        void rekInsert(TreeNode<T, Order> tn, const T& value){
            if(value < *(tn.m_value)){
                if(tn.m_left != 0){
                    printf("rek_left");
                    rekInsert(tn.m_left , value);
                }else{
                    TreeNode<T , Order> tmp;
                    tmp.m_value= &value;
                    tmp.m_up = tn.m_up;
                    tn = tmp;
                }
            }else if(value > *(tn.m_value)){
                if(tn.m_right != 0){
                    printf("rek_right");
                    rekInsert(tn.m_right , value);
                }else{
                    TreeNode<T , Order> tmp;
                    tmp.m_value = &value;
                    tmp.m_up = tn.m_up;
                    tn = tmp;
                }
            }
            //return 0;
        }

    public:

        Tree():
            m_root(0)
            {}

        void insert(const T& value){
            if(m_root == 0){
                printf("m_root null\n");
                TreeNode<T , Order>* tmp = new TreeNode<T ,Order>(&value);
//                m_root = tmp;
            }else{
                printf("m_root not null\n");
//                rekInsert(this->m_root,value);
            }
           // return 0;
        }
    };

//    template<typename T , template<typename> class Order = Less >
//    void Tree<T, Order>::insert(T& value){
//        if(this.m_root == 0){
//            TreeNode<T , Order> tn;
//            tn.value() = value;
//            this->m_root = tn;
//        }else {
//            rekInsert(value);
//        }
//        return 0;
//    }

}

#endif // TREE_H
