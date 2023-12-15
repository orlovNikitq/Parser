#include <iostream>
#include <fstream>
#include <vector> 
#include <nlohmann/json.hpp>
using namespace std;
using json = nlohmann::json;

struct Person {
    string name;
    string surname;
};

int main() {
    ifstream file("qwe.json");

    json json_data;
    file >> json_data;
    vector<Person> people;

    for (const auto& entry : json_data) {
        Person person;
        person.name = entry["name"];
        person.surname = entry["surname"];
        people.push_back(person);
    }

    for (const auto& person : people) {
        cout << "Name: " << person.name << ", Surname: " << person.surname << endl;
    }

}