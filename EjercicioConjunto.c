#include <stdio.h>
#define SET_CAPACITY 10
typedef struct set{
    int data[SET_CAPACITY];
    int size;
}Set;
int add(Set *s, int value);
int init_set (Set *s);
int find(Set set, int value);
int removee(Set *s, int value);
int removerfirst(Set *s, int value);
int removerlast(Set *s, int value);
int exist(Set set, int value);
void intersect(Set setA, Set setB, Set *setC);
void printSet(Set set);
void join(Set set, Set setB, Set *setC);
void Complement(Set set, Set setB, Set *setC);
void DifSet(Set set, Set setB, Set *setC);
int main(){
    Set set; Set setB; Set setC;
    init_set(&set);
    add(&set, 4);
    add(&set, 7);
    add(&set, 9);
    add(&set, 13);
    add(&set, 5);
    init_set(&setB);
    add(&setB, 2);
    add(&setB, 4);
    add(&setB, 13);
    add(&setB, 8);
    init_set(&setC);
    printSet(set);
    printSet(setB);
    intersect(set,  setB,  &setC);
    printf("----interseccion----\n");
    printSet(setC);
    init_set(&setC);
    Complement(set, setB, &setC);
    printf("----complemento----\n");
    printSet(setC);
    init_set(&setC);
    DifSet(set,  setB,  &setC);
    printf("----diferencia----\n");
    printSet(setC);
    init_set(&setC);
    join(set,  setB,  &setC);
    printf("----union----\n");
    printSet(setC);
    int n1=removerfirst(&setC, 2);
    int n2= removee(&setC,8);
    int n3=removerlast(&setC, 13);
    printf("Eliminando valores en el conjunto\n");
    printSet(setC);
}
void join(Set set, Set setB, Set *setC) {
    int e, e2;
    for (int index = 0; index < set.size; ++index) {
        e = exist(set, setB.data[index]);
        e2 = exist(setB, set.data[index]);
        if (e != 1 || e2 == 1) {
            add(setC, set.data[index]);
            add(setC, set.data[index]);
        }
    }
    for (int index = 0; index < setB.size; ++index) {
        e = exist(set, setB.data[index]);
        if (e != 1)
            add(setC, setB.data[index]);
    }}
void Complement(Set set, Set setB, Set *setC){
    int e;
    for (int index = 0; index < setB.size; ++index) {
        e= exist(set, setB.data[index]);
        if (e!=1)
        {
            add(setC, setB.data[index]);
        }}}
void DifSet(Set set, Set setB, Set *setC) {
    int e;
    for (int index = 0; index < set.size; ++index) {
        e= exist(set, setB.data[index]);
        if (e!=1)
        {
            add(setC, set.data[index]);
        }}}
void intersect(Set set, Set setB, Set *setC){
    int e;
    for (int index = 0; index < set.size; ++index) {
        e= exist(setB, set.data[index]);
        if (e==1)
        {
            add(setC, set.data[index]);
        }}}
int add(Set *s, int value) {
    int exists;
    int result = 0;
    if (s->size < SET_CAPACITY) {
        exists = find(*s, value);
        if (exists==-1) {
            int index;
            for (index = s->size - 1; index >= 0 && s->data[index] > value; index--) {
                s->data[index + 1] = s->data[index];
            }
            s->data[index + 1] = value;
            s->size++;
            result = 1;
        }
    }
    return result;
}
int find(Set set, int value){
    int inicio=0;
    int fin= set.size-1;
    int mitad;
    int encontrado=0;
    while(inicio <= fin && encontrado == 0){
        mitad = inicio + (fin - inicio) / 2;
        if(set.data[mitad] == value)
            encontrado = 1;
        else
        if(set.data[mitad] > value)
            fin = mitad - 1;
        else
            inicio = mitad + 1;
    }
    if(encontrado == 1)
        return mitad;
    else{
        return -1;
    }
}
int init_set (Set *s){
    s->size=0;
    return 1;
}
int removee(Set *s, int value){
    int index= find(*s, value);
    if (index!=-1){
        s->size--;
        for (; index <= s->size-1 ; ++index) {
            s->data[index]=s->data[index+1];
        }
        return 1;
    }
    return -1;
}
int removerfirst(Set *s, int value){
    int index= find(*s, value);
    if (index==0){
        s->size--;
        for (; index <= s->size-1 ; ++index) {
            s->data[index]=s->data[index+1];
        }
        return 1;
    }
    return -1;
}
int removerlast(Set *s, int value){
    int index= find(*s, value);
    if (index==s->size-1){
        s->size--;
        for (; index <= s->size-1 ; ++index) {
            s->data[index]=s->data[index+1];
        }
        return 1;
    }
    return -1;
}
int exist(Set set, int value){
    int index= find(set, value);
    if (index==-1)
        return 0;
    return 1;
}
void printSet(Set set){
    printf("[");
    for (int index = 0; index < set.size; ++index) {
        printf("  %d  ", set.data[index]);
    }
    printf("]\n");
}