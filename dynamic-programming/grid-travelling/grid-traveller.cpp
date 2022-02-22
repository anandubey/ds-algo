/*
 * Say that you are a traveller on a 2D grid. You begin in the
 * top-left corner and your goal is to travel to the bottom-right 
 * corner. You may only move down or right.
 * In how many ways can you travel to the goal on a grid with 
 * dimensions m * n?
 */


#include <time.h>
#include <iostream>
#include <map>

using namespace std;


long long grid_iterator (int rows, int cols, int **dp)
{
   for (int i=0; i < rows; i++) {
       dp[i][cols-1] = 1;
   }
   for (int i=0; i < cols; i++) {
        dp[rows-1][i] = 1;
   }
   for (int i=rows-2; i >= 0; i--) {
       for (int j=cols-2; j >= 0; j--) {
           dp[i][j] = dp[i+1][j] + dp[i][j+1];
       }
   }
   return dp[0][0];
}


long long grid_traveller_recursive (int row, int col)
{
    if (row == 1 || col == 1){
        return 1;
    }
    if (row == 0 || col == 0){
        return 0;
    }
    return grid_traveller_recursive(row-1, col) + grid_traveller_recursive(row, col-1);
}


long long grid_traveller (int row, int col, map<pair<int,int>, long long> &memo)
{
    if (memo.count(pair<int, int>(row, col)) > 0)
    {
        return memo.at(pair<int, int>(row, col));
    }

    if (row == 1 || col == 1)
    {
        return 1;
    }
    if (row == 0 || col == 0)
    {
        return 0;
    }
    memo.insert(pair<pair<int, int>, long long> (pair<int, int>(row, col), grid_traveller(row - 1, col, memo) + grid_traveller(row, col-1, memo)));
    return memo.at(pair<int, int>(row, col));
}


int main()
{
    double time_taken;
    clock_t t;
    long long no_of_path;


    cout << "============= USING DP-ITERATION ==============" << endl;
    
    int *dp_1_1[1];
    t = clock();
    no_of_path = grid_iterator(1, 1, dp_1_1);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    cout << "grid_iterator(1, 1) = " << no_of_path << " took " << time_taken << " seconds to execute.\n";
    
    int *dp_2_3[3];
    t = clock();
    no_of_path = grid_iterator(2, 3, dp_2_3);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    cout << "grid_iterator(2, 3) = " << no_of_path << " took " << time_taken << " seconds to execute.\n";

    
    int *dp_3_2[2];
    t = clock();
    no_of_path = grid_iterator(3, 2, dp_3_2);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    cout << "grid_iterator(3, 2) = " << no_of_path << " took " << time_taken << " seconds to execute.\n";

    
    int *dp_4_3[3];
    t = clock();
    no_of_path = grid_iterator(4, 3, dp_4_3);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    cout << "grid_iterator(4, 3) = " << no_of_path << " took " << time_taken << " seconds to execute.\n";

    
    int *dp_18_18[18];
    t = clock();
    no_of_path = grid_iterator(18, 18, dp_18_18);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    cout << "grid_iterator(18, 18) = " << no_of_path << " took " << time_taken << " seconds to execute.\n";


    cout << "============= USING RECURSION==============" << endl;
 
    t = clock();
    no_of_path = grid_traveller_recursive(1, 1);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    cout << "grid_traveller(1, 1) = " << no_of_path << " took " << time_taken << " seconds to execute.\n";

    t = clock();
    no_of_path = grid_traveller_recursive(2, 3);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    cout << "grid_traveller(2, 3) = " << no_of_path << " took " << time_taken << " seconds to execute.\n";

    t = clock();
    no_of_path =  grid_traveller_recursive(3, 2);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    cout << "grid_traveller(3, 2) = " << no_of_path << " took " << time_taken << " seconds to execute.\n";

    t = clock();
    no_of_path =  grid_traveller_recursive(4, 3);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    cout << "grid_traveller(4, 3) = " << no_of_path << " took " << time_taken << " seconds to execute.\n";

    t = clock();
    no_of_path =  grid_traveller_recursive(18, 18);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    cout << "grid_traveller(18, 18) = " << no_of_path << " took " << time_taken << " seconds to execute.\n";
    


    cout << "============= USING DP-MEMOIZATION==============" << endl;

    map<pair<int, int>, long long> memo;

    t = clock();
    no_of_path = grid_traveller(1, 1, memo);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    cout << "grid_traveller(1, 1) = " << no_of_path << " took " << time_taken << " seconds to execute.\n";
    memo.clear();

    t = clock();
    no_of_path = grid_traveller(2, 3, memo);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    cout << "grid_traveller(2, 3) = " << no_of_path << " took " << time_taken << " seconds to execute.\n";
    memo.clear();

    t = clock();
    no_of_path = grid_traveller(3, 2, memo);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    cout << "grid_traveller(3, 2) = " << no_of_path << " took " << time_taken << " seconds to execute.\n";
    memo.clear();

    t = clock();
    no_of_path = grid_traveller(4, 3, memo);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    cout << "grid_traveller(4, 3) = " << no_of_path << " took " << time_taken << " seconds to execute.\n";
    memo.clear();

    t = clock();
    no_of_path = grid_traveller(18, 18, memo);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    cout << "grid_traveller(18, 18) = " << no_of_path << " took " << time_taken << " seconds to execute.\n";
    memo.clear();


    return 0;
}
