#include<stdio.h>
#include<stdlib.h>
struct node
{
struct node* nodes[27];
};
struct node* getnode()
{int i;
struct node* newnode=(struct node*)malloc(sizeof(struct node));
for(i=0;i<27;i++)newnode->nodes[i]=NULL;
return newnode;
}
struct node* insert(struct node* root,char *key)
{
if(!root)root=getnode();
if(!(*key))return root;
int index=*key-'a';
root->nodes[index]=insert(root->nodes[index],++key);
return root;
}
void printt9(char *pre,int depth)
{
pre[depth]=0;
printf("%s\n",pre);
}
int keys(struct node* root,int val,int o)
{int s,e;
int a[]={0,3,6,9,12,15,19,22,26};
if(o&&o>=a[val+1])return -1;
s=o?o:a[val];
e=a[val+1];
for(;s<e;s++)
if(root->nodes[s])return s;
return -1;
}
void search(struct node* root,char *val,char *pre,int depth)
{int i;
if(*(val+depth)==0)
{
pre[depth]=0;printt9(pre,depth);return;
}
i=keys(root,*(val+depth)-'2',0);
if(i==-1)pre[depth]=0;
while(i>=0)
{
pre[depth]=i+'a';
search(root->nodes[i],val,pre,depth+1);
pre[depth]=0;
i=keys(root,*(val+depth)-'2',i+1);
}
}
int main()
{struct node* root=NULL;int i=0;
FILE *fp;char a[100],b[100];
fp=fopen("t9.dic","r");
while(!feof(fp))
{
fscanf(fp,"%s",&a);
root=insert(root,a);
}
printf("enter numbers\n");
while((a[i]=getchar())!='q')
{if(a[i]=='0'){i=0;continue;}
if((a[i]>='2')&&(a[i]<='9'))
{
a[++i]=0;
printf("%s\n",a);
search(root,a,b,0);
fflush(stdout);
}

}}
