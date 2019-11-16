#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<algorithm>
using namespace std;
//120min
typedef struct book{
	string id;
	string title,author,publisher;
	string keywords;
	string year;

}book;
int n,m;
vector<book> b;
vector<string> searchTitle(string title){
	vector<string> ans;
	for(int i=0;i<n;i++){
		if(b[i].title==title)
			ans.push_back(b[i].id);
	}
	return ans;
}
vector<string> searchAuthor(string author){
	vector<string> ans;
	for(int i=0;i<n;i++){
		if(b[i].author==author)
			ans.push_back(b[i].id);
	}
	return ans;
}
vector<string> searchKeyword(string keyword){
	vector<string> ans;
	for(int i=0;i<n;i++){
		if(b[i].keywords.find(keyword)!=string::npos)
			ans.push_back(b[i].id);
	}
	return ans;
}
vector<string> searchPublisher(string publisher){
	vector<string> ans;
	for(int i=0;i<n;i++){
		if(b[i].publisher==publisher)
			ans.push_back(b[i].id);
	}
	return ans;
}
vector<string> searchYear(string year){
	vector<string> ans;
	for(int i=0;i<n;i++){
		if(b[i].year==year)
			ans.push_back(b[i].id);
	}
	return ans;
}
int main(){
	cin>>n;cin.get();
	char t[100];book bt;
	for(int i=0;i<n;i++){
		getline(cin,bt.id);
		getline(cin,bt.title);
		getline(cin,bt.author);
		getline(cin,bt.keywords);
		getline(cin,bt.publisher);
		getline(cin,bt.year);
		b.push_back(bt);
	}
	cin>>m;
	int type;string key;
	vector<string> result;
	for(int i=0;i<m;i++){
		cin >> type;cin.get();cin.get();
		getline(cin,key);
		result.clear();
		switch(type){
		case 1:
			result=searchTitle(key);
			break;
		case 2:
			result=searchAuthor(key);
			break;
		case 3:
			result=searchKeyword(key);
			break;
		case 4:
			result=searchPublisher(key);
			break;
		case 5:
			result=searchYear(key);
			break;
		}
		cout<<type<<": "<<key<<endl;
		if(result.size()==0){
			cout<<"Not Found\n";
		}else{
			sort(result.begin(),result.end());
			for(int j=0;j<result.size();j++){
				cout<<result[j]<<endl;
			}
		}
	}
	cin.get();
	return 0;
}