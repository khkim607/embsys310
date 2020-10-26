// unsigned int counter = 0;
int counter = 0x0;
int main()
{
// int counter = 0;
// unsigned int counter = 0;
  int *p_int = (int *)0x20000000;
  ++(*p_int);
  ++(*p_int);
  ++(*p_int);
  counter++;
 
 /*  counter++;
  counter++;
  counter++;
  counter++;
  counter++;
  counter++;
  counter++; */
/*  (void)counter; // to avoid no reference warning
  
  int x = 0xA;
  int y = 0xB;
  int result;
  
  result = x & y;
  result  = x && y; */
  return 0;
}
