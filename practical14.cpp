//to be compiled in turbo c++ as it uses dos bgi graphics library

#include<iostream.h>
#include<graphics.h>
#include<conio.h>

int t1(int n);
int t2(int n);
int t3(int n);
void drawGraph(int (*func)(int),int n);

int main()
{
	clrscr();
	int n,choice;
	cout<<"Enter n: ";
	cin>>n;
	clrscr();
	while(1)
	{
		cout<<"Select function to draw graph with ";
		cout<<"n = "<<n<<endl;
		cout<<"1- T(n) = T(n-1) + n; T(0) = 1"<<endl;
		cout<<"2- T(n) = T(n-1) + n^2; T(0) = 1"<<endl;
		cout<<"3- T(n) = 2 * T(n/2) + n; T(1) = 1"<<endl;
		cout<<"Enter 0 to exit..."<<endl;
		cout<<"Enter your choice: ";
		cin>>choice;
		switch(choice)
		{
		case 0:
			return 1;
		case 1:
			drawGraph(t1,n);
			break;
		case 2:
			drawGraph(t2,n);
			break;
		case 3:
			drawGraph(t3,n);
			break;
		default:
			cout<<"Wrong choice please try again..."<<endl;
		}
	}
}

int t1(int n)
{
	if(n==0)
		return 1;
	return t1(n-1) + n;
}

int t2(int n)
{
	if(n==0)
		return 1;
	return t2(n-1) + n*n;
}

int t3(int n)
{
	if(n<=1)
		return 1;
	return 2 * t3(n/2) + n;
}

void drawGraph(int (*func)(int),int n)
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	line(20,20,20,440);
	line(20,440,600,440);
	outtextxy(10,5,"T(N)");
	outtextxy(610,440,"N");
	setcolor(RED);
	for(int i=0;i<=n;i++)
	{
		circle(20+i*50,440-func(i)*5,2);
	}
	for(i=0;i<n;i++)
	{
		line(20+i*50,440-func(i)*5,20+(i+1)*50,440-func(i+1)*5);
	}
	getch();
	cleardevice();
}