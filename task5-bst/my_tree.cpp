#include <iostream>
#include "my_tree.h"
using namespace std;

int main(int argc, char** argv) {
    int elementsnum, opnum;
    cin >> elementsnum >> opnum;

    vector<int> elements;

    for (int i = 0; i < elementsnum; ++i) {
        int x;
        cin >> x;
        elements.push_back(x);
    }
    MyTree<int> bst(elements);

    while (opnum--)
    {
        int optype;
        cin >> optype;
        if (optype == 1)
        {
            int element;
            cin >> element;
            bst.insert(element);
        }
        else if (optype == 2)
        {
            int element;
            cin >> element;
            cout << (bst.search(element) ? "1 " : "0") << endl;
        }
        else if (optype == 3)
        {
            int x;
            cin >> x;
            if (x == 1) {
                bst.inorder_rec();
                cout << endl;
            }
            else {
                bst.inorder_it();
                cout << endl;
            }
        }
        else if (optype == 4)
        {
            int x;
            cin >> x;
            if (x == 1) {
                bst.preorder_rec();
                cout << endl;
            }
            else {
                bst.preorder_it();
                cout << endl;
            }
        }
        else if (optype == 5)
        {
            int x;
            cin >> x;
            if (x == 1) {
                bst.postorder_rec();
                cout << endl;
            }
            else {
                bst.postorder_it();
                cout << endl;
            }
        }
        else if (optype == 6)
        {
            bst.breadth_traversal();
            cout << endl;
        }
        else
        {
            cout << bst.size() << ' ' << '\n';
        }
    }

}