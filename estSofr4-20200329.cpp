//
// Created by 전형진 on 2020-03-29.
//

// you can use includes, for example:
// #include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>


using namespace std;


bool checkLower (char c) {
    if ('a' <= c && c <= 'z') {
        return true;
    }
    return false;
}
bool checkUpper (char c) {
    if ('A' <= c && c <= 'Z') {
        return true;
    }
    return false;
}

bool checkAlpa (char c) {
    if (checkUpper(c) || checkLower(c)) {
        return false;
    }
    return true;
}

string delSpace (string s) {
    if (checkAlpa(s.front())) {
        return s.substr(1, s.size());
    }
    return s;
}
string change (string str) {
    string temp = "";
    for (int i = 0; i < (int)str.size(); ++i) {
        if (checkAlpa(str[i])) continue;

        if (checkUpper(str[i])) {
            temp += (str[i] + 32);
        }
        else {
            temp += str[i];
        }
    }
    return temp;
}

vector<string> makeName (string &S) {
    istringstream buffer(S);
    string name;

    vector<string> nalist;

    while (getline(buffer, name, ';')) {
        nalist.push_back(delSpace(name));
    }

    return nalist;
}
string makeEmail (string company, string id, int cnt) {
    if (cnt) {
        return id + to_string(cnt) + '@' + company + ".com";
    }
    else {
        return id + '@' + company + ".com";
    }
}

string makeId (string name) {
    istringstream buffer(name);
    string temp;
    vector<string> namelist;

    while (getline(buffer, temp, ' ')) {
        namelist.push_back(temp);
    }

    return change(namelist.back()) + '_' + change(namelist.front());
}



string solution(string &S, string &C) {
    vector<string> name;
    // write your code in C++14 (g++ 6.2.0)
    string ans = "";
    unordered_map<string, int> list;
    string ID;
    string COM;


    name = makeName(S);

    COM = change(C);

    for (int i = 0; i < (int)name.size(); ++i) {
        ID = makeId(name[i]);

        ans+= (name[i] + ' ');

        ans += '<';
        if (list.find(ID) == list.end()) {
            ans += makeEmail(COM, ID, 0);
            list.insert({ID, 1});
        }
        else {
            list[ID] +=1;
            ans += makeEmail(COM, ID, list[ID]);
        }
        ans += '>';
        if (i + 1 != (int)name.size()) {
            ans += "; ";
        }
    }
    return ans;
}