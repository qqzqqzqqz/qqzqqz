#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<string.h>
#include<vector>
#include<stack>
using namespace std;
void TakeKeywords(string s);//��ȡ�ؼ��ֲ�����ɸѡ 
void Calculate1a2(string a[]);
void Calculate3a4(); 
void output(int Level);
string key_word[32] = {
	"auto","break","case","char","const","continue","default","double",
	"do","else","enum","extern","float","for","goto","if","int","long",
	"register","return","short","signed","sizeof","static","struct",
	"switch","typedef","union","unsigned","void","volatile","while"};
int keyword_num = 0;
int switch_num = 0;
int ifelse_num = 0;
int case_num[500] = {0};//ͳ��ÿ��switch ��Ӧ��case���� 
int case_cnt = 0; 
int iee_num = 0;    //if-else-else���� 
int ie_num = 0;     //if-else���� 
int top = -1;        //��Ϊ����ջ��ջ�� 
string temp1[1000];//��ŵõ����ַ��� 
string temp2[1000];//���ɸѡ����ַ��� ,��ʹ�ؼ��� 
int cnt1 = 0;        // temp1���� 
int cnt2 = 0;        // temp2���� 
vector <string> iee; //���{,},��if,elseif,else 

int main()
{
	int level;
	string filename,temp;
	char buffer[1];
	cout<<"�����ļ�·��:";	
	cin>>filename;	
	ifstream fin(filename.c_str());   
	if ( ! fin)
		{
			cout << "�ļ����ܴ�" <<endl;
		}
	else
		{
			while (getline(fin,temp))
				{           // �Ӵ����ļ�����,���ж���,���н��д��� 
				TakeKeywords(temp);			  
				}
			fin.close();    // �ر��ļ�������    
		}
	Calculate1a2(temp1);    //�����һ�εõ�������Ӣ�ĵ��� ,ɸѡ�õ��ؼ��ʲ����� ,�õ�level1,2�Ľ�� 
	Calculate3a4();         //�õ�level3,4��� 
	cout<<"����level:";
	cin>>level;
	output(level);
}

void TakeKeywords(string s)
{
	int n = s.length();
	string str;
	int flag = 0;              //�жϷ���ĸ���ַ��Ƿ���'{'��'}' ,���б�� 
	const char* p = s.data();  //��stringת��Ϊchar *[] 
	for(int i = 0;i <= n;i++)    //ÿ���ַ����д�����ж� 
	{
		if(p[i] == '{')
		{
			flag=1;
		}
		if(p[i] == '}')
		{
			flag=2;
		}		
		if((p[i] >= 'a'&&p[i] <= 'z'||p[i] >= 'A'&&p[i] <= 'Z'))
		{
			str += p[i];  //����������� ,���ַ��������� 
		}
		else 
		{
			if(str == "")//û������ĸ,�����п���������������,�����ж�,�еĻ�ѹ��iee 
			{
			 	if(flag == 1)iee.push_back("{");
			 	if(flag == 2)iee.push_back("}");
			 	flag = 0;
			 	continue;
			}
			temp1[cnt1++] = str;  
			if(str == "else")       //�ҵ���else,�ж��Ƿ���else if �����,��ô����n���ո��ض���if 
			{
				int j = i;
				while(p[j] == ' '&& j <= n)j++;  //ȥ��else��if��Ŀո� 
				if(p[j] == 'i'&&p[j+1] == 'f')
				{
					iee.push_back("else_if");
					i = j+2;
					keyword_num++;
				}
				else iee.push_back("else");

			}
			if(str == "if")                   // �ҵ���if�ж�ǰһ���Ƿ�Ϊelse ,���Ǿͽ�ifѹ�� 
			{

			 	if(iee.back() != "else")iee.push_back("if");
			}
			if(flag == 1)iee.push_back("{");
			if(flag == 2)iee.push_back("}");
			flag = 0;
			str = "";
			continue;
		}
	}
}

void Calculate1a2(string a[])
{
	int i,j;
	for(i = 0;i < cnt1;i++)
	{
		for(j = 0;j <= 31;j++)//�ж���������ǲ�����Ҫ�Ĺؼ��� 
		{
		    if(a[i] == key_word[j])
		  	{
			  	keyword_num++;       //ͳ�ƹؼ��� 
			  	temp2[cnt2++] = a[i];  //���ؼ���ת�Ƶ�temp2,����ɸѡ 
		    }
		}
		if(a[i] == "switch")
		{ 
			switch_num++;
			case_cnt++; 
		}
		if(a[i] == "case")
		{
			case_num[case_cnt]++;
	    }
	}
}

void Calculate3a4() 
{
	stack <string> s;  
	stack <int> have_elseif; 
	for (int i = 0;i < iee.size();i++) 
	{
		if (iee[i] == "{") 
		{
			s.push("{");
			have_elseif.push(0);
		}
		else if (iee[i] == "}") 
		{  
			while (s.top() != "{") 
			{
				s.pop();
			}
			s.pop();
			have_elseif.pop();
		}
		else if (iee[i] == "if") 
		{  
			s.push("if");
			have_elseif.pop();
			have_elseif.push(0);
		}
		else if (iee[i] == "else_if") 
		{
			have_elseif.pop();
			have_elseif.push(1);
		}
		else if (iee[i] == "else") 
		{  
			if (have_elseif.top()) 
			{
				iee_num++;
			}
			else 
			{
				ie_num++;
			}
			have_elseif.pop();
			have_elseif.push(0);
			while (s.top() != "if") 
			{ 
				s.pop();
			}
			s.pop();
		}
	}
}
void output(int Level)
{
	if(Level == 1)
	{
		cout<<"total num: "<<keyword_num<<endl;
	}
	if(Level == 2)
	{
		cout<<"total num: "<<keyword_num<<endl;
		cout<<"switch num: "<<switch_num<<endl;
		cout<<"case num: ";
		for(int i = 1;i <= case_cnt;i++)
		{
			cout<<case_num[i]<<" ";
		}
		cout<<endl;
	}
	if(Level == 3)
	{
		cout<<"total num: "<<keyword_num<<endl;
		cout<<"switch num: "<<switch_num<<endl;
		cout<<"case num: ";
		for(int i = 1;i <= case_cnt;i++)
		{
			cout<<case_num[i]<<" ";
		}
		cout<<endl;
		cout<<"if-else num: "<<ie_num<<endl;
	}
	if(Level == 4)
	{
		cout<<"total num: "<<keyword_num<<endl;
		cout<<"switch num: "<<switch_num<<endl;
		cout<<"case num: ";
		for(int i = 1;i <= case_cnt;i++)
		{
			cout<<case_num[i]<<" ";
		}
		cout<<endl;
		cout<<"if-else num: "<<ie_num<<endl;
		cout<<"if-elseif-else num: "<<iee_num<<endl;
	}
}
