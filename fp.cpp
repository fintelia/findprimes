#include <queue>
#include <iostream>
#include <iomanip>

struct primeFactor{
	unsigned long long prime;
	unsigned long long nextMultiple;

	primeFactor(unsigned long long p): prime(p), nextMultiple(p*p) {}
};

bool operator< (const primeFactor& p1, const primeFactor& p2){
	return p1.nextMultiple > p2.nextMultiple;
}

int main(){
	std::priority_queue<primeFactor> primeFactors;

	unsigned long long n = 1;
	unsigned long long i = 5;
	std::cout << "[" << std::setw(6) << n++ << "] " << 2 << std::endl;
	std::cout << "[" << std::setw(6) << n++ << "] " << 3 << std::endl;
	primeFactors.push(primeFactor(3));

	unsigned long long nextComposite;	
	while(true){
		auto p = primeFactors.top();
		primeFactors.pop();
		nextComposite = p.nextMultiple;
		p.nextMultiple += p.prime;
		primeFactors.push(p);

		while(i < nextComposite){
			std::cout << "[" << std::setw(6) << n++ << "] " << i << std::endl;
			primeFactors.push(primeFactor(i));
			i += 2;
		}
		if(i == nextComposite)
			i += 2;
	}
}
