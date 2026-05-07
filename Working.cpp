//COLLEGE MANAGEMENT SYSTEM
//GROUP MEMBERS:
//TALHA SIDDIQUE(056)
//LAKHTE HASNAIN(065)
//RAMISH TARIQ (73)
//SHAHZAD AKRAM (88)
#include<iostream>
#include<fstream>
#include<stdio.h>
#include<conio.h> 
#include<string.h>
#include<windows.h>
#include<iomanip>
using namespace std;
class DataBase{
	protected:
		int choose;
		int cntq;
		int a=2;
	string studentinfo1[6];
	string studentinfo2[6];	
	double physicsmark[20];
	double englishmark[20];
	double chemistrymark[20];
	double mathmark[20];
	double biologymark[20];	
	string studentnames[25];  //STUDENT DATA ARRAY
	char studentattendence[25];	
	int studentpass[25];	
	int roll_no[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	string stud_attend[6][20];
	string teachername[7];
	int teacherpass[7];
	int n=20;
	
	public:
		DataBase(){
			
	}
};
class Student:public DataBase{
	protected:
	int nameindex;
	int NOS;	
	string namefind;
	int passfind;
	string createname;
	int createpass;
	public:
		void choose(){
			int choice;
		cout<<"\t\t\t------------------------------------------"<<endl;	
		cout<<"\t\t\t| S T U D E N T    L O G I N    M E N U  |"<<endl;
	    cout<<"\t\t\t------------------------------------------"<<endl;
			cout<<endl<<endl;
			cout<<"\t---------------------------------------"<<endl;			
			cout<<"\t| 1- If you Already Have an Account    |"<<endl;
			cout<<"\t| 2- If you Want to Forget Password    |"<<endl;
			cout<<"\t| 3- If you Want to Create New Account |"<<endl;
			cout<<"\t| 4- if you Want back in Homepage      |"<<endl;
			cout<<"\t---------------------------------------"<<endl;
			cin>>choice;
			while(!cin.good()){
				cout<<"Enter Valid Input of integer type 1-4 "<<endl;
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout<<"Enter Again :";
				cin>>choice;
			}
			switch(choice) {
				case 1:
					system("cls");
					Student::login();
					break;
				case 2:
				Student::forget();
				break;	
				case 3:
				system("cls");
				Student::createaccount();
				break;
				case 4:
				cntq=1;
				break;	
	default:
		system("cls");
		cout<<"Please Enter Valid Number \n";
		Student::choose();
		
}
		}
	
void createaccount(){
			int d;
			ifstream nos;
			nos.open("nos.txt");
			
			nos>>NOS;
			cout<<"Enter Name :\n";
			ifstream s1;
			s1.open("studentdata.txt");
			for(int i=0;i<NOS;i++){
				s1>>studentnames[i];
				s1>>studentpass[i];
			}
			int cnt69;
			
		cnt69=0;
	
			cin>>createname;
			for(int i=0;i<NOS;i++){
			if(createname==studentnames[i]){cnt69++;}}
			if(cnt69==1){
				cnt69=0;
				cout<<"This Name Already Exists Please Choose Another Name \n";
				Student::createaccount();
				
				}
			
			else{
			cout<<"Enter Password :\n";
			cin>>createpass;
			int pcnt1=0;
			while(!cin.good()){
				cout<<"Enter Valid Input of integer type 1-9 "<<endl;
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout<<"Enter Again :";
				cin>>createpass;
			}
			
			system("cls");
			cout<<"Congratulations(Account Created) !\n";
		    NOS=NOS+1;
		    ofstream s;
		    s.open("nos.txt");
		    s<<NOS;
		    nos.close();
		    s.close();
			ofstream a1;
			a1.open("studentdata.txt",ios::app);
			a1<<endl;
			a1<<createname<<"\t\t"<<createpass;
			a1.close();
			Student::choose();
			
			}
				
		}
	void forget(){
		int counter=0;
		int z;
		int i;
		int save;
		string forname;
		int forpass;
		ifstream a;
		a.open("studentdata.txt");
		for(int i=0;i<NOS;i++){
			a>>studentnames[i];
			a>>studentpass[i];
		}
		int c=0;
		cout<<"Enter User Name (press 't' to back login menu):\n";
		cin>>forname;
		if(forname=="t"){
		system("cls");
		Student::choose();
		}
		else
		for(int i=0;i<NOS;i++){
			if(forname==studentnames[i]){
				counter=1;
			}
		}
		if(counter==1){
				for(int i=0;i<1;i++){		
			cout<<"Enter new password :";
			cin>>forpass;
				while(!cin.good()){
				cout<<"Enter Valid Input of integer type 1-9 "<<endl;
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout<<"Enter Again :";
				cin>>forpass;
			}
			studentpass[i]=forpass;
			save=i;
			
		}}
		else
		{system("cls");
		cout<<"Please enter Valid User name :\n";
		Student::forget();
		
		}
		a.close();
	
	ofstream b1;
	b1.open("studentdata.txt",ios::in);
	for(int i=0;i<NOS;i++){
	b1<<studentnames[i]<<"\t\t"<<studentpass[i]<<endl;
	}
	b1.close();
	system("cls");
	cout<<"\t\t\tPassword forgotted Successfully !\n";
	Student::choose();
	}	
	
void login(){
	int cnt11;
	int cnt12;
  	ifstream student;
  	ifstream noofstudent;
	noofstudent.open("nos.txt");
	noofstudent>>NOS;
  	student.open("studentdata.txt");
  	for(int i=0;i<NOS;i++){
	student>>studentnames[i];
	student>>studentpass[i];
	
}
int cnt=0;
	
	
	cin.ignore();
		cout<<"Enter your user name :";
		do{

	 	int cnt1=0;
	 	getline(cin,namefind);
	 	for(int i=0;i<NOS;i++){
		 
	 	if(namefind==studentnames[i]){
					cnt++;
					nameindex=i;	
		 }
		 else{
		 	cnt1++;
		 }
	}
		 if(cnt1==NOS){
		 	cout<<"Enter a valid user name(A-Z) :";
		 	
		 }
	
}while(cnt!=1);
int pcnt=0;
if(cnt==1){
	cout<<"Enter Your Password :";
			
			do{
			int pcnt1=0;
			cin>>passfind;
			while(!cin.good()){
				cout<<"Enter Valid Input of integer type 1-9 "<<endl;
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout<<"Enter Again :";
				cin>>passfind;
			}
			   
				if(passfind==studentpass[nameindex]){		
							pcnt++;
							break;
				}
				else{
					
						cout<<"Wrong Password "<<endl;
					cout<<"Please Enter correct password ";

				}

				
		}while(pcnt!=1);
	}
		if(pcnt==1){system("cls");
		Student::StudentMenu();
		
		}
noofstudent.close();
}
	void StudentMenu(){
		int ch;
			cout<<"\t\t\t\t\t\t\t\tYou Have Successfully login ! "<<endl<<endl;
			cout<<char(2)<<":"<<studentnames[nameindex]<<endl;
			cout<<"\t\t\t\t\t\tWelcome "<<studentnames[nameindex]<<endl;
			cout<<endl;
			cout<<endl;
			cout<<"\t\t\t\t\t-----------------------------------"<<endl;
			cout<<"\t\t\t\t\t| S T U D E N T     S E C T I O N |"<<endl;
			cout<<"\t\t\t\t\t-----------------------------------"<<endl;
			cout<<"\t\t\t----------------------"<<endl;
			cout<<"\t\t\t| M A I N   M E N U  |"<<endl;
			cout<<"\t\t\t----------------------"<<endl;
			cout<<endl<<endl;
			cout<<"\t-----------------"<<endl;			
			cout<<"\t| 1- Courses    |"<<endl;
			cout<<"\t| 2- Fee status |"<<endl;
			cout<<"\t| 3- Time Table |"<<endl;
			cout<<"\t| 4- User Info  |"<<endl;
			cout<<"\t| 5- User LogOut|"<<endl;
			cout<<"\t-----------------"<<endl;
			cin>>ch;
			
			while(!cin.good()){
				cout<<"Enter Valid Input of integer type 1-9 "<<endl;
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout<<"Enter Again :";
				cin>>ch;
			}
	
			switch(ch) {
				case 1:
					system("cls");
					cout<<"\t\t\t\tYou Entered Courses Choice :"<<endl;
					Student::courses();
					break;	
					
				case 2:
					int choice;
				cout<<"Your fee status is :"<<"unchecked"<<endl;
				do{
				cout<<"To go back to user menu press 9"<<endl;
				cin>>choice;
					while(!cin.good()){
				cout<<"Enter Valid Input of integer type (9)"<<endl;
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout<<"Enter Again :";
				cin>>choice;
			}
				system("cls");
				if(choice==9){
					Student::StudentMenu();
				}
			}while(choice!=9);
				break;	
				case 3:
					int x;
					system("cls");
					cout<<"\n\nYou entered in time table :";
					Student::Time_Table();
					do{
					cout<<"Enter (9) Key To Go Back Main Menu:\n";
	                
	      			cin>> x;
					if(x==9){
					system("cls");
					Student::StudentMenu();}
				}while(x!=9);
					break;  
	            case 4:
	            		system("cls");
	            		int w;
					cout<<"\n\nYou entered in User info :\n\n";
					Student::info();
					do{
					cout<<"Press 9 to Main Menu \n";
					cin>>w;
					while(!cin.good()){
				cout<<"Enter Valid Input of integer type (9)"<<endl;
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout<<"Enter Again :";
				cin>>w;
			}
					if(w==9){
					system("cls");
					Student::StudentMenu();
					}}while(w!=9);
					break;
				case 5:
					system("cls");
					cout<<"\t\tLogout Successfully ! \n";
					Student::choose();
					break;
	default:
		system("cls");
		cout<<"You Enter invalid Number"<<endl;
		Student::StudentMenu();
}
			
			
			
	
			}
		
void info(){
		if(studentnames[nameindex]=="Talha"){
			ifstream s1;
			
			s1.open("talha.txt");
			for(int i=0;i<6;i++){
				s1>>studentinfo1[i];
				s1>>studentinfo2[i];			
			}
			
			for(int i=0;i<6;i++){
			cout<<studentinfo1[i]<<"\t\t"<<studentinfo2[i]<<endl;	
			}
			s1.close();
		}
		else
		if(studentnames[nameindex]=="Ramish"){
			ifstream s1;
			
			s1.open("ramish.txt");
			for(int i=0;i<6;i++){
				s1>>studentinfo1[i];
				s1>>studentinfo2[i];			
			}
			
			for(int i=0;i<6;i++){
			cout<<studentinfo1[i]<<"\t\t"<<studentinfo2[i]<<endl;	
			}
			s1.close();
		}
	else	
	if(studentnames[nameindex]=="ali"){
			ifstream s1;
			
			s1.open("ali.txt");
			for(int i=0;i<6;i++){
				s1>>studentinfo1[i];
				s1>>studentinfo2[i];			
			}
			
			for(int i=0;i<6;i++){
			cout<<studentinfo1[i]<<"\t\t"<<studentinfo2[i]<<endl;	
			}
			s1.close();
		}
		else
		if(studentnames[nameindex]=="hasnain"){
			ifstream s1;
			
			s1.open("hasnain.txt");
			for(int i=0;i<6;i++){
				s1>>studentinfo1[i];
				s1>>studentinfo2[i];			
			}
			
			for(int i=0;i<6;i++){
			cout<<studentinfo1[i]<<"\t\t"<<studentinfo2[i]<<endl;	
			}
			s1.close();
		}
		else
		if(studentnames[nameindex]=="Zain"){
			ifstream s1;
			
			s1.open("zain.txt");
			for(int i=0;i<6;i++){
				s1>>studentinfo1[i];
				s1>>studentinfo2[i];			
			}
			
			for(int i=0;i<6;i++){
			cout<<studentinfo1[i]<<"\t\t"<<studentinfo2[i]<<endl;	
			}
			s1.close();
		}
		else
		if(studentnames[nameindex]=="Saad"){
			ifstream s1;
			
			s1.open("saad.txt");
			for(int i=0;i<6;i++){
				s1>>studentinfo1[i];
				s1>>studentinfo2[i];			
			}
			
			for(int i=0;i<6;i++){
			cout<<studentinfo1[i]<<"\t\t"<<studentinfo2[i]<<endl;	
			}
			s1.close();
		}
		else
		if(studentnames[nameindex]=="Akram"){
			ifstream s1;
			
			s1.open("akram.txt");
			for(int i=0;i<6;i++){
				s1>>studentinfo1[i];
				s1>>studentinfo2[i];			
			}
			
			for(int i=0;i<6;i++){
			cout<<studentinfo1[i]<<"\t\t"<<studentinfo2[i]<<endl;	
			}
			s1.close();
		}
		else
		if(studentnames[nameindex]=="eshe"){
			ifstream s1;
			
			s1.open("esha.txt");
			for(int i=0;i<6;i++){
				s1>>studentinfo1[i];
				s1>>studentinfo2[i];			
			}
			
			for(int i=0;i<6;i++){
			cout<<studentinfo1[i]<<"\t\t"<<studentinfo2[i]<<endl;	
			}
			s1.close();
		}
		else
		if(studentnames[nameindex]=="Zunair"){
			ifstream s1;
			
			s1.open("zunair.txt");
			for(int i=0;i<6;i++){
				s1>>studentinfo1[i];
				s1>>studentinfo2[i];			
			}
			
			for(int i=0;i<6;i++){
			cout<<studentinfo1[i]<<"\t\t"<<studentinfo2[i]<<endl;	
			}
			s1.close();
		}
		else
		if(studentnames[nameindex]=="ayesha"){
			ifstream s1;
			
			s1.open("ayesha.txt");
			for(int i=0;i<6;i++){
				s1>>studentinfo1[i];
				s1>>studentinfo2[i];			
			}
			
			for(int i=0;i<6;i++){
			cout<<studentinfo1[i]<<"\t\t"<<studentinfo2[i]<<endl;	
			}
			s1.close();
		}
		else
		if(studentnames[nameindex]=="Emash"){
			ifstream s1;
			
			s1.open("emash.txt");
			for(int i=0;i<6;i++){
				s1>>studentinfo1[i];
				s1>>studentinfo2[i];			
			}
			
			for(int i=0;i<6;i++){
			cout<<studentinfo1[i]<<"\t\t"<<studentinfo2[i]<<endl;	
			}
			s1.close();
		}
		if(studentnames[nameindex]=="asif"){
			ifstream s1;
			
			s1.open("asif.txt");
			for(int i=0;i<6;i++){
				s1>>studentinfo1[i];
				s1>>studentinfo2[i];			
			}
			
			for(int i=0;i<6;i++){
			cout<<studentinfo1[i]<<"\t\t"<<studentinfo2[i]<<endl;	
			}
			s1.close();
		}
		else
		if(studentnames[nameindex]=="umer"){
			ifstream s1;
			
			s1.open("umer.txt");
			for(int i=0;i<6;i++){
				s1>>studentinfo1[i];
				s1>>studentinfo2[i];			
			}
			
			for(int i=0;i<6;i++){
			cout<<studentinfo1[i]<<"\t\t"<<studentinfo2[i]<<endl;	
			}
			s1.close();
		}
		else
		if(studentnames[nameindex]=="Anas"){
			ifstream s1;
			
			s1.open("anas.txt");
			for(int i=0;i<6;i++){
				s1>>studentinfo1[i];
				s1>>studentinfo2[i];			
			}
			
			for(int i=0;i<6;i++){
			cout<<studentinfo1[i]<<"\t\t"<<studentinfo2[i]<<endl;	
			}
			s1.close();
		}
		else
		if(studentnames[nameindex]=="Hassan"){
			ifstream s1;
			
			s1.open("hassan.txt");
			for(int i=0;i<5;i++){
				s1>>studentinfo1[i];
				s1>>studentinfo2[i];			
			}
			
			for(int i=0;i<6;i++){
			cout<<studentinfo1[i]<<"\t\t"<<studentinfo2[i]<<endl;	
			}
			s1.close();
		}
		else
		if(studentnames[nameindex]=="Hania"){
			ifstream s1;
			
			s1.open("hania.txt");
			for(int i=0;i<6;i++){
				s1>>studentinfo1[i];
				s1>>studentinfo2[i];			
			}
			
			for(int i=0;i<6;i++){
			cout<<studentinfo1[i]<<"\t\t"<<studentinfo2[i]<<endl;	
			}
			s1.close();
		}
		else
		if(studentnames[nameindex]=="Pakiza"){
			ifstream s1;
			
			s1.open("pakiza.txt");
			for(int i=0;i<6;i++){
				s1>>studentinfo1[i];
				s1>>studentinfo2[i];			
			}
			
			for(int i=0;i<6;i++){
			cout<<studentinfo1[i]<<"\t\t"<<studentinfo2[i]<<endl;	
			}
			s1.close();
		}
		else
		if(studentnames[nameindex]=="Khulood"){
			ifstream s1;
			
			s1.open("khulood.txt");
			for(int i=0;i<6;i++){
				s1>>studentinfo1[i];
				s1>>studentinfo2[i];			
			}
			
			for(int i=0;i<6;i++){
			cout<<studentinfo1[i]<<"\t\t"<<studentinfo2[i]<<endl;	
			}
			s1.close();
		}
		else
		if(studentnames[nameindex]=="Mani"){
			ifstream s1;
			
			s1.open("mani.txt");
			for(int i=0;i<6;i++){
				s1>>studentinfo1[i];
				s1>>studentinfo2[i];			
			}
			
			for(int i=0;i<6;i++){
			cout<<studentinfo1[i]<<"\t\t"<<studentinfo2[i]<<endl;	
			}
			s1.close();
		}
		else
		if(studentnames[nameindex]=="Umair"){
			ifstream s1;
			
			s1.open("umair.txt");
			for(int i=0;i<6;i++){
				s1>>studentinfo1[i];
				s1>>studentinfo2[i];			
			}
			
			for(int i=0;i<6;i++){
			cout<<studentinfo1[i]<<"\t\t"<<studentinfo2[i]<<endl;	
			}
			s1.close();
	}
	
	
}
void courses(){
			int choice1;
			int subject_choice;
	cout<<"\t\t\t\t-------------------------------"<<endl;		
	cout<<"\t\t\t\tS T U D E N T    C O U R S E S "<<endl;
	cout<<"\t\t\t\t-------------------------------"<<endl;
	cout<<"\t----------------------------"<<endl;
	cout<<"\t|  1- PHYSICS              |"<<endl;
	cout<<"\t|  2- CHEMISTRY            |"<<endl;
	cout<<"\t|  3- BIOLOGY              |"<<endl;
	cout<<"\t|  4- MATHEMATICS          |"<<endl;
	cout<<"\t|  5- English              |"<<endl;
	cout<<"\t|  6- Go back To Main menu |"<<endl;
	cout<<"\t----------------------------"<<endl;
	cout<<"\tSelect one of above :";
	cin>>choice1;
			
			
			while(!cin.good()){
				cout<<"Enter Valid Input of integer type 1-9 "<<endl;
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout<<"Enter Again :";
				cin>>choice1;
			}
	
	switch(choice1) {
	case 1:
	  cout<<"1-Grades:"<<endl;
	  cout<<"2-Subject Atendence:"<<endl;
	  
	  do{
	 cout<<"Select From ( 1 or 2 )>> ";
	  cin>>subject_choice;
			while(!cin.good()){
				cout<<"Enter Valid Input of integer type 1-9 "<<endl;
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout<<"Enter Again :";
				cin>>subject_choice;
			}		
	if(subject_choice==1 ||subject_choice==2){
	  if(subject_choice==1){cout<<"your Current Grade is "<<endl;
	  ifstream s1;
	  s1.open("physics.txt");
	  for(int i=0;i<n;i++){
	  	s1>>studentnames[i];
	  	s1>>physicsmark[i];
	  	if(studentnames[i]==studentnames[nameindex]){
	  		cout<<physicsmark[i]<<" /100"<<endl;
		  }
	  }
	  s1.close();
	  cout<<"Go Back To Menu(9):";
	  cin>>subject_choice;
			while(!cin.good()){
				cout<<"Enter Valid Input of integer type (9) "<<endl;
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout<<"Enter Again :";
				cin>>subject_choice;
			}
	
	  if(subject_choice==9){
	  system("cls");
	  Student::courses();}
	}
	else
	if(subject_choice==2){Student::attendence();
	cout<<"\n Go Back to Menu(9):";
	cin>>subject_choice;
			while(!cin.good()){
				cout<<"Enter Valid Input of integer type (9) "<<endl;
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout<<"Enter Again :";
				cin>>subject_choice;
			}
	
	if(subject_choice==9){
	system("cls");
	Student::courses();
	}
	}
}}
while(subject_choice!=1 ||subject_choice!=2);
	case 2:
		cout<<"1-Grades:"<<endl;
	  cout<<"2-Subject Atendence:"<<endl;
	  do{
	  cout<<"Select From ( 1 or 2 )>> ";
	  cin>>subject_choice;
	  		while(!cin.good()){
				cout<<"Enter Valid Input of integer type 1-2 "<<endl;
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout<<"Enter Again :";
				cin>>subject_choice;
			}
	if(subject_choice==1 ||subject_choice==2){
	  if(subject_choice==1){cout<<"your Current Grade is : "<<endl;
	    ifstream s1;
	  s1.open("chemistry.txt");
	  for(int i=0;i<n;i++){
	  	s1>>studentnames[i];
	  	s1>>chemistrymark[i];
	  	if(studentnames[i]==studentnames[nameindex]){
	  		cout<<chemistrymark[i]<<" /100"<<endl;
		  }
	  }
	  s1.close();
	  cout<<"Go Back To Menu(9):";
	  cin>>subject_choice;
	  		while(!cin.good()){
				cout<<"Enter Valid Input of integer type (9) "<<endl;
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout<<"Enter Again :";
				cin>>subject_choice;
			}
	
	  if(subject_choice==9){
	  system("cls");
	  Student::courses();}
	}
	else
	if(subject_choice==2){Student::attendence();
	cout<<"\n Go Back to Menu(9):";
	cin>>subject_choice;
			while(!cin.good()){
				cout<<"Enter Valid Input of integer type (9) "<<endl;
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout<<"Enter Again :";
				cin>>subject_choice;
			}
	
	if(subject_choice==9){
	system("cls");
	Student::courses();
	}
	}
	}}
while(subject_choice!=1 ||subject_choice!=2);
	case 3:
		cout<<"1-Grades:"<<endl;
	  cout<<"2-Subject Atendence:"<<endl;
	  do{
	  cout<<"Select From ( 1 or 2 )>> ";	
	  cin>>subject_choice;
			while(!cin.good()){
				cout<<"Enter Valid Input of integer type 1-2 "<<endl;
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout<<"Enter Again :";
				cin>>subject_choice;
			}
	if(subject_choice==1||subject_choice==2){
	  if(subject_choice==1){cout<<"your Current Grade is : "<<endl;
	    ifstream s1;
	  s1.open("biology.txt");
	  for(int i=0;i<n;i++){
	  	s1>>studentnames[i];
	  	s1>>biologymark[i];
	  	if(studentnames[i]==studentnames[nameindex]){
	  		cout<<biologymark[i]<<" /100"<<endl;
		  }
	  }
	  s1.close();
	  cout<<"Go Back To Menu(9):";
	  cin>>subject_choice;
	  		while(!cin.good()){
				cout<<"Enter Valid Input of integer type (9) "<<endl;
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout<<"Enter Again :";
				cin>>subject_choice;
			}
	
	  if(subject_choice==9){
	  system("cls");
	  Student::courses();}
	}
	else
	if(subject_choice==2){Student::attendence();
	cout<<"\n Go Back to Menu(9):";

	cin>>subject_choice;
			while(!cin.good()){
				cout<<"Enter Valid Input of integer type (9) "<<endl;
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout<<"Enter Again :";
				cin>>subject_choice;
			}
	
	if(subject_choice==9){
	system("cls");
	Student::courses();
	}
	}
	}}
while(subject_choice!=1 ||subject_choice!=2);
	case 4:
		cout<<"1-Grades:"<<endl;
	  cout<<"2-Subject Atendence:"<<endl;
	  do{
	  	cout<<"Select From ( 1 or 2 )>> ";
	  cin>>subject_choice;
	  		while(!cin.good()){
				cout<<"Enter Valid Input of integer type 1-2 "<<endl;
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout<<"Enter Again :";
				cin>>subject_choice;
			}
	if(subject_choice==1||subject_choice==2){
	  if(subject_choice==1){cout<<"your Current Grade is : "<<endl;
	    ifstream s1;
	  s1.open("math.txt");
	  for(int i=0;i<n;i++){
	  	s1>>studentnames[i];
	  	s1>>mathmark[i];
	  	if(studentnames[i]==studentnames[nameindex]){
	  		cout<<mathmark[i]<<" /100"<<endl;
		  }
	  }
	  s1.close();
	  cout<<"Go Back To Menu(9):";
	  cin>>subject_choice;
	  		while(!cin.good()){
				cout<<"Enter Valid Input of integer type (9) "<<endl;
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout<<"Enter Again :";
				cin>>subject_choice;
			}
	
	  if(subject_choice==9){
	  system("cls");
	  Student::courses();}
	}
	else
	if(subject_choice==2){Student::attendence();
	cout<<"\n Go Back to Menu(9):";
	cin>>subject_choice;
	if(subject_choice==9){
	system("cls");
	Student::courses();
	}
	}
	}}
while(subject_choice!=1 ||subject_choice!=2);
	case 5:
		cout<<"1-Grades:"<<endl;
	  cout<<"2-Subject Atendence:"<<endl;
	do{
		cout<<"Select From ( 1 or 2 )>> ";
	  cin>>subject_choice;
			while(!cin.good()){
				cout<<"Enter Valid Input of integer type (1-2) "<<endl;
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout<<"Enter Again :";
				cin>>subject_choice;
			}
	if(subject_choice==1||subject_choice==2){
	  if(subject_choice==1){cout<<"your Current Grade is : "<<endl;
	    ifstream s1;
	  s1.open("english.txt");
	  for(int i=0;i<n;i++){
	  	s1>>studentnames[i];
	  	s1>>englishmark[i];
	  	if(studentnames[i]==studentnames[nameindex]){
	  		cout<<englishmark[i]<<" /100"<<endl;
		  }
	  }
	  s1.close();
	  cout<<"Go Back To Menu(9):";
	
	  cin>>subject_choice;
			while(!cin.good()){
				cout<<"Enter Valid Input of integer type (9) "<<endl;
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout<<"Enter Again :";
				cin>>subject_choice;
			}
	
	  if(subject_choice==9){
	  system("cls");
	  Student::courses();}
	}
	else
	if(subject_choice==2){Student::attendence();
	cout<<"\n Go Back to Menu(9):";
	cin>>subject_choice;
			while(!cin.good()){
				cout<<"Enter Valid Input of integer type (9) "<<endl;
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout<<"Enter Again :";
				cin>>subject_choice;
			}
	
	if(subject_choice==9){
	system("cls");
	Student::courses();
	}
	}
	}}
while(subject_choice!=1 ||subject_choice!=2);
	case 6:
		system("cls");
		Student::StudentMenu();
		break;
	  	default:
	  		system("cls");
	  		cout<<"invalid Number \n";
	  		Student::StudentMenu();
}
}

void Time_Table(){
	cout<<"\t\t\t T I M E     T A B L E   "<<endl;
	cout<<"\t\t---------------------------------------------------------------------------------"<<endl;
	cout<<"\t\t|\t1\t|\t2\t|\t3\t|\t4\t|\t5\t|"<<endl;
	cout<<"-------------------------------------------------------------------------------------------------"<<endl;
	cout<<"|        "<<" \t| 8:45-9:30"<<" \t| 9:30-10:15"<<" \t| 10:15-11:00"<<" \t| 11:00-11:45"<<" \t| 11:45-12:30   |"<<endl;
    cout<<"-------------------------------------------------------------------------------------------------"<<endl;

    cout<<"| Monday  "<<" \t| Mr.Saleem"<<" \t| Mr.Anwar"<<" \t| Mr.Najeeb"<<" \t| Mr.Zafar"<<" \t| Mr.Sohail     |"<<endl;    
	cout<<"|\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|"<<endl;
    cout<<"|         "<<" \t| Maths    "<<" \t| Biology " <<"\t| Physics  "<<" \t| Chemistry"<<" \t| English       |"<<endl;
	cout<<"-------------------------------------------------------------------------------------------------"<<endl;    
    cout<<"| Tuesday  "<<" \t| Mr.Saleem"<<" \t| Mr.Anwar"<<" \t| Mr.Najeeb"<<" \t| Mr.Zafar"<<" \t| Mr.Sohail     |"<<endl;    
	cout<<"|\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|"<<endl;
    cout<<"|         "<<" \t| Maths    "<<" \t| Biology " <<"\t| Physics  "<<" \t| Chemistry"<<" \t| English       |"<<endl;    
 		cout<<"-------------------------------------------------------------------------------------------------"<<endl;    
    cout<<"| Wednessday  "<<" \t| Mr.Saleem"<<" \t| Mr.Anwar"<<" \t| Mr.Najeeb"<<" \t| Mr.Zafar"<<" \t| Mr.Sohail     |"<<endl;    
	cout<<"|\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|"<<endl;
    cout<<"|         "<<" \t| Maths    "<<" \t| Biology " <<"\t| Physics  "<<" \t| Chemistry"<<" \t| English       |"<<endl;    
 		cout<<"-------------------------------------------------------------------------------------------------"<<endl;    
    cout<<"| Thursday  "<<" \t| Mr.Saleem"<<" \t| Mr.Anwar"<<" \t| Mr.Najeeb"<<" \t| Mr.Zafar"<<" \t| Mr.Sohail     |"<<endl;    
	cout<<"|\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|"<<endl;
    cout<<"|         "<<" \t| Maths    "<<" \t| Biology " <<"\t| Physics  "<<" \t| Chemistry"<<" \t| English       |"<<endl;    
 		cout<<"-------------------------------------------------------------------------------------------------"<<endl;    
    cout<<"| Friday  "<<" \t| Mr.Saleem"<<" \t| Mr.Anwar"<<" \t| Mr.Najeeb"<<" \t| Mr.Zafar"<<" \t| Mr.Sohail     |"<<endl;    
	cout<<"|\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|"<<endl;
    cout<<"|         "<<" \t| Maths    "<<" \t| Biology " <<"\t| Physics  "<<" \t| Chemistry"<<" \t| English       |"<<endl;    
 	cout<<"-------------------------------------------------------------------------------------------------"<<endl;    
    cout<<"| Saturday  "<<" \t| Mr.Saleem"<<" \t| Mr.Anwar"<<" \t| Mr.Najeeb"<<" \t| Mr.Zafar"<<" \t| Mr.Sohail     |"<<endl;    
	cout<<"|\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|"<<endl;
    cout<<"|         "<<" \t| Maths    "<<" \t| Biology " <<"\t| Physics  "<<" \t| Chemistry"<<" \t| English       |"<<endl;    
	cout<<"-------------------------------------------------------------------------------------------------"<<endl; 
		   
    cout<<"| Sunday    "<<" \t|          "<<" \t|         "<<" \t|          "<<" \t|         "<<" \t|               |"<<endl;    
	cout<<"|\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|"<<endl;
    cout<<"|         "<<" \t| OFF    "<<" \t| OFF \t" <<"\t| OFF  "<<" \t| OFF\t"<<" \t| OFF           |"<<endl;    
    cout<<"-------------------------------------------------------------------------------------------------"<<endl; 
   	

}

	void attendence(){
		cout<<"\t\t\t\t\t\t\t\t\t-----------------------------------"<<endl;
		cout<<"\t\t\t\t\t\t\t\t\tA T T E N D E N C E  D E T A I L S"<<endl;
		cout<<"\t\t\t\t\t\t\t\t\t-----------------------------------"<<endl;
		cout<<"\t\t\t\t\t\t---\t\t\t\t----\t\t\t\t----------------"<<endl;
		cout<<"\t\t\t\t\t\tDAY\t\t\t\tDATE\t\t\t\tATTENDENCE MARK"<<endl;
		cout<<"\t\t\t\t\t\t---\t\t\t\t----\t\t\t\t----------------"<<endl;
		cout<<"\t\t(for Present=P,Absent=A)\n";
		cout<<"\t\t\t\t\t\tMONDAY       \t\t\t02-05-2018\t\t\t";
		ifstream s1;
		s1.open("monday.txt");
		for(int i=0;i<n+1;i++){
			s1>>studentnames[i];
			s1>>studentattendence[i];
			if(studentnames[i]==studentnames[nameindex]){
				cout<<studentattendence[i];
				break;
			}
		}
		s1.close();
		cout<<endl;
		cout<<"\t\t\t\t\t\tTUESDAY      \t\t\t02-05-2018\t\t\t";
			ifstream s2;
		s2.open("tuesday.txt");
		for(int i=0;i<n+1;i++){
			s2>>studentnames[i];
			s2>>studentattendence[i];
			if(studentnames[i]==studentnames[nameindex]){
				cout<<studentattendence[i];
				break;
			}
		}
		s2.close();
		cout<<endl;
		cout<<"\t\t\t\t\t\tWEDNESDAY    \t\t\t02-05-2018\t\t\t";
			ifstream s3;
		s3.open("wednesday.txt");
		for(int i=0;i<n+1;i++){
			s3>>studentnames[i];
			s3>>studentattendence[i];
			if(studentnames[i]==studentnames[nameindex]){
				cout<<studentattendence[i];
				break;
			}
		}
		s3.close();
		cout<<endl;
		cout<<"\t\t\t\t\t\tTHURSDAY     \t\t\t02-05-2018\t\t\t";
			ifstream s4;
		s4.open("thursday.txt");
		for(int i=0;i<n+1;i++){
			s4>>studentnames[i];
			s4>>studentattendence[i];
			if(studentnames[i]==studentnames[nameindex]){
				cout<<studentattendence[i];
				break;
			}
		}
		s4.close();
		cout<<endl;
		cout<<"\t\t\t\t\t\tFRIDAY       \t\t\t02-05-2018\t\t\t";
			ifstream s5;
		s5.open("friday.txt");
		for(int i=0;i<n+1;i++){
			s5>>studentnames[i];
			s5>>studentattendence[i];
			if(studentnames[i]==studentnames[nameindex]){
				cout<<studentattendence[i];
				break;
			}
		}
		s5.close();
		cout<<endl;
		cout<<"\t\t\t\t\t\tSATURDAY     \t\t\t02-05-2018\t\t\t";
			ifstream s6;
		s1.open("saturday.txt");
		for(int i=0;i<n+1;i++){
			s6>>studentnames[i];
			s6>>studentattendence[i];
			if(studentnames[i]==studentnames[nameindex]){
				cout<<studentattendence[i];
				break;
			}
		}
		s6.close();
		cout<<endl;
		
	}
	
};
class Teacher:public Student{
  	protected:
  		int NOT;
  		string tnamefind;
  		int tnamepass;
  		string tname;
  		int nameindex1;
		int tpass;
  		char nameFinder[50];
  		
  	public:
	void tchoose(){

			int choice;
		cout<<"\t\t\t------------------------------------------"<<endl;	
		cout<<"\t\t\t| T E A C H E R    L O G I N    M E N U  |"<<endl;
	    cout<<"\t\t\t------------------------------------------"<<endl;
			cout<<endl<<endl;
			cout<<"\t---------------------------------------"<<endl;			
			cout<<"\t| 1- If you Already Have an Account    |"<<endl;
			cout<<"\t| 2- If you Want to Forget Password    |"<<endl;
			cout<<"\t| 3- If you Want to Create New Account |"<<endl;
			cout<<"\t| 4- if you Want back in Homepage      |"<<endl;
			cout<<"\t---------------------------------------"<<endl;
			cin>>choice;
			while(!cin.good()){
				cout<<"Enter Valid Input of integer type 1-4 "<<endl;
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout<<"Enter Again :";
				cin>>choice;
			}
			switch(choice) {
				case 1:
					system("cls");
			       Teacher::tlogin();
					break;
				case 2:
				Teacher::tforget();
				break;	
				case 3:
				system("cls");
				Teacher::tcreateaccount();
				break;
				case 4:
				cntq=1;
				break;	
	default:
		system("cls");
		cout<<"Please Enter Valid number \n";
		Teacher::tchoose();
}
		}
		void tcreateaccount(){
			system("cls");
			ifstream s1;
			ifstream noT;
			noT.open("not.txt");
			noT>>NOT;
			ofstream S1;
			S1.open("not.txt");
			s1.open("teacherdata.txt");
			for(int i=0;i<NOT;i++){
				s1>>teachername[i];
				s1>>teacherpass[i];
			}
			cout<<"Enter Name :\n";
			
			
			int cnt69;
			
		cnt69=0;
	
			cin>>tname;
			for(int i=0;i<NOT;i++){
			if(tname==teachername[i]){cnt69++;}}
			if(cnt69==1){
				cnt69=0;
				cout<<"This Name Already Exists Please Choose Another Name \n";
				Teacher::tcreateaccount();
				
				}
			
			else{
			cout<<"Enter Password :\n";
			int pcnt1=0;
			cin>>tpass;
			while(!cin.good()){
				cout<<"Enter Valid Input of integer type 1-9 "<<endl;
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout<<"Enter Again :";
				cin>>tpass;
			}
			
			system("cls");
			cout<<"Congratulations(Account Created) !\n";
			NOT=NOT+1;
			S1<<NOT;
			noT.close();
			S1.close();
			s1.close();
			ofstream a1;
			a1.open("teacherdata.txt",ios::app);
			a1<<endl;
			a1<<tname<<"\t\t"<<tpass;
			a1.close();
			Teacher::tchoose();
			
			}
				
		}
	void tforget(){
		int counter=0;
		int z;
		int i;
		int save;
		string forname;
		int forpass;
		ifstream a;
		ifstream Z;
		Z.open("not.txt");
		Z>>NOT;
		a.open("teacherdata.txt");
		for(int i=0;i<NOT;i++){
			a>>teachername[i];
			a>>teacherpass[i];
		}
		int c=0;
		cout<<"Enter User Name (press 't' to back login menu):\n";
		cin>>forname;
		if(forname=="t"){
		system("cls");
		Teacher::tchoose();
		}
		else
		for(int i=0;i<NOT;i++){
			if(forname==teachername[i]){
				counter=1;
			}
		}
		if(counter==1){
				for(int i=0;i<1;i++){		
			cout<<"Enter new password :";
			cin>>forpass;
				while(!cin.good()){
				cout<<"Enter Valid Input of integer type 1-9 "<<endl;
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout<<"Enter Again :";
				cin>>forpass;
			}
			teacherpass[i]=forpass;
			save=i;
			
		}}
		else
		{system("cls");
		cout<<"Please enter Valid User name :\n";
		Teacher::tforget();
		
		}
		a.close();
        Z.close();
	ofstream b;
	b.open("teacherdata.txt",ios::in);
	for(int i=0;i<7;i++){
	b<<teachername[i]<<"\t\t"<<teacherpass[i]<<endl;
	}
	b.close();
	system("cls");
	cout<<"\t\tPassword forgotted !\n";
	Teacher::tchoose();
	}
	void showstudinfo(){
		string findnaam;
		int tec;
		ifstream studentre;
  	ifstream noofstudent;
	noofstudent.open("nos.txt");
	noofstudent>>NOS;
  	studentre.open("studentdata.txt");
  	for(int i=0;i<NOS;i++){
	studentre>>studentnames[i];
	studentre>>studentpass[i];
	
}
		int nameindexre;
		int cntre1=0;
		do{

	 	int cntre=0;
	 	cout<<"Enter the student name you want to check data of :";
	 	getline(cin.ignore(),findnaam);
	 	for(int i=0;i<NOS;i++){
		 
	 	if(findnaam==studentnames[i]){
					cntre1++;
					nameindexre=i;	
		 }
		 else{
		 	cntre++;
		 }
	}
		 if(cntre==NOS){
		 	cout<<"Enter a valid user name(A-Z) :";
		 	
		 }
	
}while(cntre1!=1);
				if(findnaam=="Talha"){
			ifstream s1;
			
			s1.open("talha.txt");
			for(int i=0;i<6;i++){
				s1>>studentinfo1[i];
				s1>>studentinfo2[i];			
			}
			
			for(int i=0;i<6;i++){
			cout<<studentinfo1[i]<<"\t\t"<<studentinfo2[i]<<endl;	
			}
			do{
				cout<<"Press 9 to Teacher Menu :\n";
				cin>>tec;
				while(!cin.good()){
				cout<<"Enter Valid Input of integer type 1-9 "<<endl;
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout<<"Enter Again :";
				cin>>tec;
			}
			}while(tec!=9);
			Teacher::TeacherMenu();
			s1.close();
		}
		else
		if(findnaam=="Ramish"){
			ifstream s1;
			
			s1.open("ramish.txt");
			for(int i=0;i<6;i++){
				s1>>studentinfo1[i];
				s1>>studentinfo2[i];			
			}
			
			for(int i=0;i<6;i++){
			cout<<studentinfo1[i]<<"\t\t"<<studentinfo2[i]<<endl;	
			}
			do{
				cout<<"Press 9 to Teacher Menu :\n";
				cin>>tec;
				while(!cin.good()){
				cout<<"Enter Valid Input of integer type 1-9 "<<endl;
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout<<"Enter Again :";
				cin>>tec;
			}
			}while(tec!=9);
			Teacher::TeacherMenu();
			s1.close();
		}
	else	
	if(findnaam=="ali"){
			ifstream s1;
			
			s1.open("ali.txt");
			for(int i=0;i<6;i++){
				s1>>studentinfo1[i];
				s1>>studentinfo2[i];			
			}
			
			for(int i=0;i<6;i++){
			cout<<studentinfo1[i]<<"\t\t"<<studentinfo2[i]<<endl;	
			}
			do{
				cout<<"Press 9 to Teacher Menu :\n";
				cin>>tec;
				while(!cin.good()){
				cout<<"Enter Valid Input of integer type 1-9 "<<endl;
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout<<"Enter Again :";
				cin>>tec;
			}
			}while(tec!=9);
			Teacher::TeacherMenu();
			s1.close();
		}
		else
		if(findnaam=="hasnain"){
			ifstream s1;
			
			s1.open("hasnain.txt");
			for(int i=0;i<6;i++){
				s1>>studentinfo1[i];
				s1>>studentinfo2[i];			
			}
			
			for(int i=0;i<6;i++){
			cout<<studentinfo1[i]<<"\t\t"<<studentinfo2[i]<<endl;	
			}
			do{
				cout<<"Press 9 to Teacher Menu :\n";
				cin>>tec;
				while(!cin.good()){
				cout<<"Enter Valid Input of integer type 1-9 "<<endl;
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout<<"Enter Again :";
				cin>>tec;
			}
			}while(tec!=9);
			Teacher::TeacherMenu();
			s1.close();
		}
		else
		if(findnaam=="Zain"){
			ifstream s1;
			
			s1.open("zain.txt");
			for(int i=0;i<6;i++){
				s1>>studentinfo1[i];
				s1>>studentinfo2[i];			
			}
			
			for(int i=0;i<6;i++){
			cout<<studentinfo1[i]<<"\t\t"<<studentinfo2[i]<<endl;	
			}
			do{
				cout<<"Press 9 to Teacher Menu :\n";
				cin>>tec;
				while(!cin.good()){
				cout<<"Enter Valid Input of integer type 1-9 "<<endl;
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout<<"Enter Again :";
				cin>>tec;
			}
			}while(tec!=9);
			Teacher::TeacherMenu();
			s1.close();
		}
		else
		if(findnaam=="Saad"){
			ifstream s1;
			
			s1.open("saad.txt");
			for(int i=0;i<6;i++){
				s1>>studentinfo1[i];
				s1>>studentinfo2[i];			
			}
			
			for(int i=0;i<6;i++){
			cout<<studentinfo1[i]<<"\t\t"<<studentinfo2[i]<<endl;	
			}
			do{
				cout<<"Press 9 to Teacher Menu :\n";
				cin>>tec;
				while(!cin.good()){
				cout<<"Enter Valid Input of integer type 1-9 "<<endl;
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout<<"Enter Again :";
				cin>>tec;
			}
			}while(tec!=9);
			Teacher::TeacherMenu();
			s1.close();
		}
		else
		if(findnaam=="Akram"){
			ifstream s1;
			
			s1.open("akram.txt");
			for(int i=0;i<6;i++){
				s1>>studentinfo1[i];
				s1>>studentinfo2[i];			
			}
			
			for(int i=0;i<6;i++){
			cout<<studentinfo1[i]<<"\t\t"<<studentinfo2[i]<<endl;	
			}
			do{
				cout<<"Press 9 to Teacher Menu :\n";
				cin>>tec;
				while(!cin.good()){
				cout<<"Enter Valid Input of integer type 1-9 "<<endl;
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout<<"Enter Again :";
				cin>>tec;
			}
			}while(tec!=9);
			Teacher::TeacherMenu();
			s1.close();
		}
		else
		if(findnaam=="eshe"){
			ifstream s1;
			
			s1.open("esha.txt");
			for(int i=0;i<6;i++){
				s1>>studentinfo1[i];
				s1>>studentinfo2[i];			
			}
			
			for(int i=0;i<6;i++){
			cout<<studentinfo1[i]<<"\t\t"<<studentinfo2[i]<<endl;	
			}
			do{
				cout<<"Press 9 to Teacher Menu :\n";
				cin>>tec;
				while(!cin.good()){
				cout<<"Enter Valid Input of integer type 1-9 "<<endl;
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout<<"Enter Again :";
				cin>>tec;
			}
			}while(tec!=9);
			Teacher::TeacherMenu();
			s1.close();
		}
		else
		if(findnaam=="Zunair"){
			ifstream s1;
			
			s1.open("zunair.txt");
			for(int i=0;i<6;i++){
				s1>>studentinfo1[i];
				s1>>studentinfo2[i];			
			}
			
			for(int i=0;i<6;i++){
			cout<<studentinfo1[i]<<"\t\t"<<studentinfo2[i]<<endl;	
			}
			do{
				cout<<"Press 9 to Teacher Menu :\n";
				cin>>tec;
				while(!cin.good()){
				cout<<"Enter Valid Input of integer type 1-9 "<<endl;
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout<<"Enter Again :";
				cin>>tec;
			}
			}while(tec!=9);
			Teacher::TeacherMenu();
			s1.close();
		}
		else
		if(findnaam=="ayesha"){
			ifstream s1;
			
			s1.open("ayesha.txt");
			for(int i=0;i<6;i++){
				s1>>studentinfo1[i];
				s1>>studentinfo2[i];			
			}
			
			for(int i=0;i<6;i++){
			cout<<studentinfo1[i]<<"\t\t"<<studentinfo2[i]<<endl;	
			}
			do{
				cout<<"Press 9 to Teacher Menu :\n";
				cin>>tec;
				while(!cin.good()){
				cout<<"Enter Valid Input of integer type 1-9 "<<endl;
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout<<"Enter Again :";
				cin>>tec;
			}
			}while(tec!=9);
			Teacher::TeacherMenu();
			s1.close();
		}
		else
		if(findnaam=="Emash"){
			ifstream s1;
			
			s1.open("emash.txt");
			for(int i=0;i<6;i++){
				s1>>studentinfo1[i];
				s1>>studentinfo2[i];			
			}
			
			for(int i=0;i<6;i++){
			cout<<studentinfo1[i]<<"\t\t"<<studentinfo2[i]<<endl;	
			}
			do{
				cout<<"Press 9 to Teacher Menu :\n";
				cin>>tec;
				while(!cin.good()){
				cout<<"Enter Valid Input of integer type 1-9 "<<endl;
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout<<"Enter Again :";
				cin>>tec;
			}
			}while(tec!=9);
			Teacher::TeacherMenu();
			s1.close();
		}
		if(findnaam=="asif"){
			ifstream s1;
			
			s1.open("asif.txt");
			for(int i=0;i<6;i++){
				s1>>studentinfo1[i];
				s1>>studentinfo2[i];			
			}
			
			for(int i=0;i<6;i++){
			cout<<studentinfo1[i]<<"\t\t"<<studentinfo2[i]<<endl;	
			}
			do{
				cout<<"Press 9 to Teacher Menu :\n";
				cin>>tec;
				while(!cin.good()){
				cout<<"Enter Valid Input of integer type 1-9 "<<endl;
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout<<"Enter Again :";
				cin>>tec;
			}
			}while(tec!=9);
			Teacher::TeacherMenu();
			s1.close();
		}
		else
		if(findnaam=="umer"){
			ifstream s1;
			
			s1.open("umer.txt");
			for(int i=0;i<6;i++){
				s1>>studentinfo1[i];
				s1>>studentinfo2[i];			
			}
			
			for(int i=0;i<6;i++){
			cout<<studentinfo1[i]<<"\t\t"<<studentinfo2[i]<<endl;	
			}
			do{
				cout<<"Press 9 to Teacher Menu :\n";
				cin>>tec;
				while(!cin.good()){
				cout<<"Enter Valid Input of integer type 1-9 "<<endl;
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout<<"Enter Again :";
				cin>>tec;
			}
			}while(tec!=9);
			Teacher::TeacherMenu();
			s1.close();
		}
		else
		if(findnaam=="Anas"){
			ifstream s1;
			
			s1.open("anas.txt");
			for(int i=0;i<6;i++){
				s1>>studentinfo1[i];
				s1>>studentinfo2[i];			
			}
			
			for(int i=0;i<6;i++){
			cout<<studentinfo1[i]<<"\t\t"<<studentinfo2[i]<<endl;	
			}
			do{
				cout<<"Press 9 to Teacher Menu :\n";
				cin>>tec;
				while(!cin.good()){
				cout<<"Enter Valid Input of integer type 1-9 "<<endl;
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout<<"Enter Again :";
				cin>>tec;
			}
			}while(tec!=9);
			Teacher::TeacherMenu();
			s1.close();
		}
		else
		if(findnaam=="Hassan"){
			ifstream s1;
			
			s1.open("hassan.txt");
			for(int i=0;i<5;i++){
				s1>>studentinfo1[i];
				s1>>studentinfo2[i];			
			}
			
			for(int i=0;i<6;i++){
			cout<<studentinfo1[i]<<"\t\t"<<studentinfo2[i]<<endl;	
			}
			do{
				cout<<"Press 9 to Teacher Menu :\n";
				cin>>tec;
				while(!cin.good()){
				cout<<"Enter Valid Input of integer type 1-9 "<<endl;
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout<<"Enter Again :";
				cin>>tec;
			}
			}while(tec!=9);
			Teacher::TeacherMenu();
			s1.close();
		}
		else
		if(findnaam=="Hania"){
			ifstream s1;
			
			s1.open("hania.txt");
			for(int i=0;i<6;i++){
				s1>>studentinfo1[i];
				s1>>studentinfo2[i];			
			}
			
			for(int i=0;i<6;i++){
			cout<<studentinfo1[i]<<"\t\t"<<studentinfo2[i]<<endl;	
			}
			do{
				cout<<"Press 9 to Teacher Menu :\n";
				cin>>tec;
				while(!cin.good()){
				cout<<"Enter Valid Input of integer type 1-9 "<<endl;
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout<<"Enter Again :";
				cin>>tec;
			}
			}while(tec!=9);
			Teacher::TeacherMenu();
			s1.close();
		}
		else
		if(findnaam=="Pakiza"){
			ifstream s1;
			
			s1.open("pakiza.txt");
			for(int i=0;i<6;i++){
				s1>>studentinfo1[i];
				s1>>studentinfo2[i];			
			}
			
			for(int i=0;i<6;i++){
			cout<<studentinfo1[i]<<"\t\t"<<studentinfo2[i]<<endl;	
			}
			do{
				cout<<"Press 9 to Teacher Menu :\n";
				cin>>tec;
				while(!cin.good()){
				cout<<"Enter Valid Input of integer type 1-9 "<<endl;
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout<<"Enter Again :";
				cin>>tec;
			}
			}while(tec!=9);
			Teacher::TeacherMenu();
			s1.close();
		}
		else
		if(findnaam=="Khulood"){
			ifstream s1;
			
			s1.open("khulood.txt");
			for(int i=0;i<6;i++){
				s1>>studentinfo1[i];
				s1>>studentinfo2[i];			
			}
			
			for(int i=0;i<6;i++){
			cout<<studentinfo1[i]<<"\t\t"<<studentinfo2[i]<<endl;	
			}
			do{
				cout<<"Press 9 to Teacher Menu :\n";
				cin>>tec;
				while(!cin.good()){
				cout<<"Enter Valid Input of integer type 1-9 "<<endl;
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout<<"Enter Again :";
				cin>>tec;
			}
			}while(tec!=9);
			Teacher::TeacherMenu();
			s1.close();
		}
		else
		if(findnaam=="Mani"){
			ifstream s1;
			
			s1.open("mani.txt");
			for(int i=0;i<6;i++){
				s1>>studentinfo1[i];
				s1>>studentinfo2[i];			
			}
			
			for(int i=0;i<6;i++){
			cout<<studentinfo1[i]<<"\t\t"<<studentinfo2[i]<<endl;	
			}
			do{
				cout<<"Press 9 to Teacher Menu :\n";
				cin>>tec;
				while(!cin.good()){
				cout<<"Enter Valid Input of integer type 1-9 "<<endl;
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout<<"Enter Again :";
				cin>>tec;
			}
			}while(tec!=9);
			Teacher::TeacherMenu();
			s1.close();
		}
		else
		if(findnaam=="Umair"){
			ifstream s1;
			
			s1.open("umair.txt");
			for(int i=0;i<6;i++){
				s1>>studentinfo1[i];
				s1>>studentinfo2[i];			
			}
			
			for(int i=0;i<6;i++){
			cout<<studentinfo1[i]<<"\t\t"<<studentinfo2[i]<<endl;	
			}
			do{
				cout<<"Press 9 to Teacher Menu :\n";
				cin>>tec;
				while(!cin.good()){
				cout<<"Enter Valid Input of integer type 1-9 "<<endl;
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout<<"Enter Again :";
				cin>>tec;
			}
			}while(tec!=9);
			Teacher::TeacherMenu();
			s1.close();
	}
	
	
	}
void tlogin(){
	system("cls");
	string tnamefind;
	int tpassfind;
	int cnt11;
	int cnt12;
		ifstream z;
		z.open("not.txt");
		z>>NOT;	
  	ifstream teacher;
  	teacher.open("teacherdata.txt",ios::app);
  	for(int i=0;i<NOT;i++){
	teacher>>teachername[i];
	teacher>>teacherpass[i];
	
}
int cnt2=0;
	cin.ignore();

		cout<<"Enter your user name :";
		do{
	
	 	int cnt1=0;
	 	getline(cin,tnamefind);
	 	for(int i=0;i<NOT;i++){
		 
	 	if(tnamefind==teachername[i]){
					cnt2++;
					nameindex1=i;	
		 }
		 else{
		 	cnt1++;
		 }
	}
		 if(cnt1==NOT){
		 	cout<<"Enter a valid user name(A-Z) :";
		 }
	
}while(cnt2!=1);
int pcnt=0;
if(cnt2==1){
	cout<<"Enter Your Password :";
			
			do{
			int pcnt1=0;
			cin>>tpassfind;
			while(!cin.good()){
				cout<<"Enter Valid Input of integer type 1-9 "<<endl;
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout<<"Enter Again :";
				cin>>tpassfind;
			}
			   
				if(tpassfind==teacherpass[nameindex1]){		
							pcnt++;
							break;
				}
				else{
					
						cout<<"Wrong Password "<<endl;
					cout<<"Please Enter correct password ";

				}

				
		}while(pcnt!=1);
	}
		if(pcnt==1){system("cls");
		Teacher::TeacherMenu();
		
		}
	
			
}
void Student_Attendence(){
	int daych;
	int cnt;
	cout<<"1-Monday"<<endl;
	cout<<"2-Tuesday"<<endl;
	cout<<"3-Wednesday"<<endl;
	cout<<"4-Thursday"<<endl;
	cout<<"5-Friday"<<endl;
	cout<<"6-Saturday"<<endl;
	cout<<"7-Teacher Menu"<<endl;
	cout<<"Select a day you want to check attendence of :";
	cin>>daych;
	//cws
	switch (daych){
		case 1:{
			ofstream a;
			a.open("monday.txt");
			ifstream s1;
			s1.open("studentdata.txt");
			for(int i=0;i<n+2;i++){
				s1>>studentnames[i];
				s1>>studentpass[i];
			}
			s1.close();
			cout<<"For present press 'P' , for absent press 'A'"<<endl;
			cout<<"\t\tDAY\tMONDAY"<<endl;
			cout<<"\t\tNAME\t\t\tAttendence"<<endl;
			int cnt;
			cin.ignore();
			for(int i=0;i<n+1;i++){
				cout<<"\t\t"<<studentnames[i]<<"\t\t\t";
				a<<"\t\t"<<studentnames[i]<<"\t\t\t";
					do{
				cnt=0;
				getline(cin,stud_attend[0][i]);
			
				if(stud_attend[0][i]=="P"||stud_attend[0][i]=="A"){
					cnt++;	
				}
				else{
					cout<<"invalid input enter again :"<<endl;
					cout<<studentnames[i]<<"\t\t\t";
				}
			}while(cnt!=1);
//				cin>>stud_attend[0][i];
				a<<stud_attend[0][i]<<endl;
				cout<<endl;
			}
		}
			system("cls");
			cout<<"\t\t\tAttendece marked Successfully !\n";
			Teacher::Student_Attendence();
			break;
		
		case 2:
			{
			ofstream a;
			a.open("tuesday.txt");
			ifstream s1;
			s1.open("studentdata.txt");
				for(int i=0;i<n+1;i++){
				s1>>studentnames[i];
			s1>>studentpass[i];
			}
			s1.close();
			cout<<"\t\tDAY\tTUESTDAY"<<endl;
			cout<<"\t\tNAME\t\t\tAttendence"<<endl;
		cin.ignore();
			for(int i=0;i<n+1;i++){
				cout<<"\t\t"<<studentnames[i]<<"\t\t\t";
				a<<"\t\t"<<studentnames[i]<<"\t\t\t";
			
				do{
				cnt=0;
				getline(cin,stud_attend[1][i]);
			
				if(stud_attend[1][i]=="P"||stud_attend[1][i]=="A"){
					cnt++;	
				}
				else{
					cout<<"invalid input enter again :"<<endl;
					cout<<studentnames[i]<<"\t\t\t";
				}
			}while(cnt!=1);
				a<<stud_attend[1][i]<<endl;
				cout<<endl;
			}
		}
			system("cls");
			cout<<"\t\t\tAttendece marked Successfully !\n";
			Teacher::Student_Attendence();
			break;
		
		case 3:{
			ofstream a;
			a.open("wednesday.txt");
				ifstream s1;
		s1.open("studentdata.txt");
				for(int i=0;i<n+1;i++){
				s1>>studentnames[i];
				s1>>studentpass[i];
			}
			s1.close();
			cout<<"\t\tDAY\tWEDNESDAY"<<endl;
			cout<<"\t\tNAME\t\t\tAttendence"<<endl;
					cin.ignore();

			for(int i=0;i<21;i++){
				cout<<"\t\t"<<studentnames[i]<<"\t\t\t";
				a<<"\t\t"<<studentnames[i]<<"\t\t\t";
				do{
				cnt=0;
				getline(cin,stud_attend[2][i]);
			
				if(stud_attend[2][i]=="P"||stud_attend[2][i]=="A"){
					cnt++;	
				}
				else{
					cout<<"invalid input enter again :"<<endl;
					cout<<studentnames[i]<<"\t\t\t";
				}
			}while(cnt!=1);
				a<<stud_attend[2][i]<<endl;
				cout<<endl;
			}
		}
		system("cls");
			cout<<"\t\t\tAttendece marked Successfully !\n";
			Teacher::Student_Attendence();
			break;
		
		case 4:
			{
			ofstream a;
			a.open("thursday.txt");
					ifstream s1;
			s1.open("studentdata.txt");
				for(int i=0;i<n+1;i++){
				s1>>studentnames[i];
				s1>>studentpass[i];
			}
			s1.close();
			cout<<"\t\tDAY\tTHURSDAY"<<endl;
			cout<<"\t\tNAME\t\t\tAttendence"<<endl;
					cin.ignore();

			for(int i=0;i<21;i++){
				cout<<"\t\t"<<studentnames[i]<<"\t\t\t";
				a<<"\t\t"<<studentnames[i]<<"\t\t\t";
				do{
				cnt=0;
				getline(cin,stud_attend[3][i]);
			
				if(stud_attend[3][i]=="P"||stud_attend[3][i]=="A"){
					cnt++;	
				}
				else{
					cout<<"invalid input enter again :"<<endl;
					cout<<studentnames[i]<<"\t\t\t";
				}
			}while(cnt!=1);
				a<<stud_attend[3][i]<<endl;
				cout<<endl;
			}
		}
			system("cls");
			cout<<"\t\t\tAttendece marked Successfully !\n";
			Teacher::Student_Attendence();
			break;
		
		case 5:
		{
			ofstream a;
			a.open("friday.txt");
					ifstream s1;
			s1.open("studentdata.txt");
				for(int i=0;i<n+1;i++){
				s1>>studentnames[i];
				s1>>studentpass[i];
			}
			s1.close();
			cout<<"\t\tDAY\tFRIDAY"<<endl;
			cout<<"\t\tNAME\t\t\tAttendence"<<endl;
					cin.ignore();
			for(int i=0;i<21;i++){
				cout<<"\t\t"<<studentnames[i]<<"\t\t\t";
				a<<"\t\t"<<studentnames[i]<<"\t\t\t";
				do{
				cnt=0;
				getline(cin,stud_attend[4][i]);
			
				if(stud_attend[4][i]=="P"||stud_attend[4][i]=="A"){
					cnt++;	
				}
				else{
					cout<<"invalid input enter again :"<<endl;
					cout<<studentnames[i]<<"\t\t\t";
				}
			}while(cnt!=1);
				a<<stud_attend[4][i]<<endl;
				cout<<endl;
			}
		}
			system("cls");
			cout<<"\t\t\tAttendece marked Successfully !\n";
			Teacher::Student_Attendence();
			break;
		
		case 6:
			{
			ofstream a;
			a.open("saturday.txt");
					ifstream s1;
			s1.open("studentdata.txt");
				for(int i=0;i<n+1;i++){
				s1>>studentnames[i];
				s1>>studentpass[i];
			}
			s1.close();
			cout<<"\t\tDAY\tSATURDAY"<<endl;
			cout<<"\t\tNAME\t\t\tAttendence"<<endl;
					cin.ignore();
			for(int i=0;i<21;i++){
				cout<<"\t\t"<<studentnames[i]<<"\t\t\t";
				a<<"\t\t"<<studentnames[i]<<"\t\t\t";
				do{
				cnt=0;
				getline(cin,stud_attend[5][i]);
			
				if(stud_attend[5][i]=="P"||stud_attend[5][i]=="A"){
					cnt++;	
				}
				else{
					cout<<"invalid input enter again :"<<endl;
					cout<<studentnames[i]<<"\t\t\t";
				}
			}while(cnt!=1);
				a<<stud_attend[5][i]<<endl;
				cout<<endl;
			}
		}
		system("cls");
			cout<<"\t\t\tAttendece marked Successfully !\n";
			Teacher::Student_Attendence();
			break;
		
		case 7:
			system("cls");
			Teacher::TeacherMenu();
			break;
		default:
			system("cls");
			cout<<"please Enter valid Input\n";
			Teacher::Student_Attendence();
	}
}
void Teacher_atendence(){
	int man;
			cout<<"\t\t\t\tU S E R    A T E N D E N C E"<<endl;
		cout<<"\t\t\t\t\t\tDAY\t\t\t\tDATE\t\t\t\tATTENDENCE MARK"<<endl;
		cout<<"\t\t\t\t\t\tMONDAY       \t\t\t02-05-2018\t\t\t"<<endl;
		cout<<"\t\t\t\t\t\tTUESDAY      \t\t\t02-05-2018\t\t\t"<<endl;
		cout<<"\t\t\t\t\t\tWEDNESDAY    \t\t\t02-05-2018\t\t\t"<<endl;
		cout<<"\t\t\t\t\t\tTHURSDAY     \t\t\t02-05-2018\t\t\t"<<endl;
		cout<<"\t\t\t\t\t\tFRIDAY       \t\t\t02-05-2018\t\t\t"<<endl;
		cout<<"\t\t\t\t\t\tSATURDAY     \t\t\t02-05-2018\t\t\t"<<endl;
		cout<<"\t\t\t\t\t\tSUNDAY       \t\t\t02-05-2018\t\t\t"<<endl;
        cout<<"\n\nPress 9 To Go Back teacher Menu"<<endl;
        cin>>man;
        system("cls");
        if(man==9){Teacher::TeacherMenu();
		}
	}
	void physics(){
		
		cout<<"\t\t\tYou entered in Physics Subject"<<endl;
		ofstream a1;
		a1.open("physics.txt",ios::app);
		ifstream d;
		int c;
		d.open("physics.txt");
		cout<<"Press-1 to back menu \n";
		cout<<"Press-2 to Continue \n";
		cin>>c;
		if(c==1){
		system("cls");
		Teacher::student_grades();
		}
		else
		if(c==2){
		cout<<"Total Subject Mark(100)\n";
		cout<<"Student Name #\tMarks"<<endl;
		ifstream z;
		z.open("studentdata.txt");
		for(int i=0;i<n+1;i++){
			z>>studentnames[i];
			z>>studentpass[i];
		}
		for(int j=0;j<n+1;j++){
			cout<<studentnames[j]<<"\t";
			cin>>physicsmark[j];
			a1<<studentnames[j]<<"\t"<<physicsmark[j]<<endl;
		}
		system("cls");
		cout<<"\t\t\tMarked Successfully !\n";
		Teacher::student_grades();
		z.close();
		d.close();
		a1.close();
	}
}

void english(){
		
		cout<<"\t\t\tYou entered in English Subject"<<endl;
		ofstream a1;
		a1.open("english.txt",ios::app);
		ifstream d;
		int c;
		d.open("english.txt");
		cout<<"Press-1 to back menu \n";
		cout<<"Press-2 to Continue \n";
		cin>>c;
		if(c==1){
		system("cls");
		Teacher::student_grades();
		}
		else
		if(c==2){
		cout<<"Total Subject Mark(100)\n";
		cout<<"Student Name #\tMarks"<<endl;
		ifstream z;
		z.open("studentdata.txt");
		for(int i=0;i<n+1;i++){
			z>>studentnames[i];
			z>>studentpass[i];
		}
		for(int j=0;j<n+1;j++){
			cout<<studentnames[j]<<"\t";
			cin>>englishmark[j];
			a1<<studentnames[j]<<"\t"<<englishmark[j]<<endl;
		}
		system("cls");
		cout<<"\t\t\tMarked Successfully !\n";
		Teacher::student_grades();
		z.close();
		d.close();
		a1.close();
	}
}
void biology(){
		
		cout<<"\t\t\tYou entered in Biology Subject"<<endl;
		ofstream a1;
		a1.open("biology.txt",ios::app);
		ifstream d;
		int c;
		d.open("biology.txt");
		cout<<"Press-1 to back menu \n";
		cout<<"Press-2 to Continue \n";
		cin>>c;
		if(c==1){
		system("cls");
		Teacher::student_grades();
		}
		else
		if(c==2){
		cout<<"Total Subject Mark(100)\n";
		cout<<"Student Name #\tMarks"<<endl;
		ifstream z;
		z.open("studentdata.txt");
		for(int i=0;i<n+1;i++){
			z>>studentnames[i];
			z>>studentpass[i];
		}
		for(int j=0;j<n+1;j++){
			cout<<studentnames[j]<<"\t";
			cin>>biologymark[j];
			a1<<studentnames[j]<<"\t"<<biologymark[j]<<endl;
		}
		system("cls");
		cout<<"\t\t\tMarked Successfully !\n";
		Teacher::student_grades();
		z.close();
		d.close();
		a1.close();
	}
}
void chemistry(){
		
		cout<<"\t\t\tYou entered in Chemistry Subject"<<endl;
		ofstream a1;
		a1.open("chemistry.txt",ios::app);
		ifstream d;
		int c;
		d.open("chemistry.txt");
		cout<<"Press-1 to back menu \n";
		cout<<"Press-2 to Continue \n";
		cin>>c;
		if(c==1){
		system("cls");
		Teacher::student_grades();
		}
		else
		if(c==2){
		cout<<"Total Subject Mark(100)\n";
		cout<<"Student Name #\tMarks"<<endl;
		ifstream z;
		z.open("studentdata.txt");
		for(int i=0;i<n+1;i++){
			z>>studentnames[i];
			z>>studentpass[i];
		}
		for(int j=0;j<n+1;j++){
			cout<<studentnames[j]<<"\t";
			cin>>chemistrymark[j];
			a1<<studentnames[j]<<"\t"<<chemistrymark[j]<<endl;
		}
		system("cls");
		cout<<"\t\t\tMarked Successfully !\n";
		Teacher::student_grades();
		z.close();
		d.close();
		a1.close();
	}
}
void math(){
		
		cout<<"\t\t\tYou entered in Mathematics Subject"<<endl;
		ofstream a1;
		a1.open("math.txt",ios::app);
		ifstream d;
		int c;
		d.open("math.txt");
		cout<<"Press-1 to back menu \n";
		cout<<"Press-2 to Continue \n";
		cin>>c;
		if(c==1){system("cls");
		Teacher::student_grades();
		}
		else
		if(c==2){
		cout<<"Total Subject Mark(100)\n";
		cout<<"Student Name #\tMarks"<<endl;
		ifstream z;
		z.open("studentdata.txt");
		for(int i=0;i<n+1;i++){
			z>>studentnames[i];
			z>>studentpass[i];
		}
		for(int j=0;j<n+1;j++){
			cout<<studentnames[j]<<"\t";
			cin>>mathmark[j];
			a1<<studentnames[j]<<"\t"<<mathmark[j]<<endl;
		}
		system("cls");
		cout<<"\t\t\tMarked Successfully !\n";
		Teacher::student_grades();
		z.close();
		d.close();
		a1.close();
	}
}
	void student_grades(){
		int chaman;
	cout<<"\t\t\t\t----------------------------------------------------"<<endl;		
	cout<<"\t\t\t\tS T U D E N T     M I D T E R M S     G R A D E S  |"<<endl;
	cout<<"\t\t\t\t----------------------------------------------------"<<endl;
	cout<<"\t----------------------------"<<endl;
	cout<<"\t|  1- PHYSICS              |"<<endl;
	cout<<"\t|  2- CHEMISTRY            |"<<endl;
	cout<<"\t|  3- BIOLOGY              |"<<endl;
	cout<<"\t|  4- MATHEMATICS          |"<<endl;
	cout<<"\t|  5- English              |"<<endl;
	cout<<"\t|  6- Go back To Main menu |"<<endl;
	cout<<"\t----------------------------"<<endl;
	cout<<"\tSelect one of above :";
	cin>>chaman;
	while(!cin.good()){
				cout<<"\t\t\t\tEnter Valid Input of integer type 1-6 "<<endl;
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout<<"\t\t\t\tEnter Again :";
				cin>>chaman;
			}
		switch(chaman) {
			case 1:
				system("cls");
				Teacher::physics();
				break;
			case 2:
				system("cls");
				Teacher::chemistry();
				break;
			case 3:
				system("cls");
				Teacher::biology();
				break;		
			case 4:
				system("cls");
				Teacher::math();
				break;
			case 5:
				system("cls");
				Teacher::english();
				break;
			case 6:
			   system("cls");
			   Teacher::TeacherMenu();
			   break;			
	default:
		cout<<"Invalid Number\n";
		Teacher::student_grades();
}

		
	}  

	void TeacherMenu(){
		int choi;
		int ti;
			cout<<"\t\t\t\t\t\tWelcome "<<teachername[nameindex1]<<endl;
			cout<<char(2)<<":"<<teachername[nameindex1]<<endl;
			cout<<endl;
			cout<<endl;
			cout<<"\t\t\t----------------------"<<endl;
			cout<<"\t\t\t| M A I N   M E N U  |"<<endl;
			cout<<"\t\t\t----------------------"<<endl;
			cout<<endl<<endl;
			cout<<"\t\t\t\t\t-----------------------------------"<<endl;
			cout<<"\t\t\t\t\t| T E A C H E R     S E C T I O N |"<<endl;
			cout<<"\t\t\t\t\t-----------------------------------"<<endl;
			cout<<"\t-------------------------"<<endl;			
			cout<<"\t| 1- User Attendence    |"<<endl;
			cout<<"\t| 2- Student Attendence |"<<endl;
			cout<<"\t| 3- Time Table         |"<<endl;
			cout<<"\t| 4- User Info          |"<<endl;
			cout<<"\t| 5- User LogOut        |"<<endl;
			cout<<"\t| 6- Student Grades     |"<<endl;
			cout<<"\t| 7- Student Data	     |"<<endl;
			cout<<"\t-------------------------"<<endl<<"\t";
			cin>>choi;
			while(!cin.good()){
				cout<<"\t\t\t\tEnter Valid Input of integer type 1-7 "<<endl;
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout<<"\t\t\t\tEnter Again :";
				cin>>choi;
			}
		
		 switch(choi) {
		 	case 1:
		 		system("cls");
		 		cout<<"\t\You Entered in User Attendence "<<endl;
		 		Teacher::Teacher_atendence();
		 		break;
		 	case 2:
			 system("cls");
			 int m;
	         	cout<<"\t\You Entered in Student Attendece "<<endl;
	         	Teacher::Student_Attendence();
	         	system("cls");
	         	break;
	         case 3:
			 system("cls");
			 
			 	cout<<"\t\tYou Entered in User Time Table "<<endl;
			 	Teacher::Time_Table();
			 	
				 do{
			 	cout<<"Press 9 to go back User Menu ";	
					 cin>>ti;
					 	while(!cin.good()){
				cout<<"Enter Valid Input of integer type (9) "<<endl;
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout<<"Enter Again :";
				cin>>ti;
			}
					 system("cls"); 
	         	if(ti==9){Teacher::TeacherMenu();
				 }
			}while(ti!=9);
				 break;
			 case 4:
			 	system("cls");
			 cout<<"\t\tYou Entered in User Info"<<endl;
			 cout<<"Press 9 to go back User Menu ";	
					 cin>>m;
					 system("cls");
	         	if(m==9){Teacher::TeacherMenu();
				 }
				 break;	 
	         case 5:
	         	system("cls");
	         	cout<<"\t\t\t\tLog out Successfully !!"<<endl;
	         	Teacher::tchoose();
				 				 break;
			case 6:
			system("cls");
			Teacher::student_grades();
			break;	 				 
			case 7:
			system("cls");
			Teacher::showstudinfo();
			break;		 	
	default:
		system("cls");
		cout<<"Invalid input \n";
        cout<<"\t\tPlease enter Valid Input !\n";
        Teacher::TeacherMenu();
			}
	
}
			
		
		
	  	
  	
  };
class Dis:public Teacher{
	private:
		int choose;
	public:
		
	void display(){
    cout<<endl;
	cout<<"\t\t\t\t---------------------------------------------------------------------------------"<<endl;
	cout<<"\t\t\t\t|\t\t\t\t\t\t\t\t\t\t|"<<endl<<"\t\t\t\t|\t\t\t\t\t\t\t\t\t\t|"<<endl;
	cout<<"\t\t\t\t|\t--------------------------------------------------------------- \t|"<<endl;
	cout<<"\t\t\t\t|          C O L L E G E     M A N A G E M E N T     S Y S T E M \t\t|"<<endl;
	cout<<"\t\t\t\t|\t--------------------------------------------------------------- \t|"<<endl;
	cout<<"\t\t\t\t|\t\t\t\t\t\t\t\t\t\t|"<<endl<<"\t\t\t\t|\t\t\t\t\t\t\t\t\t\t|"<<endl<<"\t\t\t\t|\t\t\t\t\t\t\t\t\t\t|"<<endl<<"\t\t\t\t|\t\t\t\t\t\t\t\t\t\t|"<<endl;
	cout<<"\t\t\t\t|\t\t\t\t---------------\t\t\t\t\t|"<<endl;
	cout<<"\t\t\t\t|\t\t\t\t|  MAIN  MENU |\t\t\t\t\t|"<<endl;
	cout<<"\t\t\t\t|\t\t\t\t---------------\t\t\t\t\t|"<<endl;
	cout<<"\t\t\t\t|\t\t\t\t\t\t\t\t\t\t|"<<endl;
	cout<<"\t\t\t\t|\t ---------------------\t\t\t\t\t\t\t|"<<endl;
	cout<<"\t\t\t\t|\t | 1-Student Login   |\t\t\t\t\t\t\t|"<<endl;
	cout<<"\t\t\t\t|\t ---------------------\t\t\t\t\t\t\t|"<<endl;
	cout<<"\t\t\t\t|\t | 2-Teacher Login   |\t\t\t\t\t\t\t|"<<endl;
	cout<<"\t\t\t\t|\t ---------------------\t\t\t\t\t\t\t|"<<endl;
	cout<<"\t\t\t\t|\t | 3-Admin Login     |\t\t\t\t\t\t\t|"<<endl;
	cout<<"\t\t\t\t|\t ---------------------\t\t\t\t\t\t\t|"<<endl;
	cout<<"\t\t\t\t|\t | 4-Principal Login |\t\t\t\t\t\t\t|"<<endl;
	cout<<"\t\t\t\t|\t ---------------------\t\t\t\t\t\t\t|"<<endl;
	cout<<"\t\t\t\t|\t\t\t\t\t\t\t\t\t\t|"<<endl;
	cout<<"\t\t\t\t|\t\t\t\t\t\t\t\t\t\t|"<<endl;
	cout<<"\t\t\t\t|\t\t\t\t\t\t\t\t\t\t|"<<endl;
	cout<<"\t\t\t\t|\t\t\t\t\t\t\t\t\t\t|"<<endl;
	cout<<"\t\t\t\t---------------------------------------------------------------------------------"<<endl;
    cout<<"\t\t\t\tChoose one of them"<<endl;
    cout<<"\t\t\t\t-----------------------\n\t\t\t\t|--> ";
    cin>>choose;
     
    	while(!cin.good()){
				cout<<"\t\t\t\tEnter Valid Input of integer type 1-4 "<<endl;
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				
				cout<<"\t\t\t\tEnter Again :";
				cin>>choose;
			}		
			
			
    switch(choose) {
	case 1:
		system("cls");
		 cntq=0;
		cout<<"Welcome To Student login !"<<endl;
		Student::choose();
		if(cntq==1){system("cls");
		Dis::display();
		}
		break;
	case 2:
		system("cls");
		cntq=0;
		cout<<"Welcome To Teacher login !"<<endl;
		Teacher::tchoose();
		if(cntq==1){system("cls");
		Dis::display();
		}
		break;
	case 3:
		system("cls");
		cout<<"Welcome To Admin login !"<<endl;
		cout<<"Under Development \n";
		Dis::display();
		break;
	case 4:
		system("cls");
		cout<<"Welcome To Principal login !"<<endl;
		cout<<"Under Development \n";
		Dis::display();
		break;					
	default:
		system("cls");
		cout<<"\t\t\t\tInput not valid"<<endl;
		Dis::display();
	
	
}	
}
};


  









int main()
{   
   
system("color E4");
Dis a1;
a1.display();  
}

