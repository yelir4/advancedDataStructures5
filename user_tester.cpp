// FILE: main.cpp
// To test string class
//
//  COEN 79
//  --- Farokh Eskafi, COEN, SCU ---
//
// user tester, tests all functions of tester.cpp

#include <iostream>
#include "mystring.h"

using std::cout;
using std::cin;
using std::endl;
using coen79_lab5::string;

#include<cstring>

int main(int argc, char const *argv[]) {
	cout << "testing empty string constructor" << endl;
	string s1, s01, s001, s0001; // test empty string constructor
	cout << "testing non-empty string constructor" << endl;
	string s2("Hello, World!"); // test non-empty string constructor
	cout << "testing copy constructor with non-empty string" << endl;
	string s3(s2); // test copy constructor with non-empty string
	cout << "testing char constructor" << endl;
	string s4('e'); // test char constructor
	cout << "testing copy constructor with empty string" << endl;
	string s5(s1); // test copy constructor with empty string
	cout << "testing copy constructor with char" << endl;
	string s6(s4); // test copy constructor with char


	cout << endl << "=====================" << endl;
	cout << "=====================" << endl << endl;

	cout << "testing += with empty string and non empty string" << endl;
	s1 += s2;
	cout << "testing += with non empty string and non empty string" << endl;
	s4 += s4;
    cout << "testing += with non empty string and empty string" << endl;
	s4 += s01;

	cout << endl << "=====================" << endl;
	cout << "=====================" << endl << endl;

	cout << "testing += with empty string and empty char[]" << endl;
	s01 += "";
	cout << "testing += with non empty string and empty char[]" << endl;
	s4 += "";

	cout << "testing += with empty string and non-empty char[]" << endl;
	s01 += "hello";
	cout << "testing += with non empty string and non-empty char[]" << endl;
	s4 += "hello";

	cout << endl << "=====================" << endl;
	cout << "=====================" << endl << endl;

	cout << "testing += with empty string and empty char" << endl;
	s001 += '\0';
	cout << "testing += with non empty string and empty char" << endl;
	s4 += '\0';

	cout << "testing += with empty string and non-empty char" << endl;
	s001 += 'x';
	cout << "testing += with non empty string and non-empty char" << endl;
	s4 += 'x';


	cout << endl << "=====================" << endl;
	cout << "=====================" << endl << endl;

	cout << "setting non-empty string to empty string" << endl;
	s2 = s0001;
	cout << "setting empty string to non-empty string" << endl;
	s0001 = s4;



	cout << endl << "=====================" << endl;
	cout << "=====================" << endl << endl;

	string t1a = "ad";
	string t1b(t1a), t1c(t1a), t1d(t1a);
	string t2a = "bc";

	cout << "testing insert; 'bc' inserted before 'ad' string" << endl;
	t1a.insert(t2a, 0);
	cout << "inserting 'bc' in middle of 'ad' string" << endl;
	t1b.insert(t2a, 1);
	cout << "inserting 'bc' after 'ad' string" << endl;
	t1c.insert(t2a, 2);
	cout << "inserting 'bc' out of bounds" << endl;
	t1d.insert(t2a, 3);



	cout << endl << "=====================" << endl;
	cout << "=====================" << endl << endl;

	string u1a = "abcdef";
	string u1b(u1a), u1c(u1a), u1d(u1a);

	cout << "testing dlt, delete whole string" << endl;
	u1b.dlt(0, 6);
	cout << "testing dlt, 'bcd'" << endl;
	u1c.dlt(1, 3);
	cout << "testing dlt, deleting more than bounds" << endl;
	u1d.dlt(0, 7);



	cout << endl << "=====================" << endl;
	cout << "=====================" << endl << endl;

	string u1e(u1a), u1f(u1a), u1g(u1a);

	cout << "testing replace, replace 'b' with 'x'" << endl;
	u1e.replace('x', 1);
	cout << "testing replace, replace 'f' with 'x'" << endl;
	u1f.replace('x', 5);
	cout << "testing replace, replace out of bounds" << endl;
	u1g.replace('x', 6);



	cout << endl << "=====================" << endl;
	cout << "=====================" << endl << endl;

	string u1h(u1a), u1i(u1a), u1j(u1a);
	string uu1("yz");

	cout << "testing replace, replace 'bc' with 'yz'" << endl;
	u1h.replace(uu1, 1);
	cout << "testing replace, replace 'ef' with 'yz'" << endl;
	u1i.replace(uu1, 4);
	cout << "testing replace, replace out of bounds" << endl;
	u1j.replace(uu1, 6);




	cout << endl << "=====================" << endl;
	cout << "=====================" << endl << endl;

	cout << "testing []. return first letter of ayzdef" << endl;
	cout << u1h[0] << endl;
	cout << "testing []. return last letter of ayzdef" << endl;
	cout << u1h[5] << endl;
	cout << "testing []. return out of bounds" << endl;
	cout << u1h[6] << endl;



	cout << endl << "=====================" << endl;
	cout << "=====================" << endl << endl;

	cout << "testing search. return first instance of 'a' in ayzdef" << endl;
	cout << u1h.search('a') << endl;
	cout << "testing search. return first instance of 'e' in ayzdef" << endl;
	cout << u1h.search('e') << endl;
	cout << "testing search. return first instance of 'b' in ayzdef" << endl;
	cout << u1h.search('b') << endl;

	



	cout << endl << "=====================" << endl;
	cout << "=====================" << endl << endl;
	string ay("ay");
	string ef("ef");
	string efe("efe");

	cout << "testing search. return first instance of 'ay' in ayzdef" << endl;
	cout << u1h.search(ay) << endl;
	cout << "testing search. return first instance of 'ef' in ayzdef" << endl;
	cout << u1h.search(ef) << endl;
	cout << "testing search. return 'efe' (not in ayzdef)" << endl;
	cout << u1h.search(efe) << endl;


	cout << endl << "=====================" << endl;
	cout << "=====================" << endl << endl;
	string bazooka("bazoooooka");

	cout << "testing count. return count of 'o' in 'bazoooooka'" << endl;
	cout << bazooka.count('o') << endl;
	cout << "testing count. return count of 'r' in 'bazoooooka'" << endl;
	cout << bazooka.count('r') << endl;



	cout << endl << "=====================" << endl;
	cout << "=====================" << endl << endl;
	
	cout << "testing cout. printing bazooka" << endl;
	cout << bazooka << endl;



	cout << endl << "=====================" << endl;
	cout << "=====================" << endl << endl;
	string w1("qq"), w2("qq"), w3("ww");

	cout << "testing ==. is 'qq' == 'qq' ? " << (w1==w2) << endl;
	cout << "testing ==. is 'qq' == 'ww' ? " << (w1==w3) << endl;
	cout << "testing !=. is 'qq' != 'qq' ? " << (w1!=w2) << endl;
	cout << "testing !=. is 'qq' != 'ww' ? " << (w1!=w3) << endl;


	cout << endl << "=====================" << endl;
	cout << "=====================" << endl << endl;

	string w4("abc"), w5("def"), w6("ghi");
	cout << "testing >. is 'abc' > 'ghi' ? " << (w4>w6) << endl;
	cout << "testing >. is 'ghi' > 'def' ? " << (w6>w5) << endl;
	cout << "testing >. is 'ghi' > 'ghi' ? " << (w6>w6) << endl;
	cout << "testing <. is 'abc' < 'ghi' ? " << (w4<w6) << endl;
	cout << "testing <. is 'ghi' < 'def' ? " << (w6<w5) << endl;
	cout << "testing >. is 'ghi' < 'ghi' ? " << (w6>w6) << endl;



	cout << endl << "=====================" << endl;
	cout << "=====================" << endl << endl;

	cout << "testing >=. is 'abc' >= 'ghi' ? " << (w4>=w6) << endl;
	cout << "testing >=. is 'ghi' >= 'def' ? " << (w6>=w5) << endl;
	cout << "testing >=. is 'ghi' >= 'ghi' ? " << (w6>=w6) << endl;
	cout << "testing <=. is 'abc' <= 'ghi' ? " << (w4<=w6) << endl;
	cout << "testing <=. is 'ghi' <= 'def' ? " << (w6<=w5) << endl;
	cout << "testing >=. is 'ghi' <= 'ghi' ? " << (w6>=w6) << endl;


	cout << endl << "=====================" << endl;
	cout << "=====================" << endl << endl;

	cout << "testing +. abc + def: " << (w4+w5) << endl;
	cout << "testing +. abc + 'xo'" << (w4+"xo");



	cout << endl << "=====================" << endl;
	cout << "=====================" << endl << endl;
	cout << "testing >>. please type in a string" << endl;
	string x99("");

	cin >> x99;
	cout << x99 << endl;
	

	cout << endl << "=====================" << endl;
	cout << "=====================" << endl << endl;
	string y2("hi");

	cout << "*** = operator test ***" << endl;
	cout << y2 << endl;
    y2 = string("= Test 1 Success");
	cout << y2.length() << endl;
	cout << y2 << endl;
	cout << "y2: " << y2 << endl;
    cout << "y2: " << (y2 = string("= Test 2 Success")) << endl;


	cout << endl << "=====================" << endl;
	cout << "=====================" << endl << endl;
	string xyz001, xyz002("a"), xyz003("b");

	cout << "testing insert/dlt" << endl;
	cout << y2 << endl;

	xyz001.insert(xyz002,0);
	xyz001.insert(xyz003,0);
	xyz001.insert(xyz002,0);
	xyz001.insert(xyz003,0);
	cout << xyz001 << " before dlt, " << xyz001.length() << endl;
	xyz001.dlt(0, 2);
	cout << xyz001 << " after dlt, " << xyz001.length() << endl;

	return 0;
}
