
//Implementacion de treap explicito, no-persistente, no-aumentado
//Similar a set
#include <stdlib.h>

template <typename T> 
struct treap {
    T value;
    int p;
    treap * l, *r;
    treap () {
        l=r=NULL;
        p=rand();
    }
    treap (T _val) {
        l=r=NULL;
        p=rand();
        value=_val;
    }
};

//Combina a y b, guarda el resultado en des. MODIFICA a y b
template <typename T> 
void treap_merge(treap<T> * &des,treap<T> * a, treap<T> *b) {
    if (!a) {
        des=b;
        return;
    }
    if (!b) {
        des=a;
        return;
    }

    if (a->p < b->p) {
        des=a;
        treap_merge(des->r,des->r,b);
    } else {
        des=b;
        treap_merge(des->l,a, des->l);
    }    
}

//Divide src por val y lo guarda en {a,b} de forma que b incluye val. MODIFICA a y b
template <typename T> 
void treap_split(treap<T> *src, treap<T> *&a,treap<T>*&b,T val ){
    if (!src) {
        a=b=NULL;
        return;
    }
    if (src->value < val) {
        a=src;
        treap_split(a->r, a->r, b,val);
    } else {
        b=src;
        treap_split(b->l,a,b->l,val);
    }

}
template <typename T> 
void treap_print(treap<T> *cur ){
    if (!cur) {
        return;
    }
    treap_print(cur->l);
    //cout << cur->value<<" ";
    treap_print(cur->r);

}
template <typename T> 
treap<T> * treap_find(treap<T>*src,T target) {
    treap<T> *cur=src;
    while (cur!=NULL) {
        if (cur->value==target)break;
        if (target < cur->value)
            cur = cur->l;
        else
            cur=cur->r;
    }
    return cur;
}

template <typename T> 
void treap_insert(treap<T>*src,T target) {    
        treap<T> *n=new treap<T>(target),*a,*b;
        treap_split(src,a,b,target);
        treap_merge(src, a,n);
        treap_merge(src, src,b);
}
//NOTA, este erase esta muy chafa y causa memory-leak, tal vez TLE?
template <typename T> 
void treap_erase(treap<T>*src,T target) {
    treap<T>*n=treap_find(src,target),*tmp;
    if (n!=NULL){
        treap_merge(tmp,n->l,n->r);
        *n=*tmp;
    }

}
///UNTESTED
template <typename T> 
treap<T> * treap_lowerbound(treap<T>*src,T target) {
    treap<T> *a,*b,*c;
    treap_split(src,a,b,target);
    if (a==NULL) {
        treap_merge(src,a,b);
        return NULL;
    }
    c=a;
    while(c->r!=NULL)c=c->r;
    treap_merge(src,a,b);
    return c;
}