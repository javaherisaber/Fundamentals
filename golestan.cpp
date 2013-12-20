#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

struct lesson{
	char name[50];
	short int unitvalue;//vahede dars
	long lessonssn;//shomareye dars
	double grade;//nomreye dars
};//in structure baraye dars haye mojod dar list doros mibashad

struct student{
	char firstname[25];
	char lastname[25];
	char fathername[50];
	char birthday[15];
	long ID;//shomareye daneshjoi
	lesson doros[7][15];//dorose daneshjo dar 8 term
	int sum_vahed[7];//majmoe vahedhaye 8 term
	double average[7];
	bool hazfe_tak_dars_status[7];//vaziyate hazfe tak dars dar har term
	bool unit_status[7];//vaziyate entekhab vahede har term baraye controle virayeshe etelaate daneshjoyan
	bool mashrotiyat[7];//vaziyate mashrotiyate har term
	bool insert_grade_student_status[7];//vaziyate vared shodan nomre dar har term baraye controle virayeshe nomarat
};//in structure etelaate daneshjo ast

int term=1;
int lessonlist_column[7];
lesson **lessonlist;//baraye negahdari drorose tamami termha 
student *studentlist;//baraye negahdari daneshjoyan ba tamamiye etelaat
int studentlist_column=0;
bool lesson_status[7];//vaziyate ezafe shodan ya nashodan dars baraye controle entekhab vahed
bool student_status[7];//vaziyate ezafe shodan ya nashodan daneshjoo baraye controle entekhab vahed


char *inputdata(int*);
char menu();
void lesson_database_name(char*,int);
void lesson_database_unitvalue(short int);
void lesson_database_lessonssn(long);
void addlesson();
int search_lesson_by_name(char*,int);
int search_lesson_by_ssn(long);
void addterm();
void delete_lesson(int);
void edit_lesson(int);
void addstudent();
int search_student_by_ID(long);
void delete_student();
void edit_student();
void search_student_by_firstname();
void search_student_by_lastname();
void entekhab_vahed();
void hazfe_tak_dars();
void insert_grade_student();
void credit_student();
void display_students();
void display_lessons();

void main() {
	system("color B");
	lessonlist=new lesson*[7];//list dorose dar 8 term
	for(int i=0;i<8;i++)
	{
		lessonlist[i]=new lesson[50];
	}
	studentlist=new student[50];//list daneshjoyan ba tamamie etelaat
	lesson_status[0]=false;
	student_status[0]=false;
	lessonlist_column[0]=0;
	bool flag=true;
	long ID;
	int IDtemp;

	char choice;
	do{
		choice=menu();
		switch(choice)
		{
		case 't' :
			if(term<8){
			addterm();
			cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\nnew term added\nnow you are in term : "<<term<<"\n\n\n\n\n\n\n\n\n\n\n\t\tpress any key to return to menu";
			_getch();}
			else{
				system("color C");
				for(int a=0;a<23;a++)
					cout<<endl;
			cout<<"\n\t\tyou havent right to add new term!";
			cout<<"\n\t\tpress any key to return to menu";
			_getch();
			 system("color B");
			}
			break;
		case 'a' :
			addstudent();
			break;
		case 'b' :
			search_student_by_firstname();
			break;
		case 'c' :
			search_student_by_lastname();
			break;
		case 'd' :
			cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\nyou are here :\nstudent by ID\n\n";
			cout<<"insert ID in order to search :";
			cin>>ID;
			IDtemp=search_student_by_ID(ID);
			if(IDtemp==-1)
			{
				cout<<"your student not found !";
				cout<<"\n\t\tpress any key to return to menu";
				_getch();
			}
			else
			{
				cout<<"\n\n\nfound !";
				cout<<"\ninformation :"<<endl;
				cout<<"ID :"<<studentlist[IDtemp].ID<<endl;
				cout<<"name :"<<studentlist[IDtemp].firstname<<" "<<studentlist[IDtemp].lastname<<endl;
				cout<<"fathername :"<<studentlist[IDtemp].fathername<<endl;
				cout<<"birthday :"<<studentlist[IDtemp].birthday;
				cout<<"\n\n\t\tpress any key to return to menu";
				_getch();
			}
			break;
		case 'e' :
			delete_student();
			break;
		case 'f' :
			edit_student();
			break;
		case 'g' :
			addlesson();
			break;
		case 'h' :
		char *name;
		int namelen,nametemp;
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nyou are here :\nsearch lesson by name\n\n\n\n\n\n\n\n\n\n\nenter your lesson name in order to search(at end of name put . ) :";
		name=inputdata(&namelen);
	    nametemp=search_lesson_by_name(name,namelen);
	if(nametemp==-1)
				{
					cout<<"your lesson not found ! \n";
					cout<<"\t\tpress any key to return to menu";
					_getch();
				}
				else
				{
					cout<<"\nyour lesson found !";
					cout<<"\nlesson name : "<<lessonlist[term-1][nametemp].name;
					cout<<"\nlesson ssn : "<<lessonlist[term-1][nametemp].lessonssn;
					cout<<"\nlesson unit value : "<<lessonlist[term-1][nametemp].unitvalue;
					cout<<"\n\n\t\tpress any key to return to menu";
					_getch();
				}
			break;
		case 'i' :
			long num;
			int ssntemp;
			cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nyou are here :\nsearch lesson by ssn\n\n\n\n\n\n\n\n\n\n\n\nenter your lesson ssn in order to search : ";
			cin>>num;
			ssntemp=search_lesson_by_ssn(num);
				if(ssntemp==-1)
				{
					cout<<"your lesson not found ! \n";
					cout<<"\t\tpress any key to return to menu";
					_getch();
				}
				else
				{
					cout<<"\nyour lesson found !";
					cout<<"\nlesson name : "<<lessonlist[term-1][ssntemp].name;
					cout<<"\nlesson ssn : "<<lessonlist[term-1][ssntemp].lessonssn;
					cout<<"\nlesson unit value : "<<lessonlist[term-1][ssntemp].unitvalue;
					cout<<"\n\n\t\tpress any key to return to menu";
					_getch();
				}
			break;
		case 'j' :
		
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nyou are here :\ndelete lesson\n\n\n\n\n\n\n\n\n\n\n\nenter your lesson name in order to delete(at end of name put . ) :";
     name=inputdata(&namelen);
	nametemp=search_lesson_by_name(name,namelen);
	if(nametemp==-1)
				{
					cout<<"your lesson not found ! \n";
					cout<<"\t\tpress any key to return to menu";
					_getch();
				}
				else
				{
					cout<<"\nyour lesson with this information :";
					cout<<"\nlesson name : "<<lessonlist[term-1][nametemp].name;
					cout<<"\nlesson ssn : "<<lessonlist[term-1][nametemp].lessonssn;
					cout<<"\nlesson unit value : "<<lessonlist[term-1][nametemp].unitvalue;
					cout<<"\n\n deleted ";
					cout<<"\n\n\t\tpress any key to return to menu";
					delete_lesson(nametemp);
					_getch();
				}
			break;
		case 'k' :
			if(lesson_status[term-1]==false)
	          {
		         cout<<"\n\n\nyou cant edit lesson!\nyou should add lesson first !";
		         cout<<"\n\t\tpress any key to return to menu";
		            _getch();
	          }
			else
			{
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nyou are here :\nedit lesson\n\n\n\n\n\n\n\n\n\n\n\nenter your lesson name in order to edit(at end of name put . ) :";
	name=inputdata(&namelen);
	nametemp=search_lesson_by_name(name,namelen);
	if(nametemp==-1)
				{
					cout<<"your lesson not found ! \n";
					cout<<"\t\tpress any key to return to menu";
					_getch();
				}
				else
				{
					edit_lesson(nametemp);
					cout<<"\n\n\t\tpress any key to return to menu";
					_getch();
				}
	        }
			break;
		case 'l' :
			entekhab_vahed();
			break;
		case 'm' :
			hazfe_tak_dars();
			break;
		case 'n' :
			insert_grade_student();
			break;
		case 'o' :
			credit_student();
			break;
		case 'p' :
			display_students();
			break;
		case 'q' :
			display_lessons();
			break;
		case 'x' :
			flag=false;
			break;
		}
		cout<<endl;
	}while(flag);
		cout<<"\n\t\tpress any key to close the application";
		delete[] *lessonlist;
		delete[] studentlist;
		_getch();
}/******end of main******/


char menu(){
	char choice;
	cout<<"\n\t\t\t***** IN THE NAME OF GOD *****\n";
	cout<<"\t\t      ** programmer : mehdy javahery **\n";
	cout<<"\t\t\t** master : vahid ghanbari **\n\n";
	cout<<"enter as examples in the [] \nfor example for adding new student insert a\n\n\n";
	cout<<"you are in term : "<<term<<endl;
	cout<<"1.add new term[t]\n";
	cout<<"2.add new student [a]\n";
	cout<<"3.search student by :-->first name[b]  -->last name[c]  -->student ID[d]\n";
	cout<<"4.delete[e] or edit[f] student information\n";
	cout<<"5.add new lesson[g]\n";
	cout<<"6.search lesson by :-->name[h]  -->ssn[i]\n";
	cout<<"7.delete[j] or edit[k] one lesson\n";
	cout<<"8.entekhab vahed[l] or delete one lesson[m] from student chart\n";
	cout<<"9.insert grades of lessons[n]\n";
	cout<<"10.display credit of student[o]\n";
	cout<<"11.display all of students in list[p]\n";
	cout<<"12.display all of lessons[q]\n";
	cout<<"13.exit[x]";
	cout<<"\n\n\n\t\t\tmake your choice :";
	cin>>choice;

return choice;
}/******end of menu*****/

char *inputdata(int *namelen){
	char *name,temp;
	bool wordflag=true;
    name=new char[50];
	int i;
	for(i=0;wordflag;i++){
		cin>>name[i];
		temp=name[i];
		if(temp=='.'){
			wordflag=false;
			name[i]=0;
		}
	}
	wordflag=true;
	*namelen=i-1;
	return name;
}/****end of input data*****/

void addterm(){
	term++;
	lessonlist_column[term-1]=0;
}/*****end of addterm******/


void addlesson(){
	char *name;
	int nametemp,ssntemp,ssn,unitvalue,namelen;
	bool flag1=true,flag2=true;
	while(flag1)
	         {
	cout<<"\nenter your lesson name (at end of name put . ) :";
    name=inputdata(&namelen);
	nametemp=search_lesson_by_name(name,namelen);
	if(nametemp==-1)
	{
		while(flag2)
		      {
		cout<<"enter ssn of lesson (except 0) :";
		cin>>ssn;
		ssntemp=search_lesson_by_ssn(ssn);
		if(ssntemp==-1)
		{
			cout<<"enter unit of this lesson :";
			cin>>unitvalue;
			lesson_database_name(name,namelen);
			lesson_database_lessonssn(ssn);
			lesson_database_unitvalue(unitvalue);
			flag1=false;
			flag2=false;
		}
		else
		{
			cout<<"\nssn is available !\ninsert new ssn\n";
		}
		      }
	}
	else
	{
		cout<<"\nlesson is availabe!\ninsert new word :";
	}
	          }
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nyou entered :\nlesson : "<<name<<"\nlesson ssn : "<<ssn<<"\nunit of this lesson : "<<unitvalue<<endl;
	cout<<"\n\t\t   your lesson saved\n\t\tpress any key to return to menu";
	lesson_status[term-1]=true;
	_getch();
}/*****end of addlesson*****/


void lesson_database_name(char *name,int namelen)
{
	for(int i=0;i<namelen;i++)
	{
		lessonlist[term-1][lessonlist_column[term-1]].name[i]=name[i];
	}
	lessonlist[term-1][lessonlist_column[term-1]].name[namelen]=0;
}/*******end of lesson_database_name*******/


void lesson_database_unitvalue(short int unitvalue)
{

	lessonlist[term-1][lessonlist_column[term-1]].unitvalue=unitvalue;
	lessonlist_column[term-1]++;

}/******end of lesson_database_unitvalue*****/


void lesson_database_lessonssn(long ssn)
{
     
	lessonlist[term-1][lessonlist_column[term-1]].lessonssn=ssn;

}/******end of lesson_database_lessonssn*********/



int search_lesson_by_name(char *name,int namelen)
{
	for(int j=0;j<lessonlist_column[term-1];j++)
	{
		int k=0,count=0,f=0;
		for(k=0;lessonlist[term-1][j].name[k];k++);
		if(k==namelen)
		{
			for(f=0;f<namelen;f++)
			{
				if(name[f]==lessonlist[term-1][j].name[f])
					count++;
			}
			if(count==namelen)
				return j;
		}

	}

	return -1;
}/******end of search_lesson_by_name*****/


int search_lesson_by_ssn(long ssn)
{
	for(int i=0;i<lessonlist_column[term-1];i++)
	{
		if(lessonlist[term-1][i].lessonssn==ssn)
			return i;
	}
	return -1;
}/******end of search_lesson_by_ssn*****/


void delete_lesson(int d){
	lessonlist[term-1][d].name[0]=NULL;
	lessonlist[term-1][d].lessonssn=0;
	lessonlist[term-1][d].unitvalue=0;
}/****end of delete_lesson****/


void edit_lesson(int input){

	char *name;
	cout<<"\n\n\n\n\n\n\ncurrent information :\n\n";
	cout<<"lesson name : "<<lessonlist[term-1][input].name;
    cout<<"\nlesson ssn : "<<lessonlist[term-1][input].lessonssn;
	cout<<"\nlesson unit value : "<<lessonlist[term-1][input].unitvalue;
	cout<<"\n\n\n\ninsert new information of this lesson :";
	bool flag1=true,flag2=true;
	int nametemp,ssntemp,ssn,unitvalue,namelen;
	while(flag1)
	         {
	cout<<"\ninsert your new lesson name (at end of name put . ) :";
    name=inputdata(&namelen);
	nametemp=search_lesson_by_name(name,namelen);
	if(nametemp==-1)
	{
		while(flag2)
		      {
		cout<<"\ninsert new ssn of lesson (except 0) :";
		cin>>ssn;
		ssntemp=search_lesson_by_ssn(ssn);
		if(ssntemp==-1)
		{
			cout<<"\ninsert new unit of this lesson :";
			cin>>unitvalue;
			for(int j=0;lessonlist[term-1][input].name[j];j++)
		        lessonlist[term-1][input].name[j]=NULL;
	        for(int i=0;i<namelen;i++)
	        {
		       lessonlist[term-1][input].name[i]=name[i];
	        }
	            lessonlist[term-1][input].name[namelen]=0;

		lessonlist[term-1][input].lessonssn=ssn;
		lessonlist[term-1][input].unitvalue=unitvalue;
			flag1=false;
			flag2=false;
		}
		else
		{
			cout<<"\nssn is available !\ninsert new ssn\n";
		}
		      }
	}
	else
	{
		cout<<"\nlesson name is availabe!\ninsert new word :";
	}
	          }
	
	cout<<"\n\t\t   your lesson edited and saved !";


}/*******end of edit_lesson*****/


void addstudent()
{
	char *firstname,*lastname,*fathername,*birthday;
	int firstname_len,lastname_len,fathername_len,birthday_len,IDtemp;
	long ID;
		for(int a=0;a<25;a++)
		cout<<endl;
	cout<<"you are here:\nadd student\n\n\n\n\n\ninsert information of student :\n\n";
	cout<<"first name(at end of word put .) :";
	firstname=inputdata(&firstname_len);
	for(int i=0;i<firstname_len;i++)
	{
		studentlist[studentlist_column].firstname[i]=firstname[i];
	}
	studentlist[studentlist_column].firstname[firstname_len]=0;
	cout<<"last name(at end of word put .) :";
	lastname=inputdata(&lastname_len);
	for(int j=0;j<lastname_len;j++)
	{
		studentlist[studentlist_column].lastname[j]=lastname[j];
	}
	studentlist[studentlist_column].lastname[lastname_len]=0;
	cout<<"father name(at end of word put .) :";
	fathername=inputdata(&fathername_len);
	for(int k=0;k<fathername_len;k++)
	{
		studentlist[studentlist_column].fathername[k]=fathername[k];
	}
	studentlist[studentlist_column].fathername[fathername_len]=0;
	cout<<"birthday for example 72/10/29 (at end of word put .) :";
	birthday=inputdata(&birthday_len);
	for(int l=0;l<birthday_len;l++)
	{
		studentlist[studentlist_column].birthday[l]=birthday[l];
	}
	studentlist[studentlist_column].birthday[birthday_len]=0;
	bool flag=true;
	while(flag)
	{
     cout<<"insert ID (except 0): ";
	 cin>>ID;
	 IDtemp=search_student_by_ID(ID);
		 if(IDtemp==-1)
		 {
			 cout<<"\n\t\t\tyour student saved\n\n\t\tpress any key to return to menu";
			 studentlist[studentlist_column].ID=ID;
			 studentlist[studentlist_column].unit_status[term-1]=false;
			 studentlist[studentlist_column].hazfe_tak_dars_status[term-1]=false;
			 studentlist[studentlist_column].insert_grade_student_status[term-1]=false;
			 studentlist_column++;
			 student_status[term-1]=true;

			 flag=false;
			 _getch();
		 }
		 else
		 {
			 cout<<"\n\n\tID available !\n";
		 }
	}
}/****end of addstudent****/

int search_student_by_ID(long ID)
{
	for(int i=0;i<studentlist_column;i++)
	{

		if(studentlist[i].ID==ID)
			return i;

	}
	return -1;
}/******end of search_student_by_ID*****/


void delete_student()
{
	long ID;
	int IDtemp;
	char choice;
		for(int a=0;a<25;a++)
		cout<<endl;
   cout<<"you are here:\ndelete student\n\n\n\n\n\n";
   bool flag=true;
   while(flag)
   {
	   cout<<"insert student ID in order to delete (except 0):";
	   cin>>ID;
	   IDtemp=search_student_by_ID(ID);
	   if(IDtemp!=-1)
	   {
		   cout<<"\n\n\nstudent info :";
		   cout<<"\nID :"<<studentlist[IDtemp].ID;
		   cout<<"\nname : "<<studentlist[IDtemp].firstname<<" "<<studentlist[IDtemp].lastname;
		   cout<<"\nbirthday : "<<studentlist[IDtemp].birthday;
		   cout<<"\nfather name : "<<studentlist[IDtemp].fathername;
		   cout<<"\n\nare you sure to delete this student (y/n) ? ";
		   cin>>choice;
		   if(choice=='y')
		   {
			   studentlist[IDtemp].birthday[0]=NULL;
			   studentlist[IDtemp].fathername[0]=NULL;
			   studentlist[IDtemp].firstname[0]=NULL;
			   studentlist[IDtemp].lastname[0]=NULL;
			   studentlist[IDtemp].ID=0;
			   cout<<"\n\n\t\tstudent deleted !";
			   cout<<"\n\t\tpress any key to return to menu";
			   _getch();
			   flag=false;
		   }
		   else
		   {
			   cout<<"\n\t\t  deleting student canceled !";
			   cout<<"\n\t\tpress any key to return to menu";
			   _getch();
			   flag=false;
		   }
	   }
	   else
	   {
		   cout<<"\tID not available !\n";
	   }
   }




}/***end of delete_student****/


void edit_student()
{
	if(student_status[term-1]==false)
	{
		cout<<"\n\n\nyou cant edit student!\nyou should add  student first !";
		cout<<"\n\t\tpress any key to return to menu";
		_getch();
	}
	else
	{
	long ID,IDedit;
	int IDtemp,IDtemp_edit,firstname_len,lastname_len,fathername_len,birthday_len;
	char choice,exit,*firstname,*lastname,*fathername,*birthday;
		for(int a=0;a<25;a++)
		cout<<endl;
   cout<<"you are here:\nedit student\n";
   bool flag=true,flag2=true,flag3=true,unit_status,flag4=true,flag5=true,flag6=true;
   while(flag)
   {
	   cout<<"insert student ID in order to edit (except 0):";
	   cin>>ID;
	   IDtemp=search_student_by_ID(ID);
	   if(IDtemp!=-1)
	   {
		   while(flag2)
		          {
					  for(int u=0;u<25;u++)
		                   cout<<endl; 
		   cout<<"\n\n\nstudent info :";
		   cout<<"\n1.ID[a] :"<<studentlist[IDtemp].ID;
		   cout<<"\n2.firstname[b] : "<<studentlist[IDtemp].firstname;
		   cout<<"\n3.lastname[c] :"<<studentlist[IDtemp].lastname;
		   cout<<"\n3.birthday[d] : "<<studentlist[IDtemp].birthday;
		   cout<<"\n4.fathername[e] : "<<studentlist[IDtemp].fathername;
		   cout<<"\n5.edit lessons grade[f]";
		   cout<<"\n6.return to menu[g]";
		   cout<<"\n\n\t\t\tmake your choice :";
		   cin>>choice;
		   switch(choice)
		   {
		   case 'a' :
			   while(flag3)
			       {
			   cout<<"insert new ID for this student :";
				   cin>>IDedit;
			   IDtemp_edit=search_student_by_ID(IDedit);
			   if(IDtemp_edit==-1)
			   {
				   studentlist[IDtemp].ID=IDedit;
				   cout<<"ID for student has been changed!";
				   flag3=false;
			   }
			   else
			   {
				   cout<<"\tID is availabe !\n";
			   }
 
			       }
			   flag3=true;
			   break;
		  case 'b' :
			   for(int i=0;studentlist[IDtemp].firstname[i];i++)
				   studentlist[IDtemp].firstname[i]=0;
			   cout<<"insert new firstname to this student (at the end put .) :";
			   firstname=inputdata(&firstname_len);
			   for(int j=0;j<firstname_len;j++)
	                {
		               studentlist[IDtemp].firstname[j]=firstname[j];
	                }
	                  studentlist[IDtemp].firstname[firstname_len]=0;
			   break;
		   case 'c' :
			   for(int k=0;studentlist[IDtemp].lastname[k];k++)
				   studentlist[IDtemp].lastname[k]=0;
			   cout<<"insert new lastname to this student (at the end put .) :";
			   lastname=inputdata(&lastname_len);
			   for(int l=0;l<lastname_len;l++)
	                {
		               studentlist[IDtemp].lastname[l]=lastname[l];
	                }
	                  studentlist[IDtemp].lastname[lastname_len]=0;
			   break;
		   case 'd' :
			   for(int m=0;studentlist[IDtemp].birthday[m];m++)
				   studentlist[IDtemp].birthday[m]=0;
			   cout<<"insert new birthday to this student (at the end put .) :";
			   birthday=inputdata(&birthday_len);
			   for(int n=0;n<birthday_len;n++)
	                {
		               studentlist[IDtemp].birthday[n]=birthday[n];
	                }
	                  studentlist[IDtemp].birthday[birthday_len]=0;
			   break;
		   case 'e' :
			    for(int p=0;studentlist[IDtemp].fathername[p];p++)
				   studentlist[IDtemp].fathername[p]=0;
			   cout<<"insert new fathername to this student (at the end put .) :";
			   fathername=inputdata(&fathername_len);
			   for(int q=0;q<fathername_len;q++)
	                {
		               studentlist[IDtemp].fathername[q]=fathername[q];
	                }
	                  studentlist[IDtemp].fathername[fathername_len]=0;
			   break;
		   case 'f' :
			   double grade;
			    unit_status=studentlist[IDtemp].unit_status[term-1];
				for(int y=0;y<25;y++)
		               cout<<endl;
				if(unit_status==false||studentlist[IDtemp].insert_grade_student_status[term-1]==false)
					cout<<"\n\tyou didnt made unit or didnt graded this student lessons yet!";
				else
				{
					while(flag6)
					             {
									 for(int e=0;e<25;e++)
		                                 cout<<endl;
					cout<<"mark     lessonname       ssn       unit    grade"<<endl;
			cout<<"--------------------------------------------------------------------------------"<<endl;
			int s=0;
			for(int w=0;flag5;w++)
			  {
				  if(studentlist[IDtemp].doros[term-1][w].unitvalue==-1)
					  flag5=false;
				  if(flag5&&studentlist[IDtemp].doros[term-1][w].unitvalue!=0)
				  {
					  if(studentlist[IDtemp].doros[term-1][w].grade==-1)
					  {
					  cout<<s+1<<"-        "<<studentlist[IDtemp].doros[term-1][w].name<<"            "<<studentlist[IDtemp].doros[term-1][w].lessonssn<<"         "<<studentlist[IDtemp].doros[term-1][w].unitvalue<<"      not added"<<endl;
					  s++;
					  }
					  else
					  {
						  cout<<s+1<<"-        "<<studentlist[IDtemp].doros[term-1][w].name<<"            "<<studentlist[IDtemp].doros[term-1][w].lessonssn<<"         "<<studentlist[IDtemp].doros[term-1][w].unitvalue<<"      "<<studentlist[IDtemp].doros[term-1][w].grade<<endl;
						  s++;
					  }
				  }
				  else
					  s--;
			  }
			flag5=true;
			cout<<"\n\ninsert ssn of lesson that you want to edit grade :";
			long ssn=0;
			int place=-1;
			cin>>ssn;
			for(int j=0;flag4;j++)
			    {
					if(studentlist[IDtemp].doros[term-1][j].unitvalue==-1)
						flag4=false;
					if(flag4)
					{
						if(studentlist[IDtemp].doros[term-1][j].lessonssn==ssn)
							{
								place=j;
								flag4=false;
						    }
					}
			    }
					
			flag4=true;
			if(place==-1)
			    {
					cout<<"\nplease insert ssn correctly!";
						cout<<"\n\t\tpress any key to try again";
					_getch();
			    }
			else
			    {
					cout<<"\ninsert your new grade for this lesson--> "<<studentlist[IDtemp].doros[term-1][place].name<<" =";
					cin>>grade;
					studentlist[IDtemp].doros[term-1][place].grade=grade;
					double average,sum_grades=0;
					int sum_units=0;
					for(int v=0;studentlist[IDtemp].doros[term-1][v].unitvalue!=-1;v++)
					{
						if(studentlist[IDtemp].doros[term-1][v].unitvalue!=0)
						{
							sum_grades+=((studentlist[IDtemp].doros[term-1][v].grade)*(studentlist[IDtemp].doros[term-1][v].unitvalue));
							sum_units+=studentlist[IDtemp].doros[term-1][v].unitvalue;
						}
					}
					average=(sum_grades/sum_units);
					studentlist[IDtemp].average[term-1]=average;
					if(average>12)
						studentlist[IDtemp].mashrotiyat[term-1]=false;
					else
						studentlist[IDtemp].mashrotiyat[term-1]=true;
					cout<<"your lesson grade has been changed!";
                  flag6=false;
				}
				
					        }
				}
				flag6=true;
			   break;
		   case 'g' :
			   break;
			   }//end of switch
		   cout<<"\ndo you want to edit anything else(y/n) ?";
			   cin>>exit;
		   if(exit=='n')
		   {
			   cout<<"\t\tpress any key to return to menu";
				   _getch();
			   flag2=false;
		   }

		          
		   flag=false;
	      
	        }

			}
	   else
	   {
		   cout<<"\tID not available !\n";
	   }
   
	   
   }//while
           }
}/****end of edit_student****/

void search_student_by_firstname()
{
	char *firstname;
	bool flag=true;
	int firstname_len,*found,count=0,j,found_count=0;
	found=new int[30];
	for(int a=0;a<25;a++)
		cout<<endl;
	cout<<"you are here :\nsearch student by firstname\n\n\n\n\n\n\n";
	cout<<"insert your student firstname in order to search (at the end put .) :";
	firstname=inputdata(&firstname_len);
	for(int i=0;i<studentlist_column;i++)
	{
		for(j=0;studentlist[i].firstname[j];j++);
		if(j==firstname_len)
		{
			for(int k=0;studentlist[i].firstname[k];k++)
			{
				if(studentlist[i].firstname[k]==firstname[k])
					count++;
			}
			if(count==firstname_len)
			{
				found[found_count]=i;
				found_count++;
				flag=false;
			}
			count=0;
		}


	}
	if(flag==true)
	{
		cout<<"\nyour student not found !";
		cout<<"\n\t\tpress any key to return to menu";
		_getch();
	}
	else
	{
		cout<<"\n\n"<<found_count<<" student with this firstname found\n\n";
		for(int h=0;h<found_count;h++)
		{
			cout<<"student "<<h+1<<" :"<<studentlist[found[h]].firstname<<" "<<studentlist[found[h]].lastname<<endl;
			cout<<"       ID :"<<studentlist[found[h]].ID<<"\n\n";
		}
		cout<<"\t\tpress any key to return to menu";
		_getch();
	}
	delete[] found;
}/****end of search_student_by_firstname****/


void search_student_by_lastname()
{
	char *lastname;
	bool flag=true;
	int lastname_len,*found,count=0,j,found_count=0;
	found=new int[30];
	for(int a=0;a<25;a++)
		cout<<endl;
	cout<<"you are here :\nsearch student by lastname\n\n\n\n\n\n\n";
	cout<<"insert your student lastname in order to search (at the end put .) :";
	lastname=inputdata(&lastname_len);
	for(int i=0;i<studentlist_column;i++)
	{
		for(j=0;studentlist[i].lastname[j];j++);
		if(j==lastname_len)
		{
			for(int k=0;studentlist[i].lastname[k];k++)
			{
				if(studentlist[i].lastname[k]==lastname[k])
					count++;
			}
			if(count==lastname_len)
			{
				found[found_count]=i;
				found_count++;
				flag=false;
			}
			count=0;
		}


	}
	if(flag==true)
	{
		cout<<"\nyour student not found !";
		cout<<"\n\t\tpress any key to return to menu";
		_getch();
	}
	else
	{
		cout<<"\n\n"<<found_count<<" student with this lastname found\n\n";
		for(int h=0;h<found_count;h++)
		{
			cout<<"student "<<h+1<<" :"<<studentlist[found[h]].firstname<<" "<<studentlist[found[h]].lastname<<endl;
			cout<<"       ID :"<<studentlist[found[h]].ID<<"\n\n";
		}
		cout<<"\t\tpress any key to return to menu";
		_getch();
	}

	delete[] found;
}/****end of search_student_by_lastname****/


void entekhab_vahed()
{
	if(lesson_status[term-1]==false||student_status[term-1]==false)
	{
		cout<<"\n\n\nyou cant make unit!\nyou should add lesson or student first !";
		cout<<"\n\t\tpress any key to return to menu";
		_getch();
	}
	else
	{
		long ID;
		int IDtemp,sumvahed=0,ssnsearch;
		long *entekhab;
		entekhab=new long[20];
		bool flag=true,flag2=true,flag3=true;
		for(int a=0;a<25;a++)
			cout<<endl;
		cout<<"you are here :\nentekhab vahed\n";
		while(flag)
	 {
		  cout<<"insert student ID in order to entekhab vahed :";
		  cin>>ID;
		  IDtemp=search_student_by_ID(ID);
		  if(IDtemp==-1)
			  cout<<"\t\tID is wrong!\n";
		  else
		  {
			  if(studentlist[IDtemp].unit_status[term-1]==true)
                 {
				  cout<<"\nthis student has made entekhab vahed befor in this term !";
				  cout<<"\n\t\tpress any key to return to menu";
				  _getch();
				  flag=false;
		         }
			  else
			  {
			  while(flag2)
			             {
             for(int b=0;b<25;b++)
			   cout<<endl;
			 cout<<"\n\n\nstudent :"<<studentlist[IDtemp].firstname<<" "<<studentlist[IDtemp].lastname<<"   ID :"<<studentlist[IDtemp].ID<<endl;
			 cout<<"lessons list :\n\n\n";
			 int s=0;
			 for(int c=0;c<lessonlist_column[term-1];c++)
			    {
					if(lessonlist[term-1][c].name[0]!=0)
					{
				   cout<<s+1<<".lesson name :"<<lessonlist[term-1][c].name<<"  ssn :"<<lessonlist[term-1][c].lessonssn<<"  unit :"<<lessonlist[term-1][c].unitvalue<<endl;
				   s++;
					}
					else
						s--;
			    }
             if(term==1)
			 {
				 cout<<"\n\nyou just select maximum 20 unit for student !";
				 cout<<"\nchoose lessons by inserting ssn of lesson"<<endl<<"like this for example(52 1665 124 2644,...) and at last put 0 and press enter\n :";
				  for(int  i=0;flag3;i++)
				  {
					 cin>>entekhab[i];
					 if(entekhab[i]==0)
						 flag3=false;
				  }
				  for(int j=0;entekhab[j]!=0;j++)
				  {
					  ssnsearch=search_lesson_by_ssn(entekhab[j]);
					  sumvahed+=lessonlist[term-1][ssnsearch].unitvalue;
				  }
				           if(sumvahed>20)
					     	{
								sumvahed=0;
								flag3=true;
							cout<<"\nplease choose units as followed !\n";
							cout<<"\t\tpress any key to try again";
								_getch();
						    }
						    else
						    {
								int k=0;
                               for(k=0;entekhab[k]!=0;k++)
				                 {
					               ssnsearch=search_lesson_by_ssn(entekhab[k]);
								   studentlist[IDtemp].doros[term-1][k].unitvalue=lessonlist[term-1][ssnsearch].unitvalue;
								   int l;
								   for(l=0;lessonlist[term-1][ssnsearch].name[l];l++)
								   studentlist[IDtemp].doros[term-1][k].name[l]=lessonlist[term-1][ssnsearch].name[l];
								   studentlist[IDtemp].doros[term-1][k].name[l]=0;
								   studentlist[IDtemp].doros[term-1][k].lessonssn=lessonlist[term-1][ssnsearch].lessonssn;
				                 }
							   studentlist[IDtemp].doros[term-1][k].unitvalue=-1;
							   flag2=false;
							   studentlist[IDtemp].sum_vahed[term-1]=sumvahed;
							   studentlist[IDtemp].unit_status[term-1]=true;
							     cout<<"\n\t\tentekhab vahed completed !";
								   cout<<"\n\t\tpress any key to return to menu";
								   _getch();
						    }
			 }
			 else
			 {
				 if(studentlist[IDtemp].mashrotiyat[term-2]==true)
				     {
					 cout<<"you just select at last only 14 unit for student !";
				  cout<<"\nchoose lessons by inserting ssn of lesson"<<endl<<"like this for example(52 1665 124 2644,...) and at last put 0 and press enter\n :";
				  for(int  i=0;flag3;i++)
				  {
					 cin>>entekhab[i];
					 if(entekhab[i]==0)
						 flag3=false;
				  }
				  for(int j=0;entekhab[j]!=0;j++)
				  {
					  ssnsearch=search_lesson_by_ssn(entekhab[j]);
					  sumvahed+=lessonlist[term-1][ssnsearch].unitvalue;
				  }
				           if(sumvahed>14)
					     	{
							sumvahed=0;
								flag3=true;
							cout<<"\nplease choose units as followed !\n";
							cout<<"\t\tpress any key to try again";
								_getch();
						    }
						    else
						    {
								int k=0;
                               for(k=0;entekhab[k]!=0;k++)
				                   {
					               ssnsearch=search_lesson_by_ssn(entekhab[k]);
								   studentlist[IDtemp].doros[term-1][k].unitvalue=lessonlist[term-1][ssnsearch].unitvalue;
								   int l;
								   for(l=0;lessonlist[term-1][ssnsearch].name[l];l++)
								   studentlist[IDtemp].doros[term-1][k].name[l]=lessonlist[term-1][ssnsearch].name[l];
								   studentlist[IDtemp].doros[term-1][k].name[l]=0;
								   studentlist[IDtemp].doros[term-1][k].lessonssn=lessonlist[term-1][ssnsearch].lessonssn;
				                 }
								studentlist[IDtemp].doros[term-1][k].unitvalue=-1;
							   flag2=false;
							   studentlist[IDtemp].sum_vahed[term-1]=sumvahed;
							   studentlist[IDtemp].unit_status[term-1]=true;
							     cout<<"\n\t\tentekhab vahed completed !";
								   cout<<"\n\t\tpress any key to return to menu";
								   _getch();
						    }
			           }
				 else
				 {
					 if(studentlist[IDtemp].average[term-2]>18)
					 {
					 cout<<"you just select maximum 24 unit for student !";
					  cout<<"\nchoose lessons by inserting ssn of lesson"<<endl<<"like this for example(52 1665 124 2644,...) and at last put 0 and press enter\n :";
				  for(int  i=0;flag3;i++)
				  {
					 cin>>entekhab[i];
					 if(entekhab[i]==0)
						 flag3=false;
				  }
				  for(int j=0;entekhab[j]!=0;j++)
				  {
					  ssnsearch=search_lesson_by_ssn(entekhab[j]);
					  sumvahed+=lessonlist[term-1][ssnsearch].unitvalue;
				  }
				           if(sumvahed>24)
					     	{
								sumvahed=0;
								flag3=true;
							cout<<"\nplease choose units as followed !\n";
							cout<<"\t\tpress any key to try again";
								_getch();
						    }
						    else
						    {
                            	int k=0;
                               for(k=0;entekhab[k]!=0;k++)
				                 {
					               ssnsearch=search_lesson_by_ssn(entekhab[k]);
								   studentlist[IDtemp].doros[term-1][k].unitvalue=lessonlist[term-1][ssnsearch].unitvalue;
								   int l;
								   for(l=0;lessonlist[term-1][ssnsearch].name[l];l++)
								   studentlist[IDtemp].doros[term-1][k].name[l]=lessonlist[term-1][ssnsearch].name[l];
								   studentlist[IDtemp].doros[term-1][k].name[l]=0;
								   studentlist[IDtemp].doros[term-1][k].lessonssn=lessonlist[term-1][ssnsearch].lessonssn;
				                 }
								studentlist[IDtemp].doros[term-1][k].unitvalue=-1;
							   flag2=false;
							   studentlist[IDtemp].sum_vahed[term-1]=sumvahed;
							   studentlist[IDtemp].unit_status[term-1]=true;
							     cout<<"\n\t\tentekhab vahed completed !";
								   cout<<"\n\t\tpress any key to return to menu";
								   _getch();
						    }
					 }
					 else
					 {
				     cout<<"you just select maximum 20 unit for student !";
					  cout<<"\nchoose lessons by inserting ssn of lesson"<<endl<<"like this for example(52 1665 124 2644,...) and at last put 0 and press enter\n :";
				  for(int  i=0;flag3;i++)
				  {
					 cin>>entekhab[i];
					 if(entekhab[i]==0)
						 flag3=false;
				  }
				  for(int j=0;entekhab[j]!=0;j++)
				  {
					  ssnsearch=search_lesson_by_ssn(entekhab[j]);
					  sumvahed+=lessonlist[term-1][ssnsearch].unitvalue;
				  }
				           if(sumvahed>20)
					     	{
						        sumvahed=0;
								flag3=true;
							cout<<"\nplease choose units as followed !\n";
							cout<<"\t\tpress any key to try again";
								_getch();
						    }
						    else
						    {
                              	int k=0;
                               for(k=0;entekhab[k]!=0;k++)
				                   {
					               ssnsearch=search_lesson_by_ssn(entekhab[k]);
								   studentlist[IDtemp].doros[term-1][k].unitvalue=lessonlist[term-1][ssnsearch].unitvalue;
								   int l;
								   for(l=0;lessonlist[term-1][ssnsearch].name[l];l++)
								   studentlist[IDtemp].doros[term-1][k].name[l]=lessonlist[term-1][ssnsearch].name[l];
								   studentlist[IDtemp].doros[term-1][k].name[l]=0;
								   studentlist[IDtemp].doros[term-1][k].lessonssn=lessonlist[term-1][ssnsearch].lessonssn;
				                 }
								studentlist[IDtemp].doros[term-1][k].unitvalue=-1;
							   flag2=false;
							   studentlist[IDtemp].sum_vahed[term-1]=sumvahed;
							   studentlist[IDtemp].unit_status[term-1]=true;
							     cout<<"\n\t\tentekhab vahed completed !";
								   cout<<"\n\t\tpress any key to return to menu";
								   _getch();
						    }
					 }
				 }
			 }
			      
		                }
			  flag=false;
			  }
		  }//end of else
	 }
	  delete[]  entekhab;
  }
  
}/****end of entekhab_vahed****/


void hazfe_tak_dars()
{
	if(lesson_status[term-1]==false||student_status[term-1]==false)
	{
		cout<<"\n\n\nyou cant delete any lesson for any student!\nyou should add lesson or student first !";
		cout<<"\n\t\tpress any key to return to menu";
		_getch();
	}
	else
	{
		long ID;
		int IDtemp;
		bool flag=true,flag2=true,flag3=true,flag4=true;
		while(flag)
		        {
		for(int a=0;a<25;a++)
			cout<<endl;
		cout<<"you are here :\nhazfe tak dars\n\n\n\n\ninsert ID of student in order to hazfe tak dars :";
		cin>>ID;
		IDtemp=search_student_by_ID(ID);
		if(IDtemp==-1)
		{
			cout<<"ID not found!\n\t\tpress any key to try again!";
				_getch();
		}
		else
		{
			while(flag3)
			              {
			cout<<"\n\nstudent :"<<studentlist[IDtemp].firstname<<"  "<<studentlist[IDtemp].lastname<<"   ID :"<<studentlist[IDtemp].ID<<endl;
			if(studentlist[IDtemp].unit_status[term-1]==false||studentlist[IDtemp].hazfe_tak_dars_status[term-1]==true)
			{
				cout<<"\nthis student doesnt made unit or deleted one lesson befor!\nif you didnt made unit for this student please go to entekhab vahed first";
				cout<<"\n\n\t\tpress any key to return to menu";
				_getch();
				flag=false;
				flag3=false;
			}
			else
			{
			cout<<"mark     lessonname       ssn       unit"<<endl;
			cout<<"--------------------------------------------------------------------------------";
			for(int i=0;flag2;i++)
			  {
				  if(studentlist[IDtemp].doros[term-1][i].unitvalue==-1)
					  flag2=false;
				  if(flag2)
					  cout<<i+1<<"-        "<<studentlist[IDtemp].doros[term-1][i].name<<"            "<<studentlist[IDtemp].doros[term-1][i].lessonssn<<"         "<<studentlist[IDtemp].doros[term-1][i].unitvalue<<endl;
			  }
			flag2=true;
			cout<<"\n\ninsert ssn of lesson that you want to delete from student chart :";
			long ssn;
			int place=-1;
			cin>>ssn;
			for(int j=0;flag4;j++)
			    {
					if(studentlist[IDtemp].doros[term-1][j].unitvalue==-1)
						flag4=false;
					if(flag4)
					{
						if(studentlist[IDtemp].doros[term-1][j].lessonssn==ssn)
							{
								place=j;
								flag4=false;
						    }
					}
			    }
			flag4=true;
			if(place==-1)
			    {
					cout<<"\nplease insert ssn correctly!";
						cout<<"\n\t\tpress any key to try again";
					_getch();
			    }
			else
			    {
					studentlist[IDtemp].doros[term-1][place].lessonssn=0;
					studentlist[IDtemp].doros[term-1][place].name[0]=0;
					int unit_minus;
					unit_minus=studentlist[IDtemp].doros[term-1][place].unitvalue;
					studentlist[IDtemp].doros[term-1][place].unitvalue=0;
					studentlist[IDtemp].sum_vahed[term-1]-=unit_minus;
					cout<<"\nstudent lesson successfully deleted!";
					cout<<"\n\n\t\tpress any key to return to menu";
					studentlist[IDtemp].hazfe_tak_dars_status[term-1]=true;
					_getch();
					flag3=false;
			    }


			}
			          }//end of while flag3
			flag=false;
		}//end of else

		        }
	}

}/****end of hazfe_tak_dars*****/


void insert_grade_student()
{
	if(lesson_status[term-1]==false||student_status[term-1]==false)
	{
		cout<<"\n\n\nyou cant put grade to any lesson for any student!\nyou should add lesson or student first !";
		cout<<"\n\t\tpress any key to return to menu";
		_getch();
	}
	else
	{
		long ID;
		int IDtemp;
		bool flag=true,flag2=true,flag3=true,flag4=true,flag5=true;
		while(flag)
		        {
		for(int a=0;a<25;a++)
			cout<<endl;
		cout<<"you are here :\ninsert grade of students\n\n\n\n\ninsert ID of student in order to insert grade :";
		cin>>ID;
		IDtemp=search_student_by_ID(ID);
		if(IDtemp==-1)
		{
			cout<<"ID not found!\n\t\tpress any key to try again!";
				_getch();
		}
		else
		{
			int count_grades=0;
			double sum_grades=0,average;
			int sum_unit=0;
			for(int t=0;flag5;t++)
			{
				if(studentlist[IDtemp].doros[term-1][t].unitvalue==-1)
					flag5=false;
				if(flag5)
					studentlist[IDtemp].doros[term-1][t].grade=-1;
			}
			flag5=true;
			while(flag3)
			              {
            	for(int b=0;b<25;b++)
			cout<<endl;
			cout<<"\n\nstudent :"<<studentlist[IDtemp].firstname<<"  "<<studentlist[IDtemp].lastname<<"   ID :"<<studentlist[IDtemp].ID<<endl;
			if(studentlist[IDtemp].unit_status[term-1]==false||studentlist[IDtemp].insert_grade_student_status[term-1]==true)
			{
				cout<<"\nthis student doesnt made unit or has been graded befor!\nif you didnt made unit for this student please go to entekhab vahed first";
				cout<<"\n\n\t\tpress any key to return to menu";
				_getch();
				flag=false;
				flag3=false;
			}
			else
			{
				int count_lessons=0;
				double grade;
			
			for(int r=0;studentlist[IDtemp].doros[term-1][r].unitvalue!=-1;r++)
			{
				if(studentlist[IDtemp].doros[term-1][r].name[0]!=0)
					count_lessons++;
			}
			cout<<"mark     lessonname       ssn       unit    grade"<<endl;
			cout<<"--------------------------------------------------------------------------------"<<endl;
			int s=0;
			for(int i=0;flag2;i++)
			  {
				  if(studentlist[IDtemp].doros[term-1][i].unitvalue==-1)
					  flag2=false;
				  if(flag2&&studentlist[IDtemp].doros[term-1][i].unitvalue!=0)
				  {
					  if(studentlist[IDtemp].doros[term-1][i].grade==-1)
					  {
					  cout<<s+1<<"-        "<<studentlist[IDtemp].doros[term-1][i].name<<"            "<<studentlist[IDtemp].doros[term-1][i].lessonssn<<"         "<<studentlist[IDtemp].doros[term-1][i].unitvalue<<"      not added"<<endl;
					  s++;
					  }
					  else
					  {
						  cout<<s+1<<"-        "<<studentlist[IDtemp].doros[term-1][i].name<<"            "<<studentlist[IDtemp].doros[term-1][i].lessonssn<<"         "<<studentlist[IDtemp].doros[term-1][i].unitvalue<<"      "<<studentlist[IDtemp].doros[term-1][i].grade<<endl;
						  s++;
					  }
				  }
				  else
					  s--;
			  }
			flag2=true;
			cout<<"\n\ninsert ssn of lesson that you want to put grade :";
			long ssn;
			int place=-1;
			cin>>ssn;
			for(int j=0;flag4;j++)
			    {
					if(studentlist[IDtemp].doros[term-1][j].unitvalue==-1)
						flag4=false;
					if(flag4)
					{
						if(studentlist[IDtemp].doros[term-1][j].lessonssn==ssn)
							{
								place=j;
								flag4=false;
						    }
					}
			    }
			flag4=true;
			if(place==-1||studentlist[IDtemp].doros[term-1][place].grade!=-1)
			    {
					cout<<"\nthis lesson has been graded befor or ssn is incorrect!";
						cout<<"\n\t\tpress any key to try again";
					_getch();
			    }
			else
			    {
					cout<<"\ninsert your grade for this lesson--> "<<studentlist[IDtemp].doros[term-1][place].name<<" =";
					cin>>grade;
					studentlist[IDtemp].doros[term-1][place].grade=grade;
					sum_grades+=(grade*studentlist[IDtemp].doros[term-1][place].unitvalue);
                    sum_unit+=studentlist[IDtemp].doros[term-1][place].unitvalue;
					count_grades++;
				if(count_grades==count_lessons)
				{
					cout<<"\nstudent lessons successfully graded!";
					cout<<"\n\n\t\tpress any key to return to menu";
					studentlist[IDtemp].insert_grade_student_status[term-1]=true;
					average=(sum_grades/sum_unit);
					studentlist[IDtemp].average[term-1]=average;
					if(average>12)
						studentlist[IDtemp].mashrotiyat[term-1]=false;
					else
						studentlist[IDtemp].mashrotiyat[term-1]=true;
					_getch();
					flag3=false;
			    }
				else
				{
					cout<<"\nyour grade added";
					cout<<"\nyou should insert all grade of this student first and then leave to menu!";
					cout<<"\n\t\tpress any key to put other grades";
					_getch();
				}


			}
			          }
			flag=false;
		    }
		}//end of second else

		         }//end of while flag
	}//end of first else
}/*****end of insert_grade_student*****/


void credit_student(){
	for(int a=0;a<25;a++)
		cout<<endl;
	bool flag=true,flag2=true;
	if(lesson_status[term-1]==false||student_status[term-1]==false)
	{
		cout<<"\n\n\nyou cant see any credit!\nyou should add lesson or student first !";
		cout<<"\n\t\tpress any key to return to menu";
		_getch();
	}
	else
	{
		while(flag)
		{
			for(int b=0;b<25;b++)
		      cout<<endl;
		long ID;
		int IDtemp;
		cout<<"you are here :\nkarnameye daneshjoo\n\n\n\n\ninsert ID of student in order to show credit :";
		cin>>ID;
		IDtemp=search_student_by_ID(ID);
		     if(IDtemp==-1)
		         {
			         cout<<"ID not available!"<<"\n\n\t\tpress any key to try again";
					 _getch();
		         }
			 else
			 {
				 if(studentlist[IDtemp].unit_status[1]==false||studentlist[IDtemp].insert_grade_student_status[1]==false)
					{
						cout<<"\n\tthis student doesnt made unit or deosnt graded  yet!";
						cout<<"\n\t\tpress any key to return to menu";
						_getch();
						flag=false;
				    }
				 else
				      {
				 for(int c=0;c<25;c++)
		              cout<<endl;
				 cout<<"name           ID         fathername         birthday"<<endl;
				 cout<<"--------------------------------------------------------------------------------"<<endl;
				 cout<<studentlist[IDtemp].firstname<<" "<<studentlist[IDtemp].lastname<<"   "<<studentlist[IDtemp].ID<<"          "<<studentlist[IDtemp].fathername<<"            "<<studentlist[IDtemp].birthday<<endl;
				 for(int k=0;k<term;k++)
				 {
	
					 cout<<"\n\nterm :"<<k+1<<"\nvaziyate mashrotiyat :"<<studentlist[IDtemp].mashrotiyat[k]<<"\nmajmoe vahedha :"<<studentlist[IDtemp].sum_vahed[k]<<"\naverage :"<<studentlist[IDtemp].average[k]<<"\n\n";
					 cout<<"mark     lessonname       ssn       unit    grade"<<endl;
			         cout<<"--------------------------------------------------------------------------------"<<endl;
					 int s=0;
				     for(int i=0;studentlist[IDtemp].doros[k][i].unitvalue!=-1;i++)
					 {
						 if(studentlist[IDtemp].doros[term-1][i].unitvalue==-1)
					        flag2=false;
				      if(flag2&&studentlist[IDtemp].doros[term-1][i].unitvalue!=0)
				        {
					         if(studentlist[IDtemp].doros[term-1][i].grade==-1)
					              {
					                   cout<<s+1<<"-        "<<studentlist[IDtemp].doros[term-1][i].name<<"            "<<studentlist[IDtemp].doros[term-1][i].lessonssn<<"         "<<studentlist[IDtemp].doros[term-1][i].unitvalue<<"      not added"<<endl;
					                    s++;
					              }
					        else
					              {
						              cout<<s+1<<"-        "<<studentlist[IDtemp].doros[term-1][i].name<<"            "<<studentlist[IDtemp].doros[term-1][i].lessonssn<<"         "<<studentlist[IDtemp].doros[term-1][i].unitvalue<<"      "<<studentlist[IDtemp].doros[term-1][i].grade<<endl;
						              s++;
					              }
				         }
				        else
					     s--;
					 }

					flag2=true;
				 }
				  cout<<"\n\t\tpress any key to return to menu";
					 _getch();
				 flag=false;
			          }
			 }

	    }//end of while flag
	}//end of first else 
}/****end of credit_student*****/

void display_students()
{
	for(int a=0;a<25;a++)
		cout<<endl;
	cout<<"students list :\n\n";
	cout<<"name                      ID\n";
	cout<<"------------------------------------------------------"<<endl;
		for(int i=0;i<studentlist_column;i++)
		{
			if(studentlist[i].firstname[0]!=0)
				cout<<studentlist[i].firstname<<"  "<<studentlist[i].lastname<<"               "<<studentlist[i].ID<<endl;
		}
		cout<<"\n\n\t\tpress any key to return to menu";
		_getch();
}/****end of display_students***/


void display_lessons()
{
	for(int a=0;a<25;a++)
		cout<<endl;
	int b=term;
	cout<<"lessons list :\n\n";
	cout<<"name              ssn          unit\n";
	cout<<"------------------------------------------------------"<<endl;
	for(b;b;b--)
	{
		for(int i=0;i<lessonlist_column[b-1];i++)
		{
			if(lessonlist[b-1][i].name[0]!=0)
				cout<<lessonlist[b-1][i].name<<"            "<<lessonlist[b-1][i].lessonssn<<"               "<<lessonlist[b-1][i].unitvalue<<endl;
		}
	}
	cout<<"\n\n\t\tpress any key to return to menu";
		_getch();
}/****end of display_lessons****/





/*************************************   THE END  ************************************************************/