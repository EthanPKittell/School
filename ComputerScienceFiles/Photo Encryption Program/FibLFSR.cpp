/*

my name: Ethan Kittell
course name: computing 4
assignment: ps1a
instructors name: james daly
due date: 1/31
description of file: This is my file for function definitions of my LFSR header

*/
#include "FibLFSR.h"



FibLFSR::FibLFSR(string seed){


    //filling the vector with every element from the seed string
    for (int i = 0; i < (int)seed.length(); i++)
    {
        //this inserts the element of the seed string as a int
        //ASCII numbers start at 48 so that is why it is subtracted
    vectorLFSR.insert(vectorLFSR.begin()+i, ((int)seed[i] - 48));
    }


}

int FibLFSR::step(){
    int XOR;
    XOR = vectorLFSR.at(0) ^ vectorLFSR.at(2);
    XOR = XOR ^ vectorLFSR.at(3);
    XOR = XOR ^ vectorLFSR.at(5);
    //pops the front element of the vector
    vectorLFSR.erase(vectorLFSR.begin());

    vectorLFSR.push_back(XOR);
    

    return XOR;
}

int FibLFSR::generate(int k)
{
    
    int bitsExtracted = 0;

    for (int i = 0; i < k; i++)
    {
    bitsExtracted = bitsExtracted * 2;
    bitsExtracted = bitsExtracted + step();
    }
   
    return bitsExtracted;
}

FibLFSR::~FibLFSR(){

    vectorLFSR.clear();
    vectorLFSR.shrink_to_fit();
}

int FibLFSR::returnSizeOfVector(const FibLFSR& obj)
{
    return obj.vectorLFSR.size();
}
