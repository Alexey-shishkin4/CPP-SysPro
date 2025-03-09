#include <gtest/gtest.h>
#include "avl.h"

// Тест на вставку элементов в дерево
TEST(AVLTreeTest, TestInsert) {
    AVLTree avl;
    avl.insert(10);
    avl.insert(20);
    avl.insert(30);
    avl.insert(40);
    avl.insert(50);

    std::vector<int> expected = { 10, 20, 30, 40, 50 };
    EXPECT_EQ(avl.getInorder(), expected);
}

// Тест на удаление элемента из дерева
TEST(AVLTreeTest, TestRemove) {
    AVLTree avl;
    avl.insert(10);
    avl.insert(20);
    avl.insert(30);
    avl.insert(40);
    avl.remove(30);

    std::vector<int> expected = { 10, 20, 40 };
    EXPECT_EQ(avl.getInorder(), expected);
}

// Тест на поиск элемента в дереве
TEST(AVLTreeTest, TestSearch) {
    AVLTree avl;
    avl.insert(10);
    avl.insert(20);
    avl.insert(30);

    EXPECT_TRUE(avl.search(10));
    EXPECT_TRUE(avl.search(20));
    EXPECT_TRUE(avl.search(30));
    EXPECT_FALSE(avl.search(40));
}

// Основная функция для запуска тестов
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
