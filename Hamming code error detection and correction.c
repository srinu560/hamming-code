
#include <stdio.h>
#include<string.h>
void encoding();
void Decode();
void read();
int n,a[10],b[20];
void main() {
    int i,p=1,r=0,j,ch;
    printf("**MENU**\n1.Encoding\n2.Decoding\n3.Exit\n");
   do{
    	printf("Enter your choice:\n");
    	scanf("%d",&ch);
    	switch(ch){
    	case 1:read();	
    			encoding();
  			  break;
  	 case 2:read();
  	 Decode();
  	 break;
  	 /*case 3:
  	 break;*/
}}while(ch<3);
}
void encoding(){
    int count=0,p=1,i=1,j,l,r=0;
    //calculating nilo of parity bits
    while(p<n+r+1){
        p=p*2;
        r++;
    }
    l=n+r;
    printf("Parity:%d\n",r);
    i=1;
    p=1;
    j=n-1;
    printf("The string is:\n");
    while(i<=l){
        if(i==p){
            p=p*2;
            b[i-1]=0;
        }
        else{
            b[i-1]=a[j];
            j--;
        }
        printf("%d",b[i-1]);
        i++;
    }
    p=1;
    i=1;
    while(i<=r){
        j=p;
        printf(" %d,%d ",j,p);
        while(j<=l){
            if(count<p){
                b[p-1]=b[p-1]^b[j-1];
                j++;
                ++count;    
                if(count==p){
                    j=j+(p);
                    count=0;
                }
            }  
    }
    printf(" %d ",b[p-1]);
    p=p*2;
    i++;
    }
    printf("\nthe output string is:\n");
    		for(i=l;i>0;i--){
        	printf(" %d ",b[i-1]);
    }
}
void read(){
	int i;
	printf("Enter the length of the string:\n");
    scanf("%d",&n);
    printf("Enter the string:\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }	
}
void Decode(){
	int count=0,p=1,i=1,j,r=0,temp,result=0;
    //calculating nilo of parity bits
    while(p<n){
        p=p*2;
        r++;
    }
        printf("Parity:%d\n",r);
    p=1;
    i=1;
    while(i<=r){
        j=p;
        temp=0;
        while(j<=n){
            if(count<p){
                temp=temp^a[j-1];
                printf("%d ",j);
                j++;
                ++count;    
                if(count==p){
                    j=j+(p);
                    count=0;
                }
            }
    }
    printf(" %d ",temp);
    result+=temp*p;
    p=p*2;
    i++;
    }
    printf("\nThe error at position:%d\n",result);
}
