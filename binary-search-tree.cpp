//Requires better algorithm. Currently naive
template <typename T>
class BinarySearchTree{
private:
    struct Node{
        T value{0};
        Node* lchild{nullptr};
        Node* rchild{nullptr};
        Node* parent{nullptr};

        ~Node(){
            if(lchild != nullptr){
                delete lchild;
            }
            if(rchild != nullptr){
                delete rchild;
            }
        }
    };

    Node* root{nullptr};

public:
    BinarySearchTree(){}
    ~BinarySearchTree(){
        delete root;
    }

    void Insert(const T& value_){
        if(root == nullptr){
            root = new Node();
            root->value = value_;
            return;
        }
        Node* curr{root};
        while(curr->value != value_){
            if(value_ < curr->value){
                if(curr->lchild == nullptr){
                    curr->lchild = new Node();
                    curr->lchild->parent = curr;
                    curr->lchild->value = value_;
                    break;
                }
                curr = curr->lchild;
            } else {
                if(curr->rchild == nullptr){
                    curr->rchild = new Node();
                    curr->rchild->parent = curr;
                    curr->rchild->value = value_;
                    break;
                }
                curr = curr->rchild;
            }
        }
        return;
    }

    //I pray this one actually works and isn't the broken version
    void Remove(const T& value_){
        if(root == nullptr){
            return;
        }
        Node* curr{root};
        while(curr->value != value_){
            if(value_ < curr->value){
                if(curr->lchild != nullptr){
                    curr = curr->lchild;
                } else {
                    return;
                }
            } else {
                if(curr->rchild != nullptr){
                    curr = curr->rchild;
                } else {
                    return;
                }
            }
        }
        if(curr->lchild == nullptr){
            if(curr->rchild == nullptr){
                if(curr->parent != nullptr){
                    if(curr->value < curr->parent->value){
                        curr->parent->lchild = nullptr;
                    } else {
                        curr->parent->rchild = nullptr;
                    }
                } else {
                    root = nullptr;
                }
                delete curr;
            } else {
                if(curr->parent != nullptr){
                    if(curr->value < curr->parent->value){
                        curr->parent->lchild = curr->rchild;
                    } else {
                        curr->parent->rchild = curr->rchild;
                    }
                    curr->rchild->parent = curr->parent;
                } else {
                    root = curr->rchild;
                    root->parent = nullptr;
                }
                curr->rchild = nullptr;
                delete curr;
            }
        } else {
            if(curr->rchild == nullptr){
                if(curr->parent != nullptr){
                    if(curr->value < curr->parent->value){
                        curr->parent->lchild = curr->lchild;
                    } else {
                        curr->parent->rchild = curr->lchild;
                    }
                    curr->lchild->parent = curr->parent;
                } else {
                    root = curr->lchild;
                    root->parent = nullptr;
                }
                curr->lchild = nullptr;
                delete curr;
            } else {
                Node* tmp{curr};
                curr = curr->lchild;
                while(curr->rchild != nullptr){
                    curr = curr->rchild;
                }
                tmp->value = curr->value;
                if(curr->lchild == nullptr){
                    if(curr->parent != nullptr){
                        if(curr->value < curr->parent->value){
                            curr->parent->lchild = nullptr;
                        } else {
                            curr->parent->rchild = nullptr;
                        }
                    } else {
                        root = nullptr;
                    }
                    delete curr;
                } else {
                    if(curr->parent != nullptr){
                        if(curr->value < curr->parent->value){
                            curr->parent->lchild = curr->lchild;
                        } else {
                            curr->parent->rchild = curr->lchild;
                        }
                        curr->lchild->parent = curr->parent;
                    } else {
                        root = curr->lchild;
                        root->parent = nullptr;
                    }
                    curr->lchild = nullptr;
                    delete curr;
                }
            }
        }
        return;
    }

    //Returns a pointer to an object of type T if found.
    //Makes it so you can get data from custom structs where
    //not everything is considered by T::operator < (const T&) const
    //or T::operator != (const T&) const
    T* Query(const T& value_) const{
        if(root == nullptr){
            return nullptr;
        }
        Node* curr{root};
        while(curr->value != value_){
            if(curr->value < value_){
                if(curr->lchild != nullptr){
                    curr = curr->lchild;
                } else {
                    return nullptr;
                }
            } else {
                if(curr->rchild != nullptr){
                    curr = curr->rchild;
                } else {
                    return nullptr;
                }
            }
        }
        return new T{curr->value};
    }
};
