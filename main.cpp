#include <iostream>
#include "file.h"

using namespace std;

int main(int argc, char** argv)
{
    file f("test.txt");
    f.readFile();
    f.printFile();
}