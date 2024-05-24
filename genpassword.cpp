#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

/*Function to generate a random number between a
 starting point and the specified amount of values wanted*/
int randnum(int startpoint, int amountofvalues){
    int length = amountofvalues + 1;
    int num = startpoint + rand() % length;
    return num;
}
string genPassword()
{
    srand(time(NULL));
    int passlength = randnum(10, 6);
    char upper[25];
    char lower[25];
    char digit[10];
    char password[passlength];
    string userpassword;
    int indexv = 0;

    while(true){
        //Generate characters for each type.
        for(int i = 48; i < 124; i+=1)
        {
            if(i < 58){
                digit[indexv] = char(i);
                indexv+=1;
                continue;
            }
            else if (i > 64 && i < 91){
                if (indexv != 0 && i == 65){
                    indexv = 0;
                    upper[indexv] = char(i);
                    indexv+=1;
                    continue;
                }else{
                    upper[indexv] = char(i);
                    indexv+=1;
                    continue;
                }
            }
            else if (i > 96 && i < 123){
                if (indexv != 0 && i == 97){
                    indexv = 0;
                    lower[indexv] = char(i);
                    indexv+=1;
                    continue;
                }else{
                    lower[indexv] = char(i);
                    indexv+=1;
                    continue;
                }

            }
        }
        
        /*Randomly getting characters to put in the password, while 
        checking to see if the character behind it is the same as that one
        */
        for(int i = 0; i <= passlength; i+=1){
            int randomlist = randnum(1, 3);
            if(randomlist == 1){
                if (password[i] == password[i-1]){
                    continue;
                }else{
                    password[i] =  digit[randnum(0, 9)];
                    continue;
                }
            }else if(randomlist == 2){
                if (password[i] != password[i-1]){
                    password[i] = upper[randnum(0, 25) ];
                    continue;
                }else{
                    continue;
                }
            }else{
                if (password[i] != password[i-1]){
                    password[i] = lower[randnum(0, 25)];
                    continue;
                }else{
                    continue;
            }
            }
        }    
        bool hasupper = false, haslower = false, hasdigit = false, norepeat = false;

        //Checking to see if the password has upper values and lower values
        for(char u : upper){
            for(char l : password){
                if(u == l){
                    hasupper = true;
                    break;
                }
                else{continue;}
            }
        if (hasupper == true){
            break;
        }
        else{continue;}
        }
        
        for(char u : lower){
            for(char l : password){
                if(u == l){
                    haslower = true;
                    break;
                }
                else{continue;}
            }
        if (haslower == true){
            break;
        }
        else{continue;}
        }

        for(char u : digit){
            for(char l : password){
                if(u == l){
                    hasdigit = true;
                    break;
                }
                else{continue;}
            }
        if (hasdigit == true){
            break;
        }
        else{continue;}
        }
    
        char passchecker[passlength];
        for(int i = 0; i <= passlength; i++){
            passchecker[i] = tolower(password[i]);
        }
        for (int i = 1; i <= passlength; i++){
            if (passchecker[i] == passchecker[i-1]){
                norepeat = false;
                break;
            }else{ 
                norepeat =true;
                continue;
            }
        }
        
        //If the password passes all requirements, then put all characters as a string.
        if (hasdigit == true && haslower == true && hasupper == true && norepeat == true){
            for(char i:password){userpassword += i;}
            break;
        }else{continue;}
    }
    //Returning the users password in a single string
    return userpassword;
}

int main(){
    cout << genPassword();
}