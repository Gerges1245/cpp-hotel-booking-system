#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/*Guest_Class*/

class Guest
{
public:
    int Guest_Id;
    string Guest_Name;
    string Guest_Password;
    Guest* Guest_Next;
};
class list_Guest
{
public:
    Guest* headptr;
    Guest* tailptr;
    int currentGuestID;
    list_Guest()
    {
        headptr = NULL;
        tailptr = NULL;
        currentGuestID = -1;
    }


    void attach(Guest* pnn)
    {
        if (headptr == NULL)
        {
            headptr = pnn;
            tailptr = pnn;
        }
        else
        {
            tailptr->Guest_Next = pnn;
            tailptr = pnn;
        }
    }
    ~list_Guest()
    {
        Guest* tailptrrav = headptr;
        while (headptr != NULL)
        {
            headptr = tailptrrav->Guest_Next;
            tailptrrav->Guest_Next = NULL;
            delete tailptrrav;
            tailptrrav = headptr;
        }
    }
    void Logout() {
        currentGuestID = -1;
    }

    int Guest_Login(int id, string password)
    {
        ifstream Guest_file("D:\\y2 s 2\\project_213_ done\\Guest.txt", ios::app);
        string line;
        string temp[3];
        int k = 0;
        int ct = 0;
        int flag = 0;
        if (Guest_file.is_open())
        {
            while (getline(Guest_file, line))
            {
                if (ct > 0)
                {
                    k = 0;
                    flag = 0;


                    for (int i = 0; i < 3; i++)
                    {
                        temp[i].clear();
                    }


                    for (int i = 0; i < line.length(); i++)
                    {
                        if (line[i] == ',')
                        {
                            k++;
                        }
                        else
                        {
                            temp[k] += line[i];
                        }
                    }


                    if (stoi(temp[0]) == id && temp[2] == password)
                    {
                        Guest_file.close();
                        return 1;
                    }
                }
                ct = 1;
            }

            if (flag == 0)
            {
                cout << " The ID or password is incorrect. Please try again." << endl;
                return 0;
            }
        }
        Guest_file.close();
        return 0;
    }

    void save_Guest(int id)
    {
        fstream Guest_file("D:\\y2 s 2\\project_213_ done\\Guest.txt", ios::app);
        Guest* newC = tailptr;

        while (newC != NULL)
        {
            Guest_file << newC->Guest_Id << ",";
            Guest_file << newC->Guest_Name << ",";
            Guest_file << newC->Guest_Password << endl;
            newC = newC->Guest_Next;
        }
        cout << " Registration Successful! Your Guest ID is: " << id << endl;
        Guest_file.close();
    }

    void Register_Guest(string name, string password)
    {
        Guest* pnn = new Guest;
        ifstream Guest_file;
        Guest_file.open("D:\\y2 s 2\\project_213_ done\\Guest.txt", ios::app);
        string line, temp[3];
        int k = 0, flag = 0, ct = 0;

        if (Guest_file.is_open())
        {
            while (getline(Guest_file, line))
            {
                if (ct > 0)
                {
                    k = 0;
                    flag = 1;
                    for (int i = 0; i < 3; i++)
                    {
                        temp[i].clear();
                    }

                    for (int i = 0; i < line.length(); i++)
                    {
                        if (line[i] == ',')
                        {
                            k++;
                        }
                        else
                        {
                            temp[k] += line[i];
                        }
                    }
                }
                ct = 1;
            }

            if (flag == 1)
            {
                pnn->Guest_Id = stoi(temp[0]) + 1;
            }
            else
            {
                pnn->Guest_Id = 1;
            }
            for (int i = 0; i < 3; i++)
            {
                temp[i].clear();
            }
            pnn->Guest_Name = name;
            pnn->Guest_Password = password;
            pnn->Guest_Next = NULL;

            attach(pnn);
            save_Guest(pnn->Guest_Id);
        }
        else
        {
            cout << "Failed to open file." << endl;
        }
    }

};

/*Admin_Class*/

class Admin
{
public:
    int Admin_Id;
    string Admin_Name;
    string Admin_Password;
    Admin* Admin_Next;
};
class list_Admin
{
public:
    Admin* headptr;
    Admin* tailptr;
    int  currentAdminID;

    list_Admin()
    {
        headptr = NULL;
        tailptr = NULL;
        currentAdminID = -1;
    }

    void attach(Admin* pnn)
    {
        if (headptr == NULL)
        {
            headptr = pnn;
            tailptr = pnn;
        }
        else
        {
            tailptr->Admin_Next = pnn;
            tailptr = pnn;
        }
    }
    void Logout() {
        currentAdminID = -1;
    }
    ~list_Admin()
    {
        Admin* tailptrrav = headptr;
        while (headptr != NULL)
        {
            headptr = tailptrrav->Admin_Next;
            tailptrrav->Admin_Next = NULL;
            delete tailptrrav;
            tailptrrav = headptr;
        }
    }

    int Admin_Login(int id, string password)
    {
        ifstream Admin_file("D:\\y2 s 2\\project_213_ done\\Admin.txt");
        string line;
        string temp[3];
        int k = 0;
        int ct = 0;
        int flag = 0;
        if (Admin_file.is_open())
        {
            while (getline(Admin_file, line))
            {
                if (ct > 0)
                {
                    k = 0;
                    flag = 0;


                    for (int i = 0; i < 3; i++)
                    {
                        temp[i].clear();
                    }


                    for (int i = 0; i < line.length(); i++)
                    {
                        if (line[i] == ',')
                        {
                            k++;
                        }
                        else
                        {
                            temp[k] += line[i];
                        }
                    }
                    if (stoi(temp[0]) == id && temp[2] == password)
                    {
                        Admin_file.close();
                        cout << "You are logged in" << endl;
                        return 1;
                    }
                }
                ct = 1;
            }

            if (flag == 0)
            {
                cout << " The ID or password is incorrect. Please try again." << endl;
                Admin_file.close();
                return 0;
            }
        }
        Admin_file.close();
        return 0;
    }
    void save_Admin(int id)
    {
        fstream Admin_file("D:\\y2 s 2\\project_213_ done\\Admin.txt", ios::app);
        Admin* newC = tailptr;

        while (newC != NULL)
        {
            Admin_file << newC->Admin_Id << ",";
            Admin_file << newC->Admin_Name << ",";
            Admin_file << newC->Admin_Password << endl;
            newC = newC->Admin_Next;
        }
        cout << " Registration Successful! Your Guest ID is: " << id << endl;
        Admin_file.close();
    }
};

/*Room_Class*/

class Room
{
public:
    int RoomId;
    string Room_Type;
    float Room_Price;
    string Room_status;
    string Room_Features;
    Room* Room_Next;
};
class list_Room
{
public:
    Room* headptr;
    Room* tailptr;

    list_Room()
    {
        headptr = NULL;
        tailptr = NULL;
    }

    void attach(Room* pnn)
    {
        if (headptr == NULL)
        {
            headptr = pnn;
            tailptr = pnn;
        }
        else
        {
            tailptr->Room_Next = pnn;
            tailptr = pnn;
        }
    }

    ~list_Room()
    {
        Room* tailptrrav = headptr;
        while (headptr != NULL)
        {
            headptr = tailptrrav->Room_Next;
            tailptrrav->Room_Next = NULL;
            delete tailptrrav;
            tailptrrav = headptr;
        }
    }
    void save_Room()
    {
        fstream Room_file("D:\\y2 s 2\\project_213_ done\\Room.txt", ios::app);
        Room* newC = tailptr;

        if (newC == NULL) {
            cout << "  No rooms to save." << endl;
            return;
        }

        while (newC != NULL)
        {
            Room_file << newC->RoomId << ',';
            Room_file << newC->Room_Type << ',';
            Room_file << newC->Room_Price << ',';
            Room_file << newC->Room_status << ',';
            Room_file << newC->Room_Features << endl;
            newC = newC->Room_Next;
        }
        cout << " Room Added Successfully." << endl;
        Room_file.close();
    }
    void Add_Room(string type, float price, string status, string features) {
        Room* pnn = new Room;
        ifstream Room_file;
        Room_file.open("D:\\y2 s 2\\project_213_ done\\Room.txt");
        string line, temp[5];
        int k = 0, flag = 0, ct = 0;
        if (Room_file.is_open())
        {
            while (getline(Room_file, line))
            {
                if (ct > 0)
                {
                    k = 0;
                    flag = 1;
                    for (int i = 0; i < 5; i++)
                    {
                        temp[i].clear();
                    }

                    for (int i = 0; i < line.length(); i++)
                    {
                        if (line[i] == ',')
                        {
                            k++;
                        }
                        else
                        {
                            temp[k] += line[i];
                        }
                    }
                }
                ct = 1;
            }

            if (flag == 1)
            {
                pnn->RoomId = stoi(temp[0]) + 1;
            }
            else
            {
                pnn->RoomId = 1;
            }
            pnn->Room_Type = type;
            pnn->Room_Price = price;
            pnn->Room_status = status;
            pnn->Room_Features = features;
            pnn->Room_Next = NULL;
            attach(pnn);
            save_Room();
        }
    }
    void save_Room_edit()
    {
        ofstream Room_file_out("D:\\y2 s 2\\project_213_ done\\Room.txt", ios::out);
        if (!Room_file_out.is_open()) {
            cout << "  Failed to open file for writing." << endl;
            return;
        }
        Room* newC = headptr;
        Room_file_out << "roomId" << ',' << "type" << ',' << "price" << ',' << "status" << ',' << "features" << endl;
        while (newC != NULL)
        {
            Room_file_out << newC->RoomId << ',';
            Room_file_out << newC->Room_Type << ',';
            Room_file_out << newC->Room_Price << ',';
            Room_file_out << newC->Room_status << ',';
            Room_file_out << newC->Room_Features << endl;
            newC = newC->Room_Next;
        }
        Room_file_out.close();
        clear_list();
        cout << "  Room Edited Successfully." << endl;
    }
    void Edit_Room(int id, string newType, float newPrice, string newStatus, string newFeatures)
    {
        ifstream Room_file("D:\\y2 s 2\\project_213_ done\\Room.txt");
        string line;
        string temp[5];
        int k = 0;
        int ct = 0;
        int flag = 0;

        if (Room_file.is_open())
        {
            while (getline(Room_file, line))
            {
                if (ct > 0)
                {
                    k = 0;
                    for (int i = 0; i < 5; i++)
                    {
                        temp[i].clear();
                    }

                    for (int i = 0; i < line.length(); i++)
                    {
                        if (line[i] == ',')
                        {
                            k++;
                        }
                        else
                        {
                            temp[k] += line[i];
                        }
                    }
                    // cout<< temp[0] <<endl;
                    // cout<< temp[1] <<endl;
                    // cout<< temp[2] <<endl;
                    // cout<< temp[3] <<endl;
                    // cout<< temp[4] <<endl;
                    Room* pnn = new Room;
                    if (id == stoi(temp[0]))
                    {
                        pnn->RoomId = id;
                        pnn->Room_Type = newType;
                        pnn->Room_Price = newPrice;
                        pnn->Room_status = newStatus;
                        pnn->Room_Features = newFeatures;
                        flag = 1;
                    }
                    else
                    {
                        pnn->RoomId = stoi(temp[0]);
                        pnn->Room_Type = temp[1];
                        pnn->Room_Price = stof(temp[2]);
                        pnn->Room_status = temp[3];
                        pnn->Room_Features = temp[4];
                    }
                    pnn->Room_Next = NULL;
                    attach(pnn);
                }
                ct++;
            }
            Room_file.close();
            if (flag == 0)
            {
                clear_list();
                cout << "   id not found";
                return;
            }
            save_Room_edit();
        }
        else
        {
            cout << "  Unable to open the file." << endl;
        }
    }
    void Monitor()
    {
        float totalRooms = 0;
        int bookedRooms = 0;

        ifstream Room_file("D:\\y2 s 2\\project_213_ done\\Room.txt");
        string line;
        string temp[5];
        int k = 0;
        int ct = 0;
        float occupancyRate;

        if (Room_file.is_open())
        {
            while (getline(Room_file, line))
            {
                if (ct > 0)
                {
                    k = 0;
                    for (int i = 0; i < 5; i++)
                    {
                        temp[i].clear();
                    }

                    for (int i = 0; i < line.length(); i++)
                    {
                        if (line[i] == ',')
                        {
                            k++;
                        }
                        else
                        {
                            temp[k] += line[i];
                        }
                    }

                    totalRooms++;
                    if (temp[3] == "booked")
                    {
                        bookedRooms++;
                    }
                }
                ct++;
            }
            Room_file.close();

            occupancyRate = (bookedRooms / totalRooms) * 100;

            cout << "Total Rooms: " << totalRooms << endl;
            cout << "Currently Booked Rooms: " << bookedRooms << endl;
            cout << "Occupancy Rate: " << occupancyRate << "%" << endl;
        }
        else
        {
            cout << "  Unable to open the file." << endl;
        }
    }
    void save_Room_delete()
    {
        ofstream Room_file_out("D:\\y2 s 2\\project_213_ done\\Room.txt", ios::out);
        if (!Room_file_out.is_open()) {
            cout << "  Failed to open file for writing." << endl;
            return;
        }
        Room* newC = headptr;
        Room_file_out << "roomId" << ',' << "type" << ',' << "price" << ',' << "status" << ',' << "features" << endl;
        while (newC != NULL)
        {
            Room_file_out << newC->RoomId << ',';
            Room_file_out << newC->Room_Type << ',';
            Room_file_out << newC->Room_Price << ',';
            Room_file_out << newC->Room_status << ',';
            Room_file_out << newC->Room_Features << endl;
            newC = newC->Room_Next;
        }
        Room_file_out.close();
        clear_list();
        cout << "  Room delete Successfully." << endl;
    }
    void delete_Room(int id)
    {
        ifstream Room_file("D:\\y2 s 2\\project_213_ done\\Room.txt");
        string line;
        string temp[5];
        int k = 0;
        int ct = 0;
        int flag = 0;

        if (Room_file.is_open())
        {
            while (getline(Room_file, line))
            {
                if (ct > 0)
                {
                    k = 0;
                    for (int i = 0; i < 5; i++)
                    {
                        temp[i].clear();
                    }

                    for (int i = 0; i < line.length(); i++)
                    {
                        if (line[i] == ',')
                        {
                            k++;
                        }
                        else
                        {
                            temp[k] += line[i];
                        }
                    }
                    if (stoi(temp[0]) != id)
                    {
                        Room* pnn = new Room;
                        pnn->RoomId = stoi(temp[0]);
                        pnn->Room_Type = temp[1];
                        pnn->Room_Price = stof(temp[2]);
                        pnn->Room_status = temp[3];
                        pnn->Room_Features = temp[4];
                        pnn->Room_Next = NULL;
                        attach(pnn);
                    }
                    else {
                        flag = 1;
                    }
                }
                ct++;
            }
            Room_file.close();
            if (flag == 0)
            {
                clear_list();
                cout << "   id not found";
                return;
            }
            save_Room_delete();
        }
        else
        {
            cout << "  Unable to open the file." << endl;
        }
    }
    void Search_Rooms_types(string type)
    {
        ifstream Room_file("D:\\y2 s 2\\project_213_ done\\Room.txt");
        string line;
        string temp[5];
        int k = 0;
        int ct = 0;
        int flag = 0;

        if (Room_file.is_open())
        {
            while (getline(Room_file, line))
            {
                if (ct > 0)
                {
                    k = 0;
                    
                    for (int i = 0; i < 5; i++)
                    {
                        temp[i].clear();
                    }
                    for (int i = 0; i < line.length(); i++)
                    {
                        if (line[i] == ',')
                        {
                            k++;
                        }
                        else
                        {
                            temp[k] += line[i];
                        }
                    }
                    if (temp[1] == type)
                    {
                        flag=1;
                        cout << "Room ID: " << temp[0] << " ";
                        cout << "Room Type: " << temp[1] << " ";
                        cout << "Room Price: " << temp[2] << " ";
                        cout << "Room Status: " << temp[3] << " ";
                        cout << "Room Features: " << temp[4] << endl;
                        cout << "-----------------------------" << endl;
                    }
                }
                ct++;
            }
            if (flag==0)
            {
                cout << " No Rooms from " << type << " found." << endl;
            }
        }
    }
    void Search_Rooms_available(string ava)
    {
        ifstream Room_file("D:\\y2 s 2\\project_213_ done\\Room.txt");
        string line;
        string temp[5];
        int k = 0;
        int ct = 0;
        int flag = 0;

        if (Room_file.is_open())
        {
            while (getline(Room_file, line))
            {
                if (ct > 0)
                {
                    k = 0;
                    for (int i = 0; i < 5; i++)
                    {
                        temp[i].clear();
                    }
                    for (int i = 0; i < line.length(); i++)
                    {
                        if (line[i] == ',')
                        {
                            k++;
                        }
                        else
                        {
                            temp[k] += line[i];
                        }
                    }
                    if (temp[3] == ava)
                    {
                        flag=1;
                        cout << "Room ID: " << temp[0] << " ";
                        cout << "Room Type: " << temp[1] << " ";
                        cout << "Room Price: " << temp[2] << " ";
                        cout << "Room Status: " << temp[3] << " ";
                        cout << "Room Features: " << temp[4] << endl;
                        cout << "-----------------------------" << endl;
                    }
                }
                ct++;
            }
            if (flag == 0)
            {
                cout << " No Rooms  " << ava << " ." << endl;;
            }
        }
    }
    void Search_Rooms_Range(float num1, float num2)
    {
        ifstream Room_file("D:\\y2 s 2\\project_213_ done\\Room.txt");
        string line;
        string temp[5];
        int k = 0;
        int ct = 0;
        int flag = 0;

        if (Room_file.is_open())
        {
            while (getline(Room_file, line))
            {
                if (ct > 0)
                {
                    k = 0;
                    for (int i = 0; i < 5; i++)
                    {
                        temp[i].clear();
                    }
                    for (int i = 0; i < line.length(); i++)
                    {
                        if (line[i] == ',')
                        {
                            k++;
                        }
                        else
                        {
                            temp[k] += line[i];
                        }
                    }
                    float price = stof(temp[2]);

                    if (price >= num1 && price <= num2)
                    {
                        flag=1;
                        cout << "Room ID: " << temp[0] << " ";
                        cout << "Room Type: " << temp[1] << " ";
                        cout << "Room Price: " << temp[2] << " ";
                        cout << "Room Status: " << temp[3] << " ";
                        cout << "Room Features: " << temp[4] << endl;
                        cout << "-----------------------------" << endl;
                    }
                }
                ct++;
            }
            if (flag==0)
            {
                cout << " No rooms found in the given price range (" << num1 << " - " << num2 << ")." << endl;
            }
        }
        else
        {
            cout << "can't open file " ;
        }
    }
    void change_state_room(int idroom)
    {
        ifstream Room_file("D:\\y2 s 2\\project_213_ done\\Room.txt");
        string line;
        string temp[5];
        int k = 0;
        int ct = 0;
        int flag = 0;

        if (Room_file.is_open())
        {
            while (getline(Room_file, line))
            {
                if (ct > 0)
                {
                    k = 0;
                    for (int i = 0; i < 5; i++)
                    {
                        temp[i].clear();
                    }

                    for (int i = 0; i < line.length(); i++)
                    {
                        if (line[i] == ',')
                        {
                            k++;
                        }
                        else
                        {
                            temp[k] += line[i];
                        }
                    }
                    Room* pnn = new Room;
                    if (idroom == stoi(temp[0]))
                    {
                        pnn->RoomId = idroom;
                        pnn->Room_Type = temp[1];
                        pnn->Room_Price = stof(temp[2]);
                        if(temp[3] == "booked")
                        {
                            pnn->Room_status = "available";
                        }
                        else
                        {
                            pnn->Room_status = "booked";
                        }
                        pnn->Room_Features = temp[4];
                        flag = 1;
                    }
                    else
                    {
                        pnn->RoomId = stoi(temp[0]);
                        pnn->Room_Type = temp[1];
                        pnn->Room_Price = stof(temp[2]);
                        pnn->Room_status = temp[3];
                        pnn->Room_Features = temp[4];
                    }
                    pnn->Room_Next = NULL;
                    attach(pnn);
                }
                ct++;
            }
            Room_file.close();
            if (flag == 0)
            {
                clear_list();
                cout << "   Room ID not found";
                return;
            }
            save_Room_edit();
        }
        else
        {
            cout << "  Unable to open the file." << endl;
        }
    }
    void clear_list() {
        Room* curr = headptr;
        while (curr != NULL) {
            Room* temp = curr;
            curr = curr->Room_Next;
            delete temp;
        }
        headptr = NULL;
        tailptr = NULL;
    }
    int is_Booked(int idroom)
    {
        ifstream Room_file("D:\\y2 s 2\\project_213_ done\\Room.txt");
        string line;
        string temp[5];
        int k = 0;
        int ct = 0;
        int flag=0;

        if (Room_file.is_open())
        {
            while (getline(Room_file, line))
            {
                if (ct > 0)
                {
                    k = 0;
                    for (int i = 0; i < 5; i++)
                    {
                        temp[i].clear();
                    }

                    for (int i = 0; i < line.length(); i++)
                    {
                        if (line[i] == ',')
                        {
                            k++;
                        }
                        else
                        {
                            temp[k] += line[i];
                        }
                    }

                    if (stoi(temp[0]) == idroom)
                    {
                        flag=1;
                        if (temp[3] == "booked" )
                        {
                            cout << "  Room ID " << idroom << " is already booked." << endl;
                            Room_file.close();
                            return 1;
                        }
                        else
                        {
                            cout << "  Room ID " << idroom << " is available for booking." << endl;
                            Room_file.close();
                            return 0;
                        }
                    }
                    
                }
                ct++;
            }
            cout << "  Room ID " << idroom << " not found." << endl;
            Room_file.close();
        }
        return 1;
    }
};

/*Booking_Class*/

class Booking
{
public:
    int Booking_Id;
    string Guest_Id;
    string Room_Id;
    string check_in_Date;
    string check_out_Date;
    float total_Cost;
    Booking* Booking_Next;
};
class list_Booking
{
public:
    Booking* headptr;
    Booking* tailptr;

    list_Booking() {
        headptr = NULL;
        tailptr = NULL;
    }

    void attach(Booking* pnn) {
        if (headptr == NULL) {
            headptr = pnn;
            tailptr = pnn;
        }
        else {
            tailptr->Booking_Next = pnn;
            tailptr = pnn;
        }
    }
    void clear_list() {
        Booking* curr = headptr;
        while (curr != NULL) {
            Booking* temp = curr;
            curr = curr->Booking_Next;
            delete temp;
        }
        headptr = NULL;
        tailptr = NULL;
    }
    void Display()
    {
        ifstream Booking_file("D:\\y2 s 2\\project_213_ done\\Booking.txt");
        string line;
        string temp[6];
        int k = 0;
        int ct = 0;

        if (Booking_file.is_open())
        {
            while (getline(Booking_file, line))
            {
                if (ct > 0)
                {
                    k = 0;
                    for (int i = 0; i < 6; i++)
                    {
                        temp[i].clear();
                    }

                    for (int i = 0; i < line.length(); i++)
                    {
                        if (line[i] == ',')
                        {
                            k++;
                        }
                        else
                        {
                            temp[k] += line[i];
                        }
                    }

                    cout << temp[0] << ',';
                    cout << temp[1] << ',';
                    cout << temp[2] << ',';
                    cout << temp[3] << ',';
                    cout << temp[4] << ',';
                    cout << temp[5] << endl;
                }
                ct++;
            }
            Booking_file.close();
        }
        else
        {
            cout << "  Unable to open the file." << endl;
        }
    }

    ~list_Booking()
    {
        Booking* tailptrrav = headptr;
        while (headptr != NULL)
        {
            headptr = tailptrrav->Booking_Next;
            tailptrrav->Booking_Next = NULL;
            delete tailptrrav;
            tailptrrav = headptr;
        }
    }
    float get_Room(int id)
    {
        ifstream Room_file("D:\\y2 s 2\\project_213_ done\\Room.txt");
        string line;
        string temp[5];
        int k = 0;
        int ct = 0;
        float price = -1;

        if (Room_file.is_open())
        {
            while (getline(Room_file, line))
            {
                if (ct > 0)
                {
                    k = 0;
                    for (int i = 0; i < 5; i++)
                    {
                        temp[i].clear();
                    }
                    for (int i = 0; i < line.length(); i++)
                    {
                        if (line[i] == ',')
                        {
                            k++;
                        }
                        else
                        {
                            temp[k] += line[i];
                        }
                    }

                    if (stoi(temp[0]) == id)
                    {
                        price = stof(temp[2]);
                        Room_file.close();
                        break;
                    }
                }
                ct++;
            }
        }
        else
        {
            cout << "  Unable to open the file." << endl;
        }
        Room_file.close();
        return price;
    }
    void Book_Room(int guestId, int roomId, string checkInDate, string checkOutDate)
    {
        list_Room roomList;
        if (roomList.is_Booked(roomId))
        {
            return;
        }
        
        Booking* pnn = new Booking;
        ifstream Booking_file;
        Booking_file.open("D:\\y2 s 2\\project_213_ done\\Booking.txt");
        string line, temp[6];
        int k = 0, flag = 0, ct = 0, h = 0, j = 0;
        string parts[3];
        float totalCost = 0;
        int day, day2, month2, month, year, year2, day_in, day_out, total_days = 0;

        if (Booking_file.is_open())
        {
            while (getline(Booking_file, line))
            {
                if (ct > 0)
                {
                    k = 0;
                    h = 0;
                    j = 0;
                    flag = 1;
                    for (int i = 0; i < 6; i++)
                    {
                        temp[i].clear();
                    }
                    for (int i = 0; i < line.length(); i++)
                    {
                        if (line[i] == ',')
                        {
                            k++;
                        }
                        else
                        {
                            temp[k] += line[i];
                        }
                    }
                }
                ct = 1;
            }
            for (int i = 0; i < checkInDate.length(); i++)
            {
                if (checkInDate[i] == '/')
                {
                    h++;
                }
                else
                {
                    parts[h] += checkInDate[i];
                }
            }
            day = stoi(parts[0]);
            month = stoi(parts[1]);
            year = stoi(parts[2]);
            day_in = day + (month * 30) + (year * 365);

            for (int i = 0; i < 3; i++)
            {
                parts[i].clear();
            }
            for (int i = 0; i < checkOutDate.length(); i++)
            {
                if (checkOutDate[i] == '/')
                {
                    j++;
                }
                else
                {
                    parts[j] += checkOutDate[i];
                }
            }

            day2 = stoi(parts[0]);
            month2 = stoi(parts[1]);
            year2 = stoi(parts[2]);
            day_out = day2 + (month2 * 30) + (year2 * 365);
            total_days = day_out - day_in;
            totalCost = get_Room(roomId) * total_days;
            totalCost=totalCost*1.14;
            for (int i = 0; i < 3; i++)
            {
                parts[i].clear();
            }

            if (flag == 1)
            {
                pnn->Booking_Id = stoi(temp[0]) + 1;
            }
            else
            {
                pnn->Booking_Id = 1;
            }

            pnn->Guest_Id = to_string(guestId);
            pnn->Room_Id = to_string(roomId);
            pnn->check_in_Date = checkInDate;
            pnn->check_out_Date = checkOutDate;
            pnn->total_Cost = totalCost;
            pnn->Booking_Next = NULL;

            attach(pnn);
            save_Booking(roomId);
            Booking_file.close();
        }
        else
        {
            cout << "Failed to open file. Please check the file path." << endl;
        }
    }

    void check_out(int guestId, string currentDate, int bookingId , int role)
    {
        ifstream Booking_file("D:\\y2 s 2\\project_213_ done\\Booking.txt");
        string line;
        string temp[6];
        int k = 0;
        int ct = 0;
        string part[3], part2[3];
        list_Room roomList;
        if (Booking_file.is_open())
        {
            while (getline(Booking_file, line))
            {
                if (ct > 0)
                {
                    k = 0;
                    for (int i = 0; i < 6; i++)
                    {
                        temp[i].clear();
                    }

                    for (int i = 0; i < line.length(); i++)
                    {
                        if (line[i] == ',')
                        {
                            k++;
                        }
                        else
                        {

                            temp[k] += line[i];
                        }
                    }
                    if (stoi(temp[0]) == bookingId && stoi(temp[1]) == guestId)
                    {
                        if (currentDate ==temp[4])
                        {
                            if (roomList.is_Booked(stoi(temp[2])) == 1)
                            {
                                roomList.change_state_room(stoi(temp[2]));
                            }
                            cout << "price: " << temp[5] << " EGP" << endl;
                            cout << "Room status updated to available." << endl;
                        }
                        else if (role==1)
                        {
                            int h = 0, j = 0;
                            for (int i = 0; i < currentDate.length(); i++) {
                                if (currentDate[i] == '/')
                                {

                                    h++;
                                }
                                else
                                {

                                    part[h] += currentDate[i];
                                }
                            }
                            for (int i = 0; i < temp[4].length(); i++) {
                                if (temp[4][i] == '/')
                                {

                                    j++;
                                }
                                else
                                {

                                    part2[j] += temp[4][i];
                                }
                            }
                            int day1 = stoi(part[0]), month1 = stoi(part[1]), year1 = stoi(part[2]);
                            int day2 = stoi(part2[0]), month2 = stoi(part2[1]), year2 = stoi(part2[2]);
                            int days1 = day1 + month1 * 30 + year1 * 365;
                            int days2 = day2 + month2 * 30 + year2 * 365;
                            if (roomList.is_Booked(stoi(temp[2])) == 1)
                            {
                                roomList.change_state_room(stoi(temp[2]));
                            }

                            cout << "price: " << temp[5] << " EGP" << endl;
                            cout << "Room status updated to available." << endl;

                            cout << "Days between current date and check-out date: " << (days2 - days1) << endl;
                        }
                        Booking_file.close();
                        return;
                    }
                }
                ct++;
            }
            Booking_file.close();
            cout << "Booking ID not found." << endl;
        }
        else
        {
            cout << "Failed to open file. Please check the file path." << endl;
        }
    }
    void save_Booking(int room)
    {
        fstream Booking_file("D:\\y2 s 2\\project_213_ done\\Booking.txt", ios::app);
        Booking* newC = tailptr;
        while (newC != NULL)
        {
            cout << newC->Booking_Id  << "  your Booking id" << endl ;
            Booking_file << newC->Booking_Id << ",";
            Booking_file << newC->Guest_Id << ",";
            Booking_file << newC->Room_Id << ",";
            Booking_file << newC->check_in_Date << ",";
            Booking_file << newC->check_out_Date << ",";
            Booking_file << newC->total_Cost << endl;
            newC = newC->Booking_Next;
        }
        cout << "  Room Booked Successfully." << endl;
        Booking_file.close();
        list_Room roomList;
       // roomList.change_state_room(room);
    }

    void check_in(int guestId, string currentDate)
    {
        ifstream Booking_file("D:\\y2 s 2\\project_213_ done\\Booking.txt");
        string line;
        string temp[6];
        int k = 0;
        int ct = 0;
        int found = 0;
        int daysCheckIn ;
        int daysCurrent;
        list_Room roomList;

        if (Booking_file.is_open())
        {
            while (getline(Booking_file, line))
            {
                if (ct > 0)
                {
                    k = 0;
                    for (int i = 0; i < 6; i++)
                    {

                        temp[i].clear();
                    }

                    for (int i = 0; i < line.length(); i++)
                    {
                        if (line[i] == ',')
                        {
                            k++;
                        }
                        else
                        {
                            temp[k] += line[i];
                        }
                    }

                    if (stoi(temp[1]) == guestId)
                    {
                        string checkInDate = temp[3];
                        int day1 = 0, month1 = 0, year1 = 0;
                        int day2 = 0, month2 = 0, year2 = 0;
                        int idx = 0;
                        string part[3]; idx = 0;
                        for (int i = 0; i < checkInDate.length(); i++)
                        {
                            if (checkInDate[i] == '/')
                            {
                                idx++;
                            }
                            else
                            {
                                part[idx] += checkInDate[i];
                            }
                        }
                        day1 = stoi(part[0]);
                        month1 = stoi(part[1]);
                        year1 = stoi(part[2]);

                        idx = 0;
                        for (int i = 0; i < 3; i++) 
                        {
                            part[i].clear();
                        }
                        for (int i = 0; i < currentDate.length(); i++)
                        {
                            if (currentDate[i] == '/')
                            {
                                idx++;
                            }
                            else
                            {
                                part[idx] += currentDate[i];
                            }
                        }
                        day2 = stoi(part[0]);
                        month2 = stoi(part[1]);
                        year2 = stoi(part[2]);
                         daysCheckIn = day1 + month1 * 30 + year1 * 365;
                         daysCurrent = day2 + month2 * 30 + year2 * 365;
                        if (daysCheckIn - daysCurrent == 1 || daysCheckIn - daysCurrent == 0)
                        {
                            cout << "Booking ID: " << temp[0] << endl;
                            cout << "Guest ID: " << temp[1] << endl;
                            cout << "Room ID: " << temp[2] << endl;
                            cout << "Check-in Date: " << temp[3] << endl;
                            cout << "Check-out Date: " << temp[4] << endl;
                            cout << "Total Cost: " << temp[5] << " EGP" << endl;
                            cout << "You can confirm your booking now. Do you want to confirm? (y/n): ";
                            char confirm;
                            cin >> confirm;
                            if (confirm == 'y' || confirm == 'Y')
                            {
                                cout << "Booking confirmed successfully!" << endl;

                                if (roomList.is_Booked(stoi(temp[2])) == 0)
                                {
                                    roomList.change_state_room(stoi(temp[2]));
                                }
                                else
                                {
                                    cout << "Room ID " << temp[2] << " is already booked." << endl;
                                }
                            }
                            else
                            {
                                Cancel_Booking(guestId, stoi(temp[0]), currentDate);
                            }
                            found = 1;
                        }
                    }
                }
                ct++;
            }
            Booking_file.close();
            if (found==0)
            {
                if (daysCheckIn - daysCurrent < 0 && roomList.is_Booked(stoi(temp[2])) == 0)
                {
                    roomList.change_state_room(stoi(temp[2]));
                }
            }
        }
        else
        {
            cout << "  Unable to open the file." << endl;
        }
    }
    void Income_Report(string mode, string targetDateOrMonth)
    {
        ifstream Booking_file;
        Booking_file.open("D:\\y2 s 2\\project_213_ done\\Booking.txt");

        string line, temp[6], part[3];
        float totalIncome = 0.0;
        int ct = 0, k = 0, h = 0, month, year;
        string checkInDate, extractedDate;

        if (Booking_file.is_open())
        {
            while (getline(Booking_file, line))
            {
                if (ct > 0)
                {
                    k = 0;
                    h = 0;
                    for (int i = 0; i < 6; i++)
                    {
                        temp[i].clear();
                    }
                    for (int i = 0; i < 3; i++)
                    {
                        part[i].clear();
                    }

                    for (int i = 0; i < line.length(); i++)
                    {
                        if (line[i] == ',')
                        {
                            k++;
                        }
                        else
                        {
                            temp[k] += line[i];
                        }
                    }

                    checkInDate = temp[3];

                    if (mode == "daily")
                    {
                        if (checkInDate == targetDateOrMonth)
                        {
                            totalIncome += stof(temp[5]);
                        }
                    }
                    else if (mode == "monthly")
                    {
                        for (int i = 0; i < checkInDate.length(); i++)
                        {
                            if (checkInDate[i] == '/')
                            {
                                h++;
                            }
                            else
                            {
                                part[h] += checkInDate[i];
                            }
                        }

                        extractedDate = part[1] + "/" + part[2];
                        if (extractedDate == targetDateOrMonth)
                        {
                            totalIncome += stof(temp[5]);
                        }
                    }
                }

                ct = 1;
            }

            if (mode == "daily")
            {
                cout << "Daily income for " << targetDateOrMonth << " is: " << totalIncome << " EGP" << endl;
            }
            else if (mode == "monthly")
            {
                cout << "Monthly income for " << targetDateOrMonth << " is: " << totalIncome << " EGP" << endl;
            }

            Booking_file.close();
        }
        else
        {
            cout << "Failed to open file. Please check the file path." << endl;
        }
    }
    void check_check_out(int guestId, string currentDate)
    {
        int check = 0;
        ifstream Booking_file("D:\\y2 s 2\\project_213_ done\\Booking.txt");
        string line;
        string temp[6];
        int k = 0;
        int ct = 0;

        if (Booking_file.is_open())
        {
            while (getline(Booking_file, line))
            {
                if (ct > 0)
                {
                    k = 0;
                    for (int i = 0; i < 6; i++)
                    {
                        temp[i].clear();
                    }
                    for (int i = 0; i < line.length(); i++)
                    {
                        if (line[i] == ',')
                        {
                            k++;
                        }
                        else
                        {
                            temp[k] += line[i];
                        }
                    }
                    if (stoi(temp[1]) == guestId && temp[4] == currentDate)
                    {
                        check_out(guestId, currentDate, stoi(temp[0]) , check);
                    }
                }
                ct++;
            }

            Booking_file.close();
        }
        else
        {
            cout << "Failed to open file. Please check the file path." << endl;
        }
    }
    void View_Booking_History(int guestId)
    {
        ifstream Booking_file("D:\\y2 s 2\\project_213_ done\\Booking.txt");
        string line;
        string temp[6];
        int k = 0;
        int ct = 0;

        if (Booking_file.is_open())
        {
            cout << "Booking History for Guest ID: " << guestId << endl;
            cout << "-----------------------------------------" << endl;

            while (getline(Booking_file, line))
            {
                if (ct > 0)
                {
                    k = 0;
                    for (int i = 0; i < 6; i++)
                    {
                        temp[i].clear();
                    }

                    for (int i = 0; i < line.length(); i++)
                    {
                        if (line[i] == ',')
                        {
                            k++;
                        }
                        else
                        {
                            temp[k] += line[i];
                        }
                    }

                    if (stoi(temp[1]) == guestId)
                    {
                        cout << "Booking ID: " << temp[0] << endl;
                        cout << "Room ID: " << temp[2] << endl;
                        cout << "Check-in Date: " << temp[3] << endl;
                        cout << "Check-out Date: " << temp[4] << endl;
                        cout << "Total Cost: " << temp[5] << " EGP" << endl;
                        cout << "-----------------------------------------" << endl;
                    }
                }
                ct++;
            }

            Booking_file.close();
        }
        else
        {
            cout << "  Unable to open the file." << endl;
        }
    }

    void Cancel_Booking(int guestId, int bookingId, string curremt_data)
    {
        ifstream Booking_file("D:\\y2 s 2\\project_213_ done\\Booking.txt");
        string line, data, part[3] , Rid ;
        string temp[6];
        int k = 0, h = 0, j = 0;
        int ct = 0;
        int flag = 0;
        int flag2 = 0;
        int day, day2, month2, month, year, year2, day_in, day_out, total_days;

        if (Booking_file.is_open())
        {
            while (getline(Booking_file, line))
            {
                if (ct > 0)
                {
                    k = 0;
                    for (int i = 0; i < 6; i++)
                    {
                        temp[i].clear();
                    }
                    for (int i = 0; i < line.length(); i++)
                    {
                        if (line[i] == ',')
                        {
                            k++;
                        }
                        else
                        {
                            temp[k] += line[i];
                        }
                    }
                    if (bookingId == stoi(temp[0]) && guestId == stoi(temp[1]))
                    {
                        flag2++;
                        data= temp[3];
                        Rid= temp[2];
                    }
                }
                ct++;
            }

            if (flag2 == 0)
            {
                cout << "  Booking ID not found for the given Guest ID." << endl;
                Booking_file.close();
                return;
            }
            for (int i = 0; i < curremt_data.length(); i++)
            {
                if (curremt_data[i] == '/')
                {
                    h++;
                }
                else
                {
                    part[h] += curremt_data[i];
                }
            }

            day = stoi(part[0]);
            month = stoi(part[1]);
            year = stoi(part[2]);
            day_in = day + (month * 30) + (year * 365);
            for (int i = 0; i < 3; i++)
            {
                part[i].clear();
            }

            for (int i = 0; i < data.length(); i++)
            {
                if (data[i] == '/')
                {
                    j++;
                }
                else
                {
                    part[j] += data[i];
                }
            }

            day2 = stoi(part[0]);
            month2 = stoi(part[1]);
            year2 = stoi(part[2]);

            day_out = day2 + (month2 * 30) + (year2 * 365);

            total_days = day_out - day_in;

            if (day_in < day_out) {
                total_days = 1;
            }
            if (total_days == 1 )
            {
                delete_booking(to_string(bookingId));
                    list_Room roomList;
                    roomList.change_state_room(stoi(Rid));

            }
            else {
                cout << "  You cannot cancel the booking as it is not within the allowed time frame." << endl;
            }
            for (int i = 0; i < 3; i++)
            {
                part[i].clear();
            }
            for (int i = 0; i < 6; i++)
            {
                temp[i].clear();
            }
        }
    }

    void delete_booking(string idbooking)
    {
        ifstream Booking_file("D:\\y2 s 2\\project_213_ done\\Booking.txt");
        string line;
        string temp[6];
        int k = 0;
        int ct = 0;
        int flag = 0;

        if (Booking_file.is_open())
        {
            while (getline(Booking_file, line))
            {
                if (ct > 0)
                {
                    k = 0;
                    for (int i = 0; i < 6; i++)
                    {
                        temp[i].clear();
                    }

                    for (int i = 0; i < line.length(); i++)
                    {
                        if (line[i] == ',')
                        {
                            k++;
                        }
                        else
                        {
                            temp[k] += line[i];
                        }
                    }

                    if (temp[0] != idbooking)
                    {
                        Booking* pnn = new Booking;
                        pnn->Booking_Id = stoi(temp[0]);
                        pnn->Guest_Id = temp[1];
                        pnn->Room_Id = temp[2];
                        pnn->check_in_Date = temp[3];
                        pnn->check_out_Date = temp[4];
                        pnn->total_Cost = stof(temp[5]);
                        pnn->Booking_Next = NULL;
                        attach(pnn);
                    }
                    else
                    {
                        flag = 1;
                    }
                }
                ct++;
            }
            Booking_file.close();
            if (flag == 0)
            {
                clear_list();
                cout << "  Booking ID not found." << endl;
                return;
            }
            save_booking_delete();
        }
        else
        {
            cout << "  Unable to open the file." << endl;
        }
    }

    void save_booking_delete()
    {
        ofstream Booking_file_out("D:\\y2 s 2\\project_213_ done\\Booking.txt", ios::out);
        if (!Booking_file_out.is_open())
        {
            cout << "  Failed to open file for writing." << endl;
            return;
        }
        Booking* newC = headptr;
        Booking_file_out << "BookingId" << ',' << "GuestId" << ',' << "RoomId" << ',' << "CheckInDate" << ',' << "CheckOutDate" << ',' << "TotalCost" << endl;
        while (newC != NULL)
        {
            Booking_file_out << newC->Booking_Id << ',';
            Booking_file_out << newC->Guest_Id << ',';
            Booking_file_out << newC->Room_Id << ',';
            Booking_file_out << newC->check_in_Date << ',';
            Booking_file_out << newC->check_out_Date << ',';
            Booking_file_out << newC->total_Cost << endl;
            newC = newC->Booking_Next;
        }
        Booking_file_out.close();
        clear_list();
        cout << "  Booking deleted successfully." << endl;
    }

};


int main() {
    list_Guest guestList;
    list_Admin adminList;
    list_Room roomlist;
    list_Booking bookinglist;

    int choice = 0;

    while (choice != 3) {
        cout << "Welcome to the Hotel Management System" << endl;
        cout << "1. Guest Operations" << endl;
        cout << "2. Admin Operations" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: " << endl;
        cin >> choice;

        if (choice == 1) {
            int loggedInStatus = 0;
            string currentDate;
            cout << "Enter current date (DD/MM/YYYY): ";
            cin >> currentDate;
            
            while (loggedInStatus == 0)
            {
                int loginChoice;
                cout << "Guest Area:" << endl;
                cout << "1. Register" << endl;
                cout << "2. Login" << endl;
                cout << "Enter your choice: " << endl;
                cin >> loginChoice;

                if (loginChoice == 1) 
                {
                    string name, password;
                    cout << "Enter your name: " << endl;
                    cin >> name;
                    cout << "Enter your password: " << endl;
                    cin >> password;
                    guestList.Register_Guest(name, password);
                }
                else if (loginChoice == 2)
                {
                    int id;
                    string password;
                    cout << "Enter your ID: " << endl;
                    cin >> id;
                    cout << "Enter your password: " << endl;
                    cin >> password;

                    int attempts = 0;
                    while (attempts < 3)
                    {
                        if (guestList.Guest_Login(id, password)) {
                            cout << "Login successful!" << endl;
                            loggedInStatus = 1;
                            guestList.currentGuestID =id;
                            break;
                        }
                        else {
                            attempts++;
                            if (attempts < 3) {
                                cout << "Login failed. Try again (" << attempts << "/3)." << endl;
                                cout << "Enter your ID: " << endl;
                                cin >> id;
                                cout << "Enter your password: " << endl;
                                cin >> password;

                            }
                            else {
                                cout << "Too many failed attempts. Exiting the system." << endl;
                                return 0;
                            }
                        }
                    }
                }
                else {
                    cout << "Invalid choice." << endl;
                }
            }
            int guestChoice = 0;
            int checked = 0;
            while (guestChoice != 6) {
                
                if (checked == 0) {
                    bookinglist.check_in(guestList.currentGuestID, currentDate);
                    bookinglist.check_check_out(guestList.currentGuestID, currentDate);
                    checked = 1;
                }
                cout << "Guest Operations:" << endl;
                cout << "1. Search Rooms" << endl;
                cout << "2. Book Room" << endl;
                cout << "3. Cancel Booking" << endl;
                cout << "4. View Booking History" << endl;
                cout << "5. Check-out" << endl;
                cout << "6. Logout" << endl;
                cout << "Enter your choice: " << endl;
                cin >> guestChoice;

                if (guestChoice == 1)
                {
                    int searchChoice;
                    cout << "Search Rooms by:" << endl;
                    cout << "1. Type" << endl;
                    cout << "2. Price Range" << endl;
                    cout << "3. available" << endl;
                    cout << "Enter your choice: " << endl;
                    cin >> searchChoice;

                    if (searchChoice == 1) {
                        int typeChoice;
                        cout << "Select room type:" << endl;
                        cout << "1. Single" << endl;
                        cout << "2. Double" << endl;
                        cout << "3. Suite" << endl;
                        cout << "Enter your choice: " << endl;
                        cin >> typeChoice;

                        string type;
                        if (typeChoice == 1) {
                            type = "single";
                        }
                        else if (typeChoice == 2) {
                            type = "double";
                        }
                        else if (typeChoice == 3) {
                            type = "suite";
                        }
                        else {
                            cout << "Invalid choice. Returning to menu." << endl;
                            guestChoice = 0;
                        }
                        roomlist.Search_Rooms_types(type);
                    }
                    else if (searchChoice == 2) {
                        float minPrice, maxPrice;
                        cout << "Enter min price: ";
                        cin >> minPrice;
                        cout << "Enter max price: ";
                        cin >> maxPrice;
                        roomlist.Search_Rooms_Range(minPrice, maxPrice);
                    }
                    else if (searchChoice == 3) {
                        roomlist.Search_Rooms_available("available");
                    }
                }
                else if (guestChoice == 2) {
                    int roomId;
                    string checkIn, checkOut;
                    cout << "Enter Room ID: ";
                    cin >> roomId;
                    cout << "Enter Check-in Date: ";
                    cin >> checkIn;
                    cout << "Enter Check-out Date: ";
                    cin >> checkOut;
                    bookinglist.Book_Room(guestList.currentGuestID, roomId, checkIn, checkOut);
                }
                else if (guestChoice == 3) {
                    int bookingId;
                    cout << "Enter Booking ID: ";
                    cin >> bookingId;
                    bookinglist.Cancel_Booking(guestList.currentGuestID, bookingId, currentDate);
                }
                else if (guestChoice == 4) {
                    bookinglist.View_Booking_History(guestList.currentGuestID);
                }
                else if (guestChoice == 5) {
                    int bookingId;
                    cout << "Enter Booking ID: ";
                    cin >> bookingId;
                    bookinglist.check_out(guestList.currentGuestID ,currentDate, bookingId,1);
                }
                else if (guestChoice == 6) {
                    cout << "Logging out..." << endl;
                    guestList.Logout();
                    break;
                }
                else {
                    cout << "Invalid choice." << endl;
                }
            }
        }
        else if (choice == 2)
        {
            int loggedInStatus = 0;
            while (loggedInStatus == 0)
            {
                int loginChoice;
                cout << "Admin Area:" << endl;
                cout << "1. Login" << endl;
                cout << "Enter your choice: " << endl;
                cin >> loginChoice;

                string name, password;
                if (loginChoice == 1) {
                    int id;
                    string password;
                    cout << "Enter Admin ID: ";
                    cin >> id;
                    cout << "Enter password: ";
                    cin >> password;
                    int attempts = 0;
                    while (attempts < 3) {
                        if (adminList.Admin_Login(id, password)) {
                            cout << "Admin login successful!" << endl;
                            adminList.currentAdminID =id;
                            loggedInStatus = 1;
                            break;
                        }
                        else {
                            attempts++;
                            if (attempts < 3) {
                                cout << "Login failed. Try again (" << attempts << "/3)." << endl;
                                cout << "Enter Admin ID: ";
                                cin >> id;
                                cout << "Enter password: ";
                                cin >> password;
                            }
                            else {
                                cout << "Too many failed attempts. Exiting the system." << endl;
                                return 0;
                            }
                        }
                    }
                }
                else {
                    cout << "Invalid choice." << endl;
                }
            }
            int adminChoice = 0;
            while (adminChoice != 7) {
                cout << "Admin Operations:" << endl;
                cout << "1. Add Room" << endl;
                cout << "2. Edit Room" << endl;
                cout << "3. Delete Room" << endl;
                cout << "4. View All Bookings" << endl;
                cout << "5. Monitor Occupancy Rate" << endl;
                cout << "6. Income Report" << endl;
                cout << "7. Logout" << endl;
                cout << "Enter your choice: " << endl;
                cin >> adminChoice;
                if (adminChoice == 1) {
                    string type, status, features;
                    float price;
                    cout << "Enter Room Type: " << endl;
                    cin >> type;
                    cout << "Enter Room Price: " << endl;
                    cin >> price;
                    cout << "Enter Room Status: " << endl;
                    cin >> status;
                    cout << "Enter Room Features: " << endl;
                    cin >> features;
                    roomlist.Add_Room(type, price, status, features);
                }
                else if (adminChoice == 2) {
                    int roomId;
                    string type, status, features;
                    float price;
                    cout << "Enter Room ID to edit: " << endl;
                    cin >> roomId;
                    cout << "Enter new Type: " << endl;
                    cin >> type;
                    cout << "Enter new Price: " << endl;
                    cin >> price;
                    cout << "Enter new Status: " << endl;
                    cin >> status;
                    cout << "Enter new Features: " << endl;
                    cin >> features;
                    roomlist.Edit_Room(roomId, type, price, status, features);
                }
                else if (adminChoice == 3) {
                    int roomId;
                    cout << "Enter Room ID to delete: " << endl;
                    cin >> roomId;
                    roomlist.delete_Room(roomId);
                }
                else if (adminChoice == 4) {
                    bookinglist.Display();
                }
                else if (adminChoice == 5) {
                    roomlist.Monitor();
                }
                else if (adminChoice == 6) {
                    string mode, date;
                    int mode_type , year = 0 , day= 0 , month=0;
                    cout << "Enter report mode (daily/monthly): ";
                    cout << "Enter 1 for daily " <<endl;
                    cout << "Enter 2 for monthly " <<endl;
                    cin >> mode_type;
                    if (mode_type == 1)
                    {
                        mode = "daily";
                        cout << "Enter target day ";
                        cin >> day;
                        cout << "Enter target month ";
                        cin >> month;
                        cout << "Enter target year ";
                        cin >> year;
                        date = to_string(day) + "/" + to_string(month) + "/" + to_string(year);
                    }
                    else if (mode_type==2)
                    {
                        mode = "monthly";
                        cout << "Enter target month ";
                        cin >> month;
                        cout << "Enter target year ";
                        cin >> year;
                        date =to_string(month) + "/" + to_string(year);
                    }

                    bookinglist.Income_Report(mode, date);
                }
                else if (adminChoice == 7) {
                    cout << "Logging out..." << endl;
                    adminList.Logout();
                    break;
                }
                else {
                    cout << "Invalid choice." << endl;
                }
            }
        }
        else if (choice == 3) {
            cout << "Exiting the system. Goodbye!" << endl;
        }
        else {
            cout << "Invalid main choice." << endl;
        }
    }
    return 0;
}
