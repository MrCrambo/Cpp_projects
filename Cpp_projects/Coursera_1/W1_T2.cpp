//
//  W1_T2.cpp
//  Cpp_projects
//
//  Created by mrcrambo on 14/02/2020.
//  Copyright © 2020 mrcrambo. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[])  {
    // find the second entrance of 'f' symbol
    string text;
    int f_entrance = 0, id = 0;
    cin >> text;
//    for (int i = 0; i < text.size(); i++) {
//        if (text.at(i) == 'f' && f_entrance != 2)
//        {
//            f_entrance++;
//            id = i;
//        }
//    }
//
//    if (f_entrance == 2) {
//        cout << id;
//    } else if (f_entrance == 1){
//        cout << -1;
//    } else {
//        cout << -2;
//    }
    cout << text;
    
    return 0;
}
