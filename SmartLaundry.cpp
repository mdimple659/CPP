#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <limits.h>
#include <set>
#include <utility>
#include <vector>
#include <conio.h>
 
using namespace std;

string dayName[]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
 
class Map {
	private :
		string city;
		int vertex;
		int edges;
		int laundry;
		vector<pair<int,int> > laundries;
	public :
		int getVertex() {
			return vertex;
		}
		int getEdges() {
			return edges;
		}
		int getLaundry() {
			return laundry;
		}
		vector<pair<int,int> > getLaundries() {
			return laundries;
		}
		void createMap() {
			cout<<"-------------**Map Genration**-------------"<<endl;
			bool flag=true;
			while(flag) {
				cout<<"City : ";
				cin>>city;
				string temp = city+".map";
				ifstream file;
				file.open(temp.c_str());
				if(file) {
					cout<<"Sorry This city already exit.......Please Try another one"<<endl;
				}
				else
					flag=false;
				file.close();
			}
			cout<<"Number of nodes/vertex : ";
			cin>>vertex;
			cout<<"Number of edges/ways : ";
			cin>>edges;
			cout<<"Number of Laundry Centeres : ";
			cin>>laundry;
			laundries.assign(vertex,make_pair<int,int> (0,0)); //first attribute for current , second for maximum
			for(int i=0;i<laundry;i++) {
				cout<<"Laundry Center location code "<<i+1<<" : ";
				int x;
				cin>>x;
				(laundries[x].first)++;
				(laundries[x].second)++;
			}
			
			/*saving data into file*/
			
			string temp = city+".map";
			ofstream file;
			file.open(temp.c_str());
			
			char arr[200]; //for converting string into character array
			strcpy(arr,city.c_str());
			file<<arr<<"\n";
			
			file<<vertex<<"\n";
			file<<edges<<"\n";
			file<<laundry<<"\n";
			
			for(int i=0;i<vertex;i++) {
				file<<laundries[i].first<<"\n";
				file<<laundries[i].second<<"\n";
			}
			file.close();
			
			/*now creating new file only for storing edges*/
			temp=city+".edg";
			file.open(temp.c_str());
			
			cout<<endl<<"\t----------------**Entries for Edges**----------------"<<endl<<endl;
			for(int i=0;i<edges;i++) {
				cout<<"\t<< For Edge No "<<i+1<<" >>\t"<<endl;
				int a,b,w;
				cout<<"a(source) : ";
				cin>>a;
				cout<<"b(destination) : ";
				cin>>b;
				cout<<"w(distance/weight) : ";
				cin>>w;
				file<<a<<"\n";
				file<<b<<"\n";
				file<<w<<"\n";
			}
			file.close();
			system("CLS");
			cout<<"*********Map succesfully created............."<<endl;
			this->showMap(city);
			getch();
		}
		
		bool loadMetaData(string s) {
			string temp=s+".map";
			ifstream file;
			file.open(temp.c_str());
			if(file) {
				getline(file,city);
				file>>vertex;
				file>>edges;
				file>>laundry;
				laundries.assign(vertex,make_pair<int,int> (0,0));
				for(int i=0;i<vertex;i++) {
					int x,y;
					file>>x;
					file>>y;
					laundries[i].first=x;
					laundries[i].second=y;
				}
				cout<<"\tMetaData loaded ........"<<endl;
				return true;
			}
			else {
				cout<<"Sorry!!!!!!! Map not found for city : "<<s<<endl;
				return false;
			}
		}
		
		void showMap(string s) {
			if(this->loadMetaData(s)) {
				cout<<"\t**------MetaData for city : "<<city<<"------**"<<endl<<endl;
				cout<<"Number of loaction(vertex) : "<<vertex<<endl;
				cout<<"Number of edges(ways) : "<<edges<<endl;
				cout<<"Number of laundry Centers : "<<laundry<<endl;
				cout<<"Laundry Centers are ::: "<<endl<<endl;
				cout<<"-----------------------------------"<<endl;
				cout<<"AreaCode   :    Number of Laundry"<<endl;
				cout<<"-----------------------------------"<<endl;
				for(int loc=0;loc<vertex;loc++) {
					if(laundries[loc].first) {
						cout<<"      "<<loc<<"    :    "<<laundries[loc].first<<"( ";
						for(int j=1;j<=laundries[loc].second;j++) {
							char buf[10];
							sprintf(buf,"%d",loc);
							string temp_ssn = city+"_"+buf;
							sprintf(buf,"%d",j);
							temp_ssn=temp_ssn+"_"+buf;
							string t=temp_ssn;
							temp_ssn=temp_ssn+".tm";
							ifstream file(temp_ssn.c_str());
							if(file) {
								cout<<t<<", ";
							}
							file.close();
						}
						cout<<")"<<endl;
					}
				}
				
				cout<<endl<<endl<<"Information about edges(way) ::::::::::: "<<endl<<endl;
				string temp = city+".edg";
				ifstream file;
				file.open(temp.c_str());
				for(int i=0;i<edges;i++) {
					int a,b,w;
					file>>a;
					file>>b;
					file>>w;
					cout<<a<<" -->> "<<b<<" "<<"( "<<w<<" )"<<endl;
				}
				file.close();
			}
		}
		void updateLaundry(string s) {
			if(this->loadMetaData(s))
			{
				cout<<"\t**------MetaData for city : "<<city<<"------**"<<endl<<endl;
				cout<<"Number of loaction(vertex) : "<<vertex<<endl;
				cout<<"Number of edges(ways) : "<<edges<<endl;
				cout<<"Number of Laundry Centers : "<<laundry<<endl;
				cout<<"Laundry Centers are ::: "<<endl<<endl;
				cout<<"-----------------------------------"<<endl;
				cout<<"AreaCode   :    Number of Laundry"<<endl;
				cout<<"-----------------------------------"<<endl;
				for(int loc=0;loc<vertex;loc++) {
					if(laundries[loc].first) {
						cout<<"      "<<loc<<"    :    "<<laundries[loc].first<<"( ";
						for(int j=1;j<=laundries[loc].second;j++) {
							char buf[10];
							sprintf(buf,"%d",loc);
							string temp_ssn = city+"_"+buf;
							sprintf(buf,"%d",j);
							temp_ssn=temp_ssn+"_"+buf;
							string t=temp_ssn;
							temp_ssn=temp_ssn+".tm";
							ifstream file(temp_ssn.c_str());
							if(file) {
								cout<<t<<", ";
							}
							file.close();
						}
						cout<<")"<<endl;
					}
				}
				
				cout<<endl<<endl<<"<< To add Laundry press 1 else 0 >>"<<endl;
				int ch;
				cin>>ch;
				cout<<"Enter area code : ";
				int x;
				cin>>x;
				if(ch) {
					laundries[x].first++;
					laundries[x].second++;
					laundry++;
					cout<<"!!!!!!  Laundry System Successfully added......"<<endl;
					
					/*saving Data*/
						
						string temp=s+".map";
						ofstream file;
						file.open(temp.c_str());
						char arr[200]; //for converting string into character array
						strcpy(arr,city.c_str());
						file<<arr<<"\n";
				
						file<<vertex<<"\n";
						file<<edges<<"\n";
						file<<laundry<<"\n";
			
						for(int i=0;i<vertex;i++) {
							file<<laundries[i].first<<"\n";
							file<<laundries[i].second<<"\n";
						}
						file.close();
				}
				else {
					string ssn;
					cin.ignore();
					cout<<"Please Enter ssn : ";
					getline(cin,ssn);
					ssn=ssn+".tm";
					
					if(remove(ssn.c_str()) != 0)
    					cout<<"Sorry No file found, Laundry Can't Be Removed"<<endl;
  					else {
    					puts("File successfully deleted");
    					(laundries[x].first)--;
						laundry--;
						cout<<"!!!!!! Laundry Successfully removed......"<<endl;
						
						/*saving Data*/
						
						string temp=s+".map";
						ofstream file;
						file.open(temp.c_str());
						char arr[200]; //for converting string into character array
						strcpy(arr,city.c_str());
						file<<arr<<"\n";
				
						file<<vertex<<"\n";
						file<<edges<<"\n";
						file<<laundry<<"\n";
			
						for(int i=0;i<vertex;i++) {
							file<<laundries[i].first<<"\n";
							file<<laundries[i].second<<"\n";
						}
						file.close();
    				}
				}
			}
		}
		int getNumberOfLaundriesAtLocation(int loc {
			return laundries[loc].second;
		}
};

class Customer {
	private:
		string userId;
		string passWord;
		string name;
		string city;
		int areaCode;
		string preferedLaundryCenter;
		string l_ssn;
	public :
		/* since for new customer will have no history thats why preferedLaundryCenter will be null
		the purpose for customer class is to register the user and access data from file*/
		Customer() {
			preferedLaundryCenter=preferedLaundryCenter+"No Data Found.....";
		}
		
		/*all set methods*/
		void setL_ssn(string str) {
			l_ssn=str;
		}
		void setPassWord(const string &pass) {
			passWord=pass;
		}
		void setuserId(const string &userId) {
			this->userId=userId;
		}
		void setName(const string &name) {
			this->name=name;
		}
		void setCity(const string &city) {
			this->city=city;
		}
		void setAreaCode(const int &areaCode) {
			this->areaCode=areaCode;
		}
		void setPreferedLaundryCenter(string str) {
			preferedLaundryCenter=str;
		}
		
		/*all get methods*/
		
		string getUserId() {
			return userId;
		}
		string getName() {
			return name;
		}
		string getCity() {
			return city;
		}
		int getAreaCode() {
			return areaCode;
		}
		string getPassWord() {
			return passWord;
		}
		string getPreferedLaundryCenter() {
			return preferedLaundryCenter;
		}
		string getL_ssn() {
			return l_ssn;
		}
		/*To save user*/
		void saveCustomer() {
			string temp=userId+".cust";
			ofstream file;
			file.open(temp.c_str());
			char temparr[200];
			
			strcpy(temparr,passWord.c_str());
			file<<temparr<<"\n";
			
			strcpy(temparr,userId.c_str());
			file<<temparr<<"\n";
			
			strcpy(temparr,name.c_str());
			file<<temparr<<"\n";
			
			strcpy(temparr,city.c_str());
			file<<temparr<<"\n";
			
			file<<areaCode;
			
			strcpy(temparr,preferedLaundryCenter.c_str());
			file<<temparr<<"\n";
			
			strcpy(temparr,l_ssn.c_str());
			file<<temparr<<"\n";
			
			file.close();
			cout<<"Customer information saved......."<<endl;
		}
		
		/*to get information from user*/
		void custRegister() {
			cout<<endl<<"---------**Customer Registration**---------"<<endl;
			bool flag=false;
			do {
				cout<<"User_Id : ";
				cin>>userId;
				ifstream file;
				string temp=userId+".cust";
				file.open(temp.c_str());
				if(file) {
					flag=true;
					cout<<"UserId already exist please try another one......"<<endl;
				}
				else
					flag=false;
				file.close();
			} while(flag==true);
			
			cin.ignore();
			cout<<"PassWord : ";
			cin>>passWord;
			
			cin.ignore();
			cout<<"Name : ";
			getline(cin,name);
			
			cout<<"City : ";
			cin>>city;
			
			cout<<"Area Code : ";
			cin>>areaCode;
			this->saveCustomer();
		}
		
		/*To load a customer*/
		bool loadCustomer(const string Id) {
			string temp =Id+".cust";
			ifstream file(temp.c_str());

			/*if user is not registered or programe is unable to read the file*/
			if(!file) {
				cout<<"\tSorry......Unable to load file!!"<<endl;
				return false;
			} else {
				getline(file,passWord);
				getline(file,userId);
				getline(file,name);
				getline(file,city);
				file>>areaCode;
				getline(file,preferedLaundryCenter);
				getline(file,l_ssn);
			}
		}
		/* first load file then call this method*/
		void showCustDetail() {
			cout<<endl<<"---------**Customer Deatails**---------"<<endl;
			cout<<"\tUser_id : "<<userId<<endl;
			cout<<"\tName : "<<name<<endl;
			cout<<"\tCity : "<<city<<endl;
			cout<<"\tAreaCode : "<<areaCode<<endl;
			cout<<"\tPrefered Laundry : "<<preferedLaundryCenter<<endl;
			cout<<"\tL_ssn : "<<l_ssn<<endl;
		}
};

class Edge {
	int b,w;
	public:
		Edge() { }
		Edge(int b,int w) {
			this->b=b;
			this->w=w;
		}
		int getB() {
			return b;
		}
		int getW() {
			return w;
		}
};

class Graph {
	private:
		int v;
		int e;
		vector<Edge> adj[100]; //maximum vertex may be 100
	public:
		/*create or load map*/
		int getV() {
			return v;
		}
		void createGraph(string s_city) {
			Map m;
			string temp=s_city;
			if(m.loadMetaData(temp)) {
				v=m.getVertex();
				e=m.getEdges();
				temp=s_city+".edg";
				ifstream file(temp.c_str());
				for(int i=0;i<e;i++) {
					int a,b,w;
					file>>a;
					file>>b;
					file>>w;
					Edge temp_e(b,w);
					adj[a].push_back(temp_e);
					Edge t_e(a,w);
					adj[b].push_back(t_e);
				}
				file.close();
				cout<<"\tGraph Created!!!!!!"<<endl;
			}
		}
		void showGraph() {
			cout<<"Vertex : "<<v<<endl;
			cout<<"Edges : "<<2*e<<endl;
			cout<<endl<<"Adjacency List : "<<endl<<endl;
			for(int i=0;i<v;i++) {
				cout<<i<<"==>>";
				vector<Edge> :: iterator it;
				for(it=adj[i].begin();it!=adj[i].end();it++) {
					cout<<it->getB()<<"("<<it->getW()<<") ->";
				}
				cout<<endl;
			}
		}
		
		/*first load create graph then call this method*/
		
		void dijkstra(int source , vector<int> &dist) {
			set<pair<int,int> > st;
			dist.assign(v,INT_MAX);
			dist[source]=0;
			
			st.insert(make_pair(0,source));
			
			while(!st.empty()) {
				pair<int,int> temp_pair = *(st.begin());
				st.erase(st.begin());
				int a=temp_pair.second;
				
				int size=adj[a].size();
				for(int i=0;i<size;i++) {
					int b=adj[a][i].getB();
					int w=adj[a][i].getW();
					
					if(dist[b] > dist[a]+w) {
						if(dist[b]!=INT_MAX)
							st.erase(st.find(make_pair(dist[b],b)));
						dist[b]=dist[a]+w;
						st.insert(make_pair(dist[b],b));
					}
				}
			}
		}
};

class day {
	public:
	string item[12];
	int itemPrice[12];
};	
class LaundryInfo {
	private :
		string ssn;
		string name;
		string city;
		string mobile_no;
		string email;
		string Working_Days_Hours;  //: Mon - Sun / 9:00 AM - 8:00 PM
		int areaCode;
         
		
	public :
		day d[7];  	 
		string getName() {
			return name;
		}
		 
	    string getItemName(int dd ,int n) {
	    	return d[dd].item[n];
	    }
	    
		int getItemPrice(int dd ,int n) {
			return d[dd].itemPrice[n];
		}
		

		void saveLaundryInfo() {
			ofstream file;
			string temp=ssn+".tm";
			file.open(temp.c_str());
			char arr[100];
			strcpy(arr,ssn.c_str());
			file<<arr<<"\n";
			
			strcpy(arr,name.c_str());
			file<<arr<<"\n";
			
			strcpy(arr,city.c_str());
			file<<arr<<"\n";
	
			strcpy(arr,mobile_no.c_str());
			file<<arr<<"\n";
			
			strcpy(arr,email.c_str());
			file<<arr<<"\n";
			
			strcpy(arr,Working_Days_Hours.c_str());
			file<<arr<<"\n";
			
			file<<areaCode<<"\n";
			
			int i,j;
			
			for(i=0;i<7;++i) {
				for(j=0;j<12;++j) {
						strcpy(arr,d[i].item[j].c_str());
						file<<arr<<"\n";
				}
					
				for(j=0;j<12;++j) { 
						file<<d[i].itemPrice[j]<<"\n";
				}				   
			} 
			file.close();
			cout<<"!!!!!!Data saved........"<<endl;
		}
		 
		
	
		void LaundryRegistration() {
			cout<<"\t*************Registration Form*************"<<endl<<endl;
			cout<<"Laundry Name : ";
			cin.ignore();
			getline(cin,name);
			
			bool flag=true;
			while(flag) { 
				cout<<"city : ";
				cin>>city;
				string temp= city+".map";
				ifstream file(temp.c_str());
				if(file) {
					flag=false;
					file.close();
				}
				else {
					cout<<"Sorry No Such city exit ......Try again!!!"<<endl;
				}
			}
			
			cout<<"Mobile No : ";
			cin>>mobile_no;
			
			cout<<"Email Id : ";
			cin>>email;
			
			cout<<"Working_Days_Hours ( Mon - Sun / 9:00 AM - 8:00 PM) : ";
			cin.ignore();
			getline(cin,Working_Days_Hours);		
			
			cin.ignore();
			cout<<"Area Code : ";
			cin>>areaCode;				
					
			int i,j;
			
 			cout<<"\t<< Item Name and Price per unit >>"<<endl<<endl;
			int k1;
			
			for( i=0 ,k1=0;i<7;++i) { 
			   cout<<"\t<< "<<dayName[k1++]<<"   >>\n";
			   			   
			   cout<<"\t __Enter Info Item and Price__ \n";			   
				for(j=0;j<12;++j) {
					cin>>d[i].item[j];      
			        cin>>d[i].itemPrice[j];
				} 				   
			} 					
					
			 
			Map m;
			m.updateLaundry(city); // to load and update data in matadata of map
			
			/*all this stuff is for generating ssn*/
			
			int x=m.getNumberOfLaundriesAtLocation(areaCode);
			char buffer[10];
			sprintf(buffer,"%d",areaCode); //to convert integer into string
			ssn=city+"_"+buffer;
			sprintf(buffer,"%d",x); //to convert integer into stirng
			ssn=ssn+"_"+buffer;
			cout<<"Your Social Security Number : "<<ssn<<endl;
			this->saveLaundryInfo();
			getch();
		}
		bool loadLaundryCenter(string s) {
			s=s+".tm";
			ifstream file;
			file.open(s.c_str());
			if(file) {
			getline(file,ssn);
			getline(file,name);
			getline(file,city);
			getline(file,mobile_no);
			getline(file,email);
			getline(file,Working_Days_Hours);									
		
			file>>areaCode;
			int i,j;
			for(i=0 ;i<7;++i) { 
			    for(j=0;j<12;++j) { 
			        file>>d[i].item[j];      
			    }
				for(j=0;j<12;++j)					   
				    file>>d[i].itemPrice[j];	
			} 
			
			return true;
		}
		else {
			cout<<"Sorry No data found........"<<endl;
			return false;
		}
	}
	
	void showLaundryCenter(string s) { // s = ssn
		if(this->loadLaundryCenter(s)) {
			cout<<endl<<"********* Laundry Details*********"<<endl<<endl;
			cout<<"Social Security Number : "<<ssn<<endl;
			cout<<"Center name : "<<name<<endl;
			cout<<"City : "<<city<<endl;
			cout<<"Mobile No : "<<mobile_no<<endl;
			cout<<"Email : "<<email<<endl;
			cout<<"Area Code : "<<areaCode<<endl;
			cout<<"Working Days and Hours : "<<Working_Days_Hours<<endl;
					
			cout<<"<<\tInfo List\t>>"<<endl;
			int i,j,k1;
			
			for(i=0,k1=0;i<7;++i) { 
			   cout<<"\t<< "<<dayName[k1++]<<"   >>\n";
            
			   cout<<"-------------------------------------"<<endl;
			   cout<<"Item Name       :      Price"<<endl;
			   cout<<"-------------------------------------"<<endl;
						   			    		   
			   for(j=0;j<12;++j) { 		
			        cout<<d[i].item[j]<<"      : "<<d[i].itemPrice[j]<<"\n";
			    }
			    cout<<"-------------------------------------"<<endl;		 				   
			}
		}
		getch();
	}
};

class SmartLaundryCenter {
	public :
		SmartLaundryCenter() {
			this->StartUpLoginBox();
		}
		void StartUpLoginBox() {
			system("CLS");
			cout<<"\t\t\t    **Smart Laundry System**"<<endl<<endl;
			
			cout<<"\t-----------------------------------"<<endl;
			cout<<"\t| (A)dministrator ?                |"<<endl;
			cout<<"\t| (C)ustomer ?                     |"<<endl;
			cout<<"\t| (E)xit !                         |"<<endl;
			cout<<"\t-----------------------------------"<<endl;
			char ch;
			cin>>ch;
			if(ch=='a' || ch=='A')
				this->administratorOperations();
			else if(ch=='C' || ch=='c')
				this->customerStartupPage();
			else
				exit(0);
		}
		void administratorOperations() {
			system("CLS");
			cout<<"\t\t\t    **Smart Laundry System**"<<endl<<endl;
			cout<<"\t--------------------------------------------------------------"<<endl;
			cout<<"\t|                                                             |"<<endl;
			cout<<"\t|    Hello Admin plese login with Master Password........     |"<<endl;
			cout<<"\t|                                                             |"<<endl;
			cout<<"\t-------------------------------------------------------------- "<<endl;
			bool flag=true;
			do {
				cout<<endl<<"Password : ";
				string pass;
				cin.ignore();
				getline(cin,pass);
				if(!pass.compare("admin")) {
					flag=false;
				}
				else {
					system("CLS");
					cout<<"\t\t\t    **Smart Laundry System**"<<endl<<endl;
					cout<<"\t-------------------------------------------------"<<endl;
					cout<<"\t|  (S)orry Incorrect password,try again!!!!!!   |"<<endl;
					cout<<"\t|  (O)r go Back to Home Page!!!!                |"<<endl;
					cout<<"\t-------------------------------------------------"<<endl;
					char ch;
					cin>>ch;
					if(ch=='o' || ch=='O')
						this->StartUpLoginBox();
				}
			} while(flag);
			
			do {
				system("CLS");
				cout<<"\t\t\t    **Smart Laundry System**"<<endl<<endl;
				cout<<"\t--------------------------------------"<<endl;
				cout<<"\t| (C)reate map                       |"<<endl;
				cout<<"\t| (A)dd Laundry                   |"<<endl;
				cout<<"\t| (G)et Detail        			      |"<<endl;
				cout<<"\t| (D)elete Laundry                |"<<endl;
				cout<<"\t| (S)how Map MetaData               |"<<endl;
				cout<<"\t| (L)og Out                          |"<<endl;
				cout<<"\t--------------------------------------"<<endl;
				char choice;
				cin>>choice;
				switch(choice) {
					case 'c':
					case 'C':
					{
						Map map;
						map.createMap();
					}
						break;
					case 'a':
					case 'A':
					{
						LaundryInfo l;
						l.LaundryRegistration();	
					}
						break;
						
					case 'g':
					case 'G':
					{
						LaundryInfo l;
						cout<<"Enter SSN : ";
						string ssn;
						cin.ignore();
						getline(cin,ssn);
						l.showLaundryCenter(ssn);
					}
						break;
					case 'D':
					case 'd':
					{
						Map map;
						cout<<"Enter city : ";
						string city;
						cin.ignore();
						getline(cin,city);
						map.updateLaundry(city);
						getch();
					}
						break;
					case 'S':
					case 's':
					{
						Map map;
						cout<<"Enter city : ";
						string city;
						cin.ignore();
						getline(cin,city);
						map.showMap(city);
						getch();
					}
						break;
					case 'l':
					case 'L':
						this->StartUpLoginBox();
						break;
				}
			} while(true);
		}
		void useService(Customer &c,string &s_ssn,LaundryInfo &l ,int d1) {
			int i,j,k;
			int  arritem[12]={0};
			while(true) {
				system("CLS");
				cout<<"\t\t\t    **Smart Laundry System**"<<endl<<endl;
				cout<<"\t-----------------------------------"<<endl;
				cout<<"\t|                                  |"<<endl;
				cout<<"\t|         Entre Details :          |"<<endl;
				cout<<"\t|                                  |"<<endl;
				cout<<"\t-----------------------------------"<<endl;
				
				for(i=0;i<12;++i) {
				    cout<<"Number of "<<l.d[d1].item[i]<<" : ";cin>>arritem[i];
			    }
				int ch;
				cout<<"To Confirm order press 1 else 0 : ";cin>>ch;
				if(ch==1)
					break;
			}
			system("CLS");
			cout<<"\t\t\t    **Smart Laundry System**"<<endl<<endl;

			int total=0;
			
			cout<<"\t  ============================================================="<<endl;
			cout<<"\t|                          INVOICE                             |"<<endl;
			cout<<"\t|--------------------------------------------------------------|"<<endl;
			cout<<"\t|  Customer Name : ";printf("%23s                     |",c.getName().c_str());cout<<endl;
			cout<<"\t|--------------------------------------------------------------|"<<endl;
			cout<<"\t|    Item     |   Price(Rs.)    |   Quant    |   Amount      |"<<endl;
			cout<<"\t|--------------------------------------------------------------|"<<endl;
			for(i=0;i<12;++i) {
				if(arritem[i]!=0) {
					cout<<"\t|"<<l.d[d1].item[i]<<"   |  "<<l.d[d1].itemPrice[i]<<"    |   ";
					printf("%2d",arritem[i]);
					cout<<"       "<<"|"<<"   ";printf("%4d",arritem[i]*l.d[d1].itemPrice[i]);cout<<"     "<<"|       \n";
                    total+=arritem[i]*l.d[d1].itemPrice[i];
				}
			}
			cout<<"\t|--------------------------------------------------------------|"<<endl;
			cout<<"\t|                            Total Amount      :       "<<total<<"      |"<<endl;
			cout<<"\t  ============================================================="<<endl;
			
			c.setPreferedLaundryCenter(l.getName());
			c.setL_ssn(s_ssn);
			c.saveCustomer();
		}
		void search(Graph &g,Customer &c,vector<int> &dist) {
			g.dijkstra(c.getAreaCode(),dist);
			set< pair<int,int> > result;//to store nodes distance vise
			for(int i=0;i<g.getV();i++) {
				result.insert(make_pair<int,int>(dist[i],i));
			}
			Map m;
			m.loadMetaData(c.getCity());		
			
			vector<pair<int,int> > laundries;
			
			laundries=m.getLaundries();
			
			while(true) {
				if(result.empty()) {
					cout<<"End of result...."<<endl;
					break;
				}
				pair<int,int> temp=*result.begin();
				
				result.erase(result.begin());
				
				if(laundries[temp.second].first!=0) {	
					LaundryInfo l;
					int count=temp.second;
					int i=1;
					while(i<=laundries[temp.second].second) {
						string t_str; 
						char buff[100];
						
						t_str=t_str+c.getCity();
						t_str=t_str+"_";
						sprintf(buff,"%d",temp.second);
						t_str=t_str+buff;
						t_str=t_str+"_";
						sprintf(buff,"%d",i);
						t_str=t_str+buff;
						
						strcpy(buff,t_str.c_str());
						
						strcat(buff,".tm");
						
						ifstream file;
						file.open(buff);
						if(file) {
							system("CLS");
							cout<<"\t\t\t    **Smart Laundry System**"<<endl<<endl;
							
							cout<<endl<<"Best search for you >>>>"<<endl<<endl;
							l.showLaundryCenter(t_str);
							
							cout<<"\t-------------------------------------------"<<endl;
							cout<<"\t|    (N)ot happy!! Next Result ?           |"<<endl;
							cout<<"\t|    (U)se services of this Center  |"<<endl;
							cout<<"\t|    (E)xit !!                             |"<<endl;
							cout<<"\t--------------------------------------------"<<endl;
							
							char ch3;
							cin>>ch3;
							if(ch3=='n' || ch3=='N') {
								//do nothing
							}
							else if(ch3=='U' || ch3=='u') {
								string ddy;
									cout<<"Enter day : ";
									cin>>ddy;
										int d1 ;
										for(d1=0;d1<7;++d1) {
											if(dayName[d1]==ddy)
												break;
										}
								this->useService(c,t_str,l,d1);
								getch();
								return;
							}
							else
								return ;
						}
						i++;
					}
				}
			}
		}
		void customerOperations(Customer &c) {
			do {	
				system("CLS");
				cout<<"\t\t\t    **Smart Laundry System**"<<endl<<endl;
			
				cout<<"\tWelcome : "<<c.getName()<<endl;
				cout<<"\t-----------------------------------"<<endl;
				cout<<"\t|    (M)y Account                  |"<<endl;
				cout<<"\t|    (F)ind a Laundry Center        |"<<endl;
				cout<<"\t|    (L)og Out                     |"<<endl;
				cout<<"\t------------------------------------"<<endl;
				
				char ch1;
				cin>>ch1;
				switch(ch1) {
					case 'm':
					case 'M':
					{
						c.showCustDetail();
						getch();
					}
						break;
					case 'f':
					case 'F':
					{
						Graph g;
						g.createGraph(c.getCity());
						if(!c.getL_ssn().empty()) {
							system("CLS");
							cout<<"\t\t\t    **Smart Laundry System**"<<endl<<endl;
							cout<<"\they "<<c.getName()<<"!!!!!"<<endl;       
							cout<<"\tBased on your previous transaction prefered center is : "<<c.getPreferedLaundryCenter()<<endl<<endl<<endl;
							do {
								cout<<"\t-----------------------------------------------"<<endl;
								cout<<"\t|  (G)et details of prefered center    |"<<endl;
								cout<<"\t|  (U)se services of prefered center   |"<<endl;
								cout<<"\t|  (N)ot haappy ?? want more ??               |"<<endl;
								cout<<"\t|  (E)xit                                     |"<<endl;
								cout<<"\t-----------------------------------------------"<<endl;
							
								char ch2;
								cin.ignore();
								cin>>ch2;
							    string ddy;
								if(ch2=='G' || ch2=='g') {
									system("CLS");
									cout<<"\t\t\t    **Smart laundry System**"<<endl<<endl;
									LaundryInfo l;
									l.showLaundryCenter(c.getL_ssn());
									getch();
								}
								else if (ch2=='U' || ch2=='u') {
									cout<<"Enter day : ";
									cin>>ddy;
									int d1 ;
									for(d1=0;d1<7;++d1) {
										if(dayName[d1]==ddy)
											break;
									}									
									LaundryInfo l;
									l.loadLaundryCenter(c.getL_ssn());
									string temp=c.getL_ssn();
									this->useService(c,temp,l,d1);
									getch();
									break;
								}
								else if(ch2=='N' || ch2=='n') {
									vector<int> dist;
									this->search(g,c,dist);
									break;
								}
								else {
									break;
								}
							} while(true);
						}
						else {
							vector<int> dist;
							this->search(g,c,dist);
							getch();
						}
					}
						break;
					case 'l':
					case 'L':
						this->StartUpLoginBox();
				}
				
			} while(true);
		}
		void custLogInPage() {
			system("CLS");
			cout<<"\t\t\t    **Smart Laundry System**"<<endl<<endl;
			cout<<"\t-----------------------------------"<<endl;
			cout<<"\t|                                  |"<<endl;
			cout<<"\t|         Customer Login           |"<<endl;
			cout<<"\t|                                  |"<<endl;
			cout<<"\t-----------------------------------"<<endl;
				
			string u_id;
			string pass;
			cout<<"\tUser Id : ";
			cin.ignore();
			getline(cin,u_id);
				
			Customer c;
			if(c.loadCustomer(u_id)) {
				cout<<"\tPassword : ";
				getline(cin,pass);
				if(pass.compare(c.getPassWord())) {
					cout<<"\tIncorrect Password !!!!!";
					getch();
					this->customerStartupPage();
				}
				else {
					this->customerOperations(c);
				}
			}
			else {
				getch();
				this->customerStartupPage();
			}
		}
		void customerStartupPage() {
			do {
				system("CLS");
				cout<<"\t\t\t    **Smart Laundry System**"<<endl<<endl;
				cout<<"\t-----------------------------------"<<endl;
				cout<<"\t| (L)ogin   ?                     |"<<endl;
				cout<<"\t| (S)ign Up ?                     |"<<endl;
				cout<<"\t| (E)xit    !                     |"<<endl;
				cout<<"\t-----------------------------------"<<endl;
			
				char ch;
				cin>>ch;
				if(ch=='s' || ch=='S') {
					Customer c;
					c.custRegister();
					getch();
				}
				else if(ch=='L' || ch=='l') {
					this->custLogInPage();
					getch();
				}
				else
					exit(0);
			} while(true);
		}
};

int main() {
	SmartLaundryCenter sl;
}
