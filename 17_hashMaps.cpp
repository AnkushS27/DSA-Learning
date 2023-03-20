#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

int main()
{
    // when we use unordered map T.C = O(1) for insertion, deletion and lookups
    // When we use map instead T.C = O(logn) for insertion, deletion and lookup
    
    // Creation
    unordered_map<string,int> m;
    
    // Insertion
    pair<string,int> p1 = make_pair("babbar", 3); // choice 1
    m.insert(p1);
    
    pair<string,int> p2("love", 2); // choice 2
    m.insert(p2);
    
    m["mera"] = 1; // choice 3
    
    m["mera"] = 4; // updation of <mera, 1> to <mera, 4>
    // key must be unique for creation of new map element
    
    // Search
    cout << m["mera"] << endl; // choice 1
    cout << m.at("babbar") << endl; // choice p2
    
    // size
    cout<<m.size()<<endl;
    
    // to check presence
    cout<<m.count("bro")<<endl;
    // count method gives 0 if value at key is absent and vice-versa
    
    // erase
    m.erase("love");
    cout<<m.size()<<endl;
    
    // Iterators
    unordered_map<string,int> :: iterator it = m.begin();
    while(it != m.end()){
        cout << it->first << " " << it->second << endl;
        it++;
    }

    return 0;
}
