#include <stdio.h>
union myUnion
 {
  int i;
  float f;
} data;

int main() {
  char input[10]; 
  printf("Enter a value of your choice (integer or float): ");
  fgets(input, 10, stdin); 
  
  if (sscanf(input, "%d", &data.i) == 1) {
    
    printf("You entered an integer: %d\n", data.i);
  } 
  else if (sscanf(input, "%f", &data.f) == 1) 
  {
    printf("You entered a float: %.2f\n", data.f);
  } else {
    // User did not enter a valid number
    printf("Invalid input.\n");
  }

  return 0;
}