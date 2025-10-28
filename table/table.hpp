#pragma once

template<typename T>
class Table{
public:
	Table() : Table(0,0){
	}
	Table(int r, int c) {
		this->r = r;
		this->c = c;
		dataptr = new T[r * c];
	}
	~Table() {
		delete[] dataptr;
	}

	Table(const Table&) {

	}
	Table& operator=(const Table& old) {

	}
	Table(Table&&) {

	}
	Table& operator=(Table&& old) {

	}

	T& at(int r, int c) {

	}
	T const& at(int r, int c) const {

	}
	T* data() const {
		return dataptr;
	}
	void resize(int r, int c) {

	}

	Table& operator[](int i) {

	}
	Table const& operator[](int i) const {

	}

private:
	T* dataptr;
	int r;
	int c;
};