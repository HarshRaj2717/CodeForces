#include<bits/stdc++.h>

using namespace std;

bool isPalindrome(string s, int i=0){
    if(i<s.size()-1-i){
        if(tolower(s[i]) != tolower(s[s.size()-1-i])){
            return false;
        }
        isPalindrome(s, i+1);
    }
    return true;
}

int main(){
    string s;
    getline(cin, s);
    if(isPalindrome(s)){
        cout << "Palindrome" << endl;
    }
    else{
        cout << "Not Palindrome" << endl;
    }
    return 0;
}