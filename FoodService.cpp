#include "FoodService.h"
#include <algorithm>
#include <string>
#include "Time.h"

FoodService::FoodService(string _name)
{
    setName(_name);
}

FoodService::~FoodService()
{
    for (int i = 0; i < foodServices.size(); i++) {
        delete foodServices[i];
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

void FoodService::addFoodService(Food* obj)
{
    foodServices.push_back(obj);
}

void FoodService::addFoodService()
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
        bool tmpBool;
        int n1, n2;
        string tmpStrAdd;
        Cafe* obj = new Cafe;
        cout << "Enter a name: " << endl;
        getline(cin, tmpStrAdd);
        obj->setName(tmpStrAdd);
        cout << "Enter an adress: " << endl;
        getline(cin, tmpStrAdd);
        obj->setAdress(tmpStrAdd);
        cout << "Enter a music genre: " << endl;
        getline(cin, tmpStrAdd);
        obj->setMusicGenre(tmpStrAdd);
        cout << "Enter a rating: ";
        cin >> n1;
        obj->setRating(n1);
        cout << "Enter a coordinates(x y): ";
        cin >> n1 >> n2;
        obj->changeCoordinates(n1, n2);
        cout << "Enter an opening time: ";
        cout << "Hours (24): ";
        cin >> n1;
        cout << "Minutes: ";
        cin >> n2;
        obj->setOpeningTime(Time_(n1, n2, 0, true));
        cout << "Enter a closing time: ";
        cout << "Hours (24): ";
        cin >> n1;
        cout << "Minutes: ";
        cin >> n2;
        obj->setClosingTime(Time_(n1, n2, 0, true));
        cout << "Availability of free wifi (1 - yes/0 - no): ";
        cin >> tmpBool;
        obj->setFreeWifi(tmpBool);
        cout << "The naiability of board games (1 - yes/0 - no): ";
        cin >> tmpBool;
        obj->setBoardGames(tmpBool);
        cout << "Pet friendly (1 - yes/0 - no): ";
        cin >> tmpBool;
        obj->setPetFriendly(tmpBool);
        foodServices.push_back(obj);
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

void FoodService::delFoodService()
{
    if (!foodServices.empty()) {
        int tmpInt;
        do {
            system("cls");
            cout << "Select which food service you want to delete:" << endl;
            for (int i = 0; i < foodServices.size(); i++) {
                cout << i + 1 << ". " << foodServices[i]->getName() << endl;
            }
            cout << "Your choice: ";
            cin >> tmpInt;
        } while (!(tmpInt >= 1 && tmpInt <= foodServices.size()));
        foodServices.erase(foodServices.begin() + (tmpInt - 1));
        cout << "\nSuccessfully deleted!" << endl;
        return;
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

void FoodService::edit()
{
    int num;
    if (foodServices.empty()) cout << "There are no establishments to edit them!" << endl;
    else {
        do {
            system("cls");
            cout << "=========================== FOOD CONTROL ===========================" << endl;
            cout << "1. Show all establishments\n2. Add new establishments\n3. Delete establishments\n";
            cout << "4. Edit establishment\n5. Search for establishments\n6. Sort establishments\n";
            cin >> num;
            switch (num)
            {
            case 1:
                showFoodServices();
                break;
            default:
                break;
            }
        } while (num != 0);
        /*cout << "Select which establishment you would like to edit:" << endl;
        do {
            system("cls");
            for (int i = 0; i < foodServices.size(); i++) {
                cout << i + 1 << foodServices[i]->getName() << endl;
            }
            cout << "Your choice: ";
            cin >> num;
            if (num != 0 && num <= foodServices.size() && num > 0) {
                foodServices[num - 1]->edit();
            }
        } while (num != 0);*/
    }
}

void FoodService::searchByName(string _name) const
{
    system("cls");
    for (int i = 0; i < foodServices.size(); i++) {
        if (foodServices[i]->getName() == _name) {
            foodServices[i]->showFoodService();
            return;
        }
    }
    cout << "Name search results: nothing found!" << endl;
}

void FoodService::searchByAdress(string _adress) const
{
    system("cls");
    for (int i = 0; i < foodServices.size(); i++) {
        if (foodServices[i]->getAdress() == _adress) {
            foodServices[i]->showFoodService();
            return;
        }
    }
    cout << "Adress search results: nothing found!" << endl;
}

void FoodService::searchByRating(int _ratingLow, int _ratingHigh) const
{
    system("cls");
    bool find = false;
    for (int i = 0; i < foodServices.size(); i++) {
        if (foodServices[i]->getRating() >= _ratingLow && foodServices[i]->getRating() <= _ratingHigh) {
            foodServices[i]->showFoodService();
            find = true;
        }
    }
    if (!find) cout << "Rating search results: nothing found!" << endl;
}

void FoodService::sortByRating() const
{
    system("cls");
    if (foodServices.empty()) cout << "There are no establishments to sort them out!" << endl;
    else if (foodServices.size() == 1) {
        cout << "There's only one available establishment: " << endl;
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
            tmpFoodServices[i]->showFoodService();
        }
        tmpFoodServices.clear();
    }
}

void FoodService::sortByOpeningTime() const
{
    system("cls");
    if (foodServices.empty()) cout << "There are no establishments to sort them out!" << endl;
    else if (foodServices.size() == 1) {
        cout << "There's only one available establishment: " << endl;
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
            tmpFoodServices[i]->showFoodService();
        }
        tmpFoodServices.clear();
    }
}

void FoodService::sortByClosingTime() const
{
    system("cls");
    if (foodServices.empty()) cout << "There are no establishments to sort them out!" << endl;
    else if (foodServices.size() == 1) {
        cout << "There's only one available establishment: " << endl;
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
            tmpFoodServices[i]->showFoodService();
        }
        tmpFoodServices.clear();
    }
}

void FoodService::showFoodServices() const
{
    system("cls");
    if (foodServices.empty()) {
        cout << "There are no establishments in the " << name << "!" << endl;
    }
    else {
        cout << "======================- " << name << " -======================" << endl;
        cout << "Average rating: " << calculateAverageRating() << endl;
        cout << "All " << getTotalFoodCount() << " establishments: " << endl;
        for (int i = 0; i < foodServices.size(); i++) {
            foodServices[i]->showFoodService();
        }
    }
}
