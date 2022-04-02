#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class FibLFSR {
public:
FibLFSR(string seed); // constructor to create LFSR with

//default constructor for testing
FibLFSR() = default;

//accessor functions
int returnSizeOfVector(const FibLFSR& obj);


// the given initial seed
int step(); // simulate one step and return the
// new bit as 0 or 1
int generate(int k); // simulate k steps and return
// k-bit integer

//insertion operator for printing the vector
friend ostream& operator<<(ostream& out, const FibLFSR& obj){
    
    for (int i = 0; i < (int)obj.vectorLFSR.size(); i++)
    {
        out << obj.vectorLFSR.at(i);
    }
    
    return out;
}

//deconstructor
~FibLFSR();

private:
std::vector<int> vectorLFSR;

};

