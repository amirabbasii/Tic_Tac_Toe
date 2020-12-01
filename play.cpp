#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
using namespace std;
int pic[4][4];
void sort();
string board[4][4];
void game(string,string,string);
void menu();
void one();
void winners();
int winner(int);
int hoosh(int);
void entekhab();
int turn();
void human(string,string);
void two();
int main() {
	cout<<"=================================\n";
	cout<<"@@@@@@@@@@ @@@@@@@@@@ @@@@@@@@@@@\n";
	cout<<"@              @      @          \n";
	cout<<"@@@@@@@@@@     @      @          \n";
	cout<<"@              @      @@@@@@@@@@@\n";
	cout<<"@              @                @\n";
	cout<<"@              @                @\n";
	cout<<"@              @      @@@@@@@@@@@\n";
	cout<<"=================================\n\n";
			cout<<"Welcome to FTS!Enjoy!\n\n";
	int flag;
	ifstream file1("win.txt");
	ifstream file2("score.txt");
	if(file1.is_open()==0 || file2.is_open()==0){
	system("@echo off>win.txt");
		system("@echo off>score.txt");
	file1.close();
		file2.close();
}
	file1.close();
		file2.close();
	char a;
	cout<<"Please choose:\n 1)Start Game \n 2)Winner \n 3)Exit \n";
	flag=1;
	while(flag==1){
	cin>>a;
	
	switch(a){
		case '1':
			flag=0;
			menu();
			break;
			case '2':
				flag=0;
				winners();
				break;
				case '3':
					flag=0;
					break;
					default:
						flag=1;
				}
				if(flag==1)
				cout<<"Impossible!Please try again.\n";
				}
			
		return 0;
}
void menu(){
	char a,flag;
	system("cls");
	cout<<"Please choose:\n1)One player\n2)Two player\n3)Back\n4)Exit\n";

	flag=1;
	while(flag==1){
		
		cin>>a;
	switch(a){
		case '1':
			flag=0;
			one();
			break;
			case '2':
				flag=0;
				two();
				break;
				case '3':
					flag=0;
					system("cls");
					main();
					break;
					case '4':
						flag=0;
						break;
						default:
							flag=1;
	}
	if(flag==1)
	cout<<"Impossible!Please try again.\n";
}
	
}
void one(){
string a,b;
cout<<"Pleae enter yot name:\n"	;
cin>>a;
b="Computer";
game("one",a,b);
}
int hoosh(int o){
	int i,j,k,s;
	/////////////////////////////

for(k=1;k<4;k++){
	s=0;
	for(i=1;i<4;i++)
s=s+pic[i][k];
if(s==o){
for(i=1;i<4;i++)
{
	if(pic[i][k]==0){
	pic[i][k]=-1;
	return o;
	break;
	}
}
}
}
s=0;
////////////////////////////////////////////

for(k=1;k<4;k++){
	s=0;
for(i=1;i<4;i++)
s=s+pic[k][i];
if(s==o){
for(i=1;i<4;i++)
{
	if(pic[k][i]==0){
	pic[k][i]=-1;
	return o;
	break;}
}
}

}
s=0;
///////////////////////////////////////////

for(i=1;i<4;i++)
s=s+pic[i][i];
if(s==o){
for(i=1;i<4;i++)
{
	if(pic[i][i]==0){
	pic[i][i]=-1;
	return o;
	break;}
}
}
s=0;
///////////////////////////////////////////

for(i=1;i<4;i++)
s=s+pic[i][4-i];
if(s==o){
for(i=1;i<4;i++)
{
	if(pic[i][4-i]==0){
	pic[i][4-i]=-1;
	return o;
	break;}
}
}
return 0;
}
void entekhab(){
	int z,flag,r,p;
	if(winner(3)!=3){
z=hoosh(-2);
if(z==0)
	z=hoosh(2);
if(z==0)
z=hoosh(-1);
if(z==0){
	flag=1;
while(flag==1){

	srand(time(0));
	r=rand()%3+1;
		p=rand()%3+1;
	if(pic[r][p]==0)
	{pic[r][p]=-1;
	flag=0;
	}
}
}}

}
int turn(){
	int r;
	srand(time(0));
	r=rand();
	if(r%2==0)
	return 1;
	else
	return 2;
}
void human(string player,string root){
		int x,h,y,g;
	cout<<player<<","<<"please enter your partion:\n";

	g=1;
	while(g!=0){
	cin>>h;		
if(h<4)
x=1;
if(h>=4 && h<7)
x=2;
if(h>=7 && h<10)
x=3;
y=h%3;
if(y==0)
y=3;
g=pic[x][y];
if(g!=0)
cout<<"Imposible!\n";
}
if(root=="one")
pic[x][y]=1;
else
pic[x][y]=-1;
}
void two(){
	string a,b;
	cout<<"First player,Please enter your name:";
	cin>>a;
	cout<<"Second player,Please enter your name:";
	cin>>b;
	game("two",a,b);
	
	
}
void game(string root,string a,string b){
int i,j,t,flag,m,con[2],n,g,f,we;
string win;
		con[0]=0;
con[1]=0;
for(n=1;n<=5;n++){
	t=1;
for(i=1;i<4;i++){
	for(j=1;j<4;j++){
		board[i][j]=" ";
	pic[i][j]=0;}}
	system("cls");
	cout<<b<<":"<<con[1]<<"\t"<<a<<":"<<con[0]<<"\n***Round="<<n<<"***"<<endl;
	we=0;
	cout<<"==========================\n";
for(i=1;i<4;i++){
	cout<<"|       |       |       |\n|";
	for(j=1;j<4;j++){
		we++;
	if(board[i][j]==" ")
		cout<<"   "<<we<<"   |";
		else
	cout<<"   "<<board[i][j]<<"   |";}
		cout<<"\n|       |       |       |";
		cout<<"\n==========================\n";
}
f=turn();
if(f%2==0)
win=a;
else
win=b;
while(t<10){
if(f%2==0){
	human(a,"one");
	f++;
}
else if(f%2!=0 && root=="one"){
	entekhab();
	f++;
}
else if(f%2!=0 && root=="two")
{
	human(b,root);
	f++;
}

system("cls");
for(i=1;i<4;i++){
{for(j=1;j<4;j++){
	if(pic[i][j]==1)
board[i][j]="X";
if(pic[i][j]==-1)
board[i][j]="O";
if(pic[i][j]==0)
board[i][j]=" ";
}}}
	cout<<b<<":"<<con[1]<<"\t"<<a<<":"<<con[0]<<"\n***Round="<<n<<"***"<<endl;
		we=0;
	cout<<"==========================\n";
for(i=1;i<4;i++){
	cout<<"|       |       |       |\n|";
	for(j=1;j<4;j++){
		we++;
	if(board[i][j]==" ")
		cout<<"   "<<we<<"   |";
		else
	cout<<"   "<<board[i][j]<<"   |";}
		cout<<"\n|       |       |       |";
		cout<<"\n==========================\n";
}
if(winner(3)==3){
win=a;
break;}
if(winner(-3)==-3){
win=b;
break;}

t++;}
if(win==a){
	cout<<"Winners is "<<a<<"!\n";
	cout<<"Press ENTER to start next round...\n";
	cin.get();
		cin.get();
			
con[0]++;}
else
{
	cout<<"Winners is "<<b<<"!\n";
	cout<<"Press ENTER to start next round...\n";
	cin.get();
		cin.get();
		
con[1]++;}
}
if(win!="Computer" || root=="two"){
int score;
string temp;
if(con[0]>con[1]){
win=a;
score=con[0];}
if(con[0]<con[1]){
win=b;
score=con[1];}
ifstream file1("win.txt");
flag=0;
i=0;
while(file1>>temp)
{i++;
	if(temp==win)
	{
		flag=1;
		break;
	}
}
file1.close();
if(flag==0){
	ofstream file1("score.txt",ios::app);
		ofstream file2("win.txt",ios::app);
file2<<win<<" ";
file1<<score<<" ";
file2.close();
file1.close();
}
else{
system("@echo off >tmp.txt");
ifstream file2("score.txt",ios::app);
ofstream file1("tmp.txt",ios::app);
char amir;
while(file2>>amir){
	i--;
	if(i!=0)
	file1<<amir<<" ";
	else
	break;
}
file1<<int(amir)-48+score<<" ";
while(file2>>amir)
{
	file1<<amir<<" ";
}
file1.close();
file2.close();
system("del score.txt");
system("ren tmp.txt score.txt");
}}

system("cls");
cout<<endl;
cout<<"=====================\n";
cout<<b<<":"<<con[1]<<"   "<<a<<":"<<con[0]<<endl;
cout<<"Winner:"<<win<<"!"<<endl;
cout<<"=====================\n";
cout<<endl<<"Do you want to play again?Or do you want to leave?\n1)Play agin\n2)Main menu\n3)Exit\n";
char get;
flag=1;
while(flag==1){
cin>>get;
switch(get){
	case '1':
		flag=0;
		system("cls");
		one();
		break;
		case '2':
			flag=0;
			system("cls");
			main();
			break;
		case '3':
			flag=0;
			break;
			default:
				flag=1;

if(flag==1)
cout<<"Impossible!Please try again.\n";}}}
int winner(int x){
	int i,j,s=0,k;
	for(k=1;k<4;k++){
		s=0;
		for(i=1;i<4;i++)
		s=s+pic[i][k];
		if(s==x)
		return x;
		s=0;
		for(i=1;i<4;i++)
		s=s+pic[k][i];
		if(s==x)
		return x;	
	}
	s=0;
		for(i=1;i<4;i++)
		s=s+pic[i][i];
		if(s==x)
		return x;
		s=0;
		for(i=1;i<4;i++)
		s=s+pic[i][4-i];
		if(s==x)
		return x;
		
	return 0;
	}
	void winners(){
			system("cls");
			sort();
		string wiin,score;
		int t=0;
	ifstream file1("win.txt");
	ifstream file2("score.txt");
	
		cout<<"=============WINNERS==============\n";
		while(file1>>wiin && file2>>score){
			t++;
		cout<<t<<"-"<<wiin<<":"<<score<<endl;}
		if(t==0)
		cout<<"There isn't any winner\n";
		cout<<"==================================\n";
		file1.close();
		file2.close();
		char n;
		int flag=1;
		cout<<"What do you wnat to do?please choose:\n1)Back\n2)Exit\n";
		while(flag==1){
		
		cin>>n;
		switch(n){
			case '1':
				flag=0;
				system("cls");
				main();
				break;
				case '2':
					flag=0;
					break;
					defual:
						flag=1;}
				
		if(flag==1)
		cout<<"Impossible!Please try again.\n";
	}}
	void sort(){
		int t=0,i,j,tm;
		string temp;
		ifstream file("score.txt");
		while(file>>temp){
			t++;
		}
		file.close();
	ifstream file1("score.txt");
	ifstream file2("win.txt");
		int *a=new int [t];
		string *b=new string [t];
		for(i=0;i<t;i++)
		{file1>>a[i];
		file2>>b[i];
		}
		for(i=0;i<t;i++)
		{for(j=0;j<t-1;j++){
			if(a[j]>a[j+1]){
				tm=a[j];
				a[j]=a[j+1];
				a[j+1]=tm;
				temp=b[j];
				b[j]=b[j+1];
				b[j+1]=temp;
				
			}
		}
		}
		file1.close();
		file2.close();
		ofstream file3("score.txt",ios::trunc);
		ofstream file4("win.txt",ios::trunc);
		for(i=0;i<t;i++)
		file3<<a[i]<<" ";
			for(i=0;i<t;i++)
		file4<<b[i]<<" ";
		file3.close();
		file4.close();
		
		
	}

