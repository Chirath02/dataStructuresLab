#include<iostream>
#define Max 10
using namespace std;

class mulstack
{
	int arr[Max];
	int top[Max];
	int ns;
	public:
	mulstack ( int n=1)
	{	ns=n;
		int seg;
		seg= Max/ns;
		cout<<"Tops: ";
		for(int i=0; i<ns; i++)
		{	top[i]=-1+ i*seg;
			cout<<top[i]<<" ";
		}
		cout<<endl;
		for(int i=0; i<Max;  i++)
			arr[i]=-999;
		
	}
	bool spacethere()
	{
		for(int i=0; i<ns; i++)
			if(arr[i]==-999)
				return 1;
		return 0;
	}
	void tops()
	{
		cout<<"\nTops: ";
		for(int i=0; i<ns; i++)
			cout<<top[i]<<" ";
	}
	bool makespace(int cur)
	{	if(!spacethere() )
			return 0;
		for(int i=0; i<Max && i< top[cur]; i++)
		{
			if(arr[i]==-999)
			{
				for(int j=i; j<Max && j<top[cur] ; j++)
				{
					arr[j]=arr[j+1];	
				}
				// Also make all tops that are left of cur as top-1
				for(int k=0; k<cur; k++)
					top[k]--;
				return 1;
			}
		}
		for(int i=Max-1; i>=0&& i> top[cur]; i--)
		{
			if(arr[i]==-999)
			{
				for(int j=i; j>=0 && j>top[cur] ; j--)
				{
					arr[j]=arr[j-1];	
				}
				for(int k=cur+1; k<ns; k++)
					top[k]++;
				return 1;
			}
		}
		return 0;
	}
	
						// move all left to left and right to right
	void push( int ele, int stk)
	{	int cur_stk=stk-1;
		int temp;
		temp= top[cur_stk];
		
		if( arr[temp+1] == -999 &&( (top[cur_stk] < top[cur_stk+1] ) || stk==ns) )
		{	arr[ ++top[cur_stk] ] = ele;
			for(int i=stk;i>0 &&i<ns-1; i++)
			{
				if(top[stk]>top[stk+1])
					top[stk+1]++;
			}
		}
		else if(arr[temp+1] == -999 && (top[cur_stk] == top[cur_stk+1] ) )
		{
			top[cur_stk+1] ++;
			arr[ ++top[cur_stk] ] = ele;
			for(int i=stk;i>0 &&i<ns-1; i++)
			{
				if(top[stk]>top[stk+1])
					top[stk+1]++;
			}
		}
		else if(makespace(cur_stk))
				 arr[ top[cur_stk] ] = ele;
		else
			cout<<"Array is full. "<<endl;
		
	}
	int pop(int stk)
	{
		int cur=stk-1;
		// underflow is when top of current is less than the top of left stacks
		for(int i=0; i< cur; i++)
		{	if( top[cur]< top[i] || top[cur]<0)
			{	cout<<"Underflow"<<endl;
				return -999;
			}
		}
		arr[top[cur] ]=-999;
		top[cur]--;
	}
	void disp(int stk)
	{
		int cur=stk-1;
		cout<<"Displaying stack #"<<stk<<endl;
		for(int i=top[cur]; i>=0 && i> top[cur-1] && arr[i]!=-999 ; i--)
		{	cout<<arr[i]<<"  ";
		}
	}
	void disp()
	{	cout<<"\nDisplaying array"<<endl;
		for(int i=0; i< Max; i++)
			cout<<arr[i]<<" ";
		cout<<endl;
		tops();
		cout<<endl;
	}
};
		
	
int main()
{
	char ch;
	int ele,stk;
	int ns;
	cout<<"Enter number of stacks:";
	cin>>ns;
	if(ns>Max)
	{	cout<<"Number of stacks is greater than array size.Aborting.";
		return 0;
	}	
		
	int c;
	mulstack a(ns);
	do
	{	cout<<"1.Push 2.Pop 3.Abort"<<endl;
		cin>>c;
		switch(c)
		{	case 1:	cout<<"Enter stack and element ";
					cin>>stk>>ele;
					a.push(ele,stk);
					a.disp(stk);
					a.disp();
					break;
			case 2: cout<<"Enter stack number: ";
					cin>>stk;
					a.pop(stk);
					a.disp(stk);
					a.disp();
					break;
			default:return 0;
		}
		cout<<"Enter $ to push again ";
		cin>>ch;
	}
	while( ch=='$');
	
	
	return 0;
	
}
