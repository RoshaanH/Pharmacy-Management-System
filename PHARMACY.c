#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int i=6;
char user[]="ron";
char pass[]="1234";
struct admin{
    char name[20];
    int quantity;
    float price;
}; //changess
void buy(struct admin y[]); // function through which customer will buy
void display(struct admin z[]); //display for adminitrator 
void display2(struct admin j[]);//display for customer
void update(struct admin p[]);//to update prices quantity of medicines 
void delete(struct admin v[]);//to delete medicines
void add(struct admin s[]);//to add any medicine


int main(){
    struct admin b[20];
    for (int i = 0; i < 20; i++)
    {
        b[i].quantity=0;
    }
    
    int admin;   //Adding Data of medicines that will show on the screen
    strcpy(b[0].name,"Azathioprine");
    b[0].quantity=30;
    b[0].price=90;
    strcpy(b[1].name,"Atorvastatin");
    b[1].quantity=4;
    b[1].price=900;
   strcpy(b[2].name,"Lisinopril");
    b[2].quantity=9;
    b[2].price=950;
   strcpy(b[3].name,"Amlodipine");
    b[3].quantity=7;
    b[3].price=550;
  strcpy(b[4].name,"Gabapentin");
    b[4].quantity=6;
    b[4].price=440;
  strcpy(b[5].name,"Azelastine");
    b[5].quantity=3;
    b[5].price=200;
    start:  
    printf("\n*************************PHARMACY MANAGEMENT*************************\n");
    printf("Press 1 for Administration Control\nPress 2 for Customer View\nPress 3 for Exit\n");
    scanf("%d",&admin);
        fflush(stdin);
       int add_rem,size;
        char n[15];
        char pas[10];
    switch(admin){
        case 1:
        printf("Input User Name: ");
        gets(n);
        fflush(stdin);
        printf("Input Password: ");
        gets(pas);
        if(strcmp(user,n)==0 && strcmp(pass,pas)==0){
        display(b);
        // size = sizeof(b)/sizeof(b[0]);
        // printf("%d\n\n",size);
        printf("Do you want to Add(1),Delete(0) or Update(2):\n");
        scanf("%d",&add_rem);
        if(add_rem==1){
        add(b);
        }
        else if(add_rem==0){
            delete(b);
        }
        else if(add_rem==2){
            update(b);
        }
        display(b);
        goto start;
    }
       else{
        printf("Invalid ID or Password. Please enter valid credentials.");
        }
         goto start;
        break;
        case 2:
        display2(b);
        buy(b);
        break;
        case 3:
        break;
        default:
        printf("Invalid Input");
    }

}
void buy(struct admin y[]){
   
    int j=0,sum=0,num,r=0,qty[20][40],price[20][40];
    char medicine[20][100];
    while (j!=1)
    {
    printf("\nInput List Number of Medicines you want to buy: ");
    scanf("%d",&num);
    printf("Input Quantity: ");
    scanf("%d",&qty[r][40]);
    if(qty[r][40]>y[num-1].quantity){
        printf("Sorry! But %d %s is not Available",qty[r][40],y[num-1].name);
        buy(y);
        exit(1);
    }
    else{
    strcpy(medicine[r],y[num-1].name);
    sum+=y[num-1].price*qty[r][40];
    y[num-1].quantity-=qty[r][40];
    price[r][40]=y[num-1].price;
    }
    r++;
    printf("\nMove to Checkout(1) or Continue Shopping(0)?");
    scanf("%d",&j);        
    }
        printf("*****************CheckOut Section********************\n");
    for (int k = 0; k<r; k++)
    {    
        
        printf("Product = %s \tQuantity = %d\tPrice = %d\n",medicine[k],qty[k][40],price[k][40]*qty[k][40]);
    }
    printf("\t\t\t\t\tTotal = %d",sum);
    
    
}
void display2(struct admin j[]){
    int i;
    for (i = 0; i < 20; i++)
    {
        if(j[i].quantity==0)
        continue;
        printf("%d.\t%s\t\tPrice=%.0f\n",i+1,j[i].name,j[i].price);
    }
}
void display(struct admin z[]){
    int i;
    for (i = 0; i < 20; i++)
    {
        if(z[i].quantity==0)
        continue;
        printf("%d.\t%s\tQuantity=%d\tPrice=%.0f\n",i+1,z[i].name,z[i].quantity,z[i].price);
    }
}
void update(struct admin p[]){
     int j=0,d,num,pr,qty;
     while (j!=1)
     {
        printf("Do you want to Update Price or Quantity?\nPress 1 for Price and 2 for Quantity\n");
        scanf("%d",&d);
        if(d==1){
            printf("Which Medicine to Update?\n");
            scanf("%d",&num);
            printf("Input New Price: ");
            scanf("%d",&pr);
            p[num-1].price=pr;
        }
        else if(d==2){
            printf("Which Medicine to Update?\n");
            scanf("%d",&num);
            printf("Input New Quantity: ");
            scanf("%d",&qty);
            p[num-1].quantity=qty;
        }
        else
        printf("Invalid Input");
        printf("Changed Succesfully!");
        printf("Update Again?(0 for Yes, 1 for No)\n");
        scanf("%d",&j);
     }
     
}
void delete(struct admin v[]){
    int j=0,n;
    while (j!=1)
    {
        printf("Which Medicine do you want to remove?\n");
        scanf("%d",&n);
        v[n-1].quantity=0;
        printf("Remove more Medicines?\n(Press 0 for Yes and 1 for No)\n");
        scanf("%d",&j);
    }
}
void add(struct admin s[]){
    int j=0;
    while (j!=1)
    {
        printf("Input Name of Medicine: ");
        scanf("%s",s[i].name);
        printf("Quantity of Meidicine: ");
        scanf("%d",&s[i].quantity);
        printf("Price of Medicine: ");
        scanf("%f",&s[i].price);
        i++;
        printf("Input more Medicines(0) or Exit(1)");
        scanf("%d",&j);

    }   
}