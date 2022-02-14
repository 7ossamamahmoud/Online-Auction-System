#include <iostream>
#include<string>
#include <stdlib.h>
using namespace std;
int counter_items = 0;
string counter_category_fruit = "0";
string counter_category_car = "0";
string counter_category_clothes = "0";
string counter_category_book = "0";
string counter_category_electorincs = "0";
int counter_point = 0;
string Best_seller;
struct member  //storing information of member
{
    int memberID;
    string email;
    string name;
    int password;
    string address;
    int phone;
};
member dataofmember(member s) // input data of member
{
    cout << "########## Welcome to Our Online Auction System ##########" << endl;
    cout << "########## Sign UP ,Please! ##########" << endl;
    cout << "Enter your ID" << endl;
    cin >> s.memberID;
    cout << "Enter your Email: " << endl;
    cin >> s.email;
    cout << "Enter your Name: " << endl;
    cin >> s.name;
    cout << "Enter your Password: " << endl;
    cin >> s.password;
    cout << "Enter your Delivery address: " << endl;
    cin >> s.address;
    cout << "Enter your Phone Number: " << endl;
    cin >> s.phone;
    return s;
}
struct items   // storing information of item
{
    int number;
    string category;
    int price;
    string startDate;
    string endDate;
    bool status;
    int id;
    float rate;
};
void item(items v, items i[])   //input information of item
{
    cout << "Enter item Number:" << endl;
    cin >> v.number;
    cout << "########## Choosr Item's Category ##########" << endl;
    cout << "########## For Car ,Press 1 ##########" << endl;
    cout << "########## For Fruit ,Press 2 ##########" << endl;
    cout << "########## For Clothes ,Press 3 ##########" << endl;
    cout << "########## For Books ,Press 4 ##########" << endl;
    cout << "########## For Electonics ,Press 5 ##########" << endl;
    int category_num;
    cin >> category_num;
    if (category_num == 1)
    {
        v.category = "Car";
    }
    else if (category_num == 2)
    {
        v.category = "Fruit";
    }
    else if (category_num == 3)
    {
        v.category = "Clothes";
    }
    else if (category_num == 4)
    {
        v.category = "Book";
    }
    else if (category_num == 5)
    {
        v.category = "Electronics";
    }
    cout << "Enter item Price: " << endl;
    cin >> v.price;
    cout << "Enter item Start Date:" << endl;
    cin >> v.startDate;
    cout << "Enter item End Date" << endl;
    cin >> v.endDate;
    v.status = true;
    cout << " Status : Available For Buying :)" << endl;
    i[counter_items] = v;
    counter_items++;
}
void best_seller(int z, items i[])   // make a report of the top category in respect of the monthly transactions
{
    if (i[z].status == false && i[z].category == "Car")
    {
        counter_category_car = counter_category_car + "1";
    }
    if (i[z].status == false && i[z].category == "Fruit")
    {
        counter_category_fruit = counter_category_fruit + "1";
    }
    if (i[z].status == false && i[z].category == "Clothes")
    {
        counter_category_clothes = counter_category_clothes + "1";
    }
    if (i[z].status == false && i[z].category == "Book")
    {
        counter_category_book = counter_category_book + "1";
    }
    if (i[z].status == false && i[z].category == "Electronics")
    {
        counter_category_electorincs = counter_category_electorincs + "1";
    }
}
void rates(int z, items i[])
{
    if (i->rate >= 3)
    {
        counter_point = counter_point++;
        cout << "Other Member Participating Point: " << counter_point << endl;
    }
}
void confirmation(int confirm, int z, items i[])
{
    if (confirm == 1)
    {
        string comment;
        cout << "Operation has been done :) " << endl;
        cout << "Item has been sold out " << endl;
        cout << "Please Do the Comming 3 Orders, Enter another member participating ID , Rate him & Write a comment about him: " << endl;
        cin >> i[z].id;
        cin >> i[z].rate;
        cin >> comment;
        cout << "The Another member participating ID: " << i[z].id << endl;
        cout << "The Another member participating Rate: " << i[z].rate << endl;
        cout << "Your Comment about the another member: " << comment << endl;
        rates(z, i);
        i[z].status = false;
        best_seller(z, i);
    }
}
int main()
{
    system("color F0");
    member s;
    dataofmember(s);
    items i[50];
    while (true)
    {
        // user choose mode
        cout << "########## Welcome to Our Online Auction System ##########" << endl;
        cout << "########## Enter You Choice: ##########" << endl;
        cout << "Press 1, For Buyer Mode" << endl;
        cout << "Press 2, For Seller Mode " << endl;
        cout << "Press 3, For a Report of the top category in respect of the monthly transactions" << endl;
        cout << "Press 4, For Search by Category and price" << endl;
        cout << "Press 5, For Search by Category Only" << endl;
        cout << "Press 6, For Exit" << endl;
        int mode;
        cin >> mode;
        if (mode == 1)
        {
            for (int z = 0; z < counter_items; z++)
            {
                // show the items for sale
                cout << "item number :" << i[z].number << endl;
                cout << "item category :" << i[z].category << endl;
                cout << "price :" << i[z].price << endl;
                cout << "start date :" << i[z].startDate << endl;
                cout << "end date :" << i[z].endDate << endl;
                if (i[z].status == true)
                {
                    cout << "The item is Available now :) " << endl;
                }
                else
                {
                    cout << "The item has been sold out you can't make any operation on it :( " << endl;
                }
            }
            for (int z = 0; z < counter_items; z++)
            {
                if (i[z].status == true)
                {
                    cout << "Enter item Number to buy it |Or| Press 0 to GO Back to Main Menu:" << endl;
                    int item_num;
                    cin >> item_num;
                    // check if item number is true or not
                    if (item_num == i[z].number)
                    {
                        cout << "Do you want to send request to buy it ? || Press 1 For Yes || Press 2 For Suggest Price || Press 3 For No: " << endl;
                        int request;
                        cin >> request;
                        if (request == 1)
                        {
                            //user accept the price and he will buy directly
                            cout << "Your Request has been sent :) " << endl;
                            cout << "Seller, Do you confirm Operation ? --> Press 1 For Yes || Press 2 For No: " << endl;
                            int confirm;
                            cin >> confirm;
                            confirmation(confirm, z, i);
                        }
                        else if (request == 2)
                        {
                            // user suggest a suit price
                            cout << "Enter the Price that suits you: " << endl;
                            int price;
                            cin >> price;
                            cout << "Seller, Do you confirm Operation ? --> Press 1 For Yes || Press 2 For No: " << endl;
                            int confirm;
                            cin >> confirm;
                            confirmation(confirm, z, i);
                        }
                    }
                    else if (item_num != i[z].number)
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
        else if (mode == 2)
        {
            // Enter the data of item which user want to sell it
            while (true)
            {
                cout << "########## Welcome to Our Online Auction System ##########" << endl;
                cout << "Enter your Item Data, Please:" << endl;
                items v;
                item(v, i);
                cout << "The Item has been added Successfully :) " << endl;
                cout << "Do you want to add another item ? --> Press 1 For Yes || Press 2 For No: " << endl;
                int addtion_item;
                cin >> addtion_item;
                if (addtion_item == 2)
                {
                    dataofmember(s);
                    break;
                }
            }
        }
        else if (mode == 3)
        {
            //a report of the top category in respect of the monthly transactions

            string Best_seller_array[5] = { counter_category_car,counter_category_fruit,counter_category_clothes,counter_category_book,counter_category_electorincs };
            Best_seller = counter_category_car;
            int x = 1;
            for (int i = 0; i < 5; i++)
            {
                if (Best_seller < Best_seller_array[x])
                {
                    Best_seller = Best_seller_array[x];
                    x++;
                }
            }
            if (Best_seller == counter_category_car)
            {
                cout << "The Top Category in respect of the monthly transactions is a Car" << endl;
            }
            else if (Best_seller == counter_category_fruit)
            {
                cout << "The Top Category in respect of the monthly transactions is a Fruit" << endl;
            }
            else if (Best_seller == counter_category_clothes)
            {
                cout << "The Top Category in respect of the monthly transactions is a Clothes" << endl;
            }
            else if (Best_seller == counter_category_book)
            {
                cout << "The Top Category in respect of the monthly transactions is a Book" << endl;
            }
            else if (Best_seller == counter_category_electorincs)
            {
                cout << "The Top Category in respect of the monthly transactions is a Electronics" << endl;
            }
        }
        else if (mode == 4)
        {
            //search via price and category
            cout << "Enter Price: " << endl;
            int price;
            cin >> price;
            cout << "Enter Category: " << endl;
            string category;
            cin >> category;
            for (int z = 0; z < counter_items; z++)
            {
                if (price != i[z].price && category != i[z].category)
                {
                    cout << " This item does NOT Exist :( " << endl;
                }
                //check the category and price is true or not
                else if (price == i[z].price && category == i[z].category)
                {
                    cout << "Item Number is: " << i[z].number << endl;
                    cout << "Item Category is:" << i[z].category << endl;
                    cout << "Price is: " << i[z].price << endl;
                    cout << "Item Start Date is: " << i[z].startDate << endl;
                    cout << "Item End Date is: " << i[z].endDate << endl;
                    cout << "Enter item Number to buy it |OR| Press 0 to GO Back to Main Menu: " << endl;
                    int item_num;
                    cin >> item_num;
                    for (int z = 0; z < counter_items; z++)
                    {
                        // check the item number is true or not
                        if (item_num == i[z].number)
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
                                confirmation(confirm, z, i);
                            }
                            else if (request == 2)
                            {
                                // user suggest a suit price
                                cout << "Enter the Price that suits You: " << endl;
                                int price;
                                cin >> price;
                                cout << "Seller, Do you confirm Operation ? --> Press 1 For Yes || Press 2 For No: " << endl;
                                int confirm;
                                cin >> confirm;
                                confirmation(confirm, z, i);
                            }
                        }
                        else if (item_num != i[z].number)
                        {
                            cout << "Invalid Item Number :( " << endl;
                        }
                        else if (item_num == 0)
                        {
                            break;
                        }
                    }
                }
            }
        }
        else if (mode == 5)
        {
            cout << "Enter Category: " << endl;
            string category;
            cin >> category;
            for (int z = 0; z < counter_items; z++)
            {
                if (category != i[z].category)
                {
                    cout << "This Category does NOT Exist " << endl;

                }
                // check if category is true or not
                else if (category == i[z].category)
                {


                    cout << "Item Number is: " << i[z].number << endl;
                    cout << "Item Category is:" << i[z].category << endl;
                    cout << "Price is: " << i[z].price << endl;
                    cout << "Item Start Date is: " << i[z].startDate << endl;
                    cout << "Item End Date is: " << i[z].endDate << endl;
                    cout << "Enter item Number to buy it : " << endl;
                    int item_num;
                    cin >> item_num;
                    for (int z = 0; z < counter_items; z++)
                    {
                        if (item_num == i[z].number)
                        {
                            // check if item number is true or not
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
                                confirmation(confirm, z, i);
                            }
                            else if (request == 2)
                            {
                                // user suggest a suit price
                                cout << "Enter the Price that suits You: " << endl;
                                int price;
                                cin >> price;
                                cout << "Seller, Do you confirm Operation ? --> Press 1 For Yes || Press 2 For No: " << endl;
                                int confirm;
                                cin >> confirm;
                                confirmation(confirm, z, i);
                            }
                            else if (item_num != i[z].number)
                            {
                                cout << "Invalid Item Number " << endl;
                            }
                        }
                    }
                }
            }
        }
        else if (mode == 6)
        {
            break;
        }
    }
    return 0;
}