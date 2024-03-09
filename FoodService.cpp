#include "FoodService.h"
#include <algorithm>
#include <string>
#include "Time.h"

FoodService::FoodService()
{
    setName("BestFood");
}

FoodService::FoodService(string _name)
{
    setName(_name);
}

FoodService::~FoodService()
{
    for (int i = 0; i < foodServices.size(); i++) {
        //delete foodServices[i];
    }
    foodServices.clear();
}

void FoodService::setName(string _name)
{
    if (_name.empty()) {
        throw new FoodEmptyNameException();
    }
    name = _name;
}

string FoodService::getName() const
{
    return name;
}

int FoodService::getFoodServicesSize() const
{
    return foodServices.size();
}

void FoodService::addFoodService(Food* obj)
{
    foodServices.push_back(obj);
}

void FoodService::addFoodService(Map& map)
{
    int cmd;
    do {
        system("cls");
        cout << "What type of establishment do you want to add: " << endl;
        cout << "1. Cafe\n2. Canteen\n3. Restaraunt" << endl;
        cout << "Your choice: ";
        cin >> cmd;
        cin.ignore();
    } while (cmd != 1 && cmd != 2 && cmd != 3);
    if (cmd == 1) {
        try {
            Cafe* obj = new Cafe;
            obj->setInfo();
            foodServices.push_back(obj);
            map.addPoint(obj->getX(), obj->getY(), obj->getName(), 0);
            cout << "\nThe cafe \"" << obj->getName() << "\" has been successfully added!" << endl;
        }
        catch (FoodException* err) {
            cout << err->message() << endl;
            delete err;
        }
    }
    else if (cmd == 2) {
        try {
            Canteen* obj = new Canteen;
            obj->setInfo();
            foodServices.push_back(obj);
            map.addPoint(obj->getX(), obj->getY(), obj->getName(), 0);
            cout << "\nThe canteen \"" << obj->getName() << "\" has been successfully added!" << endl;
        }
        catch (FoodException* err) {
            cout << err->message() << endl;
            delete err;
        }
    }
    else if (cmd == 3) {
        try {
            Restaraunt* obj = new Restaraunt;
            obj->setInfo();
            foodServices.push_back(obj);
            map.addPoint(obj->getX(), obj->getY(), obj->getName(), 0);
            cout << "\nThe restaraunt \"" << obj->getName() << "\" has been successfully added!" << endl;
        }
        catch (FoodException* err) {
            cout << err->message() << endl;
            delete err;
        }
    }
}

void FoodService::delFoodServiceByName(string userName)
{
    for (int i = 0; i < foodServices.size(); i++) {
        if (foodServices[i]->getName() == userName) {
            foodServices.erase(foodServices.begin() + i);
            return;
        }
    }
    system("cls");
    cout << "No establishment by that name was found!" << endl;
}

void FoodService::delFoodService(Map& map)
{
    if (!foodServices.empty()) {
        int tmpInt;
        do {
            system("cls");
            cout << "Select which food service you want to delete:" << endl;
            for (int i = 0; i < foodServices.size(); i++) {
                cout << i + 1 << ". " << foodServices[i]->getName() << endl;
            }
            cout << "0 - BACK" << endl;
            cout << "Your choice: ";
            cin >> tmpInt;
        } while ((tmpInt != 0) && !(tmpInt >= 1 && tmpInt <= foodServices.size()));
        if (tmpInt != 0) {
            map.delPoint(foodServices[tmpInt - 1]->getX(), foodServices[tmpInt - 1]->getY(), 0);
            foodServices.erase(foodServices.begin() + (tmpInt - 1));
            cout << "\nSuccessfully deleted!" << endl;
        }
    }
    else {
        system("cls");
        cout << "There are no food services available for removal!" << endl;
    }
}

double FoodService::calculateAverageRating() const
{
    if (foodServices.empty()) {
        return 0.0;
    }

    double totalRating = 0.0;
    for (auto food : foodServices) {
        totalRating += food->getRating();
    }
    return totalRating / foodServices.size();
}

int FoodService::getTotalFoodCount() const
{
    return foodServices.size();
}

void FoodService::edit(Map& map)
{
    int num;
    //if (foodServices.empty()) cout << "There are no establishments to edit them!" << endl;
    //else {
        do {
            system("cls");
            cout << "=========================== FOOD CONTROL ===========================" << endl;
            cout << "|   1. Show all establishments\n|   2. Add new establishments\n|   3. Delete establishments\n";
            cout << "|   4. Edit establishment\n|   5. Search for establishments\n|   6. Sort establishments\n| 0. EXIT\n\n>>> ";
            cin >> num;
            switch (num)
            {
            case 1:
                system("cls");
                showFoodServices();
                system("pause");
                break;
            case 2:
                system("cls");
                addFoodService(map);
                system("pause");
                break;
            case 3:   
                delFoodService(map);
                system("pause");
                break;
            case 4:
                if (foodServices.empty()) cout << "There are no establishments to edit them" << endl;
                else {
                    int tmpInt;
                    do {
                        system("cls");
                        cout << "Select which food service you want to edit:" << endl;
                        for (int i = 0; i < foodServices.size(); i++) {
                            cout << i + 1 << ". " << foodServices[i]->getName() << endl;
                        }
                        cout << "0 - BACK" << endl;
                        cout << "Your choice: ";
                        cin >> tmpInt;
                    } while ((tmpInt != 0) && !(tmpInt >= 1 && tmpInt <= foodServices.size()));
                    if (tmpInt != 0) {
                        try {
                            foodServices[tmpInt - 1]->edit(map);
                            cout << "The establishment has been successfully edited!" << endl;
                        }
                        catch (FoodException* err) {
                            cout << err->message() << endl;
                            delete err;
                        }
                    }
                }
                system("pause");
                break;
            case 5:
                system("cls");
                int tempInteger;
                do {
                    system("cls");
                    cout << "Enter which parameter you want to search for:" << endl;
                    cout << "1. Search by name" << endl;
                    cout << "2. Search by adress" << endl;
                    cout << "3. Search by rating" << endl;
                    cout << "4. Search by type" << endl;
                    cout << "0 - BACK" << endl;
                    cout << ">>> ";
                    cin >> tempInteger;
                    string tmpString;
                    if (tempInteger == 1) {
                        system("cls");
                        cout << "Enter a name: " << endl;
                        cin.ignore();
                        getline(cin, tmpString);
                        searchByName(tmpString, true);
                        system("pause");
                        tempInteger = 0;
                    }
                    else if (tempInteger == 2) {
                        system("cls");
                        cout << "Enter an adress: " << endl;
                        cin.ignore();
                        getline(cin, tmpString);
                        searchByAdress(tmpString, true);
                        system("pause");
                        tempInteger = 0;
                    }
                    else if (tempInteger == 3) {
                        system("cls");
                        int tempInt1, tmpInt2;
                        cout << "Enter a lower rating threshold: ";
                        cin >> tempInt1;
                        cout << "Enter the upper rating threshold: ";
                        cin >> tmpInt2;
                        searchByRating(tempInt1, tmpInt2, true);
                        system("pause");
                        tempInteger = 0;
                    }
                    else if (tempInteger == 4) {
                        system("cls");
                        int tempInt3;
                        do {
                            system("cls");
                            cout << "Choose type:" << endl;
                            cout << "1. Cafe" << endl;
                            cout << "2. Canteen" << endl;
                            cout << "3. Restaraunt" << endl;
                            cout << ">>> ";
                            cin >> tempInt3;
                        } while (tempInt3 != 1 && tempInt3 != 2 && tempInt3 != 3);
                        if (tempInt3 == 1) {
                            searchByType("CAFE", true);
                        }
                        else if (tempInt3 == 2) {
                            searchByType("CANTEEN", true);
                        }
                        else if (tempInt3 == 3) {
                            searchByType("RESTARAUNT", true);
                        }
                        system("pause");
                        tempInteger = 0;
                    }
                } while (tempInteger != 0);
                break;
            case 6:
                system("cls");
                int tempIntgr;
                do {
                    system("cls");
                    cout << "Select which parameter to sort by:" << endl;
                    cout << "1. Sort by rating" << endl;
                    cout << "2. Sort by opening time" << endl;
                    cout << "3. Sort by closing time" << endl;
                    cout << "0 - BACK" << endl;
                    cout << ">>> ";
                    cin >> tempIntgr;
                    switch (tempIntgr)
                    {
                    case 1:
                        sortByRating(true);
                        system("pause");
                        break;
                    case 2:
                        sortByOpeningTime(true);
                        system("pause");
                        break;
                    case 3:
                        sortByClosingTime(true);
                        system("pause");
                        break;
                    default:
                        break;
                    }
                } while (tempIntgr != 0);
                break;
            default:
                break;
            }
        } while (num != 0);
}

void FoodService::editForTour()
{
    int num;
    //if (foodServices.empty()) cout << "There are no establishments to edit them!" << endl;
    //else {
    do {
        system("cls");
        cout << "=========================== FOOD CONTROL ===========================" << endl;
        cout << "|   1. Add new establishments\n|   2. Delete establishments\n";
        cout << "|   3. Edit establishment\n| 0. EXIT\n\n>>> ";
        cin >> num;
        switch (num)
        {
        case 1:
            int cmd;
            do {
                system("cls");
                cout << "What type of establishment do you want to add: " << endl;
                cout << "1. Cafe\n2. Canteen\n3. Restaraunt" << endl;
                cout << "Your choice: ";
                cin >> cmd;
                cin.ignore();
            } while (cmd != 1 && cmd != 2 && cmd != 3);
            if (cmd == 1) {
                try {
                    Cafe* obj = new Cafe;
                    obj->setInfo();
                    foodServices.push_back(obj);
                    //map.addPoint(obj->getX(), obj->getY(), obj->getName(), 0);
                    cout << "\nThe cafe \"" << obj->getName() << "\" has been successfully added!" << endl;
                }
                catch (FoodException* err) {
                    cout << err->message() << endl;
                    delete err;
                }
            }
            else if (cmd == 2) {
                try {
                    Canteen* obj = new Canteen;
                    obj->setInfo();
                    foodServices.push_back(obj);
                    //map.addPoint(obj->getX(), obj->getY(), obj->getName(), 0);
                    cout << "\nThe canteen \"" << obj->getName() << "\" has been successfully added!" << endl;
                }
                catch (FoodException* err) {
                    cout << err->message() << endl;
                    delete err;
                }
            }
            else if (cmd == 3) {
                try {
                    Restaraunt* obj = new Restaraunt;
                    obj->setInfo();
                    foodServices.push_back(obj);
                    //map.addPoint(obj->getX(), obj->getY(), obj->getName(), 0);
                    cout << "\nThe restaraunt \"" << obj->getName() << "\" has been successfully added!" << endl;
                }
                catch (FoodException* err) {
                    cout << err->message() << endl;
                    delete err;
                }
            }
            system("pause");
            break;
        case 2:
            if (!foodServices.empty()) {
                int tmpInt;
                do {
                    system("cls");
                    cout << "Select which food service you want to delete:" << endl;
                    for (int i = 0; i < foodServices.size(); i++) {
                        cout << i + 1 << ". " << foodServices[i]->getName() << endl;
                    }
                    cout << "0 - BACK" << endl;
                    cout << "Your choice: ";
                    cin >> tmpInt;
                } while ((tmpInt != 0) && !(tmpInt >= 1 && tmpInt <= foodServices.size()));
                if (tmpInt != 0) {
                    foodServices.erase(foodServices.begin() + (tmpInt - 1));
                    cout << "\nSuccessfully deleted!" << endl;
                }
            }
            else {
                system("cls");
                cout << "There are no food services available for removal!" << endl;
            }
            system("pause");
            break;
        case 3:
            if (foodServices.empty()) cout << "There are no establishments to edit them" << endl;
            else {
                int tmpInt;
                do {
                    system("cls");
                    cout << "Select which food service you want to edit:" << endl;
                    for (int i = 0; i < foodServices.size(); i++) {
                        cout << i + 1 << ". " << foodServices[i]->getName() << endl;
                    }
                    cout << "0 - BACK" << endl;
                    cout << "Your choice: ";
                    cin >> tmpInt;
                } while ((tmpInt != 0) && !(tmpInt >= 1 && tmpInt <= foodServices.size()));
                if (tmpInt != 0) {
                    try {
                        //foodServices[tmpInt - 1]->edit(map);
                        cout << "The establishment has been successfully edited!" << endl;
                    }
                    catch (FoodException* err) {
                        cout << err->message() << endl;
                        delete err;
                    }
                }
            }
            system("pause");
            break;
        default:
            break;
        }
    } while (num != 0);
}

int FoodService::editForClient()
{
    int num;
    do {
        system("cls");
        cout << "=========================== FOOD ===========================" << endl;
        cout << "|   1. Show all establishments\n";
        cout << "|   2. Search for establishments\n|   3. Sort establishments\n| 0. EXIT\n\n>>> ";
        cin >> num;
        switch (num)
        {
        case 1:
            system("cls");
            return showFoodServices();
            system("pause");
            break;
        case 2:
            system("cls");
            int tempInteger;
            do {
                system("cls");
                cout << "Enter which parameter you want to search for:" << endl;
                cout << "1. Search by name" << endl;
                cout << "2. Search by adress" << endl;
                cout << "3. Search by rating" << endl;
                cout << "4. Search by type" << endl;
                cout << "0 - BACK" << endl;
                cout << ">>> ";
                cin >> tempInteger;
                string tmpString;
                if (tempInteger == 1) {
                    system("cls");
                    cout << "Enter a name: " << endl;
                    cin.ignore();
                    getline(cin, tmpString);
                    int searchTmp = searchByName(tmpString);
                    if (searchTmp == -1) {
                        cout << "Nothing was found!" << endl;
                        return -1;
                    }
                    else return searchTmp;
                    system("pause");
                    tempInteger = 0;
                }
                else if (tempInteger == 2) {
                    system("cls");
                    cout << "Enter an adress: " << endl;
                    cin.ignore();
                    getline(cin, tmpString);
                    int searchTmp = searchByAdress(tmpString);
                    if (searchTmp == -1) {
                        cout << "Nothing was found!" << endl;
                        return -1;
                    }
                    else return searchTmp;
                    system("pause");
                    tempInteger = 0;
                }
                else if (tempInteger == 3) {
                    system("cls");
                    int tempInt1, tmpInt2;
                    cout << "Enter a lower rating threshold: ";
                    cin >> tempInt1;
                    cout << "Enter the upper rating threshold: ";
                    cin >> tmpInt2;
                    int searchTmp = searchByRating(tempInt1, tmpInt2);
                    if (searchTmp == -1) {
                        cout << "Nothing was found!" << endl;
                        return -1;
                    }
                    else return searchTmp;
                    system("pause");
                    tempInteger = 0;
                }
                else if (tempInteger == 4) {
                    int tempInt3;
                    do {
                        system("cls");
                        cout << "Choose type:" << endl;
                        cout << "1. Cafe" << endl;
                        cout << "2. Canteen" << endl;
                        cout << "3. Restaraunt" << endl;
                        cout << ">>> ";
                        cin >> tempInt3;
                    } while (tempInt3 != 1 && tempInt3 != 2 && tempInt3 != 3);
                    int searchTmp = -1;
                    if (tempInt3 == 1) {
                        searchTmp = searchByType("CAFE");
                    }
                    else if (tempInt3 == 2) {
                        searchTmp = searchByType("CANTEEN");
                    }
                    else if (tempInt3 == 3) {
                        searchTmp = searchByType("RESTARAUNT");
                    }
                    if (searchTmp == -1) {
                        cout << "Nothing was found!" << endl;
                        return -1;
                    }
                    else return searchTmp;
                    system("pause");
                    tempInteger = 0;
                }
            } while (tempInteger != 0);
            break;
        case 3:
            system("cls");
            int tempIntgr;
            do {
                system("cls");
                cout << "Select which parameter to sort by:" << endl;
                cout << "1. Sort by rating" << endl;
                cout << "2. Sort by opening time" << endl;
                cout << "3. Sort by closing time" << endl;
                cout << "0 - BACK" << endl;
                cout << ">>> ";
                cin >> tempIntgr;
                int searchTmp = -1;
                switch (tempIntgr)
                {
                case 1:
                    searchTmp = sortByRating();
                    if (searchTmp == -1) {
                        cout << "Nothing was found!" << endl;
                        return -1;
                    }
                    else return searchTmp;
                    system("pause");
                    break;
                case 2:
                    searchTmp = sortByOpeningTime();
                    if (searchTmp == -1) {
                        cout << "Nothing was found!" << endl;
                        return -1;
                    }
                    else return searchTmp;
                    system("pause");
                    break;
                case 3:
                    searchTmp = sortByClosingTime();
                    if (searchTmp == -1) {
                        cout << "Nothing was found!" << endl;
                        return -1;
                    }
                    else return searchTmp;
                    system("pause");
                    break;
                default:
                    break;
                }
            } while (tempIntgr != 0);
            break;
        default:
            break;
        }
    } while (num != 0);
    return -1;
}

void FoodService::editForClient(bool flag)
{
    int num;
    do {
        system("cls");
        cout << "=========================== FOOD ===========================" << endl;
        cout << "|   1. Show all establishments\n";
        cout << "|   2. Search for establishments\n|   3. Sort establishments\n| 0. EXIT\n\n>>> ";
        cin >> num;
        switch (num)
        {
        case 1:
            system("cls");
            showFoodServices(1);
            system("pause");
            break;
        case 2:
            system("cls");
            int tempInteger;
            do {
                system("cls");
                cout << "Enter which parameter you want to search for:" << endl;
                cout << "1. Search by name" << endl;
                cout << "2. Search by adress" << endl;
                cout << "3. Search by rating" << endl;
                cout << "4. Search by type" << endl;
                cout << "0 - BACK" << endl;
                cout << ">>> ";
                cin >> tempInteger;
                string tmpString;
                if (tempInteger == 1) {
                    system("cls");
                    cout << "Enter a name: " << endl;
                    cin.ignore();
                    getline(cin, tmpString);
                    searchByName(tmpString, true);
                    system("pause");
                    tempInteger = 0;
                }
                else if (tempInteger == 2) {
                    system("cls");
                    cout << "Enter an adress: " << endl;
                    cin.ignore();
                    getline(cin, tmpString);
                    searchByAdress(tmpString, true);
                    system("pause");
                    tempInteger = 0;
                }
                else if (tempInteger == 3) {
                    system("cls");
                    int tempInt1, tmpInt2;
                    cout << "Enter a lower rating threshold: ";
                    cin >> tempInt1;
                    cout << "Enter the upper rating threshold: ";
                    cin >> tmpInt2;
                    searchByRating(tempInt1, tmpInt2, true);
                    system("pause");
                    tempInteger = 0;
                }
                else if (tempInteger == 4) {
                    int tempInt3;
                    do {
                        system("cls");
                        cout << "Choose type:" << endl;
                        cout << "1. Cafe" << endl;
                        cout << "2. Canteen" << endl;
                        cout << "3. Restaraunt" << endl;
                        cout << ">>> ";
                        cin >> tempInt3;
                    } while (tempInt3 != 1 && tempInt3 != 2 && tempInt3 != 3);
                    if (tempInt3 == 1) {
                        searchByType("CAFE", true);
                    }
                    else if (tempInt3 == 2) {
                        searchByType("CANTEEN", true);
                    }
                    else if (tempInt3 == 3) {
                        searchByType("RESTARAUNT", true);
                    }
                    system("pause");
                    tempInteger = 0;
                }
            } while (tempInteger != 0);
            break;
        case 3:
            system("cls");
            int tempIntgr;
            do {
                system("cls");
                cout << "Select which parameter to sort by:" << endl;
                cout << "1. Sort by rating" << endl;
                cout << "2. Sort by opening time" << endl;
                cout << "3. Sort by closing time" << endl;
                cout << "0 - BACK" << endl;
                cout << ">>> ";
                cin >> tempIntgr;
                int searchTmp = -1;
                switch (tempIntgr)
                {
                case 1:
                    sortByRating(true);
                    system("pause");
                    break;
                case 2:
                    sortByOpeningTime(true);
                    system("pause");
                    break;
                case 3:
                    sortByClosingTime(true);
                    system("pause");
                    break;
                default:
                    break;
                }
            } while (tempIntgr != 0);
            break;
        default:
            break;
        }
    } while (num != 0);
}

void FoodService::searchByName(string _name, bool flag) const
{
    system("cls");
    bool find = false;
    for (int i = 0, j = 0; i < foodServices.size(); i++) {
        if (foodServices[i]->getName() == _name) {
            if (foodServices[i]->type() == "CAFE") {
                cout << "--------------- " << "#" << j + 1 << " " << foodServices[i]->type() << " ---------------->" << endl;
            }
            else if (foodServices[i]->type() == "CANTEEN") {
                cout << "-------------- " << "#" << j + 1 << " " << foodServices[i]->type() << " -------------->" << endl;
            }
            else if (foodServices[i]->type() == "RESTARAUNT") {
                cout << "------------- " << "#" << j + 1 << " " << foodServices[i]->type() << " ------------>" << endl;
            }
            foodServices[i]->showFoodService();
            j += 1;
            find = true;
        }
    }
    if (!find) {
        cout << "Name search results: nothing found!" << endl;
    }
}

int FoodService::searchByName(string _name)
{
    system("cls");
    bool find = false;
    vector<int> vecInt;
    for (int i = 0, j = 0; i < foodServices.size(); i++) {
        if (foodServices[i]->getName() == _name) {
            if (foodServices[i]->type() == "CAFE") {
                cout << "--------------- " << "#" << j + 1 << " " << foodServices[i]->type() << " ---------------->" << endl;
            }
            else if (foodServices[i]->type() == "CANTEEN") {
                cout << "-------------- " << "#" << j + 1 << " " << foodServices[i]->type() << " -------------->" << endl;
            }
            else if (foodServices[i]->type() == "RESTARAUNT") {
                cout << "------------- " << "#" << j + 1 << " " << foodServices[i]->type() << " ------------>" << endl;
            }
            foodServices[i]->showFoodService();
            vecInt.push_back(i);
            j += 1;
            find = true;
        }
    }
    if (!find) {
        cout << "Name search results: nothing found!" << endl;
        return -1;
    }
    else {
        int tmp;
        cout << "Choose what you want to order: ";
        cin >> tmp;
        return vecInt[tmp - 1];
    }
}

void FoodService::searchByAdress(string _adress, bool flag) const
{
    system("cls");
    bool find = false;
    for (int i = 0, j = 0; i < foodServices.size(); i++) {
        if (foodServices[i]->getAdress() == _adress) {
            if (foodServices[i]->type() == "CAFE") {
                cout << "--------------- " << "#" << j + 1 << " " << foodServices[i]->type() << " ---------------->" << endl;
            }
            else if (foodServices[i]->type() == "CANTEEN") {
                cout << "-------------- " << "#" << j + 1 << " " << foodServices[i]->type() << " -------------->" << endl;
            }
            else if (foodServices[i]->type() == "RESTARAUNT") {
                cout << "------------- " << "#" << j + 1 << " " << foodServices[i]->type() << " ------------>" << endl;
            }
            foodServices[i]->showFoodService();
            j += 1;
            find = true;
        }
    }
    if (!find) {
        cout << "Adress search results: nothing found!" << endl;
    }
}

int FoodService::searchByAdress(string _adress)
{
    system("cls");
    bool find = false;
    vector<int> vecInt;
    for (int i = 0, j = 0; i < foodServices.size(); i++) {
        if (foodServices[i]->getAdress() == _adress) {
            if (foodServices[i]->type() == "CAFE") {
                cout << "--------------- " << "#" << j + 1 << " " << foodServices[i]->type() << " ---------------->" << endl;
            }
            else if (foodServices[i]->type() == "CANTEEN") {
                cout << "-------------- " << "#" << j + 1 << " " << foodServices[i]->type() << " -------------->" << endl;
            }
            else if (foodServices[i]->type() == "RESTARAUNT") {
                cout << "------------- " << "#" << j + 1 << " " << foodServices[i]->type() << " ------------>" << endl;
            }
            foodServices[i]->showFoodService();
            vecInt.push_back(i);
            j += 1;
            find = true;
        }
    }
    if (!find) {
        cout << "Adress search results: nothing found!" << endl;
        return -1;
    }
    else {
        int tmp;
        cout << "Choose what you want to order: ";
        cin >> tmp;
        return vecInt[tmp - 1];
    }
}

void FoodService::searchByRating(int _ratingLow, int _ratingHigh, bool flag) const
{
    system("cls");
    bool find = false;
    for (int i = 0, j = 0; i < foodServices.size(); i++) {
        if (foodServices[i]->getRating() >= _ratingLow && foodServices[i]->getRating() <= _ratingHigh) {
            if (foodServices[i]->type() == "CAFE") {
                cout << "--------------- " << "#" << j + 1 << " " << foodServices[i]->type() << " ---------------->" << endl;
            }
            else if (foodServices[i]->type() == "CANTEEN") {
                cout << "-------------- " << "#" << j + 1 << " " << foodServices[i]->type() << " -------------->" << endl;
            }
            else if (foodServices[i]->type() == "RESTARAUNT") {
                cout << "------------- " << "#" << j + 1 << " " << foodServices[i]->type() << " ------------>" << endl;
            }
            foodServices[i]->showFoodService();
            j += 1;
            find = true;
        }
    }
    if (!find) cout << "Rating search results: nothing found!" << endl;
}

int FoodService::searchByRating(int _ratingLow, int _ratingHigh)
{
    system("cls");
    bool find = false;
    vector<int> vecInt;
    for (int i = 0, j = 0; i < foodServices.size(); i++) {
        if (foodServices[i]->getRating() >= _ratingLow && foodServices[i]->getRating() <= _ratingHigh) {
            if (foodServices[i]->type() == "CAFE") {
                cout << "--------------- " << "#" << j + 1 << " " << foodServices[i]->type() << " ---------------->" << endl;
            }
            else if (foodServices[i]->type() == "CANTEEN") {
                cout << "-------------- " << "#" << j + 1 << " " << foodServices[i]->type() << " -------------->" << endl;
            }
            else if (foodServices[i]->type() == "RESTARAUNT") {
                cout << "------------- " << "#" << j + 1 << " " << foodServices[i]->type() << " ------------>" << endl;
            }
            foodServices[i]->showFoodService();
            vecInt.push_back(i);
            j += 1;
            find = true;
        }
    }
    if (!find) {
        cout << "Rating search results: nothing found!" << endl;
        return -1;
    }
    else {
        int tmp;
        cout << "Choose what you want to order: ";
        cin >> tmp;
        return vecInt[tmp - 1];
    }
}

void FoodService::searchByType(string _type, bool flag) const
{
    system("cls");
    bool find = false;
    for (int i = 0, j = 0; i < foodServices.size(); i++) {
        if (foodServices[i]->type() == _type) {
            if (foodServices[i]->type() == "CAFE") {
                cout << "--------------- " << "#" << j + 1 << " " << foodServices[i]->type() << " ---------------->" << endl;
            }
            else if (foodServices[i]->type() == "CANTEEN") {
                cout << "-------------- " << "#" << j + 1 << " " << foodServices[i]->type() << " -------------->" << endl;
            }
            else if (foodServices[i]->type() == "RESTARAUNT") {
                cout << "------------- " << "#" << j + 1 << " " << foodServices[i]->type() << " ------------>" << endl;
            }
            foodServices[i]->showFoodService();
            j += 1;
            find = true;
        }
    }
    if (!find) cout << "Type search results: nothing found!" << endl;
}

int FoodService::searchByType(string _type)
{
    system("cls");
    bool find = false;
    vector<int> vecInt;
    for (int i = 0, j = 0; i < foodServices.size(); i++) {
        if (foodServices[i]->type() == _type) {
            if (foodServices[i]->type() == "CAFE") {
                cout << "--------------- " << "#" << j + 1 << " " << foodServices[i]->type() << " ---------------->" << endl;
            }
            else if (foodServices[i]->type() == "CANTEEN") {
                cout << "-------------- " << "#" << j + 1 << " " << foodServices[i]->type() << " -------------->" << endl;
            }
            else if (foodServices[i]->type() == "RESTARAUNT") {
                cout << "------------- " << "#" << j + 1 << " " << foodServices[i]->type() << " ------------>" << endl;
            }
            foodServices[i]->showFoodService();
            vecInt.push_back(i);
            j += 1;
            find = true;
        }
    }
    if (!find) {
        cout << "Type search results: nothing found!" << endl;
        return -1;
    }
    else {
        int tmp;
        cout << "Choose what you want to order: ";
        cin >> tmp;
        return vecInt[tmp - 1];
    }
}

void FoodService::sortByRating(bool flag) const
{
    system("cls");
    if (foodServices.empty()) cout << "There are no establishments to sort them out!" << endl;
    else if (foodServices.size() == 1) {
        cout << "There's only one available establishment: " << endl;
        if (foodServices[0]->type() == "CAFE") {
            cout << "--------------- " << "#" << 1 << " " << foodServices[0]->type() << " ---------------->" << endl;
        }
        else if (foodServices[0]->type() == "CANTEEN") {
            cout << "-------------- " << "#" << 1 << " " << foodServices[0]->type() << " -------------->" << endl;
        }
        else if (foodServices[0]->type() == "RESTARAUNT") {
            cout << "------------- " << "#" << 1 << " " << foodServices[0]->type() << " ------------>" << endl;
        }
        foodServices[0]->showFoodService();
        return;
    }
    else {
        cout << "Results of sorting by rating: " << endl;
        vector<Food*> tmpFoodServices;
        tmpFoodServices = foodServices;
        sort(tmpFoodServices.begin(), tmpFoodServices.end(), [](const Food* a, const Food* b) {
            return a->getRating() > b->getRating();
            });
        for (int i = 0; i < tmpFoodServices.size(); i++) {
            if (tmpFoodServices[i]->type() == "CAFE") {
                cout << "--------------- " << "#" << i + 1 << " " << tmpFoodServices[i]->type() << " ---------------->" << endl;
            }
            else if (tmpFoodServices[i]->type() == "CANTEEN") {
                cout << "-------------- " << "#" << i + 1 << " " << tmpFoodServices[i]->type() << " -------------->" << endl;
            }
            else if (tmpFoodServices[i]->type() == "RESTARAUNT") {
                cout << "------------- " << "#" << i + 1 << " " << tmpFoodServices[i]->type() << " ------------>" << endl;
            }
            tmpFoodServices[i]->showFoodService();
        }
        tmpFoodServices.clear();
    }
}

int FoodService::sortByRating()
{
    system("cls");
    if (foodServices.empty()) {
        cout << "There are no establishments to sort them out!" << endl;
        return -1;
    }
    else {
        cout << "Results of sorting by rating: " << endl;
        vector<Food*> tmpFoodServices;
        tmpFoodServices = foodServices;
        sort(tmpFoodServices.begin(), tmpFoodServices.end(), [](const Food* a, const Food* b) {
            return a->getRating() > b->getRating();
            });
        for (int i = 0, j = 0; i < tmpFoodServices.size(); i++) {
            if (tmpFoodServices[i]->type() == "CAFE") {
                cout << "--------------- " << "#" << j + 1 << " " << tmpFoodServices[i]->type() << " ---------------->" << endl;
            }
            else if (tmpFoodServices[i]->type() == "CANTEEN") {
                cout << "-------------- " << "#" << j + 1 << " " << tmpFoodServices[i]->type() << " -------------->" << endl;
            }
            else if (tmpFoodServices[i]->type() == "RESTARAUNT") {
                cout << "------------- " << "#" << j + 1 << " " << tmpFoodServices[i]->type() << " ------------>" << endl;
            }
            tmpFoodServices[i]->showFoodService();
            j += 1;
        }
        int tmp;
        cout << "Choose what you want to order: ";
        cin >> tmp;
        for (int i = 0; i < foodServices.size(); i++) {
            if (foodServices[i]->getName() == tmpFoodServices[tmp - 1]->getName()) {
                tmpFoodServices.clear();
                return i;
            }
        }
        tmpFoodServices.clear();
        return -1;
    }
}

void FoodService::sortByOpeningTime(bool flag) const
{
    system("cls");
    if (foodServices.empty()) cout << "There are no establishments to sort them out!" << endl;
    else if (foodServices.size() == 1) {
        cout << "There's only one available establishment: " << endl;
        if (foodServices[0]->type() == "CAFE") {
            cout << "--------------- " << "#" << 1 << " " << foodServices[0]->type() << " ---------------->" << endl;
        }
        else if (foodServices[0]->type() == "CANTEEN") {
            cout << "-------------- " << "#" << 1 << " " << foodServices[0]->type() << " -------------->" << endl;
        }
        else if (foodServices[0]->type() == "RESTARAUNT") {
            cout << "------------- " << "#" << 1 << " " << foodServices[0]->type() << " ------------>" << endl;
        }
        foodServices[0]->showFoodService();
        return;
    }
    else {
        cout << "Results of sorting by opening time: " << endl;
        vector<Food*> tmpFoodServices;
        tmpFoodServices = foodServices;
        sort(tmpFoodServices.begin(), tmpFoodServices.end(), [](const Food* a, const Food* b) {
            return a->getOpeningTime() < b->getOpeningTime();
            });
        for (int i = 0; i < tmpFoodServices.size(); i++) {
            if (tmpFoodServices[i]->type() == "CAFE") {
                cout << "--------------- " << "#" << i + 1 << " " << tmpFoodServices[i]->type() << " ---------------->" << endl;
            }
            else if (tmpFoodServices[i]->type() == "CANTEEN") {
                cout << "-------------- " << "#" << i + 1 << " " << tmpFoodServices[i]->type() << " -------------->" << endl;
            }
            else if (tmpFoodServices[i]->type() == "RESTARAUNT") {
                cout << "------------- " << "#" << i + 1 << " " << tmpFoodServices[i]->type() << " ------------>" << endl;
            }
            tmpFoodServices[i]->showFoodService();
        }
        tmpFoodServices.clear();
    }
}

int FoodService::sortByOpeningTime()
{
    system("cls");
    if (foodServices.empty()) {
        cout << "There are no establishments to sort them out!" << endl;
        return -1;
    }
    else {
        cout << "Results of sorting by opening time: " << endl;
        vector<Food*> tmpFoodServices;
        tmpFoodServices = foodServices;
        sort(tmpFoodServices.begin(), tmpFoodServices.end(), [](const Food* a, const Food* b) {
            return a->getOpeningTime() < b->getOpeningTime();
            });
        for (int i = 0, j = 0; i < tmpFoodServices.size(); i++) {
            if (tmpFoodServices[i]->type() == "CAFE") {
                cout << "--------------- " << "#" << j + 1 << " " << tmpFoodServices[i]->type() << " ---------------->" << endl;
            }
            else if (tmpFoodServices[i]->type() == "CANTEEN") {
                cout << "-------------- " << "#" << j + 1 << " " << tmpFoodServices[i]->type() << " -------------->" << endl;
            }
            else if (tmpFoodServices[i]->type() == "RESTARAUNT") {
                cout << "------------- " << "#" << j + 1 << " " << tmpFoodServices[i]->type() << " ------------>" << endl;
            }
            tmpFoodServices[i]->showFoodService();
            j += 1;
        }
        int tmp;
        cout << "Choose what you want to order: ";
        cin >> tmp;
        for (int i = 0; i < foodServices.size(); i++) {
            if (foodServices[i]->getName() == tmpFoodServices[tmp - 1]->getName()) {
                tmpFoodServices.clear();
                return i;
            }
        }
        tmpFoodServices.clear();
        return -1;
    }
}

void FoodService::sortByClosingTime(bool flag) const
{
    system("cls");
    if (foodServices.empty()) cout << "There are no establishments to sort them out!" << endl;
    else if (foodServices.size() == 1) {
        cout << "There's only one available establishment: " << endl;
        if (foodServices[0]->type() == "CAFE") {
            cout << "--------------- " << "#" << 1 << " " << foodServices[0]->type() << " ---------------->" << endl;
        }
        else if (foodServices[0]->type() == "CANTEEN") {
            cout << "-------------- " << "#" << 1 << " " << foodServices[0]->type() << " -------------->" << endl;
        }
        else if (foodServices[0]->type() == "RESTARAUNT") {
            cout << "------------- " << "#" << 1 << " " << foodServices[0]->type() << " ------------>" << endl;
        }
        foodServices[0]->showFoodService();
        return;
    }
    else {
        cout << "Results of sorting by closing time: " << endl;
        vector<Food*> tmpFoodServices;
        tmpFoodServices = foodServices;
        sort(tmpFoodServices.begin(), tmpFoodServices.end(), [](const Food* a, const Food* b) {
            return a->getClosingTime() > b->getClosingTime();
            });
        for (int i = 0; i < tmpFoodServices.size(); i++) {
            if (tmpFoodServices[i]->type() == "CAFE") {
                cout << "--------------- " << "#" << i + 1 << " " << tmpFoodServices[i]->type() << " ---------------->" << endl;
            }
            else if (tmpFoodServices[i]->type() == "CANTEEN") {
                cout << "-------------- " << "#" << i + 1 << " " << tmpFoodServices[i]->type() << " -------------->" << endl;
            }
            else if (tmpFoodServices[i]->type() == "RESTARAUNT") {
                cout << "------------- " << "#" << i + 1 << " " << tmpFoodServices[i]->type() << " ------------>" << endl;
            }
            tmpFoodServices[i]->showFoodService();
        }
        tmpFoodServices.clear();
    }
}

int FoodService::sortByClosingTime()
{
    system("cls");
    if (foodServices.empty()) {
        cout << "There are no establishments to sort them out!" << endl;
        return -1;
    }
    else {
        cout << "Results of sorting by closing time: " << endl;
        vector<Food*> tmpFoodServices;
        tmpFoodServices = foodServices;
        sort(tmpFoodServices.begin(), tmpFoodServices.end(), [](const Food* a, const Food* b) {
            return a->getClosingTime() > b->getClosingTime();
            });
        for (int i = 0, j = 0; i < tmpFoodServices.size(); i++) {
            if (tmpFoodServices[i]->type() == "CAFE") {
                cout << "--------------- " << "#" << j + 1 << " " << tmpFoodServices[i]->type() << " ---------------->" << endl;
            }
            else if (tmpFoodServices[i]->type() == "CANTEEN") {
                cout << "-------------- " << "#" << j + 1 << " " << tmpFoodServices[i]->type() << " -------------->" << endl;
            }
            else if (tmpFoodServices[i]->type() == "RESTARAUNT") {
                cout << "------------- " << "#" << j + 1 << " " << tmpFoodServices[i]->type() << " ------------>" << endl;
            }
            tmpFoodServices[i]->showFoodService();
            j += 1;
        }
        int tmp;
        cout << "Choose what you want to order: ";
        cin >> tmp;
        for (int i = 0; i < foodServices.size(); i++) {
            if (foodServices[i]->getName() == tmpFoodServices[tmp - 1]->getName()) {
                tmpFoodServices.clear();
                return i;
            }
        }
        tmpFoodServices.clear();
        return -1;
    }
}

void FoodService::showFoodServices(bool flag) const
{
    if (foodServices.empty()) {
        cout << "There are no establishments in the " << name << "!" << endl;
    }
    else {
        cout << "======================- " << name << " -======================" << endl;
        cout << "Average rating: " << calculateAverageRating() << endl;
        cout << "All " << getTotalFoodCount() << " establishments: " << endl;
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
        }
    }
}

int FoodService::showFoodServices()
{
    if (foodServices.empty()) {
        cout << "There are no establishments in the " << name << "!" << endl;
        return -1;
    }
    else {
        cout << "======================- " << name << " -======================" << endl;
        cout << "Average rating: " << calculateAverageRating() << endl;
        cout << "All " << getTotalFoodCount() << " establishments: " << endl;
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
        }
        int tmp;
        cout << "Choose what you want to order: ";
        cin >> tmp;
        return tmp - 1;
    }
}

float FoodService::askClient() const
{
    int askInt = -1;
    do {
        cout << "Do you wish to include the availability of a banquet in the price? (1 - yes/0 - no)\n";
        cout << ">>> ";
        cin >> askInt;
    } while (askInt != 1 && askInt != 0);
    if (askInt == 1) {
        return 25;
    }
    else {
        return 0;
    }
}

void FoodService::saveFoodServicesToFile(const string& filename) const
{
    ofstream file(filename);
    if (!file.is_open()) cout << "File open error!" << endl;
    else {
        file << foodServices.size();
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
        }
    }
    file.close();
}

void FoodService::saveFoodServicesToFile(ofstream& file) const
{
    file << foodServices.size();
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
    }
}

void FoodService::loadFoodServicesFromFile(const string& filename, Map& map)
{
    ifstream file(filename);
    if (!file.is_open()) cout << "File open error!" << endl;
    else {
        int typeN, sizeN;
        file >> sizeN;
        //cout << sizeN << endl;
        for (int i = 0; i < sizeN; i++) {
            file >> typeN;
            if (typeN == 1) {
                //foodServices.push_back(new Cafe);
                Cafe* nCafe = new Cafe;
                nCafe->loadFromFile(file);
                //foodServices[i]->loadFromFile(file);
                foodServices.push_back(nCafe);
                map.addPoint(nCafe->getX(), nCafe->getY(), nCafe->getName(), 0);
            }
            else if (typeN == 2) {
                Canteen* nCanteen = new Canteen;
                nCanteen->loadFromFile(file);
                foodServices.push_back(nCanteen);
                map.addPoint(nCanteen->getX(), nCanteen->getY(), nCanteen->getName(), 0);
            }
            else if (typeN == 3) {
                Restaraunt* nRest = new Restaraunt;
                nRest->loadFromFile(file);
                foodServices.push_back(nRest);
                map.addPoint(nRest->getX(), nRest->getY(), nRest->getName(), 0);
            }
        }
    }
    file.close();
}

void FoodService::loadFoodServicesFromFile(ifstream& file)
{
    int typeN, sizeN;
    file >> sizeN;
    //cout << sizeN << endl;
    for (int i = 0; i < sizeN; i++) {
        file >> typeN;
        if (typeN == 1) {
            //foodServices.push_back(new Cafe);
            Cafe* nCafe = new Cafe;
            nCafe->loadFromFile(file);
            //foodServices[i]->loadFromFile(file);
            foodServices.push_back(nCafe);
            //map.addPoint(nCafe->getX(), nCafe->getY(), nCafe->getName(), 0);
        }
        else if (typeN == 2) {
            Canteen* nCanteen = new Canteen;
            nCanteen->loadFromFile(file);
            foodServices.push_back(nCanteen);
            //map.addPoint(nCanteen->getX(), nCanteen->getY(), nCanteen->getName(), 0);
        }
        else if (typeN == 3) {
            Restaraunt* nRest = new Restaraunt;
            nRest->loadFromFile(file);
            foodServices.push_back(nRest);
            //map.addPoint(nRest->getX(), nRest->getY(), nRest->getName(), 0);
        }
    }
}

Food* FoodService::returnFoodService(int index)
{
    return foodServices[index];
}
