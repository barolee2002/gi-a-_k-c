#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define maxNum 100
#define NameLength 15
#define PhoneLength 11
#define EmailLength 20
typedef struct Address {
   char phone[maxNum][PhoneLength];
   char name[maxNum][NameLength];
   char email[maxNum][EmailLength];
} Addr;


void sort(Addr *l,int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(l->name[i], l->name[j]) > 0) {
                char tmp[NameLength];
                strcpy(tmp, l->name[i]);
                strcpy(l->name[i], l->name[j]);
                strcpy(l->name[j], tmp);

                char tmp1[EmailLength];
                strcpy(tmp1, l->email[i]);
                strcpy(l->email[i], l->email[j]);
                strcpy(l->email[j], tmp1);

                char tmp2[PhoneLength];
                strcpy(tmp2, l->phone[i]);
                strcpy(l->phone[i], l->phone[j]);
                strcpy(l->phone[j], tmp2);
         }
      }
   }
}
void Read() {
    FILE *fp = fopen("du_lieu.dat", "rb");
    Addr l;
    fread(&l, sizeof(Addr), 1, fp);
    if (fp == NULL) {
        printf("Error reading file!");
    } else {
        int i = 0;
        int n = 0;
        while (strcmp(l.name[n], "\0")) {
            n++;
        } 
        sort(&l,n);
        while (strcmp(l.name[i], "\0")) {
            printf("%d. %s - %s - %s\n", i + 1, l.name[i], l.phone[i], l.email[i]);
            i++;
        }
    }
    fclose(fp);
}
void binarySearch(Addr *l, char name[], int size) {
    int h = 0;
    int r = size - 1;
    while (h <= r) {
        int m = (h + r) / 2;
        int k = strcmp(name, l->name[m]);
        if (k == 0) {
            printf("Found! \n%d. %s - %s - %s\n", m + 1, l->name[m], l->phone[m], l->email[m]);
            return;
        }
        if (k > 0) {
            h = m + 1;
        }
        if (k < 0) {
            r = m - 1;
        }
    }
    printf("Not Found!");
}

void readAndSearch() {
    FILE *fp = fopen("du_lieu.dat", "rb");
    Addr l;
    fread(&l, sizeof(Addr), 1, fp);
    if (fp == NULL) {
        printf("Error reading file!");
    } else {
        int n = 0;
        while (strcmp(l.name[n], "\0")) {
            n++;
        }
        sort(&l, n);
        for (int i = 0; i < n; i++) {
            printf("%d. %s - %s - %s\n", i + 1, l.name[i], l.phone[i], l.email[i]);
        }
        printf("Numbers of query: ");
        int count;
        scanf("%d", &count);
        while (count--) {
            char name[NameLength];
            printf("\nEnter name:");
            scanf("%s", name);
            binarySearch(&l, name, n);
        }
    }
    fclose(fp);
};
struct node
{
    Addr data;
    struct node *pNext;
};
typedef struct node NODE;
typedef struct list
{
    NODE *pHead;
    NODE *pTail;
} LIST;
void GET(LIST &x)
{
    x.pHead = NULL;
    x.pTail = NULL;
}
NODE *getNode(Addr l)
{
    NODE *p = (NODE*)malloc(sizeof(NODE));
    if(p == NULL) {
        printf("Khong du bo nho de cap phat");
    }
    p->data = l;
    p->pNext = NULL;
    return p;
}
void ThemVaoCuoi(LIST &x,NODE *p)
{
    if(x.pHead == NULL) {
        x.pHead = x.pTail = p;
    }
    else {
        x.pTail ->pNext =p;
        x.pTail = p;
    }
}
void Link_list(LIST x)
{
    Addr l;
    FILE *fp = fopen("du_lieu.dat", "rb");
    fread(&l, sizeof(Addr), 1, fp);
    int n = 0;
    while(l.name[n] != "\0") {
        NODE *p = getNode(l);
        ThemVaoCuoi(x,p);
        n++;
    }
    int i =1;
    for(NODE *k = x.pHead; k!= NULL;k = k->pNext) {
        printf("%d. %s - %s - %s\n", i , (k->data).name, (k->data).phone, (k->data).email);
        i++;
    }
}
int main() {
    Addr l;
    LIST x;
    GET(x);
    while (1) {
      system("cls");
      printf("Menu: list \n1. Read address l from file and print out\n2. Search Address by array\n3. Read Address by link list\n 0. Exit\nSelect options:");
      int k;
      printf("\n\n\nChose : ");
      scanf("%d", &k);
      switch (k) {
        case 4:
            Link_list(x);
        case 1:
            Read();
            getch();
            break;
        case 2:
            readAndSearch();
            getch();
            break;
      case 0:
            return 0;
            break;
      }
    }
    getch();
}