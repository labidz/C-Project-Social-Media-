#include<bits/stdc++.h>
#include<conio.h>

using namespace std;

//Globals and PreFunctions
int userCount = -1;
void getData();
void getPosts();
void signin();
void home();
void allusers();
void testUsers();
//Main Class
class data{
	private:
		string password;
		string name;
		string posts[100];
		int post_count;
	public:
		data()
		{
			post_count = 0;
		}
		void new_user(string &pass,string &n)
		{
			password = pass;
			name = n;
		}
		
		void updatePost(string &str);
		void userInterface(string &pass,string &n,data &user);
		friend void getData(data &obj);
		friend void getPosts(data &obj);
		friend void login();
		friend void allusers(data &user);
		friend void testUsers();
};

//Total Users
data data_base[100];


void testUsers(){
//User #1
data_base[0].name = "Labid";
data_base[0].password = "oki";
data_base[0].posts[data_base[0].post_count++] = "I am a student of BAUST.";
data_base[0].posts[data_base[0].post_count++] = "BAUST is a good choise to study CSE.";
userCount++;
//User #2
data_base[1].name = "Chooyan";
data_base[1].password = "123";
data_base[1].posts[data_base[1].post_count++] = "I live in Dinajpur.";
data_base[1].posts[data_base[1].post_count++] = "I study CSE and my favourite subject is DSA.";
userCount++;
//User #3
data_base[2].name = "Nafis";
data_base[2].password = "BD";
data_base[2].posts[data_base[2].post_count++] = "My name is Nafis Fuad.";
data_base[2].posts[data_base[2].post_count++] = "I live in Rangpur.";
data_base[2].posts[data_base[2].post_count++] = "I want to be a Web Developer.";
userCount++;
//End
}


//updatePost : Class Member
inline void data :: updatePost(string &str)
{
	posts[post_count] = str;
	post_count++;
	cout<<"Post Saved. Press any key to Return"<<endl;
	getch();
	
}

//Class Member
inline void data :: userInterface(string &pass,string &n,data &user)
{
	system("cls");
	
	if(pass == user.password and n == user.name)
	{
		cout<<"\t\t\t\tWelcome "<<user.name<<" This is your Home"<<endl;
	}
	else
	{
		cout<<"\t\t\t\tWrong Username or Password"<<endl;
		signin();
	}
	cout<<"1.Write a post\n2.View previous post\n3.View other user's Posts\n4.Log out"<<endl;
	string post; 
	
	int x; cin>>x;
	switch(x)
	{
		case 1 : cout<<"Write your post: ";
		cin.ignore();
		getline(cin,post);
		user.updatePost(post);
		userInterface(pass,n,user);
		break;
		
		case 2 : cout<<"Here are your saved posts:\n\n"<<endl;
		getData(user);
		userInterface(pass,n,user);
		break;
		
		case 3 :
		allusers(user);
		userInterface(pass,n,user);
		break;
		
		case 4 : cout<<"Log out Complete. Press any key";
		getch();
		home();
		break;
		
		default : cout<<"Invalid Input. Press any key to return";
		getch();
		userInterface(pass,n,user);
		break;
	}
}

//Friend Function
void allusers(data &obj){
	cin.ignore();
	system("cls");
	cout<<"Write the User's name to view his/her post: "<<endl;
	int j = 0;
	for(int i=0;i<=userCount;++i)
	{
		if((data_base[i].name != obj.name) or (data_base[i].password != obj.password) )
		{
			cout<<++j<<". "<<data_base[i].name<<endl;
		}
	}
	cout<<"4. All\nEnter '0' to return\n";
	string s; getline(cin,s);
	system("cls");
	if(s== "0"){
		return;
	}
	if(s == "All"){
		getPosts(obj);
		allusers(obj);
	}
	for(int i=0;i<=userCount;++i){
		if(data_base[i].name == s){
			cout<<data_base[i].name<<"'s Posts: "<<endl;
			for(int j=0;j<data_base[i].post_count;j++)
			{
				cout<<"\n"<<j+1<<". "<<data_base[i].posts[j]<<"\n\n"<<endl;
			}
			cout<<"Press any key to return";
			getch();
			allusers(obj);
		}
	}
}

//Friend Function
void getPosts(data &obj){
	for(int i=0;i<=userCount;++i)
	{
		if((data_base[i].name != obj.name) or (data_base[i].password != obj.password) )
		{
			cout<<"\n"<<data_base[i].name<<"'s Posts: \n";
			
			for(int j=0;j<data_base[i].post_count;j++)
			{
				cout<<"\n"<<j+1<<". "<<data_base[i].posts[j]<<"\n\n"<<endl;
			}
			cout<<"------------------------------------------------------"<<endl;
		}
	}
	cout<<"Press any key to return";
	getch();
	allusers(obj);
}

//Friend Function
void getData(data &obj){
	for(int i=0;i<obj.post_count;i++)
	{
		cout<<i+1<<". "<<obj.posts[i]<<"\n\n"<<endl;
	}
	cout<<"\n\nPress any key to continue";
	getch();
}

//Friend Function
void login(){
	system("cls");
	cout<<"\t\t\t\tEnter Name: ";
	cin.ignore();
	string s; getline(cin,s);
	cout<<"\t\t\t\tEnter Password: ";
	
	string p; getline(cin,p);
	for(int i = 0;i<= userCount ; ++i)
	{
		if(data_base[i].name == s and data_base[i].password == p )
		{
			data_base[i].userInterface(p,s,data_base[i]);
			home();
		}
	}
	cout<<"\t\t\t\tWrong User Name or Password. Press any to return Home";
	getch();
	home();
}

//Local Function
void signin(){
	system("cls");
	cout<<"\t\t\t\tEnter Name: ";
	cin.ignore();
	string s; getline(cin,s);
	cout<<"\t\t\t\tEnter Password: ";
	string p; getline(cin,p);
	cout<<"\t\t\t\tConfirm Password: ";
	
	string p1; getline(cin,p1);
	if(p != p1)
	{
		cout<<p<<p1<<endl;
		cout<<"\t\t\t\tWrong Passwor. Press any key to try again";
		getch();
		signin();
	}
	else
	{
		userCount++;
		data_base[userCount].new_user(p,s);
		cout<<"\t\t\t\tAccount Created. Press any key to continue";
		getch();
		data_base[userCount].userInterface(p,s,data_base[userCount]);
	}
}

//Local Function
void home(){
	system("cls");
	cout<<"\t\t\t\tWelcome To BaceFook"<<endl;
	cout<<"Homapage\n\n\n"<<endl;
	cout<<"\t\t\t\t1.Sign in\n\t\t\t\t2.Log in\n\t\t\t\t";
	
	int x; cin>>x;
	switch(x)
	{
		case 1 : signin();
		break;
		case 2 : login();
		break;
		default : cout<<"Invalid Input. Press any key to continue";
		getch();
		home();
		break;
	}
}

int main() {
	while(1)
	{
		testUsers();
		home();
		getch();
	}
	return 0;
}

