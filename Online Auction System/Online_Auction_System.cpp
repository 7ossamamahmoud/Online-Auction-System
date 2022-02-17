#include <iostream>
#include<string>
#include <stdlib.h>
using namespace std;
int Counter = 0;

int Items_Count = 0;

string Car_Count = "0";

string Fruit_Count = "0";

string Books_Count = "0";

string Clothes_Count = "0";

string Electronics_Count = "0";

string Opt_seller;
struct member 
{
    string name;
    int memberID;
    string email;
    int password;
    string address;
    int phone;
};
struct items
{
    int id;
    int number;
    int price;
    float rate;
    string category;
    string StartDate;
    string EndDate;
    bool status;

};
member MemberInfo(member mem) 
{
    cout << "########## Welcome to Our Online Auction System ##########" << endl;
    cout << "########## Sign UP ,Please! ##########" << endl;
    cout << "Enter your Name: " << endl;
    cin >> mem.name;
    cout << "Enter your ID" << endl;
    cin >> mem.memberID;
    cout << "Enter your Email: " << endl;
    cin >> mem.email;
    cout << "Enter your Password: " << endl;
    cin >> mem.password;
    cout << "Enter your Delivery address: " << endl;
    cin >> mem.address;
    cout << "Enter your Phone Number: " << endl;
    cin >> mem.phone;
    return mem;
}

void itemOption(items it, items itm[])  
{
    cout << "Enter item Number:" << endl;
    cin >> it.number;
    cout << "########## Choosr Item's Category ##########" << endl;
    cout << "########## For Car ,Press 1 ##########" << endl;
    cout << "########## For Fruit ,Press 2 ##########" << endl;
    cout << "########## For Clothes ,Press 3 ##########" << endl;
    cout << "########## For Books ,Press 4 ##########" << endl;
    cout << "########## For Electonics ,Press 5 ##########" << endl;
    int CategoryOptionNo;
    cin >> CategoryOptionNo;
    if (CategoryOptionNo == 1)
    {
        it.category = "Car";
    }
    else if (CategoryOptionNo == 2)
    {
        it.category = "Fruit";
    }
    else if (CategoryOptionNo == 3)
    {
        it.category = "Clothes";
    }
    else if (CategoryOptionNo == 4)
    {
        it.category = "Book";
    }
    else if (CategoryOptionNo == 5)
    {
        it.category = "Electronics";
    }


    cout << "Enter item Price: " << endl;
    cin >> it.price;
    cout << "Enter item Start Date:" << endl;
    cin >> it.StartDate;
    cout << "Enter item End Date" << endl;
    cin >> it.EndDate;
    cout << " Status : Available For Buying :)" << endl;
    it.status = true;
    itm[Items_Count] = it;
    Items_Count++;
}
void Online_Rating(int index, items i[])
{
    if (i->rate >= 3)
    {
        Counter = Counter++;
        cout << "Other Member Participating Point: " << Counter << endl;
    }
}
void Optimal_Selling(int index, items i[])   // make a report of the top category in respect of the monthly transactions
{
    if(i[index].category == "Car" && i[index].status == false)
    {
        Car_Count = Car_Count + "1";
    }
    if (i[index].category == "Fruit" && i[index].status == false  )
    {
        Fruit_Count = Fruit_Count + "1";
    }
    if (i[index].category == "Clothes" && i[index].status == false)
    {
        Clothes_Count = Clothes_Count + "1";
    }
    if (i[index].category == "Books" && i[index].status == false)
    {
        Books_Count = Books_Count + "1";
    }
    if (i[index].category == "Electronics" && i[index].status == false)
    {
        Electronics_Count = Electronics_Count + "1";
    }
}
void Ensure_Operation(int Ensuring, int index, items itm[])
{
    if (Ensuring == 1)
    {
        string comment;
        cout << "Process has been done & Item has been sold out :) " << endl;
        cout << "Please Do the Comming 3 Orders, Enter another member participating ID , Rate him & Write a Comment about him: " << endl;
        cin >> itm[index].rate;
        cin >> itm[index].id;
        cin >> comment;
        cout << "Your Comment about the another member: " << comment << endl;
        cout << "The Another member participating ID: " << itm[index].id << endl;
        cout << "The Another member participating Rate: " << itm[index].rate << endl;
        Online_Rating(index, itm);
        itm[index].status = false;
        Optimal_Selling(index, itm);
    }
}
int main()
{
    member m;
    MemberInfo(m);
    items it[50];
    while (true)
    {
        cout << "########## Welcome to Our Online Auction System ##########" << endl;
        cout << "########## Enter You Choice: ##########" << endl;
        cout << "Press 1, For Buyer Mode" << endl;
        cout << "Press 2, For Seller Mode " << endl;
        cout << "Press 3, For a Report of the top category in respect of the monthly transactions" << endl;
        cout << "Press 4, For Search by Category and price" << endl;
        cout << "Press 5, For Search by Category Only" << endl;
        cout << "Press 6, For Exit" << endl;
        int Option;
        cin >> Option;
        if (Option == 1)
        {
            for (int j = 0; j < Items_Count; j++)
            {
                
                cout << "item number :" << it[j].number << endl;
                cout << "item category :" << it[j].category << endl;
                cout << "Price is = :" << it[j].price << endl;
                cout << "Start Date is:" << it[j].StartDate << endl;
                cout << "End Date is:" << it[j].EndDate << endl;

                if (it[j].status == true)
                {
                    cout << "The item is Available now :) " << endl;
                }
                else
                {
                    cout << "The item has been sold out you can't make any processes on it :( " << endl;
                }
            }
            for (int j = 0; j < Items_Count; j++)
            {
                if (it[j].status == true)
                {
                    cout << "Enter item Number to buy it |Or| Press 0 to GO Back to Main Menu:" << endl;
                    int item_num;
                    cin >> item_num;
                    if (item_num == it[j].number)
                    {
                        cout << "Do you want to send request to buy it ? || Press 1 For Yes || Press 2 For Suggest Price || Press 3 For No: " << endl;
                        int order;
                        cin >> order;
                        if (order == 1)
                        {
                           
                            cout << "Your Request has been sent :) " << endl;
                            cout << "Seller, Do you confirm the Process ? --> Press 1 For Yes || Press 2 For No: " << endl;
                            int confirm;
                            cin >> confirm;
                            Ensure_Operation(confirm, j, it);
                        }
                        else if (order == 2)
                        {
                            
                            cout << "Enter the Price that suits you: " << endl;
                            int price;
                            cin >> price;
                            cout << "Seller, Do you confirm the Process ? --> Press 1 For Yes || Press 2 For No: " << endl;
                            int confirm;
                            cin >> confirm;
                            Ensure_Operation(confirm, j, it);
                        }
                    }
                    else if (item_num != it[j].number)
                    {
                        cout << "Invalid Item Number! :( " << endl;
                    }
                    else if (item_num == 0)
                    {
                        break;
                    }
                }
            }
        }
        else if (Option == 2)
        {
            
            while (true)
            {
                cout << "########## Welcome to Our Online Auction System ##########" << endl;
                cout << "Enter your Item Data, Please:" << endl;
                items v;
                itemOption(v, it);
                cout << "The Item has been added Successfully :) " << endl;
                cout << "Do you want to add another item ? --> Press 1 For Yes || Press 2 For No: " << endl;
                int ItemAdd;
                cin >> ItemAdd;
                if (ItemAdd == 2)
                {
                    MemberInfo(m);
                    break;
                }
            }
        }
        else if (Option == 3)
        {

            string Opt_Seller_arr[5] = { Car_Count,Fruit_Count,Clothes_Count,Books_Count,Electronics_Count };
            Opt_seller = Car_Count;
            int count = 1;
            for (int i = 0; i < 5; i++)
            {
                if (Opt_seller < Opt_Seller_arr[count])
                {
                    Opt_seller = Opt_Seller_arr[count];
                    count++;
                }
            }
            if (Opt_seller == Car_Count)
            {
                cout << "The Top Category in respect of the monthly transactions is a Car" << endl;
            }
            else if (Opt_seller == Fruit_Count)
            {
                cout << "The Top Category in respect of the monthly transactions is a Fruit" << endl;
            }
            else if (Opt_seller == Clothes_Count)
            {
                cout << "The Top Category in respect of the monthly transactions is a Clothes" << endl;
            }
            else if (Opt_seller == Books_Count)
            {
                cout << "The Top Category in respect of the monthly transactions is a Book" << endl;
            }
            else if (Opt_seller == Electronics_Count)
            {
                cout << "The Top Category in respect of the monthly transactions is a Electronics" << endl;
            }
        }
        else if (Option == 4)
        {
            int price;
            string category;
            int Itm_No;
            cout << "Enter Price: " << endl;
            cin >> price;
            cout << "Enter Category: " << endl;
            cin >> category;
            for (int j = 0; j < Items_Count; j++)
            {
                if (price != it[j].price && category != it[j].category)
                {
                    cout << " This item does NOT Exist :( " << endl;
                }
                //check the category and price is true or not
                else if (price == it[j].price && category == it[j].category)
                {
                    cout << "Item Number is: " << it[j].number << endl;
                    cout << "Item Category is:" << it[j].category << endl;
                    cout << "Price is: " << it[j].price << endl;
                    cout << "Item Start Date is: " << it[j].StartDate << endl;
                    cout << "Item End Date is: " << it[j].EndDate << endl;


                    cout << "Enter item Number to buy it |OR| Press 0 to GO Back to Main Menu: " << endl;
                    cin >> Itm_No;
                    for (int j = 0; j < Items_Count; j++)
                    {
                        // check the item number is true or not
                        if (Itm_No == it[j].number)
                        {
                            cout << "Do you want to send request to buy it ? || Press 1 For Yes || Press 2 For Suggest Price || Press 3 For No: " << endl;
                            int request;
                            cin >> request;
                            if (request == 1)
                            {
                                //user accept the price and he will buy directly
                                cout << "your Request has been Sent Successfully :) " << endl;
                                cout << "Seller, Do you confirm Operation ? --> Press 1 For Yes || Press 2 For No: " << endl;
                                int confirm;
                                cin >> confirm;
                                Ensure_Operation(confirm, j, it);
                            }
                            else if (request == 2)
                            {
                                // user suggest a suit price
                                cout << "Enter the Price that suits You: " << endl;
                                int price;
                                cin >> price;
                                cout << "Seller, Do you confirm the Process ? --> Press 1 For Yes || Press 2 For No: " << endl;
                                int confirm;
                                cin >> confirm;
                                Ensure_Operation(confirm, j, it);
                            }
                        }
                        else if (Itm_No != it[j].number)
                        {
                            cout << "Invalid Item Number :( " << endl;
                        }
                        else if (Itm_No == 0)
                        {
                            break;
                        }
                    }
                }
            }
        }
        else if (Option == 5)
        {
             string category;
             int ItmNo;
            cout << "Enter Category: " << endl;
            cin >> category;
            for (int j = 0; j < Items_Count; j++)
            {
                if (category != it[j].category)
                {
                    cout << "This Category does NOT Exist " << endl;

                }
                
                else if (category == it[j].category)
                {


                    cout << "Item Number is: " << it[j].number << endl;
                    cout << "Item Category is:" << it[j].category << endl;
                    cout << "Price is: " << it[j].price << endl;
                    cout << "Item Start Date is: " << it[j].StartDate << endl;
                    cout << "Item End Date is: " << it[j].EndDate << endl;
                    cout << "Enter item Number to buy it : " << endl;
                    
                    cin >> ItmNo;
                    for (int j = 0; j < Items_Count; j++)
                    {
                        if (ItmNo == it[j].number)
                        {
                           
                            cout << "Do you want to send request to buy it ? || Press 1 For Yes || Press 2 For Suggest Price || Press 3 For No: " << endl;
                            int ord;
                            cin >> ord;
                            if (ord == 1)
                            {
                               
                                cout << "your Request has been Sent Successfully :) " << endl;
                                cout << "Seller, Do you confirm the Process ? --> Press 1 For Yes || Press 2 For No: " << endl;
                                int confirm;
                                cin >> confirm;
                                Ensure_Operation(confirm, j, it);
                            }
                            else if (ord == 2)
                            {
                               
                                cout << "Enter the Price that suits You: " << endl;
                                int price;
                                cin >> price;
                                cout << "Seller, Do you confirm the Process ? --> Press 1 For Yes || Press 2 For No: " << endl;
                                int confirm;
                                cin >> confirm;
                                Ensure_Operation(confirm, j, it);
                            }
                            else if (ItmNo != it[j].number)
                            {
                                cout << "Invalid Item Number! :( " << endl;
                            }
                        }
                    }
                }
            }
        }
        else if (Option == 6)
        {
            break;
        }
    }
    return 0;
}
