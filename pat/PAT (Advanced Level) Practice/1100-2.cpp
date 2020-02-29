//————————————————
//版权声明：本文为CSDN博主「Leonardo1897」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
//原文链接：https://blog.csdn.net/Leonardo1897/article/details/48804523
#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <cstdlib>
 
using namespace std;
map<string,int>map1,map2;
 
void init_map1(){
	map1.insert(make_pair("tret",0));
	map1.insert(make_pair("jan",1));
	map1.insert(make_pair("feb",2));
	map1.insert(make_pair("mar",3));
	map1.insert(make_pair("apr",4));
	map1.insert(make_pair("may",5));
	map1.insert(make_pair("jun",6));
	map1.insert(make_pair("jly",7));
	map1.insert(make_pair("aug",8));
	map1.insert(make_pair("sep",9));
	map1.insert(make_pair("oct",10));
	map1.insert(make_pair("nov",11));
	map1.insert(make_pair("dec",12));
}
 
void init_map2(){
	map2.insert(make_pair("tret",0));
	map2.insert(make_pair("tam",1));
	map2.insert(make_pair("hel",2));
	map2.insert(make_pair("maa",3));
	map2.insert(make_pair("huh",4));
	map2.insert(make_pair("tou",5));
	map2.insert(make_pair("kes",6));
	map2.insert(make_pair("hei",7));
	map2.insert(make_pair("elo",8));
	map2.insert(make_pair("syy",9));
	map2.insert(make_pair("lok",10));
	map2.insert(make_pair("mer",11));
	map2.insert(make_pair("jou",12));
}
 
char str1[][8]={"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
char str2[][8]={"tret","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
 
void convert_to_mar(const char *str){
	int num = atoi(str);
	int high = num/13;
	int low = num%13;
	if(!high)
	    cout <<str1[low] <<endl;
	else{
		cout <<str2[high];
		if(low)
		    cout << ' ' <<str1[low];
		cout <<endl;
	}
}
 
void convert_to_earth(char *str){
	int size = strlen(str);
	if(size < 4){
		string strr = str;
		int high = map2[strr];
		high = 13*high;
		if(!high)
		    high = map1[strr];
		cout <<high <<endl;
	}else{
		char *p2 = str+4;
		str[3] = '\0';
		string strr1 = str;
		string strr2 = p2;
		int high = map2[strr1];
		int low = map1[strr2];
		int res = high*13+low;
		cout <<res <<endl;
	}
}
 
int main()
{
	int N;
	char str[16];
	init_map1();
	init_map2();
	for (int i = 0; i <= 168; i++)
    {
        string c;
        getline(cin,c);
        strcpy(str,c.c_str());
        convert_to_earth(str);
    }
	return 0;
}
