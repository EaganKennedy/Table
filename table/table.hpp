#pragma once
#include <utility>
#include <algorithm>

template<typename T>
class Table{
public:
	//Construct & Destruct
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

	//Copy
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

	//Move
	Table(Table&& old) {
		dataptr = old.dataptr;
		r = old.r;
		c = old.c;

		old.dataptr = nullptr;
		old.r = 0;
		old.c = 0;
	}
	Table& operator=(Table&& old) {
		if (this == &old) {
			return *this;
		}

		delete[] dataptr;

		dataptr = old.dataptr;
		r = old.r;
		c = old.c;

		old.dataptr = nullptr;
		old.r = 0;
		old.c = 0;

		return *this;
	}

	// at()
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

	//Data manip
	T* data() const {
		return dataptr;
	}
	void resize(int r, int c) {
		Table temp(r, c);
		int copyR = std::min(r, this->r);
		int copyC = std::min(c, this->c);

		for (int ir = 0; ir < copyR; ir++) {
			for (int ic = 0; ic < copyC; ic++) {
				std::swap(temp.at(ir, ic), at(ir, ic));
			}
		}

		std::swap(*this, temp);
	}

	//Row
	T* operator[](int i) {
		return dataptr + (i * c);
	}
	T const* operator[](int i) const {
		return dataptr + (i * c);
	}

private:
	T* dataptr;
	int r;
	int c;
};