#include <iostream>
#include <vector>

using namespace std;

bool isCorrect(int a) {

    if (cin.fail()) {
        cerr << "Invalid input! Please enter an integer." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    } else if (a < -2) {
        cerr << "Invalid input! Number must be positive either -1 or -2." << endl;
        return false;
    } else {
        return true;
    }
}

vector<int> bubbleSort(vector<int> vec) {

    for (int i = 0; i < vec.size(); ++i) {
        for (int j = 0; j < vec.size() - i - 1; ++j) {
            if (vec[j] > vec[j + 1]) {
                int tmp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = tmp;
            }
        }
    }
    return vec;
}

int main() {
    vector<int> numbs;
    int a = 0;

    do {
        cout << "Input the number: ";
        cin >> a;
        if (isCorrect(a) && a != -1) {
            numbs.push_back(a);
        } else if (a == -1) {
            if (numbs.size() > 5) {
                numbs = bubbleSort(numbs);
                cout << "The fifth highest number among the entered is " << numbs[4] << endl;
            } else {
                cerr << "You entered less than 5 digits" << endl;
            }

        }
    } while (a != -2);
    return 0;
}
