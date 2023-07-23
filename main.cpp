#include <iostream>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<fstream>
#include<stdlib.h>
using namespace std;
class players
{

	public:

		char fname[50],lname[50],address[50],tname[50],sex[20],nationality[30];
         int id,run,age,jno;
		int getdata();
		int getid()
		{
		    return id;
		}
		int viewdata();
        int mcount=0;
        int getMatchPlayedByPlayerId(int player_id);
        int totalrunscored(int i);
};
class score
{
public:

    int  run,jno,day,month,year,pid,found;
    void allrecord();
    void getallrecord();
    int playerid;
    int getid()
    {
        return playerid;
    }
    char place[45];

};
int players::getdata()
{

	cout<<endl<<"     FIRST NAME         :";
	cin>>fname;
	cout<<endl<<"     LAST NAME          :";
	cin>>lname;
	 h:
    cout<<endl<<"     AGE                :";
    cin>>age;
    if(age<20 || age>40)
        {
          cout<<"SORRY THIS PROGRAM STORES THE DATA OF ONLY AGE BETWEEN 20-40 OF PLAYERS......."<<endl;
          getch();
          goto h;
        }
	cout<<endl<<"     ADDRESS            :";
	cin>>address;
	cout<<endl<<"     SEX                :";
	cin>>sex;
	k:
	cout<<endl<<"     JURSEY NO.         :";
	cin>>jno;
	if(jno<0)
    {
        cout<<"JURSEY NO. SHOULDNOT BE NEGATIVE !!";
        getch();
        goto k;
    }
	cout<<endl<<"     TEAM NAME          :";
	cin>>tname;
}

int players::viewdata()
{
	cout<<"------------------------------------------------------------------------------------------------------------------\n\n";
	cout<<id<<"  \t"<<fname<<"\t"<<lname<<"     "<<age<<"       "<<address<<"         "<<sex<<"       "<<jno<<"\t          "<<tname<<"\t\t"<<getMatchPlayedByPlayerId(id)<<"\t        "<<totalrunscored(id)<<endl;
}
void score::allrecord()
{
                               cout<<endl<<endl<<endl;
                               cout<<"DATE OF MATCH:";
                               cout<<endl<<"--------------"<<endl;
                               cout<<"          DAY     :"<<day<<endl;
                               cout<<"         MONTH    :"<<month<<endl;
                               cout<<"          YEAR    :"<<year<<endl;
                               cout<<endl<<"-------------------------------"<<endl;
                               cout<<"PLACE 0F MATCH    :"<<place;
                               cout<<endl<<"-------------------------------"<<endl;
                               cout<<"RUN SCORED        :"<<run;
                               cout<<endl<<"-------------------------------"<<endl<<endl;


}
void score::getallrecord()
{

                                        m:
                                        cout<<"DATE OF MATCH:"<<endl;
                                        cout<<"          DAY     :";
                                        cin>>day;
                                        cout<<"         MONTH    :";
                                        cin>>month;
                                        cout<<"          YEAR    :";
                                        cin>>year;
                                        if(day>32 || month>12 || year>2019)
                                        {
                                            cout<<"CHECK YOUR DATE OF MATCH  AND ENTER AGAIN ......."<<endl;
                                            getch();
                                            goto m;
                                        }
                                        cout<<"PLACE 0F MATCH    :";
                                        cin>>place;
                                        j:
                                        cout<<"RUN SCORED        :";
                                        cin>>run;
                                        if(run<0)
                                        {
                                            cout<<" The run should not be in negative !!"<<endl;
                                            getch();
                                            goto j;
                                        }


}
int players::totalrunscored(int i)
{
    fstream file("cricket.txt",ios::in);
    score rs;
    int r=0;
    while(file.read((char*)&rs,sizeof(rs)))
    {
        if(i==rs.getid())
        {
            r+=rs.run;
        }

    }
    return r;
}

int players::getMatchPlayedByPlayerId(int player_id){
    fstream file("cricket.txt",ios::in);
    score sc;
    int match=0;
    while(file.read((char*)&sc,sizeof(sc))){
        if(player_id==sc.getid()){
            match++;
        }
    }
    return match;
}


int main()
{
	int i=3;
	int k,pw;
	char user[6]="admin",pass[20]="password",username[6],password[20];
    players p;
    score s;
    int ch,isfound,id;
    top:
    cout<<"                            WELCOME TO THE PROGRAM"<<endl;
    cout<<"                            ======================"<<endl<<endl<<endl;
    cout<<"USERNAME    :";
    cin>>username;
    cout<<endl;
    cout<<"PASSWORD    :";
    for(k=0;k<8;k++)
     {
       pw=getch();
  	   password[k]=pw;
  	   pw='*';
  	   printf("%c",pw);
     }
    getch();
    password[k]='\0';
    cout<<endl;
    if(strcmp(username,user)==0 && strcmp(password,pass)==0)
    {
     system("cls");
	 cout<<"                                                       LOGIN SUCESSFUL!!!!!"<<endl<<endl<<endl<<endl;
      t:
     cout<<"                    ------------------------------------------------------------------------------------"<<endl;
     cout<<"                    -----------------------YOUR CHOICE ARE AVAILABLE HERE!!-----------------------------"<<endl;
     cout<<"                    ------------------------------------------------------------------------------------"<<endl<<endl;
     cout<<"                        1.Create record "<<endl;
     cout<<"                        2.Create all records"<<endl;
     cout<<"                        3.View   record"<<endl;
     cout<<"                        4.Search record"<<endl;
     cout<<"                        5.Update record"<<endl;
     cout<<"                        6.Delete record"<<endl;
     cout<<"                        7.Exit program"<<endl;
     cout<<endl<<"Enter your choice:";
     cin>>ch;
     system("cls");
     switch(ch)
    {
    	case 1:
    	    {
    	                    int i;

                            cout<<"\t\t\tCREATE RECORD IS AVAILABLE HERE!!"<<endl;
                            m:
                            cout<<"      Enter all details:"<<endl;
                            cout<<"             ID:";
	                        cin>>i;
	                        if(i<0)
                            {
                                cout<<"         ID should not be negative!!"<<endl;
                                getch();
                                system("cls");
                                goto m;
                            }
                            fstream file("players.txt",ios::in | ios::out | ios::app);
	                        while(file.read((char *)&p,sizeof(p)))
                               {
                                   if(i==p.getid())
                                     {
                                         cout<<endl<<"  SORRY! THIS ID IS ALREADY ENTERED!!!"<<endl;
                                         getch();
                                         system("cls");
                                         goto m;
                                      }

                               }
                            file.close();
                            fstream f("players.txt",ios::in|ios::out|ios::app);
                            p.id=i;
                            p.getdata();
                            f.write((char*)&p,sizeof(p));
                            cout<<endl<<"   RECORD SUCESSFULLY CREATED!!";
                            getch();
                            f.close();
                            system("cls");
                            goto t;
                            break;
            }
    	case 2:
    	    {


    		                  int pid,isfound=0,id=0;
    		                  fstream f;
    		                  fstream file1("players.txt",ios::in|ios::out|ios::app);
                              cout<<"--------ENTER ALL RECORDS---------"<<endl<<endl;
                              cout<<"ID                :";
                              cin>>pid;
                              cout<<endl;
                              file1.seekg(0,ios::beg);

                              while(file1.read((char*)&p,sizeof(p)))
                                {

                                                        id=p.getid();

                                                        if(pid==id)
                                                            {
                                                                isfound=1;
                                                                cout<<endl<<"ID FOUND......."<<endl<<endl;
                                                                cout<<"ID     "<<"       NAME       "<<"  AGE "<<"     ADDRESS      "<<" SEX  "<<"  JURSEY NO. "<<"    TEAM NAME "<<"   MATCH PLAYED "<<"   RUN SCORED"<<endl;
                                                                p.viewdata();
                                                                p.mcount+=1;
                                                                file1.close();
                                                                f.open("cricket.txt",ios::in|ios::out|ios::app|ios::binary);
                                                                cout<<endl<<endl;
                                                                s.playerid=pid;
                                                                s.getallrecord();

                                                                f.write((char*)&s,sizeof(s));
                                                                cout<<endl<<endl<<"    ALL RECORDS ARE CREATED SUCCESSFULLY!!  "<<endl;
                                                                getch();
                                                                file1.close();
                                                                system("cls");
                                                                goto t;

                                                            }

                             }
                              if(isfound==0)
                                        {
                                            cout<<endl<<"ID "<<pid<<" DOES NOT FOUND...... "<<endl;
                                            getch();
                                            system("cls");
                                            goto t;

                                        }
                                        break;
    	    }

    	   case 3:
             {
                            fstream file4("players.txt",ios::in|ios::out);
                            cout<<"\t\t\tVIEW RECORD IS AVAILABLE HERE!!\n";
                            cout<<"\t\t\t===============================\n\n";
                            file4.seekg(0,ios::beg);
                            cout<<"ID     "<<"  FULL  NAME       "<<"  AGE "<<"     ADDRESS      "<<"SEX  "<<"   JURSEY NO. "<<"    TEAM NAME "<<"   MATCH PLAYED "<<"   RUN SCORED"<<endl;
                            while(file4.read((char*)&p,sizeof(p)))
                                {
                                    p.viewdata();
                                }

                            getch();
                            file4.close();
                            system("cls");
                            goto t;
                            break;
            }
           case 4:
            {

                        int id,i;
                       isfound=0;
                       fstream fi;
                       cout<<endl<<"Enter ID of player to be searched:";
                       cin>>id;
                       fstream file4("players.txt",ios::in|ios::out|ios::app);
                       file4.seekg(0,ios::beg);
                       while(file4.read((char *)&p,sizeof(p)))
                       {
                           if(id==p.getid())
                           {
                               isfound==1;
                               cout<<endl<<"THE RECORD FOUND......."<<endl;
                               cout<<"ID     "<<"       NAME       "<<"  AGE "<<"     ADDRESS      "<<" SEX  "<<"  JURSEY NO. "<<"    TEAM NAME "<<"   MATCH PLAYED "<<"   RUN SCORED"<<endl;
                               p.viewdata();
                               file4.close();
                               fi.open("cricket.txt",ios::in|ios::out|ios::app);
                               while(fi.read((char*)&s,sizeof(s)))
                               {

                                   if(id==s.getid())
                                   {
                                       s.allrecord();
                                   }
                               }

                               fi.close();
                               isfound=1;
                               getch();
                               system("cls");
                              goto t;
                           }
                       }
                         if(isfound==0)
                         {
                           cout<<endl<<"Data not found for player id:"<<id<<endl;
                           getch();
                           system("cls");
                           goto t;

                        }


            }
         case 5:
         	{
         		int recordno=0,id;
         		cout<<endl<<"RECORD IS BEING MODIFIED......."<<endl;
         		cout<<"Enter the players id to be updated:";
         		cin>>id;
         		isfound=0;
         		fstream file4("players.txt",ios::in|ios::out);
         		while(file4.read((char*)&p,sizeof(p)))
         		{
         			recordno++;
         			if(id==p.getid())
         			{
         				cout<<endl<<"The old record of player having ID"<<id<<"is:"<<endl<<endl;
         				cout<<"ID     "<<"       NAME       "<<"  AGE "<<"     ADDRESS      "<<" SEX  "<<"  JURSEY NO. "<<"    TEAM NAME "<<"   MATCH PLAYED "<<"   RUN SCORED"<<endl;
         				p.viewdata();
         				isfound=1;
         				break;
					 }

				 }
				 if(isfound==1)
				 {
				 file4.clear();
				 int location=((recordno-1)*sizeof(p));
				 file4.seekp(location,ios::beg);
				 cout<<endl<<"Enter new record for player ID:"<<id<<endl;
				 p.getdata();
				 file4.write((char*)&p,sizeof(p));
				 cout<<endl<<"RECORD IS UPDATED SUCESSIFULLY!!";
				 file4.close();
				 getch();
				 system("cls");
				 goto t;
				 break;
				 }
				 if(isfound==0)
				 {
				 	cout<<endl<<"Data not found for player ID:"<<id;
				 	getch();
				 	system("cls");
				 	goto t;
				 	break;
				 }


			 }
		    case 6:
			 	{

			 		int record,id,pid;
			 		cout<<endl<<"Enter the players id to be deleted:";
			 		cin>>id;
			 		isfound=0;
                    fstream f("players.txt",ios::in|ios::out);
                    fstream temp("temp.txt",ios::out|ios::app|ios::in);
                    f.seekg(0,ios::beg);

			 	    while(f.read((char*)&p,sizeof(p)))
                     {
			 	    	record++;
			 	    	pid=p.getid();
                       if(id==pid)
			 	    	  {

			 	        	cout<<endl<<endl<<"The old record of players having ID "<<id<<" is:"<<endl<<endl;
			 	        	cout<<"ID     "<<"       NAME       "<<"  AGE "<<"     ADDRESS      "<<" SEX  "<<"  JURSEY NO. "<<"    TEAM NAME "<<"   MATCH PLAYED "<<"   RUN SCORED"<<endl;
			 	        	p.viewdata();
			 	        	isfound=1;
			 	    	  }
			 	    	  if(id!=pid)
			 					{
			 						temp.write((char*)&p,sizeof(p));
								 }

                     }
                             f.close();
							 temp.close();
						     remove("players.txt");
						     rename("temp.txt","players.txt");

                     fstream fi("cricket.txt",ios::in|ios::out|ios::app|ios::binary);
                     fstream t("temp.txt",ios::out|ios::app|ios::in);
                     f.seekg(0,ios::beg);

                     while(fi.read((char*)&s,sizeof(s)))
                     {
                            pid=s.getid();
                            if(id!=pid)
			 					{
			 						t.write((char*)&s,sizeof(s));
								 }
                     }
                             fi.close();
							 t.close();
						     remove("cricket.txt");
						     rename("temp.txt","cricket.txt");

			 		if(isfound==0)
			 			{
						 	cout<<endl<<"Data is not found for player id:"<<id;
						 	getch();
						 	system("cls");
						 	break;

						 }
                    else
                    {
                        cout<<endl<<endl<<"                   THIS RECORD IS SUCCESSFULLY DELETED!!!"<<endl;
						     getch();
						     system("cls");
                    }
						 goto t;



				}
			case 7:
				{
					exit(0);
					break;
				}
			default:
			{
				cout<<"    INVALID OPTION!!  ";
				getch();
				system("cls");
				goto t;
				}
    	}
    }


	else
	{
	    i--;
		cout<<"					INVALID USERNAME OR PASSWORD !!!"<<endl<<endl;

		if(i>0)
		{
		    cout<<"                 YOU HAVE "<<i<<"times remainings!!"<<endl;
			getch();
			system("cls");
            goto top;

		}
		else if(i==0)
		{
		    cout<<"       SORRY YOUR REMAINING TIME COMPLETED  !!!!"<<endl;
		    exit(0);
		}

		else
		{
		        getch();
		        system("cls");

		}

	}


    return 0;





}
