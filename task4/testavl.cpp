#include <iostream>
#include <vector>
#include <cassert>
#include "avl.h"

void testInsert() {
    AVLTree avl;
    avl.insert(10);
    avl.insert(20);
    avl.insert(30);
    avl.insert(40);
    avl.insert(50);

    std::vector<int> expected = { 10, 20, 30, 40, 50 };
    assert(avl.getInorder() == expected);
    std::cout << "testInsert passed!" << std::endl;
}

void testRemove() {
    AVLTree avl;
    avl.insert(10);
    avl.insert(20);
    avl.insert(30);
    avl.insert(40);
    avl.remove(30);

    std::vector<int> expected = { 10, 20, 40 };
    assert(avl.getInorder() == expected);
    std::cout << "testRemove passed!" << std::endl;
}

void testSearch() {
    AVLTree avl;
    avl.insert(10);
    avl.insert(20);
    avl.insert(30);

    assert(avl.search(10) == true);
    assert(avl.search(20) == true);
    assert(avl.search(30) == true);
    assert(avl.search(40) == false);

    std::cout << "testSearch passed!" << std::endl;
}

void testCopyConstructor() {
    AVLTree avl;
    avl.insert(10);
    avl.insert(20);
    avl.insert(30);

    AVLTree avlCopy(avl);
    assert(avl.getInorder() == avlCopy.getInorder());

    std::cout << "testCopyConstructor passed!" << std::endl;
}

void testAssignmentOperator() {
    AVLTree avl;
    avl.insert(10);
    avl.insert(20);
    avl.insert(30);

    AVLTree avlAssigned;
    avlAssigned = avl;
    assert(avl.getInorder() == avlAssigned.getInorder());

    std::cout << "testAssignmentOperator passed!" << std::endl;
}

void testMoveConstructor() {
    AVLTree avl;
    avl.insert(10);
    avl.insert(20);
    avl.insert(30);

    AVLTree avlMoved(std::move(avl));
    std::vector<int> expected = { 10, 20, 30 };
    assert(avlMoved.getInorder() == expected);
    assert(avl.getInorder().empty());  // avl should be in a valid but empty state after move

    std::cout << "testMoveConstructor passed!" << std::endl;
}

void testMoveAssignmentOperator() {
    AVLTree avl;
    avl.insert(10);
    avl.insert(20);
    avl.insert(30);

    AVLTree avlAssigned;
    avlAssigned = std::move(avl);
    std::vector<int> expected = { 10, 20, 30 };
    assert(avlAssigned.getInorder() == expected);
    assert(avl.getInorder().empty());  // avl should be in a valid but empty state after move

    std::cout << "testMoveAssignmentOperator passed!" << std::endl;
}

int main() {
    testInsert();
    testRemove();
    testSearch();
    testCopyConstructor();
    testAssignmentOperator();
    testMoveConstructor();
    testMoveAssignmentOperator();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
