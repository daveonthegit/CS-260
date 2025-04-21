#IVERSON
#include <iostream>
using namespace std;
int main() {
  struct foo_t {
    int x[100];
    int var1;
    int y[10];
    } foo;
  int var2;
  long i;
  int *p, *q;
  short int *s;
  long int *l;
  struct foo_t bar[50];

  for (i=0; i<100; i++) foo.x[i]=300+i;
  for (i=0; i<10; i++)  foo.y[i]=800+i;
  foo.var1 = 440;

  cout << sizeof(*s) << "\n";
  cout << sizeof(*p) << "\n";
  cout << sizeof(*l) << "\n";
  cout << "Pointer size: " << sizeof(p) << " bytes" << endl;
  q = (int *) &foo;    
  cout << q << "\n";
  p=&(foo.x[5]);       
  cout << *p << "\n";
  // POINT 1
  q = (int *) &var2;   
  cout << q << "\n";
  q = p+16;            
  cout << *q << "\n";
  i = ((long) p) + 16;
  q = (int *) i;       
  cout << *q << "\n";
  s = (short *) i;     
  cout << *s << "\n";
  l = (long *) i;      
  cout << *l << "\n";
  q = p+95;     
  cout << q << "\n";         
  cout << *q << "\n";  
  i = ((long) p) + 17;
  q = (int *) i;       
  cout << *q << "\n";  //IVERSON EXPLAIN [This result is achieved because it is pointing to the wrong space in memory.
  //Rather than pointing to an integer it is pointing to one of the 4 bytes that makeup the integer, to get an integer it should be 
  //increased w/ multiples of 4.]
  q = p + 101;     
  cout <<q<<"\n";
  cout << *q << "\n";
  q = (int *) (((long) p) + 404);  //This is an example of which, 404 is the byte position equivalent of where p + 101 is.
  cout << *q << "\n";
  p = (int *) bar; // p is now set to the address location of bar
  *(p + 988) = 947; cout << bar[8].var1 << "\n"; //Each foo_t struct is roughly 444 bytes large, so skip ahead 444*8, and var1 is after x[100]
  //which takes up 400 bytes, so you'd skip ahead (444*8)+400 bytes, which is 3952 bytes. And since we're working w/ integers
  // we must convert to integers, so 3952/4 = 988.
  cout << "Address of foo: " << &foo << "\n";
  cout << "Address of bar: " << &bar << "\n";
  cout << "Address of foo.x: " << &foo.x << "\n";
  cout << "Address of foo.var1: " << &foo.var1 << "\n";
  cout << "Address of foo.y: " << &foo.y << "\n";
  cout << "Address of var2: " << &var2 << "\n";
  cout << "Address of i: " << &i << "\n";
  cout << "Address of p: " << &p << "\n";
  cout << "Address of q: " << &q << "\n";
  cout << "Address of s: " << &s << "\n";
  cout << "Address of l: " << &l << "\n";
}
