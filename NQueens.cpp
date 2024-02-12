/*

Implement a solution for a Constraint Satisfaction Problem using Branch and Bound and
Backtracking for n-queens problem or a graph coloring problem

*/

#include<iostream>
#include<vector>
using namespace std;

bool checkContrainst(vector<vector<int>> &matrix,int qi,int qj){

    int m=matrix.size();
    int n=matrix[0].size();

    //Check for rows

    for(int i=0;i<m;i++){

        if(i==qi){

            continue;
        }

        if(matrix[i][qj]==1){

            return false;
        }
    }

    //Check for column

    for(int j=0;j<n;j++){

        if(j==qj){

            continue;
        }

        if(matrix[qi][j]==1){

            return false;
        }
    }

    //Check upper right diagonal

    int ri3=qi-1;
    int rj3=qj+1;

    while(rj3<n && ri3>=0){

        if(matrix[ri3][rj3]==1){

            return false;
        }

        ri3--;
        rj3++;

    }

    //Check lower right diagonal

    int ri4=qi+1;
    int rj4=qj+1;

    while(rj4<n && ri4<m){

        if(matrix[ri4][rj4]==1){

            return false;
        }

        ri4++;
        rj4++;

    }

    //Check upper left diagonal

    int ri1=qi-1;
    int rj1=qj-1;

    while(rj1>=0 && ri1>=0){

        if(matrix[ri1][rj1]==1){

            return false;
        }

        ri1--;
        rj1--;
    }

    //Check lower left diagonal

    int ri2=qi+1;
    int rj2=qj-1;

    while(rj2>=0 && ri2<m){

        if(matrix[ri2][rj2]==1){

            return false;
        }

        ri2++;
        rj2--;

    }
    

    return true;

}

bool solveNQ(vector<vector<int>> &matrix,int qi){

    int n=matrix.size();

    if(qi>=n){

        return true;
    }

    for(int i=0;i<n;i++){

        if(checkContrainst(matrix,qi,i)){

            matrix[qi][i]=1;

            if(solveNQ(matrix,qi+1)){

                return true;

            };

            matrix[qi][i]=0;

        }

    }

    return false;
}

void display(vector<vector<int>> &matrix){
    
    int m=matrix.size();
    int n=matrix[0].size();

    for(int i=0;i<m;i++){

        for(int j=0;j<n;j++){

            cout<<matrix[i][j]<<" ";

        }

        cout<<endl;
    }

}

int main(){

    int n;

    cout<<"\nEnter the size of the chessboard (n x n): ";
    cin>>n;

    vector<vector<int>> mat(n,vector<int>(n,0));

    if(solveNQ(mat,0)){

        cout<<"\nThe solution is: \n\n";
        display(mat);

    }

    else{

        cout<<"\n\nNo solution exists";
    }

    return 0;
}