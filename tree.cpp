#include <cstdio>  
#include <cstdlib>  
#include <cstring>  
#define MAXN 1500 + 100  
typedef struct TNode    //定义树结构  
{  
    bool is_value;      //是否被赋值过  
    int v;              //节点值  
    TNode *left, *right;//左儿子和右儿子  
}Node;  
Node* root; //二叉树的根节点  
bool failed;  
int ans[MAXN],cnt;  
//功能：申请新节点并初始化  
Node* newnode(){  
    Node* u = (Node*)malloc(sizeof(Node));  
    if(u != NULL ){  
        u->is_value = false;  
        u->left = u->right = NULL;  
    }  
    return u;  
}  
//功能：程序运行结束之前先释放内存  
void remove_tree(Node* u){  
    if(u == NULL) return ;  
    remove_tree(u->left);  
    remove_tree(u->right);  
    free(u);  
}  
//功能：将给定的序列加入树，若不存在则使用newnode创建新节点  
void addnode(int v,char *s){  
    int nLen = strlen(s);  
    Node* u = root;             //从根节点往下走  
    for(int i = 0; i < nLen; i++){  
        if(s[i] == 'L'){  
            if(u->left == NULL) u->left = newnode();    //节点不存在，建立新节点  
            u = u->left;                    //往左走  
        }else if(s[i] == 'R'){  
            if(u->right == NULL) u->right = newnode();  
            u = u->right;                   //往右走  
        }  
    }           //忽略其他情况，即最后那个多余的括号  
    if(u->is_value) failed = true;  //已经赋过值，表明输入有误  
    u->v = v;  
    u->is_value = true;  
}  
void input_tree(){  
    char s[MAXN];   //保存读入节点  
    failed = false;  
    root = newnode(); //创建根节点  
    while(scanf("%s",s),strcmp(s,"()")){ //读到结束标志退出循环  
        int v;  
        sscanf(&s[1],"%d",&v);    //读入节点值  
        addnode(v,strchr(s,',')+1);  //查找逗号，插入节点  
    }  
    return ;  
}  
bool bfs(){  
    Node *q[MAXN],*u;  
    q[0] = root;  
    int front = 0, rear = 1;  
    while(front < rear){  
        u = q[front++];  
        if(!u->is_value) return false;  //没有被赋过值，表明输入有误  
        ans[cnt++] = u->v;                //增加到输出序列的尾部  
        if(u->left != NULL) q[rear++] = u->left; //把左儿子放入队列  
        if(u->right != NULL) q[rear++] = u->right;//把右儿子放入队列  
    }  
    return true;        //输入正确  
}  
int main()
{  
    while(1){  
        cnt = 0;  
        input_tree();  
        if(!failed&&bfs()){      //判断是否有重复输入或者节点中断  
            for(int i = 0; i < cnt; i++){   //按照层次遍历输出二叉树  
                if(i) printf(" ");  
                printf("%d",ans[i]);  
            }  
            printf("\n");  
        }  
        else  
            printf("-1\n");  
    }  
    return 0;  
}  
