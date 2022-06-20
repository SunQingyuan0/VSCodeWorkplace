/*Write a program that finds and displays all pairs of 5-digit numbers that between them use the digits 0
through 9 once each, such that the first number divided by the second is equal to an integer N, where
2 ≤ N ≤ 79. That is,
abcde
fghij = N
where each letter represents a different digit. The first digit of one of the numerals is allowed to be
zero.
Input
Each line of the input file consists of a valid integer N. An input of zero is to terminate the program.
Output
Your program have to display ALL qualifying pairs of numerals, sorted by increasing numerator (and,
of course, denominator).
Your output should be in the following general form:
xxxxx / xxxxx = N
xxxxx / xxxxx = N
.
.
In case there are no pairs of numerals satisfying the condition, you must write ‘There are no
solutions for N.’. Separate the output for two different values of N by a blank line.
Sample Input
61
62
0
Sample Output
There are no solutions for 61.
79546 / 01283 = 62
94736 / 01528 = 62*/
#include <iostream>
#include <string.h>
using namespace std;
struct Number{
    int arr[5];
    void cal(int num){
        int sum=1;
        for(int i = 0; i < 5; ++i){
            arr[i]=(num/sum)%10;
            sum*=10;
        }
    }
};
int main(){
    int n,m,ans,x,count[10];
    bool flag=true;
    while(scanf("%d", &n) != EOF&&n != 0){
        x=0;
        if(flag){
            flag=false;
        }else{
            cout<<endl;
        }
        for(int i = 1234; i < 98765; i++){
        ans = i*n;
        Number nu[2];
        memset(count,0,sizeof(count));
        nu[0].cal(i);
        nu[1].cal(ans);
        if(ans > 98765) break;      
        for(int j = 0; j < 5; ++j){
            count[nu[0].arr[j]]++;
            count[nu[1].arr[j]]++;
        }
        for(m = 0; m <= 9; m++){

            if(count[m]>1){
                break;
            }
        }
        if(m == 10){
            printf("%d%d%d%d%d / %d%d%d%d%d = %d\n", nu[1].arr[4], nu[1].arr[3], nu[1].arr[2], nu[1].arr[1], nu[1].arr[0], nu[0].arr[4], nu[0].arr[3], nu[0].arr[2], nu[0].arr[1], nu[0].arr[0], n);
            x++;
        }else{
            continue;
        }   
    }
    if(x == 0){
        cout<<"There are no solutions for "<<n<<"."<<endl; 
    }
    }
    return 0;
}