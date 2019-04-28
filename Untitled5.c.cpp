int x, y, a = 0, i, t, j;
cout << "enter two numbers" << endl;
cin >> x >> y; // x as the number in base-10 and x, as the destination base
a = x;
while (x >= y)
{
    t = 1;
    for (i = 0; x > y; i++)
    {
        x /= y;
    }
    cout << x;
    for (j = 0; j < i; j++)
    {
        t *= y;
    }
    a = a - (t*x);
    x = a;
}
cout << x<<endl;
