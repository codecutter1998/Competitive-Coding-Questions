/*
if given that
1)query given range

2)update single element

*/


#include<iostream>
using namespace std;

const int MAX = 1e5;
int a[MAX],n;
int seg_tree[2*MAX];

void build()
{
	for(int i=n-1;i>0;i--)
		seg_tree[i]=seg_tree[i<<1]+seg_tree[(i<<1)|1];
}

void update(int pos,int val)
{
	for(seg_tree[pos+=n]=val;i>1;i>>=1)
		seg_tree[i>>1]=seg_tree[i]+seg_tree[i^1];
}

int query(int l,int r)/*Query format: [2,4],[6,9]*/
{
	int i,j;
	int res=0;
	for(i=l+n,j=r+n;i<=j;)
	{
		if(i&1)
		{	res+=seg_tree[i];
			i++;
		}
		if((r&1)==0)
		{
			res+=seg_tree[j];
			j--;
		}	

		i>>=1;
		j>>=1;

	}

	return res;
}

int main()
{
	cout<<"Enter the size of array:\n";
	cin>>n;
	cout<<"Enter the array elements:\n";

	for(int i=0;i<n;i++)
	{	
		cin>>a[i];
		seg_tree[i+n]=a[i];
	}

	build();
}
