/*A message from humans to extraterrestrial intelligence was sent through the Arecibo radio telescope in Puerto Rico on the afternoon of Saturday November 16, 1974. The message consisted of 1679 bits and was meant to be translated to a rectangular picture with 23 * 73 pixels. Since both 23 and 73 are prime numbers, 23 * 73 is the unique possible size of the translated rectangular picture each edge of which is longer than 1 pixel. Of course, there was no guarantee that the receivers would try to translate the message to a rectangular picture. Even if they would, they might put the pixels into the rectangle incorrectly. The senders of the Arecibo message were optimistic.
We are planning a similar project. Your task in the project is to find the most suitable width and height of the translated rectangular picture. The term "most suitable" is defined as follows. An integer m greater than 4 is given. A positive fraction a / b less than or equal to 1 is also given. The area of the picture should not be greater than m. Both of the width and the height of the translated picture should be prime numbers. The ratio of the width to the height should not be less than a / b nor greater than 1. You should maximize the area of the picture under these constraints.

In other words, you will receive an integer m and a fraction a / b. It holds that m > 4 and 0 < a / b < 1. You should find the pair of prime numbers p, q such that pq <= m and a / b <= p / q <= 1, and furthermore, the product pq takes the maximum value among such pairs of two prime numbers. You should report p and q as the "most suitable" width and height of the translated picture.
The input is a sequence of at most 2000 triplets of positive integers, delimited by a space character in between. Each line contains a single triplet. The sequence is followed by a triplet of zeros, 0 0 0, which indicated the end of the input and should not be treated as data to be processed.

The integers of each input triplet are the integer m, the numerator a, and the denominator b described above, in this order. You may assume 4 < m <= 100000 and 1 <= a <= b <= 1000.
The output is a sequence of pairs of positive integers. The i-th output pair corresponds to the i-th input triplet. The integers of each output pair are the width p and the height q described above, in this order.

Each output line contains a single pair. A space character is put between the integers as a delimiter. No other characters should appear in the output.
Sample Input
5 1 2
99999 999 999
1680 5 16
1970 1 1
2002 4 11
0 0 0
Sample Output
2 2
313 313
23 73
43 43
37 53*/

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
bool IsPrime(int n)
{
    if(n==2)return true;
    if(n%2==0)return false;
    int i;
    for(i=3;i<=sqrt(n);i+=2)
    {
        if(n%i==0)return false;
    }
    return true;
}
int DataPrime[100010];
int Init()
{
    int count=0;
    int i=2;
    while (true)
    {
        if(IsPrime(i))
        {
            DataPrime[count]=i;
            count++;
            i++;
            if(i>100000)return count;
        }
        else
        {
            i++;
        } 
    }
}
int countsize(int m)
{
    int len=0;
    while (DataPrime[len]<=m)
    {
        len++;
    }
    return len;
}
int main()
{
    int len=Init();
    while (true)
    {
        int m,a,b;
        scanf("%d%d%d",&m,&a,&b);
        if(m==0&&a==0&&b==0)break;
        // int len=countsize(m);
        int max=0;
        int x,y;
        for(int i=0;i<=sqrt(m);i++)
        {
            for(int j=i;j<=len;j++)
            {
                if(DataPrime[i]*DataPrime[j]<=m&&DataPrime[i]*b>=a*DataPrime[j])
                {
                    if(DataPrime[i]*DataPrime[j]>max)
                    {
                        max=DataPrime[i]*DataPrime[j];
                        x=DataPrime[i];
                        y=DataPrime[j];
                    }
                }
            }
        }
        printf("%d %d\n",x,y);
    }
    
}