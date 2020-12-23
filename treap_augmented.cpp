
//Implementacion de treap explicito, no-persistente.
//Para aumentarlo se ha de modificar la funcion treap_update y treap_push
//Similar a set
#include <stdlib.h>

template <typename T, typename Q> 
struct treap {
    T value;
    Q info;
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
//Lazy-propagation
template <typename T, typename Q> 
void treap_push(treap<T,Q> *cur){
    if (!cur)
        return;
    ///TODO: IMPLEMENT
} 
// Combine
template <typename T, typename Q> 
void treap_update(treap<T,Q> *cur){
    if (!cur)
        return;
    ///TODO: IMPLEMENT
} 

//Combina a y b, guarda el resultado en des. MODIFICA a y b
template <typename T,typename Q> 
void treap_merge(treap<T,Q> * &des,treap<T,Q> * a, treap<T,Q> *b) {
    treap_push(a);
    treap_push(b);
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
    treap_update(des);   
}

//Divide src por val y lo guarda en {a,b} de forma que b incluye val. MODIFICA a y b
template <typename T,typename Q> 
void treap_split(treap<T,Q> *src, treap<T,Q> *&a,treap<T,Q>*&b,T val ){
    treap_push(src);
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
    treap_update(src);

}
template <typename T,typename Q> 
void treap_print(treap<T,Q> *cur ){
    treap_push(cur);
    if (!cur) {
        return;
    }
    treap_print(cur->l);
    //cout << cur->value<<" ";
    treap_print(cur->r);

}
template <typename T,typename Q> 
treap<T,Q> * treap_find(treap<T,Q>*src,T target) {
    treap_push(src);
    treap<T,Q> *cur=src;
    while (cur!=NULL) {        
        treap_push(cur);
        if (cur->value==target)break;
        if (target < cur->value)
            cur = cur->l;
        else
            cur=cur->r;
    }
    return cur;
}

template <typename T,typename Q> 
void treap_insert(treap<T,Q>*src,T target) {    
        treap<T,Q> *n=new treap<T,Q>(target),*a,*b;
        treap_split(src,a,b,target);
        treap_merge(src, a,n);
        treap_merge(src, src,b);
}
///UNTESTED
template <typename T,typename Q> 
treap<T,Q> * treap_lowerbound(treap<T,Q>*src,T target) {
    treap<T,Q> *a,*b,*c;
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