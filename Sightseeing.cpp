#include "Sightseeing.h"

Sightseeing::Sightseeing()
{
}

Sightseeing::Sightseeing(string _name, string _address, string _description, Date _date, Time_ _time, float _rating, float _price, float _photosPrice, string _guide, int _number, int _minNumber, int _maxNumber, string _sightseeingTransport)
    :Tour(_name, _address, _description, _date, _time, _rating, _price,
        _photosPrice, _guide, _number, _minNumber, _maxNumber)
{
    setSightseeingTransport(_sightseeingTransport);
}

Sightseeing::Sightseeing(bool a)
{
    string str;
    int intVar, intVar1, intVar2;
    float floatVar;
    Date date1;
    Time_ time1;
    cout << "|   Enter name: ";
    getline(cin, str);
    setName(str);
    cout << "|   Enter address: ";
    getline(cin, str);
    setAddress(str);
    cout << "|   Enter type of sightseeing transport: ";
    getline(cin, str);
    setSightseeingTransport(str);
    cout << "|   Enter guide name: ";
    getline(cin, str);
    setGuide(str);
    cout << "|   Enter equipment: ";
    getline(cin, str);
    if (str.size() <= 3) {
        HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(console_color, 4);
        throw new TourInputErrorException(1);
    }
    equipment.push_back(str);
    cout << "|   Enter description: ";
    getline(cin, str);
    setAddress(str);
    cout << "|   Enter date: ";
    cin >> date1;
    setDate(date1);
    cout << "|   Enter time: ";
    cin >> time1;
    setTime(time1);
    cout << "|   Enter rating: ";
    cin >> floatVar;
    setRating(floatVar);
    cout << "|   Enter price: ";
    cin >> floatVar;
    setPrice(floatVar);
    cout << "|   Enter price for photos: ";
    cin >> floatVar;
    setPhotosPrice(floatVar);
    cout << "|   Enter price for " << TransportType[0] << ": ";
    cin >> floatVar;
    setPriceTransportType1(floatVar);
    cout << "|   Enter price for " << TransportType[1] << ": ";
    cin >> floatVar;
    setPriceTransportType2(floatVar);
    cout << "|   Enter price for " << TransportType[2] << ": ";
    cin >> floatVar;
    setPriceTransportType3(floatVar);
    cout << "|   Enter number of tourists: ";
    cin >> intVar;
    cout << "|   Enter min number of tourists: ";
    cin >> intVar1;
    cout << "|   Enter max number of tourists: ";
    cin >> intVar2;
    setNumbers(intVar, intVar1, intVar2);
}

string Sightseeing::TourType() const
{
    return "Sightseeing";
}

Sightseeing::~Sightseeing()
{
}

void Sightseeing::TourShow() const
{
    cout << " ";
    for (int i = 0; i < (ceil(38 - TourType().size())) / 2 - 1; i++)
    {
        cout << "~";
    }
    cout << " " << TourType() << " ";
    for (int i = 0; i < (floor(38 - TourType().size())) / 2; i++)
    {
        cout << "~";
    }
    cout << " >\n|\n";
    cout << "|   Name: " << name << endl;
    cout << "|   Address: " << address << endl;
    cout << "|   Sightseeing transport: " << sightseeingTransport << endl;
    cout << "|   Guide name: " << guide << endl;
    if (equipment.size() > 0) {
        cout << "|   To-take list:\n";
        for (int i = 0; i < equipment.size(); i++)
        {
            cout << "|     - " << equipment[i];
            if (i != equipment.size() - 1) {
                cout << ",\n";
            }
            else {
                cout << endl;
            }
        }
    }
    cout << "|   Description: " << description << endl;
    cout << "|   Date: " << date << endl;
    cout << "|   Time: ";
    time.showTime();
    cout << endl;
    cout << "|   Rating: " << rating << "/5\n";
    cout << "|   Price: " << price << " $\n";
    cout << "|   Price for " << TransportType[0] << ": " << priceTransportType1 << " $\n";
    cout << "|   Price for " << TransportType[1] << ": " << priceTransportType2 << " $\n";
    cout << "|   Price for " << TransportType[2] << ": " << priceTransportType3 << " $\n";
    cout << "|   Price for video shooting: " << photosPrice << " $\n";
    cout << "|   Amount of tourists: " << number << "/" << maxNumber << endl;
    cout << "|   Min number of tourists: " << minNumber << endl;

    cout << "|   Tour status: ";
    if (checkIsTourAvailable() == 1) {
        cout << "available\n";
    }
    else {
        cout << "not available,\n|   (less than the required number of people)\n";
    }
    cout << "|\n ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ <\n";
}

void Sightseeing::TourShowClients() const
{
    cout << " ";
    for (int i = 0; i < (ceil(38 - TourType().size())) / 2 - 1; i++)
    {
        cout << "~";
    }
    cout << " " << TourType() << " ";
    for (int i = 0; i < (floor(38 - TourType().size())) / 2; i++)
    {
        cout << "~";
    }
    cout << ">\n|\n";
    cout << "|   Name: " << name << endl;
    cout << "|   Address: " << address << endl;
    cout << "|   Sightseeing transport: " << sightseeingTransport << endl;
    cout << "|   Guide name: " << guide << endl;
    if (equipment.size() > 0) {
        cout << "|   To-take list:\n";
        for (int i = 0; i < equipment.size(); i++)
        {
            cout << "|   " << equipment[i];
            if (i != equipment.size() - 1) {
                cout << ",\n";
            }
            else {
                cout << endl;
            }
        }
    }
    cout << "|   Description: " << description << endl;
    cout << "|   Date: " << date << endl;
    cout << "|   Time: ";
    time.showTime();
    cout << endl;
    cout << "|   Rating: " << rating << "/5\n";
    cout << "|   Price: " << price << " $\n";
    cout << "|   Amount of tourists: " << number << "/" << maxNumber << endl;
    cout << "|   Min number of tourists: " << minNumber << endl;

    cout << "|   Video shooting: ";
    if (photos == 1) {
        cout << "included\n";
        cout << "|   Extra price for video shooting: " << photosPrice << " $\n";
    }
    else {
        cout << "not included\n";
    }

    cout << "|   Transport: ";
    if (arriveTransport > 0) {
        cout << TransportType[arriveTransport - 1] << " included\n";
        switch (arriveTransport)
        {
        case 1:
            cout << "|   Extra price for " << TransportType[arriveTransport - 1] << ": " << priceTransportType1 << " $\n";
            break;
        case 2:
            cout << "|   Extra price for " << TransportType[arriveTransport - 1] << ": " << priceTransportType2 << " $\n";
            break;
        case 3:
            cout << "|   Extra price for " << TransportType[arriveTransport - 1] << ": " << priceTransportType3 << " $\n";
            break;
        default:
            cout << "|   Input error!\n";
            break;
        }
    }
    else {
        cout << "not included\n";
    }

    cout << "|   Tour status: ";
    if (checkIsTourAvailable() == 1) {
        cout << "available\n";
    }
    else {
        cout << "not available\n|   (less than the required number of people)\n";
    }
    cout << "|\n ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ <\n";
}

void Sightseeing::TourEdit()
{
    int menu, intVar;
    float floatVar;
    string str;
    Date date;
    Time_ time;
    do {
        cout << "|   Choose what you want to edit:\n|\n";
        cout << "|   1. Name.\n";
        cout << "|   2. Address.\n";
        cout << "|   3. Sightseeing transport.\n";
        cout << "|   4. Equipment.\n";
        cout << "|   5. Description.\n";
        cout << "|   6. Date.\n";
        cout << "|   7. Time.\n";
        cout << "|   8. Rating.\n";
        cout << "|   9. Price.\n";
        cout << "|   10. Price for photos.\n";
        cout << "|   11. Price for " << TransportType[0] << ".\n";
        cout << "|   12. Price for " << TransportType[1] << ".\n";
        cout << "|   13. Price for " << TransportType[2] << ".\n";
        cout << "|   14. Guide.\n";
        cout << "|   15. Number of tourists.\n";
        cout << "|   16. Min number.\n";
        cout << "|   17. Max number.\n";
        cout << "|   18. Leave.\n";
        cout << "\nYour choice >> ";
        cin >> menu;
        cout << endl;
        switch (menu)
        {
        case 1:
            cout << "|   Enter new name: ";
            cin.ignore();
            getline(cin, str);
            setName(str);
            break;
        case 2:
            cout << "|   Enter new address: ";
            cin.ignore();
            getline(cin, str);
            setAddress(str);
            break;
        case 3:
            cout << "|   Enter new type of sightseeing transport: ";
            cin.ignore();
            getline(cin, str);
            setSightseeingTransport(str);
            break;
        case 4:
            cout << "|   Enter what you want to do with equipment list:\n|\n";
            cout << "|   1. Add new equipment.\n";
            cout << "|   2. Remove existing equipment.\n";
            cout << "|   3. Remove all equipment.\n\n";
            cout << "\nYour choice >> ";
            cin >> intVar;
            cout << endl;
            switch (intVar)
            {
            case 1:
                cout << "|\n";
                setEquipment();
                break;
            case 2:
                cout << "|   Enter name of equipment you want to remove: ";
                cin.ignore();
                getline(cin, str);
                delEquipment(str);
                break;
            case 3:
                delAllEquipment();
                break;
            default:
                cout << "|   Input error!\n";
                break;
            }
            break;
        case 5:
            cout << "|   Enter new description: ";
            cin.ignore();
            getline(cin, str);
            setAddress(str);
            break;
        case 6:
            cout << "|   Enter new date: ";
            cin >> date;
            setDate(date);
            break;
        case 7:
            cout << "|   Enter new time: ";
            cin >> time;
            setTime(time);
            break;
        case 8:
            cout << "|   Enter new rating: ";
            cin >> floatVar;
            setRating(floatVar);
            break;
        case 9:
            cout << "|   Enter new price: ";
            cin >> floatVar;
            setPrice(floatVar);
            break;
        case 10:
            cout << "|   Enter new price for photos: ";
            cin >> floatVar;
            setPhotosPrice(floatVar);
            break;
        case 11:
            cout << "|   Enter new price for " << TransportType[0] << ": ";
            cin >> floatVar;
            setPriceTransportType1(floatVar);
            break;
        case 12:
            cout << "|   Enter new price for " << TransportType[1] << ": ";
            cin >> floatVar;
            setPriceTransportType2(floatVar);
            break;
        case 13:
            cout << "|   Enter new price for " << TransportType[2] << ": ";
            cin >> floatVar;
            setPriceTransportType3(floatVar);
            break;
        case 14:
            cout << "|   Enter new guide name: ";
            cin.ignore();
            getline(cin, str);
            setGuide(str);
            break;
        case 15:
            cout << "|   Enter new number of tourists: ";
            cin >> intVar;
            setNumber(intVar);
            break;
        case 16:
            cout << "|   Enter new min number of tourists: ";
            cin >> intVar;
            setMinNumber(intVar);
            break;
        case 17:
            cout << "|   Enter new max number of tourists: ";
            cin >> intVar;
            setMaxNumber(intVar);
            break;
        case 18:
            break;
        default:
            cout << "|   Input error!\n";
        }
    } while (menu != 18);
}

void Sightseeing::setSightseeingTransport(string _sightseeingTransport)
{
    if (_sightseeingTransport.size() > 2) {
        sightseeingTransport = _sightseeingTransport;
    }
    else {
        throw new TourInputErrorException(1);
    }
}

string Sightseeing::getSightseeingTransport() const
{
    return sightseeingTransport;
}

void Sightseeing::saveToFile(ofstream& file) const
{
    Tour::saveToFile(file);
    string str = "\n";
    file.write(str.c_str(), str.size());
    file.write(sightseeingTransport.c_str(), sightseeingTransport.size());
}

void Sightseeing::loadFromFile(ifstream& file)
{
    Tour::loadFromFile(file);
    string str;
    getline(file, str); 
    setSightseeingTransport(str);
}