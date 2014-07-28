#include <queue>
#include <iostream>

struct primeFactor{
	unsigned int prime;
	unsigned int nextMultiple;

	primeFactor(unsigned int p): prime(p), nextMultiple(p*p) {}
};

bool operator< (const primeFactor& p1, const primeFactor& p2){
	return p1.nextMultiple > p2.nextMultiple;
}

int main(){
	std::priority_queue<primeFactor> primeFactors;

	unsigned int i = 2;
	std::cout << 2 << std::endl;
	primeFactors.push(primeFactor(i));

	unsigned int nextComposite;	
	while(true){
		auto p = primeFactors.top();
		primeFactors.pop();
		nextComposite = p.nextMultiple;
		p.nextMultiple += p.prime;
		primeFactors.push(p);

		while(i < nextComposite){
			std::cout << i << std::endl;
			primeFactors.push(primeFactor(i));
			i++;
		}
		if(i == nextComposite)
			i++;
	}
}
