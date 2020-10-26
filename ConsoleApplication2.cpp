#include <iostream>
#include <fstream>//для работы с файлами
#include <string>
using namespace std;

void findPlayer() {
    char letter{ 'a' };
    string str;
    int k{ 0 }, player_1{ 0 }, player_2{ 0 }, count{ 1 };
    ifstream inFile("input.txt"); 
    ofstream fout("output.txt");
    while (getline(inFile, str)) {
        cout << str << " ";
    }
    int i{ 0 };
    while (true) {
        if (str[i] == letter) {
            if (count % 2 == 0 && i < str.length()) {
                player_2++;
            }
            else {
                player_1++;
            }
            while (str[i] != ' ' && i < str.length()) {
                i++;
            }
            ++letter;
            ++count;
        }
        else {
            if (str[i] == ' ') {
                i = str.length();
                if (count % 2 == 0) {
                    player_2 = 0;
                }
                else {
                    player_1 = 0;
                }
            }
        }
        i++;
        if (i >= str.length()) {
            break;
        }
    }
    if (player_1 > player_2)
        fout << "PLAYER 1";
    else if (player_1 < player_2)
        fout << "PLAYER 2";
    else
        fout << "NO WINNER";
    fout.close();
}


int main()
{
    findPlayer();
    return 0;
}

//cout << "PLAYER 1";
//cout << "PLAYER 2";
//cout << "NO WINNER";