#include "application.h"
#include "array.h"
#include "number.h"
#include <iostream>

using namespace std;


TApplication::TApplication() {

}

int TApplication::exec() {
    int ch;
    TArray arr;
    while (true) {
        cin.clear(); // Clearing the input stream from possible errors
        cin.sync();
        ch = menu();

        switch (ch) {
        case 7: {
            short int sCh = 0;
            number item;
            cout << "0. enter elements manually" << "\n";
            cout << "1. enter dimension" << "\n";
            cin >> sCh;

            if (!cin.good()) {
                cout << "\nYou entered an incorrect value\n";
                continue;
            }
            arr.flushMemory();

            if (!sCh) {
                cout << "Elements (to stop it - enter any char): ";
                while (cin >> item) arr.appendElement(item);
            } else {
                unsigned dimension;
                cout << "Dimension (warn - this operation will delete the old array if it exists): ";
                cin >> dimension;
                getchar();
                cout << " ";
                if (!cin.good()) {
                    cout << "\nYou entered an incorrect value\n";
                    continue;
                }

                cout << "\nEnter filling value (default 0): ";
                cin >> item;

                arr.fillArray(dimension, item);
            }

            arr.print();
            break;
        }
        case 6: {
            cout <<"Medium value: " << arr.mediumValue() << "\n";
            break;
        }
        case 5: {
            cout << "SKO (standard deviation): " << arr.standardDeviation() << "\n";
            break;
        }
        case 4: {
            short int sCh = 0;

            cout << "0. ascending order" << "\n";
            cout << "1. descending order" << "\n";
            cin >> sCh;

            if (!cin.good()) {
                cout << "\nYou entered an incorrect value\n";
                continue;
            }

            if (!sCh) {
                arr.sort();
            } else {
                arr.reverseSort();
            }

            arr.print();
            break;
        }
        case 3: {
            unsigned newSize;

            cout << "Enter a new array dimension: ";
            cin >> newSize;

            if (!cin.good()) {
                cout << "\nYou entered an incorrect value\n";
                continue;
            }
            arr.resizeArray(newSize);
            arr.print();
            break;
        }
        case 2: {
            unsigned index;
            number value;

            cout << "index: ";
            cin >> index;
            if (!cin.good()) {
                cout << "\nYou entered an incorrect value\n";
                continue;
            }
            getchar();
            cout << " ";
            cout << "\n" << "value: ";
            cin >> value;
            if (!cin.good()) {
                cout << "\nYou entered an incorrect value\n";
                continue;
            }
            cout << "\n";
            arr.replaceElement(index, value);
            break;
        }
        case 1: {
            arr.print();
            break;
        }
        case 0: {
            return 0;
        }
        default: {
            cout << "\n" << "There is no case with this number" << "\n";
            break;
        }
        }
    }
    return 0;
}


int TApplication::menu() {
    int ch;

    cout << "Operations:" << "\n";
    cout << "7 - define array" << "\n";
    cout << "6 - SO" << "\n";
    cout << "5 - SKO" << "\n";
    cout << "4 - sort array" << "\n";
    cout << "3 - change size of array" << "\n";
    cout << "2 - change element of array" << "\n";
    cout << "1 - print array" << "\n";
    cout << "0 - exit" << "\n" << "> ";

    cin >> ch;
    if (!cin.good()) return -1;

    return ch;
}
