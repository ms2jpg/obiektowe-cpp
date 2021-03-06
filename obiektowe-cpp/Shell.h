#pragma once
#include <string>
#include <vector>
#include "Storage.h"

class Shell
{
	public:
		void run();
		typedef std::vector<std::string> arg_array;
	protected:
		typedef std::string(Shell::* cmd_ptr)(arg_array);
		Storage storage;
		std::string getCommandPrompt();
		std::string runCommand(std::vector<std::string> args);
		std::vector<std::string> inputCommand();
		std::vector<std::string> splitCommand(std::string cmd);
		cmd_ptr getCommand(std::string cmd);
		std::string _tree(arg_array args);
		std::string _cd(arg_array args);
		std::string _makeObject(arg_array args);
		std::string _modifyObject(arg_array args);
		std::string _dir(arg_array args);
		std::string _show(arg_array args);
		std::string _save(arg_array args);
		std::string _read(arg_array args);
		std::string _deleteObject(arg_array args);
		std::string _exit(arg_array args);
};

