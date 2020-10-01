#include <iostream>
 
using namespace std;
 
int numofdiamonds(int roomno) {
    int oddsum = 0;
    int evesum = 0;
    while(roomno!=0) {
      int dig = roomno%10;
      roomno/=10;
      if(dig%2==1) oddsum+=dig;
      else evesum+= dig;
    }
    return oddsum>evesum?oddsum-evesum:evesum-oddsum;
}
  
int main() {
    
    int numoftestcases;
    cin >> numoftestcases;
    int maxNum=-1;
    int testcases[numoftestcases];
    
    for(int i=0 ; i<numoftestcases ; i++) {
        cin >> testcases[i];
        maxNum = maxNum > testcases[i] ? maxNum : testcases[i];
    }
    
    int rooms[maxNum][maxNum];
    for(int i=0 ; i<maxNum ; i++) {
        rooms[i][i] = numofdiamonds(2*(i+1));
        for(int j=i+1 ; j<maxNum ; j++) {
            int diamonds = numofdiamonds(i+j+2);
            rooms[i][j] = diamonds;
            rooms[j][i] = diamonds;
        }
    }
    
    int diamonds = 0;
    int answers[maxNum];
    for(int i=0 ; i<maxNum ; i++) {
        diamonds+=rooms[i][i];
        for(int j=i-1;j>=0;j--) {
            diamonds+= 2*rooms[j][i];
        }
        answers[i] = diamonds;
    }
    
    for(int i=0 ; i<numoftestcases ; i++) {
        cout << answers[testcases[i]-1] << endl;
    }
  }