#include <iostream>
#include <string>
#include <vector>
using namespace std;
int visited[10] = {0};
int l;
vector<char> vec;
int A,B;
string strB;
int maxi = 0, answer = 0;
void DFS(int sel, string str){
    if( sel == 0 ){
        int num = stoi(str);
 
        if(num!=A && num<B){        
            if(maxi<num) {
                maxi = num;
                answer = num;
            }
        }
    }
    
    for(int i = 0; i< vec.size(); i++){
        
        if(visited[i]==0){
            if(str.length()==0 && vec[i]=='0') continue;
            visited[i] = 1;
            str.push_back(vec[i]);
            DFS(sel-1, str);
            str.pop_back();
            visited[i] = 0;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> A >> B;
    string strA = to_string(A);
    string strB = to_string(B);
    l = (int)strA.length();
    
    for(int i = 0; i < l; i++){
        vec.push_back(strA[i]);
    }
    
    DFS(l, "");
    if(answer==0) answer=-1;
    cout << answer ;
    
    return 0;
}