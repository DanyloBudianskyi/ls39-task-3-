#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <exception>
using namespace std;

class Users
{
	map<string, string> users;
	vector<string> signInUsers;
public:
	void userRegister(string login, string password);
	void signIn(string login, string password);
	void signOut(string login);

	void showAllRegistered()const;
	void showAllSignIn()const;
};

