#include <iostream>
#include <vector>

#define INF 0x3f3f3f3f

using namespace std;


int solve(vector<int> alloys){
	return 0;
}

void printAlloys(vector<int> alloys){
	for(auto a : alloys){
		cout<<a<<' ';
	}
	cout<<endl;
}

int main(int argc, char const *argv[]) { 
  unsigned int test_cases{0}, alloy_types{0}, order{0};
	vector<int> alloys(alloy_types, 1);

	cin>>test_cases;
	while(cin>>alloy_types>>order){
		for(unsigned int i=0; i<alloy_types; i++){
			int buffer{0};
			cin>>buffer;
			alloys.push_back(buffer);
		}


		// printAlloys(alloys);
		int minimum_alloys = solve(alloys);
		cout<<minimum_alloys<<endl;
		alloys.clear();
	}



  return 0;
}
