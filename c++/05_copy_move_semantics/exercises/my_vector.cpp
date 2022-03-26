#include <iostream>
#include <memory>
#include <algorithm>

template<typename T>
class Vector{
 std::unique_ptr<T[]> elem;
 std::size_t _size{};
 std::size_t _capacity{};

 void check_and_increase_capacity(){
  if(_capacity == 0)
   reserve(8); // reserve 8 elements
  else if(_size == _capacity)
   reserve(2*_capacity);
 }

 template <typename O>
 void _push_back(O&& x){
  check_and_increase_capacity();
  elem[_size] = std::forward<O>(x);
  ++_size;
 }

 public:

  auto size() const { return _size; }
  auto capacity() const { return _capacity; }
  Vector() = default;
  
  Vector(std::initializer_list<T> list): 
   elem{new T{list.size()}},
   _size{list.size()},
   _capacity{list.size()}{

   std::copy(list.begin(), list.end(), elem.get());

  // for(std::size_t i = 0; i < list.size(); i++)
  //	elem[i] = std::move(list[i]);
   }

  void reserve(const std::size_t n){
   if(_capacity < n){
    T* tmp {new T[n]};
    for(std::size_t i = 0; i < _size; ++i)
	   tmp[i] = std::move(elem[i]);
    elem.reset(tmp);
    _capacity = n;
   }
  }

  void push_back(const T& x){
   _push_back(x);
  }
  void push_back(T&& x){
   _push_back(std::move(x));
  }

  auto& operator[](const std::size_t i){
  return elem[i];
  }

  const auto& operator[](const std::size_t i) const {
  return elem[i];
  }

};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& x){
 os << "capacity: " << x.capacity() << ", size: " << x.size() << "\n";
 for(auto i = 0u; i < x.size(); ++i)
	 os << x[i] << " ";
 os << std::endl;
 return os;
}

int main(){
 Vector<int> x{1,2,3,4};

 std::cout << x;

 x.push_back(3);

 std::cout << x;
}
