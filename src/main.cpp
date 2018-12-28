#include <iostream>
#include "src/rpn.h"

using namespace std;

int main() {

    string s = "1234+++";
    cout << s << " is " << rpn::rpn(s) << endl;

    return 0;
}

