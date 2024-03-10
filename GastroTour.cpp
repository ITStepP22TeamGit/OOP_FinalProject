#include "GastroTour.h"

GastroTour::GastroTour()
{
	
}

GastroTour::GastroTour(string _name, string _address, string _description, Date _date, Time_ _time, float _rating, float _price, float _photosPrice, string _guide, int _number, int _minNumber, int _maxNumber)
    :Tour(_name, _address, _description, _date, _time, _rating, _price,
        _photosPrice, _guide, _number, _minNumber, _maxNumber)
{
}

GastroTour::GastroTour(bool a, Map& map)
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
    cout << "|   Enter number of tourists: ";
    cin >> intVar;
    cout << "|   Enter min number of tourists: ";
    cin >> intVar1;
    cout << "|   Enter max number of tourists: ";
    cin >> intVar2;
    setNumbers(intVar, intVar1, intVar2);
    arr.addFoodService(map);
}

GastroTour::~GastroTour()
{
}

void GastroTour::setRestaurantCounter(int _restaurantCounter)
{
    if (_restaurantCounter < 0) {
        throw new TourInputErrorException(3);
    }
    if (_restaurantCounter > 4) {
        throw new TourInputErrorException(12);
    }
    restaurantCounter = _restaurantCounter;
}

int GastroTour::getRestaurantCounter() const
{
    return restaurantCounter;
}

void GastroTour::TourEdit()
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
        cout << "|   13. Guide.\n";
        cout << "|   14. Number of tourists.\n";
        cout << "|   15. Min number.\n";
        cout << "|   16. Max number.\n";
        cout << "|   17. Food services.\n";
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
            cout << "|   Enter new guide name: ";
            cin.ignore();
            getline(cin, str);
            setGuide(str);
            break;
        case 14:
            cout << "|   Enter new number of tourists: ";
            cin >> intVar;
            setNumber(intVar);
            break;
        case 15:
            cout << "|   Enter new min number of tourists: ";
            cin >> intVar;
            setMinNumber(intVar);
            break;
        case 16:
            cout << "|   Enter new max number of tourists: ";
            cin >> intVar;
            setMaxNumber(intVar);
            break;
        case 17:
            arr.editForTour();
            break;
        case 18:
            break;
        default:
            cout << "|   Input error!\n";
        }
    } while (menu != 18);
}

void GastroTour::TourShow() const
{
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
    /*cout << "|   Restaurants names and addresses:\n";
    for (int i = 0; i < foodServices.size(); i++)
    {
        cout << "|     - " << foodServices[i]->getName() << endl;
        cout << "|     - " << foodServices[i]->getAdress();
        if (i != foodServices.size() - 1) {
            cout << ";\n";
        }
        else {
            cout << endl;
        }
    }*/
    /*double totalRating = 0.0;
    for (auto food : foodServices) {
        totalRating += food->getRating();
    }
    int averageRating = totalRating / foodServices.size();
    cout << "|   Restaurants:\n";
    cout << "|   Average rating: " << averageRating << endl;
    cout << "|   All " << foodServices.size() << " establishments: " << endl;
    for (int i = 0; i < foodServices.size(); i++) {
        if (foodServices[i]->type() == "CAFE") {
            cout << "--------------- " << "#" << i + 1 << " " << foodServices[i]->type() << " ---------------->" << endl;
        }
        else if (foodServices[i]->type() == "CANTEEN") {
            cout << "-------------- " << "#" << i + 1 << " " << foodServices[i]->type() << " -------------->" << endl;
        }
        else if (foodServices[i]->type() == "RESTARAUNT") {
            cout << "------------- " << "#" << i + 1 << " " << foodServices[i]->type() << " ------------>" << endl;
        }
        foodServices[i]->showFoodService();
    }*/
    arr.showFoodServices(1);
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
}

void GastroTour::TourShowClients() const
{
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
   /* double totalRating = 0.0;
    for (auto food : foodServices) {
        totalRating += food->getRating();
    }
    int averageRating = totalRating / foodServices.size();
    cout << "|   Restaurants:\n";
    cout << "|   Average rating: " << averageRating << endl;
    cout << "|   All " << foodServices.size() << " establishments: " << endl;
    for (int i = 0; i < foodServices.size(); i++) {
        if (foodServices[i]->type() == "CAFE") {
            cout << "--------------- " << "#" << i + 1 << " " << foodServices[i]->type() << " ---------------->" << endl;
        }
        else if (foodServices[i]->type() == "CANTEEN") {
            cout << "-------------- " << "#" << i + 1 << " " << foodServices[i]->type() << " -------------->" << endl;
        }
        else if (foodServices[i]->type() == "RESTARAUNT") {
            cout << "------------- " << "#" << i + 1 << " " << foodServices[i]->type() << " ------------>" << endl;
        }
        foodServices[i]->showFoodService();
    }*/
    arr.showFoodServices(1);
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
}

void GastroTour::askClient()
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
        setPhotos(1);
        cout << "Video shooting service was successfully added!\n\n";
    }
    else {
        setPhotos(0);
    }

    cout << "|   Do you want transport to pick you up?\n\n";
    do {
        cout << "Your choice (yes/no) >> ";
        cin >> str;
        cout << endl;
    } while (str != "yes" && str != "no" && str != "Yes" && str != "No");
    if (str == "yes" || str == "Yes") {
        cout << "|   Choose type of transport:\n|\n";
        for (int i = 0; i < 3; i++)
        {
            str = TransportType[i];
            str[0] = toupper(str[0]);
            cout << "|   " << i + 1 << ". " << str << ". Price: ";
            if (i == 0) {
                cout << priceTransportType1 << " $\n";
            }
            else if (i == 1) {
                cout << priceTransportType2 << " $\n";
            }
            else {
                cout << priceTransportType3 << " $\n";
            }
        }
        int intVar;
        do {
            cout << "\nYour choice >> ";
            cin >> intVar;
            cout << endl;
        } while (intVar != 1 && intVar != 2 && intVar != 3);
        setArriveTransport(intVar);
        switch (arriveTransport)
        {
        case 1:
            str = TransportType[0];
            str[0] = toupper(str[0]);
            cout << "|   " << str << " ride was successfully added!\n\n";
            break;
        case 2:
            str = TransportType[1];
            str[0] = toupper(str[0]);
            cout << "|   " << str << " ride was successfully added!\n\n";
            break;
        case 3:
            str = TransportType[2];
            str[0] = toupper(str[0]);
            cout << "|   " << str << " ride was successfully added!\n\n";
            break;
        default:
            cout << "|   Input error!\n";
            break;
        }
    }
    else {
        setArriveTransport(0);
    }

    int a, b;
    b = number;
    do {
        cout << "|   Amount of people: ";
        cin >> a;
        setNumber(a + number);
    } while (number == b);
    price *= a;
    /*for (int i = 0; i < foodServices.size(); i++)
    {
        price+= foodServices[i]
    }*/
}

void GastroTour::saveToFile(ofstream& file) const
{
    file << TourType() << endl;
    file << name << endl;
    file << address << endl;
    file << guide << endl;
    file << equipment.size() << endl;
    for (int i = 0; i < equipment.size(); i++)
    {
        file << equipment[i] << endl;
    }
    file << description << endl;
    file << date.getDay() << " " << date.getMonth() << " " << date.getYear() << endl;
    file << time.getHour() << " " << time.getMinutes() << " " << time.getSeconds() << endl;
    file << rating << endl;
    file << price << endl;
    file << photos << endl;
    file << photosPrice << endl;
    file << arriveTransport << endl;
    file << priceTransportType1 << endl;
    file << priceTransportType2 << endl;
    file << priceTransportType3 << endl;
    file << number << endl;
    file << minNumber << endl;
    /*string str = to_string(maxNumber);
    file.write(str.c_str(), str.size());*/
    file << maxNumber << endl;
    arr.saveFoodServicesToFile(file);
    /*file << foodServices.size();
    file << "\n";
    for (int i = 0; i < foodServices.size(); i++) {
        if (foodServices[i]->type() == "CAFE") {
            file << 1;
            file << "\n";
            foodServices[i]->saveToFile(file);
        }
        else if (foodServices[i]->type() == "CANTEEN") {
            file << 2;
            file << "\n";
            foodServices[i]->saveToFile(file);
        }
        else if (foodServices[i]->type() == "RESTARAUNT") {
            file << 3;
            file << "\n";
            foodServices[i]->saveToFile(file);
        }
    }*/
}

void GastroTour::loadFromFile(ifstream& file)
{
    string s1;
    int i1, i2, i3;
    float fl1;
    bool b1;
    getline(file, s1);
    setName(s1);
    getline(file, s1);
    setAddress(s1);
    getline(file, s1);
    setGuide(s1);
    file >> i1;
    for (int i = 0; i < i1; i++)
    {
        if (i == 0) {
            getline(file, s1);
        }
        getline(file, s1);
        equipment.push_back(s1);
    }
    getline(file, s1);
    setDescription(s1);
    file >> i1;
    file >> i2;
    file >> i3;
    setDate(Date(i1, i2, i3));
    file >> i1;
    file >> i2;
    file >> i3;
    setTime(Time_(i1, i2, i3));
    file >> fl1;
    setRating(fl1);
    file >> fl1;
    setPrice(fl1);
    file >> b1;
    setPhotos(b1);
    file >> fl1;
    setPhotosPrice(fl1);
    file >> i1;
    setArriveTransport(i1);
    file >> fl1;
    setPriceTransportType1(fl1);
    file >> fl1;
    setPriceTransportType2(fl1);
    file >> fl1;
    setPriceTransportType3(fl1);
    file >> i1;
    file >> i2;
    file >> i3;
    setNumbers(i1, i2, i3);
    //int typeN, sizeN;
    //file >> sizeN;
    ////cout << sizeN << endl;
    //for (int i = 0; i < sizeN; i++) {
    //    file >> typeN;
    //    if (typeN == 1) {
    //        //foodServices.push_back(new Cafe);
    //        Cafe* nCafe = new Cafe;
    //        nCafe->loadFromFile(file);
    //        //foodServices[i]->loadFromFile(file);
    //        foodServices.push_back(nCafe);
    //    }
    //    else if (typeN == 2) {
    //        Canteen* nCanteen = new Canteen;
    //        nCanteen->loadFromFile(file);
    //        foodServices.push_back(nCanteen);
    //    }
    //    else if (typeN == 3) {
    //        Restaraunt* nRest = new Restaraunt;
    //        nRest->loadFromFile(file);
    //        foodServices.push_back(nRest);
    //    }
    //}
    arr.loadFoodServicesFromFile(file);
    file.get();
}

string GastroTour::TourType() const
{
	return "GastroTour";
}