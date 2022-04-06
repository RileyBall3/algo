#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;

void generate_p1(int n){
    ofstream p1;
    p1.open("p1.txt");                          //makes a new file called p1.txt for the program to read the data from
    srand((unsigned)time(0));

    for(int i = 0; i < n; i++){
        int temp = ((rand()%32769));            //generates random number and writes it to the open file
        if(i % 3 == 0){
            p1 << (-1 * temp) << " ";
        }
        else{
            p1 << temp << " ";
        }
    }

    p1.close();
}

void generate_p2(int n, int m){
    ofstream p2;
    p2.open("p2.txt");                          //makes a new file called p1.txt for the program to read the data from
    srand((unsigned)time(0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int temp = ((rand()%32769));        //generates random number and writes it to the open file
            if(i % 3 == 0 && j % 2 == 0){
                p2 << (-1 * temp) << " ";
            }
            else{
                p2 << temp << " ";
            }
        }
        p2 << endl;
    }

    p2.close();
}

// int main(){
//     cout << "Generate data for problem 1 or 2? " << endl;
//     int p, n, m;
//     cin >> p;
//     if(p == 1){
//         cout << "what is the n size? " << endl;
//         cin >> n;
//         generate_p1(n);
//     }
//     else if(p == 2){
//         cout << "what is the n and m size? " << endl;
//         cin >> m >> n;
//         generate_p2(m, n);
//     }
// }