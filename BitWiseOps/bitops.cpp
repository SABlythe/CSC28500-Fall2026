#include <iostream>

#define NBITS sizeof(unsigned int)*8 

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

  cout << "Logical and (&&) gives ... "
       << (val1 && val2) << endl;

  cout << "Bitwise and (&) gives ... "
       << (val1 & val2) << endl;
  
  printBin(val1, NBITS);
  cout << endl;
  printBin(val2, NBITS);
  cout << endl;
  printBin(val1&val2, NBITS);
  cout << endl;

  cout << "Logical or (||) gives ... "
       << (val1 || val2) << endl;

  cout << "Bitwise and (|) gives ... "
       << (val1 | val2) << endl;
  
  printBin(val1, NBITS);
  cout << endl;
  printBin(val2, NBITS);
  cout << endl;
  printBin(val1|val2, NBITS);
  cout << endl;

  cout << "What bit position in " << val1 << " do you want to see? ";
  unsigned int pos;
  cin >> pos;

  unsigned mask = 1;
  mask = mask << pos;
  printBin(val1, NBITS);
  cout << endl;
  printBin(mask, NBITS);
  cout << endl;
  printBin(mask& val1, NBITS);
  cout << endl;

  if (mask&val1)
    cout << "it was a 1!" << endl;
  else
    cout << "it was a 0!" << endl;

  printBin(val1, NBITS);
  cout << endl;
  printBin(~val1, NBITS);
  cout << endl;
  
  return 0;
}
