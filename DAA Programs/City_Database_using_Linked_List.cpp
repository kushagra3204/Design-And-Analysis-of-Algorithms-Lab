#include <iostream>
#include <cmath>
#include <windows.h>

using namespace std;

class City {
public:
    string name;
    int x, y;
    City* next;
    
    City(string name, int x, int y) {
        this->name = name;
        this->x = x;
        this->y = y;
        this->next = NULL;
    }
};

class CityDatabase {
public:
    City* head;
    
    CityDatabase() {
        head = NULL;
    }
    
    void insert(string name, int x, int y) {
        City* city = new City(name, x, y);
        if (head == NULL) {
            head = city;
        } else {
            City* curr = head;
            while (curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = city;
        }
    }
    
    void deleteByName(string name) {
        if (head == NULL) {
            return;
        }
        if (head->name == name) {
            head = head->next;
            return;
        }
        City* prev = head;
        City* curr = head->next;
        while (curr != NULL) {
            if (curr->name == name) {
                prev->next = curr->next;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }
    
    void deleteByCoord(int x, int y) {
        if (head == NULL) {
            return;
        }
        if (head->x == x && head->y == y) {
            head = head->next;
            return;
        }
        City* prev = head;
        City* curr = head->next;
        while (curr != NULL) {
            if (curr->x == x && curr->y == y) {
                prev->next = curr->next;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }
    
    City* searchByName(string name) {
        City* curr = head;
        while (curr != NULL) {
            if (curr->name == name) {
                return curr;
            }
            curr = curr->next;
        }
        return NULL;
    }
    
    City* searchByCoord(int x, int y) {
        City* curr = head;
        while (curr != NULL) {
            if (curr->x == x && curr->y == y) {
                return curr;
            }
            curr = curr->next;
        }
        return NULL;
    }
    
    void printWithinDistance(int x, int y, int distance) {
        City* curr = head;
        while (curr != NULL) {
            double dist = sqrt(pow(curr->x - x, 2) + pow(curr->y - y, 2));
            if (dist <= distance) {
                cout << curr->name << " (" << curr->x << ", " << curr->y << ")" << endl;
            }
            curr = curr->next;
        }
    }
};

int main() {
    system("cls");
    CityDatabase db;
    db.insert("Vapi", 0, 0);
    db.insert("Surat", 3, 4);
    db.insert("Gandhinagar", -1, 2);
    db.insert("Ahmedabad", 5, -1);
    db.deleteByName("Ahmedabad");
    db.deleteByCoord(5, -1);
    City* nyc = db.searchByName("Gandhinagar");
    City* la = db.searchByCoord(3, 4);
    db.printWithinDistance(3, 4, 3);
    db.printWithinDistance(5, -1, 3);
    db.printWithinDistance(0, 0, 3);
    return 0;
}
