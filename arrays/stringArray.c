#include <stdio.h>
#include <string.h>
void string_functions(char *str);

int main(){

  char str[5];
  printf("Enter a string ? ");
  gets(str);
  printf("The string is = %s\n", str);
  string_functions(str);
  return 0;
}
void string_functions(char *str){
  int length = strlen(str);
  char str2[5];
  printf("The length of the string is = %d\n",length);
  strcpy(str2, str);
  printf("Copying the string to str2 gives =  %s\n", str2);       
   
}
