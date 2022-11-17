#include<iostream>
#include<conio.h>
#include<iomanip>
#include<string.h>
#include<fstream>
#include<windows.h>

using namespace std;

void HOME();
void ADMIN();
void USER();

class AIRLINE
{
      int flcode;
      char flname[40];	
      char from[40];
	  char to[40];
	  char date[15];
      public:
             void INPUT()
             {
				cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
			    cout<<"\t\t\t\t\t\t\t\t ------------------------------------------------------- \n";
			    cout<<"\t\t\t\t\t\t\t\t                  	   	                    			\n";  
			    cout<<"\t\t\t\t\t\t        				ENTER DETAILS  		            		\n";
			    cout<<"\t\t\t\t\t\t\t\t                  		                				\n";
			    cout<<"\t\t\t\t\t\t\t\t ------------------------------------------------------- \n";
			    cout<<"\t\t\t\t\t\t\t\t                  		                				\n";
			    cout<<"\t\t\t\t\t\t	    		FLIGHT CODE			: 	";     	            		
			    cin>>flcode;
			    cin.ignore();
			    cout<<"\t\t\t\t\t\t\t\t                  		                				\n";
			    cout<<"\t\t\t\t\t\t\t     		FLIGHT NAME			: 	";      	    
				cin.getline(flname,40);       	    
			    cout<<"\t\t\t\t\t\t\t\t                  		                				\n";
			    cout<<"\t\t\t\t\t\t\t     		DEPARTURE POINT			: 	";
				cin.getline(from,40);
			    cout<<"\t\t\t\t\t\t\t\t                  		                				\n";
			    cout<<"\t\t\t\t\t\t\t     		ARRIVAL POINT			:	";
				cin.getline(to,40);     	            		
			    cout<<"\t\t\t\t\t\t\t\t                  		                				\n";
			    cout<<"\t\t\t\t\t\t\t     		DATE (DD/MM/YYYY)		:	";
			    cin.getline(date,15);
			    cout<<"\t\t\t\t\t\t\t\t                  		                				\n";
			    cout<<"\t\t\t\t\t\t\t\t ------------------------------------------------------- \n\n";

             }
             void OUTPUT()
             {
				cout<<"\t\t\t\t	 "<<flcode<<setw(27)<<flname<<setw(25)<<from<<setw(23)<<to<<setw(25)<<date<<"\n\n\n";Sleep(50);
             }
             friend void SEARCH_FLIGHTS();
             friend void MOD_FLIGHTS();
             friend void DEL_FLIGHTS();
             };   

void ADD_FLIGHTS()
{
	AIRLINE a;
    ofstream f1("Flight.dat",ios::binary|ios::app);

    if(!f1)
    cout<<"FILE NOT FOUND";
    else
    {
        a.INPUT();
        f1.write((char*)&a,sizeof(a));
    }
    f1.close();
}

void DISP_FLIGHTS()
{ 
	AIRLINE a;
    ifstream f1("Flight.dat",ios::binary);
	if(!f1)
    cout<<"FILE NOT FOUND";
    else
    {
	cout<<"\n\n\n\n\n\n\n\n\n";
	cout<<"\t\t\t\t\t----------------------------------------------------------------------------------------------------------\n\n";
	cout<<"\t\t\t\t  	FLIGHT CODE"<<setw(20)<<"FLIGHT NAME"<<setw(25)<<"DEPARTURE POINT"<<setw(23)<<"ARRIVAL POINT"<<setw(20)<<"DATE\n";
	cout<<"\t\t\t\t\t----------------------------------------------------------------------------------------------------------\n\n";
    while(f1.read((char*)&a,sizeof(a)))
    {
	   a.OUTPUT();
    }
    cout<<"\t\t\t\t\t----------------------------------------------------------------------------------------------------------\n\n"; 

   }
   f1.close();
}

void SEARCH_FLIGHTS()
{
    int flag=0,flcode1;
    AIRLINE a;
    ifstream f1("Flight.dat",ios::binary);
	if(!f1)
    cout<<"FILE NOT FOUND";
    else
    {
        cout<<"\n\n\t\t\t\t\t\t\t\t	  ENTER FLIGHT CODE TO BE SEARCHED : ";
        cin>>flcode1;
        while(f1.read((char*)&a,sizeof(a)))
        if(a.flcode==flcode1)
        {
            flag=1;
	cout<<"\n\n\n\n\n\n\n\n\n";
	cout<<"\t\t\t\t\t----------------------------------------------------------------------------------------------------------\n\n";
	cout<<"\t\t\t\t  	FLIGHT CODE"<<setw(20)<<"FLIGHT NAME"<<setw(25)<<"DEPARTURE POINT"<<setw(23)<<"ARRIVAL POINT"<<setw(20)<<"DATE\n";
	cout<<"\t\t\t\t\t----------------------------------------------------------------------------------------------------------\n\n";
	a.OUTPUT();
        cout<<"\t\t\t\t\t -------------------------------------------------------------------------------------------------------\n\n"; 
        }
    f1.close();
    if(flag==0)
    cout<<"\n\n\n\t\t\t\t\t\t\t\t\tRECORD NOT FOUND ";
    }
}

void MOD_FLIGHTS()
{
    int flag=0,flcode1;
    AIRLINE a;
    ifstream f1("Flight.dat",ios::binary);
    ofstream f2("Temp.dat",ios::binary|ios::app);
    if(!f1)
    cout<<"FILE NOT FOUND";
    else
    {
        cout<<"\n\n\t\t\t\t\t\t\t\t	  ENTER FLIGHT CODE TO BE MODIFIED : ";
        cin>>flcode1;
        while(f1.read((char*)&a,sizeof(a)))
        if(flcode1==a.flcode)
        {
            flag=1;
            a.INPUT();
            f2.write((char*)&a,sizeof(a));
       }
        else
	f2.write((char*)&a,sizeof(a));
    }
    f1.close();
    f2.close();
    if(flag==0)
    cout<<"RECORD NOT FOUND ";
    remove("Flight.dat");
    rename("Temp.dat","Flight.dat");
}

void DEL_FLIGHTS()
{
    int flag=0,flcode1;
    AIRLINE a;
    ifstream f1("Flight.dat",ios::binary);
    ofstream f2("Temp.dat",ios::binary|ios::app);
	if(!f1)
   cout<<"FILE NOT FOUND";
   else
   {
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t	  ENTER FLIGHT CODE TO BE DELETED : ";
        cin>>flcode1;
        while(f1.read((char*)&a,sizeof(a)))
        {
			if(flcode1==a.flcode)
			flag=1;
			else if(flcode1!=a.flcode)
	        {
	           f2.write((char*)&a,sizeof(a));
	        }
		}
   }
   f1.close();
   f2.close();
   if(flag==1)
   cout<<"\n\n\t\t\t\t\t\t\t\t\t\tRECORD FOUND AND DELETED ";
   else //if(flag==1)
   cout<<"\n\n\t\t\t\t\t\t\t\t\t\tRECORD NOT FOUND";
    
   remove("Flight.dat");
   rename("Temp.dat","Flight.dat");
}

class PASSENGER
{
      char name[50];
	  char ppno[20];
	  char date[15];
	  char from[30];
	  char to[30];
	  char iclass[20];
	  int age;
      
	   public:
       void ACCEPT()
       {
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		    cout<<"\t\t\t\t\t\t ------------------------------------------------------------------------- \n";
		    cout<<"\t\t\t\t\t\t                  														  \n";  
		    cout<<"\t\t\t\t\t        				ENTER DETAILS  										  \n";
		    cout<<"\t\t\t\t\t\t                  														  \n";
		    cout<<"\t\t\t\t\t\t ------------------------------------------------------------------------  \n";
		    cout<<"\t\t\t\t\t\t\t\t                  													  \n";
		    cin.ignore();
		    cout<<"\t\t\t\t    			  NAME					:  ";     			
		    cin.getline(name,50);
		    cout<<"\t\t\t\t\t\t\t\t                  													  \n";
		    cout<<"\t\t\t\t    			  PASSPORT NO.				:  ";      	
			cin.getline(ppno,20); 	
		    cout<<"\t\t\t\t\t\t\t\t                  													  \n";
		    cout<<"\t\t\t\t    			  DATE OF DEPARTURE (DD/MM/YYYY)	:  ";
			cin.getline(date,15); 
		    cout<<"\t\t\t\t\t\t\t\t                  													  \n";
		    cout<<"\t\t\t\t    			  ORIGIN	                        :  ";
			cin.getline(from,30);   			
		    cout<<"\t\t\t\t\t\t\t\t                  													  \n";
		    cout<<"\t\t\t\t    			  DESTINATION				:  ";
		    cin.getline(to,30);
		    cout<<"\t\t\t\t\t\t\t\t                  													  \n";
		    cout<<"\t\t\t\t    			  CLASS (ECONOMY / BUSINESS /FIRST)	:  ";
		    cin.getline(iclass,20);
		    cout<<"\t\t\t\t\t\t\t\t                  													  \n";
		    cout<<"\t\t\t\t    			  AGE					:  ";
		    cin>>age;
		    cout<<"\t\t\t\t\t\t\t\t                  												      \n";
		    cout<<"\t\t\t\t\t\t ------------------------------------------------------------------------ \n\n";
		    cout<<"\t\t\t\t\t\tYOUR BOOKING HAS BEEN SUCCESSFUL !";
	}
       void DISP()
        {  
			float fare;
			if(strcmpi(iclass,"ECONOMY")==0)
			fare=7000;
			else if(strcmpi(iclass,"BUSINESS")==0)
			fare=10000;
			else if(strcmpi(iclass,"FIRST")==0)
			fare=50000;
			system("cls");
            cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\t\t\n";
			cout<<"\t\t\t\t\t ------------------------------------------------------------------------------------------------\n";Sleep(50);
			cout<<"\t\t\t\t\t																								  \n";Sleep(50);
			cout<<"\t\t\t							BOARDING PASS															  \n";Sleep(50);
			cout<<"\t\t\t\t\t																								  \n";Sleep(50);
			cout<<"\t\t\t\t\t ------------------------------------------------------------------------------------------------\n";Sleep(50);
			cout<<"\t\t\t\t\t																								  \n";Sleep(50);
			cout<<"\t\t\t\t\t 			PASSENGER INFORMATION : 															  \n";Sleep(50);
			cout<<"\t\t\t\t\t																								  \n";Sleep(50);
			cout<<"\t\t\t\t\t 			NAME : "<<name<<																	 "\n";Sleep(50);																				
			cout<<"\t\t\t\t\t 			AGE  : "<<age<<																		 "\n";Sleep(50);																				
			cout<<"\t\t\t\t\t																								  \n";Sleep(50);
			cout<<"\t\t\t\t\t ------------------------------------------------------------------------------------------------\n";Sleep(50);
			cout<<"\t\t\t\t\t																								  \n";Sleep(50);
			cout<<"\t\t\t\t\t 			FLIGHT INFORMATION : 																  \n";Sleep(50);
			cout<<"\t\t\t\t\t																								  \n";Sleep(50);
			cout<<"\t\t\t\t\t 			DATE 		: "<<date<<																	 "\n";Sleep(50);																				
			cout<<"\t\t\t\t\t 			ORIGIN 		: "<<from<<																	 "\n";Sleep(50);																			
			cout<<"\t\t\t\t\t 			DESTINATION 	: "<<to<<																 "\n";Sleep(50); 																		
			cout<<"\t\t\t\t\t 			FLIGHT 		: BOING 747																	  \n";Sleep(50);
			cout<<"\t\t\t\t\t																								  \n";Sleep(50);
			cout<<"\t\t\t\t\t ------------------------------------------------------------------------------------------------\n";Sleep(50);
			cout<<"\t\t\t\t\t																								  \n";Sleep(50);
			cout<<"\t\t\t\t\t 			TICKET INFORMATION : 																  \n";Sleep(50);
			cout<<"\t\t\t\t\t																								  \n";Sleep(50);
			cout<<"\t\t\t\t\t 			CLASS  : "<<iclass<<																 "\n";Sleep(50);																	
			cout<<"\t\t\t\t\t 			STATUS : CONFIRMED																	  \n";Sleep(50);           
		    cout<<"\t\t\t\t\t 			COST   : Rs "<<fare<<"																  \n";Sleep(50);
			cout<<"\t\t\t\t\t																								  \n";Sleep(50);
			cout<<"\t\t\t\t\t ------------------------------------------------------------------------------------------------\n";Sleep(50);
			cout<<"\t\t\t\t\t																								  \n";Sleep(50);
			cout<<"\t\t\t\t\t 			BAGGAGE ALLOWED : 300 KGS 															  \n";Sleep(50);           
			cout<<"\t\t\t\t\t			CONTACT AIRLINES TO CONFIRM BAGGAGE ALLOWANCE									      \n";Sleep(50);
			cout<<"\t\t\t\t\t																								  \n";Sleep(50);
			cout<<"\t\t\t\t\t ------------------------------------------------------------------------------------------------\n";Sleep(50);
			cout<<"\t\t\t\t\t																								  \n";Sleep(50);
			cout<<"\t\t\t\t\t 				GOOD BYE AND HAVE A SAFE JOURNEY 												  \n";Sleep(50);
			cout<<"\t\t\t\t\t																								  \n";Sleep(50);
			cout<<"\t\t\t\t\t ------------------------------------------------------------------------------------------------\n\n";Sleep(50);    
		} 
        friend void CANCEL();
        friend void DISPLAY();
};

void BOARDING_PASS()
{
	PASSENGER p;
	ifstream f1("Passenger.dat",ios::binary);
	if(!f1)
	cout<<"FILE NOT FOUND ";
	else
	{
		while(f1.read((char*)&p,sizeof(p)))
		p.DISP();
		f1.close();
	}
}

void BOOK()
{
    PASSENGER p;
    ofstream f1("Passenger.dat",ios::binary|ios::app);
    p.ACCEPT();
    f1.write((char*)&p,sizeof(p));
    p.DISP();  
	f1.close();  
}

void DISPLAY()
{
    int flag=0;
    system("cls");
	PASSENGER p;
	ifstream f1("Passenger.dat",ios::binary);
	if(!f1)
	cout<<"FILE NOT FOUND ";
	else
	{
		char ppno1[20];
        cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t	  ENTER PASSPORT NUMBER : ";
        cin.ignore();
        cin.getline(ppno1,20);
		while(f1.read((char*)&p,sizeof(p)))
		if(strcmp(p.ppno,ppno1)==0)
		{
			p.DISP();
			flag=1;
		}		
	} 
	f1.close();
	if(flag==0)
	cout<<"\n\t\t\t\t\t\t\t\t\t  BOARDING PASS NOT FOUND ! ";
}

void CANCEL()
{
	int flag=0;
	char ppno1[20];
    PASSENGER p;
    ifstream f1("Passenger.dat",ios::binary);
    ofstream f2("Temp.dat",ios::binary|ios::app);
	if(!f1)
    cout<<"FILE NOT FOUND";
    else
    {
        cin.ignore();
        cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t	  ENTER PASSPORT NO. : ";
        cin.getline(ppno1,20);
        while(f1.read((char*)&p,sizeof(p)))
        if(strcmp(p.ppno,ppno1)==0)
        flag=1;
        if(strcmp(p.ppno,ppno1)!=0)
        f2.write((char*)&p,sizeof(p));
    }

    f1.close();
    f2.close();
    if(flag==0)
    cout<<"\n\t\t\t\t\t\t\t\t\t\tRECORD NOT FOUND ";
    else
    cout<<"\n\t\t\t\t\t\t\t\tBOOKING HAS BEEN CANCELLED AND THE AMOUND IS REFUNDED";
    remove("Passenger.dat");
    rename("Temp.dat","Passenger.dat");
}

void ADMIN()
{
    system("cls");
    int opt;
    char ch;
    do
    {
        system("cls");
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	    cout<<"\t\t\t\t\t\t\t\t ------------------------------------------------------- \n";Sleep(50);
	    cout<<"\t\t\t\t\t\t\t\t                  										\n";Sleep(50);  
	    cout<<"\t\t\t\t\t\t        				MENU  									\n";Sleep(50);
	    cout<<"\t\t\t\t\t\t\t\t                  										\n";Sleep(50);
	    cout<<"\t\t\t\t\t\t\t\t ------------------------------------------------------- \n";Sleep(50);
	    cout<<"\t\t\t\t\t\t\t\t                  										\n";Sleep(50);
	    cout<<"\t\t\t\t\t\t\t    			1 . ADD FLIGHTS     						\n";Sleep(50);
	    cout<<"\t\t\t\t\t\t\t\t                  										\n";Sleep(50);
	    cout<<"\t\t\t\t\t\t\t    			2 . DISPLAY FLIGHTS      		    		\n";Sleep(50);
	    cout<<"\t\t\t\t\t\t\t\t                  										\n";Sleep(50);
	    cout<<"\t\t\t\t\t\t\t    			3 . SEARCH FLIGHTS     						\n";Sleep(50);
	    cout<<"\t\t\t\t\t\t\t\t                  										\n";Sleep(50);
	    cout<<"\t\t\t\t\t\t\t    			4 . MODIFY FLIGHTS     						\n";Sleep(50);
	    cout<<"\t\t\t\t\t\t\t\t                  										\n";Sleep(50);
	    cout<<"\t\t\t\t\t\t\t    			5 . DELETE FLIGHTS     						\n";Sleep(50);
	    cout<<"\t\t\t\t\t\t\t\t                  										\n";Sleep(50);
	    cout<<"\t\t\t\t\t\t\t    			6 . RETURN TO MAIN MENU						\n";Sleep(50);
	    cout<<"\t\t\t\t\t\t\t\t                  										\n";Sleep(50);
	    cout<<"\t\t\t\t\t\t\t\t ------------------------------------------------------- \n\n";Sleep(50);
	    cout<<"\n\n\t\t\t\t\t\t\t\t\t\t CHOOSE AN OPTION : ";
	    cin>>opt;
	    switch(opt)
	    {
		    case 1 :	system("cls");
						ADD_FLIGHTS();
						break;
			
		    case 2 :	system("cls");
						DISP_FLIGHTS();
						break;
		
		    case 3 :   system("cls");
		               SEARCH_FLIGHTS();
					   break;
		
			case 4 :   system("cls");
		               MOD_FLIGHTS();  
		               break;
		
		    case 5 :   system("cls");
		               DEL_FLIGHTS();
		               break ;
	        case 6 :   system("cls");
		               HOME();
		               break ;
		    default : cout<<"\n\n\t\t\t\t\t\t\t\t\t\t CHOOSE THE CORRECT OPTION \n";
		}
	    Sleep(400);
	    cout<<"\n\n\n\t\t\t\t\t\t\t\t\t    DO YOU WANT TO CONTINUE ? (Y/N) : ";
	    cin>>ch;
	
    }while(ch=='y'||ch=='Y');
    if (ch=='n'||ch=='N')
    HOME();    
}

void USER()
{
	int opt1;
   char ch1;
	do
	{
		system("cls");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	    cout<<"\t\t\t\t\t\t\t\t ------------------------------------------------------- \n";Sleep(50);
	    cout<<"\t\t\t\t\t\t\t\t                  										\n";Sleep(50);  
	    cout<<"\t\t\t\t\t\t        				MENU  									\n";Sleep(50);
	    cout<<"\t\t\t\t\t\t\t\t                  										\n";Sleep(50);
	    cout<<"\t\t\t\t\t\t\t\t ------------------------------------------------------- \n";Sleep(50);
	    cout<<"\t\t\t\t\t\t\t\t                  										\n";Sleep(50);
	    cout<<"\t\t\t\t\t\t\t    			1 . BOOK A FLIGHT     						\n";Sleep(50);
	    cout<<"\t\t\t\t\t\t\t\t                  										\n";Sleep(50);
	    cout<<"\t\t\t\t\t\t\t    			2 . DISPLAY BOARDING PASS         			\n";Sleep(50);
	    cout<<"\t\t\t\t\t\t\t\t                  										\n";Sleep(50);
	    cout<<"\t\t\t\t\t\t\t    			3 . CANCEL A BOOKING     					\n";Sleep(50);
	    cout<<"\t\t\t\t\t\t\t\t                  										\n";Sleep(50);
	    cout<<"\t\t\t\t\t\t\t    			4 . RETURN TO MAIN MENU						\n";Sleep(50);
	    cout<<"\t\t\t\t\t\t\t\t                  										\n";Sleep(50);
	    cout<<"\t\t\t\t\t\t\t\t ------------------------------------------------------- \n\n";Sleep(50);
		cout<<"\n\n\t\t\t\t\t\t\t\t\t CHOOSE AN OPTION : ";
		cin>>opt1;
		system("cls");
		switch(opt1)
		{
			case 1 : 	system("cls");
			BOOK();
						break;
			
			case 2 :	DISPLAY();
				break;
			
			case 3 : 	system("cls");
					CANCEL();
						break;
				
			case 4 :  	system("cls");
				HOME();
				break ;
		
		default : cout<<"CHOOSE THE CORRECT OPTION \n";
		}
	cout<<"\n\n\n\t\t\t\t\t\t\t\t\tDO YOU WANT TO CONTINUE ? (Y/N) : ";
	cin>>ch1;
	}while(ch1=='y'||ch1=='Y');
	if (ch1=='n' || ch1=='N')
    HOME();
}

void HOME()
{
     system("cls");
    int opt2;
    char v[12],password[10]="cmp",ch2;
    do
    {    
		system("cls");
	    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	    cout<<"\t\t\t\t\t\t\t\t\t ----------------------------------        \n";Sleep(50);
	    cout<<"\t\t\t\t\t\t\t\t\t                  		                    \n";Sleep(50);
	    cout<<"\t\t\t\t\t\t\t        			MENU  						\n";Sleep(50);
	    cout<<"\t\t\t\t\t\t\t\t\t                  							\n";Sleep(50);
	    cout<<"\t\t\t\t\t\t\t\t\t ----------------------------------        \n";Sleep(50);
	    cout<<"\t\t\t\t\t\t\t\t\t                  							\n";Sleep(50);
	    cout<<"\t\t\t\t\t\t\t\t    			1 . ADMIN     					\n";Sleep(50);
	    cout<<"\t\t\t\t\t\t\t\t\t                  							\n";Sleep(50);
	    cout<<"\t\t\t\t\t\t\t\t    			2 . USER      					\n";Sleep(50);
	    cout<<"\t\t\t\t\t\t\t\t\t                  							\n";Sleep(50);
	    cout<<"\t\t\t\t\t\t\t\t    			3 . EXIT     					\n";Sleep(50);
	    cout<<"\t\t\t\t\t\t\t\t\t                  							\n";Sleep(50);
	    cout<<"\t\t\t\t\t\t\t\t\t -----------------------------------       \n\n";Sleep(50);

	    cout<<"\n\n\t\t\t\t\t\t\t\t\t CHOOSE AN OPTION : ";
	    cin>>opt2;
	    system("cls");
	    switch(opt2)
	    {
	    case 1 :	for(int i=0;i=3;++i) 
	                    {
	                        char v[12],pass[10]="cmp";
                            i=0;
                            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n";
                            cout<<"\t\t\t\t\t\t\t\t  ---------------------------------------------             \n";
                            cout<<"\t\t\t\t\t\t\t                                                        \n";
                            cout<<"\t\t\t\t\t\t\t\t\t\t ENTER PASSWORD: \n\n\n";
                            cout<<"\t\t\t\t\t\t\t         \t\t     ";
                            v[i]=getch();
                            while(v[i]!=13)
	                        {
	                            cout<<"*";
	                            ++i;
	                            v[i]=getch();
							}
	                        v[i]='\0';
	                        if(strcmp(password,v)!=0)
	                            cout<<"\n\n\t\t\t\t\t\t\t\t\t   SORRY! INCORRECT PASSWORD!\n\n\t\t\t\t\t\t\t\t\t   PRESS ANY KEY AND TRY AGAIN ";
	                            getch();
	
	                        if(strcmp(password,v)==0)
	                        {
	                            cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\tACCESS GRANTED!";
	                            cout<<"\n\n\n\n\t\t\t\t\t\t\t\t";
	                            getch();
	                            ADMIN(); 
	                            break;
	                    }
	                    else
	                    cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t   ACCESS DENIED!";
	                    system("cls");
	                }
	                break;
	
	    case 2 :    USER();
					break;
	
	    case 3 :    system("cls");
	                cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tEXITING";
	                getch();
	                exit(0);
	    default : cout<<"CHOOSE THE CORRECT OPTION\n";
	   }    
	   cout<<"\n\n\n\t\t\t\t\t\t\t\t\tDO YOU WANT TO go back to main menu ? (Y/N) : ";
	   cin>>ch2;
	} while(ch2=='y'||ch2=='Y');
	system("cls");
} 

int main()
{
	HOME();
	getch();
	return 0;
}
