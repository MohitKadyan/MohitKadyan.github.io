#include <bits/stdc++.h>

using namespace std;

#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define watch(x) cout << (#x) << " is " << (x) << endl
#define f(t) for(ll i =0;i<t;i++)
#define bs(a,x) binary_search(a.begin(),a.end(),x)
#define ll long long int 
#define ul unsigned long int
#define ld long double
#define umpi unordered_map<int,int> 
#define umpl unordered_map<ll,ll> 
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define mod 1000000007 
#define N 10000000
#define all(a) a.begin(),a.end()
#define point pair<int,int>
const int inf = 1000000007;
const ll linf = 1ll * inf * inf;
const ll MAXIMUM=1e5+4;

inline ll mul(ll a, ll b){ return (a * 1ll * b) % mod; }
inline ll sub(ll a, ll b){ ll c = a - b; if(c < 0) c += mod; return c; }
inline ll add(ll a, ll b){ ll c = a + b; if(c > mod) c -= mod; return c; }

struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
};

typedef struct node
{
    int key;
    int height;
    node *left;
    node *right;
} *BSTPTR;
 
node* create_node(int key_)
{
    node *child = new node;
 
    child->key = key_;
    child->height = 1;
    child->left = NULL;
    child->right = NULL;
 
    return child;
}
 
int get_height(node *current_node)
{
    if(current_node == NULL)
        return 0;
    return current_node->height;
}
 
int get_balance(node *current_node)
{
    if(current_node == NULL)
        return 0;
    return get_height(current_node->left) - get_height(current_node->right);
}
 
node* left_rotate(node *x)
{
    node *y = x->right;
    node *t2 = y->left;
 
    y->left = x;
    x->right = t2;
 
    x->height = max(get_height(x->left), get_height(x->right)) + 1;
    y->height = max(get_height(y->left), get_height(y->right)) + 1;
 
    return y;
}
 
node* right_rotate(node *x)
{
    node *y = x->left;
    node *t2 = y->right;
 
    y->right = x;
    x->left = t2;
 
    x->height = max(get_height(x->left), get_height(x->right)) + 1;
    y->height = max(get_height(y->left), get_height(y->right)) + 1;
 
    return y;
}
 
node* left_left_case(node *current_node)
{
    return right_rotate(current_node);
}
 
node* right_right_case(node *current_node)
{
    return left_rotate(current_node);
}
 
node* left_right_case(node *current_node)
{
    current_node->left = left_rotate(current_node->left);
    return right_rotate(current_node);
}
 
node* right_left_case(node *current_node)
{
    current_node->right = right_rotate(current_node->right);
    return left_rotate(current_node);
}
 
void preorder_traverse(node *current_node)
{
    if(current_node == NULL)
        return;
 
    printf("%d ",current_node->key);
    preorder_traverse(current_node->left);
    preorder_traverse(current_node->right);
    return;
}
 
node* find_min(node *current_node)
{
    while(current_node->left != NULL)
        current_node = current_node->left;
    return current_node;
}
 
node* insert_node(node *current_node, int key_)
{
    if(current_node == NULL)
        return create_node(key_);
 
    if(key_ < current_node->key)
        current_node->left = insert_node(current_node->left, key_);
    else if(key_ > current_node->key)
        current_node->right = insert_node(current_node->right, key_);
    else
        return current_node;
 
    current_node->height = max(get_height(current_node->left), get_height(current_node->right)) + 1;
 
    int balance = get_balance(current_node);
 
    if(balance > 1 && key_ < current_node->left->key)
        return left_left_case(current_node);
 
    if(balance < -1 && key_ > current_node->right->key)
        return right_right_case(current_node);
 
    if(balance > 1 && key_ > current_node->left->key)
        return left_right_case(current_node);
 
    if(balance < -1 && key_ < current_node->right->key)
        return right_left_case(current_node);
 
    return current_node;
}
 
node* search_node(node *current_node, int item)
{
    while(current_node != NULL)
    {
        if(item > current_node->key)
            current_node = current_node->right;
        else if(item < current_node->key)
            current_node = current_node->left;
        else
            break;
    }
    return current_node;
}
 
void levelprint(queue<BSTPTR> q)
{
    if(q.front()==q.back()){return ;}
    BSTPTR P=q.front();q.pop();
    if(P==NULL){cout<<endl;q.push(NULL);}
    else
    {
        cout<<P->key<<" ";
        if(P->left!=NULL){q.push(P->left);}
        if(P->right!=NULL){q.push(P->right);}
    }
    levelprint(q);

}
 
int main()
{
    node *root = NULL;
 
    /*root = insert_node(root, 9);
    root = insert_node(root, 5);
    root = insert_node(root, 10);
    root = insert_node(root, 0);
    root = insert_node(root, 6);
    root = insert_node(root, 11);
    root = insert_node(root, -1);
    root = insert_node(root, 1);
    root = insert_node(root, 2);*/
    for(int i=1;i<=20;i++)
    {
        root=insert_node(root,i);
    }
    queue<BSTPTR> q;
    q.push(root);
    q.push(NULL);
    cout<<"Level order"<<endl;
    levelprint(q);
    cout<<endl;
    return 0;
}
/*
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif	
	fio;	
	ll t;cin>>t;
	while(t--)
	{
		ll n,q;cin>>n>>q;
		vl a(n);
		f(n)cin>>a[i];
		while(q--)
		{
			ll x1,x2,y;
			cin>>x1>>x2>>y;

		}
	}

}*/