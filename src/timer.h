#include <ctime>
#include <string>
#include <iostream>

using namespace std;

class Timer
{
public:

    Timer()
    {
        start = clock();
    }
    
    Timer(const string& s) 
    {
        name = s;
        start = clock();
    }

    ~Timer()
    {
        cout << name << " " << clock() - start << " ms\n";
    }

private:
    clock_t start;
    string name;
};

