#include <gtest/gtest.h>
#include "avl.h"

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

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}