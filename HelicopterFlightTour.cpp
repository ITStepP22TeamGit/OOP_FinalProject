#include "HelicopterFlightTour.h"

HelicopterFlightTour::HelicopterFlightTour()
{
    activity = 0;
    priceFlight = 0;
    priceSkydiving = 0;
}

HelicopterFlightTour::HelicopterFlightTour(string _name, string _address, string _description, Date _date, Time_ _time, float _rating, float _price, float _photosPrice, string _guide, int _number, int _minNumber, int _maxNumber, float _priceFlight, float _priceSkydiving)
    :Tour(_name, _address, _description, _date, _time, _rating, _price,
        _photosPrice, _guide, _number, _minNumber, _maxNumber)
{
    setPriceFlight(_priceFlight);
    setPriceSkydiving(-_priceSkydiving);
    activity = 1;
    price += priceFlight;
}

HelicopterFlightTour::HelicopterFlightTour(bool a)
{
    string str;
    int intVar, intVar1, intVar2;
    float floatVar;
    Date date1;
    Time_ time1;
    cout << "|   Enter name: ";
    cin.ignore();
    getline(cin, str);
    setName(str);
    cout << "|   Enter address: ";
    getline(cin, str);
    setAddress(str);
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
    setDescription(str);
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
    cout << "|   Enter price for flight: ";
    cin >> floatVar;
    setPriceFlight(floatVar);
    cout << "|   Enter price for skydiving: ";
    cin >> floatVar;
    setPriceSkydiving(floatVar);
    cout << "|   Enter number of tourists: ";
    cin >> intVar;
    cout << "|   Enter min number of tourists: ";
    cin >> intVar1;
    cout << "|   Enter max number of tourists: ";
    cin >> intVar2;
    setNumbers(intVar, intVar1, intVar2);
    activity = 1;
    price += priceFlight;
}

HelicopterFlightTour::~HelicopterFlightTour()
{
}

string HelicopterFlightTour::TourType() const
{
    return "HelicopterFlightTour";
}

void HelicopterFlightTour::TourEdit()
{
    int menu, intVar;
    float floatVar;
    string str;
    Date date;
    Time_ time;
    bool boolVar;
    do {
        cout << "|   Choose what you want to edit:\n|\n";
        cout << "|   1. Name.\n";
        cout << "|   2. Address.\n";
        cout << "|   3. Equipment.\n";
        cout << "|   4. Description.\n";
        cout << "|   5. Date.\n";
        cout << "|   6. Time.\n";
        cout << "|   7. Rating.\n";
        cout << "|   8. Price.\n";
        cout << "|   9. Price for photos.\n";
        cout << "|   10. Price for " << TransportType[0] << ".\n";
        cout << "|   11. Price for " << TransportType[1] << ".\n";
        cout << "|   12. Price for " << TransportType[2] << ".\n";
        cout << "|   13. Type of activity.\n";
        cout << "|   14. Price for flight.\n";
        cout << "|   15. Price for skydiving.\n";
        cout << "|   16. Guide.\n";
        cout << "|   17. Number of tourists.\n";
        cout << "|   18. Min number.\n";
        cout << "|   19. Max number.\n";
        cout << "|   20. Leave.\n";
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
        case 4:
            cout << "|   Enter new description: ";
            cin.ignore();
            getline(cin, str);
            setAddress(str);
            break;
        case 5:
            cout << "|   Enter new date: ";
            cin >> date;
            setDate(date);
            break;
        case 6:
            cout << "|   Enter new time: ";
            cin >> time;
            setTime(time);
            break;
        case 7:
            cout << "|   Enter new rating: ";
            cin >> floatVar;
            setRating(floatVar);
            break;
        case 8:
            cout << "|   Enter new price: ";
            cin >> floatVar;
            setPrice(floatVar);
            break;
        case 9:
            cout << "|   Enter new price for photos: ";
            cin >> floatVar;
            setPhotosPrice(floatVar);
            break;
        case 10:
            cout << "|   Enter new price for " << TransportType[0] << ": ";
            cin >> floatVar;
            setPriceTransportType1(floatVar);
            break;
        case 11:
            cout << "|   Enter new price for " << TransportType[1] << ": ";
            cin >> floatVar;
            setPriceTransportType2(floatVar);
            break;
        case 12:
            cout << "|   Enter new price for " << TransportType[2] << ": ";
            cin >> floatVar;
            setPriceTransportType3(floatVar);
            break;
        case 13:
            cout << "|   Enter type of activity (1 - flight, 0 - skydiving): ";
            cin >> boolVar;
            setActivity(boolVar);
            break;
        case 14:
            cout << "|   Enter new price for flight: ";
            cin >> floatVar;
            setPriceFlight(floatVar);
            break;
        case 15:
            cout << "|   Enter new price for skydiving: ";
            cin >> floatVar;
            setPriceSkydiving(floatVar);
            break;
        case 16:
            cout << "|   Enter new guide name: ";
            cin.ignore();
            getline(cin, str);
            setGuide(str);
            break;
        case 17:
            cout << "|   Enter new number of tourists: ";
            cin >> intVar;
            setNumber(intVar);
            break;
        case 18:
            cout << "|   Enter new min number of tourists: ";
            cin >> intVar;
            setMinNumber(intVar);
            break;
        case 19:
            cout << "|   Enter new max number of tourists: ";
            cin >> intVar;
            setMaxNumber(intVar);
            break;
        case 20:
            break;
        default:
            cout << "|   Input error!\n";
        }
    } while (menu != 20);
}

void HelicopterFlightTour::setActivity(bool _activity)
{
    if (activity == 1 && _activity == 1 || activity == 0 && _activity == 0) {
        activity = _activity;
    }
    else if (activity == 1 && _activity == 0) {
        price -= priceFlight;
        price += priceSkydiving;
    }
    else {
        price -= priceSkydiving;
        price += priceFlight;
    }
}

void HelicopterFlightTour::setPriceFlight(float _priceFlight)
{
    if (_priceFlight > price) {
        throw new TourInputPriceServiceException(price);
    }
    if (_priceFlight < 0) {
        throw new TourInputErrorException(2);
    }
    else {
        priceFlight = _priceFlight;
    }
}

void HelicopterFlightTour::setPriceSkydiving(float _priceSkydiving)
{
    if (_priceSkydiving > price) {
        throw new TourInputPriceServiceException(price);
    }
    if (_priceSkydiving < 0) {
        throw new TourInputErrorException(2);
    }
    else {
        priceSkydiving = _priceSkydiving;
    }
}

bool HelicopterFlightTour::getActivity() const
{
    return activity;
}

float HelicopterFlightTour::getPriceFlight() const
{
    return priceFlight;
}

float HelicopterFlightTour::getPriceSkydiving() const
{
    return priceSkydiving;
}

void HelicopterFlightTour::TourShow() const
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
    cout << "|   Price for flight: " << priceFlight << " $\n";
    cout << "|   Price for skydiving: " << priceSkydiving << " $\n";
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

void HelicopterFlightTour::TourShowClients() const
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

    cout << "|   Type of activity: ";
    if (activity == 1) {
        cout << "helicopter flight\n";
        cout << "|   Extra price for flight: " << priceFlight << " $\n";
    }
    else {
        cout << "skydiving\n";
        cout << "|   Extra price for skydiving: " << priceSkydiving << " $\n";
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

void HelicopterFlightTour::askClient()
{
    cout << "|   Do you want to include video shooting?\n";
    cout << "|   Price for video shooting: " << photosPrice << " $\n\n";
    string str;
    do {
        cout << "Your choice (yes/no) >> ";
        cin >> str;
        cout << endl;
    } while (str != "yes" && str != "no" && str != "Yes" && str != "No");
    if (str == "yes" || str == "Yes") {
        photos = 1;
        price += photosPrice;
    }
    else {
        photos = 0;
    }

    cout << "|   Do you want transport to pick you up?\n\n";
    do {
        cout << "Your choice (yes/no) >> ";
        cin >> str;
        cout << endl;
    } while (str != "yes" && str != "no" && str != "Yes" && str != "No");
    if (str == "yes" || str == "Yes") {
        cout << "|   Choose type of transport:\n";
        for (int i = 0; i < 3; i++)
        {
            cout << "|   " << i + 1 << ". " << TransportType[i] << endl;
            if (i == 0) {
                cout << "|   " << priceTransportType1 << endl;
            }
            else if (i == 1) {
                cout << "|   " << priceTransportType2 << endl;
            }
            else {
                cout << "|   " << priceTransportType3 << endl;
            }
        }
        do {
            cout << "\nYour choice >> ";
            cin >> arriveTransport;
            cout << endl;
        } while (arriveTransport != 1 && arriveTransport != 2 && arriveTransport != 3);
        switch (arriveTransport)
        {
        case 1:
            price += priceTransportType1;
            break;
        case 2:
            price += priceTransportType2;
            break;
        case 3:
            price += priceTransportType3;
            break;
        default:
            cout << "|   Input error!\n";
            break;
        }
    }
    else {
        arriveTransport = 0;
    }

    int a, b;

    cout << "|   Choose type of activity.\n";
    cout << "|   Price for video flight: " << priceFlight << " $\n";
    cout << "|   Price for video skydiving: " << priceSkydiving << " $\n\n";
    do {
        cout << "Your choice (1 - helicopter flight, 2 - skydiving) >> ";
        cin >> a;
        cout << endl;
    } while (a != 1 && a != 0);
    setActivity(a);

    b = number;
    do {
        cout << "|   Amount of people: ";
        cin >> a;
        setNumber(a + number);
    } while (number == b);
    price *= a;
}

void HelicopterFlightTour::saveToFile(ofstream& file) const
{
    Tour::saveToFile(file);
    string str = "\n";
    file.write(str.c_str(), str.size());
    file << activity << endl;
    file << priceFlight << endl;
    str = to_string(priceSkydiving);
    file.write(str.c_str(), str.size());
}

void HelicopterFlightTour::loadFromFile(ifstream& file)
{
    float f;
    bool b;
    Tour::loadFromFile(file);
    file >> b;
    setActivity(b);
    file >> f;
    setPriceFlight(f);
    file >> f;
    setPriceSkydiving(f);
    file.get();
}
