// Prepared by : Dr. V. S. Tidake
// Sequential file handling using physical deletion

#include<iostream>
#include<fstream>
using namespace std;

class Student
{
    char Name[20];
    int Rollno;
    public:
        void create()
        {
			fstream fout;
			fout.open("stud.txt",ios::out);
			cout<<"\n Enter name and roll no :: ";
            cin>>Name>>Rollno ; 
			fout<<Name<<" "<<Rollno<<"\n";
			cout<<"\n Enter name and roll no :: ";
            cin>>Name>>Rollno ; 
			fout<<Name<<" "<<Rollno<<"\n";
			cout<<"\n Enter name and roll no :: ";
            cin>>Name>>Rollno ; 
			fout<<Name<<" "<<Rollno<<"\n";
			cout<<"\n Enter name and roll no :: ";
            cin>>Name>>Rollno ; 
			fout<<Name<<" "<<Rollno<<"\n";
			fout.close();			
        }

        void display()
        {
			fstream fin;
			fin.open("stud.txt",ios::in);
			cout<<"\n Name \t Roll no :: \n";
            fin>>Name>>Rollno ; 
			while(!fin.eof())
			{
            	cout<<Name<<"\t"<<Rollno<<"\n" ; 
				fin>>Name>>Rollno ; 
			}
			fin.close();

        }

        void search()
        {
			fstream fin;
			int tRollno;
			fin.open("stud.txt",ios::in);
			cout<<"\n Enter Roll no to search :: \n";
            cin>>tRollno ;
			int flag = 0; 
			while(!fin.eof())
			{
				if (tRollno == Rollno)
				{
					flag = 1;
	            	cout<<Name<<"\t"<<Rollno<<"\n" ; 
					break;
				}
				else
					fin>>Name>>Rollno ; 
			}
			if (flag == 0)
				cout<<"\n Record not found";
			fin.close();
        }

        void deleteRec()
        {
			fstream fin, fout;
			int tRollno;
			fin.open("stud.txt",ios::in);
			fout.open("stud1.txt", ios::out);

			cout<<"\n Enter Roll no to delete :: \n";
            cin>>tRollno ;
			int flag = 0; 
			fin>>Name>>Rollno ; 
			while(!fin.eof())
			{
				if (tRollno == Rollno)
				{
					flag = 1;
	            	cout<<Name<<"\t"<<Rollno<<"\n" ; 
					cout<<"record deleted \n";
				}
				else
				{	
					fout<<Name<<" "<<Rollno<<"\n";
				}
				fin>>Name>>Rollno ; 
			}
			if (flag == 0)
				cout<<"\n Record not found";
			fin.close();
			fout.close();
        }
};
       
int main()
{
    Student s;
	s.create();
	s.display();
	s.search();
	s.deleteRec();
    return 0;
}