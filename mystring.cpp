// file: mystring.cpp
// implements class 'string' (documentation in mystring.h)
//
//
// INVARIANT:
// 'allocated' is the total number of indexes in 'characters'
// 'current_length' is the number of chars in 'characters'
// if string is empty, current_length is 0, allocated is 1
// current_length < allocated
// last char in 'characters' is '\0'

#include <algorithm> // provide copy function
#include <iostream>
#include <cstring> // provides functions
#include "mystring.h"

using std::cout;
using std::endl;
using std::copy;

namespace coen79_lab5 {
    // string constructor: O(n)
    // argument: char array 'str'
    // precondition: 'str' must be ordinary null-terminated string
    // if no argument passed, defaults to empty string
    // postcondition: 'characters' contains chars from 'str'
    string::string(const char str[ ]) {
        current_length = strlen(str); // get length of str (if empty, length() == 0)
        bool valid = false;
        for(size_t i=0; i<strlen(str)+1; ++i) { // check str is null-terminated
            if(str[i] == '\0') {
                valid = true;
                break;
            }
        }
        if(!valid) { // char array passed in is not null terminated
            cout << "not valid" << endl;
            return;
        }

        allocated = 0;
        reserve(length()+1);
        copy(str, str+length(), characters); // copy sequence from str to characters
    }

    // string constructor: O(1)
    // argument: char 'c'
    // postcondition: 'characters' contains 'c' followed by '\0'
    string::string(char c) {
        current_length = 1;
        allocated = 0;
        reserve(2); // 2 indexes for 'c', '\0'
        characters[0] = c;
    }

    // string copy constructor: O(n)
    // argument: string 'source'
    // postcondition: string copies 'source' which already satisfies invariance
    string::string(const string& source) {
        current_length = source.length();
        allocated = 0;
        reserve(source.allocated);
        copy(source.characters, source.characters+allocated, characters);
        // copies source to 'characters'
    }

    // string destructor: O(1)
    // frees memory held by 'characters'
    string::~string() {
        delete[] characters;
    }

    // += member operator: O(n)
    // argument: string 'addend'
    // calls reserve() function if insufficient indexes in 'characters'
    // postcondition: 'addend' catenated to 'characters'
    void string::operator +=(const string& addend) {
        if((length()+addend.length()) >= allocated) // insufficient indexes
            reserve(length()+addend.length()+1);

        copy(addend.characters, addend.characters+addend.length(), characters+length());
        // catenate 'addend' to 'characters'
        current_length += addend.length(); // update length
    }

    // += member operator: O(n)
    // argument: char array 'addend'
    // precondition: 'addend' is ordinary null terminated string
    // calls reserve() function if insufficient memory
    // postcondition: 'addend' catenated to 'characters'
    void string::operator +=(const char addend[]) {
        size_t addlength = strlen(addend);
        if(addlength == 0) // do nothing if addend is empty
            return;
        

        bool valid = false;
        for(size_t i=0; i<addlength+1; ++i) { // check addend is null-terminated
            if(addend[i] == '\0') {
                valid = true;
                break;
            }
        }
        if(!valid) { // char array passed in is not null terminated
            cout << "not valid" << endl;
            return;
        }

        if((length() + addlength) >= allocated) // insufficient indexes
            reserve(length() + addlength + 1);

        copy(addend, addend+addlength, characters+length());
        // catenate 'addend' to 'characters'
        current_length += addlength; // update length
    }

    // += member operator: O(1)
    // argument: char 'addend'
    // calls reserve() function if insufficient indexes
    // postcondition: 'addend' catenated to 'characters'
    void string::operator +=(char addend) {
        if(addend == '\0') // do nothing if addend is empty
            return;

        if(length()+1 >= allocated) // insufficient indexes
            reserve(length()+2);

        characters[length()] = addend; // catenate 'addend' to 'characters'
        ++current_length; // update length
    }

    // reserve() function: O(n)
    // argument: size_t 'n' indexes to allocate
    // if called by constructors, allocates memory for 'characters'
    // if called because (n > allocated), reallocate 'characters'
    // set all unused indexes to '\0' null character
    // postcondition: all functions work efficiently, only call reserve() when necessary
    void string::reserve(size_t n) {
        if(allocated == 0) { // called by constructor, initialize 'characters'
            characters = new char[n];
        } else { // (n > allocated), need to reallocate 'characters'
            char *temp = new char[n];
            copy(characters, characters+length(), temp);
            // copy 'characters' to 'temp'
            delete[] characters;
            characters = new char[n];
            copy(temp, temp+length(), characters);
            // copy 'temp' to 'characters'
            delete[] temp;
        }

        for(size_t i=length(); i<n; ++i) // set all unused indexes to '\0' null character
            characters[i] = '\0';

        allocated = n; // update 'allocated'
    }

    // = assignment operator: O(n)
    // argument: string 'source'
    // calls reserve() function if insufficient indexes
    // postcondition: 'characters' set equal to 'source'
    string& string::operator =(const string& source) {
        if(source.length() >= allocated) // insufficient memory
            reserve(source.length()+1);

        copy(source.characters, source.characters+source.length(), characters);
        // copy 'source' to 'characters'
        current_length = source.length(); // update length
        characters[length()] = '\0'; // in case 'source' is shorter than 'characters'
        return *this;
    }

    // insert() function: O(n)
    // argument: string 'source' to insert
    // argument: int 'position' index to start inserting
    // precondition: position <= length()
    // call reserve if insufficient indexes
    // postcondition: 'source' inserted to 'characters' at 'position'
    void string::insert(const string& source, unsigned int position) {
        if(position > length()) { // precondition
            cout << "given 'position' too large" << endl;
            return;
        }
        
        if((length() + source.length()) >= allocated) // insufficient indexes
            reserve(length() + source.length() + 1);
        
        char *temp = new char[allocated];
        copy(characters, characters+position, temp);
        // copy 'characters' up to 'position' to 'temp'
        copy(source.characters, source.characters+source.length(), temp+position);
        // catenate 'source' to temp
        copy(characters+position, characters+length(), temp+position+source.length());
        // copy the rest of 'characters' after 'position' to 'temp'
        copy(temp, temp+allocated, characters);
        // copy 'temp' to 'characters'

        delete[] temp; // free memory used by temp
        current_length += source.length(); // update current_length
        characters[length()] = '\0'; // add null character
    }

    // dlt() function: O(n)
    // argument: 'position' index to delete from
    // argument: 'num' indexes to delete
    // precondition: (position + num) <= length()
    // postcondition: 'num' chars removed from 'characters' starting from 'position'
    void string::dlt(unsigned int position, unsigned int num) {
        if(position + num > length()) { // precondition
            cout << "given 'position, num' too large" << endl;
            return;
        }

        char *temp = new char[allocated];
        copy(characters, characters+position, temp);
        // copy 'characters' up to 'position' to 'temp'
        copy(characters + position + num, characters + length(), temp+position);
        // copy the rest of 'characters' after (position + num) to 'temp'
        copy(temp, temp+allocated, characters);
        // copy 'temp' to 'characters'

        delete[] temp;
        current_length -= num;
        characters[length()] = '\0'; // add null character
    }

    // replace() function: O(1)
    // argument: char 'c'
    // argument: int 'position' index to replace
    // precondition: position < length()
    // postcondition: 'character[position]' is replaced with 'c'
    void string::replace(char c, unsigned int position) {
        if(position >= length()) { // precondition
            cout << "given 'position' too large" << endl;
            return;
        }

        characters[position] = c; // replace char at 'position' with 'c'
    }

    // replace() function: O(n)
    // argument: string 'source'
    // argument: int 'position' index to replace from
    // precondition: position + source.length() <= length()
    // postcondition: 'characters' starting at 'positions' are replaced with 'source'
    void string::replace(const string& source, unsigned int position) {
        if(position + source.length() > length()) { // precondition
            cout << "given 'position' too large" << endl;
            return;
        }

        char *temp = new char[allocated];
        copy(characters, characters+position, temp);
        // copy 'characters' up to 'position' to 'temp'
        copy(source.characters, source.characters+source.length(), temp+position);
        // catenate 'source' into 'temp'
        copy(characters+position+source.length(), characters+length(), temp+position+source.length());
        // catenate the rest of 'characters' after (position + source.length()) into temp
        copy(temp, temp+allocated, characters); // copy temp to characters
        
        delete[] temp;
        characters[length()] = '\0'; // add null character
    }

    // [] const operator: O(1)
    // argument: size_t 'position' index to return
    // precondition: position < length()
    // postcondition: return 'character' at given 'position' (char[position])
    char string::operator [](size_t position) const {
        if(position >= length()) { // precondition
            cout << "given 'position' out of bounds" << endl;
            return '\0';
        }

        return characters[position];
    }

    // search() const function: O(n)
    // argument: char 'c'
    // search for 'c' in 'characters'
    // postcondition: return index of first entry of 'c', or -1 if not found
    int string::search(char c) const {
        size_t i=0;
        while(i < length()) { // iterate through all indexes
            if(characters[i] == c) {
                return i; // 'i' is index of first entry
            }
            ++i;
        }

        return -1; // 'c' not found
    }

    // search() const function: O(n)
    // argument: string 'substring'
    // iterate through 'characters', searching for 'substring'
    // compare with strstr()
    // return index of first entry or -1 if not found
    int string::search(const string& substring) const {
        size_t i=0;
        char *temp = new char[substring.allocated];
        while(i+substring.length() <= length()) { // iterate through valid indexes of 'characters'
            copy(characters+i, characters+i+substring.length(), temp);
            // copy 'characters' into temp
            characters[substring.allocated] = '\0'; // add null character

            if(strstr(temp, substring.characters)) { // true if (temp==substring.characters)
                delete[] temp; // free memory used by temp
                return i; // index of first entry
            }
            ++i;
        }

        delete[] temp; // free memory used by temp
        return -1; // 'substring' not found in 'characters'
    }

    // count() const function: O(n)
    // argument: char 'c' to count
    // iterate through 'characters' for 'c'
    // postcondition: return 'count' of 'c' (0 if none found)
    unsigned int string::count(char c) const {
        size_t i, count;
        i = 0;
        count = 0;

        while(i < length()) { // iterate through 'characters'
            if(characters[i] == c) {
                ++count; // 'increment' if 'c' found
            }
            ++i;
        }

        return count;
    }

    // << friend operator: O(n)
    // argument: ostream 'outs' output stream
    // argument: string 'source' to add to outs
    // iterates through 'characters'
    // postcondition: returns 'outs' with 'characters' written to it
    std::ostream& operator <<(std::ostream& outs, const string& source) {
        size_t i = 0;
        while(i < source.length()) // iterate through 'characters'
            outs << source.characters[i++];

        return outs;
    }

    // == friend operator: O(n)
    // arguments: strings 's1', 's2' to be compared
    // use strcmp
    // postcondition: return true (1) if strings equal, false (0) otherwise
    bool operator ==(const string& s1, const string& s2) {
            int answer = strcmp(s1.characters, s2.characters);

            return answer == 0 ? 1:0; // are strings equal
    }

    // != friend operator: O(n)
    // return true if strings unequal, false otherwise
    bool operator !=(const string& s1, const string& s2) {
            int answer = strcmp(s1.characters, s2.characters);

            return answer != 0 ? 1:0; // are strings unequal
    }

    // > friend operator: O(n)
    // return true if s1 > s2, false otherwise
    bool operator > (const string& s1, const string& s2) {
            int answer = strcmp(s1.characters, s2.characters);

            return answer > 0 ? 1:0; // s1 > s2?
    }

    // < friend operator: O(n)
    // use strcmp, return true if s1 < s2, false otherwise
    bool operator < (const string& s1, const string& s2) {
        int answer = strcmp(s1.characters, s2.characters);

        return answer < 0 ? 1:0; // s1 < s2?
    }

    // >= friend operator: O(n)
    // use strcmp, return true if s1 >= s2, false otherwise
    bool operator >= (const string& s1, const string& s2) {
        int answer = strcmp(s1.characters, s2.characters);

        return answer >= 0 ? 1:0; // s1 >= s2?
    }

    // <= friend operator: O(n)
    // use strcmp, return true if s1 <= s2, false otherwise
    bool operator <= (const string& s1, const string& s2) {
        int answer = strcmp(s1.characters, s2.characters);

        return answer <= 0 ? 1:0; // s1 <= s2?
    }

    // + nonmember operator: O(n)
    // arguments 's1', 's2' strings to add
    // calls += on copies of s1, s2 to catenate
    // return copy of s1 with copy of s2 catenated
    string operator +(const string& s1, const string& s2) {
        string s01(s1), s02(s2);
        s01 += s02;
        return s01;
    }

    // + nonmember operator: O(n)
    // argument: string 's1'
    // argument: char array 'addend' to catenate to 's1'
    // calls += on copy of 's1' 'addend'
    // postcondition: return 's1' with 'addend' catenated
    string operator +(const string& s1, const char addend[]) {
        string s01(s1);
        char *add = new char[strlen(addend)+1];
        copy(addend, addend+strlen(addend)+1, add); // copy addend to add
        s01 += add;
        delete[] add; // free memory used by add
        return s01;
    }

    // >> nonmember operator: O(n)
    // argument: istream 'ins' input stream
    // argument: 'target' takes input stream
    // input goes into 'c', which goes into 'target.characters'
    // postcondition: returns 'ins'
    std::istream& operator >>(std::istream& ins, string& target) {
        char *c = new char[100];
        ins >> c;
        target = c;
        delete[] c; // free memory used by 'c'
        return ins;
    }
}