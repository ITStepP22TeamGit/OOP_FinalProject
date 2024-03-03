#include "Canteen.h"

Canteen::Canteen()
{
    banquet = false;
    veganOptions = true;
}

Canteen::Canteen(string _name, string _adress, int _rating, int _x, int _y, Time_ _openingTime,
 Time_ _closingTime, bool _banquet, bool _veganOptions)
    :Food(_name, _adress, _rating, _x, _y, _openingTime, _closingTime)
{
    setBanquet(_banquet);
    setVegan(_veganOptions);
}

void Canteen::setBanquet(bool _banquet)
{
    banquet = _banquet;
}

bool Canteen::getBanquet() const
{
    return banquet;
}

void Canteen::setVegan(bool _veganOptions)
{
    veganOptions = _veganOptions;
}

bool Canteen::getVegan() const
{
    return veganOptions;
}

bool Canteen::askClientBanquet() const
{
    cout << "Want to include a banquet in your trip? (Yes/No)" << endl;
    string tmp;
    do {
        cin >> tmp;
        if (tmp == "No" || tmp == "no" || tmp == "nO" || tmp == "NO") return false;
        else if (tmp == "Yes" || tmp == "yes" || tmp == "YES" || tmp == "yeah" || tmp ==
            "yep" || tmp == "Yeah" || tmp == "Yep") return true;
    } while (true);
}

void Canteen::showFoodService() const
{
    cout << "---------------- " << type() << " --------------->" << endl;
    cout << "|   Name: " << name << endl;
    cout << "|   Rating: " << rating << " / 10" << endl;
    if (banquet) cout << "|   A banquet can be held" << endl;
    else cout << "|   A banquet can't be held" << endl;
    if (veganOptions) cout << "|   There is also food available for vegans" << endl;
    else cout << "|   The food is not suitable for vegans" << endl;
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

string Canteen::type() const
{
    return "CANTEEN";
}

void Canteen::edit()
{
    int tmpInt, tmpN, tmpK, tmpCMD;
    float tmpFloat;
    bool tmpBool;
    string tmpStr;
    do {
        system("cls");
        cout << "Select what you want to edit: " << endl;
        cout << "1. Name\n2. Rating\n3. Adress\n4. Coordinates\n5. Opening time\n6. Closing time" << endl;
        cout << "7. Banquet availability\n8. Vegan options\n";
        cout << "9. Menu" << endl;
        cout << "0. Exit" << endl;
        cout << "Your choice: ";
        cin >> tmpInt;
        switch (tmpInt)
        {
        case 1:
            system("cls");
            cin.ignore();
            cout << "Enter new name: ";
            getline(cin, tmpStr);
            setName(tmpStr);
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
            cout << "Set the availability for banquets (1 - yes/0 - no): " << endl;
            cin >> tmpBool;
            setBanquet(tmpBool);
            cout << "The banquets availability has been successfully changed!" << endl;
            system("pause");
            break;
        case 8:
            system("cls");
            cout << "Set the availability of vegan food in the facility (1 - yes/0 - no): " << endl;
            cin >> tmpBool;
            setVegan(tmpBool);
            cout << "The status of the location has been successfully changed!" << endl;
            system("pause");
            break;
        case 9:
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

void Canteen::setInfo()
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
    cout << "Enter a rating: ";
    cin >> n1;
    setRating(n1);
    cout << "Enter a coordinates(x y): ";
    cin >> n1 >> n2;
    changeCoordinates(n1, n2);
    cout << "Enter an opening time: " << endl;
    cout << "Hours (24): ";
    cin >> n1;
    cout << "Minutes: ";
    cin >> n2;
    if (n1 > 23 || n1 < 0 || n2 > 59 || n2 < 0) {
        throw new FoodTimeInvalidException();
    }
    setOpeningTime(Time_(n1, n2, 0, true));
    cout << "Enter a closing time: " << endl;
    cout << "Hours (24): ";
    cin >> n1;
    cout << "Minutes: ";
    cin >> n2;
    if (n1 > 23 || n1 < 0 || n2 > 59 || n2 < 0) {
        throw new FoodTimeInvalidException();
    }
    setClosingTime(Time_(n1, n2, 0, true));
    cout << "Availability of banquet (1 - yes/0 - no): ";
    cin >> tmpBool;
    setBanquet(tmpBool);
    cout << "Food availability for vegans (1 - yes/0 - no): ";
    cin >> tmpBool;
    setVegan(tmpBool);
}

void Canteen::saveToFile(ofstream& file) const
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
    file << banquet << endl;
    file << veganOptions << endl;
}

void Canteen::loadFromFile(ifstream& file)
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
    file >> banquet;
    file >> veganOptions;
}
