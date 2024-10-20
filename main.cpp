// Banking System model using OOP Concepts
// Developed by Mazen Wael
// V1.1
// Modified : 1/13/24
#include <bits/stdc++.h>
using namespace std;
class AccountUsers{
private:
    string first_name;
    string last_name;
    int balance;
    static int acc_num;

public:
    AccountUsers(string fn = "N/A",string ln = "N/A", int bl = 0){
        first_name = fn;
        last_name = ln;
        balance = bl;
        acc_num++;
    }
    string Getfstname() const {
        return first_name;
    }
    string Getlsttname()const{
        return last_name;
    }

    int GetBalance()const{
        return balance;
    }

    friend void Deposit(AccountUsers& other,int add);

   friend ostream& operator<<(ostream& COUT,const AccountUsers& other){
        COUT << "First name: " << other.first_name << endl;
        COUT << "Last name: " << other.last_name << endl;
        COUT << "Balance: " << other.balance << endl;
        cout << endl;
        return COUT;
    }



};
 bool CompareByBalance(const AccountUsers& u1,const AccountUsers& u2){
        return u1.GetBalance() < u2.GetBalance();
    }
void Deposit(AccountUsers& other,int add){
    other.balance+=add;
}
int AccountUsers::acc_num = 0;
int main()
{
    vector<AccountUsers> Users;
    bool flag = 1;
    cout << "****Banking System****";
    cout << endl << endl;
    cout << "Select an option below:" << endl;
    cout <<" 1 Open an account " << endl;
    cout <<" 2 Balance Enquiry " << endl;
    cout <<" 3 Deposit " << endl;
    cout <<" 4 Withdrawal " << endl;
    cout <<" 5 Close an account " << endl;
    cout <<" 6 Show all accounts " << endl;
    cout <<" 7 Quit " << endl;
    cout << " 8 sort all accounts by balance" << endl;
     while(flag){
     char op;
    cout << "Enter your choice:";
    cin >> op;
    if(op == '1') {
        string fstname;
        string lstname;
        int balalce;
        cout << "Enter first name: ";
        cin >> fstname;
        cout << endl;
        cout << "Enter last name: ";
        cin >> lstname;
        cout << endl;
        cout << "Enter initial balance: ";
        cin >> balalce;
        cout << endl;
         AccountUsers account(fstname,lstname,balalce);
         Users.push_back(account);
         cout << "Congrats Account is created!" << endl;
         cout << account << endl;

}
else if(op == '2'){
    int cnt = 1;
    int ch;
    cout << "Enter Account Number: " << endl;
    cin >> ch;
    for(auto user : Users){
        if(cnt == ch ){
                cout << "Your Account Details: " << endl;
            cout << user;
        }
        cnt++;
    }
}
else if(op == '3'){
    int cnt = 1;
    int ch;
    int B;
    cout << "Enter Account Number: " << endl;
    cin >> ch;
    cout << "Enter Balance: " << endl;
    cin >> B;
    for(auto user : Users){
        if(cnt == ch ){
            cout << "Amount is Deposited" << endl;
            Deposit(user,B);
            cout << user;
        }
        cnt++;
    }
}
    else if(op == '7'){
    flag = 0;

}
else if(op == '5'){
    int cnt = 1;
    int ch;
    cout << "Enter Account Number: " << endl;
    cin >> ch;
    for(auto user : Users){
        if(cnt == ch ){
            cout << user;
            cout << "Account is closed" << endl;
        }
        cnt++;
    }
}
else if(op == '6'){
    int cnt = 1;
for(auto user:Users){
        cout << "Account " << cnt << endl;
    cout << user << endl;
cnt++;
}
}
else if(op == '8'){
    cout << "Users Accounts sorted by balance: " << endl;
    sort(Users.begin(),Users.end(),CompareByBalance);
    for(auto user: Users){
        cout << user;
    }
}
     }
     cout << "Thank You For Your Cooperation!" << endl;
}
