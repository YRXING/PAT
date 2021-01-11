/*
1.所有结点的颜色是红色或黑色
2.根节点是黑色
3.所有叶子结点是黑色（NULL）
4.每个红色的结点都有两个黑色的子结点
5.从任意结点出发，到其所有叶子结点的简单路径上都包含相同数目的黑色结点
*/
#define COLOR_RED 0
#define COLOR_BLACK 1

struct BinaryTreeNode{
    keyType key;
    int color;
    BinaryTreeNode* parent;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};


