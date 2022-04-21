#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void cipher();
void decipher ();
int main() {

    int x ;
    cout<<"What do you like to do today?\n"
          "1- Cipher a message\n"
          "2- Decipher a message\n"
          "3- End\n";
    cin>>x;
    cin.clear();
    cin.sync();
    if (x== 1)
        cipher();
    else if(x==2)
        decipher();
    else if (x ==3 )
        exit;
}

void cipher(){
    char  message [80]= {};
    char coded[80] ={};
    char repeated [8] ={};
    int l =0;
    cout<<"what is the message to encrypt: ";
    cin.getline( message , 80 , '\n');
    cout<<"what is the keyword :";
    cin.getline(repeated , 8, '\n');
    for (int k=0 ; k<=strlen(message) ; k++){
        message[k] = toupper(message[k]);
    }
    for (int i =0 ; i<= strlen(message) ; i++){
        if (isalpha(message[i])){
            if (l== strlen(repeated))
                l=0;
            coded[i] = char(int(((message[i]+repeated[l])%26)+65));
        }
        else{
            coded[i] = message [i];
        }
        l++;
    }
    cout<<coded;


}



void decipher(){
    char message [ 80] = {};
    char decrypted [80]  = {};
    char repeated [8] = {};
    int l = 0;
    char letters [] = {'A','B','C','D','E','F','G','H','I','J','K','L',
                       'M', 'N', 'O', 'P', 'Q', 'R', 'S','T', 'U','V','W','X', 'Y','Z'};
    cout<<"what is the message to decrypt :\n";
    cin.getline(message , 80 , '\n');
    cout<< "what is the keyword :\n";
    cin.getline(repeated , 8, '\n');
    for (int k = 0 ; k<= strlen(message) ; k++){
        message [k] = toupper(message[k]);
    }

    for (int i = 0 ; i<=strlen(message) ; i++){

        if (isalpha(message[i])){
            for (int j=0; j<26 ; j++ ){
                if(l== strlen(repeated))
                    l=0;
                if ((int (((letters[j]+repeated[l])%26)+65)) == int(message[i])){
                    cout<<letters[j];
                    break;
                }
            }
        }else{cout<< message[i];}
        l++;

    }cout<<endl;
}
