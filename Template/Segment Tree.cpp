#include<bits/stdc++.h>
using namespace std;
int tree[400005],lazy[400005],v,A[100005];
void build(int node, int start, int end)
{
	if(start == end)
	{
		// Leaf node will have a single element
		tree[node] = A[start];
	}
	else
	{
		int mid = (start + end) / 2;
		// Recurse on the left child
		build(2*node, start, mid);
		// Recurse on the right child
		build(2*node+1, mid+1, end);
		// Internal node will have the sum of both of its children
		tree[node] = tree[2*node] + tree[2*node+1];
	}
}
void updateRange(int node, int start, int end, int l, int r, int val)
{
	if(lazy[node] != 0)
	{ 
		// This node needs to be updated
		tree[node] += (end - start + 1) * lazy[node];    // Update it
		if(start != end)
		{
			lazy[node*2] += lazy[node];                  // Mark child as lazy
			lazy[node*2+1] += lazy[node];                // Mark child as lazy
		}
		lazy[node] = 0;                                  // Reset it
	}
	if(start > end or start > r or end < l)              // Current segment is not within range [l, r]
		return;
	if(start >= l and end <= r)
	{
		// Segment is fully within range
		tree[node] += (end - start + 1) * val;
		if(start != end)
		{
			// Not leaf node
			lazy[node*2] += val;
			lazy[node*2+1] += val;
		}
		return;
	}
	int mid = (start + end) / 2;
	updateRange(node*2, start, mid, l, r, val);        // Updating left child
	updateRange(node*2 + 1, mid + 1, end, l, r, val);   // Updating right child
	tree[node] = tree[node*2] + tree[node*2+1];        // Updating root with max value 
}

int queryRange(int node, int start, int end, int l, int r)
{
	if(start > end or start > r or end < l)
		return 0;         // Out of range
	if(lazy[node] != 0)
	{
		// This node needs to be updated
		tree[node] += (end - start + 1) * lazy[node];            // Update it
		if(start != end)
		{
			lazy[node*2] += lazy[node];         // Mark child as lazy
			lazy[node*2+1] += lazy[node];    // Mark child as lazy
		}
		lazy[node] = 0;                 // Reset it
	}
	if(start >= l and end <= r)             // Current segment is totally within range [l, r]
		return tree[node];
	int mid = (start + end) / 2;
	int p1 = queryRange(node*2, start, mid, l, r);         // Query left child
	int p2 = queryRange(node*2 + 1, mid + 1, end, l, r); // Query right child
	return (p1 + p2);
}
int main(){

	int t,n,c,typ,p,q;
	cin>>t;
	while(t--){
		cin>>n>>c;
		build(1,0,n-1);
		for(int i=0;i<c;i++){
			scanf("%d",&typ);
			if(typ){
				scanf("%d%d",&p,&q);
				p--;
				q--;
				cout<<queryRange(1,0,n-1,p,q)<<"\n";
			}
			else{
				scanf("%d%d%d",&p,&q,&v);
				p--;
				q--;
				updateRange(1,0,n-1,p,q,v);
			}
		}
	}
}
