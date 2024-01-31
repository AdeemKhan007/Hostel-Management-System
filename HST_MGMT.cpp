//HOSTEL MANAGEMENT PROJECT
//Adeem Shehzad-F20bb043
// Bilal Rana-F20bb013
// Hamza Bhatti-F20bb113


#include <iostream>
#include <fstream>
#include <vector>

class Hostel {
private:
    int room_no;
    std::string name;
    std::string address;
    std::string phone;

public:
    int main_menu();
    int add();
    int display();
    int rooms();
    int edit();
    int check(int);
    int modify(int);
 };

int Hostel::main_menu() {
    int choice = 0;

    while (choice != 5) {
        std::cout << "\n\t\t\t\t*****";
        std::cout << "\n\t\t\t\t* MAIN MENU *";
        std::cout << "\n\t\t\t\t*****";
        std::cout << "\n\n\n\t\t\t1. Allot A Room";
        std::cout << "\n\t\t\t2. Student Record";
        std::cout << "\n\t\t\t3. Rooms Allotted";
        std::cout << "\n\t\t\t4. Edit Record";
        std::cout << "\n\t\t\t5. Exit";
        std::cout << "\n\n\t\t\tEnter Your Choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                add();
                break;

            case 2:
                display();
                break;

            case 3:
                rooms();
                break;

            case 4:
                edit();
                break;

            case 5:
                break;

            default:
                std::cout << "\n\n\t\t\tWrong choice!!!";
                std::cout << "\n\t\t\tPress Enter to continue!!";
                std::cin.ignore();
                std::cin.get();
                break;
        }
    }
    return 0;
}

int Hostel::add() {
    int r, flag;
    std::ofstream fout("Recor.dat", std::ios::binary | std::ios::app);

    std::cout << "\n Enter Customer Details";
    std::cout << "\n ********";
    std::cout << "\n\n Room no: ";
    std::cin >> r;

    flag = check(r);

    if (flag)
        std::cout << "\n Sorry..!!! Room is already booked";
    else {
        room_no = r;
        std::cout << "\n Name:\t ";
        std::cin >> name;
        std::cout << "\n Address:\t ";
        std::cin >> address;
        std::cout << "\n Phone No:\t ";
        std::cin >> phone;

        fout.write(reinterpret_cast<char*>(this), sizeof(*this));
        std::cout << "\n Room is booked!!!";
    }

    std::cout << "\n Press Enter to continue!!";
    std::cin.ignore();
    std::cin.get();
    fout.close();
    return 0;
}

int Hostel::display() {
    std::ifstream fin("Recor.dat", std::ios::binary);
    int r;

    std::cout << "\n Enter room no: ";
    std::cin >> r;

    bool found = false;

    while (fin.read(reinterpret_cast<char*>(this), sizeof(*this))) {
        if (room_no == r) {
            std::cout << "\n Customer Details";
            std::cout << "\n ******";
            std::cout << "\n\n Room no: " << room_no;
            std::cout << "\n Name: " << name;
            std::cout << "\n Address: " << address;
            std::cout << "\n Phone no: " << phone;
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "\n Sorry Room no. not found or vacant!!";
    }

    std::cout << "\n Press Enter to continue!!";
    std::cin.ignore();
    std::cin.get();
    fin.close();

    return 0;
}

int Hostel::rooms() {
    std::ifstream fin("Recor.dat", std::ios::binary);
    std::cout << "\n\t\t\tList Of Rooms Allotted";
    std::cout << "\n\t\t\t*********";
    std::cout << "\n\n Room No.\tName\t\tAddress\t\tPhone     No.\n";

    while (fin.read(reinterpret_cast<char*>(this), sizeof(*this))) {
        std::cout << "\n\n " << room_no << "\t\t" << name << "\t\t" << address << "\t\t" << phone;
    }

    std::cout << "\n\n\n\t\t\tPress Enter to continue!!";
    std::cin.ignore();
    std::cin.get();
    fin.close();

    return 0;
}

int Hostel::edit() {
    int choice, r;

    std::cout << "\n EDIT MENU";
    std::cout << "\n ***";
    std::cout << "\n\n 1. Modify Customer Record";
    std::cout << "\n Enter your choice: ";
    std::cin >> choice;

    std::cout << "\n Enter room no: ";
    std::cin >> r;

    switch (choice) {
        case 1:
            modify(r);
            break;
  

        default:
            std::cout << "\n Wrong Choice!!";
    }

    std::cout << "\n Press Enter to continue!!!";
    std::cin.ignore();
    std::cin.get();

    return 0;
}

int Hostel::check(int r) {
    std::ifstream fin("Recor.dat", std::ios::binary);

    while (fin.read(reinterpret_cast<char*>(this), sizeof(*this))) {
        if (room_no == r) {
            fin.close();
            return 1; // Room already booked
        }
    }

    fin.close();
    return 0; // Room is available
}

int Hostel::modify(int r) {
    std::fstream file("Recor.dat", std::ios::in | std::ios::out | std::ios::binary);
    long pos;
    bool found = false;

    while (file.read(reinterpret_cast<char*>(this), sizeof(*this))) {
        pos = file.tellg();

        if (room_no == r) {
            std::cout << "\n Enter New Details";
            std::cout << "\n *******";
            std::cout << "\n Name: ";
            std::cin >> name;
            std::cout << " Address: ";
            std::cin >> address;
            std::cout << " Phone no: ";
            std::cin >> phone;

            file.seekg(pos);
            file.write(reinterpret_cast<char*>(this), sizeof(*this));

            std::cout << "\n Record is modified!!";
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "\n Sorry Room no. not found...";
    }
  else {
        remove("Recor.dat");
        rename("temp.dat", "Recor.dat");
    }
}

int main() {
    Hostel h;

    std::cout << "\n\t\t\t**********";
    std::cout << "\n\t\t\t* HOSTEL MANAGEMENT PROJECT *";
    std::cout << "\n\t\t\t* Adeem Shehzad-F20bb043 *";
    std::cout << "\n\t\t\t* Bilal Rana-F20bb013 *";
    std::cout << "\n\t\t\t* Hamza Bhatti-F20bb113 *";
    std::cout << "\n\t\t\t**********";

    std::cout << "\n\n\n\n\n\t\t\t\tPress Enter to continue!!";
    std::cin.ignore();
    std::cin.get();

    h.main_menu();

    return 0;
}

        
        
        
