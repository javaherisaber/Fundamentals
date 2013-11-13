#include <iostream>
#include <conio.h>
using namespace std;
int listrow=0;
char **list;
void database(char*,int);
void insert();
int search(char*,int);
void sortbyalphabet();
void printinversedword();
char mainmenu();
void main(){
	list=new char *[100];
	bool flag=true;//baraye controle loop
	char choose;//amaliyate entekhab shode
	
	do
	{
		choose=mainmenu();

		if(choose=='s'){
	char *word;//kalameye vorodi baraye search
	int wordlen=0,i;
	bool flagword=true;
	word=new char[30];
	cout<<"insert your word(at the end of word put .)  :";
	for(i=0;flagword&&*word!='.';i++)
	{
		cin>>*(word+i);
		if(word[i]=='.')
			flagword=false;
	                     }
	wordlen=i-1;
	word[wordlen]=0;
	int count=0;
	for(int j=0;word[j];j++)
	{
		if(word[j]==' ')
			count++;
		if(count>1)
		{
			for(int h=j;word[h+1];h++)
				word[h]=word[h+1];
			wordlen--;
			count=1;
		}
	}//in loop baraye hazfe space haye bishtar az yeki mibashad
	int sresult;
	sresult=search(word,wordlen);
	if(sresult==-1){
		cout<<"your word isnt exist in dictionary!\npress enter to continue";
		_getch();
	               }
	else{
		cout<<"found!\nplace of your word in dictionary is :"<<sresult;
		cout<<"\n\t\tpress any key to return to mainmenu";
		_getch();
		cout<<endl;
	    }
	delete[] word;
		}//end of if
		else{
		switch (choose) 
		{
		case 'i' :
			insert();
			break;
		case 'a' :
			sortbyalphabet();
			break;
		case 'p' :
			printinversedword();
			break;
		case 'e' :
			flag=false;
			break;
		}
		cout<<endl;
		}
	}while(flag);
	delete[] list;
	cout<<"\n\t\tpress any key to close the application";
	_getch();
}/**********end of main***********/



char mainmenu(){
	char choice;
	cout<<"\n\t\t\t****IN THE NAME OF GOD****\n\n";
	cout<<"select by character in examples in the [] "<<endl;
	cout<<"for example for search put s "<<endl;
	cout<<"\n\n\n\n\n1.insert[i]\n2.search[s]\n3.sortbyalphabet[a]\n4.printinversedword[p]\n5.exit[e]\n";
	cout<<"\n\n\n\n\n\n\n\n\n\t\t\tmake your choice :";
	cin>>choice;
	return choice;
}/********end of main menu*********/


void insert(){
	char *word;//kalameye vorodi dar insert
	int wordlen=0,i;
	bool flagword=true;
	word=new char[30];
	cout<<"insert your word(at the end of word put .)  :";
	for(i=0;flagword&&*word!='.';i++)
	{
		cin>>*(word+i);
		if(word[i]=='.')
			flagword=false;
	                     }
	wordlen=i-1;
	word[wordlen]=0;
	int count=0;
	for(int j=0;word[j];j++)
	{
		if(word[j]==' ')
			count++;
		if(count>1)
		{
			for(int h=j;word[h+1];h++)
				word[h]=word[h+1];
			wordlen--;
			count=1;
		}
	}//in loop baraye hazfe space haye bishtar az yeki mibashad
	int vis;
	vis=search(word,wordlen);
	if(vis==-1){
	database(word,wordlen);
	cout<<"your word   \" "<<word<<" \"   saved in dictoinary!\n\n";
	cout<<"\n\t\tpress any key to return to mainmenu";
	_getch();
	}
	else{
		cout<<"your word is repetitive !\n\n\n\t\tpress any key to return to mainmenu and try again";
	    _getch();
	    }
	delete[] word;

}/*******end of insert************/



void database(char *word,int wordlen){

	list[listrow]=new char [wordlen];
	for(int i=0;i<wordlen;i++)
		list[listrow][i]=word[i];
	list[listrow][wordlen]=0;
	listrow++;
}/*******end of database**********/

int search(char *word,int wordlen){

	int i=0,j=0,count=0;
	for(i=0;i<listrow;i++)
	{
		for(j=0;list[i][j]!=0;j++);
		if(j==wordlen){
			for(int k=0;k<wordlen;k++)
			{
				if(word[k]==list[i][k])
					count++;
			}
			if(count==wordlen)
				return i;
		}
		count=0;
	}

	return -1;
}/********end of search********/

void printinversedword(){
	bool flag=true;
	int count=0,first=0,last,count2=0;
	for(int i=0;i<listrow;i++)
	{
		for(int j=0;list[i][j];j++)
			count++;//shomareshe toole kalame
		if(count%2!=0)
		{
			last=count-1;
		   while(first!=last)
		   {
			   if(list[i][first]==list[i][last])
				   count2++;
			       first++;
			       last--;
		   }
		   if(count2==(count/2))
		   {
			   for(int k=0;list[i][k];k++)
			   {
                  cout<<list[i][k];
			   }
			   flag=false;
			   cout<<endl;
		   }
		}
		count=0;
		count2=0;
		first=0;
	}
	if(flag)
		cout<<"there is no word inversed in dictionary";
	cout<<"\n\n\n\t\tpress any key to return to mainmenu!";
	_getch();
}/*******end of printinversedword***/


void sortbyalphabet(){
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nsorted dictionary is :"<<endl;
	char i;
	for(i='a';i<='z';i++)
	{
		for(int j=0;j<listrow;j++)
		{
			if(list[j][0]==i)
			{
				for(int k=0;list[j][k];k++)
					cout<<list[j][k];
				cout<<endl;
			}
		}

	}
	cout<<"\n\t\tpress any key to return to mainmenu!";
	_getch();
}//*****end of sortbyalphabet***/