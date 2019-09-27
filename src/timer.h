#ifndef __TIMER_H__
#define __TIMER_H__

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
        long diff = clock() - start;    // clicks
        long ms = diff / (CLOCKS_PER_SEC/1000);
        long s = ms / 1000;
        long min = s / 60;
        cout << name << ": " << ms << " ms, " << s << " s, " << min << " min\n";
        //cout << "CLOCKS_PER_SEC = " << CLOCKS_PER_SEC << "\n";
    }

private:
    clock_t start;
    string name;
};

#endif

