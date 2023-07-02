#include <iostream>
#include <vector>

#define INF 0x3f3f3f3f

using namespace std;




void printAlloys(vector<int> alloys){
	for(auto a : alloys){
		cout<<a<<' ';
	}
	cout<<endl;
}

int findMinimumAlloysNumber(vector<int> alloys, int order){
	vector<int> alloyNumber(order + 1, INF); //Para cada index i, alloyNumber[i] é o numero mínimo de alloys para satisfazer o pedido i.
	alloyNumber[0] = 0;

	for(int i=1; i<=order; i++){
		for(auto alloy : alloys){
			if(i == alloy){
				alloyNumber[i] = 1;
				break;
			}
			if(i - alloy >= 0){
				alloyNumber[i] = min(alloyNumber[i], 1 + alloyNumber[i - alloy]);
			}
		}
		// cout<<"AMOUNT: "<<i<<' '<< "ALLOY#: "<<alloyNumber[i]<<endl;
	}

	return alloyNumber[order]; //Como sempre haverá liga metálica de tam=1, podemos assumir que sempre haverá solucao.
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
		int minimum_alloys = findMinimumAlloysNumber(alloys, order);
		cout<<minimum_alloys<<endl;
		alloys.clear();
	}
  return 0;
}
