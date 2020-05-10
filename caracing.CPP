#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<process.h>
#include<stdlib.h>
#include<dos.h>
#include<ctype.h>

void game()
{
	int i,k,r,y,z,o,p,c;
	long s;
	char ch,pass;
	cleardevice();
	setbkcolor(BLACK);         	//STILL GAME
	setfillstyle(1,LIGHTGREEN);     //FIELD
	bar(0,0,150,480);
	bar(490,0,640,480);
	setfillstyle(1,DARKGRAY);       //ROAD
	bar(155,0,485,480);
	r=random(325)+165;
	o=30;
	p=0;
	s=0;
	c=0;
	cout<<"Score"<<endl<<endl;            //SCORE DISPLAY
	cout<<"Speed"<<endl;            	//SPEED DISPLAY
	cout<<o<<endl;
//	gotoxy();
	cout<<"Enter Password"<<endl;
	pass=getch();
	cout<<"*"<<endl;
	if (pass==67)                          //PASSWORD
	{
		cout<<"Correct"<<endl;
		cout<<"Cheats Activated"<<endl;
		p=10;
		cout<<"Enter Score You Want To Start From"<<endl;
		cin>>s;
		gotoxy(1,2);
		cout<<s;
		c=100;
	}
	else
		cout<<"Incorrect";
	for(i=0,y=0,k=0,o,z=0 ; ; k++)
	{
	setcolor(RED);
	setfillstyle(1,BLACK);
	fillellipse(r,y,10,10);         //OBSTACLE
		if (kbhit())
		{
			if (i<=-140||i>=140)	//BORDER GO
			{
				setcolor(RED);
				settextstyle(0,0,5);
				outtextxy(160,200,"GAMEOVER");
				getch();
				cout<<endl<<endl<<"ENTER R FOR RETRY OR PRESS ANY KEY TO EXIT";
				ch=getch();
				if( ch=='r'||ch=='R' )		//FOR BACK
					game();
				else
					exit(0);
			}
			delay(10);
			setcolor(DARKGRAY);             //CAR MOVEMENT
			setfillstyle(1,DARKGRAY);
			pieslice(320+i,410,0,180,25);
			bar(295+i,410,345+i,460);
			bar(300+i,410,340+i,412);
			bar(296+i,420,306+i,450);
			bar(334+i,420,344+i,450);
			bar(296+i,435,306+i,435);
			bar(334+i,435,344+i,435);
			bar(332+i,460,337+i,465);
			ch=getch();
			if(ch==27)                      //ESC
				break;
			if (ch=='a'||ch=='A'||ch==75)           //LEFT
				i=i-5-p;
			if (ch=='d'||ch=='D'||ch==77)           //RIGHT
				i=i+5+p;
			setcolor(DARKGRAY);
			setfillstyle(1,YELLOW);
			pieslice(320+i,410,0,180,25);
			setfillstyle(1,BROWN);
			bar(295+i,410,345+i,460);
			setfillstyle(1,BLACK);
			bar(300+i,410,340+i,412);
			setfillstyle(1,DARKGRAY);
			bar(296+i,420,306+i,450);
			bar(334+i,420,344+i,450);
			setfillstyle(1,BLACK);
			bar(296+i,435,306+i,435);
			bar(334+i,435,344+i,435);
			bar(332+i,460,337+i,465);
		}
			setcolor(LIGHTGREEN);               //TREES MOVEMENT
			setfillstyle(1,LIGHTGREEN);
			fillellipse(70,-60+k,20,15);
			fillellipse(70,40+k-1,20,15);
			fillellipse(70,140+k-1,20,15);
			fillellipse(70,240+k-1,20,15);
			fillellipse(70,340+k-1,20,15);
			fillellipse(70,440+k-1,20,15);
			fillellipse(560,-60+k,20,15);
			fillellipse(560,40+k-1,20,15);
			fillellipse(560,140+k-1,20,15);
			fillellipse(560,240+k-1,20,15);
			fillellipse(560,340+k-1,20,15);
			fillellipse(560,440+k-1,20,15);
			setfillstyle(1,GREEN);
			fillellipse(70,-60+k,20,15);
			fillellipse(70,40+k,20,15);
			fillellipse(70,140+k,20,15);
			fillellipse(70,240+k,20,15);
			fillellipse(70,340+k,20,15);
			fillellipse(70,440+k,20,15);
			fillellipse(560,-60+k,20,15);
			fillellipse(560,40+k,20,15);
			fillellipse(560,140+k,20,15);
			fillellipse(560,240+k,20,15);
			fillellipse(560,340+k,20,15);
			fillellipse(560,440+k,20,15);
			if (k==100)                         //LOOP OF TREES
				k=k-100;
			delay(1);
			setcolor(DARKGRAY);                 //OBSTACLES
			setfillstyle(1,DARKGRAY);
			fillellipse(r,y,10,10);
			if (y>=450)            		    //OBSTACLE RESET
			{
				y=0;
				r=random(325)+165;
				s++;                        //SCORE INCREASE
				z++;                        //SPEED INCREASE
				o+=30;
				gotoxy(1,2);
				cout<<s;
				gotoxy(1,4);
				cout<<o;
			}
			if ((295+i<=(r+10) && (r-10)<=345+i) && y>=385+c)     //OBSTACLE GO
			{
				settextstyle(0,0,5);
				setcolor(RED);
				outtextxy(160,200,"GAMEOVER");
				cout<<"ENTER R FOR RETRY OR PRESS ANY KEY TO EXIT";
				ch=getch();
				if( ch=='r'||ch=='R' )		//FOR BACK
					game();
				else
					exit(0);

			}
			y++;                              //OBSTACLE DOWN
			y+=z;                             //SPEED WITH OBSTACLE
	}
}

void main()
{
	clrscr();
	int i,j;
	char choice,ch;
	textbackground(BLACK);
	gotoxy(35,10);
	cout<<"±±±±±±±±±±±";
	for (i=0 ; i<=10 ; ++i)		//LOADING SCREEN
	{
		gotoxy(35+i,10);
		cout<<"²";
		if(i%2==0)
		{
			gotoxy(35,15);
			cout<<"Loading..."<<endl;
			delay(200);
		}
	delay(40);
	}
	cout<<"Press Any Key To Continue";
	getch();
	int driver = DETECT , mode ;
	initgraph(&driver,&mode,"c:\\turboc3\\bgi");
	setbkcolor(RED);
	settextstyle(0,0,3);
	for( i=-200,j=-250 ; i<110,j<50 ; ++i,++j )       //MOVEMENT OF TITLE
	{
		setcolor(YELLOW);
		outtextxy(i,j,"Driving Stimulator");
		setcolor(RED);
		outtextxy(i,j,"Driving Stimulator");
		delay(5);
	}
START:	setbkcolor(RED);                             //MENU
	setcolor(YELLOW);
	outtextxy(i,j,"Driving Stimulator");
	setcolor(GREEN);
	outtextxy(250,170,"START");
	outtextxy(170,220,"INSTRUCTIONS");
	outtextxy(200,270,"HIGHSCORE");
	outtextxy(260,320,"EXIT");
	outtextxy(225,370,"CREDITS");
	gotoxy(1,1);
	choice=getch();                        //ENTERING THE MENU
	switch(tolower(choice))
	{
		case 's':                      //START
			game();
			ch=getch();
			if( ch=='b' ||ch=='B' )		//FOR BACK
			{
				cleardevice();
				goto START;
			}
			break;
		case 'i':                      //INSTRUCTIONS
			cleardevice();
			cout<<endl<<endl<<endl<<" Welcome to the World of Driving Stimulator. This game helps you to learn the"
			<<endl<<" basics of driving and enjoy the feeling of driving the car in both virtual and"
			<<endl<<" in real life."<<endl<<endl<<endl
			<<" The controls are as follows"<<endl
			<<" A   Left"<<endl<<" D   Right"<<endl<<endl
			<<" 		       !Have Fun and Drive Carefully!"
			<<endl<<endl<<endl<<endl<<endl<<" Enter B for Back";
			ch=getch();
			if( ch=='b' ||ch=='B' )		//FOR BACK
			{
				cleardevice();
				goto START;
			}
			break;
		case 'h':                      //HIGHSCORE
			cleardevice();
			cout<<endl<<" S No.			Name			Score"<<endl
			<<endl<<" 1.			Saiyam			 1000"<<endl
			<<" 2.			Mandeep			  600"<<endl
			<<" 3.			Sidharth		   50"<<endl
			<<" 4.			Harsh		  	   20"<<endl
			<<endl<<endl<<endl<<endl<<endl<<" Enter B for Back";
			ch=getch();
			if( ch=='b' ||ch=='B' )		//FOR BACK
			{
				cleardevice();
				goto START;
			}
			break;
		case 'e':                      //EXIT
			exit(0);
			break;
		case 'c':                      //CREDITS
			cleardevice();
			cout<<endl<<" The Following Game has been made Saiyam Kalra "<<endl
			<<endl<<endl<<" Enter B for Back";
			ch=getch();
			if( ch=='b' ||ch=='B' )         //FOR BACK
			{
				cleardevice();
				goto START;
			}
			break;
		default:
			cout<<"Wrong Entry!";
			goto START;
	}
	getch();
}
