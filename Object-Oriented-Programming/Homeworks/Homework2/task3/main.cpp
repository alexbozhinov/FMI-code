#include "JSONObject.h"
#include"MyString.h"
#include "JSONObject.cpp"
#include "JSONArray.h"
#include "JSONArray.cpp"
#include<iostream>
#include<cstring>
#include <fstream>

using namespace std;

int main(){

JSONObject<int> json1("age", 20);
JSONObject<int> json2("sum", 300);
JSONObject<int> json3("year", 2020);
JSONObject<int> json4("memory", 600);
JSONObject<int> json5("kg", 25);
JSONObject<int> json6("brand", 360);
JSONArray<int> arr;
///function that adds new element to the array by JSONObject
/*
arr.addElement(json1);
arr.addElement(json2);
arr.addElement(json3);
arr.addElement(json4);
arr.addElement(json5);
arr.addElement(json6);
*/
///function that adds new element to the array by a key and a value
arr.addElement("age", 20);
arr.addElement("sum", 300);
arr.addElement("year", 2020);
arr.addElement("memory", 600);
arr.addElement("kg", 25);
arr.addElement("brand", 360);
arr.print();
///overloaded operator<< for class JSONArray
/*cout<<arr;*/
///function that removes element from the array by the key
arr.removeElement("sum");
arr.print();
///function that return the value of an element by the key
cout<<arr.returnByKey("age")<<endl;
///part Task 4
arr.writeInFile("JSON.txt");

return 0;
}
