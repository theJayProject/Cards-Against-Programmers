#include <iostream>
using namespace std;

//////////////////////////////////////////////////////////////////////////
//////////////////////// VIRTUAL CLASS ///////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//MAKE A FOOKIN CLASS
class niceBody {
	
public:
	//MAKE A VIRTUAL FUNCTION THAT IS BOTH 'virtual' AND A FUNCTION(){}
	virtual void BMI() {
		cout << "Your BMI is good" << endl;
	}
	//HERE'S A NON-VIRTUAL FUNCTION
	void funny() {
		cout << "You're beautiful anyway" << endl;
	}
};

//HERE'S A DERIVED CLASS
class badBody : public niceBody {
public:
	void BMI() {
		cout << "Your BMI is bad" << endl;
	}
	void funny() {
		cout << "You're ugly anyway" << endl;
	}
};
//////////////////////////////////////////////////////////////////////////
//////////////////////// OVERRIDDEN FUNCTION /////////////////////////////
//////////////////////////////////////////////////////////////////////////

class niceEyes {
public:
	//Introduce virtual class (OVERRIDDE) 
	virtual void colour() {
		cout << "All eye colours are beautiful" << endl;
	}
	//Introduce virtual class (NO OVERRIDDE)
	virtual void shape() {
		cout << "All eye shapes are beautiful" << endl;
	}
};
class uglyEyes : public niceEyes {
public:
	//Override virtual class (OVERRIDDE) 
	void colour() override{
		cout << "All eye colours are ugly" << endl;
	}
	//Override virtual class (NO OVERRIDDE)
	void shape() {
		cout << "All eye shapes are ugly" << endl;
	}
};
//////////////////////////////////////////////////////////////////////////
//////////////////////// OBJECT SLICING //////////////////////////////////
//////////////////////////////////////////////////////////////////////////
class niceLegs {
public:
	void length() {
		cout << "Long legs are nice" << endl;
	}
	void width() {
		cout << "Thicc legs are nice" << endl;
	}
};
class uglyLegs : public niceLegs {
public:
	void tan() {
		cout << "Tanned legs are ugly" << endl;
	}
};
//////////////////////////////////////////////////////////////////////////
////////////// PURE VIRTUAL FUNCTIONS + ABSTRACT CLASSES /////////////////
//////////////////////////////////////////////////////////////////////////
class niceAss {
public:
	//PURE VIRTUAL FUNCTION
	virtual void thicc() = 0;
};
class uglyAss : public niceAss {
public:
	void thicc() {
		cout << "Dat ass is thicc" << endl;
	}
};
//Pure Virtual Functions are a Virtual Functions where you don't declare the function, by assigning a 0 in the declaration.
//Pure Virtual Functions are used in Abstract Classes.

int main() {
	//////////////////////// VIRTUAL CLASS ///////////////////////////////////
	niceBody *nice_body;
	badBody bad_body;
	nice_body = &bad_body;
	//Derived class because BMI() is virtual
	nice_body->BMI();
	//Base class because funny() is not virtual
	nice_body->funny();

	cout << endl << endl << endl << endl;

	//////////////////////// OVERRIDDEN FUNCTION /////////////////////////////
	niceEyes* nice_eyes;
	uglyEyes ugly_eyes;
	nice_eyes = &ugly_eyes;
	nice_eyes->colour();
	nice_eyes->shape();
	//Both cases show the derived class result, as there are two virtual functions.
	//Overridden functions are used to avoid bugs.

	cout << endl << endl << endl << endl;
	//////////////////////// OBJECT SLICING //////////////////////////////////
	niceLegs nice_legs;
	uglyLegs ugly_legs;
	nice_legs = ugly_legs;
	//Only length and width is copied to ugly_legs.
	//Object Slicing here in ugly_legs is a space-saving method because it cuts off the tan, and applies only the length and width.

////////////// PURE VIRTUAL FUNCTIONS + ABSTRACT CLASSES /////////////////
	niceAss *nice_ass;
	uglyAss ugly_ass;
	nice_ass = &ugly_ass;
	//PRINTS DERIVED, ABSTRACT CLASS AS A PURE VIRTUAL FUNCTION IS OVERRIDDEN.
	nice_ass->thicc();
}

////////////////////////////////////////////////////////
///////////////WHAT IS POLYMORPHISM USED FOR?///////////
////////////////////////////////////////////////////////
//PROS////////	Helps save memory space		//////// 
//PROS////////	Makes code more readible	////////
//PROS////////	Reusing code is simpler		////////
//PROS////////	derived class can access base.	////////
////////////////////////////////////////////////////////
