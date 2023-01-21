/*
C program to append two arrays
*/

#include<stdio.h>
#include<string.h>
int main() {
   int a[20],b[20],c[40],a_len,b_len,i,j,k,m,n;

   printf("Enter number of elements in first array : ");
   scanf("%d",&m);
   printf("Enter the elements : ");
   for(i = 0; i < m; i++) {
      scanf("%d",&a[i]);
   }

   printf("Enter number of elements in second array : ");
   scanf("%d",&n);
   printf("Enter the elements : ");
   for(i = 0; i < n; i++) {
      scanf("%d",&b[i]);
   }

   for(i = 0; i < m; i++) {
      c[i]=a[i];
   }

   for(j = 0; j < n; j++) {
      c[j+m]=b[j];
   }

   printf("Array one ");
   for(i=0;i<m;i++){
      printf("%d ",a[i]);
   }
   printf("\n");
   printf("Array two ");
   for(i=0;i<n;i++){
      printf("%d ",b[i]);
   }
   printf("\n");
   printf("Arrays after appending : ");
   for(i=0;i<m+n;i++){
      printf("%d ",c[i]);
   }
   return 0;
}
