#include "D:\Embeded_T10\ADVANCED CC++ ALGORITHM T122023_BT\B6_RestaurantManagement\RestaurantManagement\Header\management.hpp"

/*
Funtion Name: oder
Function description : oder food in list food
Input parameters: ManageDish listD
Output:  NONE
*/
void Table::oder(ManageDish listD){
	Dish Oder = listD.dish();
	array.push_back(Oder);
    SUCCESSFULl 
}

/*
Funtion Name: display
Function description : show list oder
Input parameters: NONE
Output:  NONE
*/
void Table::display() {
    if (array.empty()) {
        FAIL
    } else {
        cout << "Dish List:" << endl;
        for ( auto& dish : array) {
            dish.displayInfo();
        }
    }
}

/*
Funtion Name: cancel
Function description : cancel the ordered item
Input parameters: NONE
Output:  NONE
*/
void Table::cancel(){
    display();
    SEARCHID
    auto it = array.begin();
    while (it != array.end()) {
        if (it->getId() == id) {
            it = array.erase(it);
            SUCCESSFULl
            return;
        } else {
            ++it;
        }
    }
	FAIL
}

/*
Funtion Name: change
Function description : change the ordered item
Input parameters: NONE
Output:  NONE
*/
void Table::change(ManageDish listD){
    display();
    SEARCHID
    auto it = array.begin();
    while (it != array.end()) {
        if (it->getId() == id) {
            Dish Oder = listD.dish();
            *it = Oder;
            SUCCESSFULl
            return;
        } else {
            ++it;
        }
    }
	FAIL   
}

/*
Funtion Name: pay
Function description : pay the bill
Input parameters: NONE
Output:  NONE
*/
void Table::pay(){
    int money = 0;
    auto it = array.begin();
    while (it != array.end()){
        money += it->getPrice();
        it->displayInfo();
        ++it;
    }
    cout<<"Total:  "<<money<<" VND"<<endl;
}

/*
Funtion Name: setStatus
Function description : status settings
Input parameters: status
Output:  NONE
*/
void Table::setStatus(bool bStatus){
    status = bStatus;
}

/*
Funtion Name: getStatus
Function description : get status table
Input parameters: NONE
Output:  NONE
*/
string Table::getStatus(){
   if(status){
        return "x";
   }
   return "O";
}

/*
Funtion Name: resizeArray
Function description : set up table number
Input parameters: table number
Output:  NONE
*/
void Management::resizeArray(int newSize){
    myArray.resize(newSize);
    for (auto i : myArray){
        i.setStatus(false);
    }
}
void Management::displayTable(){
    int number = 0;
    system("clear");
    cout<< setw(20)<<left <<"Table Number:";
    for(auto i : myArray){
        cout<< setw(4)<<left <<number;
        number ++;
    }
    cout<<endl;
    cout<< setw(20)<<left <<"Status:";
    for ( auto i : myArray)
    { 
        cout<< setw(4)<<left <<i.getStatus();
    }
    cout<<endl;
    cout<<"X Busy"<<endl;
    cout<<"O Available"<<endl;
}
/*
Funtion Name: editTable
Function description : ordering function
Input parameters: table location, option, list food
Output:  NONE
*/
void Management::editTable(int num, int option,ManageDish listd){
    if (myArray.size() >= num) {
        switch (option)
        {
        case 1:
            myArray[num-1].oder(listd);
        case 2:
            myArray[num-1].cancel();
        case 3:
            myArray[num-1].change(listd);
        case 4:
            myArray[num-1].display();
        case 5:
            myArray[num-1].pay();
        default:
            break;
        }
    }
}