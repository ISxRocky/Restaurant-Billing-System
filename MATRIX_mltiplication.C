#include<stdio.h>
#include<conio.h>

void main()
{

    int i,j,k,m,n,p,q;
    int (*a)[10],(*b)[10],(*pr)[10];
    error:
    printf("\nEnter the value of m & n:");
    scanf("%d%d",&m,&n);
    printf("\nEnter the value of p & q:");
    scanf("%d%d",&p,&q);

    if(n!=p){
        printf("\nMatrix multiplication is not possible for these matrix!");
        goto error;
    }
    printf("Enter the Matrix A:\n");

    for (i=0;i<m;i++)
    {
        for (j=0; j< n;j++){
        scanf("%d",(*(a+i)+j));
        }
    printf("\n");
    }
    printf("Enter the Matrix B:\n");
    for (i=0;i<p;i++)
    {
        for (j=0;j<q;j++){
        scanf("%d",(*(b+i)+j));
        }
    printf("\n");
    }
    printf(" Matrix A*B:\n");

    for(i=0; i<m; i++)
    {
        for(j=0; j<q; j++)
        {
            (*(*(pr+i)+j))=0;
            for(k=0; k<n; k++)
            {
                (*(*(pr+i)+j)) += (*(*(a+i)+k)) * (*(*(b+k)+j));
            }
            printf("%d\t",(*(*(pr+i)+j)));
        }
        printf("\n");

    }
    getch();
}
