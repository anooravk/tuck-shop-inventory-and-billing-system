#include<iostream>
using namespace std;

struct items{
	string name;
	int code;
	int quantity;
	string category;
};

struct invoice{
	int pak;
	string month;
	float bill;
}invoiceObj[10];

void AddItems(){
	 more:
	int num;
	cout<<"how many items do you want to enter?";
	cin>>num;
	items itemsObj[num];
	for(int i=0;i<num;i++){
		cout<<"Enter the name of item?";
		cin>>itemsObj[i].name;
		cout<<"Enter the code of item?";
		cin>>itemsObj[i].code;
		cout<<"Enter the quantity of item?";
		cin>>itemsObj[i].quantity;
		cout<<"Enter the category of item?";
		cin>>itemsObj[i].category;
	}
	char moreItem;
	cout<<"do you want to add more items [y/n]?";
	cin>>moreItem;
	if(moreItem=='y'||moreItem=='Y'){
		goto more;
	} 
	cout<<"List of items added\n";
	for(int i=0;i<num;i++){
		cout<<"\nName of item : "<<itemsObj[i].name;
		cout<<"\nCode of item : "<<itemsObj[i].code;
		cout<<"\nQuantity of item : "<<itemsObj[i].quantity;
		cout<<"\nCategory of item : "<<itemsObj[i].category;
	}
	
}

void PurchaseItem(){
	string identifier,month;
	int quantity,pak,n;
	float bill=0.0,price;
	char moreItem;
	cout<<"Enter the pak?";
	cin>>pak;
	cout<<"Enter at position?";
	cin>>n;
	cout<<"Enter the month?";
	cin>>month;
	start:
	cout<<"Enter the name or code of item:";
	cin>>identifier;
	cout<<"Enter the price of item?";
	cin>>price;
	cout<<"Enter the quantity of item purchased:";
	cin>>quantity;
	bill=bill+(price*quantity);
	cout<<"do you want to buy more items [y/n]?";
	cin>>moreItem;
	if(moreItem=='y'||moreItem=='Y'){
		goto start;
	} 
	invoiceObj[n].pak=pak;
	invoiceObj[n].bill=bill;
	invoiceObj[n].month=month;
	cout<<"\nTotal bill : "<<bill;
}

void PakDivide(int num){
	int pak,items,people;
	float totalBill,dividedBill;
	char divideMore;
	string month;
	cout<<"Calculating pak divide of "<<num<<" people:";
	for(int i=0;i<num;i++){	
	cout<<"\nEnter Pak?";
	cin>>pak;
	invoiceObj[i].pak=pak;
	cout<<"Enter the number of items purchased :";
	cin>>items;
	cout<<"Enter the total bill?";
	cin>>totalBill;
	cout<<"Enter the month?";
	cin>>month;
	invoiceObj[i].month=month;
	divideAgain:
	cout<<"Divide the bill on how many people?";
	cin>>people;
	dividedBill=totalBill/people;
	invoiceObj[i].bill=dividedBill;
	cout<<"Divided bill is : "<<dividedBill<<" per person";
	cout<<"\nDivide more [y/n]?";
	cin>>divideMore;
	if(divideMore=='y'||divideMore=='Y'){
		goto divideAgain;
	}
}
}

void MonthlyInvoice(){
	checkAgain:
	int pak;
	string month;
	char checkMore;
	cout<<"Enter pak?";cin>>pak;
	cout<<"Enter month?";cin>>month;
	for(int i=0;i<10;i++){
	if(pak==invoiceObj[i].pak && month==invoiceObj[i].month){
		cout<<"Total bill : "<<invoiceObj[i].bill;
	} else{
	    cout<<"No result found :(";
	    return;
	}
	cout<<"\nCheck more [y/n]?";
	cin>>checkMore;
	if(checkMore=='y'||checkMore=='Y'){
		goto checkAgain;
	}
}
}
int main(){
	cout<<"\t\t\t\t******** WELCOME TO TUCK SHOP INVENTORY & BILLING SYSTEM **********\n";
	int choice;
	char checkMore;
	checkAgain:
	cout<<"\n1.Add item \n2.Purchase item \n3.PAK divide \n4.Monthly inovice \n5.Exit";
	cout<<"\nEnter your choice?";
	cin>>choice;
	switch(choice){
		case 1:
			AddItems();
			break;
		case 2:
			PurchaseItem();
			break;
		case 3:
			int n;
			cout<<"Compute pak divide of how many people?";
			cin>>n;
			PakDivide(n);
			break;
		case 4:
			MonthlyInvoice();
			break;
		default:
			return 0;
	}
	cout<<"\nGo back to main menu [y/n]?";
	cin>>checkMore;
	if(checkMore=='y'||checkMore=='Y'){
		goto checkAgain;
	}
}
