/*
1.���н�����ɫ�Ǻ�ɫ���ɫ
2.���ڵ��Ǻ�ɫ
3.����Ҷ�ӽ���Ǻ�ɫ��NULL��
4.ÿ����ɫ�Ľ�㶼��������ɫ���ӽ��
5.���������������������Ҷ�ӽ��ļ�·���϶�������ͬ��Ŀ�ĺ�ɫ���
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


