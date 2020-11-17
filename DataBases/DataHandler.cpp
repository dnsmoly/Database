#include "DataHandler.h"
#include <sstream>
#include <iostream>
#include <vector>

using namespace System;
using namespace System::Windows::Forms;

void DataHandler::fillTables() // запоняет .txt файлы хеш-таблиц при открытии БД
{
	filestream.open(filename, std::ios::in);
	if (!filestream) MessageBox::Show("He могу открыть базу данных для считывания", "Ошибка");

	std::string buff;
	int pos;
	filestream.seekg(0, std::ios::end);
	pos = filestream.tellg();

	fid.open(fieldmap[Field::ID], std::ios::out | std::ios::trunc);
	fname.open(fieldmap[Field::NAME], std::ios::out | std::ios::trunc);
	flastname.open(fieldmap[Field::LASTNAME], std::ios::out | std::ios::trunc);
	fsum.open(fieldmap[Field::SUM], std::ios::out | std::ios::trunc);
	fpayed.open(fieldmap[Field::PAYED], std::ios::out | std::ios::trunc);

	if (pos != 0) { //если файл БД не пуст то заполнить хеш-таблицы

		filestream.seekg(0, std::ios::beg);
		pos = filestream.tellg();
		getline(filestream, buff, ';');
		do {
			fid << buff << ' ' << pos << '\n';
			getline(filestream, buff, ';');
			fname << buff << ' ' << pos << '\n';
			getline(filestream, buff, ';');
			flastname << buff << ' ' << pos << '\n';
			getline(filestream, buff, ';');
			fsum << buff << ' ' << pos << '\n';
			getline(filestream, buff);
			fpayed << buff << ' ' << pos << '\n';
			pos = filestream.tellg();
		} while (std::getline(filestream, buff, ';'));
	}
	else {
		MessageBox::Show("БД пуста", "Внимание");
	}
	fid.close();
	fname.close();
	flastname.close();
	fsum.close();
	fpayed.close();
	filestream.close();
	
}

void DataHandler::clear() {
	filestream.open(filename, std::ofstream::out | std::ios::trunc);
	fid.open(fieldmap[Field::ID], std::ofstream::out | std::ios::trunc);
	fname.open(fieldmap[Field::NAME], std::ofstream::out | std::ios::trunc);
	flastname.open(fieldmap[Field::LASTNAME], std::ofstream::out | std::ios::trunc);
	fsum.open(fieldmap[Field::SUM], std::ofstream::out | std::ios::trunc);
	fpayed.open(fieldmap[Field::PAYED], std::ofstream::out | std::ios::trunc);
	fid.close();
	fname.close();
	flastname.close();
	fsum.close();
	fpayed.close();
	filestream.close();
}

void DataHandler::changeFileName(std::string s)
{
	this->filename = s;
}

std::string DataHandler::getFilename()
{
	return this -> filename;
}


bool DataHandler::addEntry(std::string id, std::string name, std::string lastname, std::string sum, bool payed) // добавляет строку в БД
{
	 
	if (!std::regex_match(id.c_str(), regmap[Field::ID]) | !std::regex_match(name.c_str(), regmap[Field::NAME]) | //проверка значений полей на корректность
		!std::regex_match(lastname.c_str(), regmap[Field::LASTNAME]) | !std::regex_match(sum.c_str(), regmap[Field::SUM])) {
		MessageBox::Show("Неправильно введены данные", "Ошибка");
		return false;
	}

	fillMap(Field::ID); 
	auto search = this->id.find(id); // проверка есть ли значение с таким ID

	if (search == this->id.end()) { // если нет, то записывает новую втроку в БД и в хеш-таблицы
		filestream.open(filename, std::ios::in | std::ios::out);
		if (!filestream) std::cout << ("He могу открыть БД для записи\n");

		filestream.seekg(0, std::ios::end);
		int b = filestream.tellg();
		
		filestream.seekg(filestream.tellg(), std::ios::beg);
		filestream << id << ';' << name << ';' << lastname << ';' << sum << ';' << payed << '\n';
		filestream.close();

		fid.open(fieldmap[Field::ID], std::ios::app);
		fid << id << ' ' << b << '\n';
		fid.close();

		fname.open(fieldmap[Field::NAME], std::ios::app);
		fname << name << ' ' << b << '\n';
		fname.close();

		flastname.open(fieldmap[Field::LASTNAME], std::ios::app);
		flastname << lastname << ' ' << b << '\n';
		flastname.close();

		fsum.open(fieldmap[Field::SUM], std::ios::app);
		fsum << sum << ' ' << b << '\n';
		fsum.close();

		fpayed.open(fieldmap[Field::PAYED], std::ios::app);
		fpayed << payed << ' ' << b << '\n';
		fpayed.close();
		this->id.clear();
		return true;
	}
	else {
		MessageBox::Show("Запись с таким id уже существует", "Ошибка");
		this->id.clear();
		return false;
	}
}

void DataHandler::writeTmp(std::vector<int> items) // Записывает найденные значения во временный .txt файл для удобного отображения
{
	fid.open("tmp.txt", std::ios::out);
	filestream.open(filename, std::ios::in);

	std::string buff;
	
	for (auto item: items) {
		filestream.seekg(item, std::ios::beg);
		for (auto j = 0; j < 4; ++j) {
			getline(filestream, buff, ';');
			fid << buff << '\n';
		}
		getline(filestream, buff);
		fid << buff << '\n';
	}
	fid.close();
	filestream.close();
}

void DataHandler::fillMap(Field f) //считывает хеш-таблицу и заполняет unordered_map ключами и значениями,
								   //где ключ - поле, а значние адрес строки в БД
{
	fid.open(fieldmap[f], std::ios::in);
	if (!fid) MessageBox::Show("He могу открыть хеш-таблицу", "Ошибка");

	std::string buff;
	std::string key;
	int val;
	switch (f) {
	case Field::ID:
		id.clear();
		break;
	case Field::NAME:
		name.clear();
		break;
	case Field::LASTNAME:
		lastname.clear();
		break;
	case Field::SUM:
		sum.clear();
		break;
	case Field::PAYED:
		payed.clear();
		break;
	}

	while (getline(fid, key, ' ')) {
		getline(fid, buff);
		if (key[0] != '-')
		{
			std::istringstream(buff) >> val;
			switch (f) {
			case Field::ID:
				id.insert(std::make_pair(key, val));
				break;
			case Field::NAME:
				name.insert(std::make_pair(key, val));
				break;
			case Field::LASTNAME:
				lastname.insert(std::make_pair(key, val));
				break;
			case Field::SUM:
				sum.insert(std::make_pair(key, val));
				break;
			case Field::PAYED:
				payed.insert(std::make_pair(key, val));
				break;
			}
		}
	}
	fid.close();
}

std::vector<int> DataHandler::find(std::string field, std::string item) // возвращает вектор значений (адреса строк в БД) с найденными значениями
{
	Field f; 
	std::vector<int> ret; 

	switch (field[0]) { // По какому полю искать
	case 'I':
		f = Field::ID;
		break;
	case 'И':
		f = Field::NAME;
		break;
	case 'Ф':
		f = Field::LASTNAME;
		break;
	case 'С':
		f = Field::SUM;
		break;
	case 'О':
		f = Field::PAYED;
		break;
	}

	fillMap(f); //считать хеш-балицу


	switch (f) {
	case Field::ID:
		//search = this->id.find(item);
		if (this->id.find(item) == this->id.end()) { //Если значения нет в табилце
			return {};
		}
		else {
			ret.push_back(this->id.find(item)->second); //добавить в результирубщий вектор
			return ret;
		}
		id.clear();
		break;
	case Field::NAME:
		if (this->name.find(item) == this->name.end()) {
			return {};
		}
		else {
			for (auto c = name.begin(name.bucket(item)); c != name.end(name.bucket(item)); ++c) {
				ret.push_back(c->second);
			}
		}
		name.clear();
		break;
	case Field::LASTNAME:
		if (this->lastname.find(item) == this->lastname.end()) {
			return {};
		}
		else {
			for (auto c = lastname.begin(lastname.bucket(item)); c != lastname.end(lastname.bucket(item)); ++c) {
				ret.push_back(c->second);
			}
		}
		lastname.clear();
		break;
	case Field::SUM:
		if (this->sum.find(item) == this->sum.end()) {
			return {};
		}
		else {
			for (auto c = sum.begin(sum.bucket(item)); c != sum.end(sum.bucket(item)); ++c) {
				ret.push_back(c->second);
			}
		}
		sum.clear();
		break;
	case Field::PAYED:
		if (this->payed.find(item) == this->payed.end()) {
			return {};
		}
		else {
			for (auto c = payed.begin(payed.bucket(item)); c != payed.end(payed.bucket(item)); ++c) {
				ret.push_back(c->second);
			}
		}
		payed.clear();
		break;
	}
	return ret;
}



void DataHandler::fixFile() // перезаписывает файл, оставляя только нузжные строки
{
	std::ifstream read;
	std::ofstream write;
	std::string line;
	/*
	read.open(fieldmap[f], std::ios::in);
	write.open("fix.txt", std::ios::app);
	while (getline(read, line)) {
		if (line[0] != '-') {
			write << line;
		}
	}
	read.close();
	write.close();
	std::remove(fieldmap[f].c_str());
	std::rename("fix.txt", fieldmap[f].c_str());
	*/
	
	read.open(filename, std::ios::in);
	write.open("fix.txt", std::ios::app);
	while (getline(read, line)) {
		if (line[0] != '-') {
			write << line << std::endl;
		}
	}
	read.close();
	write.close();
	std::remove(filename.c_str());
	std::rename("fix.txt", filename.c_str());
	
	
	
}

void DataHandler::remove(std::vector<int> items) 
{
	std::vector<std::string> s;
	std::string str;
	for (int item : items) {
		replace(item);
		replace(item, 0);
	}
}

//заменяет строку на данной позиции pos на стркоу из '-'
//возвращает строку, которую заменил
std::string DataHandler::replace(int pos) 							
{
	std::fstream out;
	int len;
	std::string buff;

	out.open(filename, std::ofstream::out | std::ofstream::in);

	out.seekg(pos, std::ios::beg); 
	len = out.tellg();
	getline(out, buff);
	len = (int)out.tellg() - len - 2;

	out.seekg(pos, std::ios::beg);
	std::string s(len-1, '-');
	out << s << ';';
	out.close();
	return buff;
}

void DataHandler::replace(int pos, bool a)
{
	std::fstream out;
	int len;
	std::string buff;
	int counter = 0;
	int curr;
	std::string sub;
	std::string delimiter = " ";
	

	for (auto item : fieldmap) {

		out.open(item.second, std::ofstream::out | std::ofstream::in);
		curr = out.tellg();

		while (getline(out, buff)) {

			sub = buff.substr(buff.find(delimiter) + 1, buff.length() - buff.find(delimiter) - 1);

			if (sub == std::to_string(pos)) {
				len = (int)out.tellg() - curr - 2;

				out.seekg(curr, std::ios::beg);
				std::string s(len-1, '-');
				out << s << ' ';
				out.seekg(2, std::ios::cur);
				curr = out.tellg();
				counter++;
			}
			else {
				curr = out.tellg();
			}
		}
		out.close();
	}
}

std::vector<std::string> DataHandler::getVec(std::string s)
{
	std::vector < std::string > f;
	size_t pos = 0;
	std::string token;
	std::string delimiter = ";";

	while (pos = s.find(delimiter) != std::string::npos) {
		token = s.substr(0, pos);
		f.push_back(token);
		s.erase(0, pos + delimiter.length());
	}
	return f;
}
