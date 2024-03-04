#include "Cafe.h"

Cafe::Cafe()
{
    freeWifi = false;
    musicGenre = "Jazz";
    boardGames = false;
    petFriendly = true;
}

Cafe::Cafe(string _name, string _adress, int _rating, int _x, int _y, Time_ _openingTime, Time_ _closingTime, bool _freeWifi,
    string _musicGenre, bool _boardGames, bool _petFr)
    :Food(_name, _adress, _rating, _x, _y, _openingTime, _closingTime)
{
    setFreeWifi(_freeWifi);
    setMusicGenre(_musicGenre);
    setBoardGames(_boardGames);
    setPetFriendly(_petFr);
}

void Cafe::setFreeWifi(bool _freeWifi)
{
    freeWifi = _freeWifi;
}

bool Cafe::getFreeWifi() const
{
    return freeWifi;
}

void Cafe::setMusicGenre(string _musicGenre)
{
    if (_musicGenre.empty()) {
        throw new FoodMusicGenreException();
    }
    musicGenre = _musicGenre;
}

string Cafe::getMusicGenre() const
{
    return musicGenre;
}

void Cafe::setBoardGames(bool _boardGames)
{
    boardGames = _boardGames;
}

bool Cafe::getBoardGames() const
{
    return boardGames;
}

void Cafe::setPetFriendly(bool _petFr)
{
    petFriendly = _petFr;
}

bool Cafe::getPetFriendly() const
{
    return petFriendly;
}

void Cafe::showFoodService() const
{
    cout << "----------------- " << type() << " ----------------->" << endl;
    cout << "|   Name: " << name << endl;
    cout << "|   Rating: " << rating << " / 10" << endl;
    if (freeWifi) cout << "|   Free Wi-Fi" << endl;
    else cout << "|   No Wi-Fi" << endl;
    cout << "|   Music genre: " << musicGenre << endl;
    if (boardGames) cout << "|   Board games are available" << endl;
    if (petFriendly) cout << "|   A pet-frendly place" << endl;
    else cout << "|   The place isn't pet-frendly" << endl;
    if (menu.size() > 0) {
        cout << "|==>Menu:" << endl;
        for (auto i : menu) {
            cout << "|   \t";
            i->showDish();
        }
    }
    else {
        cout << "|==>Menu is empty" << endl;
    }
    cout << "|   Adress: " << adress << endl;
    cout << "|   Working time: " << openingTime.getHour() / 10 << openingTime.getHour() % 10
        << ":" << openingTime.getMinutes() / 10 << openingTime.getMinutes() % 10;
    cout << " - " << closingTime.getHour() / 10 << closingTime.getHour() % 10
        << ":" << closingTime.getMinutes() / 10 << closingTime.getMinutes() % 10 << endl;
    cout << "----------------------------------------<" << endl;
}

string Cafe::type() const
{
    return "CAFE";
}

void Cafe::edit(Map& map)
{
    int tmpInt, tmpN, tmpK, tmpCMD;
    float tmpFloat;
    bool tmpBool;
    string tmpStr;
    do {
        system("cls");
        cout << "Select what you want to edit: " << endl;
        cout << "1. Name\n2. Rating\n3. Adress\n4. Coordinates\n5. Opening time\n6. Closing time" << endl;
        cout << "7. Wifi availability\n8. Music genre\n9. Availability of board games\n10. Pet friendly\n";
        cout << "11. Menu" << endl;
        cout << "0. Exit" << endl;
        cout << "Your choice: ";
        cin >> tmpInt;
        int tmpX = getX();
        int tmpY = getY();
        switch (tmpInt)
        {
        case 1:
            system("cls");
            cin.ignore();
            cout << "Enter new name: ";
            getline(cin, tmpStr);
            setName(tmpStr);
            map.delPoint(getX(), getY(), 0);
            map.addPoint(getX(), getY(), getName(), 0);
            cout << "Name was succesfully changed!" << endl;
            system("pause");
            break;
        case 2:
            system("cls");
            cout << "Enter new rating: ";
            cin >> tmpN;
            setRating(tmpN);
            cout << "Rating was succesfully changed!" << endl;
            system("pause");
            break;
        case 3:
            system("cls");
            cin.ignore();
            cout << "Enter new adress: ";
            getline(cin, tmpStr);
            setAdress(tmpStr);
            cout << "Adress was succesfully changed!" << endl;
            system("pause");
            break;
        case 4:
            system("cls");
            cout << "Enter new coordinates (x y): ";
            cin >> tmpN >> tmpK;
            changeCoordinates(tmpN, tmpK);
            map.delPoint(tmpX, tmpY, 0);
            map.addPoint(getX(), getY(), getName(), 0);
            cout << "Coordinates were succesfully changed!" << endl;
            system("pause");
            break;
        case 5:
            system("cls");
            cout << "Enter new opening time (HH MM): ";
            cin >> tmpN >> tmpK;
            if (tmpN > 23 || tmpN < 0 || tmpK > 59 || tmpK < 0) {
                throw new FoodTimeInvalidException();
            }
            setOpeningTime(Time_(tmpN, tmpK, 0, 1));
            cout << "Opening time was succesfully changed!" << endl;
            system("pause");
            break;
        case 6:
            system("cls");
            cout << "Enter new closing time (HH MM): ";
            cin >> tmpN >> tmpK;
            if (tmpN > 23 || tmpN < 0 || tmpK > 59 || tmpK < 0) {
                throw new FoodTimeInvalidException();
            }
            setClosingTime(Time_(tmpN, tmpK, 0, 1));
            cout << "Closing time was succesfully changed!" << endl;
            system("pause");
            break;
        case 7:
            system("cls");
            cout << "Set the availability of free wifi (1 - yes/0 - no): " << endl;
            cin >> tmpBool;
            setFreeWifi(tmpBool);
            cout << "The wifi availability has been successfully changed!" << endl;
            system("pause");
            break;
        case 8:
            system("cls");
            cin.ignore();
            cout << "Enter new music ganre: ";
            getline(cin, tmpStr);
            setMusicGenre(tmpStr);
            cout << "Music ganre was succesfully changed!" << endl;
            system("pause");
            break;
        case 9:
            system("cls");
            cout << "Set the availability of board games (1 - yes/0 - no): " << endl;
            cin >> tmpBool;
            setBoardGames(tmpBool);
            cout << "The board games availability has been successfully changed!" << endl;
            system("pause");
            break;
        case 10:
            system("cls");
            cout << "Do you want the place to be pet friendly? (1 - yes/0 - no): " << endl;
            cin >> tmpBool;
            setPetFriendly(tmpBool);
            cout << "The status of the location has been successfully changed!" << endl;
            system("pause");
            break;
        case 11:
            do {
                system("cls");
                cout << "Current menu: ";
                for (auto i : menu) {
                    cout << "\t";
                    i->showDish();
                }
                cout << "<------------------->" << endl;
                cout << "1. Add new dish" << endl;
                cout << "2. Del dish" << endl;
                cout << "0. Back" << endl;
                cout << "Your choice: ";
                cin >> tmpCMD;
                if (tmpCMD == 1) {
                    system("cls");
                    cout << "Enter the name of the dish: ";
                    cin.ignore();
                    getline(cin, tmpStr);
                    for (auto i : menu) {
                        if (i->getName() == tmpStr) {
                            throw new FoodDishNameSameException();
                        }
                    }
                    cout << "Enter the price of the dish: ";
                    cin >> tmpFloat;
                    if (tmpFloat <= 0) throw new FoodDishPriceException();
                    addDish(new Dish(tmpStr, tmpFloat));
                    cout << "New dish successfully added!" << endl;
                    system("pause");
                }
                else if (tmpCMD == 2) {
                    system("cls");
                    cout << "Enter the name of the dish: ";
                    cin.ignore();
                    getline(cin, tmpStr);
                    delDish(tmpStr);
                }
            } while (tmpCMD != 0);
            break;
        default:
            break;
        }
    } while (tmpInt != 0);
}

void Cafe::setInfo()
{
    bool tmpBool;
    int n1, n2;
    string tmpStrAdd;
    cout << "Enter a name: " << endl;
    getline(cin, tmpStrAdd);
    setName(tmpStrAdd);
    cout << "Enter an adress: " << endl;
    getline(cin, tmpStrAdd);
    setAdress(tmpStrAdd);
    cout << "Enter a music genre: " << endl;
    getline(cin, tmpStrAdd);
    setMusicGenre(tmpStrAdd);
    cout << "Enter a rating: ";
    cin >> n1;
    setRating(n1);
    cout << "Enter a coordinates(x y): ";
    cin >> n1 >> n2;
    changeCoordinates(n1, n2);
    cout << "Enter an opening time: ";
    cout << "Hours (24): ";
    cin >> n1;
    cout << "Minutes: ";
    cin >> n2;
    if (n1 > 23 || n1 < 0 || n2 > 59 || n2 < 0) {
        throw new FoodTimeInvalidException();
    }
    setOpeningTime(Time_(n1, n2, 0, true));
    cout << "Enter a closing time: ";
    cout << "Hours (24): ";
    cin >> n1;
    cout << "Minutes: ";
    cin >> n2;
    if (n1 > 23 || n1 < 0 || n2 > 59 || n2 < 0) {
        throw new FoodTimeInvalidException();
    }
    setClosingTime(Time_(n1, n2, 0, true));
    cout << "Availability of free wifi (1 - yes/0 - no): ";
    cin >> tmpBool;
    setFreeWifi(tmpBool);
    cout << "The naiability of board games (1 - yes/0 - no): ";
    cin >> tmpBool;
    setBoardGames(tmpBool);
    cout << "Pet friendly (1 - yes/0 - no): ";
    cin >> tmpBool;
    setPetFriendly(tmpBool);
}

void Cafe::saveToFile(ofstream& file) const
{
    file << name << endl;
    file << adress << endl;
    file << menu.size() << endl;
    for (int i = 0; i < menu.size(); i++) {
        menu[i]->saveDishToFile(file);
    }
    file << rating << endl;
    file << x << endl;
    file << y << endl;
    file << openingTime.getHour() << endl;
    file << openingTime.getMinutes() << endl;
    file << closingTime.getHour() << endl;
    file << closingTime.getMinutes() << endl;
    file << freeWifi << endl;
    file << musicGenre << endl;
    file << boardGames << endl;
    file << petFriendly << endl;
}

void Cafe::loadFromFile(ifstream& file)
{
    int h, m;
    float p;
    file.ignore();
    getline(file, name);
    getline(file, adress);
    file >> m;
    for (int i = 0; i < m; i++) {
        string tmpStr;
        file.ignore();
        getline(file, tmpStr);
        file >> p;
        menu.push_back(new Dish(tmpStr, p));
    }
    file >> rating;
    file >> x;
    file >> y;
    file >> h;
    file >> m;
    openingTime = Time_(h, m, 0, 1);
    file >> h;
    file >> m;
    closingTime = Time_(h, m, 0, 1);
    file >> freeWifi;
    file.ignore();
    getline(file, musicGenre);
    file >> boardGames;
    file >> petFriendly;
}

//void Cafe::saveCafeToFile(const string& filename) const
//{
//    ofstream file(filename);
//    if (!file.is_open()) cout << "File open error!" << endl;
//    else {
//        file << name << endl;
//        file << adress << endl;
//        file << menu.size() << endl;
//        for (int i = 0; i < menu.size(); i++) {
//            menu[i]->saveDishToFile(file);
//        }
//        file << rating << endl;
//        file << x << endl;
//        file << y << endl;
//        file << openingTime.getHour() << endl;
//        file << openingTime.getMinutes() << endl;
//        file << closingTime.getHour() << endl;
//        file << closingTime.getMinutes() << endl;
//        file << freeWifi << endl;
//        file << musicGenre << endl;
//        file << boardGames << endl;
//        file << petFriendly << endl;
//    }
//    file.close();
//}

void Cafe::saveCafeToFile(ofstream& file) const
{
    file << name << endl;
    file << adress << endl;
    file << menu.size() << endl;
    for (int i = 0; i < menu.size(); i++) {
        menu[i]->saveDishToFile(file);
    }
    file << rating << endl;
    file << x << endl;
    file << y << endl;
    file << openingTime.getHour() << endl;
    file << openingTime.getMinutes() << endl;
    file << closingTime.getHour() << endl;
    file << closingTime.getMinutes() << endl;
    file << freeWifi << endl;
    file << musicGenre << endl;
    file << boardGames << endl;
    file << petFriendly << endl;
}

void Cafe::loadCafeFromFile(const string& filename)
{
    int h, m;
    float p;
    ifstream file(filename);
    if (!file.is_open()) cout << "File open error!" << endl;
    else {
        getline(file, name);
        getline(file, adress);
        file >> m;
        for (int i = 0; i < m; i++) {
            string tmpStr;
            file.ignore();
            getline(file, tmpStr);
            file >> p;
            menu.push_back(new Dish(tmpStr, p));
        }
        file >> rating;
        file >> x;
        file >> y;
        file >> h;
        file >> m;
        openingTime = Time_(h, m, 0, 1);
        file >> h;
        file >> m;
        closingTime = Time_(h, m, 0, 1);
        file >> freeWifi;
        file.ignore();
        getline(file, musicGenre);
        file >> boardGames;
        file >> petFriendly;
    }
    file.close();
}
