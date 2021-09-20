#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<string.h>
#include<vector>
#include<stack>
using namespace std;
void TakeKeywords(string s);//获取关键字并进行筛选 
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
int case_num[500] = {0};//统计每个switch 对应的case个数 
int case_cnt = 0; 
int iee_num = 0;    //if-else-else计数 
int ie_num = 0;     //if-else计数 
int top = -1;        //作为后面栈的栈顶 
string temp1[1000];//存放得到的字符串 
string temp2[1000];//存放筛选后的字符串 ,即使关键词 
int cnt1 = 0;        // temp1计数 
int cnt2 = 0;        // temp2计数 
vector <string> iee; //存放{,},和if,elseif,else 

int main()
{
	int level;
	string filename,temp;
	char buffer[1];
	cout<<"输入文件路径:";	
	cin>>filename;	
	ifstream fin(filename.c_str());   
	if ( ! fin)
		{
			cout << "文件不能打开" <<endl;
		}
	else
		{
			while (getline(fin,temp))
				{           // 从磁盘文件输入,逐行读入,逐行进行处理 
				TakeKeywords(temp);			  
				}
			fin.close();    // 关闭文件输入流    
		}
	Calculate1a2(temp1);    //传入第一次得到的所有英文单词 ,筛选得到关键词并计算 ,得到level1,2的结果 
	Calculate3a4();         //得到level3,4结果 
	cout<<"输入level:";
	cin>>level;
	output(level);
}

void TakeKeywords(string s)
{
	int n = s.length();
	string str;
	int flag = 0;              //判断非字母的字符是否是'{'或'}' ,进行标记 
	const char* p = s.data();  //将string转化为char *[] 
	for(int i = 0;i <= n;i++)    //每个字符进行处理和判断 
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
			str += p[i];  //如果是连续的 ,则将字符进行连接 
		}
		else 
		{
			if(str == "")//没遇到字母,但是有可能遇到的是括号,进行判断,有的话压进iee 
			{
			 	if(flag == 1)iee.push_back("{");
			 	if(flag == 2)iee.push_back("}");
			 	flag = 0;
			 	continue;
			}
			temp1[cnt1++] = str;  
			if(str == "else")       //找到了else,判断是否是else if 如果是,那么隔了n个空格后必定是if 
			{
				int j = i;
				while(p[j] == ' '&& j <= n)j++;  //去掉else跟if间的空格 
				if(p[j] == 'i'&&p[j+1] == 'f')
				{
					iee.push_back("else_if");
					i = j+2;
					keyword_num++;
				}
				else iee.push_back("else");

			}
			if(str == "if")                   // 找到了if判断前一个是否为else ,不是就将if压入 
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
		for(j = 0;j <= 31;j++)//判断这个单词是不是想要的关键词 
		{
		    if(a[i] == key_word[j])
		  	{
			  	keyword_num++;       //统计关键词 
			  	temp2[cnt2++] = a[i];  //将关键词转移到temp2,二次筛选 
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
