#pragma once

template<typename T>
class Table{
public:
	Table() : Table(0,0){
	}
	Table(int r, int c) {
		this->r = r;
		this->c = c;
		dataptr = new T[r * c]{};
	}
	~Table() {
		delete[] dataptr;
	}

	Table(const Table& old) {
		r = old.r;
		c = old.c;
		dataptr = new T[r * c];

		for (int ir = 0; ir < r; ir++) {
			for (int ic = 0; ic < c; ic++) {
				at(ir, ic) = old.at(ir, ic);
			}
		}
	}
	Table& operator=(const Table& old) {
		if (this == &old) {
			return *this;
		}

		delete[] dataptr;
		r = old.r;
		c = old.c;
		dataptr = new T[r * c];

		for (int ir = 0; ir < r; ir++) {
			for (int ic = 0; ic < c; ic++) {
				at(ir, ic) = old.at(ir, ic);
			}
		}

		return *this;
	}

	Table(Table&& old) {

	}
	Table& operator=(Table&& old) {

	}

	T& at(int r, int c) {
		if (r >= 0 && r < this->r && c>= 0 && c < this->c) {
			return dataptr[r * this->c + c];
		}
		throw std::out_of_range("Index out of bounds");
	}
	T const& at(int r, int c) const {
		if (r >= 0 && r < this->r && c >= 0 && c < this->c) {
			return dataptr[r * this->c + c];
		}
		throw std::out_of_range("Index out of bounds");
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