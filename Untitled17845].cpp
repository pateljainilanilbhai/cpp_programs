#include<iostream>
using namespace std;
unsigned int binaryToGray(unsigned int num)
{
    return num ^ (num >> 1);
}

/*
 * This function converts a reflected binary
 * Gray code number to a binary number.
 * Each Gray code bit is exclusive-ored with all
 * more significant bits.
 */
unsigned int grayToBinary(unsigned int num)
{
    unsigned int mask;
    for (mask = num >> 1; mask != 0; mask = mask >> 1)
    {
        num = num ^ mask;
    }
    return num;
}

/*
 * A more efficient version, for Gray codes of 32 or fewer bits.
 */
unsigned int grayToBinary32(unsigned int num)
{
    num = num ^ (num >> 16);
    num = num ^ (num >> 8);
    num = num ^ (num >> 4);
    num = num ^ (num >> 2);
    num = num ^ (num >> 1);
    return num;
}
int main()
{
    cout<<binaryToGray(11000000);
}
