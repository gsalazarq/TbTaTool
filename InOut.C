// writing on a text file
#include <iostream>
#include <fstream>
using namespace std;

int inout () {
  ofstream myfile ("example.txt");
  if (myfile.is_open())
  {


    for(int i=0; i<10; i++){
      myfile << "This is a line.\n";
      myfile << "This is another line.\n";

    }
    myfile.close();
  }
  else cout << "Unable to open file";
  return 0;
}
