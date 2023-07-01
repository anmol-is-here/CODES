#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    map<string, int> directory;
    directory["anshil"] = 489413;
    directory["aditya"] = 564654;
    directory["mannu"] = 654516;
    directory["arjun"] = 155145;

    for(auto ele:directory){
        cout<<"Name - "<<ele.first<<endl;
        cout<<"Phone no. - "<<ele.second<<endl;
    }cout<<endl;
    // another way to insert values in a directory is.
    directory["mannu"] = 565115;   // it will not create another key with same name, it only update value of older key.
    // directory.insert(make_pair("mannu", 256348));  // if value is present witn same key it will not do anything
    for(auto ele:directory){
        cout<<"Name - "<<ele.first<<endl;
        cout<<"Phone no. - "<<ele.second<<endl;
    }cout<<endl;  

    map<string, int>::reverse_iterator itr;
    for(itr = directory.rbegin(); itr!=directory.rend(); itr++){
        cout<<itr->first<<" - "<<itr->second<<endl;
    } 
    
    return 0;
}