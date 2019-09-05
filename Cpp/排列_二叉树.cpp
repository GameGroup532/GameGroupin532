/*假设我们有一个总数为n的排列，现在将其插入到一个二叉树中，返回这个二叉树的先序遍历和后序遍历  -----递归实现*/
#include<iostream>
using namespace std;

const int N = 100005;     //排列的大小 <10^5

int cnt;  //整个二叉树的大小
int root; 

struct node
{
	int val; 	//节点的值
	int l;   	//节点左边的下标
	int r;		//节点右边的下标
} t[N]; 


/*
	在以x为根的树中插入一个数字v
	v：要插入的数字
	x：当前节点
	返回值：x
*/
int insert(int v,int x){
	if(x==0){
		cnt = cnt + 1;
		x = cnt;
		t[x].val = v;
	    t[x].l = 0;
	    t[x].r = 0;
	    return x;
	}
	//递归插入左右子树
	if (t[x].val > v)
		t[x].l = insert(v,t[x].l);
	else
		t[x].r = insert(v,t[x].r);
	return x;
}


/*先序遍历
  x:当前节点
  ans：存储结果的数组
*/
void dlr(int x ,vector<int> &ans){
	if(x){
		ans.push_back(x);
		dlr(t[x].l,ans);
		dlr(t[x].r,ans);
	}

}


/*后序遍历
  x：当前节点
*/
void lrd(int x,vector<int> &ans){
	if(x){
		lrd(t[x].l,ans);
		lrd(t[x].r,ans);
		ans.push_back(x);
	}
}

vector<int> getAnswer(int n, vector<int> sequence){
	root = cnt = 0; //初始化

	for(int i=0; i < int(sequence.size()); ++i)
		root = insert(sequence[i], root);

	vector<int> ans; 	//返回值
	dlr(root,ans);       //先加入先序遍历
	lrd(root,ans);		//后加入后序遍历

	return ans;
}

int main(){
	int n;
	scanf("%d", &n);
	vector<int> sequence;
	for(int i = 0; i < n; ++ i){
		int x;
		scanf("%d", &x);
		sequence.push_back(x);
	}
	std::vector<int> ans = getAnswer(n,sequence);
	for(int i = 0; i < n; ++i)
		printf("%d%c",ans[i], " \n"[i==n-1] );
	for(int i = 0; i < n; ++i)
		printf("%d%c",ans[n + i], " \n"[i == n-1] );

	return 0;
}