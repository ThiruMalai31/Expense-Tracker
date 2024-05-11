#include<iostream>
#include<vector>
using namespace std;

class Expenses{
	string companyName;
	string date;
	vector<int> totalAmount;
	
	
	public:
		Expenses(string name,string date,int amount){
			this->companyName=name;
			this->date=date;
			this->totalAmount.push_back(amount);
		}
		Expenses(){
		}
	setCompanyName(string name)
	{
		this->companyName=name;
	}
	string getCompanyName(){
		return companyName;
	}
	setDate(string date)
	{
		this->date=date;
	}
	string getDate(){
		return date;
	}
	setTotalAmount(int amount){
		this->totalAmount.push_back(amount);
	}
	vector<int> getTotalAmount(){
		return totalAmount;
	}
};
vector<Expenses>totalExpenses;
//int storedExpenses=0;
class ExpenseUtil{
	public:
	add(){
		string name,date;
		cout<<"Enter Company"<<endl;
		cin>>name;
		cout<<"Enter Date in DD-MM-YYYY Format"<<endl;
		cin>>date;
		int amount;
		cout<<"Enter Amount"<<endl;
		cin>>amount;
		int set=0;
		for(int i=0;i<totalExpenses.size();i++){
			if(totalExpenses[i].getCompanyName()==name && totalExpenses[i].getDate()==date){
				set=1;
				totalExpenses[i].setTotalAmount(amount);
			}
		}
		if(set==0){
			Expenses expense(name,date,amount);
			totalExpenses.push_back(expense);
		}
	}
	pay(){
		string name,startDate,endDate;
		cout<<"Enter Company"<<endl;
		cin>>name;
		cout<<"Enter Start Date in DD-MM-YYYY Format"<<endl;
		cin>>startDate;
		int date1=0,month1=0,year1=0,set=0,mul=1,amount=0;
		for(int i=startDate.length()-1;i>=0;i--){
			if(startDate[i]=='-'){
				set++;
				mul=1;
				continue;
			}
			if(set==0){
				year1+=mul*(startDate[i]-'0');
				mul*=10;
			}
			else if(set==1){
				month1+=mul*(startDate[i]-'0');
				mul*=10;
			}
			else if(set==2){
				date1+=mul*(startDate[i]-'0');
				mul*=10;
			}
		}
		cout<<date1<<" "<<month1<<" "<<year1<<endl;
		cout<<"Enter End Date in DD-MM-YYYY Format"<<endl;
		cin>>endDate;
			int date2=0,month2=0,year2=0;
			set=0,mul=1;
		for(int i=endDate.size()-1;i>=0;i--){
			if(endDate[i]=='-'){
				set++;
				mul=1;
				continue;
			}
			if(set==0){
				year2+=mul*(endDate[i]-'0');
				mul*=10;
			}
			else if(set==1){
				month2+=mul*(endDate[i]-'0');
				mul*=10;
			}
			else if(set==2){
				date2+=mul*(endDate[i]-'0');
				mul*=10;
			}
		}
		cout<<date2<<" "<<month2<<" "<<year2<<endl;
		for(int i=0;i<totalExpenses.size();i++){
			cout<<"sdbsb  "<<totalExpenses[i].getCompanyName()<<endl;
			if(totalExpenses[i].getCompanyName()==name ){
				cout<<"frr  "<<totalExpenses[i].getCompanyName()<<endl;
				
				
				int currentDate=0,currentMonth=0,currentYear=0;
			set=0,mul=1;
		for(int t=totalExpenses[i].getDate().size()-1;t>=0;t--){
			if(totalExpenses[i].getDate()[t]=='-'){
				set++;
				mul=1;
				continue;
			}
			if(set==0){
				currentYear+=mul*(totalExpenses[i].getDate()[t]-'0');
				mul*=10;
			}
			else if(set==1){
				currentMonth+=mul*(totalExpenses[i].getDate()[t]-'0');
				mul*=10;
			}
			else if(set==2){
				currentDate+=mul*(totalExpenses[i].getDate()[t]-'0');
				mul*=10;
			}
		}
		int exp,amo;
			cout<<currentDate<<" "<<currentMonth<<" "<<currentYear<<endl;
			cout<<"set  "<<(currentYear==year1) <<"  "<< (currentYear==year2) <<"  "<<(currentMonth==month1 && currentMonth==month2 ) << (currentDate>=date1 && currentDate<=date2)<<endl;
		if(currentYear>year1 && currentYear<year2){
			cout<<"11 "<<endl;
			for(int j=0;j<totalExpenses[i].getTotalAmount().size();j++ ){
				amount+=totalExpenses[i].getTotalAmount()[j];
			}
		}	
		if(currentYear==year1 && currentYear==year2){
			cout<<"222  "<<endl;
			if(currentMonth>month1 && currentMonth<month2){
			for(int j=0;j<totalExpenses[i].getTotalAmount().size();j++ ){
				amount+=totalExpenses[i].getTotalAmount()[j];
			}
		}
		}
			if((currentYear==year1) ){
				cout<<"sdgsdsggs"<<endl;
			if(((currentMonth==month1) && (currentMonth==month2 ))&& ((currentDate>=date1 )&& (currentDate<=date2))){
				cout<<"dffbdf"<<endl;
			for(int j=0;j<totalExpenses[i].getTotalAmount().size();j++ ){
				exp=i;
				amo=j;
				amount+=totalExpenses[i].getTotalAmount()[j];
			}
			}
		}		
				
				cout<<"Total Amount  "<<amount<<endl;
				cout<<"Press Y to Make Payment"<<endl;
				char c;
				cin>>c;
				if(c=='Y'){
					cout<<"Payment Successfull "<<endl;
					totalExpenses[exp].getTotalAmount()[amo]=0;
				}
//				int cnt=1;
//				for(int j=0;j<totalExpenses[i].getDate().size();j++){
//					cout<<cnt++<<" "<<totalExpenses[i].getTotalAmount()[j]<<endl;
//				}
//				cout<<"Select Any Amount To be Pay"<<endl;
//				int sel;
//				cin>>sel;
//				totalExpenses[i].getTotalAmount()[sel-1]=0;
//				cout<<"Amount Paid Successfully"<<endl;
			}
		}
	}
};

int main(){
	int operations;
	do{
	cout<<"1.Add Expenses"<<endl;
	cout<<"2.Pay For Expenses"<<endl;
	cout<<"3.Exit"<<endl;
	
	cout<<"Select Any Operations"<<endl;
	cin>>operations;
	ExpenseUtil expenses;
	switch(operations){
		case 1:
			expenses.add();
			break;
		case 2:
			expenses.pay();
			break;
	}
	}while(operations!=3);
}
