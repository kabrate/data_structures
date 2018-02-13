
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int KEY;
enum NODECOLOR
{
    BLACK = 0,
    RED = 1
};

typedef struct RBTree
{
    struct RBTree *parent;
    struct RBTree *left, *right;
    KEY key;
    NODECOLOR color;
}RBTree, *PRBTree;

PRBTree RB_InsertNode(PRBTree root, KEY key);
PRBTree RB_InsertNode_Fixup(PRBTree root, PRBTree z);
PRBTree RB_DeleteNode(PRBTree root, KEY key);
PRBTree RB_DeleteNode_Fixup(PRBTree root, PRBTree z);
PRBTree Find_Node(PRBTree root, KEY key);
void Left_Rotate(PRBTree A, PRBTree& root);
void Right_Rotate(PRBTree A, PRBTree& root);
void Mid_Visit(PRBTree T);
void Mid_DeleteTree(PRBTree T);
void Print_Node(PRBTree node);
/**//*-----------------------------------------------------------
  | A B
  | / \ ==> / \
  | a B A y
  | / \ / \
  | b y a b
  -----------------------------------------------------------*/
void Left_Rotate(PRBTree A, PRBTree& root)
{ 
    PRBTree B;
    B = A->right;
   if (NULL == B)
        return;
  A->right = B->left;
    if (NULL != B->left)
        B->left->parent = A;
    B->parent = A->parent;
    // ���������ж�����һ�������A->parent = NULL�����
   if (A == root)
    {
        root = B;
    }
    else if (A == A->parent->left)
    {
        A->parent->left = B;
    }
    else
    {
        A->parent->right = B;
    }
    B->left = A;
    A->parent = B;
}
/**//*-----------------------------------------------------------
  | A B
  | / \ / \
  | B y ==> a A
  | / \ / \
  |a b b y
  -----------------------------------------------------------*/
void Right_Rotate(PRBTree A, PRBTree& root)
{
    PRBTree B;
    B = A->left;
   if (NULL == B)
        return;
   A->left = B->right;
    if (NULL != B->right)
        B->right->parent = A;
    B->parent = A->parent;
    // ���������ж�����һ�������A->parent = NULL�����
   if (A == root)
    {
        root = B;
    }
    else if (A == A->parent->left)
    {
        A->parent->left = B;
    }
    else
    {
        A->parent->right = B;
    }
    A->parent = B;
    B->right = A;
}
/**//*-----------------------------------------------------------
  | ��������:����keyֵ��Ӧ�Ľ��ָ��
  | �������:���ڵ�root,�����ҹؼ�ֵkey
  | ���ز���:����ҵ����ؽ��ָ��,���򷵻�NULL
  -------------------------------------------------------------*/
PRBTree Find_Node(PRBTree root, KEY key)
{
    PRBTree x;
 // �ҵ�key���ڵ�node
   x = root;
    do
    {
        if (key == x->key)
            break;
        if (key < x->key)
        {
            if (NULL != x->left)
                x = x->left;
            else
                break;
        }
        else
        {
            if (NULL != x->right)
                x = x->right;
            else
                break;
        }
    } while (NULL != x);

    return x;
}

/**//*-----------------------------------------------------------
  | ��������:�����в���keyֵ
  | �������:���ڵ�root,��������Ĺؼ�ֵkey
  | ���ز���:���ڵ�root
  -------------------------------------------------------------*/
PRBTree RB_InsertNode(PRBTree root, KEY key)
{
    PRBTree x, y;
   PRBTree z;
    if (NULL == (z = (PRBTree)malloc(sizeof(RBTree))))
    {
        printf("Memory alloc error\n");
        return NULL;
    }
    z->key = key;
   // �õ�z�ĸ��ڵ�
   x = root, y = NULL;
    while (NULL != x)
    {
        y = x;
        if (z->key < x->key)
        {
            if (NULL != x->left)
            {
                x = x->left;
            }
            else
            {
                break;
            }
        }
        else
        {
            if (NULL != x->right)
            {
                x = x->right;
            }
            else
            {
                break;
            }
        }
    }
// ��z�ŵ����ʵ�λ��
z->parent = y;
    if (NULL == y)
    {
        root = z;
    }
    else
    {
        if (z->key < y->key)
            y->left = z;
        else
            y->right = z;
    }
    // ����z����������Ϊ�ղ�����ɫ��red��ע���²���Ľڵ���ɫ����red
  z->left = z->right = NULL;
    z->color = RED; // �Ժ������������
 return RB_InsertNode_Fixup(root, z);
}
/**//*-----------------------------------------------------------
  | ��������:�Բ���keyֵ֮�������������
  | �������:���ڵ�root,����Ľ��z
  | ���ز���:���ڵ�root
  -------------------------------------------------------------*/
PRBTree RB_InsertNode_Fixup(PRBTree root, PRBTree z)
{
    PRBTree y;
    while (root != z && RED == z->parent->color) // ��z���Ǹ�ͬʱ���ڵ����ɫ��red
{
        if (z->parent == z->parent->parent->left) // ���ڵ����游�ڵ��������
 {
            y = z->parent->parent->right; // yΪz�Ĳ����ڵ�
      if (NULL != y && RED == y->color) // �����ڵ��������ɫ��red
       {
                 z->parent->color = BLACK; // ����z�ĸ��ڵ���ɫ��B
          y->color = BLACK; // ����z�Ĳ����ڵ���ɫ��B
           z->parent->parent->color = RED; // ����z���游�ڵ���ɫ��B
          z = z->parent->parent; // ����zΪ�����游�ڵ�
        }
            else // �޲����ڵ���߲����ڵ���ɫ��b
      {
                if (z == z->parent->right) // ����½ڵ��Ǹ��ڵ��������
         {
                    z = z->parent;
                    Left_Rotate(z, root);
                }
                z->parent->color = BLACK; // �ı丸�ڵ���ɫ��B
         z->parent->parent->color = RED; // �ı��游�ڵ���ɫ��R
         Right_Rotate(z->parent->parent, root);
            }
        }
        else // ���ڵ�Ϊ�游�ڵ��������
{
            y = z->parent->parent->left; // yΪz�Ĳ����ڵ�
      if (NULL != y && RED == y->color) // ���y����ɫ��red
       {
                z->parent->color = BLACK; // ���ĸ��ڵ����ɫΪB
          y->color = BLACK; // ���Ĳ����ڵ����ɫ��B
          z->parent->parent->color = RED; // �����游�ڵ���ɫ��R
 z = z->parent->parent; // ����zָ���游�ڵ�
    } 
        else // y�����ڻ�����ɫ��B
      {
                if (z == z->parent->left) // ����Ǹ��ڵ��������

                {
                    z = z->parent;
                    Right_Rotate(z, root);
                }
                z->parent->color = BLACK; // �ı丸�ڵ����ɫ��B
         z->parent->parent->color = RED; // �ı��游�ڵ����ɫ��RED
         Left_Rotate(z->parent->parent, root);
            }
        }
    } // while(RED == z->parent->color)
 // ���ڵ����ɫʼ�ն���B
 root->color = BLACK;
 return root;
}
/**//*-----------------------------------------------------------
  | ��������:������ɾ��keyֵ
  | �������:���ڵ�root,��������Ĺؼ�ֵkey
  | ���ز���:���ڵ�root
  -------------------------------------------------------------*/
PRBTree RB_DeleteNode(PRBTree root, KEY key)
{
    PRBTree x, y, z, x_parent;
 z = Find_Node(root, key);
    if (NULL == z)
        return root;
 // ��z��һ����������ʱ��,y == z
 // ����,y�Ǵ���z��С�Ľ��
if (NULL == z->left || NULL == z->right)
        y = z;
    else
    {
        y = z->right;
        while (NULL != y->left)
         y = y->left;
    } // x��y������,����ΪNULL
 if (NULL != y->left)
        x = y->left;
    else
        x = y->right;  // �趨x��λ��ȡ��y
    if (NULL != x)
        x->parent = y->parent;
    if (NULL == y->parent)
        root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x; // ��y��key������z��,����y���Ǵ�ɾ���Ľ����
  if (y != z)
    {
        z->key = y->key;
    } // ���y����ɫֵ��B,��ôҪ������������
 if (BLACK == y->color && NULL != x)
    RB_DeleteNode_Fixup(root, x);
 free(y);
 return root;
}/**//*-----------------------------------------------------------
  | ��������:��ɾ��keyֵ֮�������������
  | �������:���ڵ�root,ɾ���Ľ����ӽ��x
  | ���ز���:���ڵ�root
  -------------------------------------------------------------*/
PRBTree RB_DeleteNode_Fixup(PRBTree root, PRBTree x)
{
    PRBTree w;
 while (x != root && BLACK == x->color)
    {
        if (x == x->parent->left) // ���x��������
   {
            w = x->parent->right; // w��x���ֵܽ��
         if (NULL == w)
                continue;
          if (RED == w->color) // ���w����ɫ�Ǻ�ɫ 
       {
                w->color = BLACK;
                x->parent->color = RED;
                Left_Rotate(x->parent, root);
                w = x->parent->right;
            }
            if (NULL != w->left && BLACK == w->left->color &&
                    NULL != w->right && BLACK == w->right->color)
            {
                w->color = RED;
                x = x->parent;
            }
            else
            {
                if (NULL != w->right && BLACK == w->right->color)
                {
                    w->left->color = BLACK;
                    w->color = RED;
                    Right_Rotate(w, root);
                    w = x->parent->right;
                }
         w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                Left_Rotate(x->parent, root);
                x = root;
            }
        }
        else
        {  w = x->parent->left;
            if (NULL == w)
                continue;
            if (RED == w->color)
            {
                w->color = BLACK;
                x->parent->color = RED;
                Left_Rotate(x->parent, root);
                w = x->parent->left;
            }
            if (NULL != w->left && BLACK == w->left->color &&
                    NULL != w->right && BLACK == w->right->color)
            {  w->color = RED;
                 x = x->parent;
            }
            else
            {
                if (NULL != w->left && BLACK == w->left->color)
                {
                    w->right->color = BLACK;
                    w->color = RED;
                    Left_Rotate(w, root);
                    w = x->parent->left;
                }
w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;
                Right_Rotate(x->parent, root);
                x = root;
            }
        }
    }
  x->color = BLACK;
 return root;
}
void Print_Node(PRBTree node)
{
    char* color[] = {"BLACK", "RED"};
    printf("Key = %d,\tcolor = %s", node->key, color[node->color]);
    if (NULL != node->parent)
        printf(",\tparent = %d", node->parent->key);
    if (NULL != node->left)
        printf(",\tleft = %d", node->left->key);
    if (NULL != node->right)
        printf(",\tright = %d", node->right->key);
    printf("\n");
}// ���������
void Mid_Visit(PRBTree T)
{
    if (NULL != T)
    {
        if (NULL != T->left)
            Mid_Visit(T->left);
        Print_Node(T);
        if (NULL != T->right)
         Mid_Visit(T->right);
    }
}// ����ɾ�����ĸ����ڵ�
void Mid_DeleteTree(PRBTree T)
{
    if (NULL != T)
    {
        if (NULL != T->left)
            Mid_DeleteTree(T->left);
        PRBTree temp = T->right;
        free(T);
        T = NULL;
        if (NULL != temp)
            Mid_DeleteTree(temp);
    }
}
void Create_New_Array(int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        array[i] = rand() % 1000;
    }
}
int main(int argc, char *argv[])
{  //int array[10] = {80, 116, 81, 205, 82, 68, 151, 20, 109, 100};
   int array[10];
    srand(time(NULL));
    Create_New_Array(array, 10);
    PRBTree root = NULL;
    int i;
    for (i = 0; i < 10; i++)
    {
        root = RB_InsertNode(root, array[i]);
    }
 Mid_Visit(root);
// ���ɾ��һ�����
 int index = rand() % 10;
  printf("delete node %d\n", array[index]);
  root = RB_DeleteNode(root, array[index]);
  Mid_Visit(root); // ɾ��������
 Mid_DeleteTree(root);
 return 0;
}

