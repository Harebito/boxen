#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Hotel{
private:
    string name;
    int total_amount = 0;
    int taketh_amount = 0;
    double rating = 0;
public:
Hotel(string x, int y, float z){
    name = x;
    total_amount = y;
    rating = z;
}

//**********************************
//              lub
//Hotel(string x, int y, double z) : name(x), total_amount(y), rating(z) {}
//**********************************

void reserveRoom() {
    if (taketh_amount < total_amount)
        taketh_amount++;
    else
        cout << "Brak wolnych pokoi." << endl;
}
void cancelReservation(){
    if (taketh_amount>0)
        taketh_amount--;
    else
        cout << "Brak rezerwacji." << endl;
}
int getFreeRooms() const {
    return total_amount-taketh_amount;
}
double getRating() const {
    return rating;
}
string getName() const {
    return name;
}

};
bool compareByRating(const Hotel &a, const Hotel &b) {
    return a.getRating() > b.getRating();
}
int main(){
    vector<Hotel> hotele = {
            Hotel("Hotel A", 500, 8.5),
            Hotel("Hotel B", 102, 7.8),
            Hotel("Hotel C", 405, 9.2)
    };
    sort(hotele.begin(), hotele.end(), compareByRating);

    cout << "Hotele przed rezerwacją:" << endl;
    for (const auto &hotel : hotele) {
        cout << hotel.getName() << " - Ocena: " << hotel.getRating() << ", Wolne pokoje: " << hotel.getFreeRooms() << endl;
    }

    // przykładowe rezerwacje
       hotele[0].reserveRoom();
       hotele[1].reserveRoom();
       hotele[2].reserveRoom();
    cout << "\nHotele po rezerwacji:" << endl;
    for (const auto &hotel : hotele) {
        cout << hotel.getName() << " - Ocena: " << hotel.getRating() << ", Wolne pokoje: " << hotel.getFreeRooms() << endl;
    }
    return 0;
}