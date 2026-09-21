#include <iostream>

using namespace std;

void printBin(unsigned int num,
	      unsigned int nbits,
	      ostream &toStream = cout)
{
  if (nbits==0)
    return;
  else
    {
      unsigned rem = num %2;
      printBin(num/2, nbits-1, toStream);
      toStream << rem;
    }
}

int main (int argc, char *argv[])
{
  if (argc!=3)
    {
      cerr << "USAGE: " << argv[0]
	   << " <val1> <val2> " << endl;
      return 1;
    }
  
  unsigned int val1 = stoi(argv[1]);
  unsigned int val2 = stoi(argv[2]);

  printBin(val1, 32);
  cout << endl;
  printBin(val2, 32);
  cout << endl;
  
  

  return 0;
}
