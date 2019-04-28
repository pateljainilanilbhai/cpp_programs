#include <iostream>


using namespace std;
void merge(int v[], int p, int q, int r) {
    int i, j, k, b[10];
    for (i = p; i <= q; i++) {
        b[i] = v[i];
    }
    for (j = q + 1; j <= r; j++) {
        b[r + q + 1 - j] = v[j];
    }
    i = p;
    j = r;
    for (k = p; k <= r; k++) {
        if (b[i] <= b[j]) {
            v[k] = b[i];
            i++;
        } else {
            v[k] = b[j];
            j--;
        }
    }
}


void mersort(int v[], size_t len)
{
    if (len < 2)
        return;

    size_t mid = len/2;
    mersort(v, mid);
    mersort(v+mid, len-mid); // see here.
    merge(v, mid, len);
}



void mersort3(int v[], size_t len)
{
    if (len < 3)
    {
        mersort(v, len);
        return;
    }

    size_t m1 = len/3;
    size_t m2 = (2 * len)/3;
    mersort3(v, m1);
    mersort3(v+m1, m2-m1);   // see here
    mersort3(v+m2, len-m2);  // and here
    merge(v, m1, m2);
    merge(v, m2, len);
}
int main()
{
    cout<<"Enter size of array";
    cin>>n;
    int a[n];
    cout<<"Enter "<<n<<" integers ";

    for(int i=0.;i<n;i++)
    {
        cin>>a[i];
    }
    mersort3(a,n);
    cout<<"\n";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<",";
    }
}
