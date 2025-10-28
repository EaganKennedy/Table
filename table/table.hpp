#pragma once

template<typename T>
class Table{
public:
	Table();
	Table(int r, int c);
	~Table();

	Table(const Table&);
	Table& operator=(const Table& old);
	Table(Table&&);
	Table& operator=(Table&& old)

	T& at(int r, int c) const;
	T* data() const;

	void resize(int r, int c);

	Table& operator[](Index i);
	Table const& operator[](Index i) const;

private:
	T* data;
	int r;
	int c;
};