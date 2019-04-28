#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//disjoint set data
int fathers[100];

int find(int x)
{
    if(fathers[x]==x)
    {
        return x;
    }
    return find(fathers[x]);
}

void unite(int x,int y)
{
    int setofx=find(x);
    int setofy=find(y);
    fathers[setofx]=setofy;
}

class edges
{
    public:
    int a;
    int b;
    int w;
};


//kruskal
int main()
{

    //initialize the set
    for(int i=0;i<100;i++)
    {
        fathers[i]=i;
    }
    int n,m;
    int a,b,w;

    cout<<"Enter n and m\n";
        cin>>n>>m;
         edges e[m];

    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>w;
        e[i].a=a;
        e[i].b=b;
        e[i].w=w;

    }
    cout<<endl;
    int mst_weight=0;
    int mst_edges=0;
    int mst_ni=0;

    //sort(e.begin(),e.end());
    //sorting


    int i, j;
   for (i = 0; i < n-1; i++)
       for (j = 0; j < n-i-1; j++)
           if (e[j].w > e[j+1].w)
              {
                   edges temp;
                temp=e[j];
                e[j]=e[j+1];
                e[j+1]=temp;


            };





    cout<<endl<<"sorted edges"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<e[i].w<<" ";
    }



    while((mst_edges<n-1)||(mst_ni<m))
    {
        a=e[mst_ni].a;
         b=e[mst_ni].b;
          w=e[mst_ni].w;

          if(find(a)!=find(b))
          {
              unite(a,b);
              mst_weight+=w;
              cout<<a<<" "<<b<<" "<<w<<endl;
              mst_edges++;
          }
        mst_ni++;
    }

    cout<<"\nWeight of the MST is "<<mst_weight<<endl;
}
