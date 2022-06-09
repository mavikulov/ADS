#include <iostream>
#include <iomanip>
#include "tree.h"

using namespace std;

int main()
{
    Tree<int> intTree;           /* создаем новой бинароное дерево с ключем типа int */
    int a;
    cout << "10 numbers:" << endl;   /* заполняем его */
    for (int i = 0; i < 10; i++)
    {
        cin >> a;
        intTree.insert_node(a);
    }
    cout << endl << "inorder_walk:" << endl;              /* обходим */
    intTree.inorder_walk(intTree.get_root());       /* вот для этого понадобился метод get_root() :-) */
    cout << endl << "Minimum is: " << (intTree.find_min(intTree.get_root()))->get_data() << endl;
    cout << endl << "Maximum is: " << (intTree.find_max(intTree.get_root()))->get_data() << endl;
    cout << "Enter node value U want to delete:";     /* попробуем удалить узел с ключем a */
    cin >> a;
    intTree.delete_node(intTree.find_node(intTree.get_root(), a));    /* если их несколько, то удалится первй найденный */
    cout << endl << "Now inorder_walk:" << endl;
    intTree.inorder_walk(intTree.get_root());       /* посмотрим на результат */

}