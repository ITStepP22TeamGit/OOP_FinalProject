#include "Tour.h"

Tour::Tour()
{
    name = "Undefined";
    address = "Undefined";
    description = "Undefined";
    date = Date(1, 1, 1);
    time = Time_(0, 0, 0);
    rating = 0;
    amountOfRatings = 1;
    price = 0;
    photos = 0;
    guide = "Undefined";
    number = 0;
    minNumber = 0;
    maxNumber = 0;
    photos = 0;
    photosPrice = 0;
}

Tour::Tour(string _name, string _address, string _description, Date _date, Time_ _time, float _rating, float _price, float _photosPrice, string _guide, int _number, int _minNumber, int _maxNumber)
{
    setName(_name);
    setAddress(_address);
    setDescription(_description);
    setDate(_date);
    setTime(_time);
    setRating(_rating);
    amountOfRatings = 1;
    setPrice(_price);
    setPhotosPrice(_photosPrice);
    setGuide(_guide);
    setNumbers(_number, _minNumber, _maxNumber);
    photos = 0;
    arriveTransport = 0;
    equipment.push_back("good mood");
}

Tour::~Tour()
{
    
}

void Tour::setName(string _name)
{
    if (_name.size() > 3) {
        name = _name;
    }
    else {
        throw new TourInputErrorException(1);
    }
}

void Tour::setAddress(string _address)
{
    if (_address.size() > 3) {
        address = _address;
    }
    else {
        throw new TourInputErrorException(1);
    }
}

void Tour::setEquipment()
{
    int numb;
    string str;
    cout << "|   Enter how much equipment you want to add: ";
    cin >> numb;
    if (numb < 1) {
        throw new TourInputErrorException(3);
    }
    cout << "|\n";
    for (int i = 0; i < numb; i++)
    {
        cout << "|   Enter name of equipment: ";
        cin.ignore();
        getline(cin, str);
        if (str.size() <= 3) {
            throw new TourInputErrorException(1);
        }
        equipment.push_back(str);
    }
}

void Tour::setDescription(string _description)
{
    if (_description.size() > 3) {
        description = _description;
    }
    else {
        throw new TourInputErrorException(1);
    }
}

void Tour::setDate(Date _date)
{
    if (_date > Date()) {
        date = _date;
    }
    else {
        throw new TourInputDateException();
    }
}

void Tour::setTime(Time_ _time)
{
    time = _time;
}

void Tour::setRating(float _rating)
{
    if (_rating > 1) {
        rating = _rating;
    }
    else {
        throw new TourInputErrorException(2);
    }
}

void Tour::setPrice(float _price)
{
    if (_price > 1) {
        price = _price;
    }
    else {
        throw new TourInputErrorException(2);
    }
}

void Tour::setPhotos(bool _photos)
{
    if (photos == 1 && _photos == 1 || photos == 0 && _photos == 0) {
        photos = _photos;
    }
    else if (photos == 1 && _photos == 0) {
        price -= photosPrice;
    }
    else {
        price += photosPrice;
    }
}

void Tour::setPhotosPrice(float _photosPrice)
{
    if (_photosPrice > price) {
        throw new TourInputPriceServiceException(price);
    }
    if (_photosPrice < 0) {
        throw new TourInputErrorException(2);
    }
    else {
        photosPrice = _photosPrice;
    }
}

void Tour::setPriceTransportType1(float _priceTransportType1)
{
    if (_priceTransportType1 > price) {
        throw new TourInputPriceServiceException(price);
    }
    if (_priceTransportType1 < 0) {
        throw new TourInputErrorException(2);
    }
    else {
        priceTransportType1 = _priceTransportType1;
    }
}

void Tour::setPriceTransportType2(float _priceTransportType2)
{
    if (_priceTransportType2 > price) {
        throw new TourInputPriceServiceException(price);
    }
    if (_priceTransportType2 < 0) {
        throw new TourInputErrorException(2);
    }
    else {
        priceTransportType2 = _priceTransportType2;
    }
}

void Tour::setPriceTransportType3(float _priceTransportType3)
{
    if (_priceTransportType3 > price) {
        throw new TourInputPriceServiceException(price);
    }
    if (_priceTransportType3 < 0) {
        throw new TourInputErrorException(2);
    }
    else {
        priceTransportType3 = _priceTransportType3;
    }
}

void Tour::setGuide(string _guide)
{
    if (_guide.size() > 3) {
        guide = _guide;
    }
    else {
        throw new TourInputErrorException(1);
    }
}

void Tour::setNumber(int _number)
{
    if (_number > maxNumber) {
        throw new TourInputNumberException(1, maxNumber);
    }
    else if (_number < 0) {
        throw new TourInputErrorException(3);
    }
    else {
        number = _number;
    }
}

void Tour::setMinNumber(int _minNumber)
{
    if (_minNumber > maxNumber) {
        throw new TourInputNumberException(2, maxNumber);
    }
    else if (_minNumber < 0) {
        throw new TourInputErrorException(3);
    }
    else {
        minNumber = _minNumber;
    }
}

void Tour::setMaxNumber(int _maxNumber)
{
    if (number > _maxNumber) {
        throw new TourInputNumberException(3, number);
    }
    else if (minNumber > _maxNumber) {
        throw new TourInputNumberException(4, minNumber);
    }
    else if (_maxNumber < 0) {
        throw new TourInputErrorException(3);
    }
    else {
        maxNumber = _maxNumber;
    }
}

void Tour::setNumbers(int _number, int _minNumber, int _maxNumber)
{
    if (_number > _maxNumber) {
        throw new TourInputErrorException(4);
    }
    else if (_number < 0) {
        throw new TourInputErrorException(3);
    }
    if (_minNumber > _maxNumber) {
        throw new TourInputErrorException(5);
    }
    else if (_minNumber < 0) {
        throw new TourInputErrorException(3);
    }
    else if (_maxNumber < 0) {
        throw new TourInputErrorException(3);
    }
    else {
        number = _number;
        minNumber = _minNumber;
        maxNumber = _maxNumber;
    }
}

void Tour::setArriveTransport(int _arriveTransport)
{
    if (_arriveTransport < 0){
        throw new TourInputErrorException(3);
    }
    if (_arriveTransport > 3) {
        throw new TourInputErrorException(15);
    }
    else {
        arriveTransport = _arriveTransport;
    }
}

string Tour::getName() const
{
    return name;
}

string Tour::getAddress() const
{
    return address;
}

bool Tour::checkEquipment(string _equipment) const
{
    for (int i = 0; i < equipment.size(); i++)
    {
        if (equipment[i] == _equipment) {
            return 1;
        }
    }
    return 0;
}

string Tour::getDescription() const
{
    return description;
}

Date Tour::getDate() const
{
    return date;
}

Time_ Tour::getTime() const
{
    return time;
}

float Tour::getRating() const
{
    return rating;
}

float Tour::getPrice() const
{
    return price;
}

bool Tour::getPhotos() const
{
    return photos;
}

float Tour::getPhotosPrice() const
{
    return photosPrice;
}

float Tour::getPriceTransportType1() const
{
    return priceTransportType1;
}

float Tour::getPriceTransportType2() const
{
    return priceTransportType2;
}

float Tour::getPriceTransportType3() const
{
    return priceTransportType3;
}

string Tour::getGuide() const
{
    return guide;
}

int Tour::getNumber() const
{
    return number;
}

int Tour::getMinNumber() const
{
    return minNumber;
}

int Tour::getMaxNumber() const
{
    return maxNumber;
}

int Tour::getArriveTransport() const
{
    return arriveTransport;
}

void Tour::delEquipment(string _name)
{
    if (equipment.empty()) {
        throw new TourInputErrorException(16);
    }
    if (_name.size() <= 3) {
        throw new TourInputErrorException(1);
    }
    bool check = 0;
    for (int i = 0; i < equipment.size(); i++)
    {
        if (equipment[i] == _name) {
            equipment.erase(equipment.begin() + i);
            check = 1;
        }
    }
    if (check == 0) {
        throw new TourInputErrorException(17);
    }
}

void Tour::delAllEquipment()
{
    if (equipment.empty()) {
        throw new TourInputErrorException(16);
    }
    for (int i = equipment.size() - 1; i >= 0; i--)
    {
        equipment.erase(equipment.begin() + i);
    }
}

void Tour::addClientsRating(int _rating)
{
    if (_rating < 1) {
        throw new TourInputErrorException(2);
    }
    if (_rating > 5) {
        throw new TourInputErrorException(18);
    }
    rating = (rating * amountOfRatings + _rating);
    amountOfRatings++;
    rating = rating / amountOfRatings;
}

void Tour::TourShow() const
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
            cout <<"|     - " << equipment[i];
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

void Tour::TourShowClients() const
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

    cout << "|   Tour status: ";
    if (checkIsTourAvailable() == 1) {
        cout << "available\n";
    }
    else {
        cout << "not available\n|   (less than the required number of people)\n";
    }
    cout << "|\n ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ <\n";
}

void Tour::TourEdit()
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
        cout << "|   17. Leave.\n";
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
            break;
        default:
            cout << "|   Input error!\n";
        }
    } while (menu != 17);
}

bool Tour::checkIsTourAvailable() const
{
    return number > minNumber;
}

bool Tour::operator>(const Tour& obj) const&
{
    return this->date > obj.date;
}

bool Tour::operator<(const Tour& obj) const&
{
    return this->date < obj.date;
}

void Tour::saveToFile(ofstream& file) const
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
    string str = to_string(maxNumber);
    file.write(str.c_str(), str.size());
}

void Tour::loadFromFile(ifstream& file)
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
    file.get();
}

void Tour::askClient()
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
    b = number;
    do {
        cout << "|   Amount of people: ";
        cin >> a;
        setNumber(a + number);
    } while (number == b);
    price *= a;
}