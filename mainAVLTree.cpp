#include <iostream>
#include "AVLTree.hpp"

using namespace std;

int main() {

    // ==========================================
    // Test 1: Left Rotation (RR Case)
    // ==========================================
    {
        cout << "\nTEST 1: Left Rotation\n";

        AVLTree<int> tree;

        tree.insert(20);
        tree.insert(10);
        tree.insert(30);
        tree.insert(40);

        tree.remove(10);

        tree.print();

        // Expected root: 30
        cout << (!tree.contains(10) && tree.contains(30) ? "PASS\n" : "FAIL\n");
    }


    // ==========================================
    // Test 2: Right Rotation (LL Case)
    // ==========================================
    {
        cout << "\nTEST 2: Right Rotation\n";

        AVLTree<int> tree;

        tree.insert(30);
        tree.insert(20);
        tree.insert(40);
        tree.insert(10);

        tree.remove(40);

        tree.print();

        // Expected root: 20
        cout << (!tree.contains(40) && tree.contains(20) ? "PASS\n" : "FAIL\n");
    }


    // ==========================================
    // Test 3: Left-Right Rotation (LR Case)
    // ==========================================
    {
        cout << "\nTEST 3: Left-Right Rotation\n";

        AVLTree<int> tree;

        tree.insert(30);
        tree.insert(10);
        tree.insert(40);
        tree.insert(20);

        tree.remove(40);

        tree.print();

        // Expected root: 20
        cout << (!tree.contains(40) && tree.contains(20) ? "PASS\n" : "FAIL\n");
    }


    // ==========================================
    // Test 4: Right-Left Rotation (RL Case)
    // ==========================================
    {
        cout << "\nTEST 4: Right-Left Rotation\n";

        AVLTree<int> tree;

        tree.insert(20);
        tree.insert(10);
        tree.insert(40);
        tree.insert(30);

        tree.remove(10);

        tree.print();

        // Expected root: 30
        cout << (!tree.contains(10) && tree.contains(30) ? "PASS\n" : "FAIL\n");
    }


    // ==========================================
    // Test 5: Delete a Leaf
    // ==========================================
    {
        cout << "\nTEST 5: Delete Leaf\n";

        AVLTree<int> tree;

        tree.insert(20);
        tree.insert(10);
        tree.insert(30);

        tree.remove(10);

        tree.print();

        cout << (!tree.contains(10) &&
                  tree.contains(20) &&
                  tree.contains(30)
                 ? "PASS\n" : "FAIL\n");
    }


    // ==========================================
    // Test 6: Delete Node with One Child
    // ==========================================
    {
        cout << "\nTEST 6: Delete Node with One Child\n";

        AVLTree<int> tree;

        tree.insert(20);
        tree.insert(10);
        tree.insert(30);
        tree.insert(25);

        tree.remove(30);

        tree.print();

        cout << (!tree.contains(30) &&
                  tree.contains(25)
                 ? "PASS\n" : "FAIL\n");
    }


    // ==========================================
    // Test 7: Delete Node with Two Children
    // ==========================================
    {
        cout << "\nTEST 7: Delete Node with Two Children\n";

        AVLTree<int> tree;

        tree.insert(20);
        tree.insert(10);
        tree.insert(30);
        tree.insert(25);
        tree.insert(40);

        tree.remove(30);

        tree.print();

        cout << (!tree.contains(30) &&
                  tree.contains(25) &&
                  tree.contains(40)
                 ? "PASS\n" : "FAIL\n");
    }


    // ==========================================
    // Test 8: Delete Root
    // ==========================================
    {
        cout << "\nTEST 8: Delete Root\n";

        AVLTree<int> tree;

        tree.insert(20);
        tree.insert(10);
        tree.insert(30);

        tree.remove(20);

        tree.print();

        cout << (!tree.contains(20) &&
                  tree.contains(10) &&
                  tree.contains(30)
                 ? "PASS\n" : "FAIL\n");
    }


    // ==========================================
    // Test 9: Delete the Only Node
    // ==========================================
    {
        cout << "\nTEST 9: Delete Only Node\n";

        AVLTree<int> tree;

        tree.insert(42);
        tree.remove(42);

        tree.print();

        cout << (tree.empty() ? "PASS\n" : "FAIL\n");
    }


    // ==========================================
    // Test 10: Multiple Deletions
    // ==========================================
    {
        cout << "\nTEST 10: Multiple Deletions\n";

        AVLTree<int> tree;

        tree.insert(10);
        tree.insert(20);
        tree.insert(30);
        tree.insert(40);
        tree.insert(50);
        tree.insert(25);

        cout << "Before deletion:\n";
        tree.print();

        tree.remove(10);
        tree.remove(20);
        tree.remove(30);

        cout << "After deletion:\n";
        tree.print();

        cout << (!tree.contains(10) &&
                 !tree.contains(20) &&
                 !tree.contains(30) &&
                  tree.contains(25) &&
                  tree.contains(40) &&
                  tree.contains(50)
                 ? "PASS\n" : "FAIL\n");
    }

    return 0;
}
