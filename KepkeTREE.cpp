// KepkeTREE.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream>
#include <string>
#include <list>
using namespace std;

class kepTree;
struct kList;
void printTree(kList* list);
kList* creatList(int i, string str);

struct kList {
    int index =0;
    string data = "";
    kList *left = NULL;
    kList *right = NULL;
};


class kepTree {
public:
    kList* ELroot;
    kepTree(int i, string str) {
        ELroot = creatList(i, str);
    }
          
    void addEL(int i, string str) {
        kList* tmpEL = ELroot;
          
        while (tmpEL != NULL) {
            if (i < tmpEL->index) {
                if (tmpEL->left != NULL) {
                    tmpEL = tmpEL->left;
                }
                else {
                    tmpEL->left  = creatList(i, str);
                    tmpEL = tmpEL->left;
                    tmpEL = NULL;
                }                
            }
            else if (i > tmpEL->index) {
                if (tmpEL->right != NULL) {
                    tmpEL = tmpEL->right;
                }
                else {
                    tmpEL->right = creatList(i, str);
                    tmpEL = tmpEL->right;
                    tmpEL = NULL;
                };                
            }
            else {
                tmpEL->data = str;
                tmpEL = NULL;
            };
        };
    };
};

void printTree(kList* list) {

    if (list->left != NULL)
        printTree(list->left);
    cout << "-> " << list->index << " " << list->data << endl;
    if (list->right != NULL)
        printTree(list->right);
 
};
kList* creatList(int i, string str) {
    kList* tmpEL = new kList;
    tmpEL->index = i;
        tmpEL->data = str;
        tmpEL->right = NULL;
        tmpEL->left = NULL; 
    return tmpEL;
};
          
void push_list(kList *Elroot, int i, string str) {
    kList* tmpEL = Elroot;

    while (tmpEL != NULL) {
        if (i < tmpEL->index) {
            if (tmpEL->left != NULL) {
                tmpEL = tmpEL->left;
            }
            else {
                tmpEL->left = creatList(i, str);
                tmpEL = tmpEL->left;
                tmpEL = NULL;
            }
        }
        else if (i > tmpEL->index) {
            if (tmpEL->right != NULL) {
                tmpEL = tmpEL->right;
            }
            else {
                tmpEL->right = creatList(i, str);
                tmpEL = tmpEL->right;
                tmpEL = NULL;
            };
        }
        else {
            tmpEL->data = str;
            tmpEL = NULL;
        };
    };
};
  



int main()
{
    list<int> myList;
    kepTree kTree(10, "rooot");

    kTree.addEL(5, "five");
    kTree.addEL(15, "1 one");
    kTree.addEL(0, " zero");
    kTree.addEL(25, " 1 five");
    kTree.addEL(35, " 1 five");
    kTree.addEL(45, " 1 five");
    kTree.addEL(35, " ddddddd");
    printTree(kTree.ELroot);
    int i = 0;
    std::cout << "Second tree!\n";
    kList* LLTree; 
    LLTree = creatList(100, "handreed");

    push_list(LLTree, 99, "ninti nine");
    push_list(LLTree, 101, "hand one");
    printTree(LLTree);




    std::cout << "Hello World!\n";
}

