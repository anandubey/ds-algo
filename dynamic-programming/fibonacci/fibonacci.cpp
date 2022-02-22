#include <map>
#include <time.h>
#include <iostream>
#include <iterator>

using std::cout;
using std::map;
using std::pair;


long long fibo_iter (int n)
{
    long long fib_val = 1, prev_fib_val = 1, temp = 0;
    for (int i=0; i < n; i++)
    {
        if (n <= 2)
        {
            break;
        }
        temp = fib_val + prev_fib_val;
        prev_fib_val = fib_val;
        fib_val = temp;
    }
    return fib_val;
}


long long fibo_recur (int n)
{
    if (n <= 2)
    {
        return 1;
    }
    return fibo_recur(n-1) + fibo_recur(n-2);
}


long long fibo_dp (int n, map<int, long long> &memo)
{
    if (memo.count(n) > 0)
    {
        return memo.at(n);
    }
    if (n <= 2)
    {
        return 1;
    }
    memo.insert(pair<int, long long> (n, fibo_dp(n-1, memo) + fibo_dp(n-2, memo)));
    return memo.at(n);
}


int main()
{
    cout << "============Fibonacci using iteration=============\n";

    double time_taken;
    clock_t t;
    t = clock();
    fibo_iter(6);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    cout << "fibo_iter(6) took " << time_taken <<  " seconds to execute \n";

    t = clock();
    fibo_iter(20);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    cout << "fibo_iter(20) took " << time_taken <<  " seconds to execute \n"; 

    t = clock();
    fibo_iter(46);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    cout << "fibo_iter(45) took " << time_taken <<  " seconds to execute \n";
    


    cout << "\n\n\n=============Fibonacci using recursion=============\n";

    t = clock();
    fibo_recur(6);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    cout << "fibo_recur(6) took " << time_taken <<  " seconds to execute \n";

    t = clock();
    fibo_recur(20);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    cout << "fibo_recur(20) took " << time_taken <<  " seconds to execute \n"; 

    t = clock();
    fibo_recur(46);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    cout << "fibo_recur(45) took " << time_taken <<  " seconds to execute \n";



    cout << "\n\n\n============Fibonacci using dynamic programming=============\n";

    map <int, long long> memo;
    t = clock();
    fibo_dp(6, memo);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    cout << "fibo_dp(6) took " << time_taken <<  " seconds to execute \n";

    memo.clear();
    t = clock();
    fibo_dp(20, memo);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    cout << "fibo_dp(20) took " << time_taken <<  " seconds to execute \n"; 

    memo.clear();
    t = clock();
    fibo_dp(46, memo);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    cout << "fibo_dp(45) took " << time_taken <<  " seconds to execute \n";
    

    return 0;
}
