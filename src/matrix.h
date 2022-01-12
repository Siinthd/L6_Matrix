#include <cassert>
#include <string>
#include <map>
#include <array>

template<typename Matrix, typename T, size_t Depth = 2>
class Cell {
public:
	using Key = std::array<size_t, Depth>;
	Cell() = delete;

	explicit Cell(Matrix* matrix, Key key) :_matrix(matrix), _key(key),_index(Depth)
	{
		static_assert(Depth > 0, "Depth is Empty");

	}
	explicit Cell(Matrix* matrix, size_t i) :_matrix(matrix), _key({ i }), _index(1)
	{
		static_assert(Depth > 0, "Depth is Empty");
	}

	auto& operator[](size_t i)
	{
		assert(_index < Depth && "Out of Depth");
		_key[_index] = i;
		++_index;
		return *this;
	}

	T operator=(T value)
	{
		_matrix->set(_key, value);
		return value;
	}
	const T& get() const
	{
		return _matrix->get(_key);
	}
	bool operator==(const T& value)
	{
		return get() == value;
	}

private:
	Matrix* _matrix;
	Key _key;
	size_t _index;
};

template<typename Matrix, typename T, size_t Depth = 2>
std::ostream& operator<<(std::ostream &out, const Cell<Matrix, T, Depth>& value)
{
	return out << value.get();
}

template<typename T, T Default, size_t Depth = 2>
class Matrix {
	public:
	using Key = std::array<size_t, Depth>;
	using Map = std::map<Key, T>;

	const T&  get(const Key& key) const
	{
		auto it = _map.find(key);
		if (it == _map.end())
		{
			return _default;
		}
		return it->second;
	}

	void set(const Key& key, T value)
	{
		auto it = _map.find(key);
		if (it == _map.end())
		{
			if(value!=Default)
				_map.emplace(key, value);
		}
		return;
		if (value == Default)
		{
			_map.erase(it);
			return;
		}
		it->second = value;
	}

	auto operator[](size_t i)
	{
		return Cell<Matrix,T, Depth>(this, i);
	}


	size_t size() { return _map.size(); };

	auto begin()
	{
		return _map.begin();
	}

	auto end()
	{
		return _map.end();
	}
private:
	Map _map;
	const T _default = Default;
};