/*Fatima Alobahi
 
 C++ contacts manager program. Implemneted the program using map(Binary search tree). Each contact has the following details: <first_name, last_name, phone_no, email>. The contact manager has the following features:
 - The user should be able to insert a new contact.
 - The user should be able to find an existing contact using first name.
 - The user should be able to delete or update old contacts using first name.
*/
#include <iostream>
#include <map>
using namespace std;

//data structure
struct contact
{
    string last_name;
    string phone_no;
    string email;
};
//variables declaration
string first_name;
string last_name;
string phone_no;
string email;

int main()
{
    //declaring contacts map
    map<string, contact> map_contact;
    int choice;
    while (true)
    {
        cout<<"Press |1|to insert a new contact "<<endl;
        cout<<"Press |2|to find an existing contact using first name "<<endl;
        cout<<"Press |3|to update old contacts using first name "<<endl;
        cout<<"Press |4|to delete "<<endl;
        cin>>choice;
        //while invalid input
        while(cin.fail()|| (choice!=1 && choice!=2&&choice!=3&& choice!=4))
        {
            cout<<"Invalid choice"<<endl;
            cin.clear();
            cin.ignore(100,'\n');
            cin>>choice;
        }
        //inserting a new contact
        if(choice==1)
        {
            contact contact_object;
            cout<<"Please enter your first name: "<<endl;
            cin>>first_name;
            cout<<"Please enter your last name: "<<endl;
            cin>>last_name;
            contact_object.last_name=last_name;
            cout<<"Please enter your phone number: "<<endl;
            cin>>phone_no;
            contact_object.phone_no=phone_no;
            cout<<"Please enter your E-mail address: "<<endl;
            cin>>email;
            contact_object.email=email;
            pair<string, contact> entry(first_name, contact_object);
            map_contact.insert(entry); //insertion was successful
        }
        //finding an existing contact
        if(choice==2)
        {
            string first_name;
            cout<<"Enter the first name of what you are looking for: "<<endl;
            cin>>first_name;
            //iterating through the map using first name
            map<string, contact>::iterator random = map_contact.find(first_name);
            cout<<"Last Name: "<<random->second.last_name <<endl;
            cout<<"Phone Number: "<< random->second.phone_no <<endl;
            cout<<"E-mail: "<<random->second.email <<endl;
        }
        //updating an existing contact
        if(choice==3)
        {
            string update_name;
            cout<<"Enter the first name of the contact you want to update? "<<endl;
            cin>>update_name;
            cout<<"Press |1| to update the last name: "<<endl;
            cout<<"Press |2| to update the E-mail adress: "<<endl;
            cout<<"Press |3| to update the phone number: "<<endl;
            int change;
            cin>>change;
            //while invalid input
            while(cin.fail()|| (change!=1 && change!=2&&change!=3))
            {
                cout<<"Invaild choice"<<endl;
                cin.clear();
                cin.ignore(100,'\n');
                cin>>change;
            }
            //updating last name
            if (change==1)
            {
                string last_name_change;
                cout<<"What do you want to update the last name to? "<<endl;
                cin>>last_name_change;
                map_contact.find(update_name)->second.last_name =last_name_change;
            }
            //updating E-mail
            if (change==2)
            {
                string email_change;
                cout<<"What do you want to update the E-mail to? "<<endl;
                cin>>email_change;
                map_contact.find(update_name)->second.email =
                email_change;
            }
            //updating phone number
            if (change==3)
            {
                string phone_change;
                cout<<"What do you want to update the phone number to? "<<endl;
                cin>>phone_change;
                map_contact.find(update_name)->second.phone_no =
                phone_change;
            }
        }
        //deleting a contact
        if (choice==4)
        {
            string delete_contact_first_name;
            cout<<"What is the first name of the contact you want to delete? "<<endl;
            cin>>delete_contact_first_name;
            map_contact.erase(map_contact.find(delete_contact_first_name));
            cout<<"Contact has been removed."<<endl;
        }
    }
    return 0;
}

