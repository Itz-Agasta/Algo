#include <bits/stdc++.h>
using namespace std;

void p1(int n){     
 for (int i=1; i<=n; i++){ // can be 0 --- <n
    for (int j=1; j<=n; j++ ){
        cout<< "* ";
    }
    cout << endl;
 }
}

void p2(int n){
    for (int i=1; i<=n; i++){
        for (int j=1; j<=i; j++){
            cout << "* ";
        }
    cout << endl;    
    }
}

void p3(int n){
    for (int i= 1; i<=n; i++){
        for (int j=1; j<=i ; j++){
            cout << j;
        }
    cout << endl;    
    }
}

void p4(int n){
    for (int i= 1; i<=n; i++){
        for (int j=1; j<=i ; j++){
            cout << i;
        }
    cout << endl;    
    }
}

void p5(int n){
    for (int i= 1; i<=n; i++){
        for (int j=n; j>=i ; j--){
            cout << "*";
        }
    cout << endl;    
    }
}

void p6(int n){
    for (int i= 1; i<=n; i++){
        for (int j=1; j<=n-i+1 ; j++){   // Look at the Formula. (n-j-1)
            cout << j;
        }
    cout << endl;    
    }
}

void p7(int n){
    
    for (int i=1; i<=n; i++){
        // space
        for (int j=1; j<= n-i+1; j++){
            cout << " ";
        }// star
        for (int k=1; k<= 2*i-1; k++){  // 2i-1
            cout << "*";
        }
        cout << endl;
    }
}

void p8(int n){
    
    for (int i=1; i<=n; i++){
        // space
        for (int j=1; j<= i-1; j++){
            cout << " ";
        }// star
        for (int k=1; k<= 2*n - (2*i-1); k++){   // 2n - (2i -1)
            cout << "*";
        }
        cout << endl;
    }
}

void p9(int n){
    // First half
    for (int i=1; i<=n; i++){
        // space
        for (int j=1; j<= n-i+1; j++){
            cout << " ";
        }// star
        for (int k=1; k<= 2*i-1; k++){  // 2i-1
            cout << "*";
        }
        cout << endl;
    }

    // second half
    for (int i=1; i<=n; i++){
        // space
        for (int j=1; j<= i; j++){
            cout << " ";
        }// star
        for (int k=1; k<= 2*n - (2*i-1); k++){   // 2n - (2i -1)
            cout << "*";
        }
        cout << endl;
    }
}









int main(){
    int n; 
    cin >> n;
    p9(n);
}