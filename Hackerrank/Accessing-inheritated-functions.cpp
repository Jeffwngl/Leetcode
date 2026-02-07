#include<iostream>

using namespace std;

class A
{
    public:
        A(){
            callA = 0;
        }
    private:
        int callA;
        void inc(){
            callA++;
        }

    protected:
        void func(int & a)
        {
            a = a * 2;
            inc();
        }
    public:
        int getA(){
            return callA;
        }
};

class B
{
    public:
        B(){
            callB = 0;
        }
    private:
        int callB;
        void inc(){
            callB++;
        }
    protected:
        void func(int & a)
        {
            a = a * 3;
            inc();
        }
    public:
        int getB(){
            return callB;
        }
};

class C
{
    public:
        C(){
            callC = 0;
        }
    private:
        int callC;
        void inc(){
            callC++;
        }
    protected:
        void func(int & a)
        {
            a = a * 5;
            inc();
        }
    public:
        int getC(){
            return callC;
        }
};

class D : public A, public B, public C
{

	int val;
	public:
		//Initially val is 1
		 D()
		 {
		 	val = 1;
		 }


		 //Implement this function
         // funcamental theorem of arithmetic
         // new_val = 2^a * 3^b * 5^c
		 void update_val(int new_val)
		 {
            while (new_val % 2 == 0) {
                A::func(val);
                new_val /= 2;
            }
            
            while (new_val % 3 == 0) {
                B::func(val);
                new_val /= 3;
            }
            
            while (new_val % 5 == 0) {
                C::func(val);
                new_val /= 5;   
            }
		 }
		 //For Checking Purpose
		 void check(int); //Do not delete this line.
};



void D::check(int new_val)
{
    update_val(new_val);
    cout << "Value = " << val << endl << "A's func called " << getA() << " times " << endl << "B's func called " << getB() << " times" << endl << "C's func called " << getC() << " times" << endl;
}


int main()
{
    D d;
    int new_val;
    cin >> new_val;
    d.check(new_val);

}

// Editorial
//
// Every integer > 1 can be written as a product of prime numbers, every case is also unique except for the order.
// That is new_value = 2^a * 3^b * 5^c, then for an example, factoring 90 continously, (9, 10) -> (3, 3, 2, 5)...
// will lead to the same group of prime numbers, for proof that the prime factorization is unique, assume a case
// where they are not unique, say X = p1 p2 p3 p4...pn, as well as a case for another prime factorization X = p'1 
// p'2 ... p'n. Taking p1 p2 ... pn = p'1 p'2 ... p'n, we know that both sides are made of primes and thus integers,
// thus both sides result in an integer, dividing the RHS by p1 gives (p'1 ... p'n) / p1 = an integer value, as the 
// p'1 to p'n prime are all prime numbers, then p1 must also exist in the set such that p1 = p'k, dividing the RHS
// by each number on the LHS, we will end up with p1 = p'k, p2 = p'j ... for simplicities sake, we have p1 = p'1, 
// p2 = p'2 ... proving our point.
//
// For a case where the RHS has more primes than the LHS or vice versa, it will lead to a case like 1 = p'n + 1,
// p'n + 2... which is invalid.
