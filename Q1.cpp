#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <chrono>
#include "genFiles.h"

using namespace std;

void task1(){
    int n;
    cin >> n;

    generate_p1(n);                                             //generates the random data in a file called p1.txt

    auto start = chrono::high_resolution_clock::now();

    ifstream p1;
    p1.open("p1.txt");


    vector<int> arr;
    for(int i = 0; i < n; i++){                                 //read data from file into vector
        int temp;
        p1 >> temp;
        arr.push_back(temp);
    }

    p1.close();

    long long sum = INT_MIN;
    int l = 0, r = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            long long tempsum = 0;
            for(int k = i; k <= j; k++){                    //iterate through entire subarray and sum the elements
                tempsum += arr[k];
            }
            if(tempsum > sum){
                sum = tempsum;
                l = i;
                r = j;
            }
        }
    }
    cout << l << " " << r << " " << sum << endl;
    auto end = chrono::high_resolution_clock::now();
    cout << "Execution time: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;
}

void task2(){
    int n;
    cin >> n;

    generate_p1(n);                                             //generates the random data in a file called p1.txt

    auto start = chrono::high_resolution_clock::now();          //used for start of execution time

    ifstream p1;
    p1.open("p1.txt");


    vector<int> arr;
    for(int i = 0; i < n; i++){                                 //read data from file into vector
        int temp;
        p1 >> temp;
        arr.push_back(temp);
    }

    p1.close();

    long long sum = arr[0];
    int l = 0, r = 0;
    vector<long long> dp;
    dp.push_back(0);
    for(int i = 1; i <= n; i++){
        dp.push_back(arr[i - 1] + dp[i - 1]);                   //make a dp array with the sum of the values of the array up to each index
    }
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            if(dp[j] - dp[i] > sum){                            //calculate sum of nums from i to j
                sum = dp[j] - dp[i];
                l = i;
                r = j - 1;
            }
        }
    }
    cout << l << " " << r << " " << sum << endl;
    auto end = chrono::high_resolution_clock::now();
    cout << "Execution time: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;
}

void task3a(){
    int n;
    cin >> n;

    generate_p1(n);                                             //generates the random data in a file called p1.txt

    auto start = chrono::high_resolution_clock::now();          //used for start of execution time

    ifstream p1;
    p1.open("p1.txt");


    vector<int> arr;
    for(int i = 0; i < n; i++){                                 //read data from file into vector
        int temp;
        p1 >> temp;
        arr.push_back(temp);
    }

    p1.close();

    long long prevsum = 0, sum = INT_MIN;
    int l = 0, r = 0;
    for(int i = 0; i < n; i++){                                 //kadanes algorithm and update indices within
        prevsum += arr[i];
        if(prevsum < 0){
            prevsum = 0;
            l = i + 1;
        }
        if(prevsum > sum){
            sum = prevsum;
            r = i;
        }
    }
    cout << l << " " << r << " " << sum << endl;
    auto end = chrono::high_resolution_clock::now();
    cout << "Execution time: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;
}

void task3b(){
    int n;
    cin >> n;

    generate_p1(n);                                                     //generates the random data in a file called p2.txt

    auto start = chrono::high_resolution_clock::now();                  //used for start of execution time

    ifstream p1;
    p1.open("p1.txt");


    vector<int> arr;
    for(int i = 0; i < n; i++){
        int temp;
        p1 >> temp;
        arr.push_back(temp);
    }

    p1.close();

    vector<pair<long long, pair<int, int>>> dp;
    dp.push_back(make_pair(0, make_pair(0,0)));
    for(int i = 1; i <= n; i++){
        if(arr[i - 1] >= dp[i - 1].first + arr[i - 1]){
            dp.push_back(make_pair(arr[i - 1], make_pair(i - 1, i - 1)));
        }
        else{
            dp.push_back(make_pair(dp[i - 1].first + arr[i - 1], make_pair(dp[i - 1].second.first, i - 1)));
        }
    }
    cout << dp[n].second.first << " " << dp[n].second.second << " " << dp[n].first << endl;
    auto end = chrono::high_resolution_clock::now();
    cout << "Execution time: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;
}

void task4(){
    int m, n;
    cin >> m >> n;

    generate_p2(m, n);                                                     //generates the random data in a file called p2.txt

    auto start = chrono::high_resolution_clock::now();

    ifstream p2;
    p2.open("p2.txt");

    vector<vector<int>> arr(m, vector<int>(n, 0));                          //read data into an array
    for(int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            int temp;
            p2 >> temp;
            arr[i][j] = temp;
        }
    }

    p2.close();

    long long maxsum = INT_MIN;
    int lowx = 0, highx = 0, lowy = 0, highy = 0;
    for(int i = 0; i < m; i++){
        for(int j = i; j < m; j++){
            for(int k = 0; k < n; k++){
                for(int a = k; a < n; a++){
                    long long tempsum = 0;
                    for(int b = i; b <= j; b++){
                        for(int c = k; c <= a; c++){                            //for each possible subarray, iterate through every element and sum each value
                            tempsum += arr[b][c];
                        }
                    }
                    if(tempsum > maxsum){
                        maxsum = tempsum;
                        lowx = i;
                        highx = j;
                        lowy = k;
                        highy = a;
                    }
                }
            }
        }
    }
    cout << lowy << " " << highx << " " << highy << " " << lowx << " " << maxsum << endl;
    auto end = chrono::high_resolution_clock::now();
    cout << "Execution time: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;
}

void task5(){
    int m, n;
    cin >> m >> n;

    generate_p2(m, n);                                                     //generates the random data in a file called p2.txt

    auto start = chrono::high_resolution_clock::now();                      //used for start of execution time

    ifstream p2;
    p2.open("p2.txt");

    vector<vector<int>> arr(m, vector<int>(n, 0));                          //read data into an array
    for(int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            int temp;
            p2 >> temp;
            arr[i][j] = temp;
        }
    }

    p2.close();

    long long gmax = INT_MIN, glowx = 0, ghighx = 0, glowy = 0, ghighy = 0;
    for(int i = 0; i < m; i++){ //lower bound x
        for(int j = i; j < m; j++){ //upper bound x
            vector<long long> column;                           //i and j are only iterating through the x axis
            for(int a = 0; a < n; a++){                         //at every subarray from i to j, sum the elements in each row and make a single column
                long long sum = 0;
                for(int b = i; b <= j; b++){
                    sum += arr[b][a]; 
                }
                column.push_back(sum);
            }

            //now implement kadanes algorithm on that column we just made

            long long maxsum = column[0], tempsum = 0;
            int lowy = 0, highy = 0;
            for(int k = 0; k < column.size(); k++){
                tempsum += column[k];
                if(column[k] > tempsum){
                    tempsum = column[k];
                    lowy = k;
                }
                if(tempsum > maxsum){
                    maxsum = tempsum;
                    highy = k;
                }
            }
            if(maxsum > gmax){
                gmax = maxsum;
                glowx = i;
                ghighx = j;
                glowy = lowy;
                ghighy = highy;
            }
        }
    }
    cout << glowy << " " << glowx << " " << ghighy << " " << ghighx << " " << gmax << endl;
    // cout << arr[ghighx][glowy] << " " << arr[glowx][ghighy] << endl;
    // cout << arr[0][0] << arr[1][0] << endl;
    auto end = chrono::high_resolution_clock::now();
    cout << "Execution time: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;
}

void task6(){
    int m, n;
    cin >> m >> n;

    generate_p2(m, n);                                                     //generates the random data in a file called p2.txt

    auto start = chrono::high_resolution_clock::now();                      //used for start of execution time

    ifstream p2;
    p2.open("p2.txt");

    vector<vector<int>> arr(m, vector<int>(n, 0));                          //read data into an array
    for(int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            int temp;
            p2 >> temp;
            arr[i][j] = temp;
        }
    }

    p2.close();
    
    vector<vector<long long>> dp(m + 1, vector<long long>(n, 0));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){                                     //precompute the sums of the rows at each index by using a dp array
            dp[i + 1][j] = arr[i][j] + dp[i][j];
        }
    }
    long long gmax = INT_MIN;
    int glowx = 0, ghighx = 0, glowy = 0, ghighy = 0;
    for(int i = 1; i <= m; i++){ //lower bound x
        for(int j = i; j <= m; j++){ //upper bound x 
            vector<long long> column;
            for(int a = 0; a < n; a++){
                column.push_back(dp[j][a] - dp[max(0, i - 1)][a]);      //sum the rows by subracting the sums from each index in the dp array
            }

            //now implement kadanes algorithm on the column we just made

            long long maxsum = column[0];
            int tempsum = 0, lowy = 0, highy = 0;;
            for(int k = 0; k < column.size(); k++){
                tempsum += column[k];
                if(column[k] > tempsum){
                    tempsum = column[k];
                    lowy = k;
                }
                if(tempsum > maxsum){
                    maxsum = tempsum;
                    highy = k;
                }
            }
            if(maxsum > gmax){
                gmax = maxsum;
                glowx = i;
                ghighx = j;
                glowy = lowy;
                ghighy = highy;
            }
        }
    }
    cout << glowy << " " << --glowx << " " << ghighy << " " << --ghighx << " " << gmax << endl;
    auto end = chrono::high_resolution_clock::now();
    cout << "Execution time: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;
}

int main(int argc, char* argv[]){
    string task = argv[1];

    if(task == "1"){
        task1();
    }
    else if(task == "2"){
        task2();
    }
    else if(task == "3a" || task == "3A"){
        task3a();
    }
    else if(task == "3b" || task == "3B"){
        task3b();
    }
    else if(task == "4"){
        task4();
    }
    else if(task == "5"){
        task5();
    }
    else if(task == "6"){
        task6();
    }

    return 0;
}