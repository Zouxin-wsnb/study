#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int a,b,c;
        long double temp;
        scanf("%d %d %d",&a,&b,&c);
        if(a>=2&&a<=1000&&b>=2&&b<=1000&&c>=2&&c<=1000){
            temp = (long double)a / b;
            printf("%.*Lf\n",c,temp); 
        }
    }
    return 0;
}