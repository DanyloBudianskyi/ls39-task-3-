#include "Users.h"

void Users::userRegister(string login, string password)
{
	if (users.find(login) == users.end()) {
		users[login] = password;
		cout << "\nSuccess: new user added\n";
	}
	else {
		cout << "\nFail: user already exists\n";
	}

}

void Users::signIn(string login, string password)
{
	map<string, string>::iterator item = users.find(login);
	if (item == users.end()) {
		cout << "\nFail: no such user\n";
		return;
	}
	else {
		if (item->second != password) { cout << "\nFail: incorrect password\n"; return; }
		else {
			for (int i = 0; i < signInUsers.size(); i++) {
				if (signInUsers[i] == login) {
					cout << "\nfail: already logged in\n";
					return;
				}
			}
			signInUsers.push_back(login);
		}
	}
}

void Users::signOut(string login)
{
	map<string, string>::iterator item = users.find(login);
	if (item == users.end()) {
		cout << "\nFail: no such user\n";
		return;
	}
	else {
		for (int i = 0; i < signInUsers.size(); i++) {
			if (signInUsers[i] == login) {
				signInUsers.erase(signInUsers.begin() + i);
				cout << "\nsuccess: user logged out\n";
				return;
			}
		}
		cout << "\nfail: already logged out\n";
		return;
	}
}

void Users::showAllRegistered() const
{
	if (users.size() == 0) {
		cout << "Users is empty\n";
	}
	else
	{
		map<string, string>::const_iterator item;
		for (item = users.begin(); item != users.end(); item++) {
			cout << "Login: " << item->first << " Password: " << item->second << endl;
		}
	}
}

void Users::showAllSignIn() const
{
	for (int i = 0; i < signInUsers.size(); i++) {
		cout << "User #" << i + 1 << " ";
		cout << signInUsers[i] << endl;
	}
}
