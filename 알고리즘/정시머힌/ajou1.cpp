#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> inputStringArray(int size) {
    vector<string> array(size);

    
    for (int i = 0; i < size; ++i) {
        
        getline(cin, array[i]);
    }

    return array;
}

int main() {
    int size;
    bool a;

    
    cin >> size;
   
    cin.ignore();
    if (size <= 1 || size >= 100) {
        
        return 1;
    }
    vector<string> stringArray = inputStringArray(size);
    
    for (int i = 0; i < size; i++) {
        int count = 0;
        int word = stringArray[i].size();
        for (int j = 0; j < word; j++) {
           
            if (stringArray[i][j] == '@') {
                stringArray[i][j] = 'a';
                count++;
            }
            else if (stringArray[i][j] == '[') {
                stringArray[i][j] = 'c';
                count++;
            }
            else if (stringArray[i][j] == '!') {
                stringArray[i][j] = 'i';
                count++;
            }
            else if (stringArray[i][j] == ';') {
                stringArray[i][j] = 'j';
                count++;
            }
            else if (stringArray[i][j] == '^') {
                stringArray[i][j] = 'n';
                count++;
            }
            else if (stringArray[i][j] == '0') {
                stringArray[i][j] = 'o';
                count++;
            }
            else if (stringArray[i][j] == '7') {
                stringArray[i][j] = 't';
                count++;
            }
            else if ((j == 0 and stringArray[i][j] == '\\')or (j-1>=0 and stringArray[i][j - 1] != '\\' and stringArray[i][j] == '\\')) {
                if (j + 1 < word - 1 and stringArray[i][j + 1] == '\'') {
                    stringArray[i].replace(j, 2, "v");
                    word = word - 1;
                    count++;

                }
                else if (j + 2 < word - 1 and stringArray[i][j + 1] == '\\' and stringArray[i][j + 2] == '\'') {
                    stringArray[i].replace(j, 3, "w");
                    word = word - 2;
                    count++;

                }



            }

        }
        if (word/2.0 < count) {
            stringArray[i] = "I don't understand";
            
        }



    }
    
    for (const auto& str : stringArray) {
        cout << str << endl;
    }
    return 0;
}