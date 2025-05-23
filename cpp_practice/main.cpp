#include <iostream>
#include <vector> 
#include <map>
#include <filesystem>
#include <fstream>
#include <Windows.h>

#include "main_functions.h"
#include "classes.h"
#include "structs.h"
#include "macros.h"
#include "globals.h"

using std::string, std::wstring;
using std::vector;
using std::map;
using std::make_unique, std::unique_ptr;
using std::filesystem::path;
using std::fstream;

int main() {
	// Data types
	{
		int v_int = 0;
		int32_t v_int32 = 0;
		int64_t v_int64 = 0;
		long v_long_int = 123456;
		float v_float = 1.0f;
		double v_double = 1.0;

		char v_char = 'a';
		wchar_t v_wchar = L'a';
		char16_t v_char16 = u'a';
		char32_t v_char32 = u'a';

		bool v_bool = true;
	}



	// Static arrays
	{
		char static_arr[255] = "Milos";
		static_arr[3] = 'p';
		/*You cannot do this:
		static_array = "Paunovic"; */
		StaticArrayParamTest(static_arr, static_arr);
	}



	// String literals
	{
		const char* string_literal = "Milos";
		/* You cannot do this:
		/string_literal[3] = 'p'; */
		string_literal = "Paunovic"; // This is reassigning the pointer to a different literal which is legal
	}



	// Rvalue
	{
		Player player(23, string("Melosh"), 1000000);
	}



	// Pointers
	{
		int int_val = 10;
		int* pointer_to_int = nullptr;

		pointer_to_int = &int_val;
		*pointer_to_int = 15;
	}



	// Strings
	{
		string v_string("Melosh");
		wstring v_wstring(L"Melosh");
		PrintVar(v_string.length()); // Length is without null termination char
	}



	// Classes and objects
	{
		LifecycleDebug ld;
		ObjectParamTest(ld, ld, &ld);

		LifecycleDebug* ldp = nullptr;
		LifecycleDebug* ldp2 = nullptr;
		LifecycleDebug* ldp3 = nullptr;
		ObjectParamTest2(ldp, &ldp2, ldp3);
		delete ldp2;
		delete ldp3;

		string username("Melosh");
		string username2{ "Melosh" };
		string username3 = "Melosh";
		string username4 = string("Melosh");
		string username5 = { "Melosh" };
	}



	// Structs
	{
		Player player(55, "Melosh", 1000);
		string username("Jesus");
		Player player2{ 5, username, 700 };
	}



	// std::vector
	{
		size_t val = 0;
		vector<int> vector_example;
		val = vector_example.capacity(); // Basically reserved memory
		val = vector_example.size(); // Actual number of elements
		vector_example.resize(5, 3); // Affects size() and capacity(), second param is value to fill with
		vector_example.reserve(10); // Affects only capacity()

		/* Exception, capacity is 10, but there is no element at index 8. Even with primitives
		vector_example[8] = 8; */

		/* Exception, insertions must happen at the end. At this time, size is 5
		vector_example.insert(vector_example.begin() + 8, 8); */

		vector_example.insert(vector_example.end(), 666); // Inserts at the end
		vector_example.insert(vector_example.begin() + 3, 12); // Inserts at index [3], shifting current from [3] to the right
		vector_example.push_back(7); // Inserts at the end
		vector_example.pop_back(); // Delete last element
		vector_example.erase(vector_example.begin() + 3); // Delete index [3]
		vector_example.clear(); // Delete all elements
	}

	// std::map
	{
		size_t val = 0;
		map<int, User> map_example{
			{ 65, User{"vitrina", 28} },
			{ 67, User{"mikrotalasna", 2000} }
		};
		val = map_example.max_size();
		val = map_example.size();
		map_example.insert(std::make_pair(1, User("rerna", 3)));
		map_example.insert_or_assign(3, User("sporet", 69));
		map_example.emplace(5, User("usisivac", 13));
		map_example[7] = User("bojler", 123);
		map_example.erase(5);
		map_example.clear();
	}

	// unique_ptr
	{
		unique_ptr<User> ptr = make_unique<User>("Melosh", 28);
	}



	// Files
	{
		wchar_t buffer[MAX_PATH];
		GetModuleFileName(0, buffer, MAX_PATH);
		path path(buffer);
		path.remove_filename();
		path += L"test.txt";

		fstream stream;
		try {
			stream.open(path, std::fstream::trunc | std::fstream::out | std::fstream::in);
			stream << "lorem ipsum dolor est imet";
			stream.seekg(0, std::fstream::beg);
			string file_content;
			string line;
			while (std::getline(stream, line))
			{
				file_content += line;
			}
		}
		catch (...) {
		}

		stream.close();
	}



	// Global state
	
	// globals.h included with "extern" variables. Variables implemented in globals.cpp
	open_project_id = 6;
	state.open_contact_id = 75;

	return 0;
}