#ifndef AED_PROJECT1_SORTSTUDENTS_CPP
#define AED_PROJECT1_SORTSTUDENTS_CPP
#include "Data.h"
//falta meter aqui a ordem alfabetica

struct studentComparatorAlpha2 {
    bool operator()(Student *s1, Student *s2) {
        if (s1->get_studentCode() != s2->get_studentCode()) return (s2->get_studentName() < s1->get_studentName());
        return false;
    }
};
struct studentCodeComparator {
    bool operator()(Student *s1, Student *s2) {
        if (s1->get_studentCode() != s2->get_studentCode())
            return (s1->get_studentCode() < s2->get_studentCode());
        return false;
    }
};
struct studentCodeComparatorInv {
    bool operator()(Student *s1, Student *s2) {
        if (s1->get_studentCode() != s2->get_studentCode())
            return (s2->get_studentCode() < s1->get_studentCode());
        return false;
    }
};

struct studentComparatorUC {
    bool operator()(Student *s1, Student *s2) {
        if (s1->get_studentCode() != s2->get_studentCode()) return s1->get_classes().size() < s2->get_classes().size();
        return false;
    }
};

struct studentComparatorUCInv {
    bool operator()(Student *s1, Student *s2) {
        if (s1->get_studentCode() != s2->get_studentCode()) return s1->get_classes().size() > s2->get_classes().size();
        return false;
    }
};

//não faria mais sentido as funções receberem um set ?
set<Student* , studentComparatorAlpha2> s_alphaZ(set<Student *, studentComparatorAlpha1> s){
    set<Student* , studentComparatorAlpha2> studentsA2;
    for(Student* p :s) studentsA2.insert(p);
    return studentsA2;
}
set<Student* , studentCodeComparator> s_numb(set<Student *, studentComparatorAlpha1> s){
    set<Student* , studentCodeComparator> studentNum;
    for (Student* p:s) studentNum.insert(p);
    return studentNum;
}
set<Student* , studentCodeComparatorInv> s_numbInv(set<Student *, studentComparatorAlpha1> s){
    set<Student* , studentCodeComparatorInv> studentInv;
    for (Student* p:s) studentInv.insert(p);
    return studentInv;
}

set<Student* , studentComparatorUC> s_UC(set<Student *, studentComparatorAlpha1> s){
    set<Student* , studentComparatorUC> studentsUC;
    for(Student* p :s) studentsUC.insert(p);
    return studentsUC;
}

set<Student* , studentComparatorUCInv> s_UCInv(set<Student *, studentComparatorAlpha1> s){
    set<Student* , studentComparatorUCInv> studentsUC;
    for(Student* p :s) studentsUC.insert(p);
    return studentsUC;
}

//create function that shows student beautifully

//SORTERS PARA LISTAS DE ESTUDANTES

bool l_AlphaA (Student* s1, Student* s2){
    return s1->get_studentName()<s2->get_studentName();
}

bool l_AlphaZ (Student* s1, Student* s2){
    return s1->get_studentName()>s2->get_studentName();
}

bool l_NumbInv (Student* s1, Student* s2){
    return s1->get_studentCode()>s2->get_studentCode();
}

bool l_Numb (Student* s1, Student* s2){
    return s1->get_studentCode()<s2->get_studentCode();
}

// sorters: numero de cadeiras crescente/decrescente para lista e para set

bool l_UC (Student* s1, Student* s2){
    return s1->get_classes().size() < s2->get_classes().size();
}

bool l_UCInv (Student* s1, Student* s2){
    return s1->get_classes().size() > s2->get_classes().size();
}
#endif //AED_PROJECT1_SORTSTUDENTS_CPP