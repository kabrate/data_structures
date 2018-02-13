#include <cstdio>  
#include <cstdlib>  
#include <cstring>  
#define MAXN 1500 + 100  
typedef struct TNode    //�������ṹ  
{  
    bool is_value;      //�Ƿ񱻸�ֵ��  
    int v;              //�ڵ�ֵ  
    TNode *left, *right;//����Ӻ��Ҷ���  
}Node;  
Node* root; //�������ĸ��ڵ�  
bool failed;  
int ans[MAXN],cnt;  
//���ܣ������½ڵ㲢��ʼ��  
Node* newnode(){  
    Node* u = (Node*)malloc(sizeof(Node));  
    if(u != NULL ){  
        u->is_value = false;  
        u->left = u->right = NULL;  
    }  
    return u;  
}  
//���ܣ��������н���֮ǰ���ͷ��ڴ�  
void remove_tree(Node* u){  
    if(u == NULL) return ;  
    remove_tree(u->left);  
    remove_tree(u->right);  
    free(u);  
}  
//���ܣ������������м�����������������ʹ��newnode�����½ڵ�  
void addnode(int v,char *s){  
    int nLen = strlen(s);  
    Node* u = root;             //�Ӹ��ڵ�������  
    for(int i = 0; i < nLen; i++){  
        if(s[i] == 'L'){  
            if(u->left == NULL) u->left = newnode();    //�ڵ㲻���ڣ������½ڵ�  
            u = u->left;                    //������  
        }else if(s[i] == 'R'){  
            if(u->right == NULL) u->right = newnode();  
            u = u->right;                   //������  
        }  
    }           //�������������������Ǹ����������  
    if(u->is_value) failed = true;  //�Ѿ�����ֵ��������������  
    u->v = v;  
    u->is_value = true;  
}  
void input_tree(){  
    char s[MAXN];   //�������ڵ�  
    failed = false;  
    root = newnode(); //�������ڵ�  
    while(scanf("%s",s),strcmp(s,"()")){ //����������־�˳�ѭ��  
        int v;  
        sscanf(&s[1],"%d",&v);    //����ڵ�ֵ  
        addnode(v,strchr(s,',')+1);  //���Ҷ��ţ�����ڵ�  
    }  
    return ;  
}  
bool bfs(){  
    Node *q[MAXN],*u;  
    q[0] = root;  
    int front = 0, rear = 1;  
    while(front < rear){  
        u = q[front++];  
        if(!u->is_value) return false;  //û�б�����ֵ��������������  
        ans[cnt++] = u->v;                //���ӵ�������е�β��  
        if(u->left != NULL) q[rear++] = u->left; //������ӷ������  
        if(u->right != NULL) q[rear++] = u->right;//���Ҷ��ӷ������  
    }  
    return true;        //������ȷ  
}  
int main()
{  
    while(1){  
        cnt = 0;  
        input_tree();  
        if(!failed&&bfs()){      //�ж��Ƿ����ظ�������߽ڵ��ж�  
            for(int i = 0; i < cnt; i++){   //���ղ�α������������  
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
