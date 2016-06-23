#include<fstream.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<iostream.h>
//#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>

     // void punit (void);
      void deposit(void);
      void addrecord();
      void delrecord();
      void modrecord();
      void disprecord();
      void dispall();
      void withdraw();
   float w,z;
     class account
  {
		  int accountno,cls;
		  char name[30],type;
		  float deposit,withdraw;
  public:
	account()
	{
		deposit=withdraw=0;
	}
       int giveaccountno()
	{
		      return accountno;
	 }
	 void getdata(int mrno)
	{
		    accountno=mrno+1;
		    cout<<"\n ACCOUNT NUMBER        ::  ";
		    cout<<accountno<<" ";
		    cout<<"\n ENTER YOUR NAME       ::  ";
			gets(name);
		    cout<<"";
		    cout<<"\n ENTER TYPE OF ACCOUNT SAVING(s)/CURRENT(c)  ::  ";
		    cin>>type;
		    cout<<"\n ";
		    cout<<"\n ENTER INITIAL AMOUNT  ::Rs  ";cin>>deposit;
		    cout<<"\n ";
	}

  void withdrawal(int m)
   {
		   cout<<"\n AMOUNT BEFORE WITHDRAWING::Rs  "<<deposit<<"";
		   deposit=deposit-m;
		   cout<<"\n AMOUNT AFTER WITHDRAWING::Rs  "<<deposit;
    }


  void deposital(int m)
  {
		   cout<<"AMOUNT BEFORE DEPOSIT::Rs  "<<deposit<<"";
		   deposit=deposit+m;
		   cout<<"AMOUNT AFTER DEPOSIT ::Rs  "<<deposit;
  }

  void dispdata()
   {
		     int scrnt=0;
		 if(scrnt==1)
		{
		   clrscr();
		   cout<<"DISPLAY ALL MENU ";
		   scrnt=0;
		}
		    cout<<"\n ACCOUNT NUMBER              ::";
		    cout<<accountno;
		    cout<<"\n NAME OF DEPOSITER::";
		    cout<<name;
		    cout<<"\n TYPE OF ACCOUNT SAVING(s)/CURRENT(c)  ::  ";
		    cout<<type;
		    cout<<"\n BALANCE  ::Rs  ";
		    cout<<deposit;
		    scrnt++;
    }
  };

void main()
 {
	int menuch;
      // punit();
	 do{
	       clrscr();
	    // textcolor(14);
	   // textbackground(1);
	       cout<<"\n MAIN MENU  ";
	       cout<<"\n 1.NEW ACCOUNT     ";
	       cout<<"\n 2.CLOSE AN ACCOUNT ";
	       cout<<"\n 3.MODIFY AN ACCOUNT  ";
	       cout<<"\n 4.DISPLAY AN ACCOUNT ";
	       cout<<"\n 5.DISPLAY ALL RECORDS ";
	       cout<<"\n 6.WITHDRAW AMOUNT";
	       cout<<"\n 7.DEPOSIT AMOUNT";
	       cout<<"\n 8.EXIT ";
	       cout<<" \n ENTER YOUR CHOICE  ";
	       cin>>menuch;

		switch(menuch)
	      {

		   case 1:addrecord();break;
		   case 2:delrecord();break;
		   case 3:modrecord();break;
		   case 4:disprecord();break;
		   case 5:dispall();break;
		   case 6:withdraw();break;
		   case 7:deposit();break;
	      }
	}while(menuch!=8);
	getch();
   }


  void addrecord()
  {
     account obj_1,obj_2;
      fstream fout;
      fout.open("banking.txt",ios::in|ios::binary);

     if(!fout)
	{
	   cout<<"FILE OPEN ERROR  ";
	   getch();
	   return;
	}

     int recsize=sizeof(account);
     fout.seekg(0,ios::end);
     fout.seekg(-1*recsize,ios::cur);
     fout.read((char*)&obj_1,recsize);
     int mrno=obj_1.giveaccountno();
     fout.close();

     clrscr();

     cout<<"ADD MENU ";
     obj_2.getdata(mrno);
     fout.open("banking.txt",ios::app|ios::binary);
	if(!fout)
	{
		    cout<<"FILE OPEN ERROR  ";getch();return;}
		    fout.write((char*)&obj_2,recsize);
		    cout<<"RECORD ADDED TO DATABASE"<<" Press any key to continue... ";
		    getch();
		    fout.close();
	}

   void dispall()
  {
	  account obj_3;
	  fstream fout;
	  int recsize=sizeof(account);
	  int countrec=0;

	clrscr();
	 cout<<"\n DISPLAY ALL MENU ";
	fout.open("banking.txt",ios::in);
	if(!fout)
	{
	 cout<<"FILE OPEN ERROR  ";getch();return;}
	 while(fout.read((char*)&obj_3,recsize))
		{
		   obj_3.dispdata();
		   countrec++;
		   cout<<"\n PRESS ANY KEY FOR NEXT....";
		   getch();
		}
		  clrscr();
		   cout<<"\n END OF FILE.TOTALNUMBER OF RECORDS..."<<countrec;
		   cout<<" \n Press any key......";
		 getch();
		fout.close();
	}

    void disprecord()
	{
		   account obj_4;
		   fstream fout;
		   int mrno,flag=0;
		   int recsize=sizeof(account);
		   clrscr();
		   cout<<"\n DISPLAY A RECORD MENU";
		   fout.open("banking.txt",ios::in);
		    if(!fout)
		    {
			  cout<<"FILE OPEN ERROR  ";getch();return;}
			  cout<<" ENTER  THE ACCOUNT NUMBER  ";
			  cin>>mrno;
		    while(fout.read((char*)&obj_4,recsize))
		    {
		     if (obj_4.giveaccountno()==mrno)
			{
				 obj_4.dispdata();
			 cout<<"\n  Press any key.....";
			 flag=1;
			 break;
			}

		     }
		     if(flag==0)
		    {
			cout<<"\n NO SUCH ACCOUNT EXIST  ";
			cout<<"\n Press any key......";
		    }
		getch();
		fout.close();
    }

  void delrecord()
  {
	    account obj_5;
	    fstream fout,temp;
	    int mrno,flag;
	    int recsize=sizeof(account);

     clrscr();
	   cout<<" CLOSE ACCOUNT MENU ";
    fout.open("banking.txt",ios::in);
		 if(!fout)
 {
		   cout<<"FILE OPEN ERROR  ";
		    getch();
		   return;
    }
      temp.open("temp.txt",ios::app|ios::binary);
    if(!temp)
 {
		    cout<<"FILE OPEN ERROR  ";
		getch();
     return;
  }
		    cout<<"  ENTER THE ACCOUNT NUMBER ";
		cin>>mrno;
		  while(fout.read((char*)&obj_5,recsize))
   {
		 if(obj_5.giveaccountno()==mrno)
 {
		   obj_5.dispdata();
		char confirm;
		    cout<<" ARE YOU SURE TO DELETE IT(Y/N)..";cin>>confirm;
      if(confirm=='Y'||confirm=='y')
 {
		   fout.read((char*)&obj_5,recsize);
		  cout<<" RECORD DELETED FORM DATABASE";
		  cout<<"press any key....";
		      flag=1;
				 if(!fout)
		 break;
      }
		    flag=1;
     }
   temp.write((char*)&obj_5,recsize);}
		 fout.close();
    temp.close();
		    remove("banking.txt");
		  rename("temp.txt","banking.txt");
		    if(flag==0)
 {
		   cout<<"NO SUCH ACCOUNT EXIST";
		   cout<<"Press any key.....";
  }
     getch();
 }

    void modrecord()
  {
    account obj_6;
		fstream fout;
		  int mrno,flag=0;
		  int recsize=sizeof(account);
    clrscr();
		    cout<<" MODIFY RECORD MENU ";
    fout.open("banking.txt",ios::in|ios::out|ios::binary);
     if(!fout)
 {
		   cout<<"FILE OPEN ERROR  ";
		   getch();
		    return;
		   }
     fout.seekg(ios::beg);
		   cout<<" ENTER RECORD NUMBER  ";
		    cin>>mrno;
      while(fout.read((char*)&obj_6,recsize))
  {
		  if(obj_6.giveaccountno()==mrno)
  {
		clrscr();
		  cout<<" MODIFY MENU";
		      obj_6.dispdata();
      int tmprno=obj_6.giveaccountno()-1;
		      account obj_7;
		   cout<<" ENTER NEW DATA";
		     obj_7.getdata(tmprno);
		  char confirm;
      cout<<" ARE YOU SURE(Y/N)";
		cin>>confirm;
     if(confirm=='Y'||confirm=='y')
 {
				  fout.seekg(-1*recsize,ios::cur);
		       fout.write((char*)&obj_7,recsize);
		   cout<<"  RECORD MODIFIED  ";
		  cout<<"Press any key.....";
				    flag=1;
  }
     }
		  if(flag==0)
 {
				 cout<<"NO SUCH RECORD EXIST";
		       cout<<"Press any key.....";
   }
      }
				 fout.close();
		    getch();
    }

void withdraw()
    {
		     account obj_9;
		fstream fout;
    int mrno=0;
  int recsize=sizeof(account);
		   clrscr();
		       cout<<"WITHDRAWAL MENU";
		  fout.open("banking.txt",ios::in|ios::out|ios::binary);
				  if(!fout)
     {
		   cout<<"FILE OPEN ERROR  ";getch();return;}
		       fout.seekg(ios::beg);
		   cout<<"ENTER ACCOUNT NUMBER  ";
      cin>>mrno;
		      while(fout.read((char*)&obj_9,recsize))
 {
		    if(obj_9.giveaccountno()==mrno)
      {
		 clrscr();
		 cout<<"ENTER THE AMOUNT TO BE WITHDRAWED::Rs ";
    cin>>w;
		    obj_9.withdrawal(w);
				  fout.seekg(-1*recsize,ios::cur);
		   fout.write((char*)&obj_9,recsize);
  }
    }
		  fout.close();
		      getch();
  }
    

void deposit(void)
  {
		  account obj_10;
      fstream fout;
		 int mrno=1000;
      int recsize=sizeof(account);
     clrscr();
		    cout<<"\n DEPOSITAL MENU";
		fout.open("banking.txt",ios::in|ios::out|ios::binary);
   if(!fout)
 {
		  cout<<"\n FILE OPEN ERROR  ";getch();return;}
     fout.seekg(ios::beg);
		  cout<<"\n ENTER ACCOUNT NUMBER  ";
			cin>>mrno;
		  while(fout.read((char*)&obj_10,recsize))
  {
      if(obj_10.giveaccountno()==mrno)
  {
    clrscr();
     cout<<"\n ENTER THE AMOUNT TO BE DEPOSITED ::Rs ";
   cin>>w;
      obj_10.deposital(w);
  fout.seekg(-1*recsize,ios::cur);
      fout.write((char*)&obj_10,recsize);
   }
     }
  fout.close();
     getch();
   }
