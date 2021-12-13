#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#define MAXSTACK 30
char NODE[MAXSTACK];
int numNODE[MAXSTACK];
int m = 0, n = 0;
void Push(char opt) {
   if (m == MAXSTACK - 1) {
      printf("Stack is full");
      return;
   }
   NODE[m] = opt;
   m++;
}
char pop() {
   if (m == 0) {
      printf("Stack is empty");
      return '\n';
   }
   return NODE[--m];
}
char TOP() 
{ 
   return NODE[m - 1]; 
}
bool Order(char c) {
   if (c == '+' || c == '-')
      return false;
   else
      return true;
}
void startNUM(int x) {
   if (n == MAXSTACK - 1) {
      printf("Stack is full");
      return;
   }
   numNODE[n] = x;
   n++;
}
int popNum() {
   if (n == 0) {
      printf("Stack is empty");
      return '\n';
   }
   return numNODE[--n];
}
int main() {
   printf("Enter Infix Expression : ");
   char c = getchar();
   int x;
   int result = 0;
   printf("Postfix Expression = ");
   do {
      if ('0' <= c && c <= '9') {
         startNUM((int)c - '0');
         putchar(c);
         putchar(' ');
      } else {
         int order = Order(c);
         while (m > 0 && Order(TOP()) >= order) {
            char opt= pop();
            int tmp = popNum();
            if (opt== '+')
               tmp += popNum();
            if (opt== '-')
               tmp = popNum() - tmp;
            if (opt== '*')
               tmp *= popNum();
            if (opt== '/')
               tmp = popNum() / tmp;
            startNUM(tmp);
            putchar(opt);
            putchar(' ');
         }
         Push(c);
      }
      c = getchar();
   } while (c != '\n');
   while (m > 0) {
      char opt= pop();
      int tmp = popNum();
      if (opt== '+')
         tmp += popNum();
      if (opt== '-')
         tmp = popNum() - tmp;
      if (opt== '*')
         tmp *= popNum();
      if (opt== '/')
         tmp = popNum() / tmp;
      startNUM(tmp);
      putchar(opt);
      putchar(' ');
   }
   result = popNum();
   printf("\nResult = %d", result);
   getch();
}