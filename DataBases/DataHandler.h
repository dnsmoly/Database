#pragma once

#include <string>
#include <fstream>
#include <unordered_map>
#include <regex>

#include "Func.h"

using namespace System;

class DataHandler {
public:
	//Конструктор
	DataHandler(String^ filename) {
		ConvertTostring(filename, this->filename);

	};
	
	//Деструктор
	~DataHandler() {};

	//метод для заполнения хеш-таблиц на основе фалйа БД
	void fillTables();

	//Добавляет в БД новую строку
	bool addEntry(std::string id, std::string name,
		std::string lastname, std::string sum,
		bool payed);


	void writeTmp(std::vector<int> items);
	int rowCount;
	

private:
	std::string filename;

	std::unordered_multimap<std::string, int> id;
	std::unordered_multimap<std::string, int> name;
	std::unordered_multimap<std::string, int> lastname;
	std::unordered_multimap<std::string, int> sum;
	std::unordered_multimap<std::string, int> payed;

	std::fstream filestream;
	std::fstream fid;
	std::fstream fname;
	std::fstream flastname;
	std::fstream fsum;
	std::fstream fpayed;

	std::regex pat_id{"[\\d]+"};
	std::regex pat_name{ "[a-zA-Zа-яёА-ЯЁ]+" };
	std::regex pat_lastname{ "[a-zA-Zа-яёА-ЯЁ]+" };
	std::regex pat_sum{ "[\\d]+(.?)[\\d]*" };
	std::regex pat_payed{ "[01]" };


	enum class Field { ID, NAME, LASTNAME, SUM, PAYED };

	// map с именами файлов хеш-таблиц
	std::unordered_map < Field, std::string > fieldmap{ std::make_pair(Field::ID, "id.txt"),
														std::make_pair(Field::NAME, "name.txt"),
														std::make_pair(Field::LASTNAME, "last.txt"),
														std::make_pair(Field::SUM, "sum.txt"),
														std::make_pair(Field::PAYED, "payed.txt")
	};

	std::unordered_map <Field, std::regex> regmap{ {Field::ID, pat_id},
													{Field::NAME, pat_name},
													{Field::LASTNAME, pat_lastname},
													{Field::SUM, pat_sum},
													{Field::PAYED, pat_payed}
	};

	//считывает нужную хеш-таблицу из файла в unordered multimap
	void fillMap(Field f);


public: 
	std::vector<int> find(std::string, std::string item);
	void fixFile();
	void remove(std::vector<int> items);
	std::string replace(int pos);
	void replace(int pos, bool a);
	std::vector<std::string> getVec(std::string s);
	void clear();
	void changeFileName(std::string s);
	std::string getFilename();
	
};
