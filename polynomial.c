#include<stdio.h>
struct poly
{
    int coeff;
    int expo;
};

struct poly p1[10],p2[10],p3[10],p4[10];
void main(){
    int t1,t2,t3;
    t1=readPoly(p1);
    printf("Enter the polynomial: ");
    displayPoly(p1,t1);
    t3 = addPoly(p1,p2,t1,t2,p3);
    printf("Second Polynomial: ");
    displayPoly(p2,t2);
    t3 = addPoly(p1,p2,t1,t2,p3);
    printf("\nResultant polynomial after addition: ");
    displayPoly(p3,t3);
    printf("\n");
    return 0;
}

int readPoly(struct poly p[10]){
    int t1,i;
    printf("\n\nEnter the total number of terms in polynomial: ");
    scanf("%d",&t1);
    printf("Enter coeff & exponent in DESCENDING Order: ");
    for(i=0; i<t1; i++){
        printf("Enter the coeff (%d): ",i+1);
        scanf("%d",&p[i].coeff);
        printf("Enter the exponent (%d): ");
        scanf("%d",&p[i].expo);
    }
    return (t1);
}

int addPoly(struct poly p1[10], struct poly p2[10],int t1,int t2, struct poly p3[10])
{
    int i=0,j=0,k=0;
    while (i<t1 && j<t2)
    {
        if (p1[i].expo == p2[j].expo){
            p3[k].coeff = p1[i].coeff + p2[j].coeff;
            i++;j++;k++;
        }
    }
    
}
