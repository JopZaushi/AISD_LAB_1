#include <iostream>
#include "List.h"

using namespace std;

int main() {
    List List_other;
    cout << "Constructor with parametr ";
    List List(2);
    cout << List << endl;
    cout << "Inserting two elements at the end of a list ";
    List.push_back(3);
    List.push_back(4);
    cout << List << endl;
    cout << "Inserting one elements at the begin of a list ";
    List.push_front(1);
    cout << List << endl;
    cout << "Delete the last element and the starting element ";
    List.pop_back();
    List.pop_front();
    cout << List << endl;
    cout << "Insert element in the middle " << endl;
    try
    {
        List.insert(8, 10);
    }
    catch (const out_of_range error)
    {
        cout << "The element could not be inserted because the index is outside the boundary: "<<error.what() << endl;
    }
    cout << "Let's try another ";
    List.insert(1, 1);
    cout << List << endl;
    cout << "Let's try to get the value of the element in the first place and delete the element by index. First element = ";
    List.at(0); cout << endl;
    cout << "Delete second element ";
    List.remove(1);
    cout << List << endl;
    cout << "Get the size of the list " << List.get_size() << endl;
    cout << "Delete the list ";
    List.clear();
    cout << List << endl;
    cout << "Filling in again ";
    List.push_back(1);
    List.push_back(2);
    cout << List << endl;
    cout << "Swap the second element with another ";
    List.set(1, 5);
    cout << List << endl;
    cout << "Let's check for a blank list ";
    List.isEmpty();
    cout << List << endl;
    cout << "Insert one list into another ";
    List.push_back(10);
    List.push_front(List_other);
    cout << List;
   
    return 0;
}