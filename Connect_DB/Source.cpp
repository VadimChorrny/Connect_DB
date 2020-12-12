#include <iostream>
#include <stdint.h>
#include <sqlite3.h>

using namespace std;

static int createDB(const char* s);						
static int createTable(const char* s);

int main()
{
	const char* dir = "D:\\Programming\\DeleteMe\\STUDENTS.db";
	sqlite3* DB;

	createDB(dir);
	createTable(dir);
	
	return 0;
}

int createDB(const char* s)
{
	sqlite3* DB;
	int exit = 0;

	exit = sqlite3_open(s, &DB);
	sqlite3_close(DB);
	return 0;
}

int createTable(const char* s)
{
	sqlite3* DB;
	string sql = "CREATE TABLE IF NOT EXISTS GRADES("
		"ID INTEGER PRIMARY KEY AUTOINCREMENT, "
		"NAME TEXT NOT NULL"
		"LNAME TEXT NOT NULL"
		"AGE TEXT NOT NULL"
		"ADRESS CHAR(50), "
		"GRADE CHAR(1) ); ";

	try
	{
		int exit = 0;
		exit = sqlite3_open(s, &DB);
		char* messageError;
		exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
		if (exit != SQLITE_OK) {
			cout << "Table created fail" << endl;
			sqlite3_free(messageError);
		}
		else
			cout << "Table created successfully" << endl;
		sqlite3_close(DB);
	}
	catch (const exception& e) {
		cerr << e.what();
	}



	return 0;
}
