#ifndef TREENODE_H
#define TREENODE_H

namespace mystl {

    template <typename T, template<typename> class Order> class Tree;
    template <typename T, template<typename> class Order> class TreeIterator;

    template<typename T , template<typename> class Order = Less >
    class TreeNode
    {
       typedef TreeNode<T,Order> node;

       friend class Tree<T , Order>;

    protected:
        TreeNode<T, Order>* m_left;
        TreeNode<T , Order>* m_right;
        TreeNode<T , Order>* m_up;

    private:
        Order<T> m_order;
        T m_value;

        TreeNode<T , Order>& findFirstRek(TreeNode<T , Order>& t){
            if(t->m_up == 0){
                return t;
            }else{
                return findFirstRek(t->m_up);
            }
        }

        TreeNode<T , Order>* findByValue(TreeNode<T , Order>* tn, T value){
            if(tn->m_value > value){
                if(tn->m_left != 0){
                    printf("rek left \n");
                    return findByValue(m_left , value);
                }else{
                    printf("not rek left \n");
                    node* tmp = new node(value);
                    tn->m_left = tmp;
                    return tmp;
                }
            }else if(tn->m_value < value ){
                if(tn->m_right != 0){
                    printf("rek right \n");
                    return findByValue(m_right , value);
                }else{
                    printf("not rek right \n");
                    node * tmp = new node(value);
                    tn->m_right = tmp;
                    return tmp;
                }
            }else{
                printf("the same\n");
                return tn;
            }
        }

    public:
        T* value(){ return m_value; }
        void value(const T& value){ m_value = value;}
        TreeNode<T , Order>* find(const T&value){
            return findByValue(this , value);
        }

        TreeNode<T , Order>& findFirst(){
            findFirstRek(this);
        }

        TreeNode<T , Order>& findLast(){

        }

        TreeNode(const T &value = 0):m_left(0), m_right(0),m_up(0), m_value(value)
        {
//            printf("TreeNode Konstruktor");
        }

    };
}

#endif // TREENODE_H
